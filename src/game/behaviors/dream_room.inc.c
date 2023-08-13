s32 absi(s32 x);
extern u8 gDreamEnv;

static struct ObjectHitbox sYoshiHeadHitbox = {
    /* interactType:      */ INTERACT_IGLOO_BARRIER,
    /* downOffset:        */ 300,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 200,
    /* height:            */ 550,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};


static struct ObjectHitbox sAttackPenguinHitbox = {
    /* interactType:      */ INTERACT_IGLOO_BARRIER,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 2,
    /* radius:            */ 75,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 75,
    /* hurtboxHeight:     */ 100,
};


void bhv_dream_penguin_attack_init(void) {
    obj_set_hitbox(o, &sAttackPenguinHitbox);
}


void bhv_dream_penguin_attack_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            if (o->oObj100 == NULL || o->oObj100->oAction == 6) {
                o->oAction = 1;
            }
            break;
        case 1:
            set_mario_npc_dialog(1);
            o->oFloatF4 = approach_f32_symmetric(o->oFloatF4, 2.5f, 0.08f);
            cur_obj_scale(o->oFloatF4);
            gDreamEnv = approach_s16_symmetric(gDreamEnv, 0, 1);
            if (o->oFloatF4 >= 2.5f && gDreamEnv == 0) {
                o->oFloat108 = gMarioState->pos[1] - 12599.0f;
                if (o->oBehParams2ndByte) {
                    CL_call_warp(0, -5000 - (gMarioState->pos[1] - 12599), 0);
                }
                o->oAction = 3;
                o->oForwardVel = 10.0f;
                o->oInteractType = INTERACT_BOUNCE_TOP;
                set_mario_npc_dialog(0);
            }
            break;
        case 2:
            cur_obj_update_floor_and_walls();
            if (o->oTimer & 16 == 0) {
                play_sound(SOUND_OBJ_BIG_PENGUIN_YELL, gGlobalSoundSource);
            }
            play_penguin_walking_sound(PENGUIN_WALK_BABY);
            if (o->oTimer > o->os16106) {
                o->os16104 = CL_RandomMinMaxU16(0, 10) - 5;
                o->os16106 = CL_RandomMinMaxU16(40, 100);
                o->oTimer = 0;
            }

            o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 25.0f + (f32)(o->os16104), 0.1f);
            cur_obj_move_standard(-78);
            // CL_Move();
            o->os16FA = approach_s16_symmetric(o->os16FA, 0x40, 0x4);
            o->os16F8 = approach_s16_symmetric(o->os16F8, 0x600, o->os16FA + (o->os16104 * 4));
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, o->os16F8);
            o->oFaceAngleYaw = o->oMoveAngleYaw;

            if (o->oInteractStatus & INT_STATUS_INTERACTED && o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
                spawn_mist_particles();
                obj_force_spawn_loot_coins(o, o->oNumLootCoins, 20.0f, bhvSingleCoinGetsSpawned, 0, MODEL_YELLOW_COIN);

                o->activeFlags = 0;
                create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
            }
            break;
        case 3:
            if (o->oBehParams2ndByte) {
                obj = cur_obj_nearest_object_with_behavior(bhvAirborneDeathWarp);
                if (obj != NULL) {
                    vec3f_copy(&obj->oPosX, gMarioState->pos);
                    obj->oFaceAngleYaw = gMarioState->faceAngle[1];
                }
            }
            o->oPosY -= (5000.0f + o->oFloat108);
            o->oAction = 2;
            break;
    }
    o->oInteractStatus = 0;
}



