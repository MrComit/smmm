#include "game/object_helpers.h"
extern Vec3s gRoomColors[];
struct ObjectHitbox sShadowBossHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 5,
    /* numLootCoins:      */ 2,
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
    o->oOpacity = 0x40;
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
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 0xFF, 0x10);
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
                for (i = 0; i < 5; i++) {
                    spawn_object_relative(0, 400*(i+1), 100, 0, o, MODEL_LIGHT_BUBBLE, bhvLightBubble);
                }
            }
            o->os16F4 = approach_s16_symmetric(o->os16F4, 160, 0x10);
            o->os16F6 = (o->os16F8 = o->os16F4);
            break;
        case 1:
            k = o->oBehParams2ndByte + 1;
            o->oPosY = approach_f32(o->oPosY, o->oHomeY - 10.0f, 2.5f, 2.5f);
            o->os16F4 = approach_s16_symmetric(o->os16F4, sMastersFlames[o->oBehParams2ndByte][0], 0x6);
            o->os16F6 = approach_s16_symmetric(o->os16F6, sMastersFlames[o->oBehParams2ndByte][1], 0x6);
            o->os16F8 = approach_s16_symmetric(o->os16F8, sMastersFlames[o->oBehParams2ndByte][2], 0x6);
            if (gMarioObject->platform != o) {
                o->oAction = 2;
                o->oBehParams2ndByte++;
                if (o->oBehParams2ndByte > 5) {
                    o->oBehParams2ndByte = 5;
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
            o->os16F4 = 20 + (80/(6 - o->oFC));
            o->os16F6 = (o->os16F8 = o->os16F4);
            o->oPosY = o->oHomeY - (2.0f*(5 - o->oFC));
            if (o->oFC >= 5) {
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
}


void bhv_shadow_boss_init(void) {
    obj_set_hitbox(o, &sShadowBossHitbox);
    o->os16F4 = 0xFF;
    o->os16F6 = 0xFF;
    o->os16F8 = 0xFF;
    //o->os16FA = o->oRoom - 7;
    o->oVelY = 30.0f;
    o->oForwardVel = 18.0f;
    //o->oGravity = 0;
    //o->oVelY = 0;
}



void bhv_shadow_boss_loop(void) {
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
                spawn_object_relative(0, 0, 50, 40, o, MODEL_GHOSTSAND_BALL, bhvSnufitBalls);
                o->oTimer = 0;
            }
            break;
        case 3:
            if (o->oHealth) {
                cur_obj_update_floor_and_walls();
                cur_obj_move_standard(-78);
                o->oFaceAnglePitch = approach_s16_asymptotic(o->oFaceAnglePitch, 0x4000, 10);
                o->header.gfx.scale[2] = approach_f32(o->header.gfx.scale[2], 0.8f, 0.05f, 0.05f);
                o->header.gfx.scale[0] = approach_f32(o->header.gfx.scale[0], 0.9f, 0.025f, 0.025f);
                o->header.gfx.scale[1] = approach_f32(o->header.gfx.scale[1], 0.9f, 0.025f, 0.025f);
                o->oGraphYOffset = approach_f32(o->oGraphYOffset, 140.0f, 8.0f, 8.0f);
                if (o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
                    cur_obj_play_sound_2(SOUND_OBJ_DYING_ENEMY1);
                    o->oAction = 4;
                    o->oInteractType = INTERACT_DAMAGE;
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
                o->oAction = 2;
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