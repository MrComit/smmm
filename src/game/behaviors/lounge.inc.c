extern struct Surface *sObjFloor;

static struct ObjectHitbox sHeavyHitbox = {
    /* interactType:      */ INTERACT_GRABBABLE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 65,
    /* height:            */ 113,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};



void heavy_object_held_loop(void) {
    cur_obj_become_intangible();
    o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
    o->oObjF4 = NULL;
    cur_obj_set_pos_relative(gMarioObject, 0, 60.0f, 60.0f);
}

void heavy_object_dropped_loop(void) {
    cur_obj_get_dropped();
    cur_obj_become_tangible();

    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    //cur_obj_init_animation(0);

    o->oHeldState = 0;
    //o->oAction = 0;
}


void heavy_object_free_loop(void) {
    struct Object *obj;
    object_step();
    if (sObjFloor != NULL && sObjFloor->object != NULL && absf(o->oPosY - o->oFloorHeight) <= 30.0f) {
        o->oObjF4 = sObjFloor->object;
    } else {
        o->oObjF4 = NULL;
    }
}

void bhv_heavy_object_init(void) {
    o->oGravity = 2.5;
    o->oFriction = 0.8;
    o->oBuoyancy = 1.3;
    obj_set_hitbox(o, &sHeavyHitbox);
}

void bhv_heavy_object_loop(void) {
    switch (o->oHeldState) {
        case HELD_FREE:
            heavy_object_free_loop();
            break;

        case HELD_HELD:
            heavy_object_held_loop();
            break;
        case HELD_THROWN:
        case HELD_DROPPED:
            heavy_object_dropped_loop();
            break;
    }
}



void bhv_heavy_gate_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            obj = CL_obj_nearest_object_behavior_params(bhvHeavySwitch, o->oBehParams2ndByte << 16);
            if (obj != NULL && obj->oAction == 2) {
                o->oAction = 1;
            }
            break;
        case 1:
            obj = CL_obj_nearest_object_behavior_params(bhvHeavySwitch, o->oBehParams2ndByte << 16);
            o->oPosY = approach_f32(o->oPosY, o->oHomeY + 1100.0f, 75.0f, 75.0f);
            if (obj == NULL || obj->oAction != 2) {
                o->oAction = 2;
            }
            break;
        case 2:
            o->oPosY = approach_f32(o->oPosY, o->oHomeY, 75.0f, 75.0f);
            if (o->oPosY == o->oHomeY)
                o->oAction = 0;
            break;
    }
}


void bhv_heavy_switch_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            obj = cur_obj_nearest_object_with_behavior(bhvHeavyObject);
            if (obj == NULL)
                break;
            if (obj->oObjF4 == o) {
                o->oAction = 1;
            }
            break;
        case 1:
            cur_obj_scale_over_time(2, 3, 1.5f, 0.2f);
            if (o->oTimer == 3) {
                cur_obj_play_sound_2(SOUND_GENERAL2_PURPLE_SWITCH);
                o->oAction = 2;
                cur_obj_shake_screen(SHAKE_POS_SMALL);
                queue_rumble_data(5, 80);
            }
            break;
        case 2:
            obj = cur_obj_nearest_object_with_behavior(bhvHeavyObject);
            if (obj == NULL) {
                o->oAction = 3;
                break;
            }
            if (obj->oObjF4 != o) {
                o->oAction = 3;
            }
            break;
        case 3:
            cur_obj_scale_over_time(2, 3, 0.2f, 1.5f);
            if (o->oTimer == 3) {
                o->oAction = 0;
            }
            break;
    }
}
