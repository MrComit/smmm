static struct ObjectHitbox sMiniShyguyHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 80,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 100,
    /* hurtboxHeight:     */ 60,
};


// Vec3s sPaintingEnemyCols[2] = {
//     {0xC7, 0xB4, 0xAD}, // h 16, s 0.13, v 0.78
//     {0xA3, 0xCE, 0xA4}, // h 121, s 0.20, v 0.80
// };


s32 mario_in_painting_teleport(s32 param) {
    struct MarioState *m = gMarioState;
    switch (param) {
        case 0:
            if (m->pos[0] < -19164.0f && m->pos[0] > -19477.0f) {
                if (m->pos[2] < 778.0f && m->pos[2] > 478.0f) {
                    if (m->pos[1] > 3250.0f && m->pos[1] < 3784.0f) {
                        return TRUE;
                    }
                }
            }
            break;
        case 1:
            if (m->pos[0] < -21368.0f && m->pos[0] > -21681.0f) {
                if (m->pos[2] < 7378.0f && m->pos[2] > 7078.0f) {
                    if (m->pos[1] > 2200.0f && m->pos[1] < 2715.0f) {
                        return TRUE;
                    }
                }
            }
            break;
    }

    return FALSE;
}

void bhv_painting_teleport_init(void) {
    o->oObjF4 = cur_obj_nearest_object_with_behavior(bhvPaintingTeleport);
}


void bhv_painting_teleport_loop(void) {
    if (gMarioCurrentRoom != o->oRoom) {
        return;
    }
    if (o->oObjF4 == NULL) {
        o->activeFlags = 0;
        return;
    }

    switch (o->oAction) {
        case 0:
            if (mario_in_painting_teleport(o->oBehParams2ndByte)) {
                o->oAction = 1;
                o->oObjF4->oAction = 2;
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 8, 0xFF, 0xFF, 0xFF);
                play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
            }
            break;
        case 1:
            if (o->oTimer == 8) {
                vec3f_copy(gMarioState->pos, &o->oObjF4->oPosX);
                gMarioState->faceAngle[1] = o->oObjF4->oFaceAngleYaw;
                gMarioState->pos[0] += 100.0f * sins(gMarioState->faceAngle[1]);
                gMarioState->pos[2] += 100.0f * coss(gMarioState->faceAngle[1]);
            }
            if (o->oTimer > 15) {
                play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 10, 0xFF, 0xFF, 0xFF);
                o->oAction = 2;
            }
            break;
        case 2:
            if (o->oTimer > 20 && o->oDistanceToMario > 300.0f) {
                o->oAction = 0;
            }
            break;
    }
}



void bhv_painting_brick_init(void) {
    if ((o->oBehParams >> 24) == 0) {
        o->oFloatF4 = 800.0f;
    } else {
        o->oFloatF4 = (u8)(o->oBehParams >> 24) * 10.0f;
    }
}

void bhv_painting_brick_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            obj = CL_nearest_object_with_behavior_and_field(bhvPaintingBrick, 0x144, (o->oBehParams2ndByte - 1));
            if (obj == NULL || obj->oAction == 2) {
                if (o->oDistanceToMario < o->oFloatF4) {
                    o->oAction = 1;
                    o->oForwardVel = 20.0f;
                    cur_obj_unhide();
                }
            }
            break;
        case 1:
            cur_obj_play_sound_1(SOUND_ENV_METAL_BOX_PUSH);


            CL_Move();
            if (o->oTimer >= 23) {
                o->oAction = 2;
            }
            load_object_collision_model();
            break;
        case 2:
            load_object_collision_model();
            break;
    }
}


void bhv_mini_shyguy_init(void) {
    obj_set_hitbox(o, &sMiniShyguyHitbox);
    o->oOpacity = 0xFF;
}


void bhv_mini_shyguy_loop(void) {
    struct Object *obj;
    // cur_obj_scale(o->oGoombaScale);
    cur_obj_update_floor_and_walls();
    // goomba_act_walk();
    if (o->oDistanceToMario < 1000.0f) {
        o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x600);
        o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 20.0f, 2.0f);
    } else {
        o->oMoveAngleYaw = 0x4000;
        o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 40.0f, 1.0f);
    }
    cur_obj_move_standard(-78);
    if (o->oInteractStatus & INT_STATUS_INTERACTED || o->oTimer > 180) {
            spawn_mist_particles();
            o->activeFlags = 0;
            create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
    }
    o->oInteractStatus = 0;
}

void bhv_painter_shyguy_init(void) {
    o->oObjF4 = cur_obj_nearest_object_with_behavior(bhvPaintingEnemyRespawn);
    obj_set_hitbox(o, &sShyguyHitbox);
    o->os16106 = -0x400;
}

void bhv_painter_shyguy_loop(void) {
    struct Object *obj;
    if (o->oObjF4 == NULL) {
        o->activeFlags = 0;
        return;
    }

    if (o->oDistanceToMario < 1500.0f) {
        o->oOpacity = approach_s16_symmetric(o->oOpacity, 200, 4);
    }

    if (o->oObjF4->oAction == 0 && o->os16FA++ <= 20) {
        o->os16104 += 0x10000 / 20;
        // o->oFaceAnglePitch = 0xC00 + (sins(o->os16104 - 0x4000) * 0xC00);
        o->os16106 = -0x400 + (sins(o->os16104) * -0x1C00);
    }

    o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, o->os16106, absi(o->oFaceAnglePitch - o->os16106) / 3);

    if (o->oObjF4->oAction == 1) {
        o->os16FA = 1;
    }

    if (o->oInteractStatus & INT_STATUS_INTERACTED && o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
        spawn_mist_particles();
        obj_spawn_loot_yellow_coins(o, o->oNumLootCoins, 20.0f);
        o->activeFlags = 0;
        create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
        obj = cur_obj_nearest_object_with_behavior(bhvPaintbrush);
        if (obj != NULL) {
            obj->activeFlags = 0;
        }
        o->oObjF4->o104 = 1;
    }
    o->oInteractStatus = 0;
}


