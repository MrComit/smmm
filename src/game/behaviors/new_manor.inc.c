extern s8 sBooColorsDark[][3];

void bhv_bubble_cage_init(void) {
    obj_set_hitbox(o, &sJustCageHitbox);
}

void bhv_boo_bubble_init(void) {
    struct Object *obj;
    if (!(save_file_get_boos() & (1 << o->oBehParams2ndByte))) {
        o->activeFlags = 0;
        return;
    }

    obj = spawn_object(o, MODEL_HAUNTED_CAGE, bhvBooBubbleCage);
    obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
    o->oPosY += 150.0f;

    o->os16F4 = sBooColorsDark[o->oBehParams2ndByte][0] * 1.5f;
    o->os16F6 = sBooColorsDark[o->oBehParams2ndByte][1] * 1.5f;
    o->os16F8 = sBooColorsDark[o->oBehParams2ndByte][2] * 1.5f;

}

void bhv_boo_bubble_loop(void) {
    o->os16100 += 0x400;
    o->oOpacity = 180 + (coss(o->os16100 + 0x2000) * 60);
    o->oGraphYOffset = 15.0f - (coss(o->os16100) * 15.0f);
}





void spawn_orange_number_infinite_digit_scale(u32 behParam, s16 relX, s16 relY, s16 relZ, f32 dist, f32 scale, s32 palette) {
    struct Object *orangeNumber;
    s32 behParamMod = behParam;
    s32 digits = 0;
    f32 digitsCenter;
    s32 offset;

    while (behParamMod > 10) {
        behParamMod /= 10;
        digits++;
    }
    
    digitsCenter = digits / 2.0f;

    while (digits+1) {
        offset = (digits - digitsCenter) * 220.0f;
        orangeNumber = spawn_object_relative(behParam % 10, relX + offset, relY, relZ, o, MODEL_NUMBER, bhvStationaryOrangeNumber);
        orangeNumber->oFC = palette;
        orangeNumber->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
        obj_scale(orangeNumber, scale);


        behParam /= 10;
        digits--;
    }
}


void bhv_end_coin_count_init(void) {
    struct Object *obj = spawn_object(o, MODEL_RANK_LETTER, bhvStationaryOrangeNumber);
    obj_scale(obj, 8.0f);
    obj->oPosY += 400.0f;
    obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
    //obj->oBehParams2ndByte = save_file_get_rank();
    //obj->oFC = palette?

    spawn_orange_number_infinite_digit_scale(gSaveBuffer.files[gCurrSaveFileNum - 1][0].coinCount, 0, 0, 0, 0, 4.2f, 6);
}




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