#include "game/save_file.h"
#include "buffers/buffers.h"
extern Vec3s gRoomColors[];

static struct ObjectHitbox sStarPieceHitbox = {
    /* interactType:      */ INTERACT_STAR_OR_KEY,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 80,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

struct ObjectHitbox sTokenHitbox = {
    /* interactType: */ INTERACT_COIN,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 1,
    /* health: */ 0,
    /* numLootCoins: */ 0,
    /* radius: */ 120,
    /* height: */ 78,
    /* hurtboxRadius: */ 0,
    /* hurtboxHeight: */ 0,
};

struct ObjectHitbox sSmallKeyHitbox = {
    /* interactType: */ INTERACT_STAR_OR_KEY,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 0,
    /* numLootCoins: */ 0,
    /* radius: */ 160,
    /* height: */ 100,
    /* hurtboxRadius: */ 160,
    /* hurtboxHeight: */ 100,
};


struct ObjectHitbox sBooCoinHitbox = {
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

static struct ObjectHitbox sBooCoinCageHitbox = {
    /* interactType: */ INTERACT_IGLOO_BARRIER,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 0,
    /* numLootCoins: */ 0,
    /* radius: */ 80,
    /* height: */ 70,
    /* hurtboxRadius: */ 0,
    /* hurtboxHeight: */ 0,
};


struct ObjectHitbox sCollectHeartHitbox = {
    /* interactType:      */ INTERACT_COIN,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 75,
    /* height:            */ 75,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};


Vec3f sPreviousMarioPos = {0, 0, 0};

u8 sTokenCoins[3] = {10, 50, 100};


void bhv_collect_heart_init(void) {
    o->oVelY = random_float() * 5.0f + 15 + (o->oCoinUnk110 / 2);
    o->oForwardVel = random_float() * 10.0f;
    o->oMoveAngleYaw = random_u16();

    obj_set_hitbox(o, &sCollectHeartHitbox);
    if (o->oF4 == 0) {
        cur_obj_become_intangible();
    }
}


void bhv_collect_heart_loop(void) {
    struct Surface *sp1C;

    if (o->oF4 == 0) {
        cur_obj_update_floor_and_walls();
        cur_obj_if_hit_wall_bounce_away();
        cur_obj_move_standard(-62);

        if ((sp1C = o->oFloor) != NULL) {
            if (o->oMoveFlags & OBJ_MOVE_ON_GROUND) {
                o->oSubAction = 1;
            }
            if (o->oSubAction == 1) {
                o->oBounciness = 0;
                if (sp1C->normal.y < 0.9) {
                    s16 sp1A = atan2s(sp1C->normal.z, sp1C->normal.x);
                    cur_obj_rotate_yaw_toward(sp1A, 0x400);
                }
            }
        }

        if (o->oVelY < 0) {
            cur_obj_become_tangible();
        }

        if (o->oMoveFlags & OBJ_MOVE_LANDED) {
            if (o->oMoveFlags & (OBJ_MOVE_ABOVE_DEATH_BARRIER | OBJ_MOVE_ABOVE_LAVA)) {
                obj_mark_for_deletion(o);
            }
        }

        o->oForwardVel = approach_f32_asymptotic(o->oForwardVel, 0.0f, 0.01f);

        if (cur_obj_wait_then_blink(400, 20)) {
            obj_mark_for_deletion(o);
        }
    }
    if (gCamera->comit2dcam == 1) {
        o->oPosZ = 0;
    }

    o->oFaceAngleYaw += 0x400;


    if (o->oInteractStatus & INT_STATUS_INTERACTED
        && !(o->oInteractStatus & INT_STATUS_TOUCHED_BOB_OMB)) {
        o->activeFlags = 0;
        gMarioState->healCounter += 4;
        cur_obj_play_sound_2(SOUND_GENERAL_HEART_SPIN);
    }

    o->oInteractStatus = 0;
}


void bhv_held_letter_loop(void) {
    if (o->oHeldState == HELD_HELD) {
        cur_obj_become_intangible();
        o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
        cur_obj_set_pos_relative(gMarioObject, -80.0f, 60.0f, 60.0f);
        o->oMoveAngleYaw = 0x8000;
    }
}


void bhv_generic_switch_loop(void) {
    if (o->oBehParams >> 24 == 1) {
        o->oRoom2 = 2;
    }
    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o && !(gMarioStates[0].action & MARIO_UNKNOWN_13)) {
                if (lateral_dist_between_objects(o, gMarioObject) < 127.5) {
                    o->oAction = 1;
                }
            }
            break;
        case 1:
            cur_obj_scale_over_time(2, 3, 1.5f, 0.2f);
            if (o->oTimer >= 3) {
                cur_obj_play_sound_2(SOUND_GENERAL2_PURPLE_SWITCH);
                o->oAction = 2;
                o->oF4 = 1;
                cur_obj_shake_screen(SHAKE_POS_SMALL);
                queue_rumble_data(5, 80);
            }
            break;
    }
}


