void spawn_orange_number_palette(s8 behParam, s16 relX, s16 relY, s16 relZ, s16 palette);
static struct ObjectHitbox sRedCoinHitbox = {
    /* interactType:      */ INTERACT_COIN,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 64,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};


static struct ObjectHitbox sGreenCoinHitbox = {
    /* interactType:      */ INTERACT_COIN,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 64,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};


s32 gRedCoinMissionActive = 1;

extern s8 gRedCoinsCollected;

void bhv_red_coin_init(void) {
    // Set the red coins to have a parent of the closest red coin star.
    // struct Object *hiddenRedCoinStar;

    // if ((hiddenRedCoinStar =
    //          cur_obj_nearest_object_with_behavior(bhvHiddenRedCoinStar)) != NULL) {
    //     o->parentObj = hiddenRedCoinStar;
    // } else if ((hiddenRedCoinStar =
    //          cur_obj_nearest_object_with_behavior(bhvBowserCourseRedCoinStar)) != NULL) {
    //     o->parentObj = hiddenRedCoinStar;
    // } else {
    //     o->parentObj = NULL;
    // }
    switch (gCurrLevelNum) {
        case LEVEL_BOB:
            o->oBehParams = 0;
            break;
        case LEVEL_WF:
            o->oBehParams = 1 << 24;
            break;
        case LEVEL_HMC:
            o->oBehParams = 2 << 24;
            break;
    }
    obj_set_hitbox(o, &sRedCoinHitbox);
}

/**
 * Main behavior for red coins. Primarily controls coin collection noise and spawning
 * the orange number counter.
 */
void bhv_red_coin_loop(void) {
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
            gRedCoinsCollected++;

            // Spawn the orange number counter, as long as it isn't the last coin.
            if (gRedCoinsCollected != 8) {
                spawn_orange_number_palette(gRedCoinsCollected, 0, 0, 0, 1);
            } else {
                // o->oBehParams = (o->oBehParams & 0xFF00) << 16;
                spawn_default_star(gMarioState->pos[0], gMarioState->pos[1] + 100.0f, gMarioState->pos[2]);
            }

            // On all versions but the JP version, each coin collected plays a higher noise.
            play_sound(SOUND_MENU_COLLECT_RED_COIN
                       + (((u8) gRedCoinsCollected - 1) << 16),
                       gGlobalSoundSource);

        coin_collected();
        o->oInteractStatus = 0;
    }
}

s16 sGreenStarSpawned[2] = {0, 0};


extern s8 gGreenCoinsCollected;
void bhv_green_coin_init(void) {
    struct Object *hiddenRedCoinStar;

    cur_obj_update_floor_height();

    if (gIsConsole || 500.0f < absf(o->oPosY - o->oFloorHeight)) {
        cur_obj_set_model(MODEL_GREEN_COIN_NO_SHADOW);
    }

    // Set the red coins to have a parent of the closest red coin star.
    hiddenRedCoinStar = cur_obj_nearest_object_with_behavior(bhvHiddenGreenCoinStar);
    if (hiddenRedCoinStar != NULL)
        o->parentObj = hiddenRedCoinStar;

    obj_set_hitbox(o, &sGreenCoinHitbox);
}


void bhv_green_coin_loop(void) {
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        if (o->parentObj != NULL) {
            gGreenCoinsCollected = ++o->parentObj->oHiddenStarTriggerCounter;
            gMarioState->healCounter += 4;
            if (o->parentObj->oHiddenStarTriggerCounter != 50) {
                spawn_orange_number_two_digit_scale(o->parentObj->oHiddenStarTriggerCounter, 0, 0, 0, 15.0f, 0.75f);
            }
            play_sound(SOUND_GENERAL_COIN, gGlobalSoundSource);
        }

        coin_collected();
        o->oInteractStatus = 0;
    }
}


void bhv_hidden_green_coin_star_init(void) {
    o->oRoom2 = 2;
    gGreenCoinsCollected = 0;
    o->oHiddenStarTriggerCounter = 0;
    if (save_file_get_currency_flags() & (1 << (o->oBehParams >> 24))) {
        o->oAction = 2;
    } else {
        if (gCurrAreaIndex == 1) {
            if (sGreenStarSpawned[0]) {
                o->oAction = 1;
                o->oHiddenStarTriggerCounter = sGreenStarSpawned[0];
            }
        } else {
            if (sGreenStarSpawned[1]) {
                o->oAction = 1;
                o->oHiddenStarTriggerCounter = sGreenStarSpawned[1];
            }
        }
    }
}

void bhv_hidden_green_coin_star_loop(void) {
    //gGreenCoinsCollected = o->oHiddenStarTriggerCounter;
    switch (o->oAction) {
        case 0:
            if (o->oHiddenStarTriggerCounter >= 50)
                o->oAction = 1;
            break;

        case 1:
            if (o->oTimer > 2) {
                spawn_default_star(o->oPosX, o->oPosY, o->oPosZ);
                spawn_mist_particles();
                o->oAction = 2;
                if (gCurrAreaIndex == 1) {
                    sGreenStarSpawned[0] = o->oHiddenStarTriggerCounter;
                } else {
                    sGreenStarSpawned[1] = o->oHiddenStarTriggerCounter;
                }
            }
            break;
    }
}

