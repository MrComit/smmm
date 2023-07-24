#include "game/save_file.h"
#include "buffers/buffers.h"
extern Vec3s gRoomColors[];
extern struct Object *gComitCutsceneObject;
void spawn_orange_number_three_digit_scale(u16 behParam, s16 relX, s16 relY, s16 relZ, f32 dist, f32 scale);
void spawn_orange_number_three_digit_scale_stay(u16 behParam, s16 relX, s16 relY, s16 relZ, f32 dist, f32 scale, s32 palette);

static struct ObjectHitbox sStarPieceHitbox = {
    /* interactType:      */ INTERACT_STAR_OR_KEY,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 80,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

struct ObjectHitbox sTokenHitbox = {
    /* interactType: */ INTERACT_COIN,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 1,
    /* health: */ 0,
    /* numLootCoins: */ 0,
    /* radius: */ 120,
    /* height: */ 78,
    /* hurtboxRadius: */ 0,
    /* hurtboxHeight: */ 0,
};

struct ObjectHitbox sSmallKeyHitbox = {
    /* interactType: */ INTERACT_STAR_OR_KEY,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 0,
    /* numLootCoins: */ 0,
    /* radius: */ 160,
    /* height: */ 100,
    /* hurtboxRadius: */ 160,
    /* hurtboxHeight: */ 100,
};


struct ObjectHitbox sBooCoinHitbox = {
    /* interactType: */ INTERACT_COIN,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 0,
    /* numLootCoins: */ 0,
    /* radius: */ 100,
    /* height: */ 84,
    /* hurtboxRadius: */ 0,
    /* hurtboxHeight: */ 0,
};

static struct ObjectHitbox sBooCoinCageHitbox = {
    /* interactType: */ INTERACT_IGLOO_BARRIER,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 0,
    /* numLootCoins: */ 0,
    /* radius: */ 80,
    /* height: */ 70,
    /* hurtboxRadius: */ 0,
    /* hurtboxHeight: */ 0,
};


struct ObjectHitbox sCollectHeartHitbox = {
    /* interactType:      */ INTERACT_COIN,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 75,
    /* height:            */ 75,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

struct ObjectHitbox sGoldenGoombaHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 72,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 42,
    /* hurtboxHeight:     */ 40,
};

struct ObjectHitbox sGoldenCrateHitbox = {
    /* interactType:      */ INTERACT_BREAKABLE,
    /* downOffset:        */ 20,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 1,
    /* numLootCoins:      */ 0,
    /* radius:            */ 75,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 75,
    /* hurtboxHeight:     */ 100,
};


struct ObjectHitbox sJournalHitbox = {
    /* interactType:      */ INTERACT_IGLOO_BARRIER,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 35,
    /* height:            */ 35,
    /* hurtboxRadius:     */ 35,
    /* hurtboxHeight:     */ 35,
};

extern u8 sGoombaAttackHandlers[][6];
extern s16 gComitCutsceneTimer;
extern Vec3f gComitCutscenePosVec;
extern Vec3f gComitCutsceneFocVec;

Vec3f sPreviousMarioPos = {0, 0, 0};

u8 sTokenCoins[3] = {10, 50, 100};



// void bhv_dirt_pile_init(void)
void bhv_dirt_pile_loop(void) {
    struct MarioState *m = gMarioState;
    struct Object *obj;
    s32 whichSide = 0;
    switch (o->oAction) {
        case 0:
            if (m->wall != NULL && m->wall->object == o && m->flags & MARIO_UNKNOWN_31) {
                o->oForwardVel = 10.0f;
                o->oMoveAngleYaw = (s16)((o->oAngleToMario - 0x8000) + 0x2000) & 0xC000;
                CL_Move();
                m->pos[0] += o->oVelX;
                m->pos[2] += o->oVelZ;
                if (cur_obj_lateral_dist_to_home() > 300.0f) {
                    o->oAction = 1;
                    obj = cur_obj_nearest_object_with_behavior(bhvCastlePlant);
                    if (obj != NULL) {
                        obj->oAction = 1;
                        play_puzzle_jingle();
                        save_file_set_newflags(SAVE_NEW_FLAG_FLOATING_PLANT, 0);
                    }
                }
            }
            break;
    }
}


void bhv_castle_plant_init(void) {
    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_FLOATING_PLANT) {
        o->activeFlags = 0;
    }
}


void bhv_castle_plant_loop(void) {
    switch (o->oAction) {
        case 1:
            o->oFloatF4 = approach_f32_symmetric(o->oFloatF4, 30.0f, 0.5f);
            o->oPosY += o->oFloatF4;
            if (o->oPosY - o->oHomeY > 5000.0f) {
                o->oAction = 2;
            }
            break;
        case 2:
            o->oPosY += 30.0f;
            o->header.gfx.scale[0] -= 0.02f;
            o->header.gfx.scale[1] = o->header.gfx.scale[2] = o->header.gfx.scale[0];
            if (o->header.gfx.scale[0] < 0.05f) {
                o->activeFlags = 0;
            }
            break;
    }
}


void bhv_golden_pillar_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            if (save_file_get_boos() & (1 << 4)) {
                cur_obj_unhide();
                if (save_file_get_golden_goombas() & (1 << ((o->oBehParams >> 8) & 0xFF))) {
                    o->oAction = 2;
                } else {
                    o->oAction = 1;
                }
            }
            break;
        case 1:
            if (cur_obj_is_mario_ground_pounding_platform()) {
                if (!(save_file_get_golden_goombas() & (1 << ((o->oBehParams >> 8) & 0xFF)))) {
                    save_file_set_golden_goombas((o->oBehParams >> 8) & 0xFF);
                    play_puzzle_jingle();
                    o->oObjF4 = spawn_object(o, MODEL_GOLDEN_GOOMBA, bhvGoldenGoomba);
                    vec3f_set(&o->oObjF4->oPosX, -2500.0f, 500.0f, 14000.0f);
                    gCamera->comitCutscene = 0xFF;
                    gComitCutsceneTimer = 45;
                    o->oObjF4->os16110 = 3045;
                    vec3f_set(gComitCutscenePosVec, gMarioState->pos[0], gMarioState->pos[1] + 1000.0f, gMarioState->pos[2] + 2000.0f);
                    vec3f_copy(gComitCutsceneFocVec, &o->oObjF4->oPosX);
                }
                o->oAction = 2;
            }
            // load_object_collision_model();
            // break;
        case 2:
            // gCamera->comitCutscene = 0xFF;
            // set_mario_npc_dialog(1);
            load_object_collision_model();
            break;
    }
}


