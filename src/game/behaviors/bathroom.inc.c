void bhv_falling_floor_init(void) {
    o->oFloatF4 = 10.0f;
}



void bhv_falling_floor_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oFloatF4 = approach_f32(o->oFloatF4, 30.0f, 1.1f, 1.1f);
            o->oPosY -= o->oFloatF4;
            if (o->oPosY < o->oHomeY - 800.0f) {
                CL_explode_object(o, 1);
                o->oAction = 2;
            }
            break;
    }
}