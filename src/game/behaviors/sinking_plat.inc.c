void bhv_sinking_plat_init(void) {
    o->oFloatF4 = (f32)(o->oBehParams >> 24);
    o->oFloatF8 = (f32)((o->oBehParams >> 16) & 0xFF) * 10.0f;

}

void bhv_sinking_plat_loop(void) {
    f32 approach_pos;
    if (gMarioObject->platform == o) {
        approach_pos = o->oHomeY - o->oFloatF8;
    } else {
        approach_pos = o->oHomeY;
    }
    o->oPosY = approach_f32(o->oPosY, approach_pos, o->oFloatF4, o->oFloatF4);
}