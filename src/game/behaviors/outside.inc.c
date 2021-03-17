s32 sSunflowers = 0;

void bhv_sunflower_init(void) {
    sSunflowers = 0;
    o->oOpacity = 80;
    //o->oFloatF4 = 0.6f;
    o->header.gfx.scale[1] = 0.6f;
    //cur_obj_scale(o->oFloatF4);
}

void bhv_sunflower_loop(void) {
    switch (o->oAction) {
        case 0:
            o->header.gfx.animInfo.animFrame = 0;
            if (o->oDistanceToMario < 100.0f) {
                o->oAction = 1;
                play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gGlobalSoundSource);
                sSunflowers++;
            }
            break;
        case 1:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 12);
            o->header.gfx.scale[1] = approach_f32(o->header.gfx.scale[1], 0.9f, 0.02f, 0.02f);
            //cur_obj_scale(o->oFloatF4);
            if (o->header.gfx.scale[1] == 0.9f && o->oOpacity == 255) {
                o->oAction = 2;
            }
            break;
        case 2:
            break;
    }
}