void bhv_portal_warning_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oRoom == gMarioCurrentRoom && gMarioState->pos[2] > -7500.0f) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (CL_NPC_Dialog(DIALOG_063)) {
                o->oAction = 2;
            }
            break;
    }
    o->oInteractStatus = 0;
    o->oIntangibleTimer = 0;
}



void bhv_journal_book_init(void) {
    obj_set_hitbox(o, &sJournalHitbox);
}

void bhv_journal_book_loop(void) {
    o->oFaceAngleYaw += 0x600;
    o->os16F4 += 0x400;
    o->oGraphYOffset = 20.0f + (sins(o->os16F4) * 20.0f);
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 100.0f) {
                if (o->os16F8 == 0) {
                    o->oAction = 1;
                    o->os16F8 = 1;
                }
            } else if (o->os16F8 && lateral_dist_between_objects(o, gMarioObject) > 250.0f) {
                o->os16F8 = 0;
            }
            break;
        case 1:
            if (CL_NPC_Dialog(o->oBehParams2ndByte)) {
                o->oAction = 0;
            }
            break;
    }
    o->oInteractStatus = 0;
}


void bhv_golden_crate_init(void) {
    u8 challenge = (o->oBehParams >> 8) & 0xFF;
    if (save_file_get_golden_goombas() & (1 << challenge)) {
        o->activeFlags = 0;
    }
}


void bhv_golden_crate_loop(void) {
    struct Object *obj;
    obj_set_hitbox(o, &sGoldenCrateHitbox);
    if (cur_obj_was_attacked_or_ground_pounded() != 0) {
        obj_explode_and_spawn_coins(46.0f, 1);
        create_sound_spawner(SOUND_GENERAL_BREAK_BOX);
        // save_file_set_challenges((o->oBehParams >> 8) & 0xFF);
        save_file_set_golden_goombas((o->oBehParams >> 8) & 0xFF);
        obj = spawn_object(o, MODEL_GOLDEN_GOOMBA, bhvGoldenGoomba);
        obj->oBehParams = o->oBehParams;
        obj->oVelY = 20.0f;
    }
    if (o->oDistanceToMario < 150.0f) {
        if (o->oTimer > 25) {
            struct Object *obj = spawn_object(o, MODEL_SPARKLES, bhvGoldenCoinSparkles);
            switch (o->os16F4) {
                case 0:
                    obj->oPosY += 70.0f;
                    o->os16F4 = 1;
                    break;
                case 1:
                    obj->oPosX += 60.0f;
                    obj->oPosZ -= 60.0f;
                    o->os16F4 = 2;
                    break;
                case 2:
                    obj->oPosX -= 60.0f;
                    obj->oPosZ += 60.0f;
                    o->os16F4 = 3;
                    break;
                case 3:
                    obj->oPosX -= 60.0f;
                    obj->oPosZ -= 60.0f;
                    o->os16F4 = 4;
                    break;
                case 4:
                    obj->oPosX += 60.0f;
                    obj->oPosZ += 60.0f;
                    o->os16F4 = 0;
                    break;
            }
            o->oTimer = 0;
        }
    }
}


s32 golden_goomba_turn_away_from_doors(void) {
    struct Object *obj;
    s32 val = FALSE;
    if ((obj = cur_obj_nearest_object_with_behavior(bhvDoor)) != NULL && dist_between_objects(o, obj) < 100.0f) {
        val = TRUE;
    } else if ((obj = cur_obj_nearest_object_with_behavior(bhvBigKeyDoor)) != NULL && dist_between_objects(o, obj) < 100.0f) {
        val = TRUE;
    } else if ((obj = cur_obj_nearest_object_with_behavior(bhvSmallKeyDoor)) != NULL && dist_between_objects(o, obj) < 100.0f) {
        val = TRUE;
    } else if ((obj = cur_obj_nearest_object_with_behavior(bhvBlockedDoor)) != NULL && dist_between_objects(o, obj) < 100.0f) {
        val = TRUE;
    }
    if (val) {
         o->oMoveAngleYaw = o->os16112 = obj_angle_to_object(o, obj) + 0x8000;
    }
    return val;
}


void golden_goomba_behavior(void) {
    f32 animSpeed;
    if (((o->oBehParams >> 8) & 0xFF) == 10 || ((o->oBehParams >> 8) & 0xFF) == 11) {
        o->oForwardVel = 0.0f;
        if (o->os16110 <= 2999) {
            o->os16110 = 3009;
        }
    }
    cur_obj_update_floor_and_walls();
    cur_obj_move_standard(-78);
    if (o->oFloor != NULL && o->oMoveFlags & OBJ_MOVE_MASK_ON_GROUND &&
        (o->oFloor->type == SURFACE_INSTANT_QUICKSAND || o->oFloor->type == SURFACE_BURNING || o->oFloor->type == SURFACE_DEATH_PLANE)) {
            vec3f_set(&o->oPosX, o->oHomeX, o->oHomeY + 500.0f, o->oHomeZ);
        }
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->os16112, 0x800);
    if (o->oMoveFlags & OBJ_MOVE_HIT_WALL) {
        o->os16112 = o->oWallAngle; 
    } else if (!(golden_goomba_turn_away_from_doors())) {
        o->os16112 = approach_s16_symmetric(o->os16112, o->oAngleToMario + 0x8000, 0xC00);
    }
    // o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 30.0f, 0.5f);
    o->oForwardVel = 30.0f;
    cur_obj_init_animation_with_accel_and_sound(0, 10.0f);
    cur_obj_play_sound_at_anim_range(2, 17, SOUND_OBJ_GOOMBA_WALK);
    if (obj_handle_attacks(&sGoldenGoombaHitbox, GOOMBA_ACT_ATTACKED_MARIO,
                            sGoombaAttackHandlers[o->oGoombaSize & 1])) {
        o->activeFlags = 0;
    }
    // CL_PRINT(0, "%x", o->oWallAngle);
}



