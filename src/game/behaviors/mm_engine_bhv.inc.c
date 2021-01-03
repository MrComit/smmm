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
    switch (o->oF4) {
        case 0:
            bhv_toad_message_loop();
            o->oOpacity = 255;
            if (o->oToadMessageRecentlyTalked) {
                save_file_set_newflags(SAVE_TOAD_FLAG_INTRODUCTION, 1);
            }
            break;
        case 1:
            break;
    }
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
        o->oToadMessageDialogId = (o->oBehParams >> 24) & 0xFF;
        o->oToadMessageRecentlyTalked = FALSE;
        //o->oToadMessageState = TOAD_MESSAGE_FADED;
        //o->oOpacity = 81;
}