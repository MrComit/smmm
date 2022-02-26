void bhv_trophy_plat_spin_loop(void) {
    if (gMarioObject->platform == o) {
        o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY - 20.0f, 2.0f);
    } else {
        o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 2.0f);
    }
}

void bhv_trophy_rect_loop(void) {
    o->os16F4 += (o->oBehParams >> 24) << 4;
    o->oPosX = o->oHomeX + sins(o->oFaceAngleYaw + 0x4000) * (sins(o->os16F4) * (o->oBehParams2ndByte * 100.0f));
    o->oPosZ = o->oHomeZ + coss(o->oFaceAngleYaw + 0x4000) *(sins(o->os16F4) * (o->oBehParams2ndByte * 100.0f));
}



void bhv_trophy_plat_rise_loop(void) {
    o->os16F4 += (o->oBehParams >> 24) << 4;
    o->oPosY = o->oHomeY + (sins(o->os16F4) * (o->oBehParams2ndByte * 100.0f));
}