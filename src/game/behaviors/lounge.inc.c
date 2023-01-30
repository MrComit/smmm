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

extern s16 gComitCutsceneTimer;
extern Vec3f gComitCutscenePosVec;
extern Vec3f gComitCutsceneFocVec;


Vec3f sShyguyPos[3] = {
{0.0f, 20.0f, -16750.0f},
{-1175.0f, 20.0f, -18200.0f},
{-850.0f, 20.0f, -17100.0f},
};


void bhv_shyguy_key_cutscene_init(void) {
    o->oObjF4 = cur_obj_nearest_object_with_behavior(bhvKeyCutscene);
    if (o->oObjF4 == NULL) {
        o->activeFlags = 0;
        return;
    }
    // o->oOpacity = 180;
    vec3f_copy(&o->oPosX, sShyguyPos[o->oBehParams2ndByte]);
    o->oFaceAnglePitch = o->oFaceAngleRoll = 0;
    o->oMoveAngleYaw = o->oFaceAngleYaw = obj_angle_to_object(o, o->oObjF4);
    o->oForwardVel = 15.0f;
}

void bhv_shyguy_key_cutscene_loop(void) {
    f32 dist;
    s16 pitch, yaw;
    switch (o->oAction) {
        case 0:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 180, 6);
            o->os16100 += 0x400;
            o->oGraphYOffset = 20.0f + (coss(o->os16100) * 20.0f);
            CL_Move();
            vec3f_get_dist_and_angle(&o->oPosX, &o->oObjF4->oPosX, &dist, &pitch, &yaw);
            if (dist < 80.0f) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->os16F8 += 0x5D1;
            o->oFaceAnglePitch = 0x888 + (sins(o->os16F8 - 0x4000) * 0x888);
            if (o->oTimer > 22) {
                if (o->oBehParams2ndByte) {
                    o->oObjF4->oAction = 2;
                }
                o->oObjFC = spawn_object(o, MODEL_BROKEN_KEY, bhvStaticObject);
                obj_scale(o->oObjFC, 0.3f);
                o->oObjFC->oAnimState = o->oBehParams2ndByte;
                o->oAction = 2;
                o->os16FA = o->oFaceAngleYaw;
            }
            break;
        case 2:
            o->os16100 += 0x400;
            o->oGraphYOffset = 20.0f + (coss(o->os16100) * 20.0f);
            o->oObjFC->oPosX = o->oPosX + (sins(o->oFaceAngleYaw) * 50.0f);
            o->oObjFC->oPosZ = o->oPosZ + (coss(o->oFaceAngleYaw) * 50.0f);
            o->oObjFC->oPosY = o->oPosY + o->oGraphYOffset;
            o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, (s16)(o->os16FA + 0x8000), 0x400);
            o->oMoveAngleYaw = o->oFaceAngleYaw;
            if (o->oFaceAngleYaw == (s16)(o->os16FA + 0x8000)) {
                if (o->oBehParams2ndByte) {
                    o->oObjF4->oAction = 4;
                }
                o->oAction = 3;
                o->oForwardVel = 0.0f;
            }
            break;
        case 3:
            CL_Move();
            o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 40.0f, 1.0f);
            o->os16100 += 0x400;
            o->oGraphYOffset = 20.0f + (coss(o->os16100) * 20.0f);
            o->oObjFC->oPosX = o->oPosX + (sins(o->oFaceAngleYaw) * 50.0f);
            o->oObjFC->oPosZ = o->oPosZ + (coss(o->oFaceAngleYaw) * 50.0f);
            o->oObjFC->oPosY = o->oPosY + o->oGraphYOffset;
            vec3f_get_dist_and_angle(&o->oPosX, &o->oObjF4->oPosX, &dist, &pitch, &yaw);
            if (dist > 3000.0f) {
                if (o->oBehParams2ndByte) {
                    o->oObjF4->oAction = 5;
                }
                o->oObjFC->activeFlags = 0;
                o->activeFlags = 0;
            }
            break;
    }
    // switch (o->oBehParams2ndByte) {
    //     case 0:
    //         break;
    //     case 1:
    //         break;
    //     case 2:
    //         break;
    // }
}



void bhv_key_cutscene_init(void) {
#ifndef SMMM_DEBUG
    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_KEY_CUTSCENE) {
#endif
        o->activeFlags = 0;
#ifndef SMMM_DEBUG
    }
#endif
    o->oAnimState = o->oBehParams2ndByte;
}

void bhv_key_cutscene_loop(void) {
    struct Object *obj;
    // struct Object *obj1;
    // struct Object *obj3;
    switch (o->oAction) {
        case 0:
            if (gMarioState->pos[0] < 850.0f) {
                o->oAction = 1;
                vec3f_set(gComitCutscenePosVec, 850.0f, 500.0f, -18100.0f);
                vec3f_copy(gComitCutsceneFocVec, &o->oPosX);

                obj = spawn_object(o, MODEL_SHYGUY, bhvShyguyKeyCutscene);
                obj->oBehParams2ndByte = 0;
                obj = spawn_object(o, MODEL_SHYGUY, bhvShyguyKeyCutscene);
                obj->oBehParams2ndByte = 1;
                obj = spawn_object(o, MODEL_SHYGUY, bhvShyguyKeyCutscene);
                obj->oBehParams2ndByte = 2;
            }
            break;
        case 1:
            set_mario_npc_dialog(1);
            gMarioObject->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
            gCamera->comitCutscene = 0xFF;
            break;
        case 2:
            gMarioObject->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
            gCamera->comitCutscene = 0xFF;
            spawn_mist_particles_variable(0, 0, 46.0f);
            spawn_triangle_break_particles(30, MODEL_DIRT_ANIMATION, 3.0f, 4);
            create_sound_spawner(SOUND_GENERAL_BREAK_BOX);
            cur_obj_play_sound_1(SOUND_OBJ_BOO_LAUGH_LONG);
            cur_obj_hide();
            o->oAction = 3;

            // obj = spawn_object(o, MODEL_BROKEN_KEY, bhvStaticObject);
            // obj->oBehParams2ndByte = 0;
            // obj = spawn_object(o, MODEL_BROKEN_KEY, bhvStaticObject);
            // obj->oBehParams2ndByte = 1;
            // obj = spawn_object(o, MODEL_BROKEN_KEY, bhvStaticObject);
            // obj->oBehParams2ndByte = 2;
            break;
        case 3:
            gMarioObject->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
            gCamera->comitCutscene = 0xFF;
            break;
        case 4:
            gMarioObject->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
            gCamera->comitCutscene = 0xFF;
            gComitCutsceneFocVec[2] = approach_f32_symmetric(gComitCutsceneFocVec[2], o->oPosZ + 1000.0f, 20.0f);
            gComitCutscenePosVec[0] = approach_f32_symmetric(gComitCutscenePosVec[0], 450.0f, 8.5f);
            gComitCutscenePosVec[1] = approach_f32_symmetric(gComitCutscenePosVec[1], 200.0f, 6.0f);
            break;
        case 5:
            gMarioObject->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
            gCamera->comitCutscene = 0xFF;
            gComitCutsceneTimer = 15.0f;
            o->oAction = 6;
            play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 10, 0x00, 0x00, 0x00);
            break;
        case 6:
            gMarioObject->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
            if (o->oTimer > 15) {
                play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 8, 0x00, 0x00, 0x00);
                set_mario_npc_dialog(0);
                gMarioObject->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
                o->activeFlags = 0;
                save_file_set_newflags(SAVE_NEW_FLAG_KEY_CUTSCENE, 0);
            }
            break;
    }
}


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
