void bhv_end_star_init(void) {
    u32 flags = save_file_get_star_piece();
    u32 redsStars = save_file_get_reds_star();
    switch (o->oBehParams >> 24) {
        case 0:
            if ((flags & 0b11111) != 0b11111) {
                o->activeFlags = 0;
            }
            break;
        case 1:
            flags = flags >> 5;
            if ((flags & 0b11111) != 0b11111) {
                o->activeFlags = 0;
            }
            break;
        case 2:
            flags = flags >> 10;
            if ((flags & 0b11111) != 0b11111) {
                o->activeFlags = 0;
            }
            break;
        case 3:
            flags = flags >> 15;
            if ((flags & 0b11111) != 0b11111) {
                o->activeFlags = 0;
            }
            break;
        case 4:
            flags = flags >> 20;
            if ((flags & 0b11111) != 0b11111) {
                o->activeFlags = 0;
            }
            break;
        case 5:
            if (!(redsStars & 1)) {
                o->activeFlags = 0;
            }
            break;
        case 6:
            if (!(redsStars & 2)) {
                o->activeFlags = 0;
            }
            break;
        case 7:
            if (!(redsStars & 4)) {
                o->activeFlags = 0;
            }
            break;
    }
}



extern s8 sServantsLights;

void bhv_l10_pressure_plate_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oPosY = approach_f32(o->oPosY, o->oHomeY, 2.5f, 2.5f);
            if (gMarioObject->platform == o) {
                o->oAction = 1;
                cur_obj_play_sound_1(SOUND_GENERAL_PENDULUM_SWING);
                sServantsLights ^= 1;
            }
            o->os16F4 = approach_s16_symmetric(o->os16F4, 100, 0x10);
            o->os16F6 = (o->os16F8 = o->os16F4);
            break;
        case 1:
            o->oPosY = approach_f32(o->oPosY, o->oHomeY - 10.0f, 2.5f, 2.5f);
            o->os16F4 = approach_s16_symmetric(o->os16F4, 255, 0x10);
            o->os16F6 = (o->os16F8 = o->os16F4);
            if (gMarioObject->platform != o) {
                o->oAction = 0;
            }
            break;
    }

    if (sServantsLights) {
            gRoomColors[0][0] = approach_s16_symmetric(gRoomColors[0][0], 180, 20);
            gRoomColors[0][2] = (gRoomColors[0][1] = gRoomColors[0][0]);
    } else {
            gRoomColors[0][0] = approach_s16_symmetric(gRoomColors[0][0], 30, 10);
            gRoomColors[0][2] = (gRoomColors[0][1] = gRoomColors[0][0]);

    }

}