void bhv_env_flame_init(void) {
    o->os16F4 = (o->oBehParams >> 24) & 0xFF;
    o->os16F6 = (o->oBehParams >> 16) & 0xFF;
    o->os16F8 = (o->oBehParams >> 8) & 0xFF;

    o->os16FA = o->oRoom - 7;
    if (o->os16FA < 0) {
        o->activeFlags = 0;
    }
}

void bhv_env_flame_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oTimer > 10) {
                o->oAction = 1;
            }
            break;
        case 1:
            gRoomColors[o->os16FA][0] = approach_s16_symmetric(gRoomColors[o->os16FA][0], o->os16F4, 0x8);
            gRoomColors[o->os16FA][1] = approach_s16_symmetric(gRoomColors[o->os16FA][1], o->os16F6, 0x8);
            gRoomColors[o->os16FA][2] = approach_s16_symmetric(gRoomColors[o->os16FA][2], o->os16F8, 0x8);
            break;
    }
}

void bhv_boocoin_cage_init(void) {
    struct Object *obj;
    o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
    switch (o->oBehParams2ndByte) {
        case 0:
            obj = spawn_object(o, MODEL_SMALL_KEY, bhvSmallKey);
            obj->oAction = 1;
            obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
            obj->oBehParams2ndByte = (o->oBehParams >> 8) & 0xFF;
            obj->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
            break;
        case 1:
            obj = spawn_object(o, MODEL_STAR_CURRENCY, bhvStar);
            obj->oAction = 1;
            obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
            obj->oBehParams = o->oBehParams << 16;
            obj->oPosY += 80.0f;
            obj->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
            obj_scale(o, 1.8f);
            break;
    }
    obj_set_hitbox(o, &sBooCoinCageHitbox);
}

void bhv_boocoin_cage_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            if (o->oF4 >= 5) {
                play_puzzle_jingle();
                gCamera->comitCutscene = 7 + o->oBehParams2ndByte;
                enable_time_stop();
                o->oAction = 1;
                o->oObjF8 = spawn_object(o, MODEL_NONE, bhvStaticObject);
                o->oObjF8->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
                vec3f_copy(&o->oFloatFC, gMarioState->pos);
                o->oFloat108 =  gMarioState->vel[1];
                o->oFloat10C = gMarioState->forwardVel;
                set_mario_npc_dialog(1);
            }
            break;
        case 1:
            set_mario_npc_dialog(1);
            vec3f_copy(gMarioState->pos, &o->oFloatFC);
            gMarioState->vel[1] = o->oFloat108;
            gMarioState->forwardVel = o->oFloat10C;
            if (o->oTimer == 15) {
                obj = spawn_object(o->oObjF8, MODEL_EXPLOSION, bhvExplosion);
                obj->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
                cur_obj_disable();
            }
            if (o->oTimer > 90) {
                gCamera->comitCutscene = 0;
                disable_time_stop();
                set_r_button_camera(gCamera);
                o->activeFlags = 0;
                set_mario_npc_dialog(0);
            }
            break;
    }
}



