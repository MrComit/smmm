// TV PEEPA START
#include "levels/sl/new_tv_static/geo_header.h"
static struct ObjectHitbox sNewTVPeepaHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 90,
    /* height:            */ 60,
    /* hurtboxRadius:     */ 70,
    /* hurtboxHeight:     */ 50,
};

u8 sNewPeepaNumbersCopy[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
u8 sNewPeepaNumbers[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};




// void bhv_remote_init(void) {
//    obj_set_hitbox(o, &sRemoteHitbox);
//    o->oFloatF4 = 1.0f;
// }



void bhv_new_remote_loop(void) {
    struct Object *obj = cur_obj_nearest_object_with_behavior(bhvNewTVStatic);
    struct Object *obj2;
    if (obj == NULL)
        return o->activeFlags = 0;
    o->oFaceAngleYaw += 0x380;
    switch (o->oAction) {
        case 0:
            if (obj->oAnimState == 0) {
                o->oAction = 1;
                o->oAnimState = 1;
            }
            if (o->oInteractStatus) {
                obj->oAnimState = 0;
                obj2 = spawn_object(o, MODEL_SPARKLES, bhvGoldenCoinSparkles);
                obj2->oPosY -= 50.0f;
                // o->activeFlags = 0;
                cur_obj_disable();
                o->oAction = 2;

                play_sound(SOUND_GENERAL_UNKNOWN3, gGlobalSoundSource);
                play_sound(SOUND_GENERAL2_PURPLE_SWITCH, gGlobalSoundSource);
            }
            o->oFloatF4 = approach_f32(o->oFloatF4, 1.0f, 0.05f, 0.05f);
            obj_scale(o, o->oFloatF4);
            break;
        case 1:
            o->oFloatF4 = approach_f32(o->oFloatF4, 0.6f, 0.05f, 0.05f);
            obj_scale(o, o->oFloatF4);
            if (obj->oAnimState == 1) {
                o->oAction = 0;
                o->oAnimState = 0;
            }
            break;
        case 2:
            if (obj->oAnimState == 1) {
                if (o->oTimer > 30) {
                    if (obj->oBehParams2ndByte) {
                        obj->oAnimState = 0;
                    } else {
                        o->oAction = 3;
                    }
                }
            } else {
                o->oTimer = 0;
            }
            break;
        case 3:
            if (o->oDistanceToMario > 500.0f) {
                cur_obj_enable();
                o->oAction = 0;
            }
            break;
    }
    o->oInteractStatus = 0;
}




void tv_spawn_new_peepa(s32 count) {
    struct Object *obj;
    s32 i;
    s32 more = count > 6;
    for (i = 0; i < count; i++) {
        obj = spawn_object_relative(count << 8 | i, 0, -150, -200, o, MODEL_PEEPA, bhvNewTVPeepa);
        if (more) {
            obj->oFloat110 = 60.0f * (count - 6);
        }
    }
}


void bhv_new_tv_static_loop(void) {
    struct Object *obj;
    u8 *texture = segmented_to_virtual(&new_tv_static_i8_static_i4);
    s32 count;
    s32 i;
    if (o->oDistanceToMario < 3000.0f || o->oBehParams2ndByte) {
        print_text_fmt_int(210, 192, "SCORE %d", o->oBehParams2ndByte, 3);
        print_text_fmt_int(210, 172, "HIGH  %d", save_file_get_peepa_score(), 4);
    } 

    if (o->oAnimState == 0) {
        for (i = 0; i < 2048; i++) {
            texture[i] = random_u16() & 0xFF;
        }
        switch (o->oAction) {
            case 0:
                // if (o->oDistanceToMario < 1500.0f) {
                    count = o->oBehParams2ndByte + 3;
                    if (count > 15) {
                        count = 15;
                    }
                    CL_scramble_array(&sNewPeepaNumbers, count);
                    tv_spawn_new_peepa(count);
                    o->oAction = 1;
                // }
                break;
            case 1:
                if (count_room_objects_with_behavior(bhvNewTVPeepa, o->oRoom) == 0) {
                    o->oAnimState = 1;
                    o->oF4 = 0;
                    o->oAction = 0;
                    o->oBehParams2ndByte++;
                    // if (o->oBehParams2ndByte >= 4) {
                    //     o->activeFlags = 0;
                    // }
                }

                if (o->oDistanceToMario > 4000.0f) {
                    while ((obj = cur_obj_nearest_object_with_behavior(bhvNewTVPeepa)) != NULL) {
                        obj->activeFlags = 0;
                    }
                    while ((obj = cur_obj_nearest_object_with_behavior(bhvPeepaNumber)) != NULL) {
                        obj->activeFlags = 0;
                    }

                    if (o->oBehParams2ndByte > save_file_get_peepa_score()) {
                        save_file_set_peepa_score(o->oBehParams2ndByte);
                    }

                    o->oBehParams2ndByte = 0;
                    o->oF4 = 0;
                    o->oAction = 0;
                    o->oAnimState = 1;

                    gMarioState->healCounter = 31;

                    obj = cur_obj_nearest_object_with_behavior(bhvNewRemote);
                    if (obj != NULL) {
                        obj->oAction = 3;
                    }


                    bcopy(sNewPeepaNumbersCopy, sNewPeepaNumbers, 15);
                }
                break;
        }
    }
}

void bhv_new_tv_peepa_init(void) {
    s16 beh1 = o->oBehParams2ndByte >> 8;
    s16 beh2 = o->oBehParams2ndByte & 0xFF;
    o->oForwardVel = 15.0f;
    o->oF8 = beh2 * 10;
    o->os16F4 = beh2 * 0x2000;
    o->os16F6 = beh2 * (0x10000 / beh1);
    o->oHomeX = 8102.0f;
    o->oHomeZ = 3618.0f;
    
    o->oFloat10C = o->oFloat110 + 324.0f;

    o->oBehParams2ndByte = sNewPeepaNumbers[beh2];
    if (o->oBehParams2ndByte > 8) {
        o->prevObj = spawn_object(o, MODEL_NUMBER, bhvPeepaNumber);
        o->prevObj->oAnimState = (o->oBehParams2ndByte + 1) / 10;

        o->prevObj->oF4 = 2;

        o->oObjFC = spawn_object(o, MODEL_NUMBER, bhvPeepaNumber);
        o->oObjFC->oAnimState = (o->oBehParams2ndByte + 1) % 10;

        o->oObjFC->oF4 = 1;
    } else {
        o->prevObj = spawn_object(o, MODEL_NUMBER, bhvPeepaNumber);
        o->prevObj->oAnimState = o->oBehParams2ndByte + 1;
    }
}

void bhv_new_tv_peepa_loop(void) {
    struct Object *obj;
    s32 i, k;
    o->os16F4 += 0x800;
    o->oGraphYOffset = 25.0f * sins(o->os16F4);
    switch (o->oAction) {
        case 0:
            if (o->oTimer > o->oF8)
                CL_Move();
            if (o->oTimer > 70) {
                o->oAction = 1;
                o->oFloat100 = o->oHomeX + (o->oFloat10C * sins(o->os16F6));
                o->oFloat104 = o->oHomeZ + (o->oFloat10C * coss(o->os16F6));
            }
            break;
        case 1:
            o->oPosX = approach_f32(o->oPosX, o->oFloat100, 20.0f, 20.0f);
            o->oPosZ = approach_f32(o->oPosZ, o->oFloat104, 20.0f, 20.0f);
            if (o->oTimer > 120) {
                o->oAction = 2;
                //o->prevObj->activeFlags = 0;
            }
            break;
        case 2:
            o->o108 = approach_s16_symmetric(o->o108, 0x600, 0x30);
            o->os16F6 += o->o108;
            o->oPosX = o->oHomeX + (o->oFloat10C * sins(o->os16F6));
            o->oPosZ = o->oHomeZ + (o->oFloat10C * coss(o->os16F6));
                if (o->oBehParams2ndByte == 0 && gGlobalTimer % 4 == 0) {
                    cur_obj_play_sound_2(SOUND_GENERAL_SWISH_AIR);
                }
            if (o->oTimer > 120) {
                o->oAction = 3;
                o->prevObj->activeFlags = 0;
                if (o->oObjFC != NULL) {
                    o->oObjFC->activeFlags = 0;
                }
                if (o->oBehParams2ndByte == 0) {
                    // cur_obj_play_sound_2(SOUND_OBJ_BOO_LAUGH_SHORT);
                    play_sound(SOUND_OBJ_BOO_LAUGH_LONG, gGlobalSoundSource);
                }
                obj_set_hitbox(o, &sNewTVPeepaHitbox);
            }
            break;
        case 3:
            obj = cur_obj_nearest_object_with_behavior(bhvNewTVStatic);
            if (obj == NULL) {
                o->activeFlags = 0;
                break;
            }
            o->oMoveAngleYaw += 0x600;
            if (o->oInteractStatus & INT_STATUS_INTERACTED && o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
                for (i = 0; i < o->oBehParams2ndByte; i++) {
                    if (!(obj->oF4 & 1 << i)) {
                        k = 1;
                        break;
                    } else {
                        k = 0;
                    }
                }

                if (k) {
                    CL_get_hit(gMarioState, o, 2);
                    play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                } else {
                    obj_spawn_loot_yellow_coins(o, o->oNumLootCoins, 20.0f);
                    play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gGlobalSoundSource);
                }
                spawn_mist_particles();
                o->activeFlags = 0;
                create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
                obj->oF4 |= 1 << o->oBehParams2ndByte;
            }
            o->oInteractStatus = 0;
            break;
    }
}


