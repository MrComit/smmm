
/**
 * This file contains the initialization and behavior for red coins.
 * Behavior controls audio and the orange number spawned, as well as interacting with
 * the course's red coin star.
 */

/**
 * Red coin's hitbox details.
 */
static struct ObjectHitbox sRedCoinHitbox = {
    /* interactType:      */ INTERACT_COIN,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
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

/**
 * Red coin initialization function. Sets the coin's hitbox and parent object.
 */
void bhv_red_coin_init(void) {
    // This floor and floor height are unused. Perhaps for orange number spawns originally?
    struct Surface *dummyFloor;
    UNUSED f32 floorHeight = find_floor(o->oPosX, o->oPosY, o->oPosZ, &dummyFloor);

    // Set the red coins to have a parent of the closest red coin star.
    struct Object *hiddenRedCoinStar;

    if ((hiddenRedCoinStar =
             cur_obj_nearest_object_with_behavior(bhvHiddenRedCoinStar)) != NULL) {
        o->parentObj = hiddenRedCoinStar;
    } else if ((hiddenRedCoinStar =
             cur_obj_nearest_object_with_behavior(bhvBowserCourseRedCoinStar)) != NULL) {
        o->parentObj = hiddenRedCoinStar;
    } else {
        o->parentObj = NULL;
    }

    obj_set_hitbox(o, &sRedCoinHitbox);
}

/**
 * Main behavior for red coins. Primarily controls coin collection noise and spawning
 * the orange number counter.
 */
void bhv_red_coin_loop(void) {
    // If Mario interacted with the object...
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        // ...and there is a red coin star in the level...
        if (o->parentObj != NULL) {
            // ...increment the star's counter.
            o->parentObj->oHiddenStarTriggerCounter++;

            // For JP version, play an identical sound for all coins.
#ifdef VERSION_JP
            create_sound_spawner(SOUND_GENERAL_RED_COIN);
#endif
            // Spawn the orange number counter, as long as it isn't the last coin.
            if (o->parentObj->oHiddenStarTriggerCounter != 8) {
                spawn_orange_number(o->parentObj->oHiddenStarTriggerCounter, 0, 0, 0);
            }

            // On all versions but the JP version, each coin collected plays a higher noise.
#ifndef VERSION_JP
            play_sound(SOUND_MENU_COLLECT_RED_COIN
                       + (((u8) o->parentObj->oHiddenStarTriggerCounter - 1) << 16),
                       gGlobalSoundSource);
#endif
        }

        coin_collected();
        // Despawn the coin.
        o->oInteractStatus = 0;
    }
}


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
            o->parentObj->oHiddenStarTriggerCounter++;
            gGreenCoinsCollected++;
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
                o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
            }
            break;
    }
}