/**
 * Behavior for bhvHiddenBlueCoin and bhvBlueCoinSwitch.
 * bhvHiddenBlueCoin are the stationary blue coins that appear when
 * you press a blue coin switch (a.k.a. bhvBlueCoinSwitch).
 */

/**
 * Update function for bhvHiddenBlueCoin.
 */
void bhv_hidden_blue_coin_loop(void) {
    struct Object *blueCoinSwitch;

    switch (o->oAction) {
        case HIDDEN_BLUE_COIN_ACT_INACTIVE:
            // Become invisible and intangible
            cur_obj_disable_rendering();
            cur_obj_become_intangible();

            // Set action to HIDDEN_BLUE_COIN_ACT_WAITING after the blue coin switch is found.
            o->oHiddenBlueCoinSwitch = cur_obj_nearest_object_with_behavior(bhvBlueCoinSwitch);

            if (o->oHiddenBlueCoinSwitch != NULL) {
                o->oAction++;
            } else if ((o->oHiddenBlueCoinSwitch = cur_obj_nearest_object_with_behavior(bhvBlueCoinSwitchAuto)) != NULL) {
                o->oAction++;
            }
            break;
        case HIDDEN_BLUE_COIN_ACT_WAITING:
            // Wait until the blue coin switch starts ticking to activate.
            blueCoinSwitch = o->oHiddenBlueCoinSwitch;

            if (o->oOpacity) {
                cur_obj_enable_rendering();
            } else {
                cur_obj_disable_rendering();
            }
            if (gMarioState->floor->object == blueCoinSwitch) {
                o->oOpacity = approach_s16_symmetric(o->oOpacity, 165, 25);
            } else {
                o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 40);
            }

            if (blueCoinSwitch->oAction == BLUE_COIN_SWITCH_ACT_TICKING) {
                o->oAction++; // Set to HIDDEN_BLUE_COIN_ACT_ACTIVE
                o->oOpacity = 255;
            }

            break;
        case HIDDEN_BLUE_COIN_ACT_ACTIVE:
            // Become tangible
            cur_obj_enable_rendering();
            cur_obj_become_tangible();

            // Delete the coin once collected
            if (o->oInteractStatus & INT_STATUS_INTERACTED) {
                spawn_object(o, MODEL_SPARKLES, bhvGoldenCoinSparkles);
                obj_mark_for_deletion(o);
            }

            // After 200 frames of waiting and 20 2-frame blinks (for 240 frames total),
            // delete the object.
            if (cur_obj_wait_then_blink(o->oHiddenBlueCoinSwitch->oF4, o->oHiddenBlueCoinSwitch->oF8)) {
                obj_mark_for_deletion(o);
            }

            break;
    }

    o->oInteractStatus = 0;
}

void bhv_blue_coin_switch_init(void) {
    u8 challenge;
    o->oF4 = (o->oBehParams >> 24) * 30;
    o->oF8 = ((o->oBehParams >> 16) & 0xFF) * 15;
    challenge = (o->oBehParams >> 8) & 0xFF;
    if (save_file_get_challenges(challenge / 32) & (1 << (challenge % 32))) {
        o->activeFlags = 0;
    }
}

/**
 * Update function for bhvBlueCoinSwitch.
 */
