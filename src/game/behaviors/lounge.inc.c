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

Vec3f sBlockGoal = {5000.0f, 0.0f, -7200.0f};

void bhv_dblock_init(void) {
    if (save_file_get_golden_goombas() & (1 << ((o->oBehParams >> 8) & 0xFF))) {
        o->oAction = 1;
        vec3f_copy(&o->oPosX, sBlockGoal);
    }
}

void bhv_dblock_loop(void) {
    s16 pitch, yaw;
    f32 dist;
    switch (o->oAction) {
        case 0:
            bhv_pushable_loop();
            vec3f_get_dist_and_angle(&o->oPosX, sBlockGoal, &dist, &pitch, &yaw);
            if (dist < 200.0f) {
                if (o->oTimer > 20) {
                    if (!(save_file_get_golden_goombas() & (1 << ((o->oBehParams >> 8) & 0xFF)))) {
                        save_file_set_golden_goombas((o->oBehParams >> 8) & 0xFF);
                        play_puzzle_jingle();
                        o->oObjF4 = spawn_object(o, MODEL_GOLDEN_GOOMBA, bhvGoldenGoomba);
                        vec3f_set(&o->oObjF4->oPosX, 6600.0f, 750.0f, -7800.0f);
                    gCamera->comitCutscene = 0xFF;
                    gComitCutsceneTimer = 45;
                    o->oObjF4->os16110 = 3045;
                    vec3f_set(gComitCutscenePosVec, gMarioState->pos[0], gMarioState->pos[1] + 1000.0f, gMarioState->pos[2]);
                    vec3f_copy(gComitCutsceneFocVec, &o->oObjF4->oPosX);
                    }
                    o->oAction = 1;
                }
            } else {
                o->oTimer = 0;
            }
            break;
        case 1:
            break;
    }
}


void bhv_l2_cushion_friend_init(void) {
    if (save_file_get_keys(0) & (1 << 7)) {
        o->activeFlags = 0;
    }
}


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
        if (o->oVelY > 0.0f) {
            o->oVelY = 0.0f;
        }
    } else {
        o->oObjF4 = NULL;
    }
    if (sObjFloor != NULL && (sObjFloor->type == SURFACE_BURNING || sObjFloor->type == SURFACE_INSTANT_QUICKSAND)) {
        o->os16FC = 1;
    }
    if (o->os16FC == 1) {
        o->os16FE++;
        if (o->os16FE > 90) {
            o->os16FE = 0;
            o->oHeldState = 0;
            vec3f_copy(&o->oPosX, &o->oHomeX);
            o->oFaceAngleYaw = 0;
            o->os16FC = 0;
            o->oObjF4 = NULL;
        }
    }
}

void bhv_heavy_object_init(void) {
    struct Object *obj;
    s16 posId = save_file_get_heavy_object() & (3 << (o->oBehParams2ndByte*2));
    posId = posId >> (o->oBehParams2ndByte * 2);
    if (posId) {
        obj = CL_obj_nearest_object_behavior_params(bhvHeavySwitch, (posId - 1) << 16);
        if (obj != NULL) {
            vec3f_copy(&o->oPosX, &obj->oPosX);
            vec3f_copy(&o->oHomeX, &o->oPosX);
        }
    }
    o->oGravity = 2.5;
    o->oFriction = 0.8;
    // o->oBuoyancy = 1.3;
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
            if (o->oPosY == o->oHomeY + 1100.0f) {
                cur_obj_hide();
            }
            if (obj == NULL || obj->oAction != 2) {
                o->oAction = 2;
                cur_obj_unhide();
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
                save_file_set_heavy_object(obj->oBehParams2ndByte, o->oBehParams2ndByte + 1);
                vec3f_copy(&obj->oHomeX, &o->oPosX);

                obj = CL_obj_nearest_object_behavior_params(bhvHeavySwitch, 0);
                if (obj == NULL || obj->oAction == 2) {
                    obj = CL_obj_nearest_object_behavior_params(bhvHeavySwitch, 1 << 16);
                    if (obj == NULL || obj->oAction == 2) {
                        obj = CL_obj_nearest_object_behavior_params(bhvHeavySwitch, 2 << 16);
                        if (obj == NULL || obj->oAction == 2) {
                            if ((save_file_get_keys(0) & (1 << 6)) == 0 && 
                                CL_obj_nearest_object_behavior_params(bhvSmallKey, 6 << 16) == NULL) {
                                obj = spawn_object(o, MODEL_SMALL_KEY, bhvSmallKey);
                                obj->oBehParams2ndByte = 6;
                                obj->oBehParams = 6 << 16;
                                vec3f_set(&obj->oPosX, 3420.0f, -150.0f, -7728.0f);
                            }
                        }
                    }
                }
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
