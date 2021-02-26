static struct ObjectHitbox sPipesegHitbox = {
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


Vec3f sPipeSlots[3] = {
{3616.01f, -2210.11f, -10404.5f},
{4023.04f, -2487.23f, -12483.6f},
{2061.84f, -2487.23f, -13058.9f},
};



void pipeseg_held_loop(void) {
    cur_obj_become_intangible();
    o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
    o->oObjF4 = NULL;
    cur_obj_set_pos_relative(gMarioObject, 0, 60.0f, 60.0f);
}

void pipeseg_dropped_loop(void) {
    s16 i;
    s16 h = 0;
    f32 dist;
    cur_obj_get_dropped();
    cur_obj_become_tangible();

    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    //cur_obj_init_animation(0);

    o->oHeldState = 0;
    for (i = 0; i < 3; i++) {
        CL_dist_between_points(&o->oPosX, sPipeSlots[i], &dist);
        if (dist < 50.0f) {
            h = 1;
            break;
        }
    }
    if (h) {
        vec3f_copy(&o->oPosX, sPipeSlots[i]);
    }
    //o->oAction = 0;
}


void pipeseg_free_loop(void) {
    struct Object *obj;
    object_step();
    if (sObjFloor != NULL && sObjFloor->object != NULL && absf(o->oPosY - o->oFloorHeight) <= 30.0f) {
        o->oObjF4 = sObjFloor->object;
    } else {
        o->oObjF4 = NULL;
    }
}



void bhv_pipeseg_init(void) {
    o->oGravity = 2.5;
    o->oFriction = 0.8;
    o->oBuoyancy = 1.3;
    obj_set_hitbox(o, &sPipesegHitbox);
}


void bhv_pipeseg_loop(void) {
    switch (o->oHeldState) {
        case HELD_FREE:
            pipeseg_free_loop();
            break;

        case HELD_HELD:
            pipeseg_held_loop();
            break;
        case HELD_THROWN:
        case HELD_DROPPED:
            pipeseg_dropped_loop();
            break;
    }
}



void bhv_falling_floor_init(void) {
    o->oFloatF4 = 10.0f;
}


void bhv_falling_floor_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oFloatF4 = approach_f32(o->oFloatF4, 30.0f, 1.1f, 1.1f);
            o->oPosY -= o->oFloatF4;
            if (o->oPosY < o->oHomeY - 800.0f) {
                CL_explode_object(o, 1);
                o->oAction = 2;
            }
            break;
    }
}