void bhv_dream_penguin_loop(void) {
    f32 pos;
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(-78);
            if (absf(o->oPosY - gMarioState->pos[1]) > 3000.0f) {
                cur_obj_hide();
            } else {
                cur_obj_unhide();
                play_penguin_walking_sound(PENGUIN_WALK_BABY);
            }

            if (obj_check_if_collided_with_object(o, gMarioObject) == TRUE) {
                play_sound(SOUND_MENU_COLLECT_SECRET, gGlobalSoundSource);
                o->oAction = 1;
                cur_obj_hide();
                spawn_object(o, MODEL_SPARKLES, bhvGoldenCoinSparkles);
            }
            break;
        case 1:
            set_mario_npc_dialog(1);
            gDreamEnv = approach_s16_symmetric(gDreamEnv, 0, 10);
            if (gDreamEnv == 0) {
                switch (o->oBehParams2ndByte) {
                    case 0:
                        pos = 6000.0f;
                        break;
                    case 1:
                        pos = -15888.0f;
                        break;
                    case 2:
                        pos = 10103.0f;
                        obj = cur_obj_nearest_object_with_behavior(bhvDreamYoshi);
                        if (obj != NULL) {
                            // obj->oAction = 4;
                            obj->os16112 = 1;
                        }
                        break;
                }
                // CL_instantly_warp(pos);
                CL_call_warp(0, pos, 0);
                o->oAction = 2;
                // set_mario_npc_dialog(0);
            }
            break;
        case 2:
            set_mario_npc_dialog(1);
            gDreamEnv = approach_s16_symmetric(gDreamEnv, 255, 10);
            if (gDreamEnv == 255) {
                obj = cur_obj_nearest_object_with_behavior(bhvAirborneDeathWarp);
                if (obj != NULL) {
                    vec3f_copy(&obj->oPosX, gMarioState->pos);
                    obj->oFaceAngleYaw = gMarioState->faceAngle[1];
                }
                o->activeFlags = 0;
                set_mario_npc_dialog(0);
            }
            break;
    }
}


void bhv_dream_yoshi_loop(void) {
    struct Object *obj;
    Vec3s pos;
    if (gMarioCurrentRoom != o->oRoom) {
        return;
    }
    if (absf(o->oPosY - gMarioState->pos[1]) > 3000.0f) {
        cur_obj_hide();
    } else {
        cur_obj_unhide();
    }
    switch (o->oAction) {
        case 0:
            if (o->oTimer == 0) {
                gDreamEnv = 0;
            }
            if (gMarioState->pos[0] >= -7500.0f) {
                set_mario_npc_dialog(1);
                gDreamEnv = approach_s16_symmetric(gDreamEnv, 0, 10);
                if (gDreamEnv == 0) {
                    CL_call_warp(0, 5000, 0);
                    o->oAction = 8;
                }
                // cur_obj_unhide();
                // o->oAction = 1;
            }
            break;
        case 1:
            if (o->oTimer < 45) {
                cur_obj_hide();
            }

            if (o->oInteractStatus == INT_STATUS_INTERACTED) {
                o->oAction = 2;
            }
            break;
        case 2:
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x600);
            // if ((s16) o->oMoveAngleYaw == (s16) o->oAngleToMario) {
                if (CL_NPC_Dialog(DIALOG_161)) {
                    o->oAction = 3;
                    obj = spawn_object_abs_with_rot(o, 0, MODEL_PENGUIN, bhvDreamPenguin, -6891, 12799, 19466, 0, DEGREES(180), 0);
                    obj->oRoom = o->oRoom;
                    obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
                    o->oInteractType = INTERACT_IGLOO_BARRIER;
                }
            // }
            break;
        case 3:
            if (o->os16112) {
                o->oAction = 4;
                o->oInteractType = INTERACT_TEXT;

                pos[0] = o->oPosX - 400;
                pos[1] = o->oPosY + 300;
                pos[2] = o->oPosZ - 300;
                obj = spawn_object_abs_with_rot(o, 0, MODEL_PENGUIN, bhvDreamPenguinAttack, pos[0], pos[1], pos[2], 0, 0, 0);
                obj->oObj100 = o;
                obj->oRoom = o->oRoom;
                obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
                obj->oBehParams2ndByte = 1;

                pos[0] += 400;
                pos[2] -= 200;
                obj = spawn_object_abs_with_rot(o, 0, MODEL_PENGUIN, bhvDreamPenguinAttack, pos[0], pos[1], pos[2], 0, 0, 0);
                obj->oObj100 = o;
                obj->oRoom = o->oRoom;
                obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;

                pos[0] += 300;
                pos[2] += 100;
                obj = spawn_object_abs_with_rot(o, 0, MODEL_PENGUIN, bhvDreamPenguinAttack, pos[0], pos[1], pos[2], 0, 0, 0);
                obj->oObj100 = o;
                obj->oRoom = o->oRoom;
                obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
            }
            break;
        case 4:
            if (o->oInteractStatus == INT_STATUS_INTERACTED) {
                o->oAction = 5;
            }
            break;
        case 5:
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x600);
            // if ((s16) o->oMoveAngleYaw == (s16) o->oAngleToMario) {
                if (CL_NPC_Dialog(DIALOG_162)) {
                    o->oAction = 6;
                    o->oInteractType = INTERACT_IGLOO_BARRIER;
                    o->oInteractionSubtype = 0;
                    set_mario_npc_dialog(1);
                }
            // }
            break;
        case 6:
            o->oFloat104 = approach_f32_symmetric(o->oFloat104, 60.0f, 0.8f);
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY + 1800.0f, o->oFloat104);
            spawn_mist_particles();
            if (cur_obj_nearest_object_with_behavior(bhvDreamPenguinAttack) == NULL) {
                o->oAction = 7;
                play_puzzle_jingle();
            }
            break;
        case 7:
            gDreamEnv = approach_s16_symmetric(gDreamEnv, 255, 10);
            if (gDreamEnv == 255) {
                o->activeFlags = 0;
            }
            break;
        case 8:
            cur_obj_hide();
            if (o->oTimer > 20) {
                gDreamEnv = approach_s16_symmetric(gDreamEnv, 255, 10);
                if (gDreamEnv == 255) {
                    obj = cur_obj_nearest_object_with_behavior(bhvAirborneDeathWarp);
                    if (obj != NULL) {
                        vec3f_copy(&obj->oPosX, gMarioState->pos);
                        obj->oFaceAngleYaw = gMarioState->faceAngle[1];
                    }
                    o->oAction = 1;
                    set_mario_npc_dialog(0);
                }
            }
            break;
    }
    o->oInteractStatus = 0;
}


