#include "game/object_helpers.h"
s32 approach_f32_ptr(f32 *px, f32 target, f32 delta);
s32 obj_is_rendering_enabled(void);
void cur_obj_init_anim_extend(s32 arg0);

struct ObjectHitbox sPoochyHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 3,
    /* numLootCoins:      */ 0,
    /* radius:            */ 400,
    /* height:            */ 550,
    /* hurtboxRadius:     */ 400,
    /* hurtboxHeight:     */ 550,
};

static struct ObjectHitbox sSunHitbox = {
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

struct ObjectHitbox sDarkPiranhaHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 1,
    /* numLootCoins:      */ 2,
    /* radius:            */ 120,
    /* height:            */ 180,
    /* hurtboxRadius:     */ 100,
    /* hurtboxHeight:     */ 180,
};


static struct ObjectHitbox sPelletHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 70,
    /* height:            */ 70,
    /* hurtboxRadius:     */ 70,
    /* hurtboxHeight:     */ 70,
};


s32 sSunflowers = 0;
extern s16 gComitCutsceneTimer;
extern Vec3f gComitCutscenePosVec;
extern Vec3f gComitCutsceneFocVec;

void bhv_bucket_top_init(void) {
    if (o->oBehParams2ndByte == 0) {
        o->oAction = 3;
        o->oOpacity = 40;
    } else if (o->oBehParams2ndByte == 1) {
        o->os16F4 = 1;
    }
    if ((save_file_get_golden_goombas() & (1 << 3))) {
        o->oAction = 3;
        if (o->oBehParams2ndByte < 4) {
            o->oOpacity = 255;
        }
    }
}


void bhv_bucket_top_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            if (o->os16F4 && cur_obj_is_mario_ground_pounding_platform()) {
                o->oAction = 1;
                obj = CL_nearest_object_with_behavior_and_field(bhvBucketTop, 0x144, o->oBehParams2ndByte + 1);
                if (obj == NULL) {
                    o->oAction = 2;
                } else {
                    o->oAction = 1;
                    obj->os16F4 = 1;
                    play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gGlobalSoundSource);
                }
            }
            break;
        case 1:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 10);
            if (o->oOpacity == 255) {
                o->oAction = 3;
            }
            break;
        case 2:
            if (!(save_file_get_golden_goombas() & (1 << 3))) {
                save_file_set_golden_goombas(3);
                play_puzzle_jingle();
                o->oObjF8 = spawn_object(o, MODEL_GOLDEN_GOOMBA, bhvGoldenGoomba);
                vec3f_set(&o->oObjF8->oPosX, -1400.0f, 500.0f, 1200.0f);
                gCamera->comitCutscene = 0xFF;
                gComitCutsceneTimer = 45;
                o->oObjF8->os16110 = 3045;
                vec3f_set(gComitCutscenePosVec, gMarioState->pos[0] - 500.0f, gMarioState->pos[1] + 1000.0f, gMarioState->pos[2] - 1000.0f);
                vec3f_copy(gComitCutsceneFocVec, &o->oObjF8->oPosX);
                o->oAction = 3;
            }
            break;
    }
}


void bhv_sunflower_pellet_init(void) {
    o->oForwardVel = 30.0f;
    obj_set_hitbox(o, &sPelletHitbox);
}


void bhv_sunflower_pellet_loop(void) {
    CL_Move();
    cur_obj_update_floor_and_walls();
    if (o->oMoveFlags & OBJ_MOVE_HIT_WALL || o->oMoveFlags & OBJ_MOVE_ON_GROUND 
    || o->oInteractStatus & INT_STATUS_INTERACTED) {
        o->activeFlags = 0;
        spawn_mist_particles();
        create_sound_spawner(SOUND_GENERAL_HAUNTED_CHAIR_MOVE);
    }
    if (o->oTimer < 30) {
        o->oPosY = approach_f32(o->oPosY, gMarioState->pos[1] + 100.0f, 5.0f, 5.0f);
    }
}


