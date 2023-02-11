#include "levels/lll/header.h"
s32 absi(s32 a0);
struct ObjectHitbox sClothesShotHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 1,
    /* numLootCoins:      */ 0,
    /* radius:            */ 72,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 42,
    /* hurtboxHeight:     */ 40,
};

struct ObjectHitbox sDustBunnyHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 1,
    /* numLootCoins:      */ 1,
    /* radius:            */ 125,
    /* height:            */ 150,
    /* hurtboxRadius:     */ 50,
    /* hurtboxHeight:     */ 75,
};



void bhv_dust_bunny_init(void) {
    obj_set_hitbox(o, &sDustBunnyHitbox);
    if (o->oBehParams2ndByte == 0) {
        o->oHomeX = -4800.0f;
    } else {
        o->oHomeX = 849.0f;
    }
    if (o->oBehParams2ndByte != 2) {
        o->oHomeZ = 16329.0f;
    } else {
        o->oHomeX = 500.0f;
        o->oHomeZ = -12127.0f;
    }
}


void bhv_dust_bunny_loop(void) {
    cur_obj_update_floor_and_walls();
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 600.0f) {
                o->oAction = 1;
                o->oForwardVel = 70.0f;
                o->oMoveAngleYaw = cur_obj_angle_to_home();
                if (absi(o->oAngleToMario - (s16)(o->oMoveAngleYaw + 0x3000)) <
                    absi(o->oAngleToMario - (s16)(o->oMoveAngleYaw - 0x3000))) {
                    o->oMoveAngleYaw -= 0x3000;
                } else {
                    o->oMoveAngleYaw += 0x3000;
                }
                cur_obj_init_animation(1);
            }
            break;
        case 1:
            o->oForwardVel = approach_f32_asymptotic(o->oForwardVel, 18.0f, 0.2f);
            CL_Move();
            if (o->oTimer > 20) {
                o->oAction = 0;
                cur_obj_init_animation(0);
            }
            break;
    }

    if (o->oInteractStatus & INT_STATUS_INTERACTED && o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
        spawn_mist_particles();
        obj_spawn_loot_yellow_coins(o, o->oNumLootCoins, 20.0f);
        o->activeFlags = 0;
        create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
    }
    o->oInteractStatus = 0;
}




void bhv_clothes_shot_init(void) {
    obj_set_hitbox(o, &sClothesShotHitbox);
    o->oForwardVel = 24.0f;
    // o->oMoveAngleYaw = o->parentObj->oFaceAngleYaw;
    // o->oMoveAnglePitch = -o->parentObj->oFaceAnglePitch;
    o->oPosY += 100.0f;

    // o->os16F4 = 0x00;
    // o->os16F6 = 0xA0;
    // o->os16F8 = 0xFF;
    s32 hue = CL_RandomMinMaxU16(0, 360);
    f32 sat = (random_float() * 0.3f) + 0.7f;
    f32 val = (random_float() * 0.2f) + 0.8f;
    CL_HSVtoRGB(hue, sat, val, &o->os16F4, &o->os16F6,  &o->os16F8);
}

void bhv_clothes_shot_loop(void) {
    CL_Move();
    o->oFaceAngleYaw += 0x200;
    o->oFaceAngleRoll += 0x400;
    // if (absi((u16)o->oAngleToMario - (u16)o->oMoveAngleYaw) < 0x2000) {
        o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x380);
    // }
    if (o->oBehParams2ndByte == 2) {
        f32 dist = lateral_dist_between_objects(o, gMarioObject);
        if (dist < 500.0f) {
            o->oForwardVel = 24.0f - ((500.0f - dist) / 50.0f);
        } else {
            o->oForwardVel = 24.0f;
        }
    }
    if (o->oTimer > 15) {
        cur_obj_update_floor_and_walls();
        if (o->oFloor != NULL && o->oFloorType == SURFACE_GENERAL_USE && o->oFloor->object != NULL) {
            o->oFloor->object->oAction = 1;
            o->parentObj->oAction = 3;
            o->activeFlags = 0;
            spawn_mist_particles();
            play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gGlobalSoundSource);
        }

        if (o->oMoveFlags & OBJ_MOVE_HIT_WALL || o->oInteractStatus & INT_STATUS_INTERACTED || o->oTimer > 1000) {
            o->activeFlags = 0;
            spawn_mist_particles();
        }
    }
}


extern Vec3f gComitCutscenePosVec;
extern Vec3f gComitCutsceneFocVec;

void const *sShirtsCollision[] = {
    laundry_shirts1_collision,
    laundry_shirts2_collision,
    laundry_shirts3_collision,
};

Vec3f sShirtsPos[3] = {
    {6413.0f, -15.0f, 8666.0f,},
    {8944.0f, -15.0f, 8904.0f,},
    {11860.0f, 520.0f, 7127.0f,},
};