// void bhv_peepa_number_loop(void) {
//     if (o->parentObj == o) {
//         o->activeFlags = 0;
//         return;
//     }

//     o->oPosX = o->parentObj->oPosX;
//     o->oPosY = o->parentObj->oPosY + o->parentObj->oGraphYOffset + 100.0f;
//     o->oPosZ = o->parentObj->oPosZ;
// }


// TV PEEPA END




void bhv_jukebox_loop(void) {
    if (o->oDistanceToMario < 3000.0f) {
        if (o->oTimer > 25) {
            struct Object *obj = spawn_object(o, MODEL_SPARKLES, bhvGoldenCoinSparkles);
            obj->oPosY += 30.0f;
            switch (o->os16F4) {
                case 0:
                    obj->oPosY += 90.0f;
                    // obj->oPosY -= 120.0f;
                    o->os16F4 = 1;
                    break;
                case 1:
                    obj->oPosX += 120.0f;
                    obj->oPosZ -= 120.0f;
                    o->os16F4 = 2;
                    break;
                case 2:
                    obj->oPosX -= 120.0f;
                    obj->oPosZ += 120.0f;
                    o->os16F4 = 3;
                    break;
                case 3:
                    obj->oPosX -= 120.0f;
                    obj->oPosZ -= 120.0f;
                    o->os16F4 = 4;
                    break;
                case 4:
                    obj->oPosX += 120.0f;
                    obj->oPosZ += 120.0f;
                    o->os16F4 = 0;
                    break;
            }
            o->oTimer = 0;
        }
    }
}


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