void bhv_golden_goomba_init(void) {
    bhv_goomba_init();
    o->os16110 = 3000;
    o->oForwardVel = 30.0f;
    o->oMoveAngleYaw = o->oFaceAngleYaw = obj_angle_to_object(o, gMarioObject) + 0x8000;
    // obj_set_hitbox(o, &sGoldenGoombaHitbox);
}


void bhv_golden_goomba_update(void) {
    struct Object *coin;
    f32 scale;
    s32 spawnCoins;
    if (o->os16110 % 10 == 0) {
        scale = (f32)(o->os16110) / 2500.0f;
        spawn_orange_number_three_digit_scale_stay(o->os16110 / 10, 0, 0, 0, 50.0f * scale, 0.25f + scale, 6);
    }
    o->os16110--;
    if (o->os16110 < 0) {
        o->os16110 = 0;
    }
    golden_goomba_behavior();
    if (o->activeFlags == 0) {
        spawnCoins = (o->os16110 / 10) * 0.15f;
        if (spawnCoins > 15) {
            spawnCoins = 15;
        }
        gMarioState->numCoins += (o->os16110 / 10) - spawnCoins;
        for (; spawnCoins > 0; spawnCoins--) {
            coin = spawn_object(o, MODEL_YELLOW_COIN, bhvSingleCoinGetsSpawned);
            coin->oVelY = 20.0f + (random_float() * 80.0f);
        }
    }
}



void bhv_collect_heart_init(void) {
    o->oVelY = random_float() * 5.0f + 15 + (o->oCoinUnk110 / 2);
    o->oForwardVel = random_float() * 10.0f;
    o->oMoveAngleYaw = random_u16();

    obj_set_hitbox(o, &sCollectHeartHitbox);
    if (o->oF4 == 0) {
        cur_obj_become_intangible();
    }
}


void bhv_collect_heart_loop(void) {
    struct Surface *sp1C;

    if (o->oF4 == 0) {
        cur_obj_update_floor_and_walls();
        cur_obj_if_hit_wall_bounce_away();
        cur_obj_move_standard(-62);

        if ((sp1C = o->oFloor) != NULL) {
            if (o->oMoveFlags & OBJ_MOVE_ON_GROUND) {
                o->oSubAction = 1;
            }
            if (o->oSubAction == 1) {
                o->oBounciness = 0;
                if (sp1C->normal.y < 0.9) {
                    s16 sp1A = atan2s(sp1C->normal.z, sp1C->normal.x);
                    cur_obj_rotate_yaw_toward(sp1A, 0x400);
                }
            }
        }

        if (o->oVelY < 0) {
            cur_obj_become_tangible();
        }

        if (o->oMoveFlags & OBJ_MOVE_LANDED) {
            if (o->oMoveFlags & (OBJ_MOVE_ABOVE_DEATH_BARRIER | OBJ_MOVE_ABOVE_LAVA)) {
                obj_mark_for_deletion(o);
            }
        }

        o->oForwardVel = approach_f32_asymptotic(o->oForwardVel, 0.0f, 0.01f);

        if (cur_obj_wait_then_blink(400, 20)) {
            obj_mark_for_deletion(o);
        }
    }
    if (gCamera->comit2dcam == 1 || gCamera->comit2dcam == 3) {
        o->oPosZ = o->oHomeZ;
    }

    o->oFaceAngleYaw += 0x400;


    if (o->oInteractStatus & INT_STATUS_INTERACTED
        && !(o->oInteractStatus & INT_STATUS_TOUCHED_BOB_OMB)) {
        o->activeFlags = 0;
        gMarioState->healCounter += 4;
        cur_obj_play_sound_2(SOUND_GENERAL_HEART_SPIN);
    }

    o->oInteractStatus = 0;
}


void bhv_held_letter_loop(void) {
    if (o->oHeldState == HELD_HELD) {
        cur_obj_become_intangible();
        o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
        cur_obj_set_pos_relative(gMarioObject, -80.0f, 60.0f, 60.0f);
        o->oMoveAngleYaw = 0x8000;
    }
}


void bhv_generic_switch_loop(void) {
    if (o->oBehParams >> 24 == 1) {
        o->oRoom2 = 2;
    }
    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o && !(gMarioStates[0].action & MARIO_UNKNOWN_13)) {
                if (lateral_dist_between_objects(o, gMarioObject) < 127.5) {
                    o->oAction = 1;
                }
            }
            break;
        case 1:
            cur_obj_scale_over_time(2, 3, 1.5f, 0.2f);
            if (o->oTimer >= 3) {
                cur_obj_play_sound_2(SOUND_GENERAL2_PURPLE_SWITCH);
                o->oAction = 2;
                o->oF4 = 1;
                cur_obj_shake_screen(SHAKE_POS_SMALL);
                queue_rumble_data(5, 80);
            }
            break;
    }
}


void bhv_scale_flame_init(void) {
    if (o->oBehParams2ndByte) {
        cur_obj_scale((f32)o->oBehParams2ndByte / 10.0f);
    }
}

