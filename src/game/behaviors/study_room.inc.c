void bhv_appearing_book_init(void) {
    o->header.gfx.scale[0] = 3.0f;
    o->header.gfx.scale[1] = 6.0f;
    o->header.gfx.scale[2] = 6.0f;    
}



void bhv_appearing_book_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioState->pos[1] <= gMarioState->floorHeight && absf(gMarioState->pos[2] - o->oPosZ) < 800.0f) {
                o->oAction = 1;
                o->oFloatF4 = o->oHomeX - 641.0f;
            }
            break;
        case 1:
            queue_rumble_data(5, 80);
            cur_obj_shake_screen(1);
            o->oPosX = approach_f32(o->oPosX, o->oFloatF4, 13.0f, 13.0f);
            if (o->oPosX == o->oFloatF4) {
                o->oAction = 2;
            }
            break;
    }
}