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