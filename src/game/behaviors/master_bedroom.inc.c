#include "game/object_helpers.h"
extern Vec3s gRoomColors[];
struct ObjectHitbox sShadowBossHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 2,
    /* radius:            */ 170,
    /* height:            */ 340,
    /* hurtboxRadius:     */ 170,
    /* hurtboxHeight:     */ 340,
};


void bhv_master_pressure_plate_init(void) {
   //o->os16F4 = 170;
   //o->os16F6 = 170;
   //o->os16F8 = 170;
   vec3s_set(&o->os16F4, 100, 100, 100);
}

void bhv_master_pressure_plate_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oPosY = approach_f32(o->oPosY, o->oHomeY, 2.5f, 2.5f);
            if (gMarioObject->platform == o) {
                o->oAction = 1;
                //sServantsLights = 1;
            }
            gRoomColors[5][0] = approach_s16_symmetric(gRoomColors[5][0], 16, 0x1);
            gRoomColors[5][2] = (gRoomColors[5][1] = gRoomColors[5][0]);
            o->os16F4 = approach_s16_symmetric(o->os16F4, 100, 0x10);
            o->os16F6 = (o->os16F8 = o->os16F4);
            break;
        case 1:
            o->oPosY = approach_f32(o->oPosY, o->oHomeY - 10.0f, 2.5f, 2.5f);
            gRoomColors[5][0] = approach_s16_symmetric(gRoomColors[5][0], 180, 20);
            gRoomColors[5][2] = (gRoomColors[5][1] = gRoomColors[5][0]);
            o->os16F4 = approach_s16_symmetric(o->os16F4, 255, 0x10);
            o->os16F6 = (o->os16F8 = o->os16F4);
            if (gMarioObject->platform != o) {
                o->oAction = 0;
                //sServantsLights = 0;
            }
            break;
    }
}


void bhv_shadow_boss_init(void) {
    obj_set_hitbox(o, &sShadowBossHitbox);
    o->os16F4 = 0xFF;
    o->os16F6 = 0xFF;
    o->os16F8 = 0xFF;
    o->os16FA = o->oRoom - 7;
    o->oVelY = 30.0f;
    o->oForwardVel = 18.0f;
    //o->oGravity = 0;
    //o->oVelY = 0;
}



void bhv_shadow_boss_loop(void) {
    //if (gMarioCurrentRoom != o->oRoom) {
    //    return;
    //}
    gRoomColors[o->os16FA][0] = approach_s16_symmetric(gRoomColors[o->os16FA][0], 10, 0x8);
    //gRoomColors[o->os16FA][1] = approach_s16_symmetric(gRoomColors[o->os16FA][1], 10, 0x8);
    //gRoomColors[o->os16FA][2] = approach_s16_symmetric(gRoomColors[o->os16FA][2], 10, 0x8);
    gRoomColors[o->os16FA][2] = (gRoomColors[o->os16FA][1] = gRoomColors[o->os16FA][0]);
    o->oFC += 0x100;
    o->os16F4 = absi(sins(o->oFC) * 255);
    o->os16F8 = (o->os16F6 = o->os16F4);
    switch (o->oAction) {
        case 0:
            if (gMarioState->input & INPUT_A_PRESSED) {
                o->oAction = 1;
                o->oForwardVel = 8.0f;
                break;
            }
            break;
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
            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(-78);
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x100);
            if (o->oTimer > 60) {
                cur_obj_play_sound_2(SOUND_OBJ_SNUFIT_SHOOT);
                spawn_object_relative(0, 0, -80, 40, o, MODEL_GHOSTSAND_BALL, bhvSnufitBalls);
                o->oTimer = 0;
            }
            break;
    }
    o->oInteractStatus = 0;
}