void bhv_env_flame_init(void) {
    o->os16F4 = (o->oBehParams >> 24) & 0xFF;
    o->os16F6 = (o->oBehParams >> 16) & 0xFF;
    o->os16F8 = (o->oBehParams >> 8) & 0xFF;

    o->os16FA = o->oRoom - 7;
    if (o->os16FA < 0) {
        o->activeFlags = 0;
    }
}

void bhv_env_flame_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oTimer > 10) {
                o->oAction = 1;
            }
            break;
        case 1:
            gRoomColors[o->os16FA][0] = approach_s16_symmetric(gRoomColors[o->os16FA][0], o->os16F4, 0x8);
            gRoomColors[o->os16FA][1] = approach_s16_symmetric(gRoomColors[o->os16FA][1], o->os16F6, 0x8);
            gRoomColors[o->os16FA][2] = approach_s16_symmetric(gRoomColors[o->os16FA][2], o->os16F8, 0x8);
            break;
    }
}

void bhv_boocoin_cage_init(void) {
    o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
    switch (o->oBehParams2ndByte) {
        case 0:
            o->oObj100 = spawn_object(o, MODEL_SMALL_KEY, bhvSmallKey);
            o->oObj100->oAction = 1;
            o->oObj100->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
            o->oObj100->oBehParams2ndByte = (o->oBehParams >> 8) & 0xFF;
            o->oObj100->oBehParams = o->oObj100->oBehParams2ndByte << 16;
            o->oObj100->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
            break;
        case 1:
            o->oObj100 = spawn_object(o, MODEL_STAR_CURRENCY, bhvStar);
            o->oObj100->oAction = 1;
            o->oObj100->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
            o->oObj100->oBehParams = o->oBehParams << 16;
            o->oObj100->oPosY += 80.0f;
            o->oObj100->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
            obj_scale(o, 1.8f);
            break;
        case 2:
            o->oObj100 = spawn_object(o, MODEL_STAR_PIECE, bhvStarPiece);
            o->oObj100->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
            o->oObj100->oBehParams = o->oBehParams << 16;
            o->oObj100->oPosY += 40.0f;
            o->oObj100->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
            break;
    }
    obj_set_hitbox(o, &sBooCoinCageHitbox);
}

void bhv_boocoin_cage_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            if (o->oF4 >= 5) {
                play_puzzle_jingle();
                if (o->oObj100 != NULL) {
                    o->oObj100->oIntangibleTimer = 0;
                }
                gCamera->comitCutscene = 7 + o->oBehParams2ndByte;
                if (o->oBehParams2ndByte == 2) {
                    gCamera->comitCutscene = 7;
                }
                gComitCutsceneObject = o;
                enable_time_stop();
                o->oAction = 1;
                o->oObjF8 = spawn_object(o, MODEL_NONE, bhvStaticObject);
                o->oObjF8->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
                vec3f_copy(&o->oFloatFC, gMarioState->pos);
                o->oFloat108 =  gMarioState->vel[1];
                o->oFloat10C = gMarioState->forwardVel;
                set_mario_npc_dialog(1);
            } else {
                if (o->oObj100 != NULL) {
                    o->oObj100->oIntangibleTimer = -1;
                }
            }
            break;
        case 1:
            set_mario_npc_dialog(1);
            vec3f_copy(gMarioState->pos, &o->oFloatFC);
            gMarioState->vel[1] = o->oFloat108;
            gMarioState->forwardVel = o->oFloat10C;
            if (o->oTimer == 15) {
                obj = spawn_object(o->oObjF8, MODEL_EXPLOSION, bhvExplosion);
                obj->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
                cur_obj_disable();
            }
            if (o->oTimer > 90) {
                gCamera->comitCutscene = 0;
                disable_time_stop();
                set_r_button_camera(gCamera);
                o->activeFlags = 0;
                set_mario_npc_dialog(0);
            }
            break;
    }
}



void bhv_boo_coin_init(void) {
   obj_set_hitbox(o, &sBooCoinHitbox);
}


void bhv_boo_coin_loop(void) {
    struct Object *obj = cur_obj_nearest_object_with_behavior(bhvBooCoinCage);
    struct Object *obj2;
    if (obj == NULL) {
        o->activeFlags = 0;
        return;
    }
    o->oFaceAngleYaw += 0x380;
    if (o->oInteractStatus) {
        obj2 = spawn_object(o, MODEL_SPARKLES, bhvGoldenCoinSparkles);
        obj2->oPosY -= 50.0f;
        o->activeFlags = 0;
        obj->oF4++;
        if (obj->oF4 != 5) {
            spawn_orange_number(obj->oF4, 0, 0, 0);
        }
        play_sound(SOUND_MENU_COLLECT_SECRET + (((u8) obj->oF4 - 1) << 16), gGlobalSoundSource);
    }
}


void bhv_deathwarp_init(void) {
    if (gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnLevel != 0) {
        s16 angle = gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnAngle;
        o->oPosX = (f32)gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnPos[0];
        o->oPosY = (f32)gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnPos[1];
        o->oPosZ = (f32)gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnPos[2];
        o->oFaceAngleYaw = o->oMoveAngleYaw = angle;
        o->oRoom = (gMarioPreviousRoom = gMarioCurrentRoom);
        vec3f_copy(sPreviousMarioPos, gMarioState->pos);
    }

}

