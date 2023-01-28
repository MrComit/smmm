void obj_die_if_health_non_positive(void);

static struct ObjectHitbox sPipesegHitbox = {
    /* interactType:      */ INTERACT_GRABBABLE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 90,
    /* height:            */ 140,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

static struct ObjectHitbox sGushingWaterHitbox = {
    /* interactType:      */ INTERACT_IGLOO_BARRIER,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 30,
    /* height:            */ 800,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};


static struct ObjectHitbox sOctopusHitbox = {
    /* interactType:      */ INTERACT_HIT_FROM_BELOW,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 2,
    /* numLootCoins:      */ 1,
    /* radius:            */ 50,
    /* height:            */ 60,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};



Vec3f sPipeSlots[3] = {
{3616.01f, -2338.67f, -12404.5f},
{4023.04f, -2487.23f, -14483.6f},
{2061.84f, -2840.87f, -15058.9f},
};

Vec3s sPipeRots = {0, 0, 0x4000};
Vec3s sPipeScales = {29, 32, 27};


void bhv_shower_wall_init(void) {
    if (gIsConsole) {
        o->oOpacity = 255;
    } else {
        o->oOpacity = 150;
    }
}


void bhv_shower_wall_loop(void) {
    struct MarioState *m = gMarioState;
    if (m->pos[1] < -100.0f) {
        cur_obj_hide();
        return;
    } else {
        cur_obj_unhide();
    }

    if ((m->pos[1] < 500.0f && m->pos[0] < 3750.0f && m->pos[0] > 2750.0f && m->pos[2] < -14500.0f && m->pos[2] > -15500.0f)
        || !gIsConsole) {
        o->oOpacity = approach_s16_symmetric(o->oOpacity, 150, 6);
        o->os16F4 = approach_s16_symmetric(o->os16F4, 0, 12);
    } else {
        o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 6);
    }
    o->os16F4 = 53 - ((255 - o->oOpacity))/2;
    o->os16F8 = o->os16F6 = o->os16F4;// = o->oOpacity;

}


void bhv_octopus_init(void) {
    obj_set_hitbox(o, &sOctopusHitbox);
}


void bhv_octopus_loop(void) {
    if (gMarioState->pos[1] < -100.0f) {
        cur_obj_hide();
        return;
    } else {
        cur_obj_unhide();
    }
    switch (o->oAction) {
        case 0:
            if (o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
                o->oAction = 1;
            } else 
                o->oInteractStatus = 0;
            break;
        case 1:
            o->oFaceAngleRoll -= 0xC00;
            obj_scale(o, o->header.gfx.scale[0] - 0.03f);
            if (o->header.gfx.scale[0] < 0.25f) {
                o->oHealth = 0;
                obj_die_if_health_non_positive();
            }
            break;
    }
}


void bhv_gushing_water_init(void) {
    obj_set_hitbox(o, &sGushingWaterHitbox);
    o->header.gfx.scale[1] = 0.01f;
    o->oFloatF4 = 0.5f + (o->oF8 * 0.1f);
}


void bhv_gushing_water_loop(void) {
    cur_obj_play_sound_1(SOUND_ENV_WATERFALL1);
    switch (o->oAction) {
        case 0:
            o->header.gfx.scale[1] = approach_f32(o->header.gfx.scale[1], o->oFloatF4, 0.05f, 0.05f);
            if (o->header.gfx.scale[1] == o->oFloatF4) {
                o->oAction = 1;
            }
            break;
        case 1:
            break;
    }
    if (absf(gMarioState->pos[1] - o->oPosY) < 200.0f) {
        cur_obj_become_intangible();
    } else {
        cur_obj_become_tangible();
    }
    o->hitboxHeight = 1000 * o->header.gfx.scale[1];
    o->oFlags &= ~OBJ_FLAG_HOLDABLE;
}



void pipeseg_held_loop(void) {
    cur_obj_become_intangible();
    o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
    o->oObjF4 = NULL;
    o->oAction = 0;
    o->oFC = 0;
    cur_obj_set_pos_relative(gMarioObject, 0, 60.0f, 60.0f);
    if (o->oObjF8 != NULL) {
        o->oObjF8->activeFlags = 0;
        o->oObjF8 = NULL;
    }
}

