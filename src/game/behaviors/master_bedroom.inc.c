extern Vec3s gRoomColors[];

void bhv_shadow_boss_init(void) {
    o->os16F4 = 0xFF;
    o->os16F6 = 0xFF;
    o->os16F8 = 0xFF;
    o->os16FA = o->oRoom - 7;
}



void bhv_shadow_boss_loop(void) {
    /*gRoomColors[o->os16FA][0] = approach_s16_symmetric(gRoomColors[o->os16FA][0], 10, 0x8);
    gRoomColors[o->os16FA][1] = approach_s16_symmetric(gRoomColors[o->os16FA][1], 10, 0x8);
    gRoomColors[o->os16FA][2] = approach_s16_symmetric(gRoomColors[o->os16FA][2], 10, 0x8);
    o->oFC += 0x100;
    o->os16F4 = absi(sins(o->oFC) * 255);
    o->os16F8 = (o->os16F6 = o->os16F4);*/
    
}