void bhv_deathwarp_loop(void) {
    Vec3f pos;
    s16 angle;
    struct Surface *floor;
    struct MarioState *m = gMarioState;
    if (o->oTimer != 0 && gMarioCurrentRoom != gMarioPreviousRoom) {
        pos[0] = m->pos[0];
        pos[2] = m->pos[2];
        pos[1] = m->pos[1] + 50.0f;
        if (m->pos[0] == sPreviousMarioPos[0] && m->pos[2] == sPreviousMarioPos[2]) {
            angle = gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnAngle;
        } else {
            angle = atan2s(m->pos[2] - sPreviousMarioPos[2], m->pos[0] - sPreviousMarioPos[0]);
            if (absi((u16)(angle) - (u16)(angle & 0xE000)) < 0x1000) {
                angle &= 0xE000;
            } else {
                angle = (angle & 0xE000) + 0x2000;
            }
            pos[0] += + (sins(angle) * 150.0f);
            pos[2] += + (coss(angle) * 150.0f);
        }
        find_floor(pos[0], pos[1], pos[2], &floor);
        if (floor == NULL || floor->type == SURFACE_INSTANT_QUICKSAND 
            || floor->type == SURFACE_BURNING || floor->type == SURFACE_DEATH_PLANE) {
                return;
        }
        o->oFaceAngleYaw = o->oMoveAngleYaw = angle;
        vec3f_copy(&o->oPosX, pos);
        gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnPos[0] = (s16)pos[0];
        gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnPos[1] = (s16)pos[1];
        gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnPos[2] = (s16)pos[2];
        gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnLevel = gCurrLevelNum;
        gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnArea = gCurrAreaIndex;
        gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnAngle = angle;
    }
    o->oRoom = (gMarioPreviousRoom = gMarioCurrentRoom);
    vec3f_copy(sPreviousMarioPos, m->pos);
}


void bhv_broken_key_init(void) {
    o->oAnimState = (o->oBehParams >> 24) & 0xFF;
}

void bhv_broken_key_loop(void) {
    if ((o->oBehParams >> 24) == 1) {
        cur_obj_scale(0.5f);
        obj_set_hitbox(o, &sSmallKeyHitbox);
        if (o->oInteractStatus & INT_STATUS_INTERACTED) {
            o->activeFlags = 0;
            o->oInteractStatus = 0;
        }
    } else {
        cur_obj_scale(0.3f);
        if (o->oAngleVelYaw > 0x400)
            o->oAngleVelYaw -= 0x100;
        o->oFaceAngleYaw += o->oAngleVelYaw;
        //o->oFaceAngleRoll = -0x4000;
        //o->oGraphYOffset = 165.0f;
        if (o->oAction == 0) {
            o->oFaceAngleYaw += 0x400;
            if (o->oTimer == 0)
                o->oVelY = 70.0f;
            spawn_sparkle_particles(3, 200, 80, -60);
            spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(78);
            if (o->oMoveFlags & (OBJ_MOVE_ABOVE_DEATH_BARRIER | OBJ_MOVE_ABOVE_LAVA)) {
                vec3f_set(&o->oPosX, gMarioState->pos[0], gMarioState->pos[1] + 300.0f, gMarioState->pos[2]);
                o->oVelY = 0.0f;
                return;
            }
            if (o->oMoveFlags & OBJ_MOVE_ON_GROUND)
                o->oAction++;
            else if (o->oMoveFlags & OBJ_MOVE_LANDED)
                cur_obj_play_sound_2(SOUND_GENERAL_UNKNOWN3);
        } else {
            obj_set_hitbox(o, &sSmallKeyHitbox);
            o->oFaceAngleYaw += 0x400;
            if (o->oInteractStatus & INT_STATUS_INTERACTED) {
                o->activeFlags = 0;
                o->oInteractStatus = 0;
            }
        }
    }
}

void bhv_big_key_loop(void) {
    if (o->oAnimState == 1) {
        obj_set_hitbox(o, &sSmallKeyHitbox);
        o->oPosX = gMarioState->pos[0];
        o->oPosY = gMarioState->pos[1];
        o->oPosZ = gMarioState->pos[2];
        if (o->oInteractStatus & INT_STATUS_INTERACTED) {
            o->activeFlags = 0;
            o->oInteractStatus = 0;
        }
    }
    cur_obj_scale(0.3f);
    if (o->oAngleVelYaw > 0x400)
        o->oAngleVelYaw -= 0x100;
    o->oFaceAngleYaw += o->oAngleVelYaw;
    //o->oFaceAngleRoll = -0x4000;
    //o->oGraphYOffset = 165.0f;
    if (o->oAction == 0) {
        o->oFaceAngleYaw += 0x400;
        if (o->oTimer == 0)
            o->oVelY = 70.0f;
        spawn_sparkle_particles(3, 200, 80, -60);
        spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
        cur_obj_update_floor_and_walls();
        cur_obj_move_standard(78);
        if (o->oMoveFlags & (OBJ_MOVE_ABOVE_DEATH_BARRIER | OBJ_MOVE_ABOVE_LAVA)) {
            vec3f_set(&o->oPosX, gMarioState->pos[0], gMarioState->pos[1] + 300.0f, gMarioState->pos[2]);
            o->oVelY = 0.0f;
            return;
        }
        if (o->oMoveFlags & OBJ_MOVE_ON_GROUND)
            o->oAction++;
        else if (o->oMoveFlags & OBJ_MOVE_LANDED)
            cur_obj_play_sound_2(SOUND_GENERAL_UNKNOWN3);
    } else {
        obj_set_hitbox(o, &sSmallKeyHitbox);
        o->oFaceAngleYaw += 0x400;
        if (o->oInteractStatus & INT_STATUS_INTERACTED) {
            o->activeFlags = 0;
            o->oInteractStatus = 0;
        }
    }
}


