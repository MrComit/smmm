#include <ultra64.h>
#include "sm64.h"
#include "level_update.h"
#include "camera.h"
#include "object_list_processor.h"
#include "include/behavior_data.h"
#include "audio/internal.h"
#include "game/interaction.h"
#include "game/mario.h"
#include "engine/surface_collision.h"
#include "game/ingame_menu.h"
#define o gCurrentObject
extern s16 s8DirModeYawOffset;


//returns random number between min and max inclusive
u16 CL_RandomMinMaxU16(u16 min, u16 max) {
    u16 num = random_u16();
    return (num % ((max + 1) - min)) + min;
}


u16 random_u16_seeded(u16 seed) {
    u16 temp1, temp2;

    if (seed == 22026) {
        seed = 0;
    }

    temp1 = (seed & 0x00FF) << 8;
    temp1 = temp1 ^ seed;

    seed = ((temp1 & 0x00FF) << 8) + ((temp1 & 0xFF00) >> 8);

    temp1 = ((temp1 & 0x00FF) << 1) ^ seed;
    temp2 = (temp1 >> 1) ^ 0xFF80;

    if ((temp1 & 1) == 0) {
        if (temp2 == 43605) {
            seed = 0;
        } else {
            seed = temp2 ^ 0x1FF4;
        }
    } else {
        seed = temp2 ^ 0x8180;
    }

    return seed;
}


u16 CL_RandomMinMaxU16Seeded(u16 min, u16 max, u16 seed) {
    u16 num = random_u16_seeded(seed);
    return (num % ((max + 1) - min)) + min;
}


void CL_kill_mario() {
    gMarioState->hurtCounter = 0xFF;
}

//
u8 CL_run_timer(u16 timer) {
    print_text_fmt_int(120, 210, "%d", timer / 30, 0);
    timer--;
    if (!timer)
        return TRUE;
    return FALSE;
}


void CL_Move() {
    cur_obj_compute_vel_xz();
    cur_obj_move_using_vel_and_gravity();
}

void CL_Move_3d() {
    cur_obj_compute_vel_xyz();
    cur_obj_move_using_vel_and_gravity();
}

struct Object *CL_Create_Star_Helper(struct Object *sp30, f32 sp34, f32 sp38, f32 sp3C) {
    sp30 = spawn_object_abs_with_rot(o, 0, MODEL_STAR, bhvStarSpawnCoordinates, o->oPosX, o->oPosY,
                                     o->oPosZ, 0, 0, 0);
    sp30->oBehParams = o->oBehParams;
    sp30->oHomeX = sp34;
    sp30->oHomeY = sp38;
    sp30->oHomeZ = sp3C;
    sp30->oFaceAnglePitch = 0;
    sp30->oFaceAngleRoll = 0;
    return sp30;
}

struct Object *CL_Create_Star_Ptr(f32 sp20, f32 sp24, f32 sp28) {
    struct Object *sp1C;
    sp1C = CL_Create_Star_Helper(sp1C, sp20, sp24, sp28);
    sp1C->oBehParams2ndByte = 0;
    return sp1C;
}

s16 CL_object_to_point(struct Object *o, Vec3f point) {
    f32 dx = point[0] - o->oPosX;
    f32 dz = point[2] - o->oPosZ;

    return atan2s(dz, dx);
}

s16 CL_angle_between_points(Vec3f point1, Vec3f point2) {
    f32 dx = point2[0] - point1[0];
    f32 dz = point2[2] - point1[2];

    return atan2s(dz, dx);
}

extern struct ModeTransitionInfo sModeInfo;

