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