void bhv_small_key_loop(void) {
    cur_obj_scale(0.3f);
    if (o->oAngleVelYaw > 0x400)
        o->oAngleVelYaw -= 0x100;
    o->oFaceAngleYaw += o->oAngleVelYaw;
    //o->oFaceAngleRoll = -0x4000;
    //o->oGraphYOffset = 165.0f;
    if (o->oAction == 0) {
        if (o->oBehParams >> 24 == 1) {
            o->oAction = 1;
            o->oFlags &= ~OBJ_FLAG_DISABLE_TO_ROOM_CLEAR;
            return;
        }
        if (o->oTimer == 0)
            o->oVelY = 70.0f;
        spawn_sparkle_particles(3, 200, 80, -60);
        spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
        cur_obj_update_floor_and_walls();
        cur_obj_move_standard(78);
        if (o->oMoveFlags & (OBJ_MOVE_ABOVE_DEATH_BARRIER | OBJ_MOVE_ABOVE_LAVA)) {
            vec3f_set(&o->oPosX, gMarioState->pos[0], gMarioState->pos[1] + 300.0f, gMarioState->pos[2]);
            o->oVelY = 0.0f;
            return;
        }
        if (o->oMoveFlags & OBJ_MOVE_ON_GROUND)
            o->oAction++;
        else if (o->oMoveFlags & OBJ_MOVE_LANDED)
            cur_obj_play_sound_2(SOUND_GENERAL_UNKNOWN3);
    } else {
        o->oFaceAngleYaw += 0x400;
        o->oGraphYOffset = sins(o->oFaceAngleYaw * 2) * 10.0f;
        obj_set_hitbox(o, &sSmallKeyHitbox);
        if (o->oInteractStatus & INT_STATUS_INTERACTED) {
            o->activeFlags = 0;
            o->oInteractStatus = 0;
        }
    }
}



void bhv_token_init(void) {
    u8 challenge;
    obj_set_hitbox(o, &sTokenHitbox);
    o->oDamageOrCoinValue = sTokenCoins[o->oBehParams2ndByte];
    challenge = (o->oBehParams >> 8) & 0xFF;
    if (save_file_get_challenges(challenge / 32) & (1 << (challenge % 32))) {
        o->activeFlags = 0;
    }
    o->os16F4 = o->oFaceAngleYaw;
}


void bhv_token_loop(void) {
    o->oGraphYOffset = 15.0f + (sins(o->os16F6) * 15.0f);
    if (o->oDistanceToMario < 350.0f || (o->oFaceAnglePitch == 0 && o->oFaceAngleRoll == 0 && o->oDistanceToMario < 2000.0f)) {
        o->oFaceAngleYaw += 0x400;
        o->os16F6 += 0x400;
    } else {
        o->os16F6 = approach_s16_symmetric(o->os16F6, 0, 0x300);
        o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, o->os16F4, 0x300);
    }

    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        cur_obj_play_sound_1(SOUND_PEACH_THANKS_TO_YOU);
        spawn_object(o, MODEL_SPARKLES, bhvGoldenCoinSparkles);
        o->activeFlags = 0;
        save_file_set_challenges((o->oBehParams >> 8) & 0xFF);
    }
}


void bhv_star_piece_init(void) {
    s8 pieceId = (o->oBehParams >> 24) & 0xFF;
    if (save_file_get_star_piece() & (1 << pieceId)) {
        o->activeFlags = 0;
    }

    o->os16F6 = 0x200;

    obj_set_hitbox(o, &sStarPieceHitbox);
}

extern u8 gDreamEnv;

void bhv_star_piece_loop(void) {
    s8 pieceId = (o->oBehParams >> 24) & 0xFF;
    if (save_file_get_star_piece() & (1 << pieceId)) {
        o->activeFlags = 0;
    }

    if (o->oDistanceToMario < 2000.0f) {
        cur_obj_play_sound_1(SOUND_AIR_PEACH_TWINKLE);
    }

    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        o->activeFlags = 0;
        o->oInteractStatus = 0;
        //save_file_set_star_piece(o->oBehParams >> 24);
    }

    if (o->oBehParams2ndByte == 1) {
        if (!(save_file_get_boos() & 1) && gCurrLevelNum == LEVEL_BOB) {
            cur_obj_disable();
        } else {
            cur_obj_enable();
        }
    } else {
        if (pieceId == 0x16) {
            if (gDreamEnv <= 240) {
                cur_obj_hide();
            } else {
                cur_obj_unhide();
            }
        }
        o->os16F8 += 0x300;
        o->oGraphYOffset = 20.0f + (sins(o->os16F8) * 20.0f);
        o->oFaceAngleYaw += 0x400;
        o->oFaceAnglePitch += o->os16F4;
        o->os16F4 = approach_s16_symmetric(o->os16F4, o->os16F6, 0x20);
        if (o->oTimer > 30) {
            o->os16F6 = CL_RandomMinMaxU16(0x300, 0x500);
        }
    }
}


void basic_npc_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oInteractStatus == INT_STATUS_INTERACTED) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x600);
            if ((s16) o->oMoveAngleYaw == (s16) o->oAngleToMario) {
                o->oAction = 2;
            }
            cur_obj_play_sound_2(SOUND_ACTION_READ_SIGN);
            break;
        case 2:
            if (CL_NPC_Dialog(o->oBehParams2ndByte)) {
                o->oAction = 0;
            }
            break;
    }
}


void toad_friend_l1_loop(void) {
    if (o->oF4) {
        switch (o->oAction) {
            case 0:
                if (o->oF4 == 1) {
                    set_mario_npc_dialog(1);
                    if (o->oTimer > 15) {
                        CL_Move();
                        if (o->oDistanceToMario > 300.0f) {
                            o->oForwardVel = 75.0f;
                        } else {
                            o->oForwardVel = 27.0f;
                        }
                        o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x1000);
                        o->oFaceAngleYaw = o->oMoveAngleYaw + 0x2000;
                        if (o->oDistanceToMario < 150.0f) {
                            o->oAction = 2;
                            o->oMoveAngleYaw = o->oAngleToMario - 0x2000;
                            o->oFaceAngleYaw = o->oMoveAngleYaw;
                            play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 20, 0, 0, 0);
                            play_music(0, SEQUENCE_ARGS(4, SEQ_PROF_T), 0);
                        }
                    }
                } else {
                    if (o->oInteractStatus == INT_STATUS_INTERACTED)
                        o->oAction = 1;
                }
                break;
            case 1:
                o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x1000);
                if ((s16) o->oMoveAngleYaw == (s16) o->oAngleToMario) {
                    o->oAction = 2;
                    play_music(0, SEQUENCE_ARGS(4, SEQ_PROF_T), 0);
                }

                cur_obj_play_sound_2(SOUND_ACTION_READ_SIGN);
                break;
            case 2:
                if (o->oTimer > 12) {
                    if (CL_NPC_Dialog(o->oBehParams2ndByte)) {
                        if (o->oF4 == 1) {
                            o->oBehParams2ndByte = 5;
                        }
                        o->oF4 = 2;
                        o->oAction = 0;
                        stop_background_music(SEQUENCE_ARGS(4, SEQ_PROF_T));
                    }
                }
                break;
        }
    }
    o->oInteractStatus = 0;
}