void bhv_yoshi_head_init(void) {
    if (o->oPosY < 5000.0f) {
        o->os16108 = 1200;  // MAX DIST
    } else {
        o->os16108 = 1500;  // MAX DIST
    }
    obj_set_hitbox(o, &sYoshiHeadHitbox);
}


void bhv_yoshi_head_line_init(void) {
    if (o->oPosY < 5000.0f) {
        o->os16108 = 700;  // MAX DIST
        o->os1610A = 700;  // MAX DIST
    } else {
        o->os1610A = 1000;  // MAX DIST
        o->os16108 = 1000;  // MAX DIST
    }
    obj_set_hitbox(o, &sYoshiHeadHitbox);
}

void bhv_yoshi_head_rectangle_init(void) {
    // o->oF4 = 1;
    obj_set_hitbox(o, &sYoshiHeadHitbox);
    if (o->oPosY < 5000.0f) {
        o->os16108 = 1000;  // MAX DIST
    } else {
        o->os16108 = 2000;  // MAX DIST
    }
    o->oFloatFC = o->oPosX;
    o->oFloat100 = o->oPosZ;
    o->oAction = (o->oBehParams >> 8) & 0xFF;
    o->oMoveAngleYaw = o->oFaceAngleYaw = 0x4000 * o->oAction;
    o->o104 = o->oMoveAngleYaw;
    switch (o->oAction) {
        case 1:
            o->oPosZ += (o->oBehParams2ndByte * 100.0f);
            break;
        case 2:
            o->oPosZ += (o->oBehParams2ndByte * 100.0f);
            o->oPosX += (o->oBehParams >> 24) * 100.0f;
            break;
        case 3:
            o->oPosX += (o->oBehParams >> 24) * 100.0f;
            break;
    }
}