void bhv_standing_sunflower_loop(void) {
    struct Object *obj = cur_obj_nearest_object_with_behavior(bhvL3Sun);
    if (obj == NULL) {
        o->activeFlags = 0;
        return;
    }
    if (obj->oHeldState == HELD_HELD/* && o->oDistanceToMario < 1000.0f*/) {
        o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x80);
        if (o->oTimer > o->oF4) {
            obj = spawn_object(o, MODEL_SUNFLOWER_PELLET, bhvSunflowerPellet);
            obj->oMoveAngleYaw = o->oMoveAngleYaw;
            obj->oPosY += 244.0f;
            o->oTimer = 0;
            o->oF4 = CL_RandomMinMaxU16(90, 180);
        }
    } else {
        o->oTimer = 0;
    }
}

void dark_piranha_act_hide(void) {
    if (o->oFirePiranhaPlantDeathSpinTimer != 0) {
        o->oMoveAngleYaw += (s32) o->oFirePiranhaPlantDeathSpinVel;
        approach_f32_ptr(&o->oFirePiranhaPlantDeathSpinVel, 0.0f, 200.0f);

        if (cur_obj_check_if_near_animation_end()) {
            if (--o->oFirePiranhaPlantDeathSpinTimer == 0) {
                cur_obj_play_sound_2(SOUND_OBJ_ENEMY_DEFEAT_SHRINK);
            }
        }
    } else if (approach_f32_ptr(&o->oFirePiranhaPlantScale, 0.0f,
                                0.04f * o->oFirePiranhaPlantNeutralScale)) {
        cur_obj_become_intangible();
        if (o->oFirePiranhaPlantActive) {
            o->oFirePiranhaPlantActive = FALSE;

            if (o->oHealth == 0) {
                obj_die_if_health_non_positive();
                set_object_respawn_info_bits(o, 1);
            }
        } else {
            cur_obj_play_sound_2(SOUND_OBJ_PIRANHA_PLANT_APPEAR);

            o->oFirePiranhaPlantActive = TRUE;

            cur_obj_unhide();
            o->oAction = 1;
            o->oMoveAngleYaw = o->oAngleToMario;
        }
    }

    cur_obj_extend_animation_if_at_end();
}


void dark_piranha_act_grow(void) {
    cur_obj_init_anim_extend(4);

    if (o->oDistanceToMario > 1400.0f) {
        o->oTimer = 0;
        o->header.gfx.animInfo.animFrame = 0;
    }

    if (approach_f32_ptr(&o->oFirePiranhaPlantScale, o->oFirePiranhaPlantNeutralScale,
                         0.04f * o->oFirePiranhaPlantNeutralScale)) {
        if (o->oTimer > 80) {
            //cur_obj_play_sound_2(SOUND_OBJ_PIRANHA_PLANT_SHRINK);
            //o->oAction = 0;
            //cur_obj_init_animation_with_sound(0);
        } else if (o->oTimer < 50) {
            cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x400);
        } else { // TODO: Check if we can put these conditionals on same line
            if (obj_is_rendering_enabled()) {
                if (cur_obj_check_anim_frame(56)) {
                    cur_obj_play_sound_2(SOUND_OBJ_FLAME_BLOWN);
                    obj_spit_fire(0, (s32)(30.0f * o->oFirePiranhaPlantNeutralScale),
                                  (s32)(140.0f * o->oFirePiranhaPlantNeutralScale),
                                  2.5f * o->oFirePiranhaPlantNeutralScale, MODEL_RED_FLAME_SHADOW,
                                  20.0f, 15.0f, 0x1000);
                    o->oTimer = 0;
                    o->header.gfx.animInfo.animFrame = 0;
                }
            }
        }
    } else if (o->oFirePiranhaPlantScale > o->oFirePiranhaPlantNeutralScale / 2) {
        cur_obj_become_tangible();
    }
}


