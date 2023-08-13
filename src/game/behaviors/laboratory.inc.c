extern s32 gJoystickSwitch;
static struct ObjectHitbox sSuncubeHitbox = {
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



Vec3f sSuncubeSpots[2] = {
    {18293.0f, 7311.0f, -12995.0f},
    {18293.0f, 7311.0f, -10420.0f},
};


void suncube_held_loop(void) {
    cur_obj_become_intangible();
    o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
    o->oFC = 0;
    cur_obj_set_pos_relative(gMarioObject, 0, 60.0f, 60.0f);

    // o->os16F4 = approach_s16_symmetric(o->os16F4, 0xFF, 0x10);
    // o->os16F6 = approach_s16_symmetric(o->os16F6, 0xBD, 0x10);
    // o->os16FA = o->header.gfx.animInfo.animFrame;
}

void suncube_dropped_loop(void) {
    cur_obj_get_dropped();
    cur_obj_become_tangible();

    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    //cur_obj_init_animation(0);

    //o->oFC = 1;
    o->oHeldState = 0;
    //o->oAction = 0;
}


void suncube_free_loop(void) {
    struct Object *obj;
    object_step();
    o->header.gfx.animInfo.animFrame = o->os16FA;
    o->os16F4 = approach_s16_symmetric(o->os16F4, 0x99, 0x10);
    o->os16F6 = approach_s16_symmetric(o->os16F6, 0x71, 0x10);

    if (sObjFloor != NULL && (sObjFloor->type == SURFACE_BURNING || sObjFloor->type == SURFACE_INSTANT_QUICKSAND)) {
        o->os16FC = 1;
    } 

    if (sObjFloor != NULL && sObjFloor->type == SURFACE_SUNCUBE_FLOOR) {
        o->oAction = 1;
        o->oFlags &= ~OBJ_FLAG_DISABLE_TO_ROOM_CLEAR;
        o->oInteractType = INTERACT_IGLOO_BARRIER;
        vec3f_copy(&o->oPosX, sSuncubeSpots[sObjFloor->force]);
        o->oFaceAngleYaw = o->oMoveAngleYaw = 0;
        o->oFloat10C = 1.0f;
        play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gGlobalSoundSource);
        obj = cur_obj_nearest_object_with_behavior(bhvSuncube);
        if (obj == NULL || obj->oAction == 1) {
            obj = CL_nearest_object_with_behavior_and_field(bhvAntennaBall, 0x144, 1);
            if (obj != NULL) {
                obj->os16110 = 1;
            }
        }
    }
    
    if (o->oPosY > 0.0f && gMarioState->pos[1] < -150.0f) {
        if (++o->os16110 > 45) {
            o->os16FC = 1;
        }
    } else {
        o->os16110 = 0;
    }

    if (o->os16FC == 1) {
        o->os16FE++;
        if (o->os16FE > 10) {
            o->header.gfx.scale[0] -= 0.05f;
            o->header.gfx.scale[1] = o->header.gfx.scale[2] = o->header.gfx.scale[0];
        }
        if (o->os16FE > 30) {
            o->os16FE = 0;
            o->oHeldState = 0;
            vec3f_copy(&o->oPosX, &o->oHomeX);
            o->oFaceAngleYaw = o->oMoveAngleYaw = 0;
            o->os16FC = 0;
            o->header.gfx.scale[1] = o->header.gfx.scale[2] = o->header.gfx.scale[0] = 1.0f;
        }
    }
}



void bhv_suncube_init(void) {
    struct Object *obj;
    o->oGravity = 2.5;
    o->oFriction = 0.8;
    o->oBuoyancy = 1.3;
    o->os16F4 = 0x99;
    o->os16F6 = 0x71;
    o->os16F8 = 0;
    o->os16FA = 0;
    obj_set_hitbox(o, &sSuncubeHitbox);

    if (save_file_get_boos() & (1 << 22)) {
        o->oAction = 1;
        o->oFlags &= ~OBJ_FLAG_DISABLE_TO_ROOM_CLEAR;
        o->oInteractType = INTERACT_IGLOO_BARRIER;
        vec3f_copy(&o->oPosX, sSuncubeSpots[o->oBehParams2ndByte]);
        o->oFaceAngleYaw = o->oMoveAngleYaw = 0;
        o->oFloat10C = 1.0f;
        obj = cur_obj_nearest_object_with_behavior(bhvSuncube);
        if (obj == NULL || obj->oAction == 1) {
            obj = CL_nearest_object_with_behavior_and_field(bhvAntennaBall, 0x144, 1);
            if (obj != NULL) {
                obj->os16110 = 1;
            }
        }
    }
}



