
struct ObjectHitbox sBouncyBedHitbox = {
    /* interactType: */ INTERACT_BOUNCE_TOP,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 1,
    /* numLootCoins: */ 0,
    /* radius: */ 240,
    /* height: */ 152,
    /* hurtboxRadius: */ 240,
    /* hurtboxHeight: */ 92,
};


s8 sServantsLights = 0;


void bhv_bouncy_bed_init(void) {
   obj_set_hitbox(o, &sBouncyBedHitbox);
   o->oFloatF4 = 1.0f;
   o->os16F4 = 255;
   o->os16F6 = 255;
   o->os16F8 = 255;
}


void bhv_bouncy_bed_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oInteractStatus)
                o->oAction = 1;
            break;
        case 1:
            o->oFloatF4 -= 0.15f;
            o->header.gfx.scale[1] = o->oFloatF4;
            o->header.gfx.scale[0] = approach_f32(o->header.gfx.scale[0], 1.1f, 0.04f, 0.04f);
            o->header.gfx.scale[2] = o->header.gfx.scale[0];
            if (o->oFloatF4 <= 0.6f) {
                o->oFloatF4 = 0.6f;
                o->oAction = 2;
            }
            break;
        case 2:
            o->oFloatF4 += 0.18f;
            o->header.gfx.scale[1] = o->oFloatF4;
            o->header.gfx.scale[0] = approach_f32(o->header.gfx.scale[0], 0.8f, 0.07f, 0.07f);
            o->header.gfx.scale[2] = o->header.gfx.scale[0];
            if (o->oFloatF4 >= 1.4f) {
                o->oFloatF4 = 1.4f;
                o->oAction = 3;
            }
            break;
        case 3:
            o->oFloatF4 -= 0.08f;
            o->header.gfx.scale[0] = approach_f32(o->header.gfx.scale[0], 1.0f, 0.04f, 0.04f);
            o->header.gfx.scale[2] = o->header.gfx.scale[0];
            if (o->oFloatF4 <= 1.0f) {
                o->header.gfx.scale[0] = (o->header.gfx.scale[2] = 1.0f);
                o->oFloatF4 = 1.0f;
                o->oAction = 0;
            }
            o->header.gfx.scale[1] = o->oFloatF4;
            break;
    }
    o->oInteractStatus = 0;
}






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