void bhv_dark_piranha_loop(void) {
    struct Object *obj;
    cur_obj_scale(o->oFirePiranhaPlantScale);

    if ((o->oDistanceToMario < 2500.0f && o->oPosY > gMarioState->pos[1] - 800.0f) || !gIsConsole) {
        cur_obj_unhide();
    } else {
        cur_obj_hide();
    }

    switch (o->oAction) {
        case 0:
            dark_piranha_act_hide();
            break;
        case 1:
            dark_piranha_act_grow();
            break;
    }

    obj = cur_obj_nearest_object_with_behavior(bhvL3Sun);
    if (obj == NULL) {
        o->activeFlags = 0;
    }
    if (o->oHealth != 0 && obj->oHeldState == HELD_HELD && o->oDistanceToMario < 575.0f) {
        o->oAction = 0;
        o->oHealth = 0;
        o->oFirePiranhaPlantDeathSpinTimer = 10;
        o->oFirePiranhaPlantDeathSpinVel = 8000.0f;

        cur_obj_become_intangible();
    }
    o->oInteractStatus = 0;
}




void bhv_dark_piranha_init(void) {
    o->oRoom = 4;
    o->oFirePiranhaPlantNeutralScale = 1.0f;
    obj_set_hitbox(o, &sDarkPiranhaHitbox);
    //o->oFlags |= 0x00004000;
    //o->oAction = 1;
}

extern s32 gSunblockOpacity;

void bhv_sunblock_col_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gSunblockOpacity != 0x38) {
                o->oAction = 1;
            }
            break;
        case 1:
            load_object_collision_model();
            if (gSunblockOpacity == 0x38) {
                o->oAction = 0;
            }
            break;
    }
}


void sun_held_loop(void) {
    cur_obj_become_intangible();
    o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
    o->oFC = 0;
    cur_obj_set_pos_relative(gMarioObject, 0, 60.0f, 60.0f);

    o->os16F4 = approach_s16_symmetric(o->os16F4, 0xFF, 0x10);
    o->os16F6 = approach_s16_symmetric(o->os16F6, 0xBD, 0x10);
    o->os16FA = o->header.gfx.animInfo.animFrame;
}

void sun_dropped_loop(void) {
    cur_obj_get_dropped();
    cur_obj_become_tangible();

    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    //cur_obj_init_animation(0);

    //o->oFC = 1;
    o->oHeldState = 0;
    //o->oAction = 0;
}


void sun_free_loop(void) {
    object_step();
    o->header.gfx.animInfo.animFrame = o->os16FA;
    o->os16F4 = approach_s16_symmetric(o->os16F4, 0x99, 0x10);
    o->os16F6 = approach_s16_symmetric(o->os16F6, 0x71, 0x10);

    if (sObjFloor != NULL && (sObjFloor->type == SURFACE_BURNING || sObjFloor->type == SURFACE_INSTANT_QUICKSAND)) {
        o->os16FC = 1;
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
            o->oFaceAngleYaw = 0;
            o->os16FC = 0;
            o->header.gfx.scale[1] = o->header.gfx.scale[2] = o->header.gfx.scale[0] = 1.0f;
        }
    }
}



void bhv_sun_loop(void) {
    switch (o->oHeldState) {
        case HELD_FREE:
            sun_free_loop();
            break;

        case HELD_HELD:
            sun_held_loop();
            break;
        case HELD_THROWN:
        case HELD_DROPPED:
            sun_dropped_loop();
            break;
    }
}



void bhv_sun_init(void) {
    o->oGravity = 2.5;
    o->oFriction = 0.8;
    o->oBuoyancy = 1.3;
    o->os16F4 = 0x99;
    o->os16F6 = 0x71;
    o->os16F8 = 0;
    o->os16FA = 0;
    obj_set_hitbox(o, &sSunHitbox);
}