void toad_friend_portal_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oFC == 0) {
                if (o->oDistanceToMario < 600.0f) {
                    o->oAction = 1;
                    o->oFC = 1;
                }
            } else {
                if (o->oDistanceToMario > 800.0f) {
                    o->oFC == 0;
                }
            }
            break;
        case 1:
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x1000);
            if ((s16) o->oMoveAngleYaw == (s16) o->oAngleToMario) {
                o->oAction = 2;
                play_music(0, SEQUENCE_ARGS(4, SEQ_PROF_T), 0);
            }

            cur_obj_play_sound_2(SOUND_ACTION_READ_SIGN);
            break;
        case 2:
            if (o->oTimer > 12) {
                if (CL_NPC_Dialog(o->oBehParams2ndByte)) {
                    o->oAction = 0;
                    stop_background_music(SEQUENCE_ARGS(4, SEQ_PROF_T));
                }
            }
            break;
    }
    o->oInteractStatus = 0;
}

void toad_friend_cage_one(void) {
    switch (o->oAction) {
        case 0:
            if (o->oF8 == 0 && (save_file_get_newflags(1) & SAVE_TOAD_FLAG_PROF_CAGE_MSG) == 0) {
                if (gMarioState->pos[0] > -20500.0f) {
                    o->oAction = 1;
                    o->oF8 = 1;
                    save_file_set_newflags(SAVE_TOAD_FLAG_PROF_CAGE_MSG, 1);
                }
            } else {
                if (o->oInteractStatus == INT_STATUS_INTERACTED)
                    o->oAction = 1;
            }
            break;
        case 1:
            set_mario_npc_dialog(1);
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x1000);
            if ((s16) o->oMoveAngleYaw == (s16) o->oAngleToMario) {
                o->oAction = 2;
                play_music(0, SEQUENCE_ARGS(4, SEQ_PROF_T), 0);
            }

            cur_obj_play_sound_2(SOUND_ACTION_READ_SIGN);
            break;
        case 2:
            if (o->oTimer > 12) {
                if (CL_NPC_Dialog(DIALOG_062)) {
                    o->oAction = 0;
                    stop_background_music(SEQUENCE_ARGS(4, SEQ_PROF_T));
                }
            }
            break;
    }
    o->oInteractStatus = 0;
}



void toad_friend_cage_loop(void) {
    switch (o->oF4) {
        case 0:
            toad_friend_cage_one();
            if (save_file_get_boos() & (1 << 23)) {
                // o->oF8 = 0;
                o->oF4 = 1;
                o->oFaceAngleYaw = o->oMoveAngleYaw = 0xD000;
                vec3f_set(&o->oPosX, -9400.0f, 6847.0f, -2100.0f);
            }
            break;
        case 1:
            toad_friend_portal_loop();
            if (save_file_get_boos() & (1 << 24)) {
                o->activeFlags = 0;
            }
            break;
    }
}

void toad_friend_final_boss(void) {
    s32 dialogId;
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            o->oPosY += gMarioState->vel[1];
            if (o->oPosY <= 7416.0f) {
                o->oPosY = o->oHomeY = 7416.0f;
                o->oAction = 1;
            }
            break;
        case 1:
            o->oObjF4 = cur_obj_nearest_object_with_behavior(bhvBossCage);
            if (o->oObjF4 != NULL) {
                o->oAction = 2;

                while ((obj = cur_obj_nearest_object_with_behavior(bhvEndGoomba)) != NULL) {
                    obj->activeFlags = 0;
                }

                while ((obj = cur_obj_nearest_object_with_behavior(bhvEndShyguy)) != NULL) {
                    obj->activeFlags = 0;
                }
            }
            break;
        case 2:
            gCamera->comitCutscene = 27;
            gComitCutsceneObject = o;
            gComitCutsceneTimer = 22;
            if (o->oF8) {
                dialogId = DIALOG_074;
            } else {
                dialogId = DIALOG_073;
            }
            if (CL_NPC_Dialog(dialogId)) {
                o->oF8 = 1;
                o->oAction = 3;
                // gCamera->comitCutscene = 0;
                // stop_background_music(SEQUENCE_ARGS(4, SEQ_PROF_T));
                o->oObjF4->oAction = 1;
                o->oObjF4->oForwardVel = 120.0f;
                o->oObjF4->oVelY = 75.0f;
            }
            break;
        case 3:
            if (cur_obj_nearest_object_with_behavior(bhvBossCage) == NULL) {
                o->oAction = 1;
            }
            break;
        case 4:
            cur_obj_init_animation_with_sound(8);
            // if (o->oTimer > 40) {
            //     gCamera->comitCutscene = 30;
            //     gComitCutsceneObject = o;
            //     gComitCutsceneTimer = 20;
            // }
            break;
        case 5:
            if (o->oTimer > 15) {
                o->os16112 = 1;
            }
            break;
    }
}


extern Vec3f sToadFriendWarp1;