void bhv_boo_coin_init(void) {
   obj_set_hitbox(o, &sBooCoinHitbox);
}


void bhv_boo_coin_loop(void) {
    struct Object *obj = cur_obj_nearest_object_with_behavior(bhvBooCoinCage);
    struct Object *obj2;
    if (obj == NULL) {
        o->activeFlags = 0;
        return;
    }
    o->oFaceAngleYaw += 0x380;
    if (o->oInteractStatus) {
        obj2 = spawn_object(o, MODEL_SPARKLES, bhvGoldenCoinSparkles);
        obj2->oPosY -= 50.0f;
        o->activeFlags = 0;
        obj->oF4++;
        if (obj->oF4 != 5) {
            spawn_orange_number(obj->oF4, 0, 0, 0);
        }
        play_sound(SOUND_MENU_COLLECT_SECRET + (((u8) obj->oF4 - 1) << 16), gGlobalSoundSource);
    }
}


void bhv_deathwarp_init(void) {
    if (gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnLevel != 0) {
        o->oPosX = (f32)gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnPos[0];
        o->oPosY = (f32)gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnPos[1];
        o->oPosZ = (f32)gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnPos[2];
        //vec3f_copy(gMarioState->pos, &o->oPosX);
    }

}

void bhv_deathwarp_loop(void) {
    Vec3f pos;
    s16 angle;
    struct MarioState *m = gMarioState;
    if (gMarioCurrentRoom != gMarioPreviousRoom) {
        angle = atan2s(m->pos[2] - sPreviousMarioPos[2], m->pos[0] - sPreviousMarioPos[0]);
        if (absi((u16)(angle) - (u16)(angle & 0xE000)) < 0x1000) {
            angle &= 0xE000;
        } else {
            angle = (angle & 0xE000) + 0x2000;
        }
        o->oFaceAngleYaw = angle;
        pos[0] = m->pos[0] + (sins(angle) * 150.0f);
        pos[2] = m->pos[2] + (coss(angle) * 150.0f);
        pos[1] = m->pos[1] + 50.0f;
        vec3f_copy(&o->oPosX, pos);
        gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnPos[0] = (s16)pos[0];
        gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnPos[1] = (s16)pos[1];
        gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnPos[2] = (s16)pos[2];
        gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnLevel = gCurrLevelNum;
        gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnArea = gCurrAreaIndex;
    }
    o->oRoom = (gMarioPreviousRoom = gMarioCurrentRoom);
    vec3f_copy(sPreviousMarioPos, m->pos);
}


void bhv_broken_key_init(void) {
    o->oAnimState = (o->oBehParams >> 24) & 0xFF;
}

void bhv_broken_key_loop(void) {
    if ((o->oBehParams >> 24) == 1) {
        cur_obj_scale(0.5f);
        obj_set_hitbox(o, &sSmallKeyHitbox);
        if (o->oInteractStatus & INT_STATUS_INTERACTED) {
            o->activeFlags = 0;
            o->oInteractStatus = 0;
        }
    } else {
        cur_obj_scale(0.3f);
        if (o->oAngleVelYaw > 0x400)
            o->oAngleVelYaw -= 0x100;
        o->oFaceAngleYaw += o->oAngleVelYaw;
        //o->oFaceAngleRoll = -0x4000;
        //o->oGraphYOffset = 165.0f;
        if (o->oAction == 0) {
            o->oFaceAngleYaw += 0x400;
            if (o->oTimer == 0)
                o->oVelY = 70.0f;
            spawn_sparkle_particles(3, 200, 80, -60);
            spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(78);
            if (o->oMoveFlags & OBJ_MOVE_ON_GROUND)
                o->oAction++;
            else if (o->oMoveFlags & OBJ_MOVE_LANDED)
                cur_obj_play_sound_2(SOUND_GENERAL_UNKNOWN3);
        } else {
            obj_set_hitbox(o, &sSmallKeyHitbox);
            o->oFaceAngleYaw += 0x400;
            if (o->oInteractStatus & INT_STATUS_INTERACTED) {
                o->activeFlags = 0;
                o->oInteractStatus = 0;
            }
        }
    }
}