void bhv_flower_wall_init(void) {
    o->oOpacity = 0xFF;
    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_FLOWER_DOOR) {
        o->activeFlags = 0;
    }
    //o->activeFlags = 0;
}


void bhv_flower_wall_loop(void) {
    switch (o->oAction) {
        case 0:
            if (sSunflowers >= 3) {
               o->oAction = 1;
               play_puzzle_jingle();
               gCamera->comitCutscene = 0xFF;
               vec3f_copy(gComitCutsceneFocVec, &o->oPosX);
               gComitCutsceneFocVec[1] += 500.0f;
               vec3f_set(gComitCutscenePosVec, o->oPosX, o->oPosY + 1500.0f, o->oPosZ - 2000.0f);
            }
            break;
        case 1:
            set_mario_npc_dialog(1);
            gCamera->comitCutscene = 0xFF;
            if (o->oTimer > 15) {
                o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 10);
                if (o->oOpacity < 10) {
                    o->activeFlags = 0;
                    gComitCutsceneTimer = 30;
                    set_mario_npc_dialog(0);
                    save_file_set_newflags(SAVE_NEW_FLAG_FLOWER_DOOR, 0);
                }
            }
            break;
    }
}


void bhv_exit_wall_init(void) {
    o->oOpacity = 0xFF;
    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_EXIT_DOOR) {
        o->activeFlags = 0;
    }
    //o->activeFlags = 0;
}


void bhv_exit_wall_loop(void) {
    switch (o->oAction) {
        case 0:
            if (cur_obj_nearest_object_with_behavior(bhvPoochyBoss) == NULL) {
               o->oAction = 1;
               play_puzzle_jingle();
               gCamera->comitCutscene = 0xFF;
               vec3f_copy(gComitCutsceneFocVec, &o->oPosX);
               gComitCutsceneFocVec[1] += 500.0f;
               vec3f_set(gComitCutscenePosVec, o->oPosX, o->oPosY + 1500.0f, o->oPosZ - 2000.0f);
            }
            break;
        case 1:
            set_mario_npc_dialog(1);
            gCamera->comitCutscene = 0xFF;
            if (o->oTimer > 15) {
                o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 8);
                if (o->oOpacity == 0) {
                    o->activeFlags = 0;
                    gComitCutsceneTimer = 30;
                    set_mario_npc_dialog(0);
                    save_file_set_newflags(SAVE_NEW_FLAG_EXIT_DOOR, 0);
                }
            }
            break;
    }
}


void bhv_poochy_boss_init(void) {
    cur_obj_disable();
    obj_set_hitbox(o, &sPoochyHitbox);
    vec3f_set(&o->oHomeX, -1359.0f, -488.0f, 1587.0f);
    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_EXIT_DOOR) {
        o->activeFlags = 0;
    }
}

