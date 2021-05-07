#include "game/object_helpers.h"
extern Vec3s gRoomColors[];
struct ObjectHitbox sShadowBossHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 5,
    /* numLootCoins:      */ 0,
    /* radius:            */ 170,
    /* height:            */ 340,
    /* hurtboxRadius:     */ 170,
    /* hurtboxHeight:     */ 340,
};

struct ObjectHitbox sLightBubbleHitbox = {
    /* interactType: */ INTERACT_COIN,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 0,
    /* numLootCoins: */ 0,
    /* radius: */ 120,
    /* height: */ 84,
    /* hurtboxRadius: */ 0,
    /* hurtboxHeight: */ 0,
};


struct ObjectHitbox sFistHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 120,
    /* height:            */ 400,
    /* hurtboxRadius:     */ 120,
    /* hurtboxHeight:     */ 400,
};

Vec3s sMastersFlames[5] = {
{0x00, 0x33, 0x05},
{0x33, 0x00, 0x1F},
{0x23, 0x00, 0x33},
{0x33, 0x1F, 0x00},
{0x00, 0x33, 0x33},
};

Vec3s sMastersFlamesInterpolate[6] = {
{0x08, 0x08, 0x08},
{0x00, 0x1A, 0x02},
{0x33, 0x00, 0x1F},
{0x12, 0x00, 0x1A},
{0x33, 0x1F, 0x00},
{0x00, 0x33, 0x33},
};


s16 sBubbleCount[] = {5, 6, 8, 10, 127};

static void const *sBubbleSpots[] = {
    wf_area_1_spline_Bubbles1, wf_area_1_spline_Bubbles2,
    wf_area_1_spline_Bubbles3, wf_area_1_spline_Bubbles4,
};

static void const *sSnufitSpots[] = {
    wf_area_1_spline_Bubbles1, NULL,
    wf_area_1_spline_Bubbles3, wf_area_1_spline_Bubbles4,
};

void spawn_snufits(s16 index) {
    struct Object *obj;
    struct Waypoint *traj;
    if (sSnufitSpots[index] == NULL)
        return;
    for (traj = segmented_to_virtual(sSnufitSpots[index]); traj->flags != -1; traj++) {
        obj = spawn_object(o, MODEL_SNUFIT, bhvSnufit);
        obj->oBehParams2ndByte = 1;
        obj->oPosX = traj->pos[0];
        obj->oPosY = traj->pos[1];
        obj->oPosZ = traj->pos[2];
        //spawn_mist_particles();
    }   
}

void bhv_fist_spawner_init(void) {
    o->oFaceAngleYaw = (o->oFaceAnglePitch = 0);
    cur_obj_scale(1.0f);
}


void bhv_fist_spawner_loop(void) {
    Vec3f pos;
    if (o->oObj104->oAction == 3) {
        o->oTimer = 0;
        return;
    }
    switch (o->oAction) {
        case 0:
            if (o->oTimer > 120) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oObjF4 = spawn_object(o, MODEL_RISING_FIST, bhvRisingFist);
            pos[0] = gMarioState->pos[0] + (sins(gMarioState->faceAngle[1]) * 25.0f * gMarioState->forwardVel);
            pos[2] = gMarioState->pos[2] + (coss(gMarioState->faceAngle[1]) * 25.0f * gMarioState->forwardVel);
            pos[1] = 0;            
            vec3f_copy(&o->oObjF4->oPosX, pos);
            o->oObjF4->oFaceAngleYaw = CL_RandomMinMaxU16(0, 0xFFFF);
            o->oObjF4->oFaceAnglePitch = CL_RandomMinMaxU16(0, 0x1000);
            o->oAction = 0;
            break;
    }
    if (o->oObj104->activeFlags == 0) {
        o->activeFlags = 0;
    }
}

void bhv_fist_indicator_loop(void) {
    o->oOpacity = approach_f32_symmetric(o->oOpacity, 255, 12);
}



void bhv_rising_fist_init(void) {
    obj_set_hitbox(o, &sFistHitbox);
    cur_obj_become_intangible();
    cur_obj_disable_rendering();
}



void bhv_rising_fist_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->prevObj->oOpacity == 0xFF) {
                o->oAction = 1;
                cur_obj_enable_rendering();
            }
            break;
        case 1:
            o->oGraphYOffset = approach_f32(o->oGraphYOffset, 0.0f, 90.0f, 90.0f);
            if (o->oTimer > 3) {
                cur_obj_become_tangible();
                o->prevObj->activeFlags = 0;
            }
            if (o->oTimer > 18) {
                o->oAction = 2;
                cur_obj_become_intangible();
            }
            break;
        case 2:
            o->oGraphYOffset = approach_f32(o->oGraphYOffset, -500.0f, 50.0f, 50.0f);
            if (o->oGraphYOffset == -500.0f) {
                o->activeFlags = 0;
            }
            break;
    }
}



