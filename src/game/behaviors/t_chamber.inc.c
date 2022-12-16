void bhv_swinging_plat_loop(void) {
    o->os16F4 += 0x200;
    o->oPosX = o->oHomeX + (sins(o->os16F4) * 500.0f);
}