#include <ultra64.h>
#include "sm64.h"
#include "level_update.h"
#include "camera.h"
#include "object_list_processor.h"
#include "include/behavior_data.h"
#include "audio/internal.h"
#include "game/interaction.h"
#include "game/mario.h"
#define o gCurrentObject
extern s16 s8DirModeYawOffset;

//returns random number between min and max inclusive
u16 CL_RandomMinMaxU16(u16 min, u16 max) {
    u16 num = random_u16();
    return (num % ((max + 1) - min)) + min;
}

void CL_kill_mario() {
    gMarioState->hurtCounter = 0xFF;
}

//
u8 CL_run_timer(u16 timer) {
    print_text_fmt_int(120, 210, "%d", timer / 30);
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

void CL_set_camera_pos(Vec3f pos) {
    struct MarioState *marioStates = &gMarioStates[0];
    struct LinearTransitionPoint *start = &sModeInfo.transitionStart;
    struct LinearTransitionPoint *end = &sModeInfo.transitionEnd;

    vec3f_copy(gLakituState.curPos, pos);
    vec3f_copy(gLakituState.curFocus, pos);
    vec3f_copy(gLakituState.goalPos, pos);
    vec3f_copy(gLakituState.goalFocus, pos);
    vec3f_copy(start->focus, pos);
    vec3f_copy(start->pos, pos);
    vec3f_copy(end->focus, pos);
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

//0 = not done, 1 = done, 2 = died
s32 CL_respawn(s16 *timer, Vec3f pos, s16 faceAngle, s16 damage) {
    if (gMarioState->health <= 0x280) {
        level_trigger_warp(gMarioState, WARP_OP_WARP_FLOOR);
        return 2;
    } else {
        switch (*timer) {
            case 0:
                play_transition(WARP_TRANSITION_FADE_INTO_CIRCLE, 0xC, 0x00, 0x00, 0x00);
                break;
            case 9:
                vec3f_copy(gMarioState->pos, pos);
                CL_set_camera_pos(pos);
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


void CL_Lava_Boost(void) {
    struct MarioState *m = gMarioState;
    m->floorHeight = m->pos[1];
    check_lava_boost(m);
}