void bhv_friend_toad_loop(void) {
    switch (gCurrLevelNum) {
        case LEVEL_BOB:
            toad_friend_l1_loop();
            if (save_file_get_newflags(1) & SAVE_TOAD_FLAG_INTRODUCTION) {
                o->oF4 = 2;
            }
            if (save_file_get_newflags(1) & SAVE_TOAD_FLAG_FOUND_FIRST_BOO) {
                vec3f_copy(&o->oPosX, sToadFriendWarp1);
                o->oRoom = 13;
            }
            break;
        case LEVEL_SSL:
            if (gCurrAreaIndex == 1) {
                toad_friend_portal_loop();
            } else if (gCurrAreaIndex == 2) {
                toad_friend_cage_loop();
            }
            break;
        case LEVEL_DDD:
            toad_friend_final_boss();
            break;
    }
}



void bhv_friend_toad_init(void) {
        //o->oToadMessageDialogId = (o->oBehParams >> 24) & 0xFF;
        //o->oToadMessageRecentlyTalked = FALSE;
        //o->oToadMessageState = TOAD_MESSAGE_FADED;
        //o->oOpacity = 81;
        o->oInteractionSubtype = INT_SUBTYPE_NPC;
}

extern s32 gRedCoinMissionActive;

void bhv_prospector_t_init(void) {
    o->oInteractionSubtype = INT_SUBTYPE_NPC;

    switch (gCurrLevelNum) {
        case LEVEL_BOB:
            if (save_file_get_newflags(1) & SAVE_TOAD_FLAG_REDS1 || 
                (!(save_file_get_newflags(0) & (SAVE_NEW_FLAG_BROKEN1 | SAVE_NEW_FLAG_BROKEN2 | SAVE_NEW_FLAG_BROKEN3)))) {
                // o->activeFlags = 0;
            }

            o->os16F4 = 0;
            break;
        case LEVEL_WF:
            if (save_file_get_newflags(1) & SAVE_TOAD_FLAG_REDS2) {
                o->activeFlags = 0;
            }
            o->os16F4 = 1;
            break;
        case LEVEL_HMC:
            if (save_file_get_newflags(1) & SAVE_TOAD_FLAG_REDS3) {
                o->activeFlags = 0;
            }
            o->os16F4 = 2;
            break;
    }
    o->oBehParams2ndByte = DIALOG_078 + o->os16F4;
}


void bhv_prospector_t_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oInteractStatus == INT_STATUS_INTERACTED) {
                o->oAction = 1;
                if (gRedCoinMissionActive && o->os16F8 == 0) {
                    //check if hes gotten them
                    if (save_file_get_reds_star() & (1 << o->os16F4)) {
                        //change dialog id
                        if (o->os16F4 == 2) {
                            o->oBehParams2ndByte = DIALOG_083;
                        } else {
                            o->oBehParams2ndByte = DIALOG_082;
                        }
                        //set flag to give mario coins (after dialog)
                        o->os16F8 = 1;
                        //set save flag
                        save_file_set_newflags(SAVE_TOAD_FLAG_REDS1 << o->os16F4, 1);
                    }
                }
            }

            break;
        case 1:
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x1000);
            if ((s16) o->oMoveAngleYaw == (s16) o->oAngleToMario) {
                o->oAction = 2;
                play_music(0, SEQUENCE_ARGS(4, SEQ_PROF_T), 0);
            }

            cur_obj_play_sound_2(SOUND_ACTION_READ_SIGN);
            break;
        case 2:
            if (o->oTimer > 12) {
                if (CL_NPC_Dialog(o->oBehParams2ndByte)) {
                    o->oAction = 0;
                    stop_background_music(SEQUENCE_ARGS(4, SEQ_PROF_T));
                    if (o->os16F8 == 0) {
                        gRedCoinMissionActive = 1;
                        //CHANGE DIALOG ID
                        o->oBehParams2ndByte = DIALOG_081;
                    } else if (o->os16F8 == 1) {
                        gRedCoinMissionActive = 0;
                        o->os16F8 = 2;
                        gMarioState->numCoins += 1000;
                        if (o->os16F4 == 2) {
                            gMarioState->numCoins += 1000;
                        }
                    }
                }
            }
            break;
    }
    o->oInteractStatus = 0;
}

s32 gPoolLockDisabled = 0;

void bhv_prospector_lock_loop(void) {
    switch (o->oBehParams2ndByte) {
        case 0: // kitchen
            if (save_file_get_newflags(1) & SAVE_TOAD_FLAG_REDS1 || gRedCoinMissionActive || 
                (!(save_file_get_newflags(0) & (SAVE_NEW_FLAG_BROKEN1 | SAVE_NEW_FLAG_BROKEN2 | SAVE_NEW_FLAG_BROKEN3)))) {
                o->activeFlags = 0;
            }
            break;
        case 1: // pantry2
            if (save_file_get_newflags(0) & (SAVE_NEW_FLAG_BROKEN1 | SAVE_NEW_FLAG_BROKEN2 | SAVE_NEW_FLAG_BROKEN3)) {
                o->activeFlags = 0;
            }
            break;
        case 2: // pool room
            if (gPoolLockDisabled || save_file_get_newflags(1) & SAVE_TOAD_FLAG_REDS2 || gRedCoinMissionActive) {
                o->activeFlags = 0;
                gPoolLockDisabled = 1;
            }
            break;
        case 3: // panic room
            if (save_file_get_newflags(1) & SAVE_TOAD_FLAG_REDS1) {
                o->activeFlags = 0;
            }
            break;
        case 4: // attic2
            if (save_file_get_newflags(1) & SAVE_TOAD_FLAG_REDS2 && save_file_get_boos() & (1 << 0x12)) {
                o->activeFlags = 0;
            }
            break;
    }
}



void bhv_bparam1_to_animstate(void) {
    o->oAnimState = o->oBehParams >> 24;
}