void bhv_light_bubble_init(void) {
    struct Object *obj = cur_obj_nearest_object_with_behavior(bhvShadowBoss);
    if (obj == NULL) {
        o->activeFlags = 0;
        return;
    }
    o->os16FA = obj->oHealth;
    obj_set_hitbox(o, &sLightBubbleHitbox);
    o->os16F4 = 0x40;
    o->os16F6 = (o->os16F8 = o->os16F4);
}


void bhv_light_bubble_loop(void) {
    struct Object *obj = cur_obj_nearest_object_with_behavior(bhvMastersPlate);
    if (obj == NULL) {
        o->activeFlags = 0;
        return;
    }
    switch (o->oAction) {
        case 0:
            o->os16F4 = approach_s16_symmetric(o->os16F4, 0x40, 0x10);
            o->os16F6 = (o->os16F8 = o->os16F4);
            obj = cur_obj_nearest_object_with_behavior(bhvShadowBoss);
            if (obj != NULL && obj->oAction == 4) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->os16F4 = approach_s16_symmetric(o->os16F4, 0xFF, 0x10);
            o->os16F6 = (o->os16F8 = o->os16F4);
            if (o->oInteractStatus) {
                /*obj2 = */spawn_object(o, MODEL_SPARKLES, bhvGoldenCoinSparkles);
                //obj2->oPosY -= 50.0f;
                o->activeFlags = 0;
                obj->oFC++;
                //play_sound(SOUND_MENU_COLLECT_SECRET + (((u8) obj->oF4 - 1) << 16), gGlobalSoundSource);
            }
            break;
    }
    o->oInteractStatus = 0;
}


void bhv_masters_flame_init(void) {
    o->os16F4 = 0;
    o->os16F6 = 0;
    o->os16F8 = 0; //alpha = 200?
}


void bhv_masters_flame_loop(void) {
    struct Object *obj = CL_nearest_object_with_behavior_and_field(bhvMastersPlate, 0x144, o->oBehParams2ndByte);
    switch (o->oAction) {
        case 0:
            if (obj == NULL)
                return;
            if (obj->oAction == 1) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->os16F4 = approach_s16_symmetric(o->os16F4, sMastersFlames[o->oBehParams2ndByte][0], 0x6);
            o->os16F6 = approach_s16_symmetric(o->os16F6, sMastersFlames[o->oBehParams2ndByte][1], 0x6);
            o->os16F8 = approach_s16_symmetric(o->os16F8, sMastersFlames[o->oBehParams2ndByte][2], 0x6);
            break;
    }
}



void spawn_light_bubbles(s16 index) {
    struct Object *obj;
    struct Waypoint *traj;
    for (traj = segmented_to_virtual(sBubbleSpots[index]); traj->flags != -1; traj++) {
        obj = spawn_object(o, MODEL_LIGHT_BUBBLE, bhvLightBubble);
        obj->oPosX = traj->pos[0];
        obj->oPosY = traj->pos[1];
        obj->oPosZ = traj->pos[2];
    }   

}


void bhv_master_pressure_plate_init(void) {
   //o->os16F4 = 170;
   //o->os16F6 = 170;
   //o->os16F8 = 170;
   vec3s_set(&o->os16F4, 160, 160, 160);
   o->os16FA = o->oRoom - 7;
}