s32 yoshi_head_respawn(Vec3f pos, s16 faceAngle, s16 damage) {
    vec3f_set(gMarioState->vel, 0, 0, 0);
    switch (o->os16110) {
        case 0:
            play_transition(WARP_TRANSITION_FADE_INTO_CIRCLE, 0x10, 0x00, 0x00, 0x00);
            break;
        case 13:
            vec3f_copy(gMarioState->pos, pos);
            CL_set_camera_pos(pos, pos);
            gMarioState->faceAngle[1] = faceAngle;
            s8DirModeBaseYaw = (s16)(faceAngle & 0xC000) - 0x4000;
            set_mario_action(gMarioState, ACT_JUMP_LAND_STOP, 0);
            break;
        case 16:
            play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 0xC, 0x00, 0x00, 0x00);
            gMarioState->hurtCounter = 4 * damage;
            o->os16110 = 0;
            return 1;
            break;
    }
    o->os16110++;
    return 0;
}



void yoshi_head_calc(void) {
    s32 i = 0;
    f32 length, sin, cos;
    f32 divisor;
    struct Object *obj;
    struct Surface *wall;
    struct MarioState *m = gMarioState;

    // RAYCAST TYPE THING
    o->oHomeY = o->oPosY;
    length = 0;
    sin = sins(o->oMoveAngleYaw);
    cos = coss(o->oMoveAngleYaw);
    while (wall == NULL) {
        length += 50.0f;
        if (length >= o->os16108) {
            length = o->os16108;
            break;
        }
        o->oHomeX = o->oPosX + (length * sin);
        o->oHomeZ = o->oPosZ + (length * cos);
        wall = resolve_and_return_wall_collisions(&o->oHomeX, 0, 90.0f);
        if (wall != NULL) {
            length -= 10.0f;
            while (o->oSurfF8 == NULL) {
                length += 10.0f;
                o->oHomeX = o->oPosX + (length * sin);
                o->oHomeZ = o->oPosZ + (length * cos);
                o->oSurfF8 = resolve_and_return_wall_collisions(&o->oHomeX, 0, 40.0f);
                if (o->oSurfF8 != NULL) {
                    length -= 10.0f;
                    o->oSurfF8 = NULL;
                    break;
                }
                i++;
                if (i >= 20) {
                    return;
                }
            }
            break;
        }

    }
    // LENGTH SET
    o->oF4 = length;


    //MARIO DISTANCE FROM LINE
    // m1 = coss(o->oMoveAngleYaw) / sins(o->oMoveAngleYaw);
    // b = o->oPosZ - (o->oPosX * m1);
    // e1 = absf((m1 * m->pos[0]) - m->pos[2] + b);
    // d = e1 / sqrtf(m1*m1 + 1);
    // yDif = absf(m->pos[1] - o->oPosY);
    // if ((s16)o->oDistanceToMario < o->oF4 && d < (o->oDistanceToMario / 10.0f) && yDif < 500.0f 
    //     && absi(o->oAngleToMario - (s16)o->oMoveAngleYaw) < 0x400) {
    //     if (o->oTimer > 60) {
    //         CL_get_hit(gMarioState, gMarioObject, 0);
    //         // spawn_object(o, MODEL_SAWBLADE, bhvSawbladeShoot);
    //         o->oTimer = 0;
    //     }
    // }

    // divisor = (f32)o->oF4 / 1024.0f;
    // if (o->os16112 == 0 && absf(o->oPosY - m->pos[1]) < 800.0f && (s16)o->oDistanceToMario < o->oF4 && 
    //     absi(o->oAngleToMario - (s16)o->oMoveAngleYaw) < (o->oDistanceToMario / divisor)) {
    divisor = 2000.0f / o->oF4;
    if (o->os16112 == 0 && absf(o->oPosY - m->pos[1]) < 800.0f && (s16)o->oDistanceToMario < o->oF4 &&
        absi(o->oAngleToMario - (s16)o->oMoveAngleYaw) < (0x500 * divisor)) {
        // if (o->oTimer > 60) {
            CL_get_hit(m, gMarioObject, 0);
            o->os16112 = 1;
            // spawn_object(o, MODEL_SAWBLADE, bhvSawbladeShoot);
            // o->oTimer = 0;
        // }
    }
    // print_text_fmt_int(80, 80, "%x", absi(o->oAngleToMario - (s16)o->oMoveAngleYaw), 0);
    // print_text_fmt_int(80, 40, "%x", (s32)(o->oDistanceToMario / divisor), 0);
    if (o->os16112) {
        if (m->health < 0x300) {
            level_trigger_warp(m, WARP_OP_WARP_FLOOR_OBJECT);
            o->os16112 = 0;
        } else {
            obj = cur_obj_nearest_object_with_behavior(bhvAirborneDeathWarp);
            if (obj != NULL) {
                if (yoshi_head_respawn(&obj->oPosX, -obj->oFaceAngleYaw, 2)) {
                    o->os16112 = 0;
                }
            }
        }
    }


    if (gDreamEnv < 200 || absf(o->oPosY - gMarioState->pos[1]) > 3000.0f) {
        cur_obj_hide();
    } else {
        cur_obj_unhide();
        // if (obj_has_behavior(o, bhvYoshiHeadLine)) {
        //     print_text_fmt_int(80, 80, "%x", absi(o->oAngleToMario - (s16)o->oMoveAngleYaw), 0);
        // }
    }

}