void bhv_poochy_boss_loop(void) {
    s32 jumps, frame;
    switch (o->oAction) {
        case 0:
            if (save_file_get_newflags(0) & (1 << 8)) {
                if (o->oTimer > 90) {
                    o->oAction = 1;
                    cur_obj_enable();
                    o->oObjF4 = spawn_object(o, MODEL_GARDEN_HOLES, bhvGardenHoles);
                    o->oObjF4->oPosX = o->oObjF4->oPosZ = 0;
                    o->oObjF4->oCollisionDistance = 0;
                    o->oObjF4->oPosY = 0;
                    o->oObjF4->oFaceAngleYaw = o->oObjF4->oMoveAngleYaw = 0;
                    o->oObjF4->oFaceAnglePitch = o->oObjF4->oMoveAnglePitch = 0;
                    o->oObjF4->oFaceAngleRoll = o->oObjF4->oMoveAngleRoll = 0;
                    gCamera->comitCutscene = 0xFF;
                    vec3f_copy(gComitCutsceneFocVec, &o->oPosX);
                    vec3f_copy(gComitCutscenePosVec, &o->oPosX);
                    gComitCutscenePosVec[0] -= 3000.0f;
                }
            } else {
                o->oTimer = 0;
            }
            break;
        case 1:
            set_mario_npc_dialog(1);
            gCamera->comitCutscene = 0xFF;
            gComitCutscenePosVec[1] = gComitCutsceneFocVec[1] = o->oPosY;
            cur_obj_move_standard(-78);
            o->oObjF4->oPosY = o->oPosY;
            o->oObjF4->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
            if (o->oMoveFlags & OBJ_MOVE_ON_GROUND) {
                gComitCutsceneTimer = 15;
                set_mario_npc_dialog(0);
                o->oAction = 2;
                o->os16112 = 0x80;
                o->oObjF4->oPosY = -488.0f;
                o->oObjF4->oCollisionDistance = 32767.0f;
                cur_obj_init_animation_with_sound(0);
                play_music(0, SEQUENCE_ARGS(4, SEQ_GENERIC_BOSS), 0);
            }
            break;
        case 2:
            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(-78);
            // CL_PRINT(2, "%d", o->header.gfx.animInfo.animFrame)
            frame = o->header.gfx.animInfo.animFrame;
            if (o->oMoveFlags & OBJ_MOVE_ON_GROUND && frame == 1 || frame == 8 || frame == 16 || frame == 26) {
                cur_obj_play_sound_2(SOUND_OBJ_BULLY_WALK);
            }
            o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, 0, 0x800);
            if (o->os16FA == 0) {
                o->oForwardVel = approach_f32(o->oForwardVel, 40.0f, 0.5f, 0.5f);
                o->oMoveAngleYaw += 0x100;
                if (o->oTimer > 90) {
                    o->os16FA = 1;
                    o->oTimer = 0;
                    cur_obj_play_sound_2(SOUND_OBJ2_BOWSER_ROAR);
                }
            } else {
                o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 52.0f, 0.27f);
                if (absi((s16)o->oMoveAngleYaw - o->oAngleToMario) < 0x4000) {
                    o->os16112 = approach_s16_symmetric(o->os16112, 0x300, 0xC);
                } else {
                    o->os16112 = approach_s16_symmetric(o->os16112, 0x400, 0xC);
                }
                o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, o->os16112);
                if (o->oDistanceToMario < 1500.0f && ((absi(o->oMoveAngleYaw - o->oAngleToMario) < 0x1000 && o->oTimer > 120) || o->os16F8 != 0)) {
                    jumps = o->oHealth < 3 ? 2 : 0;
                    if (o->os16F8 >= jumps) {
                        o->oAction = 3;
                        cur_obj_init_animation_with_sound(1);
                    } else {
                        o->oAction = 6;
                        cur_obj_init_animation_with_sound(1);
                    }
                    cur_obj_play_sound_2(SOUND_OBJ_KING_BOBOMB_JUMP);
                    o->os16112 = 0x80;
                    o->oVelY = 77.0f;
                    o->oForwardVel = 40.0f;
                    o->os16FA = 0;
                }
            }
            break;
        case 3:
            if (o->oTimer < 2) {
                break;
            }
            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(-78);
            o->oForwardVel = approach_f32(o->oForwardVel, 8.0f, 0.5f, 0.5f);
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x20);
            o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, -atan2s(o->oForwardVel, o->oVelY), 0x400);
            //o->oFaceAnglePitch = 0x4000;
            if (o->oVelY == 0) {
                o->oFaceAnglePitch = 0x4000;
            }
            if (o->oMoveFlags & OBJ_MOVE_ON_GROUND) {
                o->oAction = 4;
                o->oFaceAnglePitch = 0x4000;
                o->oPosY -= 200.0f;
                o->os16F8 = 0;
                cur_obj_play_sound_2(SOUND_OBJ_BOWSER_WALK);
            }
            if (dist_between_objects(o, gMarioObject) < 400.0f) {
                CL_get_hit(gMarioState, o, 2);
                o->oAction = 2;
                cur_obj_init_animation_with_sound(0);
                o->os16F8 = 0;
            }
            o->oInteractType = INTERACT_BOUNCE_TOP;
            break;
        case 4:
            if (o->oSubAction == 0) {
                if (o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
                    o->oHealth--;
                    o->oSubAction = 1;
                    o->oTimer = 0;
                    gMarioState->pos[0] = o->oPosX;
                    gMarioState->pos[1] = o->oPosY + o->hitboxHeight;
                    gMarioState->pos[2] = o->oPosZ;
                    gMarioState->faceAngle[1] = cur_obj_angle_to_home();
                    gMarioState->vel[1] = 20.0f;
                    mario_set_forward_vel(gMarioState, 50.0f);
                    set_mario_action(gMarioState, ACT_CUTSCENE_JUMP, 1);
                    o->header.gfx.scale[1] = (o->header.gfx.scale[0] = 0.9f);
                    o->header.gfx.scale[2] = 0.6f;
                    cur_obj_play_sound_2(SOUND_OBJ_BOO_BOUNCE_TOP);
                }
            } else {
                o->header.gfx.scale[2] = approach_f32(o->header.gfx.scale[1], 0.8f, 0.02f, 0.02f);
                o->header.gfx.scale[0] = approach_f32(o->header.gfx.scale[0], 0.8f, 0.01f, 0.01f);
                o->header.gfx.scale[1] = o->header.gfx.scale[2];
                if (o->oTimer > 25) {
                    o->oAction = 2;
                    cur_obj_init_animation_with_sound(0);
                    o->oPosY += 200.0f;
                    o->oInteractType = INTERACT_DAMAGE;
                    play_sound(SOUND_ACTION_UNSTUCK_FROM_GROUND, gGlobalSoundSource);
                }
                if (o->oHealth == 0) {
                    o->oAction = 5;
                    o->oForwardVel = 300.0f;
                    o->oVelY = 110.0f;
                    cur_obj_become_intangible();
                    cur_obj_init_animation_with_sound(0);
                }
            }
            break;
        case 5:
            o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, -0, 0x400);
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, 0x8000, 0x400);
            if (o->oTimer > 28) {
                cur_obj_init_animation_with_sound(1);
            }
            if (o->oTimer > 30) {
                CL_Move();
                //cur_obj_move_standard(-78);
                //cur_obj_update_floor_and_walls();
            }
            if (o->oTimer > 90) {
                o->activeFlags = 0;
                o->oObjF4->activeFlags = 0;
                stop_background_music(SEQUENCE_ARGS(4, SEQ_GENERIC_BOSS));
            }
            break;
        case 6:
            if (o->oTimer < 2) {
                break;
            }
            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(-78);
            o->oForwardVel = approach_f32(o->oForwardVel, 8.0f, 0.5f, 0.5f);
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x20);
            /*o->oFaceAnglePitch = -atan2s(o->oForwardVel, o->oVelY);
            if (o->oVelY == 0) {
                o->oFaceAnglePitch = 0x4000;
            }*/
            if (o->oMoveFlags & OBJ_MOVE_ON_GROUND) {
                o->oAction = 2;
                cur_obj_init_animation_with_sound(0);
                o->os16F8++;
                o->os16FA = 1;
                if (absi(o->oAngleToMario - o->oMoveAngleYaw) < 0x3000)
                    o->oMoveAngleYaw = o->oAngleToMario;
                else
                    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x3000);
            }

            if (dist_between_objects(o, gMarioObject) < 400.0f) {
                CL_get_hit(gMarioState, o, 2);
                o->oAction = 2;
                cur_obj_init_animation_with_sound(0);
                o->os16F8 = 0;
            }
            //o->oInteractType = INTERACT_BOUNCE_TOP;
            break;
    }
    o->oInteractStatus = 0;
}