Vec3f sShirtCamPos[3] = {
    {3141.0f, 1369.0f, 6131.0f},
    {7827.0f, 1929.0f, 13138.0f},
    {9848.0f, 1671.0f, 8919.0f},
};

s32 sShirtModels[3] = {
    MODEL_SHIRTS1, MODEL_SHIRTS2, MODEL_SHIRTS3
};

void bhv_laundry_shirts_init(void) {
    o->oFaceAngleYaw = 0;
    o->collisionData = segmented_to_virtual(sShirtsCollision[o->oBehParams2ndByte]);
    vec3f_copy(&o->oPosX, sShirtsPos[o->oBehParams2ndByte]);
    cur_obj_set_model(sShirtModels[o->oBehParams2ndByte]);
}


void bhv_laundry_shirts_loop(void) {
    if (o->oTimer > 20 && o->oOpacity != 0xFF) {
        o->oOpacity = approach_s16_symmetric(o->oOpacity, 0xFF, 0x6);
    }
}


void bhv_basement_dryer_init(void) {
    if (o->oBehParams2ndByte == 3) {
        o->oObjF8 = spawn_object(o, MODEL_NONE, bhvRoomObj);
    }
    if (!gIsConsole) {
        o->oDrawingDistance = 0x7FFF;
    }
}

void bhv_basement_dryer_loop(void) {
    if (o->oPosY < 1000.0f && gMarioState->pos[1] > 1000.0f && !gIsConsole) {
        cur_obj_hide();
    } else {
        cur_obj_unhide();
    }

    switch (o->oAction) {
        case 1:
            cur_obj_init_animation(0);
            if (o->oBehParams2ndByte != 3) {
                if (set_mario_npc_dialog(1)) {
                    o->oObjF4 = spawn_object(o, MODEL_SHIRTS1, bhvLaundryShirts);
                    o->oObjF4->oBehParams2ndByte = o->oBehParams2ndByte;
                    vec3f_copy(gComitCutsceneFocVec, gCamera->pos);
                    vec3f_copy(gComitCutscenePosVec, gCamera->focus);
                    o->oAction = 2;
                }
            } else {
                o->oObjF8->activeFlags = 0;
                o->oAction = 3;
            }
            o->collisionData = segmented_to_virtual(&basement_dryer_collision);
            break;
        case 2:
            gCamera->comitCutscene = 0xFF;
            gComitCutscenePosVec[0] = approach_f32_asymptotic(gComitCutscenePosVec[0], sShirtCamPos[o->oBehParams2ndByte][0], 0.2f);
            gComitCutscenePosVec[1] = approach_f32_asymptotic(gComitCutscenePosVec[1], sShirtCamPos[o->oBehParams2ndByte][1], 0.2f);
            gComitCutscenePosVec[2] = approach_f32_asymptotic(gComitCutscenePosVec[2], sShirtCamPos[o->oBehParams2ndByte][2], 0.2f);

            gComitCutsceneFocVec[0] = approach_f32_asymptotic(gComitCutsceneFocVec[0], sShirtsPos[o->oBehParams2ndByte][0], 0.2f);
            gComitCutsceneFocVec[1] = approach_f32_asymptotic(gComitCutsceneFocVec[1], sShirtsPos[o->oBehParams2ndByte][1], 0.2f);
            gComitCutsceneFocVec[2] = approach_f32_asymptotic(gComitCutsceneFocVec[2], sShirtsPos[o->oBehParams2ndByte][2], 0.2f);
            if (o->oTimer > 90) {
                o->oAction = 4;
                set_mario_npc_dialog(0);
            }
            break;
    }
}


void bhv_basement_washer_init(void) {
    if (!gIsConsole) {
        o->oDrawingDistance = 0x7FFF;
    }
}

void bhv_basement_washer_loop(void) {
    if (o->oPosY < 1000.0f && gMarioState->pos[1] > 1000.0f && !gIsConsole) {
        cur_obj_hide();
    } else {
        cur_obj_unhide();
    }

    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 1750.0f && absi((u16)o->oAngleToMario - (u16)o->oFaceAngleYaw) < 0x2C00) {
                if (o->oTimer > 5) {
                    cur_obj_init_animation(1);
                    o->oAction = 1;
                }
            } else {
                o->oTimer = 0;
            }

            break;
        case 1:
            if (cur_obj_set_anim_if_at_end(0)) {
                o->oAction = 2;
                o->oObjF4 = spawn_object(o, MODEL_CLOTHES_BALL, bhvClothesShot);
                if (o->oBehParams2ndByte == 2) {
                    o->oObjF4->oBehParams2ndByte = 2;
                }
            }
            break;
        case 2:
            if (cur_obj_set_anim_if_at_end(2)) {
                if (o->oObjF4->activeFlags == 0) {
                    o->oObjF4 = NULL;
                    o->oAction = 0;
                }
            }
            break;
    }
}