void bhv_big_key_loop(void) {
    cur_obj_scale(0.3f);
    if (o->oAngleVelYaw > 0x400)
        o->oAngleVelYaw -= 0x100;
    o->oFaceAngleYaw += o->oAngleVelYaw;
    //o->oFaceAngleRoll = -0x4000;
    //o->oGraphYOffset = 165.0f;
    if (o->oAction == 0) {
        o->oFaceAngleYaw += 0x400;
        if (o->oTimer == 0)
            o->oVelY = 70.0f;
        spawn_sparkle_particles(3, 200, 80, -60);
        spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
        cur_obj_update_floor_and_walls();
        cur_obj_move_standard(78);
        if (o->oMoveFlags & OBJ_MOVE_ON_GROUND)
            o->oAction++;
        else if (o->oMoveFlags & OBJ_MOVE_LANDED)
            cur_obj_play_sound_2(SOUND_GENERAL_UNKNOWN3);
    } else {
        obj_set_hitbox(o, &sSmallKeyHitbox);
        o->oFaceAngleYaw += 0x400;
        if (o->oInteractStatus & INT_STATUS_INTERACTED) {
            o->activeFlags = 0;
            o->oInteractStatus = 0;
        }
    }
}


void bhv_small_key_loop(void) {
    cur_obj_scale(0.3f);
    if (o->oAngleVelYaw > 0x400)
        o->oAngleVelYaw -= 0x100;
    o->oFaceAngleYaw += o->oAngleVelYaw;
    //o->oFaceAngleRoll = -0x4000;
    //o->oGraphYOffset = 165.0f;
    if (o->oAction == 0) {
        if (o->oTimer == 0)
            o->oVelY = 70.0f;
        spawn_sparkle_particles(3, 200, 80, -60);
        spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
        cur_obj_update_floor_and_walls();
        cur_obj_move_standard(78);
        if (o->oMoveFlags & OBJ_MOVE_ON_GROUND)
            o->oAction++;
        else if (o->oMoveFlags & OBJ_MOVE_LANDED)
            cur_obj_play_sound_2(SOUND_GENERAL_UNKNOWN3);
    } else {
        obj_set_hitbox(o, &sSmallKeyHitbox);
        if (o->oInteractStatus & INT_STATUS_INTERACTED) {
            o->activeFlags = 0;
            o->oInteractStatus = 0;
        }
    }
}



void bhv_token_init(void) {
    u8 challenge;
    obj_set_hitbox(o, &sTokenHitbox);
    o->oDamageOrCoinValue = sTokenCoins[o->oBehParams2ndByte];
    challenge = (o->oBehParams >> 8) & 0xFF;
    if (save_file_get_challenges(challenge / 32) & (1 << (challenge % 32))) {
        o->activeFlags = 0;
    }
}


void bhv_token_loop(void) {
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        spawn_object(o, MODEL_SPARKLES, bhvGoldenCoinSparkles);
        o->activeFlags = 0;
        save_file_set_challenges((o->oBehParams >> 8) & 0xFF);
    }
}


void bhv_star_piece_init(void) {
    s8 pieceId = (o->oBehParams >> 24) & 0xFF;
    if (save_file_get_star_piece() & (1 << pieceId)) {
        o->activeFlags = 0;
    }

    o->os16F6 = 0x200;

    obj_set_hitbox(o, &sStarPieceHitbox);
}