extern const Collision bounce_box_collision[];
extern const Collision snow_box_collision[];
extern const Collision laundry_bounce_box_collision[];
extern const Collision l10_bounce_box_collision[];

static void const *sBoxCollision[] = {
    bounce_box_collision,
    snow_box_collision,
    laundry_bounce_box_collision,
    mem_bounce_box_collision,
    l10_bounce_box_collision,
};

void bhv_bounce_box_init(void) {
    o->collisionData = segmented_to_virtual(sBoxCollision[o->oBehParams >> 24]);
}


void bhv_bounce_box_loop(void) {
    struct MarioState *m = gMarioState;
    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o) {
                if (o->oBehParams2ndByte)
                    o->oFloatF4 = o->oBehParams2ndByte * 10.0f;
                else
                    o->oFloatF4 = 200.0f;
                o->oAction = 1;
            }
            break;
        case 1:
            if (approach_f32_ptr(&o->header.gfx.scale[1], 0.5f, 0.25f)) {
                set_mario_action(m, ACT_CUTSCENE_JUMP, 2);
                set_r_button_camera(gCamera);
                m->vel[1] = o->oFloatF4;
                m->faceAngle[1] = (m->angleVel[1] = o->oFaceAngleYaw + 0xC000);
                mario_set_forward_vel(m, 15.0f);
                play_sound(SOUND_ACTION_BOUNCE_OFF_OBJECT, m->marioObj->header.gfx.cameraToObject);
                cur_obj_play_sound_1(SOUND_GENERAL_BOING1);
                o->oAction = 2;
            }
            break;
        case 2:
            if (approach_f32_ptr(&o->header.gfx.scale[1], 1.25f, 0.2f)) {
                o->oAction = 3;
            }

            if (gMarioObject->platform == o) {
                o->header.gfx.scale[1] = 1.0f;
                o->oAction = 1;
            }
            break;
        case 3:
            if (approach_f32_ptr(&o->header.gfx.scale[1], 1.0f, 0.2f)) {
                o->header.gfx.scale[1] = 1.0f;
                o->oAction = 0;
            }

            if (gMarioObject->platform == o) {
                o->header.gfx.scale[1] = 1.0f;
                o->oAction = 1;
            }
            break;
    }
}