void bhv_master_pressure_plate_loop(void) {
    s32 i;
    s32 k = o->oBehParams2ndByte;
    s16 r, g, b;
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            o->oPosY = approach_f32(o->oPosY, o->oHomeY, 2.5f, 2.5f);
            if (gMarioObject->platform == o) {
                o->oAction = 1;
                obj = cur_obj_nearest_object_with_behavior(bhvShadowBoss);
                if (obj != NULL) {
                    obj->oAction = 3;
                    obj->oHealth--;
                    obj->oForwardVel = (obj->oVelY = 0);
                    obj->oInteractType = INTERACT_BOUNCE_TOP;
                    cur_obj_play_sound_2(SOUND_OBJ_ENEMY_DEATH_LOW);
                }
                if (o->oBehParams2ndByte < 4) {
                    spawn_light_bubbles(o->oBehParams2ndByte);
                }
            }
            o->os16F4 = approach_s16_symmetric(o->os16F4, 160, 0x10);
            o->os16F6 = (o->os16F8 = o->os16F4);
            break;
        case 1:
            k = o->oBehParams2ndByte + 1;
            o->oPosY = approach_f32(o->oPosY, o->oHomeY - 10.0f, 2.5f, 2.5f);
            o->os16F4 = approach_s16_symmetric(o->os16F4, sMastersFlames[o->oBehParams2ndByte][0], 0x10);
            o->os16F6 = approach_s16_symmetric(o->os16F6, sMastersFlames[o->oBehParams2ndByte][1], 0x10);
            o->os16F8 = approach_s16_symmetric(o->os16F8, sMastersFlames[o->oBehParams2ndByte][2], 0x10);
            if (gMarioObject->platform != o) {
                o->oAction = 2;
                o->oBehParams2ndByte++;
                if (o->oBehParams2ndByte == 5) {
                    //o->activeFlags = 0;
                    break;
                }
            }
            break;
        case 2:
            o->os16F4 = approach_s16_symmetric(o->os16F4, 20, 0x10);
            o->os16F6 = (o->os16F8 = o->os16F4);
            if (o->oTimer > 10) {
                o->oAction = 3;
            }
            break;
        case 3:
            o->os16F4 = 20 + (80/((sBubbleCount[o->oBehParams2ndByte-1]+1) - o->oFC));
            o->os16F6 = (o->os16F8 = o->os16F4);
            o->oPosY = o->oHomeY - (2.0f*(sBubbleCount[o->oBehParams2ndByte-1] - o->oFC));
            if (o->oFC >= sBubbleCount[o->oBehParams2ndByte-1]) {
                o->oAction = 0;
                o->oFC = 0;
                vec3s_set(&o->os16F4, 160, 160, 160);
            }
            break;
    }
    for (i = 0, r = 0, g = 0, b = 0; i <= k; i++) {
        r += sMastersFlamesInterpolate[i][0];
        g += sMastersFlamesInterpolate[i][1];
        b += sMastersFlamesInterpolate[i][2];
    }
    gRoomColors[o->os16FA][0] = approach_s16_symmetric(gRoomColors[o->os16FA][0], r, 0x8);
    gRoomColors[o->os16FA][1] = approach_s16_symmetric(gRoomColors[o->os16FA][1], g, 0x8);
    gRoomColors[o->os16FA][2] = approach_s16_symmetric(gRoomColors[o->os16FA][2], b, 0x8);
    if (cur_obj_nearest_object_with_behavior(bhvShadowBoss) == NULL)
        o->activeFlags = 0;
}


void handle_shadow_boss_phases(s16 phase) {
    struct Object *obj;
    //phase = 4;
    switch (phase) {
        case 0:
        case 1:
            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(-78);
            if (o->oMoveFlags & OBJ_MOVE_LANDED) {
                o->oVelY = 30.0f;
                o->oForwardVel = 10.0f;
                cur_obj_play_sound_2(SOUND_GENERAL_BOING1);
            }
            if (o->oMoveFlags & OBJ_MOVE_HIT_WALL) {
                o->oMoveAngleYaw = o->oWallAngle;//cur_obj_angle_to_home();
            }
            o->oGraphYOffset = approach_f32(o->oGraphYOffset, 175.0f, 10.0f, 10.0f);
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x100);
            o->oFaceAnglePitch += 0x400;
            break;
        case 2:
        case 3:
            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(-78);
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x100);
            if (o->oTimer > 60) {
                cur_obj_play_sound_2(SOUND_OBJ_SNUFIT_SHOOT);
                spawn_object_relative(0, 0, 50, 40, o, MODEL_GHOSTSAND_BALL, bhvSnufitBalls);
                o->oTimer = 0;
            }
            o->oFC += 0x500;
            o->oPosY = 20.0f + (sins(o->oFC) * 100.0f);
            break;
        case 4:
            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(-78);
            if (o->oMoveFlags & OBJ_MOVE_LANDED) {
                o->oVelY = 30.0f;
                o->oForwardVel = 10.0f;
                cur_obj_play_sound_2(SOUND_GENERAL_BOING1);
                cur_obj_play_sound_2(SOUND_OBJ_SNUFIT_SHOOT);
                obj = spawn_object(o, MODEL_GHOSTSAND_BALL, bhvSnufitBalls);
                obj->oPosY += 50.0f;
                obj->oFaceAnglePitch = (obj->oMoveAnglePitch = 0);
            }
            if (o->oMoveFlags & OBJ_MOVE_HIT_WALL) {
                o->oMoveAngleYaw = o->oWallAngle;//cur_obj_angle_to_home();
            }
            o->oGraphYOffset = approach_f32(o->oGraphYOffset, 175.0f, 10.0f, 10.0f);
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x100);
            o->oFaceAnglePitch += 0x600;
            /*if (o->oTimer > 60) {
                cur_obj_play_sound_2(SOUND_OBJ_SNUFIT_SHOOT);
                spawn_object_relative(0, 0, 50, 40, o, MODEL_GHOSTSAND_BALL, bhvSnufitBalls);
                o->oTimer = 0;
            }*/
            break;
    }
}


