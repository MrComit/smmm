

void bhv_lemon_loop(void) {
    f32 approach_pos;
    struct Object *obj = cur_obj_nearest_object_with_behavior(bhvL2Lava);
    if (obj == NULL) {
        o->activeFlags = 0;
        return;
    }

    if (gMarioObject->platform == o) {
        approach_pos = o->oHomeY - o->oFloatF8;
    } else {
        approach_pos = o->oHomeY;
    }
    o->oPosY = approach_f32(o->oPosY, approach_pos, o->oFloatF4 * 4, o->oFloatF4);
    o->oPosY += obj->oVelY;
    o->oHomeY += obj->oVelY;
}


void bhv_l2_lava_loop(void) {
    f32 oldPos = o->oPosY;
    o->oF4 += 0x140;
    o->oPosY = o->oHomeY + (sins(o->oF4) * 75.0f);
    o->oVelY = o->oPosY - oldPos;
}




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