void bhv_dirt_mound_init(void) {
    o->oRoom = 1;
}

void bhv_dirt_mound_loop(void) {
    switch (o->oAction) {
        case 0:
            if (cur_obj_is_mario_ground_pounding_platform())
                o->oAction = 1;
            break;
        case 1:
            o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 0, 0.2f);
            if (o->header.gfx.scale[1] == 0) {
                o->activeFlags = 0;
                spawn_mist_particles();
            }
            break;
    }
}



void bhv_sunflower_init(void) {
    sSunflowers = 0;
    o->oOpacity = 80;
    //o->oFloatF4 = 0.6f;
    o->header.gfx.scale[1] = 0.6f;
    //cur_obj_scale(o->oFloatF4);
    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_FLOWER_DOOR) {
        o->oAction = 1;
    }
}

void bhv_sunflower_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            o->header.gfx.animInfo.animFrame = 0;
            if (o->oDistanceToMario < 100.0f) {
                o->oAction = 1;
                play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gGlobalSoundSource);
                sSunflowers++;
            }
            break;
        case 1:
            obj = spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
            obj->oPosY += 200.0f;
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 12);
            o->header.gfx.scale[1] = approach_f32(o->header.gfx.scale[1], 0.9f, 0.02f, 0.02f);
            //cur_obj_scale(o->oFloatF4);
            if (o->header.gfx.scale[1] == 0.9f && o->oOpacity == 255) {
                o->oAction = 2;
            }
            break;
        case 2:
            break;
    }

    if (o->oBehParams2ndByte) {
        if (gMarioState->pos[1] < -600.0f && gMarioState->pos[1] > -1300.0f) {
            gCamera->comitCutscene = 2;
        } else if (gCamera->comitCutscene == 2) {
            gCamera->comitCutscene = 0;
        }
    }
}