void CL_set_camera_pos(Vec3f pos, Vec3f pos2) {
    struct MarioState *marioStates = &gMarioStates[0];
    struct LinearTransitionPoint *start = &sModeInfo.transitionStart;
    struct LinearTransitionPoint *end = &sModeInfo.transitionEnd;

    vec3f_copy(gLakituState.curPos, pos);
    vec3f_copy(gLakituState.curFocus, pos2);
    vec3f_copy(gLakituState.goalPos, pos);
    vec3f_copy(gLakituState.goalFocus, pos2);
    vec3f_copy(start->focus, pos2);
    vec3f_copy(start->pos, pos);
    vec3f_copy(end->focus, pos2);
    vec3f_copy(end->pos, pos);
}


struct Object *CL_obj_nearest_object_behavior_params(const BehaviorScript *behavior, u32 params) {
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct Object *closestObj = NULL;
    struct Object *obj;
    struct ObjectNode *listHead;
    f32 minDist = 0x20000;

    listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    obj = (struct Object *) listHead->next;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr && obj->oBehParams == params) {
            if (obj->activeFlags != ACTIVE_FLAG_DEACTIVATED && obj != o) {
                f32 objDist = dist_between_objects(o, obj);
                if (objDist < minDist) {
                    closestObj = obj;
                    minDist = objDist;
                }
            }
        }
        obj = (struct Object *) obj->header.next;
    }

    return closestObj;
}


/*f32 CL_dist_between_points(Vec3f p1, Vec3f p2) {
    f32 x = p2[0] - p1[0];
    f32 y = p2[1] - p1[1];
    f32 z = p2[2] - p1[2];
    return sqrtf(x * x + y * y + z * z);
    //return sqrtf((p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[2] - p2[2]) * (p1[2] - p2[2]));
}*/


void CL_dist_between_points(Vec3f from, Vec3f to, f32 *dist) {
    register f32 x = to[0] - from[0];
    register f32 y = to[1] - from[1];
    register f32 z = to[2] - from[2];

    *dist = sqrtf(x * x + y * y + z * z);
}

void CL_lateral_dist_between_points(Vec3f from, Vec3f to, f32 *dist) {
    register f32 x = to[0] - from[0];
    register f32 z = to[2] - from[2];

    *dist = sqrtf(x * x + z * z);
}


u32 CL_count_bits(u32 b) {
    u32 i = 1;
    s32 k = 0;
    while (i != 0x80000000) {
        if (b & i)
            k++;
        i = i << 1;
    }
    return k;
}


void CL_drop_to_floor(void) {
    o->oPosY = find_floor_height(o->oPosX, o->oPosY + 200.0f, o->oPosZ);
    //o->oMoveFlags |= OBJ_MOVE_ON_GROUND;
}



s32 CL_NPC_Dialog(s32 dialogId) {
    if (set_mario_npc_dialog(1) == 2) {
        o->activeFlags |= 0x20; /* bit 5 */
        if (cutscene_object_with_dialog(CUTSCENE_DIALOG, o, dialogId)
            != 0) {
            set_mario_npc_dialog(0);
            o->activeFlags &= ~0x20; /* bit 5 */
            o->oInteractStatus = 0;
            return TRUE;
        }
    }
    return FALSE;
}

s32 CL_NPC_Dialog_Options(s32 dialogId) {
    if (set_mario_npc_dialog(1) == 2) {
        o->activeFlags |= 0x20; /* bit 5 */
        create_dialog_box_with_response(dialogId);
        if (gDialogResponse) {
            set_mario_npc_dialog(0);
            o->activeFlags &= ~0x20; /* bit 5 */
            o->oInteractStatus = 0;
        }
    }
    return gDialogResponse;
}

