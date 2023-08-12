#include "levels/bob/tv_static/geo_header.h"
#include "levels/sl/header.h"
struct ObjectHitbox sRemoteHitbox = {
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

static struct ObjectHitbox sTVPeepaHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 90,
    /* height:            */ 60,
    /* hurtboxRadius:     */ 70,
    /* hurtboxHeight:     */ 50,
};

u8 sPeepaNumbers[6] = {0, 1, 2, 3, 4, 5};


void bhv_remote_init(void) {
   obj_set_hitbox(o, &sRemoteHitbox);
   o->oFloatF4 = 1.0f;
}



void bhv_remote_loop(void) {
    struct Object *obj = cur_obj_nearest_object_with_behavior(bhvTVStatic);
    struct Object *obj2;
    if (obj == NULL)
        return o->activeFlags = 0;
    o->oFaceAngleYaw += 0x380;
    switch (o->oAction) {
        case 0:
            if (obj->oAnimState == 0) {
                o->oAction = 1;
                o->oAnimState = 1;
            }
            if (o->oInteractStatus) {
                obj->oAnimState = 0;
                obj2 = spawn_object(o, MODEL_SPARKLES, bhvGoldenCoinSparkles);
                obj2->oPosY -= 50.0f;
                o->activeFlags = 0;
                play_sound(SOUND_GENERAL_UNKNOWN3, gGlobalSoundSource);
                play_sound(SOUND_GENERAL2_PURPLE_SWITCH, gGlobalSoundSource);
            }
            o->oFloatF4 = approach_f32(o->oFloatF4, 1.0f, 0.05f, 0.05f);
            obj_scale(o, o->oFloatF4);
            break;
        case 1:
            o->oFloatF4 = approach_f32(o->oFloatF4, 0.6f, 0.05f, 0.05f);
            obj_scale(o, o->oFloatF4);
            if (obj->oAnimState == 1) {
                o->oAction = 0;
                o->oAnimState = 0;
            }
            break;
    }
    o->oInteractStatus = 0;
}

void tv_spawn_peepa(s32 count) {
    s32 i;
    for (i = 0; i < count; i++) {
        spawn_object_relative(count << 8 | i, 0, -150, -200, o, MODEL_PEEPA, bhvTVPeepa);
    }
}


void bhv_tv_static_loop(void) {
    u8 *texture = segmented_to_virtual(&tv_static_i8_static_i4);
    s32 i;
    if (o->oAnimState == 0) {
        for (i = 0; i < 2048; i++) {
            texture[i] = random_u16() & 0xFF;
        }
        switch (o->oAction) {
            case 0:
                if (o->oDistanceToMario < 1500.0f) {
                    CL_scramble_array(&sPeepaNumbers, o->oBehParams2ndByte + 3);
                    tv_spawn_peepa(o->oBehParams2ndByte + 3);
                    o->oAction = 1;
                }
                break;
            case 1:
                if (count_room_objects_with_behavior(bhvTVPeepa, o->oRoom) == 0) {
                    o->oAnimState = 1;
                    o->oF4 = 0;
                    o->oAction = 0;
                    o->oBehParams2ndByte++;
                    if (o->oBehParams2ndByte >= 4) {
                        o->activeFlags = 0;
                    }
                }
                break;
        }
    }
}

extern Vec3s gRoomColors[];

static void const *sCushionCollision[] = {
    cushion_collision,
    blue_cushion_collision,
    purple_cushion_collision,
};

void bhv_cushion_init(void) {
   o->oFloatF4 = 1.0f;
   o->collisionData = segmented_to_virtual(sCushionCollision[o->oBehParams2ndByte]);
}


void bhv_cushion_loop(void) {
    struct MarioState *m = gMarioState;

    if (gCurrLevelNum == LEVEL_SL) {
        o->oOpacity = gRoomColors[0][0];
    }

    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o) {
                play_sound(SOUND_ACTION_BOUNCE_OFF_OBJECT, m->marioObj->header.gfx.cameraToObject);
                m->pos[1] = m->floorHeight + 20.0f;
                m->vel[1] = 80.0f;
                m->flags & MARIO_UNKNOWN_08;
                reset_mario_pitch(m);
                play_sound(SOUND_MARIO_TWIRL_BOUNCE, m->marioObj->header.gfx.cameraToObject);
                drop_and_set_mario_action(m, ACT_TWIRLING, 0);
                o->oAction = 1;
            }
            break;
        case 1:
            o->oFloatF4 -= 0.15f;
            o->header.gfx.scale[1] = o->oFloatF4;
            o->header.gfx.scale[0] = approach_f32(o->header.gfx.scale[0], 1.1f, 0.04f, 0.04f);
            o->header.gfx.scale[2] = o->header.gfx.scale[0];
            if (o->oFloatF4 <= 0.6f) {
                o->oFloatF4 = 0.6f;
                o->oAction = 2;
            }
            break;
        case 2:
            o->oFloatF4 += 0.18f;
            o->header.gfx.scale[1] = o->oFloatF4;
            o->header.gfx.scale[0] = approach_f32(o->header.gfx.scale[0], 0.8f, 0.07f, 0.07f);
            o->header.gfx.scale[2] = o->header.gfx.scale[0];
            if (o->oFloatF4 >= 1.4f) {
                o->oFloatF4 = 1.4f;
                o->oAction = 3;
            }
            break;
        case 3:
            o->oFloatF4 -= 0.08f;
            o->header.gfx.scale[0] = approach_f32(o->header.gfx.scale[0], 1.0f, 0.04f, 0.04f);
            o->header.gfx.scale[2] = o->header.gfx.scale[0];
            if (o->oFloatF4 <= 1.0f) {
                o->header.gfx.scale[0] = (o->header.gfx.scale[2] = 1.0f);
                o->oFloatF4 = 1.0f;
                o->oAction = 0;
            }
            o->header.gfx.scale[1] = o->oFloatF4;
            break;
    }
}


