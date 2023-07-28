// GALLERY START

// #define NEW_MINIGAME_SECONDS 120

// struct Object *sGalleryShyguys[4] = {
//     NULL, NULL, NULL, NULL,
// };

// struct Object *sGalleryGoombas[6] = {
//     NULL, NULL, NULL, NULL, NULL, NULL,
// };

// struct Object *sGallerySnufits[3] = {
//     NULL, NULL, NULL,
// };

const BehaviorScript *sNewGalleryEnemies[4] = {
    bhvNewGalleryShyguy, bhvNewGalleryGoomba, bhvNewGallerySnufit, bhvSnufitBalls,
};

s32 gGalleryScore = 0;

Vec3f sNewShyguyPositions[4] = {
    {7044.0f - 13049.0f, 291.0f, -10352.0f + 6421.0f},
    {6811.0f - 13049.0f, 291.0f, -10159.0f + 6421.0f},
    {8875.0f - 13049.0f, 591.0f, -10125.0f + 6421.0f},
    {8644.0f - 13049.0f, 591.0f, -10321.0f + 6421.0f},
};


Vec3f sNewSnufitPositions[3] = {
    {7805.0f - 13049.0f, 1890.0f - 859.0f, -10110.0f + 6421.0f},
    {8372.0f - 13049.0f, 2000.0f - 859.0f, -10110.0f + 6421.0f},
    {6909.0f - 13049.0f, 2190.0f - 859.0f, -10110.0f + 6421.0f},
};


void bhv_new_cannon_lid_init(void) {
    o->oPosX -= 300.0f;
    o->oPosY -= 180.0f;
    o->header.gfx.scale[0] = 0.5f;
    o->oRoom = 7;
}

void bhv_new_cannon_lid_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oPosX = approach_f32_symmetric(o->oPosX, o->oHomeX, 30.0f);
            o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 1.5f, 0.1f);
            if (o->oPosX == o->oHomeX && o->header.gfx.scale[0] == 1.5f) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 20.0f);
            if (o->oPosY == o->oHomeY) {
                o->oAction = 2;
            }
            break;
        case 2:
            if (lateral_dist_between_objects(o, gMarioObject) > 600.0f) {
                o->oAction = 3;
            }
            break;
        case 3:
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY - 180.0f, 30.0f);
            o->oPosX = approach_f32_symmetric(o->oPosX, o->oHomeX - 300.0f, 30.0f);
            o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 0.5f, 0.1f);

            if (o->oPosX == o->oHomeX - 300.0f && o->header.gfx.scale[0] == 0.5f) {
                o->activeFlags = 0;
            }
            break;
    }
}


void bhv_new_gallery_snufit_loop(void) {
    f32 dist;
    s16 pitch, yaw;
    obj_set_hitbox(o, &sGallerySnufitHitbox);
    o->oDeathSound = SOUND_OBJ_SNUFIT_SKEETER_DEATH;


    vec3f_get_dist_and_angle(&o->oPosX, gMarioState->pos, &dist, &pitch, &yaw);
    o->oMoveAnglePitch = -pitch;

    cur_obj_rotate_yaw_toward(o->oAngleToMario, 2000);

    o->oFaceAnglePitch = o->oMoveAnglePitch;

    switch (o->oAction) {
        case 0:
            if (o->oTimer > 90) {
                o->oAction = 1;
            }
            o->oSnufitCircularPeriod += 0x20;
            o->oPosX = o->oHomeX + 300.0f * sins(o->oSnufitCircularPeriod);
            break;
        case 1:
            if (o->oTimer > 5) {
                o->oSnufitBullets += 3;
                cur_obj_play_sound_2(SOUND_OBJ_SNUFIT_SHOOT);
                spawn_object_relative(0, 0, -20, 40, o, MODEL_GHOSTSAND_BALL, bhvSnufitBalls);
                o->oSnufitRecoil = -30;
                o->oAction = 2;
            }
            break;
        case 2:
            if (o->oTimer > 5) {
                o->oAction = 0;
            }
            break;
    }

    o->oFloat110 = (o->oHomeY - 400.0f) + 8.0f * coss(4000 * gGlobalTimer);
    o->oPosY = approach_f32_symmetric(o->oPosY, o->oFloat110, 4.0f);

    o->oSnufitYOffset = -0x20;
    o->oSnufitZOffset = o->oSnufitRecoil + 180;
    o->oSnufitBodyScale
        = (s16)(o->oSnufitBodyBaseScale + 666
        + o->oSnufitBodyBaseScale * coss(o->oSnufitBodyScalePeriod));

    if (o->oSnufitBodyScale > 1000) {
        o->oSnufitScale = (o->oSnufitBodyScale - 1000) / 1000.0f + 1.0f;
        o->oSnufitBodyScale = 1000;
    } else {
        o->oSnufitScale = 1.0f;
    }

    cur_obj_scale(o->oSnufitScale);
    if (o->oInteractStatus & INT_STATUS_INTERACTED && o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
            spawn_mist_particles();
            o->activeFlags = 0;
            sGallerySnufits[o->oBehParams2ndByte] = NULL;
            create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
            // interact_coin(gMarioState, 0, o);
            play_sound(SOUND_GENERAL_COIN, gMarioState->marioObj->header.gfx.cameraToObject);
            gGalleryScore += 3;
    }
}