//0 = not done, 1 = done, 2 = died
s32 CL_respawn(s16 *timer, Vec3f pos, s16 faceAngle, s16 damage) {
    if (gMarioState->health <= 0x280) {
        level_trigger_warp(gMarioState, WARP_OP_WARP_FLOOR_OBJECT);
        return 2;
    } else {
        switch (*timer) {
            case 0:
                play_transition(WARP_TRANSITION_FADE_INTO_CIRCLE, 0xC, 0x00, 0x00, 0x00);
                break;
            case 9:
                vec3f_copy(gMarioState->pos, pos);
                CL_set_camera_pos(pos, pos);
                gMarioState->faceAngle[1] = faceAngle;
                s8DirModeYawOffset = (s16)(faceAngle & 0xC000) - 0x4000;
                set_mario_action(gMarioState, ACT_JUMP_LAND_STOP, 0);
                break;
            case 12:
                play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 5, 0x00, 0x00, 0x00);
                gMarioState->hurtCounter = damage;
                *timer = 0;
                return 1;
                break;
        }
    }
    *timer++;
    return 0;
}

Vec3f *CL_nearest_point(Vec3f *list, Vec3f source, s16 listcount) {
    s16 i;
    f32 smallestDist = 64000.0f;
    Vec3f *point;
    
    for (i = 0; i < listcount; i++) {
        f32 dist;
        CL_dist_between_points(source, list[i], &dist);
        if (dist < smallestDist) {
            smallestDist = dist;
            point = list[i];
        }
    }
    return *point;
}



s16 CL_obj_pitch_to_mario(void) {
    f32 x = o->oPosX - gMarioState->pos[0];
    f32 z = o->oPosZ - gMarioState->pos[2];
    f32 latDist = sqrtf(x*x + z*z);
    return atan2s(latDist, o->oPosY - gMarioState->pos[1]);
}

u32 CL_get_hit_helper(struct MarioState *m, u32 damage) {
    s32 shake;
    if (damage >= 4) {
        shake = SHAKE_LARGE_DAMAGE;
    } else if (damage >= 2) {
        shake = SHAKE_MED_DAMAGE;
    } else {
        shake = SHAKE_SMALL_DAMAGE;
    }

    if (!(m->flags & MARIO_CAP_ON_HEAD)) {
        damage += (damage + 1) / 2;
    }

    if (m->flags & MARIO_METAL_CAP) {
        damage = 0;
    }

    m->hurtCounter += 4 * damage;

    queue_rumble_data(5, 80);
    set_camera_shake_from_hit(shake);

    return damage;
}

extern s16 sInvulnerable;

void CL_get_hit(struct MarioState *m, struct Object *o, u32 damage) {
    if (!sInvulnerable && !(m->flags & MARIO_VANISH_CAP)) {
        //o->oInteractStatus = INT_STATUS_INTERACTED | INT_STATUS_ATTACKED_MARIO;
        m->interactObj = o;

        damage = CL_get_hit_helper(m, damage);
        play_sound(SOUND_MARIO_ATTACKED, m->marioObj->header.gfx.cameraToObject);

        update_mario_sound_and_camera(m);
        drop_and_set_mario_action(m, determine_knockback_action(m, o->oDamageOrCoinValue), damage);
    }
}



void CL_explode_object(struct Object *obj, s16 noDamage) {
    struct Object *explosion;
    if (obj->oTimer < 5)
        cur_obj_scale(1.0 + (f32) obj->oTimer / 5.0);
    else {
        explosion = spawn_object(obj, MODEL_EXPLOSION, bhvExplosion);
        explosion->oGraphYOffset += 100.0f;
        if (noDamage)
            explosion->oIntangibleTimer = -1;
        else 
            explosion->oIntangibleTimer = 0;
        obj->activeFlags = 0;
    }
}


void CL_scramble_array(u8 *array[], s16 size) {
    s16 i, j, k;
    u8 *bytes = (u8 *) array;
    for (i = size - 1; i > 0; i--) {
        j = CL_RandomMinMaxU16(0, i);
        k = bytes[j];
        bytes[j] = bytes[i];
        bytes[i] = k;
    }
}


