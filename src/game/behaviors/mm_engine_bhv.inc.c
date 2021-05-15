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



Vec3f sPreviousMarioPos = {0, 0, 0};

u8 sTokenCoins[3] = {10, 50, 100};



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
    switch (o->oBehParams2ndByte) {
        case 0:
            obj = spawn_object(o, MODEL_SMALL_KEY, bhvSmallKey);
            obj->oAction = 1;
            obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
            obj->oBehParams2ndByte = (o->oBehParams >> 8) & 0xFF;
            break;
    }
    obj_set_hitbox(o, &sBooCoinCageHitbox);
}

void bhv_boocoin_cage_loop(void) {
    if (o->oF4 >= 5) {
        o->activeFlags = 0;
        play_puzzle_jingle();
        //cutscene_object_without_dialog(o, CUTSCENE_STAR_SPAWN);
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
        vec3f_copy(gMarioState->pos, &o->oPosX);
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
                cur_obj_play_sound_2(SOUND_GENERAL_UNKNOWN3_2);
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
            cur_obj_play_sound_2(SOUND_GENERAL_UNKNOWN3_2);
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
            cur_obj_play_sound_2(SOUND_GENERAL_UNKNOWN3_2);
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
        o->oFaceAngleYaw += 0x400;
        o->oFaceAnglePitch += 0x400;
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