s32 gRedSparklesCollected = -1;
void bhv_red_sparkles_init(void) {
    gRedSparklesCollected = -1;
}

void bhv_red_sparkles_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            if (gRedSparklesCollected == -1 && o->oBehParams2ndByte == 0) {
                break;
            }
            spawn_object(o, MODEL_NONE, bhvRedSparkleSpawn);
            if (gRedSparklesCollected == -1 && o->oDistanceToMario < 800.0f) {
                gRedSparklesCollected = 0;
            }
            if (obj_check_if_collided_with_object(o, gMarioObject) == 1) {
                play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
                o->oAction = 1;
                // cur_obj_disable();
                o->oF4 = ++gRedSparklesCollected;
                
                // if (gRedSparklesCollected == 5) {
                //     obj = spawn_object(o, MODEL_RED_COIN, bhvPhysicsRedCoin);
                //     vec3f_set(&obj->oPosX, gMarioState->pos[0], gMarioState->pos[1] + 800.0f, gMarioState->pos[2]);
                //     vec3f_copy(&o->oPosX, &obj->oPosX);
                //     spawn_mist_particles();
                // }
            }
            break;
        case 1:
            if (gRedSparklesCollected == o->oF4) {
                if ((o->oTimer & 8) == 0) {
                    play_sound(SOUND_GENERAL2_SWITCH_TICK_FAST, gGlobalSoundSource);
                }
                if (o->oTimer > 80) {
                    gRedSparklesCollected = 0;
                    play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                }
            }
            if (gRedSparklesCollected == 5) {
                o->activeFlags = 0;
                if (o->oBehParams2ndByte == 1) {
                    o->oPosY += 800.0f;
                    obj = spawn_object(o, MODEL_RED_COIN, bhvPhysicsRedCoin);
                    // vec3f_set(&obj->oPosX, gMarioState->pos[0], gMarioState->pos[1] + 800.0f, gMarioState->pos[2]);
                    // vec3f_copy(&o->oPosX, &obj->oPosX);
                    spawn_mist_particles();
                }
            } else if (gRedSparklesCollected == 0 && o->oDistanceToMario > 250.0f) {
                // cur_obj_enable();
                o->oAction = 0;
                o->oF4 = 0;
            }

            break;
    }
    o->oInteractStatus = 0;
}

void bhv_physics_red_coin_init(void) {
    cur_obj_become_intangible();
    bhv_red_coin_init();
}

void bhv_physics_red_coin_loop(void) {
    struct Surface *sp1C;

    cur_obj_update_floor_and_walls();
    cur_obj_if_hit_wall_bounce_away();
    cur_obj_move_standard(-62);

    if ((sp1C = o->oFloor) != NULL) {
        if (o->oMoveFlags & OBJ_MOVE_ON_GROUND) {
            o->oSubAction = 1;
        }
        if (o->oSubAction == 1) {
            o->oBounciness = 0;
            if (sp1C->normal.y < 0.9) {
                s16 sp1A = atan2s(sp1C->normal.z, sp1C->normal.x);
                cur_obj_rotate_yaw_toward(sp1A, 0x400);
            }
        }
    }

    if (o->oTimer == 0) {
        cur_obj_play_sound_2(SOUND_GENERAL_COIN_SPURT);
    }

    if (o->oVelY < 0) {
        cur_obj_become_tangible();
    }

    if (o->oMoveFlags & OBJ_MOVE_LANDED) {
        if (o->oMoveFlags & (OBJ_MOVE_ABOVE_DEATH_BARRIER | OBJ_MOVE_ABOVE_LAVA))
        {
            obj_mark_for_deletion(o);
        }
    }

    if (o->oMoveFlags & OBJ_MOVE_BOUNCE) {
        if (o->oCoinUnk1B0 < 5) {
            cur_obj_play_sound_2(SOUND_GENERAL_COIN_DROP);
        }
        o->oCoinUnk1B0++;
    }
    if (o->oTimer > 30) {
        bhv_red_coin_loop();
    }
    o->oInteractStatus = 0;
}


void bhv_gold_medal_loop(void) {
    struct Object *obj;
    if (gRedCoinMissionActive) {
        if (o->oAction == 0 && o->oFlags & OBJ_FLAG_KICKED_OR_PUNCHED) {
            obj = spawn_object(o, MODEL_RED_COIN, bhvPhysicsRedCoin);
            obj->oPosX -= 150.0f;
            obj->oVelY = 20.0f;
            obj->oForwardVel = 20.0f;
            obj->oMoveAngleYaw = 0xC000;
            spawn_mist_particles();
            o->oAction = 1;
            cur_obj_play_sound_2(SOUND_GENERAL2_RIGHT_ANSWER);
        }
    }
}