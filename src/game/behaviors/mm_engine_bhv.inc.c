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

Vec3f sPreviousMarioPos = {0, 0, 0};

u8 sTokenCoins[3] = {5, 20, 50};


void bhv_deathwarp_loop(void) {
    Vec3f pos;
    s16 angle;
    struct MarioState *m = gMarioState;
    if (gMarioCurrentRoom != gMarioPreviousRoom) {
        angle = atan2s(m->pos[2] - sPreviousMarioPos[2], m->pos[0] - sPreviousMarioPos[0]);
        o->oFaceAngleYaw = angle;
        pos[0] = m->pos[0] + (sins(angle) * 150.0f);
        pos[2] = m->pos[2] + (coss(angle) * 150.0f);
        pos[1] = m->pos[1] + 50.0f;
        vec3f_copy(&o->oPosX, pos);
    }
    o->oRoom = (gMarioPreviousRoom = gMarioCurrentRoom);
    vec3f_copy(sPreviousMarioPos, m->pos);
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
    u8 page, challenge, list;
    obj_set_hitbox(o, &sTokenHitbox);
    o->oDamageOrCoinValue = sTokenCoins[o->oBehParams2ndByte];
    challenge = (o->oBehParams >> 8) & 0xFF;
    while (challenge >= 32) {
        challenge -= 32;
        page++;
    }
    list = save_file_get_challenges(page);
    if (list & 1 << challenge) {
        o->activeFlags = 0;
    }
}


void bhv_token_loop(void) {
    u8 challenge;
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        spawn_object(o, MODEL_SPARKLES, bhvGoldenCoinSparkles);
        o->activeFlags = 0;
        challenge = (o->oBehParams >> 8) & 0xFF;
        save_file_set_challenges(challenge);
    }
}


void bhv_star_piece_init(void) {
    s8 pieceId;
    u32 starPieces;

    pieceId = (o->oBehParams >> 24) & 0xFF;
    starPieces = save_file_get_star_piece();
    if (starPieces & (1 << pieceId)) {
        o->activeFlags = 0;
    }

    obj_set_hitbox(o, &sStarPieceHitbox);
}

void bhv_star_piece_loop(void) {
    //o->oFaceAngleRoll += 0x400;

    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        o->activeFlags = 0;
        o->oInteractStatus = 0;
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
                    }
                } else {
                    if (o->oInteractStatus == INT_STATUS_INTERACTED)
                        o->oAction = 1;
                }
                break;
            case 1:
                o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x1000);
                if ((s16) o->oMoveAngleYaw == (s16) o->oAngleToMario)
                    o->oAction = 2;

                cur_obj_play_sound_2(SOUND_ACTION_READ_SIGN);
                break;
            case 2:
                if (CL_NPC_Dialog(o->oBehParams2ndByte)) {
                    if (o->oF4 == 1) {
                        o->oBehParams2ndByte = 5;
                    }
                    o->oF4 = 2;
                    o->oAction = 0;
                }
                break;
        }
    }
    o->oInteractStatus = 0;
}


void bhv_friend_toad_loop(void) {
    switch (gCurrLevelNum) {
        case LEVEL_BOB:
            toad_friend_l1_loop();
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