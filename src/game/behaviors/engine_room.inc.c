#define THWOMP_SPEED_FACTOR 0.05f

void bhv_thwomp_block_init(void) {
    o->os16100 = 0xC000;
    o->os16FA = CL_RandomMinMaxU16(0, 2);
    if (o->oBehParams2ndByte) {
        o->oFloat104 = o->oBehParams2ndByte * 100.0f;
        if (o->oBehParams >> 24) {
            o->oFloat104 += 50.0f;
        }
    } else {
        o->oFloat104 = 1000.0f;
    }
    o->oFloat108 = (o->oFloat104 * THWOMP_SPEED_FACTOR) / 32.0f;
}

void bhv_thwomp_block_loop(void) {
    if (o->oTimer > 30) {
        switch (o->oAction) {
            case 0:
                o->oPosY += o->oFloat108;
                if (o->oFloat108 >= o->oFloat104 * THWOMP_SPEED_FACTOR) {
                    o->oFloat108 = o->oFloat104 * THWOMP_SPEED_FACTOR;
                } else if (o->oTimer & 1) {
                    o->oFloat108 *= 2;
                }
                if (o->oPosY >= o->oHomeY + o->oFloat104) {
                    o->oPosY = o->oHomeY + o->oFloat104;
                    o->oFloat108 = (o->oFloat104 * THWOMP_SPEED_FACTOR) / 32.0f;
                    o->oAction = 1;
                }
                break;
            case 1:
                o->oPosY -= o->oFloat108;
                if (o->oFloat108 >= o->oFloat104 * THWOMP_SPEED_FACTOR) {
                    o->oFloat108 = o->oFloat104 * THWOMP_SPEED_FACTOR;
                } else if (o->oTimer & 1) {
                    o->oFloat108 *= 2;
                }
                if (o->oPosY <= o->oHomeY) {
                    o->oPosY = o->oHomeY;
                    o->oFloat108 = (o->oFloat104 * THWOMP_SPEED_FACTOR) / 32.0f;
                    o->oAction = 0;
                }
                break;
        }
    } else if (!gLowGrav) {
        o->oTimer = 0;
        if (o->oOpacity) {
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 7);
        }
        if (o->os16100 != 0xC000) {
            o->os16100 = 0xC000;
        }
    }
    if (gLowGrav) {
        o->os16100 += 0x400;
        o->oOpacity = 70 + (sins(o->os16100) * 70);
        switch (o->os16FA) {
            case 0:
                o->os16F4 = 0xA0;
                o->os16F6 = 0;
                o->os16F8 = 0;
                if ((u16)o->os16100 == 0xC000) {
                    o->os16FA = 1;
                }
                break;
            case 1:
                o->os16F4 = 0;
                o->os16F6 = 0;
                o->os16F8 = 0xA0;
                if ((u16)o->os16100 == 0xC000) {
                    o->os16FA = 2;
                }
                break;
            case 2:
                o->os16F4 = 0xA0;
                o->os16F6 = 0xA0;
                o->os16F8 = 0;
                if ((u16)o->os16100 == 0xC000) {
                    o->os16FA = 0;
                }
                break;
        }
    }
}


void bhv_gravity_button_init(void) {
    if (gLowGrav) {
        o->os16F6 = 0xFF;
        o->os16100 = 120;
    } else {
        o->os16F4 = 0xFF;
    }
}

void bhv_gravity_button_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oFlags & OBJ_FLAG_KICKED_OR_PUNCHED) {
                o->oAction = 1;
                gLowGrav ^= 1;
            }
            break;
        case 1:
            o->header.gfx.scale[2] = approach_f32_symmetric(o->header.gfx.scale[2], 0.2f, 0.1f);
            if (o->header.gfx.scale[2] == 0.2f) {
                o->oAction = 2;
            }
            break;
        case 2:
            o->header.gfx.scale[2] = approach_f32_symmetric(o->header.gfx.scale[2], 1.0f, 0.1f);
            if (o->header.gfx.scale[2] == 1.0f) {
                o->oAction = 0;
            }
            break;
    }

    o->os16FA += 0x600;
    if (gLowGrav) {
        o->os16F6 = approach_s16_symmetric(o->os16F6, 215 + (sins(o->os16FA) * 40), 10);
        o->os16F4 = approach_s16_symmetric(o->os16F4, 0, 10);
    } else {
        o->os16F4 = approach_s16_symmetric(o->os16F4, 215 + (sins(o->os16FA) * 40), 10);
        o->os16F6 = approach_s16_symmetric(o->os16F6, 0, 10);
    }
}