void bhv_blue_coin_switch_loop(void) {
    // The switch's model is 1/3 size.
    cur_obj_scale(3.0f);

    switch (o->oAction) {
        case BLUE_COIN_SWITCH_ACT_IDLE:
            // If Mario is on the switch and has ground-pounded,
            // recede and get ready to start ticking.
            if (gMarioObject->platform == o) {
                if (gMarioStates[0].action == ACT_GROUND_POUND_LAND) {
                    // Set to BLUE_COIN_SWITCH_ACT_RECEDING
                    o->oAction++;

                    // Recede at a rate of 20 units/frame.
                    o->oVelY = -20.0f;
                    // Set gravity to 0 so it doesn't accelerate when receding.
                    o->oGravity = 0.0f;

                    cur_obj_play_sound_2(SOUND_GENERAL_SWITCH_DOOR_OPEN);
                }
            }

            // Have collision
            load_object_collision_model();

            break;
        case BLUE_COIN_SWITCH_ACT_RECEDING:
            // Recede for 6 frames before going invisible and ticking.
            // This is probably an off-by-one error, since the switch is 100 units tall
            // and recedes at 20 units/frame, which means it will fully recede after 5 frames.
            if (o->oTimer > 5) {
                cur_obj_hide();

                // Set to BLUE_COIN_SWITCH_ACT_TICKING
                o->oAction++;
                // ???
                o->oPosY = gMarioObject->oPosY - 40.0f;

                // Spawn particles. There's a function that calls this same function
                // with the same arguments, spawn_mist_particles, why didn't they just call that?
                spawn_mist_particles_variable(0, 0, 46.0f);
            } else {
                // Have collision while receding
                load_object_collision_model();
                // Recede
                cur_obj_move_using_fvel_and_gravity();
            }

            break;
        case BLUE_COIN_SWITCH_ACT_TICKING:
            if (CL_obj_find_nearest_object_with_behavior_room(o, bhvHiddenBlueCoin, o->oRoom) == NULL) {
                if (gMarioState->numCoins == gHudDisplay.coins) {
                    gMarioState->numCoins += 25;
                    o->activeFlags = 0;
                    play_puzzle_jingle();
                    save_file_set_challenges((o->oBehParams >> 8) & 0xFF);
                }
            } else {
                // Tick faster when the blue coins start blinking
                if (o->oTimer < o->oF4) {
                    play_sound(SOUND_GENERAL2_SWITCH_TICK_FAST, gGlobalSoundSource);
                } else {
                    play_sound(SOUND_GENERAL2_SWITCH_TICK_SLOW, gGlobalSoundSource);
                }

                // Delete the switch (which stops the sound) after the last coin is collected,
                // or after the coins unload after the 240-frame timer expires.
                if (o->oTimer > o->oF4 + (o->oF8 * 2)) {
                    o->activeFlags = 0;
                    save_file_set_challenges((o->oBehParams >> 8) & 0xFF);
                }
            }
            break;
    }
}



void bhv_blue_coin_switch_auto_init(void) {
    u8 challenge;
    o->oF4 = (o->oBehParams >> 24) * 30;
    o->oF8 = ((o->oBehParams >> 16) & 0xFF) * 15;
    challenge = (o->oBehParams >> 8) & 0xFF;
    if (save_file_get_challenges(challenge / 32) & (1 << (challenge % 32))) {
        o->activeFlags = 0;
        sDelayedWarpOp = 0x10;
        sDelayedWarpTimer = 1;
        sSourceWarpNodeId = 0xAB;
        music_changed_through_warp(sSourceWarpNodeId);
        shade_screen_rgba(0, 0, 0, 255);
    }
}


void bhv_blue_coin_switch_auto_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oAction = 2;
            break;
        case 2:
            if (o->oTimer < o->oF4) {
                play_sound(SOUND_GENERAL2_SWITCH_TICK_FAST, gGlobalSoundSource);
            } else {
                play_sound(SOUND_GENERAL2_SWITCH_TICK_SLOW, gGlobalSoundSource);
            }
            if (cur_obj_nearest_object_with_behavior(bhvHiddenBlueCoin) == NULL || o->oTimer > 0/*o->oF4 + (o->oF8 * 2)*/) {
                o->activeFlags = 0;
                save_file_set_challenges((o->oBehParams >> 8) & 0xFF);
                sDelayedWarpOp = 0x10;
                sDelayedWarpTimer = 12;
                sSourceWarpNodeId = 0xAB;
                music_changed_through_warp(sSourceWarpNodeId);
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 0xC, 0x00, 0x00, 0x00);
                o->oFC = (s32)gMarioState->pos[1];
            }

            if (gMarioState->pos[0] > 650.0f) {
                gMarioState->pos[0] = 650.0f;
            } else if (gMarioState->pos[0] < -650.0f) {
                gMarioState->pos[0] = -650.0f;
            }

            if (gMarioState->pos[2] > 600.0f) {
                gMarioState->pos[2] = 600.0f;
            } else if (gMarioState->pos[2] < -550.0f) {
                gMarioState->pos[2] = -550.0f;
            }
            break;
    }
}