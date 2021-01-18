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


void bhv_boo_cage_loop(void) {
    obj_set_hitbox(o, &sBooCageHitbox);
    if (o->parentObj->oUnk1A8 > 0) {
        o->activeFlags = 0;
    }
}

void bhv_room_boo_init(void) {
    bhv_boo_init();

    if (save_file_get_boos() & (1 << o->oBehParams2ndByte)) {
        o->activeFlags = 0;
    }
}

//BPARAM 1 = NO KEY, SMALL KEY, OR BIG KEY - BPARAM 3 = KEY ID
void bhv_room_boo_loop(void) {
    s32 numObjs;
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
}