void bhv_star_piece_loop(void) {
    s8 pieceId = (o->oBehParams >> 24) & 0xFF;
    if (save_file_get_star_piece() & (1 << pieceId)) {
        o->activeFlags = 0;
    }

    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        o->activeFlags = 0;
        o->oInteractStatus = 0;
        //save_file_set_star_piece(o->oBehParams >> 24);
    }

    if (o->oBehParams2ndByte == 1) {
        if (!(save_file_get_boos() & 1)) {
            cur_obj_disable();
        } else {
            cur_obj_enable();
        }
    } else {
        o->os16F8 += 0x300;
        o->oGraphYOffset = 20.0f + (sins(o->os16F8) * 20.0f);
        o->oFaceAngleYaw += 0x400;
        o->oFaceAnglePitch += o->os16F4;
        o->os16F4 = approach_s16_symmetric(o->os16F4, o->os16F6, 0x20);
        if (o->oTimer > 30) {
            o->os16F6 = CL_RandomMinMaxU16(0x300, 0x500);
        }
    }
}


void basic_npc_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oInteractStatus == INT_STATUS_INTERACTED) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x600);
            if ((s16) o->oMoveAngleYaw == (s16) o->oAngleToMario) {
                o->oAction = 2;
            }
            cur_obj_play_sound_2(SOUND_ACTION_READ_SIGN);
            break;
        case 2:
            if (CL_NPC_Dialog(o->oBehParams2ndByte)) {
                o->oAction = 0;
            }
            break;
    }
}

void toy_toad_loop(void) {
    s32 dialogResponse;
    switch (o->oAction) {
        case 0:
            if (o->oInteractStatus == INT_STATUS_INTERACTED) {
                o->oAction = 1;
                o->os16F4 = o->oMoveAngleYaw;
                if (o->oAngleToMario - o->oMoveAngleYaw > 0) {
                    o->os16F8 = 0x600;
                } else {
                    o->os16F8 = -0x600;
                }
            }
            break;
        case 1:
            if (!(o->os16F6)) {
                o->oMoveAngleYaw += o->os16F8;
                if (absi(o->oMoveAngleYaw - o->os16F4) >= 0x10000) {
                    o->os16F6 = 1;
                }
            } else {
                o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x600);
                if ((s16) o->oMoveAngleYaw == (s16) o->oAngleToMario) {
                    if (o->oBehParams2ndByte && !(save_file_get_newflags(0) & SAVE_NEW_FLAG_CITY_BAND_BOUGHT)) {
                        o->oAction = 4;
                    } else {
                        o->oAction = 2;
                    }
                }
                cur_obj_play_sound_2(SOUND_ACTION_READ_SIGN);
            }
            break;
        case 2:
            if (CL_NPC_Dialog(o->oBehParams >> 24)) {
                o->oAction = 3;
            } else {
                o->os16100 += 0x800;
                o->oFaceAnglePitch = 0xC00 + (coss(o->os16100) * 0x1000);
                o->oGraphYOffset = 30.0f + (sins(o->os16100) * 25.0f);
                o->oPosX = o->oHomeX - 35.0f * sins(o->oFaceAngleYaw) + (15.0f * sins(o->oFaceAngleYaw) * coss(o->os16100));
                o->oPosZ = o->oHomeZ - 35.0f * coss(o->oFaceAngleYaw) + (15.0f * coss(o->oFaceAngleYaw) * coss(o->os16100));
                o->oFloatFC = 0.75f + (0.05f * sins(o->os16100));
                obj_scale(o, o->oFloatFC);
            }
            break;
        case 3:
            o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, 0, 0x200);
            o->oPosX = approach_f32_symmetric(o->oPosX, o->oHomeX, 3.0f);
            o->oPosZ = approach_f32_symmetric(o->oPosZ, o->oHomeZ, 3.0f);
            o->oGraphYOffset = approach_f32_symmetric(o->oGraphYOffset, 0, 6.0f);
            if (o->oPosX == o->oHomeX && o->oPosZ == o->oHomeZ) {
                o->oAction = 0;
                o->os16F6 = 0;
                o->os16100 = 0;
                o->oFaceAnglePitch = 0;
                o->oGraphYOffset = 0;
                o->oPosX = o->oHomeX;
                o->oPosZ = o->oHomeZ;
                o->oFloatFC = 0.75f;
                obj_scale(o, o->oFloatFC);
            }
            break;
        case 4:
            dialogResponse = CL_NPC_Dialog_Options(10);
            if (dialogResponse) {
                if (dialogResponse == 1) {
                    if (gMarioState->numStars >= 2) {
                        save_file_set_newflags(SAVE_NEW_FLAG_CITY_BAND_BOUGHT, 0);
                        o->oBehParams2ndByte = 0;
                        o->oAction = 2;
                    } else {
                        o->oBehParams = 11 << 24;
                        o->oAction = 2;
                    }
                } else {
                    o->oBehParams = 13 << 24;
                    o->oAction = 2;
                }
            } else {
                o->os16100 += 0x800;
                o->oFaceAnglePitch = 0xC00 + (coss(o->os16100) * 0x1000);
                o->oGraphYOffset = 30.0f + (sins(o->os16100) * 25.0f);
                o->oPosX = o->oHomeX - 35.0f * sins(o->oFaceAngleYaw) + (15.0f * sins(o->oFaceAngleYaw) * coss(o->os16100));
                o->oPosZ = o->oHomeZ - 35.0f * coss(o->oFaceAngleYaw) + (15.0f * coss(o->oFaceAngleYaw) * coss(o->os16100));
                o->oFloatFC = 0.75f + (0.05f * sins(o->os16100));
                obj_scale(o, o->oFloatFC);
            }
            break;
    }
}