void pipeseg_dropped_loop(void) {
    cur_obj_get_dropped();
    cur_obj_become_tangible();

    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    //cur_obj_init_animation(0);

    o->oHeldState = 0;
    //o->oAction = 0;
}


void pipeseg_free_loop(void) {
    struct Object *obj;
    s16 i;
    s16 h = 0;
    f32 dist;
    object_step();
    if (sObjFloor != NULL && sObjFloor->object != NULL && absf(o->oPosY - o->oFloorHeight) <= 30.0f) {
        o->oObjF4 = sObjFloor->object;
    } else {
        o->oObjF4 = NULL;
    }

    for (i = 0; i < 3; i++) {
        CL_dist_between_points(&o->oPosX, sPipeSlots[i], &dist);
        if (dist < 150.0f) {
            h = 1;
            break;
        }
    }

    if (h == 0 && sObjFloor != NULL && (sObjFloor->type == SURFACE_BURNING || sObjFloor->type == SURFACE_INSTANT_QUICKSAND)) {
        o->oFC = 1;
    }

    if (o->oFC == 1) {
        if (o->oTimer > 200) {
            o->oTimer = 0;
            o->oHeldState = 0;
            o->oPosX = o->oHomeX;
            o->oPosY = o->oHomeY;
            o->oPosZ = o->oHomeZ;
            o->oFaceAngleYaw = 0;
            o->oFC = 0;
        }
    }

    switch (o->oAction) {
        case 0:
            if (h) {
                vec3f_copy(&o->oPosX, sPipeSlots[i]);
                o->oMoveAngleYaw = sPipeRots[i];
                o->oAction = 1;
                o->oObjF8 = spawn_object(o, MODEL_GUSHING_WATER, bhvGushingWater);
                o->oObjF8->oBehParams2ndByte = i;
                o->oObjF8->oF8 = sPipeScales[i];
                play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gGlobalSoundSource);
            } else {
                o->oFC = 1;
            }
            if (o->oTimer > 75) {
                o->oAction = 1;
            }
            break;
        case 1:
            break;
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
            if (gMarioState->pos[1] > -100.0f) {
                cur_obj_hide();
            } else {
                cur_obj_unhide();
            }
            break;

        case HELD_HELD:
            pipeseg_held_loop();
            break;
        case HELD_THROWN:
        case HELD_DROPPED:
            pipeseg_dropped_loop();
            break;
    }

    if (gMarioState->pos[1] < -100.0f && gMarioState->pos[1] > -600.0f) {
        gCamera->comitCutscene = 2;
    } else {
        gCamera->comitCutscene = 0;
    }
}



void bhv_falling_floor_init(void) {
    if (o->oBehParams2ndByte == 2) {
        o->header.gfx.scale[0] = 2.0f / 3.0f;
        o->header.gfx.scale[2] = 2.0f / 3.0f;
    }
    o->oFloatF4 = 10.0f;
    o->oAnimState = o->oBehParams2ndByte;
}


void bhv_falling_floor_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oFloatF4 = approach_f32(o->oFloatF4, 60.0f, 1.1f, 1.1f);
            o->oPosY -= o->oFloatF4;
            if (o->oPosY < o->oHomeY - 2200.0f) {
                CL_explode_object(o, 1);
                o->oAction = 2;
            }
            break;
    }
}


void bhv_rising_floor_loop(void) {
    struct Object *obj;
    f32 pos;
    switch (o->oAction) {
        case 0:
            obj = CL_nearest_object_with_behavior_and_field(bhvGushingWater, 0x144, o->oBehParams >> 24);
            if (obj != NULL) {
                pos = obj->oPosY + (obj->header.gfx.scale[1] * 1000.0f) + 100.0f;
                if (pos > o->oHomeY) {
                    o->oPosY = pos;
                }
            } else {
                o->oPosY = approach_f32(o->oPosY, o->oHomeY, 50.0f, 50.0f);
            }
            break;
        case 1:
            break;
    }
}