void bhv_tv_peepa_init(void) {
    s16 beh1 = o->oBehParams2ndByte >> 8;
    s16 beh2 = o->oBehParams2ndByte & 0xFF;
    o->oForwardVel = 15.0f;
    o->oF8 = beh2 * 10;
    o->oF4 = beh2 * 0x2000;
    o->oFC = beh2 * (0x10000 / beh1);
    o->oHomeX = -4614.0f;
    o->oHomeZ = 6800.0f;

    o->oBehParams2ndByte = sPeepaNumbers[beh2];
    o->prevObj = spawn_object(o, MODEL_NUMBER, bhvPeepaNumber);
    o->prevObj->oAnimState = o->oBehParams2ndByte + 1;
}

void bhv_tv_peepa_loop(void) {
    struct Object *obj;
    s32 i, k;
    o->oF4 += 0x800;
    o->oGraphYOffset = 25.0f * sins(o->oF4);
    switch (o->oAction) {
        case 0:
            if (o->oTimer > o->oF8)
                CL_Move();
            if (o->oTimer > 70) {
                o->oAction = 1;
                o->oFloat100 = o->oHomeX + (324.0f * sins(o->oFC));
                o->oFloat104 = o->oHomeZ + (324.0f * coss(o->oFC));
            }
            break;
        case 1:
            o->oPosX = approach_f32(o->oPosX, o->oFloat100, 20.0f, 20.0f);
            o->oPosZ = approach_f32(o->oPosZ, o->oFloat104, 20.0f, 20.0f);
            if (o->oTimer > 60) {
                o->oAction = 2;
                //o->prevObj->activeFlags = 0;
            }
            break;
        case 2:
            o->o108 = approach_s16_symmetric(o->o108, 0x800, 0x40);
            o->oFC += o->o108;
            o->oPosX = o->oHomeX + (324.0f * sins(o->oFC));
            o->oPosZ = o->oHomeZ + (324.0f * coss(o->oFC));
                if (o->oBehParams2ndByte == 0 && gGlobalTimer % 4 == 0) {
                    cur_obj_play_sound_2(SOUND_GENERAL_SWISH_AIR);
                }
            if (o->oTimer > 120) {
                o->oAction = 3;
                o->prevObj->activeFlags = 0;
                if (o->oBehParams2ndByte == 0) {
                    // cur_obj_play_sound_2(SOUND_OBJ_BOO_LAUGH_SHORT);
                    play_sound(SOUND_OBJ_BOO_LAUGH_LONG, gGlobalSoundSource);
                }
                obj_set_hitbox(o, &sTVPeepaHitbox);
            }
            break;
        case 3:
            obj = cur_obj_nearest_object_with_behavior(bhvTVStatic);
            if (obj == NULL) {
                o->activeFlags = 0;
                break;
            }
            o->oMoveAngleYaw += 0x600;
            if (o->oInteractStatus & INT_STATUS_INTERACTED && o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
                for (i = 0; i < o->oBehParams2ndByte; i++) {
                    if (!(obj->oF4 & 1 << i)) {
                        k = 1;
                        break;
                    } else {
                        k = 0;
                    }
                }

                if (k) {
                    CL_get_hit(gMarioState, o, 2);
                    play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                } else {
                    obj_spawn_loot_yellow_coins(o, o->oNumLootCoins, 20.0f);
                    play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gGlobalSoundSource);
                }
                spawn_mist_particles();
                o->activeFlags = 0;
                create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
                obj->oF4 |= 1 << o->oBehParams2ndByte;
            }
            o->oInteractStatus = 0;
            break;
    }
}


void bhv_peepa_number_loop(void) {
    if (o->parentObj == o)
        return o->activeFlags = 0;


    if (o->oF4 == 1) {
        o->oPosX = o->parentObj->oPosX + (sins(gCamera->yaw + 0x4000) * 30.0f);
        o->oPosZ = o->parentObj->oPosZ + (coss(gCamera->yaw + 0x4000) * 30.0f);
    } else if (o->oF4 == 2) {
        o->oPosX = o->parentObj->oPosX + (sins(gCamera->yaw - 0x4000) * 30.0f);
        o->oPosZ = o->parentObj->oPosZ + (coss(gCamera->yaw - 0x4000) * 30.0f);
    } else {
        o->oPosX = o->parentObj->oPosX;
        o->oPosZ = o->parentObj->oPosZ;
    }

        o->oPosY = o->parentObj->oPosY + o->parentObj->oGraphYOffset + 100.0f;
}