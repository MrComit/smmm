static void const *sInstsCollision[] = {
    violin_col_collision,
    drums_col_collision,
    piano_col_collision,
    guitar_col_collision,
};

void bhv_music_insts_init(void) {
    o->collisionData = segmented_to_virtual(sInstsCollision[o->oBehParams2ndByte]);
}

void bhv_music_insts_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 1000.0f) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 0x8);
            break;
    }
}