void bhv_paintbrush_init(void) {
    o->oObjF4 = cur_obj_nearest_object_with_behavior(bhvPaintingEnemyRespawn);
    o->os16106 = 0x400;

    if (save_file_get_boos() & (1 << 20)) {
        o->activeFlags = 0;
    }

}


void bhv_paintbrush_loop(void) {
    if (o->oObjF4 == NULL) {
        o->activeFlags = 0;
        return;
    }
    if (o->oObjF4->oAction == 0 && o->os16FA++ <= 20) {
        o->os16F8 += 0x10000 / 20;
        o->os16106 = 0x400 + (sins(o->os16F8) * 0x1C00);
    }

    o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, o->os16106, absi(o->oFaceAnglePitch - o->os16106) / 3);

    if (o->oObjF4->oAction == 1) {
        o->os16FA = 1;
    }
}



void bhv_painting_enemy_respawn_loop(void) {
    struct Object *obj;
    f32 m, b, e1, d, yDif;
    switch (o->oAction) {
        case 0:
            m = coss(o->oFaceAngleYaw) / sins(o->oFaceAngleYaw);
            b = o->oPosZ - (o->oPosX * m);
            e1 = absf((m * gMarioState->pos[0]) - gMarioState->pos[2] + b);
            d = e1 / sqrtf(m*m + 1);
            yDif = absf(gMarioState->pos[1] - o->oPosY);
            if (gMarioState->pos[0] < -21000.0f && d < 500.0f && yDif < 500.0f && o->oTimer > 20) {
                o->oAction = 1;
                obj = spawn_object(o, MODEL_BG_SHYGUY, bhvMiniShyguy);
                obj->parentObj = obj;
                obj->oFaceAngleYaw = obj->oMoveAngleYaw += 0x8000;
                cur_obj_play_sound_1(SOUND_ACTION_TELEPORT);
                // o->oFlags &= ~OBJ_FLAG_DISABLE_TO_ROOM_CLEAR;
            }

            o->oFloatFC = approach_f32_symmetric(o->oFloatFC, 0.16f, 0.01f);
            o->oFloat100 = approach_f32_symmetric(o->oFloat100, 0.8f, 0.05f);

            CL_HSVtoRGB(o->os16FA, o->oFloatFC, o->oFloat100, &o->os16F4, &o->os16F6, &o->os16F8);
            break;
        case 1:
            o->oFloatFC = approach_f32_symmetric(o->oFloatFC, 0.0f, 0.01f);
            o->oFloat100 = approach_f32_symmetric(o->oFloat100, 0.0f, 0.05f);

            CL_HSVtoRGB(o->os16FA, o->oFloatFC, o->oFloat100, &o->os16F4, &o->os16F6, &o->os16F8);

            if (o->oTimer > 25) {
                if (o->o104) {
                    o->oAction = 2;
                    o->oFlags &= ~OBJ_FLAG_DISABLE_TO_ROOM_CLEAR;
                } else {
                    o->oAction = 0;
                }
            }
            break;
    }
}









void bhv_painting_enemy_init(void) {
    // o->os16F4 = sPaintingEnemyCols[o->oBehParams2ndByte][0];
    // o->os16F6 = sPaintingEnemyCols[o->oBehParams2ndByte][1];
    // o->os16F8 = sPaintingEnemyCols[o->oBehParams2ndByte][2];
    o->oAnimState = o->oBehParams2ndByte;
    o->oOpacity = 255;
    if (o->oBehParams2ndByte == 2) {
        o->os16FA = 0;
    } else if (o->oBehParams2ndByte == 1) {
        o->os16FA = 121;
    } else {
        o->os16FA = 16;
    }
    o->oFloatFC = 0.16f;
    o->oFloat100 = 0.8f;

    CL_HSVtoRGB(o->os16FA, o->oFloatFC, o->oFloat100, &o->os16F4, &o->os16F6, &o->os16F8);

    if (save_file_get_boos() & (1 << 20)) {
        o->oAction = 1;
        o->o104 = 1;
    }
}



void bhv_painting_enemy_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 1000.0f) {
                o->oAction = 1;
                cur_obj_play_sound_1(SOUND_ACTION_TELEPORT);
                if (o->oBehParams2ndByte == 0) {
                    obj = spawn_object(o, MODEL_BG_GOOMBA, bhvGoomba);
                } else {
                    obj = spawn_object(o, MODEL_BG_KOOPA, bhvKoopa);
                    obj->oPosX += 50.0f;
                    obj->oPosZ += 50.0f;
                    obj->oPosY = o->oPosY;
                }
                obj->oFaceAngleYaw = obj->oMoveAngleYaw += 0x8000;
                o->oFlags &= ~OBJ_FLAG_DISABLE_TO_ROOM_CLEAR;
            }
            break;
        case 1:
            o->oFloatFC = approach_f32_symmetric(o->oFloatFC, 0.0f, 0.01f);
            o->oFloat100 = approach_f32_symmetric(o->oFloat100, 0.0f, 0.05f);

            CL_HSVtoRGB(o->os16FA, o->oFloatFC, o->oFloat100, &o->os16F4, &o->os16F6, &o->os16F8);
            break;
    }
}