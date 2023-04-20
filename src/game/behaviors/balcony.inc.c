#include "levels/ssl/l8_locked_cage/geo_header.h"
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



void bhv_floating_plant_init(void) {
    struct Object *obj;
    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_FLOATING_PLANT) {
        obj = spawn_object(o, MODEL_LIGHTNING_SPINNER, bhvLightningSpinner);
        obj->oRoom = o->oRoom;
        obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
    } else {
        o->activeFlags = 0;
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
    if (o->oTimer == 0 && count_room_objects_with_behavior(bhvBooCoinCage, o->oRoom) == 0) {
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
