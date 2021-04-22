
s8 sServantsLights = 0;

void bhv_servants_flame_init(void) {
    o->os16F4 = 0;
    o->os16F6 = 0;
    o->os16F8 = 0; //alpha = 200?
}


void bhv_servants_flame_loop(void) {
    if (sServantsLights) {
        o->os16F4 = approach_s16_symmetric(o->os16F4, 255, 0x20);
        o->os16F6 = approach_s16_symmetric(o->os16F6, 50, 0x6);
    } else {
        o->os16F4 = approach_s16_symmetric(o->os16F4, 0, 0x20);
        o->os16F6 = approach_s16_symmetric(o->os16F6, 0, 0x6);
    }

    if (gMarioState->input & INPUT_A_PRESSED) {
        sServantsLights = 1;
    }
}