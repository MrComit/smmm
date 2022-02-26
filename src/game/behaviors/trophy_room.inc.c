void bhv_trophy_plat_rise_loop(void) {
    o->os16F4 += (o->oBehParams >> 24) << 4;
    o->oPosY = o->oHomeY + (sins(o->os16F4) * (o->oBehParams2ndByte * 100.0f));
}