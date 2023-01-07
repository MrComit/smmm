#include "game/save_file.h"
#include "buffers/buffers.h"
extern Vec3s gRoomColors[];
extern struct Object *gComitCutsceneObject;
void spawn_orange_number_three_digit_scale(u16 behParam, s16 relX, s16 relY, s16 relZ, f32 dist, f32 scale);
void spawn_orange_number_three_digit_scale_stay(u16 behParam, s16 relX, s16 relY, s16 relZ, f32 dist, f32 scale);

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

extern u8 sGoombaAttackHandlers[][6];

Vec3f sPreviousMarioPos = {0, 0, 0};

u8 sTokenCoins[3] = {10, 50, 100};


void bhv_golden_crate_init(void) {
    u8 challenge = (o->oBehParams >> 8) & 0xFF;
    if (save_file_get_challenges(challenge / 32) & (1 << (challenge % 32))) {
        o->activeFlags = 0;
    }
}


void bhv_golden_crate_loop(void) {
    obj_set_hitbox(o, &sGoldenCrateHitbox);
    if (cur_obj_was_attacked_or_ground_pounded() != 0) {
        obj_explode_and_spawn_coins(46.0f, 1);
        create_sound_spawner(SOUND_GENERAL_BREAK_BOX);
        save_file_set_challenges((o->oBehParams >> 8) & 0xFF);
        spawn_object(o, MODEL_GOLDEN_GOOMBA, bhvGoldenGoomba);
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


void golden_goomba_behavior(void) {
    f32 animSpeed;
    cur_obj_update_floor_and_walls();
    cur_obj_move_standard(-78);
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->os16112, 0x800);
    if (o->oMoveFlags & OBJ_MOVE_HIT_WALL) {
        o->os16112 = o->oWallAngle; 
    } else {
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
        spawn_orange_number_three_digit_scale_stay(o->os16110 / 10, 0, 0, 0, 50.0f * scale, 0.25f + scale);
    }
    o->os16110--;
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
        o->oPosX = (f32)gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnPos[0];
        o->oPosY = (f32)gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnPos[1];
        o->oPosZ = (f32)gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnPos[2];
        //vec3f_copy(gMarioState->pos, &o->oPosX);
    }

}

void bhv_deathwarp_loop(void) {
    Vec3f pos;
    s16 angle;
    struct MarioState *m = gMarioState;
    if (gMarioCurrentRoom != gMarioPreviousRoom) {
        angle = atan2s(m->pos[2] - sPreviousMarioPos[2], m->pos[0] - sPreviousMarioPos[0]);
        if (absi((u16)(angle) - (u16)(angle & 0xE000)) < 0x1000) {
            angle &= 0xE000;
        } else {
            angle = (angle & 0xE000) + 0x2000;
        }
        o->oFaceAngleYaw = angle;
        pos[0] = m->pos[0] + (sins(angle) * 150.0f);
        pos[2] = m->pos[2] + (coss(angle) * 150.0f);
        pos[1] = m->pos[1] + 50.0f;
        vec3f_copy(&o->oPosX, pos);
        gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnPos[0] = (s16)pos[0];
        gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnPos[1] = (s16)pos[1];
        gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnPos[2] = (s16)pos[2];
        gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnLevel = gCurrLevelNum;
        gSaveBuffer.files[gCurrSaveFileNum - 1][0].spawnArea = gCurrAreaIndex;
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
        if (o->oMoveFlags & OBJ_MOVE_ON_GROUND)
            o->oAction++;
        else if (o->oMoveFlags & OBJ_MOVE_LANDED)
            cur_obj_play_sound_2(SOUND_GENERAL_UNKNOWN3);
    } else {
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
    if (o->oDistanceToMario < 350.0f) {
        o->oFaceAngleYaw += 0x400;
        o->os16F6 += 0x400;
    } else {
        o->os16F6 = approach_s16_symmetric(o->os16F6, 0, 0x300);
        o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, o->os16F4, 0x300);
    }

    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
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
                    CL_Move();
                    o->oForwardVel = 22.0f;
                    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x1000);
                    o->oFaceAngleYaw = o->oMoveAngleYaw + 0x2000;
                    if (o->oDistanceToMario < 150.0f) {
                        o->oAction = 2;
                        play_music(0, SEQUENCE_ARGS(4, SEQ_PROF_T), 0);
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
                if (CL_NPC_Dialog(o->oBehParams2ndByte)) {
                    if (o->oF4 == 1) {
                        o->oBehParams2ndByte = 5;
                    }
                    o->oF4 = 2;
                    o->oAction = 0;
                    stop_background_music(SEQUENCE_ARGS(4, SEQ_PROF_T));
                }
                break;
        }
    }
    o->oInteractStatus = 0;
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
        case LEVEL_WF:
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


void bhv_bparam1_to_animstate(void) {
    o->oAnimState = o->oBehParams >> 24;
}