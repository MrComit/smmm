#include "levels/ssl/l8_locked_cage/geo_header.h"
#include "levels/castle_grounds/header.h"
void obj_set_dist_from_home(f32 distFromHome);

static struct ObjectHitbox sLightningHitbox = {
    /* interactType:      */ INTERACT_SHOCK,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 290,
    /* height:            */ 2100,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};


Vec3f sBalconyRespawn = {2796.0f, 2283.0f, 13634.0f};


void bhv_locked_cage_init(void) {
    if (save_file_get_keys(1) & (1 << o->oBehParams2ndByte)) {
        o->activeFlags = 0;
    }

    if (gCurrLevelNum == LEVEL_SSL) {
        o->collisionData = segmented_to_virtual(&l8_locked_cage_collision);
    }
}


void bhv_locked_cage_loop(void) {
    if (o->oDistanceToMario < 500.0f) {
        if (save_file_get_keys(0) & (1 << o->oBehParams2ndByte)) {
            CL_explode_object(o, 1);
            play_puzzle_jingle();
            save_file_set_keys(o->oBehParams2ndByte, 1);
        }
    }
}




s32 clamp_pole_f32(f32 *value, f32 minimum, f32 maximum) {
    if (*value <= minimum) {
        *value = minimum;
    } else if (*value >= maximum) {
        *value = maximum;
    } else {
        return FALSE;
    }

    return TRUE;
}


void bhv_moving_vine_init(void) {
    //o->hitboxDownOffset = 100.0f;
    o->oFloatF8 = 100.0f * o->oBehParams2ndByte;
    o->header.gfx.scale[1] = 1.3f + (0.1f * (o->oBehParams >> 24));
}

void bhv_moving_vine_loop(void) {
    if (o->oTimer > 20) {
        o->oFloatFC += o->oFloatF4;

        if (clamp_pole_f32(&o->oFloatFC, 0.0f, o->oFloatF8)) {
            o->oFloatF4 = -o->oFloatF4;
            o->oTimer = 0;
        }
    }
    obj_set_dist_from_home(o->oFloatFC);
}

static void const *sBalconyElevatorCols[] = {
    balcony_elevator_collision,
    cg_elevator_collision,
};


void bhv_balcony_elevator_init(void) {
    o->collisionData = segmented_to_virtual(sBalconyElevatorCols[o->oBehParams2ndByte]);


    if (o->oBehParams2ndByte == 1 && (save_file_get_newflags(1) & SAVE_TOAD_FLAG_BALCONY_ELEVATOR) == 0) {
        o->activeFlags = 0;
        return;
    }
    if (o->oBehParams2ndByte == 0) {
        o->oObjF8 = spawn_object(o, MODEL_LIGHTNING_SPINNER, bhvLightningSpinner);
    } else {
        o->oObjF8 = spawn_object(o, MODEL_CG_SPINNER, bhvCGSpinner);
    }
    obj_scale(o->oObjF8, 0.8f);
    o->oObjF8->oRoom = o->oRoom;
    o->oObjF8->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
}


void bhv_balcony_elevator_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o) {
                if (o->oTimer > 5) {
                    o->oAction = 1;
                    if ((save_file_get_newflags(1) & SAVE_TOAD_FLAG_BALCONY_ELEVATOR) == 0) {
                        save_file_set_newflags(SAVE_TOAD_FLAG_BALCONY_ELEVATOR, 1);
                    }
                    if (o->oBehParams2ndByte == 0) {
                        o->oFloatF4 = -20000.0f;
                    } else {
                        o->oFloatF4 = 20000.0f;
                    }
                }
            } else {
                o->oTimer = 0;
            }
            break;
        case 1:
            cur_obj_play_sound_1(SOUND_ENV_ELEVATOR1);
            set_mario_npc_dialog(1);
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oFloatF4, 20.0f);
            if (o->oTimer == 40) {
                sDelayedWarpArg = 0;
                sDelayedWarpOp = 0x10;
                sSourceWarpNodeId = 0xBA;
                // val04 = !music_changed_through_warp(sSourceWarpNodeId);
                sDelayedWarpTimer = 20;
                play_transition(WARP_TRANSITION_FADE_INTO_CIRCLE, 0x14, 0x00, 0x00, 0x00);
            }
            break;
    }
    if (o->oObjF8 != NULL) {
        o->oObjF8->oPosY = o->oPosY + 60.0f;
    }
}



void bhv_floating_plant_init(void) {
    struct Object *obj;
    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_FLOATING_PLANT) {
        o->oObjF4 = spawn_object(o, MODEL_LIGHTNING_SPINNER, bhvLightningSpinner);
        o->oObjF4->oRoom = o->oRoom;
        o->oObjF4->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
        if (!(save_file_get_newflags(1) & SAVE_TOAD_FLAG_PLANT_CUTSCENE)) {
            o->oPosY -= 6400.0f;
        } else {
            o->oAction = 1;
        }
    } else {
        cur_obj_disable();
        o->oAction = 2;
    }
}