void toad_friend_l1_loop(void) {
    if (o->oF4) {
        switch (o->oAction) {
            case 0:
                if (o->oF4 == 1) {
                    set_mario_npc_dialog(1);
                    CL_Move();
                    o->oForwardVel = 22.0f;
                    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x1000);
                    o->oFaceAngleYaw = o->oMoveAngleYaw + 0x2000;
                    if (o->oDistanceToMario < 150.0f) {
                        o->oAction = 2;
                        play_music(0, SEQUENCE_ARGS(4, SEQ_PROF_T), 0);
                    }
                } else {
                    if (o->oInteractStatus == INT_STATUS_INTERACTED)
                        o->oAction = 1;
                }
                break;
            case 1:
                o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x1000);
                if ((s16) o->oMoveAngleYaw == (s16) o->oAngleToMario) {
                    o->oAction = 2;
                    play_music(0, SEQUENCE_ARGS(4, SEQ_PROF_T), 0);
                }

                cur_obj_play_sound_2(SOUND_ACTION_READ_SIGN);
                break;
            case 2:
                if (CL_NPC_Dialog(o->oBehParams2ndByte)) {
                    if (o->oF4 == 1) {
                        o->oBehParams2ndByte = 5;
                    }
                    o->oF4 = 2;
                    o->oAction = 0;
                    stop_background_music(SEQUENCE_ARGS(4, SEQ_PROF_T));
                }
                break;
        }
    }
    o->oInteractStatus = 0;
}

extern Vec3f sToadFriendWarp1;

void bhv_friend_toad_loop(void) {
    switch (gCurrLevelNum) {
        case LEVEL_BOB:
            toad_friend_l1_loop();
            if (save_file_get_newflags(1) & SAVE_TOAD_FLAG_INTRODUCTION) {
                o->oF4 = 2;
            }
            if (save_file_get_newflags(1) & SAVE_TOAD_FLAG_FOUND_FIRST_BOO) {
                vec3f_copy(&o->oPosX, sToadFriendWarp1);
                o->oRoom = 13;
            }
            break;
        case LEVEL_WF:
            break;
    }
}



void bhv_friend_toad_init(void) {
        //o->oToadMessageDialogId = (o->oBehParams >> 24) & 0xFF;
        //o->oToadMessageRecentlyTalked = FALSE;
        //o->oToadMessageState = TOAD_MESSAGE_FADED;
        //o->oOpacity = 81;
        o->oInteractionSubtype = INT_SUBTYPE_NPC;
}