void bhv_yoshi_head_spin_loop(void) {
    if (o->oBehParams2ndByte == 0) {
        o->oMoveAngleYaw += 0x100;
    } else {
        o->os1610A += 0x1C0;
        o->oMoveAngleYaw = (sins(o->os1610A) * 0x4000);
    }

    yoshi_head_calc();
    // if (o->os16112) {
    //     gDreamEnv = approach_s16_symmetric(gDreamEnv, 0, 10);
    // } else {
    //     gDreamEnv = approach_s16_symmetric(gDreamEnv, 255, 10);
    // }
}


void bhv_yoshi_head_rectangle_loop(void) {
    // o->oMoveAngleYaw += 0x100;
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->o104, 0x300);

    if ((u16)o->oMoveAngleYaw == o->o104) {
        if (absf(o->oPosY - gMarioState->pos[1]) < 800.0f) {
            cur_obj_play_sound_1(SOUND_ENV_ELEVATOR1);
        }

        switch (o->oAction) {
            case 0:
                o->oPosZ = approach_f32_symmetric(o->oPosZ, o->oFloat100 + (o->oBehParams2ndByte * 100.0f), 20.0f);
                if (o->oPosZ == o->oFloat100 + (o->oBehParams2ndByte * 100.0f)) {
                    o->oAction = 1;
                    o->o104 = 0x4000;
                }
                break;
            case 1:
                o->oPosX = approach_f32_symmetric(o->oPosX, o->oFloatFC + ((o->oBehParams >> 24) * 100.0f), 20.0f);
                if (o->oPosX == o->oFloatFC + ((o->oBehParams >> 24) * 100.0f)) {
                    o->oAction = 2;
                    o->o104 = 0x8000;
                }
                break;
            case 2:
                o->oPosZ = approach_f32_symmetric(o->oPosZ, o->oFloat100, 20.0f);
                if (o->oPosZ == o->oFloat100) {
                    o->oAction = 3;
                    o->o104 = 0xC000;
                }
                break;
            case 3:
                o->oPosX = approach_f32_symmetric(o->oPosX, o->oFloatFC, 20.0f);
                if (o->oPosX == o->oFloatFC) {
                    o->oAction = 0;
                    o->o104 = 0;
                }
                break;
        }
    }

    yoshi_head_calc();
}



void bhv_yoshi_head_line_loop(void) {
    // o->oMoveAngleYaw += 0x100;
    // o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->o104, 0x300);

    switch (o->oAction) {
        case 0:
            cur_obj_play_sound_1(SOUND_ENV_ELEVATOR1);
            o->os16108 = approach_s16_symmetric(o->os16108, o->os1610A, 90);
            o->oPosX += 20.0f * sins(o->oMoveAngleYaw);
            o->oPosZ += 20.0f * coss(o->oMoveAngleYaw);
            if (o->oTimer > o->oBehParams2ndByte) {
                o->oAction = 1;
                o->o104 = (u16)(o->oMoveAngleYaw + 0x8000);
            }
            break;
        case 1:
            o->os16108 = approach_s16_symmetric(o->os16108, 200, 70);
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->o104, 0x300);
            if ((u16)o->oMoveAngleYaw == o->o104 && o->os16108 == 200) {
                o->oAction = 0;
            }
            break;
    }

    yoshi_head_calc();
}