void CL_Lava_Boost_Helper(struct MarioState *m, s32 preserveVel) {
    if (!(m->action & ACT_FLAG_RIDING_SHELL) && m->pos[1] < m->floorHeight + 10.0f) {
        if (!(m->flags & MARIO_METAL_CAP)) {
            m->hurtCounter += (m->flags & MARIO_CAP_ON_HEAD) ? 12 : 18;
        }

        update_mario_sound_and_camera(m);
        drop_and_set_mario_action(m, ACT_LAVA_BOOST, preserveVel);
    }
}


void CL_Lava_Boost(s32 preserveVel) {
    struct MarioState *m = gMarioState;
    m->floorHeight = m->pos[1];
    CL_Lava_Boost_Helper(m, preserveVel);
}



struct Object *CL_nearest_object_with_behavior_and_field(const BehaviorScript *behavior, u32 field, u32 param) {
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct Object *closestObj = NULL;
    struct Object *obj;
    struct ObjectNode *listHead;
    f32 minDist = 0x20000;

    listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    obj = (struct Object *) listHead->next;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr && obj->rawData.asU32[(field - 0x88) / 4] == param) {
            if (obj->activeFlags != ACTIVE_FLAG_DEACTIVATED && obj != o) {
                f32 objDist = dist_between_objects(o, obj);
                if (objDist < minDist) {
                    closestObj = obj;
                    minDist = objDist;
                }
            }
        }
        obj = (struct Object *) obj->header.next;
    }

    return closestObj;
}


struct Object *CL_objptr_nearest_object_behavior(struct Object *obj2, const BehaviorScript *behavior) {
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct Object *closestObj = NULL;
    struct Object *obj;
    struct ObjectNode *listHead;
    f32 minDist = 0x20000;

    listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    obj = (struct Object *) listHead->next;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr) {
            if (obj->activeFlags != ACTIVE_FLAG_DEACTIVATED && obj != obj2) {
                f32 objDist = dist_between_objects(obj2, obj);
                if (objDist < minDist) {
                    closestObj = obj;
                    minDist = objDist;
                }
            }
        }
        obj = (struct Object *) obj->header.next;
    }

    return closestObj;
}



s32 CL_get_room_from_point(Vec3f point) {
    struct Surface *floor;
    f32 floorHeight = find_floor(point[0], point[1], point[2], &floor);
    
    if (floor != NULL) {
        return floor->room;
        if (floor->room != 0) {
            return floor->room;
        } else {
            // Floor probably belongs to a platform object. Try looking
            // underneath it
            find_floor(point[0], floorHeight - 100.0f, point[2], &floor);
            if (floor != NULL) {
                //! Technically possible that the room could still be 0 here
                return floor->room;
            }
        }
    }
    return -1;
}



struct Object *CL_obj_find_nearest_object_with_behavior_room(struct Object *curObj, const BehaviorScript *behavior, s32 room) {
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct Object *closestObj = NULL;
    struct Object *obj;
    struct ObjectNode *listHead;
    f32 minDist = 0x20000;

    listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    obj = (struct Object *) listHead->next;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr) {
            if (obj->activeFlags != ACTIVE_FLAG_DEACTIVATED && obj != curObj && obj->oRoom == room) {
                f32 objDist = dist_between_objects(curObj, obj);
                if (objDist < minDist) {
                    closestObj = obj;
                    minDist = objDist;
                }
            }
        }
        obj = (struct Object *) obj->header.next;
    }

    return closestObj;
}


s32 CL_cur_obj_get_obj_collision(struct Object *obj) {
    f32 objVelX = o->oForwardVel * sins(o->oMoveAngleYaw);
    f32 objVelZ = o->oForwardVel * coss(o->oMoveAngleYaw);
    f32 posX = o->oPosX + objVelX;
    f32 posY = o->oPosY;
    f32 posZ = o->oPosZ + objVelZ;
    f32 floorY;
    struct Surface *floor;
    struct WallCollisionData hitbox;
    hitbox.x = posX;
    hitbox.y = posY;
    hitbox.z = posZ;
    hitbox.offsetY = o->hitboxHeight / 2;
    hitbox.radius = o->hitboxRadius;
    if (find_wall_collisions(&hitbox) != 0) {
        if (hitbox.walls[0] != NULL && hitbox.walls[0]->object == obj) {
            return TRUE;
        }
    }

    floorY = find_floor(posX, posY, posZ, &floor);
    if (floor != NULL && floor->object == obj) {
        return TRUE;
    }
    return FALSE;
}