// void bhv_gallery_goomba_init(void) {
//     obj_set_hitbox(o, &sGalleryGoombaHitbox);

//     o->oGravity = -5.0f;
//     o->oMoveAngleYaw = 0x4000 * random_sign();;
// }


void bhv_new_gallery_goomba_update(void) {
    f32 animSpeed;

    if (obj_update_standard_actions(o->oGoombaScale)) {
        o->oGoombaScale = approach_f32_symmetric(o->oGoombaScale, 1.5f, 0.1f);
        cur_obj_scale(o->oGoombaScale);
        obj_update_blinking(&o->oGoombaBlinkTimer, 30, 50, 5);
        cur_obj_update_floor_and_walls();

        if ((animSpeed = o->oForwardVel / o->oGoombaScale * 0.4f) < 1.0f) {
            animSpeed = 1.0f;
        }

        cur_obj_init_animation_with_accel_and_sound(0, animSpeed);

        //obj_forward_vel_approach(20.0f * o->oGoombaScale, 0.4f);
        o->oForwardVel = 6.0f;// * o->oGoombaScale;
        cur_obj_move_standard(0);

        if (o->oInteractStatus & INT_STATUS_INTERACTED && o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
                spawn_mist_particles();
                o->activeFlags = 0;
                sGalleryGoombas[o->oBehParams2ndByte] = NULL;
                create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
                // interact_coin(gMarioState, 0, o);
                play_sound(SOUND_GENERAL_COIN, gMarioState->marioObj->header.gfx.cameraToObject);
                gGalleryScore += 1;
        }

    } else {
        o->oAnimState = 1;
    }

    if (o->oPosY < 1000.0f - 859.0f) {
        o->activeFlags = 0;
        sGalleryGoombas[o->oBehParams2ndByte] = NULL;
    }
}


 void bhv_new_gallery_shyguy_init(void) {
    obj_set_hitbox(o, &sShyguyHitbox);
    o->oOpacity = 0xFF;
    vec3f_copy(&o->oPosX, sNewShyguyPositions[o->oBehParams2ndByte]);
}

void bhv_new_gallery_shyguy_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oPosY = approach_f32_asymptotic(o->oPosY, o->oHomeY, 0.1f);
            if (o->oTimer > 90) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oPosY = approach_f32_asymptotic(o->oPosY, o->oHomeY + 120.0f, 0.1f);
            if (o->oTimer > 120) {
                o->oAction = 0;
            }

            if (o->oInteractStatus & INT_STATUS_INTERACTED && o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
                    spawn_mist_particles();
                    o->activeFlags = 0;
                    sGalleryShyguys[o->oBehParams2ndByte] = NULL;
                    create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
                    // interact_coin(gMarioState, 0, o);
                    play_sound(SOUND_GENERAL_COIN, gMarioState->marioObj->header.gfx.cameraToObject);
                    gGalleryScore += 5;
            }
            break;
    }
    o->oMoveAngleYaw = o->oAngleToMario;
    o->oInteractStatus = 0;
}

