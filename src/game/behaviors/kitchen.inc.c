#include "game/camera.h"

struct ObjectHitbox sBarrelHitbox = {
    /* interactType: */ INTERACT_IGLOO_BARRIER,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 1,
    /* numLootCoins: */ 0,
    /* radius: */ 100,
    /* height: */ 240,
    /* hurtboxRadius: */ 100,
    /* hurtboxHeight: */ 240,
};



void bhv_burner_init(void) {
    if (o->oBehParams2ndByte == 1) {
        o->oFaceAngleRoll = 0x8000;
        o->oAction = 2;
    }

}


void bhv_burner_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oTimer > 45) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oFaceAngleRoll += 0x600;
            if (o->oFaceAngleRoll >= 0x8000) {
                o->oAction = 2;
                o->oFaceAngleRoll = 0x8000;
            }
            break;
        case 2:
            if (o->oTimer > 45) {
                o->oAction = 3;
            }
            break;
        case 3:
            o->oFaceAngleRoll -= 0x600;
            if (o->oFaceAngleRoll < 0) {
                o->oAction = 0;
                o->oFaceAngleRoll = 0;
            }
            break;
    }
}


void bhv_l1_cabinet_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioState->flags & (MARIO_KICKING | MARIO_PUNCHING) && gMarioState->wall != NULL && gMarioState->wall->object == o) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oFaceAngleYaw -= 0x4000;
            o->oFaceAngleYaw -= o->oFaceAngleYaw / 20;
            o->oFaceAngleYaw += 0x4000;
            if (o->oFaceAngleYaw == 0x4000) {
                o->oFaceAngleYaw = 0x4000;
                o->oAction = 2;
            }
            break;
        case 2:
            break;
    }
}


void bhv_l1_barrel_loop(void) {
    switch (o->oAction) {
        case 0:
            load_object_collision_model();
            if (gMarioState->flags & (MARIO_KICKING | MARIO_PUNCHING) && gMarioState->wall != NULL && gMarioState->wall->object == o 
            && absi(gMarioState->faceAngle[1] + 0x4000) < 0x2000) {
                o->oAction = 1;
                o->oMoveAngleYaw = 0xC000;
                o->oForwardVel = 5.0f;
                o->oFloatF8 = 1.0f;
                o->oCollisionDistance = 32767.0f;
                obj_set_hitbox(o, &sBarrelHitbox);
                //o->oGraphYOffset = 111.0f;
            }
            break;
        case 1:
            o->oF4 = approach_s16_symmetric(o->oF4, 0x900, 0x1C);
            o->oFloatF8 = approach_f32(o->oFloatF8, 1.05, 0.003f, 0.003f);
            o->oFaceAngleRoll += o->oF4;
            o->oForwardVel *= o->oFloatF8;
            o->oGraphYOffset = 256.86f * (absi((s16)o->oFaceAngleRoll) / 32768.0f);
            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(-78);
            if (o->oPosX <= 840.0f) {
                o->oForwardVel = 0;
                o->oVelX = (o->oVelZ = 0);
                o->oFaceAngleRoll = 0;
                o->oGraphYOffset = 0;
                o->oAction = 2;
                o->oCollisionDistance = 768.0f;
                queue_rumble_data(5, 80);
                cur_obj_shake_screen(2);
            }
            break;
        case 2:
            load_object_collision_model();
            break;
    }
}



void bhv_l1_shelf_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            obj = cur_obj_nearest_object_with_behavior(bhvL1Barrel);
            if (obj == NULL) {
                o->activeFlags = 0;
                break;
            }
            if (obj->oAction == 2) {
                o->oAction = 1;
            }
            break;
        case 1:
            //o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, 0x4000, 0x400);
            o->oFaceAnglePitch -= 0x4000;
            o->oFaceAnglePitch -= o->oFaceAnglePitch / 18;
            o->oFaceAnglePitch += 0x4000;
            if (o->oFaceAnglePitch == 0x4000) {
                o->oAction = 2;
                play_puzzle_jingle();
            }
            break;
        case 2:
            break;
    }
}


void bhv_kitchen_door_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 800.0f) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oFaceAngleYaw -= 0xA000;
            o->oFaceAngleYaw -= o->oFaceAngleYaw / 48;
            o->oFaceAngleYaw += 0xA000;
            if (o->oFaceAngleYaw == 0xA000) {
                o->oAction = 2;
            }
            break;
        case 2:
            break;
    }
}