void bhv_shadow_boss_init(void) {
    obj_set_hitbox(o, &sShadowBossHitbox);
    o->os16F4 = 0xFF;
    o->os16F6 = 0xFF;
    o->os16F8 = 0xFF;
    //o->os16FA = o->oRoom - 7;
    o->oVelY = 30.0f;
    o->oObj100 = cur_obj_nearest_object_with_behavior(bhvMastersPlate);
    if (o->oObj100 == NULL)
        o->activeFlags = 0;
}



void bhv_shadow_boss_loop(void) {
    //o->oFC += 0x100;
    //o->os16F4 = absi(sins(o->oFC) * 255);
    //o->os16F8 = (o->os16F6 = o->os16F4);
    //print_text_fmt_int(20, 20, "%d", gPrevFrameObjectCount);
    switch (o->oAction) {
        case 0:
            if (gMarioState->input & INPUT_A_PRESSED) {
                o->oAction = 1;
                o->oForwardVel = 8.0f;
                break;
            }
            break;
        case 1:
            handle_shadow_boss_phases(o->oObj100->oBehParams2ndByte);
            break;
        case 2:
            break;
        case 3:
            if (o->oHealth) {
                cur_obj_update_floor_and_walls();
                cur_obj_move_standard(-78);
                o->oFaceAnglePitch = approach_s16_asymptotic(o->oFaceAnglePitch, 0x4000, 10);
                o->header.gfx.scale[2] = approach_f32(o->header.gfx.scale[2], 0.6f, 0.1f, 0.1f);
                o->header.gfx.scale[0] = approach_f32(o->header.gfx.scale[0], 0.8f, 0.05f, 0.05f);
                o->header.gfx.scale[1] = approach_f32(o->header.gfx.scale[1], 0.8f, 0.05f, 0.05f);
                o->oGraphYOffset = approach_f32(o->oGraphYOffset, 60.0f, 8.0f, 8.0f);
                if (o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
                    cur_obj_play_sound_2(SOUND_OBJ_DYING_ENEMY1);
                    o->oAction = 4;
                    o->oInteractType = INTERACT_DAMAGE;
                    gMarioState->pos[0] = o->oPosX;
                    gMarioState->pos[1] = o->oPosY + o->hitboxHeight;
                    gMarioState->pos[2] = o->oPosZ;
                    //vec3f_get_dist_and_angle(sBedroomCenter, gMarioState->pos, &dist, &pitch, &yaw);
                    //gMarioState->faceAngle[1] = yaw;
                    //gMarioState->faceAngle[1] = CL_object_to_point(gMarioObject, sBedroomCenter);
                    gMarioState->faceAngle[1] = cur_obj_angle_to_home();
                    gMarioState->vel[1] = 20.0f;
                    mario_set_forward_vel(gMarioState, 50.0f);
                    set_mario_action(gMarioState, ACT_CUTSCENE_JUMP, 1);
                }
            } else {
                cur_obj_play_sound_2(SOUND_OBJ_DYING_ENEMY1);
                cur_obj_become_intangible();
                o->oAction = 5;
            }
            break;
        case 4:
            if (o->oTimer > 10) {
                o->oFaceAnglePitch = approach_s16_asymptotic(o->oFaceAnglePitch, 0x0000, 10);
                o->header.gfx.scale[2] = approach_f32(o->header.gfx.scale[2], 1.0f, 0.05f, 0.05f);
                o->header.gfx.scale[0] = (o->header.gfx.scale[1] = o->header.gfx.scale[2]);
                o->oGraphYOffset = approach_f32(o->oGraphYOffset, 175.0f, 8.0f, 8.0f);
            }
            if (o->oTimer > 30) {
                o->oAction = 1;
                o->oVelY = 30.0f;
                o->oForwardVel = 10.0f;
                spawn_snufits(o->oObj100->oBehParams2ndByte - 1);
                if (o->oHealth == 3) {
                    o->oObj104 = spawn_object(o, MODEL_NONE, bhvFistSpawner);
                    o->oObj104->oObj104 = o;
                }
            }
            break;
        case 5:
            o->header.gfx.scale[2] = approach_f32(o->header.gfx.scale[2], 0.1f, 0.05f, 0.05f);
            o->header.gfx.scale[0] = (o->header.gfx.scale[1] = o->header.gfx.scale[2]);
            if (o->header.gfx.scale[2] == 0.1f) {
                o->activeFlags = 0;
            }
            break;
    }
    o->oInteractStatus = 0;
}