void new_gallery_spawn_enemies(void) {
    struct Object *obj;

    if (/*o->oShyguyCount < 12 && */o->oShyguyIndex == 0) {
        if (sGalleryShyguys[0] == NULL && sGalleryShyguys[1] == NULL && ++o->oShyguyTimer > 90) {
            sGalleryShyguys[0] = spawn_object(o, MODEL_SHYGUY, bhvNewGalleryShyguy);
            sGalleryShyguys[1] = spawn_object(o, MODEL_SHYGUY, bhvNewGalleryShyguy);
            sGalleryShyguys[1]->oBehParams2ndByte = 1;
            o->oShyguyIndex = 1;
            o->oShyguyTimer = 0;
            o->oShyguyCount++;
        }
    } else/* if (o->oShyguyCount < 12)*/ {
        if (sGalleryShyguys[2] == NULL && sGalleryShyguys[3] == NULL && ++o->oShyguyTimer > 90) {
            sGalleryShyguys[2] = spawn_object(o, MODEL_SHYGUY, bhvNewGalleryShyguy);
            sGalleryShyguys[3] = spawn_object(o, MODEL_SHYGUY, bhvNewGalleryShyguy);
            sGalleryShyguys[2]->oBehParams2ndByte = 2;
            sGalleryShyguys[3]->oBehParams2ndByte = 3;
            o->oShyguyIndex = 0;
            o->oShyguyTimer = 0;
            o->oShyguyCount++;
        }
    }

    // if (o->oGoombaCount < 7) {
        if (o->oGoombaIndex < 6) {
            if (++o->oGoombaTimer > 75) {
                sGalleryGoombas[o->oGoombaIndex] = spawn_object(o, MODEL_GOOMBA, bhvNewGalleryGoomba);
                sGalleryGoombas[o->oGoombaIndex]->oBehParams2ndByte = o->oGoombaIndex;
                o->oGoombaIndex++;
                o->oGoombaTimer = 0;
            }
        } else {
            if (cur_obj_nearest_object_with_behavior(bhvNewGalleryGoomba) == NULL) {
                o->oGoombaIndex = 0;
                o->oGoombaTimer = -120;
                o->oGoombaCount++;
            }
        }
    // }

    // if (o->oSnufitCount < 5) {
        if (o->oSnufitIndex < 3) {
            if (++o->oSnufitTimer > 120) {
                sGallerySnufits[o->oSnufitIndex] = spawn_object(o, MODEL_SNUFIT, bhvNewGallerySnufit);
                sGallerySnufits[o->oSnufitIndex]->oBehParams2ndByte = o->oSnufitIndex;
                vec3f_copy(&sGallerySnufits[o->oSnufitIndex]->oPosX, sNewSnufitPositions[o->oSnufitIndex]);
                o->oSnufitIndex++;
                o->oSnufitTimer = 0;

            }
        } else {
            if (cur_obj_nearest_object_with_behavior(bhvNewGallerySnufit) == NULL) {
                o->oSnufitIndex = 0;
                o->oSnufitTimer = -210;
                o->oSnufitCount++;
            }
        }
    // }
}

void new_gallery_kill_enemies(void) {
    s32 i;
    struct Object *obj;
    for (i = 0; i < 4; i++) {
        while ((obj = cur_obj_nearest_object_with_behavior(sNewGalleryEnemies[i])) != NULL) {
            obj->activeFlags = 0;
        }
    }
}


// void bhv_gallery_handler_init(void) {
//     o->os16F4 = (NEW_MINIGAME_SECONDS*30 + 1);

//     sGalleryShyguys[0] = NULL; sGalleryShyguys[1] = NULL; sGalleryShyguys[2] = NULL; sGalleryShyguys[3] = NULL;
//     sGalleryGoombas[0] = NULL; sGalleryGoombas[1] = NULL; sGalleryGoombas[2] = NULL; 
//     sGalleryGoombas[3] = NULL; sGalleryGoombas[4] = NULL; sGalleryGoombas[5] = NULL;
//     sGallerySnufits[0] = NULL; sGallerySnufits[1] = NULL; sGallerySnufits[2] = NULL;
// }