struct Object *CL_objptr_find_nearest_object_behavior(struct Object *obj2, const BehaviorScript *behavior, f32 *dist) {
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct Object *closestObj = NULL;
    struct Object *obj;
    struct ObjectNode *listHead;
    f32 minDist = 0x20000;

    listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    obj = (struct Object *) listHead->next;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr) {
            if (obj->activeFlags != ACTIVE_FLAG_DEACTIVATED && obj != obj2) {
                f32 objDist = dist_between_objects(obj2, obj);
                if (objDist < minDist) {
                    closestObj = obj;
                    minDist = objDist;
                }
            }
        }
        obj = (struct Object *) obj->header.next;
    }

    *dist = minDist;
    return closestObj;
}


f32 CL_objptr_dist_to_nearest_object_with_behavior(struct Object *obj2, const BehaviorScript *behavior) {
    struct Object *obj;
    f32 dist;

    obj = CL_objptr_find_nearest_object_behavior(obj2, behavior, &dist);
    if (obj == NULL) {
        dist = 15000.0f;
    }

    return dist;
}

s8 gCLInstantWarp = FALSE;
Vec3f gCLWarpPos = {0};


void CL_call_warp(f32 x, f32 y, f32 z) {
    // vec3f_set(gCLWarpPos, x, y, z);
    gCLWarpPos[0] = x;
    gCLWarpPos[1] = y;
    gCLWarpPos[2] = z;
    gCLInstantWarp = TRUE;
}


void CL_instantly_warp(Vec3f pos) {
    s16 cameraAngle;
    struct MarioState *m = gMarioState;
    m->pos[0] += pos[0];
    m->pos[1] += pos[1];
    m->pos[2] += pos[2];

    m->marioObj->oPosX = m->pos[0];
    m->marioObj->oPosY = m->pos[1];
    m->marioObj->oPosZ = m->pos[2];

    cameraAngle = m->area->camera->yaw;

    warp_camera(pos[0], pos[1], pos[2]);

    m->area->camera->yaw = cameraAngle;
    gCLInstantWarp = FALSE;
    vec3f_set(gCLWarpPos, 0, 0, 0);
}


void CL_HSVtoRGB(s32 Hue, f32 s, f32 v, s16 *red, s16 *green, s16 *blue) {
    f32 C = s*v;
    f32 h2 = (f32)Hue / 60.0f;
    f32 X = C*(1.0f-absf((h2 - ((s32)h2 - ((s32)h2 % 2)))-1.0f));
    f32 m = v-C;
    f32 r,g,b;
    if (Hue < 60) {
        r = C;
        g = X;
        b = 0;
    } else if (Hue < 120) {
        r = X;
        g = C;
        b = 0;
    } else if (Hue < 180)  {
        r = 0;
        g = C;
        b = X;
    } else if (Hue < 240) {
        r = 0;
        g = X;
        b = C;
    } else if (Hue < 300) {
        r = X;
        g = 0;
        b = C;
    } else {
        r = C;
        g = 0;
        b = X;
    }
    *red = (r+m)*255;
    *green = (g+m)*255;
    *blue = (b+m)*255;
}






f32 CL_dist_point_to_line(Vec3f point, Vec3f linePoint, s32 lineAngle) {
    f32 m = coss(lineAngle) / sins(lineAngle);
    f32 b = linePoint[2] - (linePoint[0] * m);
    f32 e = absf((m * point[0]) - point[2] + b);
    return e / sqrtf(m*m + 1);
}