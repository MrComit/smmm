void bhv_dice_enemy_init(void) {
    o->oAnimState = o->oBehParams2ndByte;
}


void bhv_dice_enemy_loop(void) {
    o->oAnimState = o->oBehParams2ndByte;
    if (o->oAnimState) {
        o->os16F4 = 0xFF;
        o->os16F6 = o->os16F8 = 0;
    } else {
        o->os16F8 = 0xFF;
        o->os16F4 = o->os16F6 = 0;
    }
}