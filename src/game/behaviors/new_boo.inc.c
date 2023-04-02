static struct ObjectHitbox sBooCageHitbox = {
    /* interactType: */ INTERACT_IGLOO_BARRIER,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 0,
    /* numLootCoins: */ 0,
    /* radius: */ 120,
    /* height: */ 300,
    /* hurtboxRadius: */ 0,
    /* hurtboxHeight: */ 0,
};

/*struct Object *CL_obj_nearest_object_behavior_params(const BehaviorScript *behavior, u32 params) {
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct Object *closestObj = NULL;
    struct Object *obj;
    struct ObjectNode *listHead;
    f32 minDist = 0x20000;

    listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    obj = (struct Object *) listHead->next;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr && obj->oBehParams == params) {
            if (obj->activeFlags != ACTIVE_FLAG_DEACTIVATED && obj != o) {
                f32 objDist = dist_between_objects(o, obj);
                if (objDist < minDist) {
                    closestObj = obj;
                    minDist = objDist;
                }
            }
        }
        obj = (struct Object *) obj->header.next;
    }

    return closestObj;
}*/


s32 count_room_objects_with_flag(u32 flag, s16 room) {
    s32 i;
    s32 count = 0;
    struct ObjectNode *listHead, *obj;

    for (i = 0; i < NUM_OBJ_LISTS; i++) {
        listHead = &gObjectLists[i];
        obj = listHead->next;
        while (listHead != obj) {
            if (((struct Object *) obj)->oFlags & flag && ((struct Object *) obj)->oRoom == room) {
                count++;
            }
            obj = obj->next;
        }
    }
    return count;
}

void room_boo_multiplier_loop(void) {
    if (gMarioCurrentRoom == o->oRoom) {
        gHudDisplay.flags |= (HUD_DISPLAY_FLAG_BOO | HUD_DISPLAY_FLAG_MULTIPLIER);
    }

    if (o->activeFlags == 0) {
        gMarioState->numCoins += gMarioState->numBooCoins * (gMultiplierUpper + ((f32)gMultiplierLower / 10));
        gHudDisplay.flags &= ~(HUD_DISPLAY_FLAG_BOO | HUD_DISPLAY_FLAG_MULTIPLIER);
        gMarioState->numBooCoins = 0;
        gHudDisplay.booCoins = 0;
    }

}


void bhv_boo_cage_loop(void) {
    if (o->parentObj->oUnk1A8 > 0) {
        o->activeFlags = 0;
    }
}

void bhv_boo_cage_init(void) {
    obj_set_hitbox(o, &sBooCageHitbox);
}

void bhv_room_boo_init(void) {
    bhv_boo_init();
    //o->activeFlags = 0;
    // o->oFloatF4 = 5.0f;
    if (save_file_get_newflags(1) & SAVE_TOAD_FLAG_MULTI_3) {
        gMultiplierUpper = 8;
    } else {
        gMultiplierUpper = 5;
    }
    gMultiplierLower = 0;
    gMarioState->numBooCoins = 0;
    if (save_file_get_boos() & (1 << o->oBehParams2ndByte)) {
        o->activeFlags = 0;
    }
}

s8 sBooBits[] = {0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,}; // ends at 0x18

//BPARAM 1 = NO KEY, SMALL KEY, OR BIG KEY
//BPARAM 2 = BOO ID
//BPARAM 3 = KEY ID/STAR ID
void bhv_room_boo_loop(void) {
    s32 numObjs;
    if (gMarioCurrentRoom != o->oRoom)
        return;
    if (gCamera->comit2dcam == 1) {
        o->oPosZ = 0;
    }
    if (o->oUnk1A8 == 0) {
        numObjs = count_room_objects_with_flag(OBJ_FLAG_DISABLE_TO_ROOM_CLEAR, o->oRoom);
        if (numObjs <= 15) {
            o->oOpacity = 255 - (17 * numObjs);
        }
        if (numObjs <= 2) {
            o->oUnk1A8 = 1;
        }
    } else if (o->oUnk1A8 == 1) {
        o->oUnk1A8 = 2;
        o->oOpacity = 255;
        if (o->oBehParams2ndByte)
            play_puzzle_jingle();
    } else {
        bhv_boo_loop();
    }

    if (sBooBits[o->oBehParams2ndByte]) {
        room_boo_multiplier_loop();
    }
}







void bhv_boogoo_cage_init(void) {
    bhv_room_boo_init();
    o->header.gfx.scale[1] = 1.4f;
    obj_set_hitbox(o, &sBooCageHitbox);
    o->oObjFC = spawn_object(o, MODEL_CAGE_GOO, bhvCageGoo);
    o->oObjFC->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
    o->oObjFC->header.gfx.scale[1] = 1.0f;
}


void bhv_boogoo_cage_loop(void) {
    s32 numObjs;
    if (gMarioCurrentRoom != o->oRoom)
        return;
    // if (gCamera->comit2dcam == 1) {
    //     o->oPosZ = 0;
    // }

    switch (o->oUnk1A8) {
        case 0:
            numObjs = count_room_objects_with_flag(OBJ_FLAG_DISABLE_TO_ROOM_CLEAR, o->oRoom);
            if (numObjs <= 15) {
                o->oObjFC->header.gfx.scale[1] = 1.0f - (numObjs * 0.067f);
                // o->oOpacity = 255 - (17 * numObjs);
            }
            if (numObjs <= 2) {
                o->oUnk1A8 = 1;
            }
            break;
        case 1:
            o->oUnk1A8 = 2;
            // o->oOpacity = 255;
            o->oObjFC->header.gfx.scale[1] = 1.0f;
            play_puzzle_jingle();
            break;
        case 2:
            o->header.gfx.scale[0] += 0.1f;
            o->header.gfx.scale[1] += 0.1f;
            o->header.gfx.scale[2] += 0.1f;
            o->oObjFC->header.gfx.scale[0] += 0.1f;
            o->oObjFC->header.gfx.scale[1] += 0.1f;
            o->oObjFC->header.gfx.scale[2] += 0.1f;
            if (o->header.gfx.scale[0] > 3.0f) {
                CL_explode_object(o, 1);
                CL_explode_object(o->oObjFC, 1);
            }
            break;
    }

    if (sBooBits[o->oBehParams2ndByte]) {
        room_boo_multiplier_loop();
    }
}