void bhv_new_gallery_handler_loop(void) {
    struct Object *obj;
    struct MarioState *m = gMarioState;
    Vec3f pos;
    switch (o->oAction) {
        case 0:
            obj = cur_obj_nearest_object_with_behavior(bhvCannon);
            if (obj != NULL && lateral_dist_between_objects(gMarioObject, obj) < 600.0f) {
                print_text_fmt_int(20, 167, "HIGH  %d", save_file_get_gallery_score(), 4);
            }
            if (m->action == ACT_IN_CANNON && m->actionState == 2) {
                o->oAction = 1;
                play_music(0, SEQUENCE_ARGS(4, SEQ_GALLERY), 0);
            }
            if (m->pos[2] < -1700.0f) {
                m->pos[2] = -1700.0f;
            }
            break;
        case 1:
            new_gallery_spawn_enemies();

            if (gGalleryScore < 0) {
                gGalleryScore = 0;
            }

            o->os16F4--;
            if (o->os16F4 > 10*30) {
                if (o->os16F4 % 30 == 0) {
                    // play_sound(SOUND_GENERAL2_SWITCH_TICK_SLOW, gGlobalSoundSource);
                }
                o->os16F6 = 209;
                o->os16F8 = 20;
            } else {
                if (o->os16F4 % 30 == 0 || o->os16F4 % 30 == 15) {
                    // play_sound(SOUND_GENERAL2_SWITCH_TICK_FAST, gGlobalSoundSource);
                }
                o->os16FA += 0x1000;
                o->os16F6 = 209 + (sins(o->os16FA) * 2);
                o->os16F8 = 20 + (coss(o->os16FA) * 2);
            }

            print_text_fmt_int(o->os16F8, o->os16F6, "TIME  %d", o->os16F4 / 30, 0);

            print_text_fmt_int(20, 187, "SCORE %d", gGalleryScore, 3);
            print_text_fmt_int(20, 167, "HIGH  %d", save_file_get_gallery_score(), 4);


            //print_text_fmt_int(20, 200, "POINTS %d", o->os16F6, 0);
            //print_text_fmt_int(20, 215, "GOAL %d", MINIGAME_GOAL, 0);
            if (o->os16F4 <= 0) {
                o->oAction = 2;
                stop_background_music(SEQUENCE_ARGS(4, SEQ_GALLERY));
            }
            if (m->health < 0x800) {
                m->health = 0x800;
            }
            break;
        case 2:
            new_gallery_kill_enemies();
            // o->activeFlags = 0;
            if (o->oTimer > 30) {
                if (gGalleryScore > save_file_get_gallery_score()) {
                    save_file_set_gallery_score(gGalleryScore);
                }
                o->oAction = 0;
                bhv_gallery_handler_init();
                gGalleryScore = 0;
                o->os16F6 = 0;
                o->os16F8 = 0;
                o->oShyguyTimer = 0;
                o->oGoombaTimer = 0;
                o->oSnufitTimer = 0;
                o->oShyguyIndex = 0;
                o->oGoombaIndex = 0;
                o->oSnufitIndex = 0;
            }
            break;
    }
}

void bhv_new_cannon_balls_loop(void) {
    s32 i;
    struct Object *obj;
    if (o->oTimer > 90) {
        o->activeFlags = 0;
    }

    for (i = 0; i < 4; i++) {
        if (cur_obj_dist_to_nearest_object_with_behavior(sNewGalleryEnemies[i]) < 200.0f) {
            obj = cur_obj_nearest_object_with_behavior(sNewGalleryEnemies[i]);
            if (i != 3) {
                attack_object(obj, 2);
            } else {
                obj->activeFlags = 0;
                spawn_mist_particles();
            }
            o->activeFlags = 0;
            break;
        }
    }


    cur_obj_update_floor_and_walls();

    obj_compute_vel_from_move_pitch(200.0f);
    if (obj_check_attacks(&sCannonBallHitbox, 1) != 0) {
        // We hit Mario while he is metal!
        // Bounce off, and fall until the first check is true.
        o->oMoveAngleYaw += 0x8000;
        o->oForwardVel *= 0.05f;
        o->oVelY = 30.0f;
        o->oGravity = -4.0f;

        cur_obj_become_intangible();
        o->oDeathSound = -1;
        obj_die_if_health_non_positive();
    } else if (o->oMoveFlags & (OBJ_MOVE_MASK_ON_GROUND | OBJ_MOVE_HIT_WALL)) {
        o->oDeathSound = -1;
        obj_die_if_health_non_positive();
    }

    cur_obj_move_standard(78);
}

// GALLERY END



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