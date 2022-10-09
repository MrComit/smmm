void bhv_cellar_blockade_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oFlags & OBJ_FLAG_KICKED_OR_PUNCHED) {
                o->oAction = 1;
                o->oObjF4 = spawn_object(o, MODEL_ENV_FLAME, bhvFlame);
                // obj_scale(o->oObjF4, 0.0f);
                o->oFloatF8 = 7.0f;
                o->oObjF4->oIntangibleTimer = -1;
                o->oObjF4->os16F4 = 0xFF;
            }
            break;
        case 1:
            o->oObjF4->oIntangibleTimer = -1;
            o->oObjF4->os16F6 = approach_s16_symmetric(o->oObjF4->os16F6, 0xFF, 0xA);
            if (o->oObjF4->os16F6 >= 0x7F) {
                o->oObjF4->os16F8 = approach_s16_symmetric(o->oObjF4->os16F8, 0xFF, 0x10);
            }
            o->oFloatF8 = approach_f32_symmetric(o->oFloatF8, 20.0f, 0.5f);
            obj_scale(o->oObjF4, o->oFloatF8);
            if (o->oFloatF8 == 20.0f) {
                o->oAction = 2;
            }
            break;
        case 2:
            CL_explode_object(o, 1);
            o->oObjF4->activeFlags = 0;
            break;
    }
}