void bhv_suncube_loop(void) {
    if (o->oAction) {
        o->oFloat10C = approach_f32_symmetric(o->oFloat10C, 2.0f, 0.05f);
        cur_obj_scale(o->oFloat10C);
    } else {
        switch (o->oHeldState) {
            case HELD_FREE:
                suncube_free_loop();
                break;

            case HELD_HELD:
                suncube_held_loop();
                break;
            case HELD_THROWN:
            case HELD_DROPPED:
                suncube_dropped_loop();
                break;
        }
    }
}



void bhv_antenna_ball_init(void) {
    o->os16F4 = 0x30;
    o->os16F6 = 0x30;
    o->os16F8 = 0x48;
}


void bhv_antenna_ball_loop(void) {
    struct Object *obj;
    struct MarioState *m = gMarioState;
    if (gMarioCurrentRoom != o->oRoom) {
        return;
    }
    if (o->oBehParams2ndByte) {
        obj = o;
    } else {
        obj = CL_nearest_object_with_behavior_and_field(bhvAntennaBall, 0x144, 1);
        if (obj == NULL) {
            o->activeFlags = 0;
            return;
        }
    }
    switch (o->oAction) {
        case 0:
            if (m->pos[0] > 11000.0f && m->pos[0] < 17650.0f && m->heldObj == NULL && m->floor->type != SURFACE_INSTANT_QUICKSAND) {
                o->oAction = 1;
                if (o->oBehParams2ndByte) {
                    // cur_obj_play_sound_1(SOUND_OBJ2_BOWSER_TELEPORT);
                    play_sound(SOUND_OBJ2_BOWSER_TELEPORT, gMarioState->marioObj->header.gfx.cameraToObject);

                    // gJoystickSwitch = CL_RandomMinMaxU16(0x1800, 0xE800);
                    gJoystickSwitch = 0x8000;
                    // m->particleFlags |= PARTICLE_DIZZY;
                    set_mario_action(m, ACT_CUTSCENE_DIZZY, 0);
                    // set_mario_animation(m, MARIO_ANIM_DYING_FALL_OVER);
                }
            }
            if (obj != NULL && obj->os16110) {
                o->oAction = 2;
                if (o->oBehParams2ndByte) {
                    gJoystickSwitch = 0;
                    // m->particleFlags &= ~PARTICLE_DIZZY;
                }
            }
            o->os16F4 = approach_s16_symmetric(o->os16F4, 0x30, 0x6);
            o->os16F6 = approach_s16_symmetric(o->os16F6, 0x30, 0x6);
            o->os16F8 = approach_s16_symmetric(o->os16F8, 0x48, 0x7);
            o->oFloatFC = approach_f32_symmetric(o->oFloatFC, 1.0f, 0.025f);
            break;
        case 1:
            if (m->pos[0] < 10500.0f || m->pos[0] > 18000.0f || m->heldObj != NULL) {
                o->oAction = 0;
                if (o->oBehParams2ndByte) {
                    gJoystickSwitch = 0;
                    // m->particleFlags &= ~PARTICLE_DIZZY;
                }
            }
            if (obj != NULL && obj->os16110) {
                o->oAction = 2;
                if (o->oBehParams2ndByte) {
                    gJoystickSwitch = 0;
                    // m->particleFlags &= ~PARTICLE_DIZZY;
                }
            }
            // set_mario_animation(m, MARIO_ANIM_DYING_FALL_OVER);
            o->os16F4 = approach_s16_symmetric(o->os16F4, 0x0, 0x6);
            o->os16F6 = approach_s16_symmetric(o->os16F6, 0xB0, 0x6);
            o->os16F8 = approach_s16_symmetric(o->os16F8, 0xFF, 0x7);
            o->oFloatFC = approach_f32_symmetric(o->oFloatFC, 1.5f, 0.025f);
            break;
        case 2:
            o->os16F4 = approach_s16_symmetric(o->os16F4, 0x0, 0x3);
            o->os16F6 = approach_s16_symmetric(o->os16F6, 0x0, 0x3);
            o->os16F8 = approach_s16_symmetric(o->os16F8, 0x0, 0x4);
            o->oFloatFC = approach_f32_symmetric(o->oFloatFC, 0.5f, 0.01f);
            break;
    }
    cur_obj_scale(o->oFloatFC);
}