void bhv_floating_plant_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oTimer > 30 && gMarioState->pos[1] <= gMarioState->floorHeight) {
                cur_obj_unhide();
                set_mario_npc_dialog(1);
                gCamera->comitCutscene = 34;
                gComitCutsceneTimer = 30;
                gComitCutsceneObject = o;

                o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 60.0f);
                o->oObjF4->oPosY = o->oPosY;
                if (o->oPosY >= o->oHomeY) {
                    o->oAction = 1;
                    save_file_set_newflags(SAVE_TOAD_FLAG_PLANT_CUTSCENE, 1);
                    play_puzzle_jingle();
                    set_mario_npc_dialog(0);
                }
            } else {
                cur_obj_hide();
            }
            break;
        case 1:
            load_object_collision_model();
            break;
        case 2:
            break;
    }
}


void bhv_lightning_init(void) {
    o->oOpacity = 0;
    obj_set_hitbox(o, &sLightningHitbox);
    if (o->oBehParams2ndByte) {
        o->oAction = 3;
    }

    if (o->oBehParams >> 24) {
        cur_obj_become_intangible();
        o->oAction = 4;
    }
}

extern s16 s8DirModeBaseYaw;

void bhv_lightning_spinner_loop(void) {
    if (o->oDistanceToMario < o->oDrawingDistance || !gIsConsole) {
        o->header.gfx.node.flags |= GRAPH_RENDER_ACTIVE;
    } else {
        o->header.gfx.node.flags &= ~GRAPH_RENDER_ACTIVE;
    }
}


void bhv_lightning_loop(void) {
    struct MarioState *m = gMarioState;
    o->oInteractStatus = 0;
    if (o->oTimer < 2 && count_room_objects_with_behavior(bhvBooCoinCage, o->oRoom) == 0 && gCurrLevelNum != LEVEL_TTM) {
        o->oAction = 4;
        o->oOpacity = 0;
        cur_obj_disable();
    }
    switch (o->oAction) {
        case 0:
            cur_obj_become_intangible();
            if (o->oTimer > 22) {
                o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 9);
                if (o->oOpacity == 255) {
                    o->oAction = 1;
                    cur_obj_shake_screen(0);
                    cur_obj_play_sound_1(SOUND_GENERAL_GRINDEL_ROLL);
                    // cur_obj_play_sound_1(SOUND_AIR_AMP_BUZZ);
                }
            }
            break;
        case 1:
            cur_obj_become_tangible();
            cur_obj_play_sound_1(SOUND_AIR_AMP_BUZZ);
            if (o->oTimer > 30) {
                o->oAction = 2;
            }
            break;
        case 2:
            cur_obj_become_intangible();
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 30);
            if (o->oOpacity == 0) {
                o->oAction = 0;
            }
            break;
        case 3:
            if (o->oTimer > 45) {
                o->oAction = 0;
            }
            break;
    }

    if ((o->oBehParams >> 8) & 0xFF && count_room_objects_with_behavior(bhvSmallKey, o->oRoom)) {
        if (m->pos[1] > 2100.0f) {
            if (m->health < 0x300) {
                o->os16FA = 2;
            } else {
                o->os16FA = 1;
            }
        } else if (m->pos[1] <= m->floorHeight && o->os16F8 == 0) {
            o->os16FA = 0;
        }
        // CL_PRINT(4, "%x", m->action)
        if (o->os16FA && m->pos[1] < 1200.0f) {
            if (o->os16FA == 2) {
                level_trigger_warp(m, WARP_OP_WARP_FLOOR_OBJECT);
                o->os16FA = 0;
            } else {
                switch (o->os16F8++) {
                    case 0:
                        play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 0xC, 0x00, 0x00, 0x00);
                        break;
                    case 18:
                        m->faceAngle[1] = 0xC000;
                        // set_r_button_camera(gCamera);
                        warp_camera(sBalconyRespawn[0] - m->pos[0], sBalconyRespawn[1] - m->pos[1], sBalconyRespawn[2] - m->pos[2]);
                        vec3f_copy(m->pos, sBalconyRespawn);
                        s8DirModeBaseYaw = (m->faceAngle[1] + 0x8000);
                        m->forwardVel = 0;
                        vec3f_set(m->vel, 0.0f, 0.0f, 0.0f);
                        play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 0xC, 0x00, 0x00, 0x00);
                        if (m->invincTimer == 0 && m->action != ACT_SHOCKED) {
                            m->hurtCounter = 8;
                        }
                        m->invincTimer = 30;
                        gCamera->cutscene = 0;
                        o->os16F8 = 0;
                        // gCutsceneTimer = CUTSCENE_STOP;
                        set_mario_action(m, ACT_FREEFALL, 0);
                }
            }


        }
    }
}
