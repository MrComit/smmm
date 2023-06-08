#include "levels/ddd/header.h"
static struct ObjectHitbox sTheControllerHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 180,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 255,
    /* numLootCoins:      */ 0,
    /* radius:            */ 300,
    /* height:            */ 300,
    /* hurtboxRadius:     */ 300,
    /* hurtboxHeight:     */ 300,
};

struct ObjectHitbox sEndFistHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 320,
    /* height:            */ 880,
    /* hurtboxRadius:     */ 320,
    /* hurtboxHeight:     */ 880,
};


struct ObjectHitbox sEndBubbleHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 100,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 80,
    /* height:            */ 180,
    /* hurtboxRadius:     */ 80,
    /* hurtboxHeight:     */ 180,
};



static struct ObjectHitbox sEndLogHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 200,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 700,
    /* height:            */ 700,
    /* hurtboxRadius:     */ 700,
    /* hurtboxHeight:     */ 700,
};

static struct ObjectHitbox sEndSpikeHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 90,
    /* height:            */ 90,
    /* hurtboxRadius:     */ 90,
    /* hurtboxHeight:     */ 90,
};

static struct ObjectHitbox sBossCageHitbox = {
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

static struct ObjectHitbox sFakeMarioHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 3,
    /* numLootCoins:      */ 0,
    /* radius:            */ 37 + 120,
    /* height:            */ 160,
    /* hurtboxRadius:     */ 37 + 120,
    /* hurtboxHeight:     */ 160,
};

struct ObjectHitbox sEndBooHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 80,
    /* height:            */ 80,
    /* hurtboxRadius:     */ 80,
    /* hurtboxHeight:     */ 80,
};




enum FinalBossAttacks {
    FBA_BUBBLES,     // 0
    FBA_CAGE,        // 1
    FBA_LASER,       // 2
    FBA_LOGS,        // 3
    FBA_WALL,        // 4
    FBA_DROPPER,     // 5
    FBA_BOWSER,      // 6
};



Vec3f sEndBossMarioPoint = {1083.0f, 7406.0f, -4448.0f};

f32 sEndHoleWallSpeeds[] = {25.0f, 35.0f, 45.0f};

static void const *sHoleWallCollisions[] = {
    hole_wall1_collision,
    hole_wall2_collision,
    hole_wall3_collision,
    hole_wall4_collision,
    hole_wall5_collision,
};


void bhv_boss_objects_room(void) {
    o->oRoom = 1;
}


void bhv_hole_wall_init(void) {
   o->collisionData = segmented_to_virtual(sHoleWallCollisions[o->oBehParams2ndByte]);
   // cur_obj_scale(0.0f);
   o->header.gfx.scale[1] = 0.0f;
}



void bhv_hole_wall_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oPosZ += 8.0f;
            load_object_collision_model();
            o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 1.0f, 0.03f);
            // cur_obj_scale(o->oFloatF4);
            if (o->header.gfx.scale[1] == 1.0f) {
                o->oAction = 1;
            }
            break;
        case 1:
            load_object_collision_model();
            o->oPosZ += sEndHoleWallSpeeds[o->os16100];
            if (gMarioState->pos[2] < o->oPosZ - 200.0f || o->oPosZ > -3000.0f) {
                o->oAction = 2;
            }
            break;
        case 2:
            o->oPosZ += sEndHoleWallSpeeds[o->os16100] * 2.0f;
            o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 0.0f, 0.025f);
            // cur_obj_scale(o->oFloatF4);
            if (o->header.gfx.scale[1] == 0.0f) {
                o->activeFlags = 0;
                // o->parentObj->oObjF4 = NULL;
            }
            break;
    }
}



void bhv_end_boo_init(void) {
    f32 dist;
    s16 pitch, yaw;
    vec3f_get_dist_and_angle(&o->oPosX, gMarioState->pos, &dist, &pitch, &yaw);
    o->oFaceAngleYaw = o->oMoveAngleYaw = yaw;
    o->oFaceAnglePitch = o->oMoveAnglePitch = pitch;
    o->oForwardVel = 50.0f;

    obj_set_hitbox(o, &sEndBooHitbox);
}


void bhv_end_boo_loop(void) {
    CL_Move_3d();
    cur_obj_update_floor_and_walls();
    if (o->oMoveFlags & OBJ_MOVE_HIT_WALL || o->oMoveFlags & OBJ_MOVE_ON_GROUND 
    || o->oInteractStatus & INT_STATUS_INTERACTED || o->oTimer > 200) {
        // obj_explode_and_spawn_coins(46.0f, 0);
        // create_sound_spawner(SOUND_GENERAL_HAUNTED_CHAIR_MOVE);
        spawn_mist_particles();
        o->activeFlags = 0;
    }
}



void bhv_end_shyguy_loop(void) {
    struct Object *obj;
    // cur_obj_scale(o->oGoombaScale);
    cur_obj_update_floor_and_walls();
    // goomba_act_walk();

    cur_obj_play_sound_at_anim_range(2, 17, SOUND_OBJ_GOOMBA_WALK);

    o->os16F4 += 0xA00;
    o->oFaceAnglePitch = 0x400 * sins(o->os16F4) - 0x400;

    o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 40.0f, 2.0f);

    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, (s16)o->oDistanceToMario);
    cur_obj_move_standard(-78);
    if (o->oInteractStatus & INT_STATUS_INTERACTED || o->oTimer > 180) {
            spawn_mist_particles();
            o->activeFlags = 0;
            create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
    }
    o->oInteractStatus = 0;
}


void bhv_laser_shyguy_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            o->oObjF4 = spawn_object(o, MODEL_END_LASER, bhvEndLaser);
            obj_scale(o->oObjF4, 0.0f);
            o->oObjF4->oPosY += 50.0f;
            o->oAction = 1;

            // o->oFaceAngleYaw = 0x4000;
            o->os16F8 = 0x8000;
            break;
        case 1:
            if (o->oObjF4->header.gfx.scale[2] < 5.0f) {
                o->oObjF4->header.gfx.scale[2] = approach_f32_symmetric(o->oObjF4->header.gfx.scale[2], 5.0f, 0.05f);
                o->oObjF4->header.gfx.scale[0] = o->oObjF4->header.gfx.scale[2] / 5.0f;
                o->oObjF4->header.gfx.scale[1] = o->oObjF4->header.gfx.scale[0];

            } else {
                // o->oObjF4->oFaceAngleYaw = 0x1244;
                o->oAction = 2;
            }
            break;
        case 2:
            o->os16F8 += 0x180;
            if (o->os1610E == 0) {
                o->oFaceAngleYaw = 0x2000 * sins(o->os16F8);
            } else {
                o->oFaceAngleYaw = -0x2000 * sins(o->os16F8);
            }
            o->oObjF4->oFaceAngleYaw = o->oFaceAngleYaw;
            
            if (o->oInteractStatus & INT_STATUS_INTERACTED && o->oInteractStatus & INT_STATUS_WAS_ATTACKED || o->oTimer > 500) {
                if (o->oTimer <= 500) {
                    obj_force_spawn_loot_coins(o, 1, 20.0f, bhvSingleCoinGetsSpawned, 0, MODEL_YELLOW_COIN);
                }
                spawn_mist_particles();
                o->activeFlags = 0;
                if (o->os1610E == 0) {
                    o->parentObj->oObjF4 = NULL;
                } else {
                    o->parentObj->oObjF8 = NULL;
                }
                o->oObjF4->activeFlags = 0;
                create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
            }
            o->oInteractStatus = 0;
            break;
    }
}


void bhv_end_laser_loop(void) {
    //MARIO DISTANCE FROM LINE
    // f32 m = coss(o->oFaceAngleYaw) / (sins(o->oFaceAngleYaw) + 0.01f);
    // f32 b = o->oPosZ - (o->oPosX * m);
    // f32 e1 = absf((m * gMarioState->pos[0]) - gMarioState->pos[2] + b);
    // f32 d = e1 / sqrtf(m*m + 1);
    f32 zDif = (o->oPosZ - gMarioState->pos[2]) * sins(o->oFaceAngleYaw);
    f32 xDif = (o->oPosX - gMarioState->pos[0]) * coss(o->oFaceAngleYaw);
    f32 d = absf(zDif - xDif);
    f32 yDif = absf(gMarioState->pos[1] - o->oPosY);
    if (d < 70.0f && yDif < 70.0f && lateral_dist_between_objects(o, gMarioObject) > 150.0f && gMarioState->pos[2] > -9500.0f) {
        if (o->oTimer > 60) {
            CL_get_hit(gMarioState, gMarioObject, 1);
            // spawn_object(o, MODEL_SAWBLADE, bhvSawbladeShoot);
            o->oTimer = 0;
        }
    }
    o->oInteractStatus = 0;
}




void bhv_end_log_init(void) {
    o->oForwardVel = 37.0f;
    o->oFloatF8 = 45.0f;
    obj_set_hitbox(o, &sEndLogHitbox);
    // o->hitboxDownOffset = -50.0f;
    cur_obj_become_intangible();
}


void bhv_end_log_loop(void) {
    switch (o->oAction) {
        case 0:
            if ((o->parentObj->oBehParams >> 24) != 2) {
                o->oFloatF4 = approach_f32_symmetric(o->oFloatF4, 1.0f * 4.0f, 0.033f * 4.0f);
                o->oGraphYOffset = approach_f32_symmetric(o->oGraphYOffset, 30.0f * 4.0f, 1.0f * 4.0f);
            } else {
                o->oFloatF4 = approach_f32_symmetric(o->oFloatF4, 1.0f * 4.0f, 0.033f * 2.0f * 4.0f);
                o->oGraphYOffset = approach_f32_symmetric(o->oGraphYOffset, 30.0f * 4.0f, 2.0f * 4.0f);
            }
            cur_obj_scale(o->oFloatF4);
            if (o->parentObj->header.gfx.animInfo.animFrame == 50) {
                o->oAction = 1;
                o->parentObj->oInteractType = INTERACT_BOUNCE_TOP;
                cur_obj_become_tangible();
                cur_obj_play_sound_1(SOUND_OBJ_UNKNOWN4);
            }
            if (o->parentObj->activeFlags == 0) {
                o->activeFlags = 0;
            }
            break;
        case 1:
            o->oFloatF8 = approach_f32_symmetric(o->oFloatF8, 0.0f, 0.06f);
            o->oFaceAnglePitch += 0x600;
            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(0);
            if (o->oMoveFlags & OBJ_MOVE_ON_GROUND) {
                o->oVelY = o->oFloatF8;
                cur_obj_play_sound_1(SOUND_GENERAL_POUND_ROCK);
            }
            if (o->oMoveFlags & OBJ_MOVE_HIT_WALL) {
                obj_explode_and_spawn_coins(46.0f, 0);
                create_sound_spawner(SOUND_GENERAL_BREAK_BOX);
                o->activeFlags = 0;
                o->parentObj->oObjF4 = NULL;
            }

            break;
    }
    if (absf(gMarioState->pos[0] - o->oPosX) < 130.0f * 4.0f && absf(gMarioState->pos[1] - o->oPosY) < 28.0f * 4.0f 
        && absf(gMarioState->pos[2] - o->oPosZ) < 28.0f * 4.0f * 1.7f) {
        cur_obj_become_tangible();
    } else {
        cur_obj_become_intangible();
    }
    o->oInteractStatus = 0;
}


static u8 sEndSpikeAttackHandler[6] = {
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_KNOCKBACK,
};

void bhv_end_spike_init(void) {
    // obj_set_hitbox(o, &sEndSpikeHitbox);
    o->header.gfx.scale[1] = 0.0f;
}


void bhv_end_spike_loop(void) {
    struct Object *obj;
    f32 x, z, x2, z2;
    switch (o->oAction) {
        case 0:
            if (o->header.gfx.scale[1] < 1.25f) {
                o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 1.25f, 0.1f);
            }
            // if (o->oBehParams2ndByte && o->oDistanceToMario < 2750.0f) {
            //     o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x300);
            // }
            // x = absf((gMarioState->pos[0] - o->oPosX) * sins(o->oMoveAngleYaw + 0x4000));
            // z = absf((gMarioState->pos[2] - o->oPosZ) * coss(o->oMoveAngleYaw + 0x4000));
            // x2 = (gMarioState->pos[0] - o->oPosX) * sins(o->oMoveAngleYaw);
            // z2 = (gMarioState->pos[2] - o->oPosZ) * coss(o->oMoveAngleYaw);
            // if (x + z < 500.0f && x2 + z2 > 200.0f) {
                if (gMarioState->pos[2] > -9300.0f && (cur_obj_check_if_at_animation_end())) {
                    if ((o->oBehParams >> 24) == 2) {
                        cur_obj_init_animation_with_accel_and_sound(1, 2.0f);
                    } else {
                        cur_obj_init_animation_with_sound(1);
                    }
                    o->oAction = 1;

                }
            // }
            break;
        case 1:
            // if (x + z >= 300.0f || x2 + z2 <= 180) {
            //     o->oAction = 0;
            // }

            if (cur_obj_check_anim_frame(20)) {
                o->oObjF4 = spawn_object(o, MODEL_END_LOG, bhvEndLog);
                // o->prevObj->oPosY += 100.0f;
                o->oInteractType = INTERACT_DAMAGE;
            }
            if (cur_obj_check_anim_frame(61)) {
                o->oAction = 0;
                if ((o->oBehParams >> 24) == 2) {
                    cur_obj_init_animation_with_accel_and_sound(0, 2.0f);
                } else {
                    cur_obj_init_animation_with_sound(0);
                }
            }
            break;
    }


    // if (obj_handle_attacks(&sEndSpikeHitbox, o->oAction, sEndSpikeAttackHandler)) {
    //     mark_goomba_as_dead();
    // }
    obj_handle_attacks(&sEndSpikeHitbox, o->oAction, sEndSpikeAttackHandler);
    obj_update_standard_actions(1.0f);

    if (o->activeFlags == 0) {
        if (o->os16112 == 0) {
            obj_force_spawn_loot_coins(o, 1, 20.0f, bhvSingleCoinGetsSpawned, 0, MODEL_YELLOW_COIN);
        }
        o->parentObj->os16100++;
        // play_puzzle_jingle();
    }
    // o->header.gfx.scale[1] = 0.5f;
    // print_text_fmt_int(80, 80, "%x", (s32)o->prevObj, 0);
    // if (o->activeFlags == 0 && (o->oBehParams >> 24) & 0xFF) {
    //     obj = spawn_object(o, MODEL_ENV_FLAME, bhvTreehouseFlame);
    //     obj->oBehParams2ndByte = (o->oBehParams >> 24) - 1;
    // }
    o->oInteractStatus = 0;

}


f32 sEndBubbleSizes[] = {1.6f, 1.8f, 2.0f};


void bhv_end_bubble_init(void) {
    obj_set_hitbox(o, &sEndBubbleHitbox);
    // o->oForwardVel = 10.0f;
}

s32 end_bubble_oob_check(void) {
    if (o->oPosX > 5600.0f) {
        return TRUE;
    } else if (o->oPosX < -3600.0f) {
        return TRUE;
    }

    if (o->oPosZ > -3400.0f) {
        return TRUE;
    } else if (o->oPosZ < -11500.0f) {
        return TRUE;
    }
    return FALSE;
}


void bhv_end_bubble_loop(void) {
    o->os16F4 += 0x300;
    o->oGraphYOffset = 10.0f * sins(o->os16F4);
    CL_Move_3d();
    // print_text_fmt_int(80, 80, "%d", (s16)o->oForwardVel, 0);
    if (o->oTimer > o->os16F6) {
        CL_explode_object(o, 0);
        o->oFaceAnglePitch = o->oFaceAngleYaw = 0;
        if (o->oBehParams2ndByte == 0) {
            switch (CL_RandomMinMaxU16(0, 8)) {
                case 0:
                    obj_force_spawn_loot_coins(o, 1, 20.0f, bhvSingleCoinGetsSpawned, 0, MODEL_YELLOW_COIN);
                    break;
                case 1:
                    o->oObjF8 = spawn_object(o, MODEL_END_GOOMBA, bhvEndGoomba);
                    o->oObjF8->parentObj = o->oObjF8;
                    break;
                case 2:
                    spawn_object(o, MODEL_END_SHYGUY, bhvEndShyguy);
                    break;
                case 3:
                    spawn_object(o, MODEL_END_BOO, bhvEndBoo);
                    break;
            }
        } else {
            if (random_u16() & 1) {
                spawn_object(o, MODEL_END_SHYGUY, bhvEndShyguy);
            }
        }
        return;
    }
    if (o->oInteractStatus || (o->oTimer > o->os16F6 / 2 && end_bubble_oob_check())) {
        CL_explode_object(o, 0);
    }
}



void bhv_end_fist_init(void) {
    obj_set_hitbox(o, &sEndFistHitbox);
}


void bhv_end_fist_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oPosY = approach_f32_symmetric(o->oPosY, 7406.0f, 50.0f);
            if (o->oPosY == 7406.0f) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (o->oTimer > 25) {
                o->oPosY = approach_f32_symmetric(o->oPosY, 6400.0f, 65.0f);
                if (o->oPosY == 6400.0f) {
                    o->activeFlags = 0;
                }
            }
            break;
    }
}

s16 sEndCageTimers[] = {60, 50, 40};
f32 sEndCageSpeeds[] = {40.0f, 50.0f, 60.0f};

void bhv_end_cage_init(void) {
    o->oPosY = 6500.0f;
    o->oFaceAngleYaw = 0x4000 * CL_RandomMinMaxU16(0, 3);
}


void bhv_end_cage_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioObject->oAction == ACT_CUTSCENE_JUMP) {
                return;
            }
            o->oPosX = gMarioState->pos[0];
            o->oPosZ = gMarioState->pos[2];
            o->oPosY = approach_f32_symmetric(o->oPosY, 6806.0f, 15.0f);
            if (o->oPosY == 6806.0f) {
                o->oAction = 1;
                o->oFloatF4 = 5.0f;
            }
            break;
        case 1:
            if (o->oTimer < sEndCageTimers[o->os16100]) {
                o->oPosY += o->oFloatF4;
                o->oFloatF4 *= -1.0f;
                o->oPosX = gMarioState->pos[0];
                o->oPosZ = gMarioState->pos[2];
            } else if (o->oPosY != o->oHomeY) {
                o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, sEndCageSpeeds[o->os16100]);
                // if (o->oPosY == o->oHomeY) {
                // }
            } else if (o->os16102++ >= 5) {
                o->oObjF8 = spawn_object(o, MODEL_END_FIST, bhvEndFist);
                o->oObjF8->oPosY = 6400.0f;
                o->oAction = 2;
                // o->oObjF8->oHomeY = 7406.0f;
            }
            break;
        case 2:
            if (o->oTimer > 60) {
                o->oPosY = approach_f32_symmetric(o->oPosY, 6500.0f, 35.0f);
                if (o->oPosY == 6500.0f) {
                    o->parentObj->oObjF4 = NULL;
                    o->activeFlags = 0;
                }
            }
            break;
    }

}


void bhv_hole_wall_ground_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oTimer > 60) {
                o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY + 120.0f, 6.0f);
                if (o->oPosY == o->oHomeY + 120.0f) {
                    o->oAction = 1;
                }
            }
            break;
        case 1:
            if (o->parentObj->activeFlags == 0) {
                o->oAction = 2;
            }
            break;
        case 2:
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 8.0f);
            if (o->oPosY == o->oHomeY) {
                o->activeFlags = 0;
            }
            break;
    }
}



void bhv_mario_bowser_loop(void) {
    o->oFaceAngleYaw = o->oMoveAngleYaw = gMarioState->faceAngle[1];
    switch (o->oAction) {
        case 0:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 8);
            if (o->oOpacity == 255) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (o->oPosY > 7406.0f) {
                cur_obj_init_animation_with_sound(7);
                if (o->header.gfx.animInfo.animFrame < 7) {
                    o->header.gfx.animInfo.animFrame = 7;
                }
            } else if (o->oPosX != gMarioState->pos[0] || o->oPosZ != gMarioState->pos[2]) {
                cur_obj_init_animation_with_sound(15);
            } else {
                cur_obj_init_animation_with_sound(12);
            }
            break;
        case 2:
            cur_obj_init_animation_with_sound(12);
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 8);
            if (o->oOpacity == 0) {
                o->activeFlags = 0;
            }
            break;
    }
    vec3f_copy(&o->oPosX, gMarioState->pos);
}

s16 set_mario_animation_other(struct MarioState *m, s32 targetAnimID);
s16 set_mario_anim_with_accel_other(struct MarioState *m, s32 targetAnimID, s32 accel);

void bhv_fake_mario_init(void) {
    struct MarioState *m = gMarioState;
    o->oForwardVel = 20.0f;
    obj_set_hitbox(o, &sFakeMarioHitbox);
    m->flags |= MARIO_METAL_CAP;
    // m->marioBodyState->modelState |= MODEL_STATE_METAL;
    set_mario_animation_other(m, MARIO_ANIM_WALKING);
}

void bhv_fake_mario_loop(void) {
    struct MarioState *m = gMarioState;
    m->marioObj->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
    m->marioBodyState->punchState = 0;
    // print_text_fmt_int(80, 80, "%x", m->action, 0);
    cur_obj_update_floor_and_walls();
    cur_obj_move_standard(-78);
    switch (o->oAction) {
        case 0:
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x600);
            o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 28.0f, 1.6f);
            set_mario_anim_with_accel_other(m, MARIO_ANIM_RUNNING, (s32)(o->oForwardVel / 4.0f * 0x10000));
            if (o->oInteractStatus & INT_STATUS_INTERACTED && o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
                if (--o->oHealth <= 0) {
                    spawn_mist_particles();
                    o->activeFlags = 0;
                    m->flags &= ~MARIO_METAL_CAP;
                    create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
                } else {
                    o->oAction = 2;
                    o->oForwardVel = -30.0f;
                    cur_obj_become_intangible();
                    // o->oInteractType = INTERACT_DAMAGE;
                }
            }
            if (o->oTimer > 60 && o->oDistanceToMario < 500.0f && o->oPosY + 30.0f > gMarioState->pos[1]) {
                o->oAction = 1;
                o->oVelY = 40.0f;
            }
            break;
        case 1:
            o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 20.0f, 1.0f);
            if (o->oPosY <= 7410.0f) {
                o->oAction = 0;
            }
            set_mario_animation_other(m, MARIO_ANIM_SINGLE_JUMP);
            break;
        case 2:
            o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 0.0f, 1.0f);
            set_mario_animation_other(m, MARIO_ANIM_BACKWARD_KB);
            if (o->oTimer > 40) {
                o->oAction = 0;
                cur_obj_become_tangible();
                // o->oInteractType = INTERACT_BOUNCE_TOP;
            }
            break;
    }

    o->oInteractStatus = 0;
}


struct Object *sEndAttacks[4] = {
    NULL, NULL, NULL, NULL,
};


void controller_bubble_attack(void) {
    if (o->os16100++ > 90) {
        if (o->os16F8 < 25) {
            if (o->oTimer > 16) {
                o->oObjF4 = spawn_object(o, MODEL_END_BUBBLE, bhvEndBubble);
                o->oObjF4->oMoveAngleYaw = o->oAngleToMario + CL_RandomMinMaxU16(0, 0xC00) - 0x600;
                o->oObjF4->oMoveAnglePitch = CL_RandomMinMaxU16(0, 0x500);
                o->oObjF4->oForwardVel = CL_RandomMinMaxU16(24, 32);
                o->oObjF4->os16F6 = (CL_RandomMinMaxU16(580, 620) * 10.0f) / o->oObjF4->oForwardVel;
                o->oObjF4->oBehParams2ndByte = 0;
                o->oObjF4->oPosY -= 30.0f;

                if (o->parentObj->oOpacity <= 0x40) {
                    obj_scale(o->oObjF4, sEndBubbleSizes[2]);
                } else if (o->parentObj->oOpacity <= 0x80) {
                    obj_scale(o->oObjF4, sEndBubbleSizes[1]);
                } else {
                    obj_scale(o->oObjF4, sEndBubbleSizes[0]);
                }

                o->oTimer = 0;
                o->os16F8++;
            }
        } else {
            if (o->oTimer > 100) {
                o->activeFlags = 0;
                sEndAttacks[o->os16112] = NULL;
            }
        }
    } else {
        vec3f_copy(&o->oPosX, &o->parentObj->oPosX);
        o->oFaceAngleYaw = o->oMoveAngleYaw = o->parentObj->oMoveAngleYaw;
    }
}

void controller_cage_attack(void) {
    switch (o->oAction) {
        case 0:
            o->oObjF4 = spawn_object(o, MODEL_END_CAGE, bhvEndCage);
            o->oObjF4->oPosY = 7406.0f;
            o->oObjF4->oHomeY = 7406.0f;
            if (o->parentObj->oOpacity <= 0x40) {
                o->oObjF4->os16100 = 2;
            } else if (o->parentObj->oOpacity <= 0x40) {
                o->oObjF4->os16100 = 1;
            }
            o->oAction = 1;
            break;
        case 1:
            if (o->oObjF4 == NULL) {
                o->os16F8++;
                if (o->os16F8 >= 3) {
                    o->activeFlags = 0;
                    sEndAttacks[o->os16112] = NULL;
                }
                o->oAction = 0;
            }
            break;
    }
}

void controller_laser_attack(void) {
    f32 dist;
    s16 pitch, yaw;
    switch (o->oAction) {
        case 0:
            if (gMarioState->pos[1] <= gMarioState->floorHeight) {
                vec3f_get_dist_and_angle(gMarioState->pos, sEndBossMarioPoint, &dist, &pitch, &gMarioState->faceAngle[1]);
                mario_set_forward_vel(gMarioState, dist / 48.0f);
                gMarioState->vel[1] = 30.0f;
                set_mario_action(gMarioState, ACT_CUTSCENE_JUMP, 1);
                // o->oFloatFC = (dist * sins(gMarioState->faceAngle[1])) / 48;
                // o->oFloat100 = (dist * coss(gMarioState->faceAngle[1])) / 48;
                // gMarioState->faceAngle[1] = angle_to
                o->os16102 = 0x2490;

                o->oObjF4 = spawn_object(o, MODEL_END_SHYGUY, bhvShyguyLaser);
                vec3f_set(&o->oObjF4->oPosX, -437.0f, 7406.0f, -9740.0f);
                if (o->parentObj->oOpacity <= 0xC0) {
                    o->oObjF8 = spawn_object(o, MODEL_END_SHYGUY, bhvShyguyLaser);
                    o->oObjF8->os1610E = 1;
                    vec3f_set(&o->oObjF8->oPosX, 2563.0f, 7406.0f, -9740.0f);
                }
                o->oAction = 1;
            }
            break;
        case 1:
            if (o->oTimer <= 48) {
                set_mario_action(gMarioState, ACT_CUTSCENE_JUMP, 1);
                if (gMarioState->vel[1] < 0.0f) {
                    gMarioState->vel[1] = 0.0f;
                }
                o->os16102 += 0x492;
                gMarioState->pos[1] += sins(o->os16102) * 30.0f;
            }
            if (o->oObjF4 == NULL && o->oObjF8 == NULL) {
                o->activeFlags = 0;
                sEndAttacks[o->os16112] = NULL;
            }
            break;
    }
}

void controller_log_attack(void) {
    f32 dist;
    s16 pitch, yaw;
    switch (o->oAction) {
        case 0:
            if ((sEndAttacks[o->os16112 ^ 1] == NULL || sEndAttacks[o->os16112 ^ 1]->oBehParams2ndByte != FBA_LASER) &&
                 gMarioState->pos[1] <= gMarioState->floorHeight) {
                vec3f_get_dist_and_angle(gMarioState->pos, sEndBossMarioPoint, &dist, &pitch, &gMarioState->faceAngle[1]);
                mario_set_forward_vel(gMarioState, dist / 48.0f);
                gMarioState->vel[1] = 30.0f;
                set_mario_action(gMarioState, ACT_CUTSCENE_JUMP, 1);
                // o->oFloatFC = (dist * sins(gMarioState->faceAngle[1])) / 48;
                // o->oFloat100 = (dist * coss(gMarioState->faceAngle[1])) / 48;
                // gMarioState->faceAngle[1] = angle_to
                o->os16102 = 0x2490;
                o->os16108 = 1;
            }

            if (gMarioState->pos[1] <= gMarioState->floorHeight) {
                o->oObjF4 = spawn_object(o, MODEL_END_SPIKE, bhvEndSpike);
                vec3f_set(&o->oObjF4->oPosX, -937.0f, 7406.0f, -9610.0f);
                o->oObjF8 = spawn_object(o, MODEL_END_SPIKE, bhvEndSpike);
                vec3f_set(&o->oObjF8->oPosX, 1063.0f, 7406.0f, -9610.0f);
                o->oObjFC = spawn_object(o, MODEL_END_SPIKE, bhvEndSpike);
                vec3f_set(&o->oObjFC->oPosX, 3063.0f, 7406.0f, -9610.0f);

                o->oAction = 1;
            }
            break;
        case 1:
            if (o->os16108 && o->oTimer <= 48) {
                set_mario_action(gMarioState, ACT_CUTSCENE_JUMP, 1);
                if (gMarioState->vel[1] < 0.0f) {
                    gMarioState->vel[1] = 0.0f;
                }
                o->os16102 += 0x492;
                gMarioState->pos[1] += sins(o->os16102) * 30.0f;
            }

            if (o->oTimer > 500) {
                while ((o->oObjF4 = cur_obj_nearest_object_with_behavior(bhvEndSpike)) != NULL) {
                    o->oObjF4->activeFlags = 0;
                    o->oObjF4->os16112 = 1;
                    o->os16100++;
                }

                while ((o->oObjF4 = cur_obj_nearest_object_with_behavior(bhvEndLog)) != NULL) {
                    o->oObjF4->activeFlags = 0;
                }
            }

            if (o->os16100 >= 3) {
                o->activeFlags = 0;
                sEndAttacks[o->os16112] = NULL;
            }
            break;
    }
}

void controller_wall_attack(void) {
    f32 dist;
    s16 pitch, yaw;
    switch (o->oAction) {
        case 0:
            if (gMarioState->pos[1] <= gMarioState->floorHeight) {
                if (o->os16F8 == 0) {
                    vec3f_get_dist_and_angle(gMarioState->pos, sEndBossMarioPoint, &dist, &pitch, &gMarioState->faceAngle[1]);
                    mario_set_forward_vel(gMarioState, dist / 48.0f);
                    gMarioState->vel[1] = 30.0f;
                    set_mario_action(gMarioState, ACT_CUTSCENE_JUMP, 1);
                    // o->oFloatFC = (dist * sins(gMarioState->faceAngle[1])) / 48;
                    // o->oFloat100 = (dist * coss(gMarioState->faceAngle[1])) / 48;
                    // gMarioState->faceAngle[1] = angle_to
                    o->os16FA = 0x2490;
                    o->os16102 = -1;

                    o->oObj10C = spawn_object(o, MODEL_HOLE_WALL_GROUND, bhvHoleWallGround);
                    vec3f_set(&o->oObj10C->oPosX, 1083.0f, 7406.0f - 120.0f, -8568.0f);


                }
                o->oObjF4 = spawn_object(o, MODEL_HOLE_WALL, bhvHoleWall);
                do {
                    o->os16100 = CL_RandomMinMaxU16(0, 4);
                } while (o->os16100 == o->os16102);
                o->oObjF4->oBehParams2ndByte = o->os16100;
                o->os16102 = o->os16100;

                if (o->parentObj->oOpacity <= 0x40) {
                    o->oObjF4->os16100 = 2;
                } else if (o->parentObj->oOpacity <= 0x40) {
                    o->oObjF4->os16100 = 1;
                }

                vec3f_set(&o->oObjF4->oPosX, 1083.0f, 7406.0f, -10068.0f);
                o->oAction = 1;
            }
            break;
        case 1:
            if (o->os16F8 == 0 && o->oTimer <= 48) {
                set_mario_action(gMarioState, ACT_CUTSCENE_JUMP, 1);
                if (gMarioState->vel[1] < 0.0f) {
                    gMarioState->vel[1] = 0.0f;
                }
                o->os16FA += 0x492;
                gMarioState->pos[1] += sins(o->os16FA) * 30.0f;
            }
            if (o->oObjF4 == NULL || o->oObjF4->oAction == 2) {
                o->oAction = 0;
                o->os16F8++;
                if (o->os16F8 >= 3) {
                    // o->oObjF4 = cur_obj_nearest_object_with_behavior(bhvTheController);
                    // if (o->oObjF4 != NULL) {
                    //     o->oObjF4->os16108 = 1;
                    // }

                    o->activeFlags = 0;
                    sEndAttacks[o->os16112] = NULL;
                }
            }
            break;
    }
}

void controller_dropper_attack(void) {
    switch (o->oAction) {
        case 0:
            if (o->oTimer > 20) {
                o->oObjF4 = cur_obj_nearest_object_with_behavior(bhvRoofHole);
                if (o->oObjF4 != NULL) {
                    o->oObjF4->oF4 = 1;
                    o->oAction = 1;
                } else {
                    o->activeFlags = 0;
                    sEndAttacks[o->os16112] = NULL;
                }
            }
            break;
        case 1:
            if (o->oObjF4 == NULL || o->oObjF4->oF4 == 0) {
                o->activeFlags = 0;
                sEndAttacks[o->os16112] = NULL;
            }
            break;
    }
}

void controller_bowser_attack(void) {
    switch (o->oAction) {
        case 0:
            cur_obj_play_sound_2(SOUND_GENERAL_VANISH_SFX);
            o->oObjF4 = spawn_object(o, MODEL_MARIO, bhvFakeMario);
            // o->oObjF4 = spawn_object(o, MODEL_MARIO, bhvFakeMario);
            // o->oObjF4 = spawn_object(o, MODEL_MARIO, bhvFakeMario);
            o->oObjF8 = spawn_object(o, MODEL_BOWSER, bhvMarioBowser);

            o->oAction = 1;
            break;
        case 1:
            if (o->oObjF4 == NULL || o->oObjF4->activeFlags == 0) {
                if (o->oObjF8 != NULL) {
                    o->oObjF8->oAction = 2;
                }
                o->activeFlags = 0;
                sEndAttacks[o->os16112] = NULL;
            }
            break;
    }
}

void kill_small_enemies(void) {
    struct Object *obj;
    while ((obj = cur_obj_nearest_object_with_behavior(bhvEndGoomba)) != NULL) {
        obj->activeFlags = 0;
    }
    while ((obj = cur_obj_nearest_object_with_behavior(bhvEndShyguy)) != NULL) {
        obj->activeFlags = 0;
    }
    while ((obj = cur_obj_nearest_object_with_behavior(bhvEndBoo)) != NULL) {
        obj->activeFlags = 0;
    }
}

void bhv_roof_hole_loop(void) {
    struct MarioState *m = gMarioState;
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            if (o->oF4) {
                if (o->oTimer == 1) {
                    kill_small_enemies();
                }

                if (m->action != ACT_CUTSCENE_JUMP && m->action != ACT_QUICKSAND_DEATH) {
                    m->pos[0] = approach_f32_symmetric(m->pos[0], o->oPosX, 45.0f);
                    m->pos[2] = approach_f32_symmetric(m->pos[2], o->oPosZ, 45.0f);
                    m->faceAngle[1] = approach_s16_symmetric(m->faceAngle[1], 0x8000, 0x600);
                }
                if (o->oFC == 0 && m->pos[0] == o->oPosX && m->pos[2] == o->oPosZ) {
                    o->oFC = 1;
                }
                obj = cur_obj_nearest_object_with_behavior(bhvToadFriend);
                if (o->oFC == 2 || obj == NULL || obj->oF8 != 0) {
                    o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 9);
                }
            } else {
                o->oTimer = 0;
            }

            if (o->oOpacity > 20 || m->pos[0] != o->oPosX || m->pos[2] != o->oPosZ) {
                load_object_collision_model();
            } else if (o->oOpacity == 0 && m->pos[1] <= o->oPosY) {
                o->oAction = 1;
                kill_small_enemies();
                // m->faceAngle[1] = 0x8000;
                set_mario_action(m, ACT_IDLE, 0);
                m->forwardVel = 0.0f;
            }
            break;
        case 1:
            gCamera->comitCutscene = 26;
            if (o->oTimer > 90 && m->pos[1] > 7000.0f && m->pos[0] < 15000.0f) {
                o->oAction = 2;
                o->oOpacity = 255;
            }
            break;
        case 2:
            gCamera->comitCutscene = 26;
            load_object_collision_model();
            if (m->pos[1] < 11000.0f) {
                gCamera->comitCutscene = 0;
                o->oAction = 0;
                o->oF4 = 0;
            }
            break;

    }
}


void bhv_attack_manager_init(void) {
    
}


void bhv_attack_manager_loop(void) {
    switch (o->oBehParams2ndByte) {
        case FBA_BUBBLES:
            controller_bubble_attack();
            break;
        case FBA_CAGE:
            controller_cage_attack();
            break;
        case FBA_LASER:
            controller_laser_attack();
            break;
        case FBA_LOGS:
            controller_log_attack();
            break;
        case FBA_WALL:
            controller_wall_attack();
            break;
        case FBA_DROPPER:
            controller_dropper_attack();
            break;
        case FBA_BOWSER:
            controller_bowser_attack();
            break;
    }
}




void cage_held_loop(void) {
    cur_obj_become_intangible();
    o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
    // o->oFC = 0;
    cur_obj_set_pos_relative(gMarioObject, 0, 60.0f, 60.0f);

    if (o->oObj108->oDistanceToMario < 1800.0f) {
        if (o->oObj100 == NULL) {
            o->oObj100 = spawn_object(o, MODEL_CAGE_BEAM, bhvBossCageBeam);
        }
    } else {
        if (o->oObj100 != NULL) {
            o->oObj100->activeFlags = 0;
            o->oObj100 = NULL;
        }
    }

    o->oFC = 1;
    // o->os16F4 = approach_s16_symmetric(o->os16F4, 0xFF, 0x10);
    // o->os16F6 = approach_s16_symmetric(o->os16F6, 0xBD, 0x10);
    // o->os16FA = o->header.gfx.animInfo.animFrame;
}

void cage_dropped_loop(void) {
    cur_obj_get_dropped();
    cur_obj_become_tangible();

    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    //cur_obj_init_animation(0);

    //o->oFC = 1;
    o->oFC = 1;
    o->oHeldState = 0;
    //o->oAction = 0;
}


void cage_free_loop(void) {
    object_step();

    if (o->oFC) {
        CL_explode_object(o, 1);
    }
    // o->header.gfx.animInfo.animFrame = o->os16FA;
    // o->os16F4 = approach_s16_symmetric(o->os16F4, 0x99, 0x10);
    // o->os16F6 = approach_s16_symmetric(o->os16F6, 0x71, 0x10);

    // if (sObjFloor != NULL && (sObjFloor->type == SURFACE_BURNING || sObjFloor->type == SURFACE_INSTANT_QUICKSAND)) {
    //     o->os16FC = 1;
    // } 
    
    // if (o->oPosY > 0.0f && gMarioState->pos[1] < -150.0f) {
    //     if (++o->os16110 > 45) {
    //         o->os16FC = 1;
    //     }
    // } else {
    //     o->os16110 = 0;
    // }

    // if (o->os16FC == 1) {
    //     o->os16FE++;
    //     if (o->os16FE > 10) {
    //         o->header.gfx.scale[0] -= 0.05f;
    //         o->header.gfx.scale[1] = o->header.gfx.scale[2] = o->header.gfx.scale[0];
    //     }
    //     if (o->os16FE > 30) {
    //         o->os16FE = 0;
    //         o->oHeldState = 0;
    //         vec3f_copy(&o->oPosX, &o->oHomeX);
    //         o->oFaceAngleYaw = 0;
    //         o->os16FC = 0;
    //         o->header.gfx.scale[1] = o->header.gfx.scale[2] = o->header.gfx.scale[0] = 1.0f;
    //     }
    // }
}



void bhv_boss_cage_init(void) {
    // o->oGravity = 2.5;
    // o->oFriction = 0.8;
    // o->oBuoyancy = 1.3;
    // o->os16F4 = 0x99;
    // o->os16F6 = 0x71;
    // o->os16F8 = 0;
    // o->os16FA = 0;
    obj_set_hitbox(o, &sBossCageHitbox);

    o->oObj108 = cur_obj_nearest_object_with_behavior(bhvTheController);
    spawn_mist_particles();
}


void bhv_boss_cage_loop(void) {
    if (o->oAction == 1) {
        CL_Move();
        o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 0.0f, 0.1f);
        if (o->oPosY <= 7406.0f) {
            o->oAction = 2;
            o->oForwardVel = 0.0f;
            o->oVelY = 0.0f;
            o->oGravity = 2.5;
            o->oFriction = 0.8;
            o->oBuoyancy = 1.3;
        }
    } else if (o->oAction == 2) {
        switch (o->oHeldState) {
            case HELD_FREE:
                cage_free_loop();
                break;

            case HELD_HELD:
                cage_held_loop();
                break;
            case HELD_THROWN:
            case HELD_DROPPED:
                cage_dropped_loop();
                break;
        }
    }
}

void bhv_boss_cage_beam_init(void) {
    o->oObjF4 = cur_obj_nearest_object_with_behavior(bhvTheController);
}


void bhv_boss_cage_beam_loop(void) {
    f32 dist;
    s16 pitch, yaw;
    if (o->parentObj->activeFlags == 0 || o->parentObj->oHeldState != HELD_HELD) {
        o->activeFlags = 0;
        return;
    }
    vec3f_set(&o->oPosX, o->parentObj->oPosX, o->parentObj->oPosY + 40.0f, o->parentObj->oPosZ);
    vec3f_get_dist_and_angle(&o->oPosX, &o->oObjF4->oPosX, &dist, &pitch, &yaw);
    o->oFaceAngleYaw = yaw;
    o->oFaceAnglePitch = -pitch;
    o->header.gfx.scale[2] = dist / 10.0f;
}

/*
BOSS STRUCTURE PLAN:

in one act: he decides which attack(s) to use
in the next act: he waits for those attacks to end

    -a separate entity should carry out the attacks.
        -a generic attack handler bhv, with a bparam2 switch case?


*/

#define CONTROLLER_ACT_INTRO   0
#define CONTROLLER_ACT_DEFAULT 1
#define CONTROLLER_ACT_ATTACKS 2
#define CONTROLLER_ACT_SWIPE   3
#define CONTROLLER_ACT_RUN     4
#define CONTROLLER_ACT_RUN_END 5
#define CONTROLLER_ACT_DEATH   6


void controller_pos_constrain(void) {
    struct Object *obj;
    s8 val = 0;
    s16 yaw;
    if (o->oPosX > 5600.0f) {
        o->oPosX = 5600.0f;
    } else if (o->oPosX < -3600.0f) {
        o->oPosX = -3600.0f;
    }
    if (o->oPosZ > -3400.0f) {
        o->oPosZ = -3400.0f;
    } else if (o->oPosZ < -11500.0f) {
        o->oPosZ = -11500.0f;
    }

    if (o->oPosX > 3411.0f) {
        val = 2;
    } else if (o->oPosX < -1256.0f) {
        val = 4;
    }
    if (o->oPosZ > -5148.0f) {
        val = 1;
    } else if (o->oPosZ < -9815.0f) {
        val = 3;
    }


    if (val) {
        // yaw = (val-1) * 0x4000;
        // if (o->oMoveAngleYaw > yaw) {
        //     o->os16F6 = yaw + 0x5C00;
        // } else {
        //     o->os16F6 = yaw - 0x5C00;
        // }
        obj = cur_obj_nearest_object_with_behavior(bhvRoofHole);
        if (obj != NULL) {
            o->os16F6 = obj_angle_to_object(o, obj);
        }
    }
}

void bhv_bg_ground_center_loop(void) {
    if (cur_obj_nearest_object_with_behavior(bhvBossCage) == NULL && 
        (sEndAttacks[0] == NULL || sEndAttacks[0]->oBehParams2ndByte != FBA_DROPPER) &&
        (sEndAttacks[1] == NULL || sEndAttacks[1]->oBehParams2ndByte != FBA_DROPPER)) {
        o->o100 = o->oAction;
        bhv_bg_ground_loop();
        if (gMarioState->action != ACT_CUTSCENE_JUMP) {
            load_object_collision_model();
        }
        cur_obj_unhide();
    } else {
        o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 60.0f);
        if (o->oPosY == o->oHomeY) {
            cur_obj_hide();
        }
    }
}


void bhv_bg_ground_init(void) {
    o->oObjF4 = spawn_object(o, MODEL_BG_GROUND_CENTER, bhvBGGroundCenter);
    o->oObjF4->oHomeY = o->oHomeY;
    o->oObjF4->parentObj = o->parentObj;
}


void bhv_bg_ground_loop(void) {
    // if (gMarioState->action != ACT_CUTSCENE_JUMP && o->oFloatFC != 0) {
    //     load_object_collision_model();
    // }
    switch (o->oAction) {
        case 0:
            // o->oPosY = o->oHomeY + 300.0f;
            if (o->parentObj->oOpacity <= 0xC0 && o->parentObj->oAction == CONTROLLER_ACT_DEFAULT) {
                o->oAction = 1;
                o->oFloatFC = 250.0f;
            }
            break;
        case 1:
            if (o->parentObj->oOpacity <= 0x80 && o->parentObj->oAction == CONTROLLER_ACT_DEFAULT) {
                o->oAction = 2;
                o->oFloatFC += 100.0f;
            }
            break;
        // case 2:
        //     if (o->parentObj->oOpacity <= 0x40 && o->parentObj->oAction == CONTROLLER_ACT_DEFAULT) {
        //         o->oAction = 3;
        //         o->oFloatFC += 100.0f;
        //     }
        //     break;
    }
    o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY + o->oFloatFC, 15.0f);
    if (o->oAction != o->o100) {
        if (o->oPosY == o->oHomeY + o->oFloatFC) {
            load_object_static_model();
            o->o100 = o->oAction;
        }
    }
}

void bhv_the_controller_init(void) {
    // sEndAttacks[0] = spawn_object(o, MODEL_NONE, bhvFinalBossAttacks);
    // sEndAttacks[0]->oBehParams2ndByte = FBA_DROPPER;
    // sEndAttacks[0]->os16112 = 0;
    // sEndAttacks[1] = spawn_object(o, MODEL_NONE, bhvFinalBossAttacks);
    // sEndAttacks[1]->oBehParams2ndByte = FBA_LASER;
    // sEndAttacks[1]->os16112 = 1;
    cur_obj_scale(0.0f);
    o->oHomeY -= 1500.0f;

    o->oObj108 = spawn_object(o, MODEL_BG_GROUND, bhvBGGround);
    vec3f_set(&o->oObj108->oPosX, 1083.0f, 7406.0f - 340.0f, -8568.0f);

    o->os1610C = -1;
    o->oFloatFC = 255.0f;
    obj_set_hitbox(o, &sTheControllerHitbox);
}


s32 boss_attacks_finished(void) {
    if (sEndAttacks[0] == NULL && sEndAttacks[1] == NULL
        && sEndAttacks[2] == NULL && sEndAttacks[3] == NULL) {
            return TRUE;
        }
    return FALSE;
}


void boss_spawn_arena_bubbles(s32 rate) {
    struct Object *obj;
    s16 randomYaw;
    s32 timer = rate ? 110 : 70;
    if (o->os1610E++ > timer) {
        obj = spawn_object(o, MODEL_END_BUBBLE, bhvEndBubble);

        randomYaw = random_u16();
        vec3f_set(&obj->oPosX, 1081.0f + (6000.0f * sins(randomYaw)), 7656.0f, -7477.0f + (6000.0f * coss(randomYaw)));

        obj->oMoveAngleYaw = (s16)(randomYaw + 0x8000) + CL_RandomMinMaxU16(0, 0x1000) - 0x800;
        obj->oMoveAnglePitch = CL_RandomMinMaxU16(0, 0x500);
        obj->oForwardVel = CL_RandomMinMaxU16(24, 32);
        obj->os16F6 = (CL_RandomMinMaxU16(710, 840) * 10.0f) / obj->oForwardVel;
        obj->oBehParams2ndByte = 0;
        // obj->oPosY -= 30.0f;

        if (o->oOpacity <= 0x40) {
            obj_scale(obj, sEndBubbleSizes[2]);
        } else if (o->oOpacity <= 0x80) {
            obj_scale(obj, sEndBubbleSizes[1]);
        } else {
            obj_scale(obj, sEndBubbleSizes[0]);
        }

        o->os1610E = 0;
    }
}


void controller_act_attacks(void) {
    struct Object *obj;
    f32 posY;
    if (o->oTimer == 0) {
        sEndAttacks[0] = spawn_object(o, MODEL_NONE, bhvFinalBossAttacks);
        do {
            sEndAttacks[0]->oBehParams2ndByte = CL_RandomMinMaxU16(0, 6);
        } while (sEndAttacks[0]->oBehParams2ndByte == o->os1610C);
        o->os1610C = sEndAttacks[0]->oBehParams2ndByte;
        sEndAttacks[0]->os16112 = 0;

        obj = cur_obj_nearest_object_with_behavior(bhvToadFriend);
        if (obj != NULL && obj->oF8 == 0) {
            switch (o->os16104) {
                case 0:
                    sEndAttacks[0]->oBehParams2ndByte = FBA_BUBBLES;
                    break;
                case 1:
                    sEndAttacks[0]->oBehParams2ndByte = FBA_LASER;
                    break;
                case 2:
                    sEndAttacks[0]->oBehParams2ndByte = FBA_DROPPER;
                    o->oSubAction = 2;
                    break;
            }
        }
        // sEndAttacks[0]->oBehParams2ndByte = FBA_BOWSER;

        if (sEndAttacks[0]->oBehParams2ndByte == FBA_BUBBLES) {
            o->oSubAction = 1;
        }

        if ((o->oOpacity <= 0x80 && sEndAttacks[0]->oBehParams2ndByte < 5) || 
            (o->oOpacity <= 0xC0 && sEndAttacks[0]->oBehParams2ndByte == FBA_BUBBLES)) {
            sEndAttacks[1] = spawn_object(o, MODEL_NONE, bhvFinalBossAttacks);
            sEndAttacks[1]->os16112 = 1;

            do {
                sEndAttacks[1]->oBehParams2ndByte = CL_RandomMinMaxU16(0, 4);
            } while (boss_attacks_incompatible());

            if (sEndAttacks[1]->oBehParams2ndByte == FBA_BUBBLES) {
                o->oSubAction = 1;
            }
        }
    }

    if (o->oSubAction == 0) {
        o->os16102 += 0x180;
        posY = o->oHomeY + 100.0f + (150.0f * coss(o->os16102 / 3));
        o->oPosY = approach_f32_symmetric(o->oPosY, posY, 15.0f);
        o->oPosX = o->oHomeX + (1200.0f * coss(o->os16102));
        o->oPosZ = o->oHomeZ + (300.0f * sins(o->os16102));
    } else {
        o->oPosX = approach_f32_symmetric(o->oPosX, o->oHomeX, 80.0f);
        o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 20.0f);
        o->oPosZ = approach_f32_symmetric(o->oPosZ, o->oHomeZ, 40.0f);

        if (o->oSubAction == 2) {
            obj = cur_obj_nearest_object_with_behavior(bhvRoofHole);
            if (obj != NULL && obj->oFC == 1) {
                if (CL_NPC_Dialog(DIALOG_075)) {
                    o->oSubAction = 3;
                    obj->oFC = 2;
                }
            }
        }
    }

    if ((sEndAttacks[0] == NULL || (sEndAttacks[0]->oBehParams2ndByte != FBA_BUBBLES 
        && sEndAttacks[0]->oBehParams2ndByte != FBA_DROPPER)) && (sEndAttacks[1] == NULL || 
        sEndAttacks[1]->oBehParams2ndByte != FBA_BUBBLES)) {
            boss_spawn_arena_bubbles(0);
        }

    if (boss_attacks_finished()) {
        o->oAction = CONTROLLER_ACT_DEFAULT;
        o->oSubAction = 0;
        o->os16104++;
    }
}


void controller_act_run(void) {
    struct Object *obj;
    f32 dist;
    s16 pitch, yaw;
    s16 angle;
    Vec3f hitboxPos;
    //ANGLE
    obj = cur_obj_nearest_object_with_behavior(bhvRoofHole);
    if (obj != NULL) {
        o->os16100 = obj_angle_to_object(o, obj);
        angle = obj_angle_to_object(gMarioObject, obj);
        if (angle < o->os16100) {
            o->os16100 -= 0x4000;
        } else {
            o->os16100 += 0x4000;
        }
    }
    controller_pos_constrain();
    o->os16F6 = approach_s16_symmetric(o->os16F6, o->os16100, 0x130);
    o->oMoveAngleYaw = approach_s16_symmetric((s16)o->oMoveAngleYaw, o->os16F6, 0x600);

    //YPOS
    o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 20.0f);

    //SPEED
    if (o->oDistanceToMario > 2700.0f) {
        o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 14.0f, 0.7f);
    } else if (o->oSubAction == 0) {
        o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 22.0f, 0.7f);
    }
    CL_Move();

    //ATTACKS
        //BUBBLES
    if (o->oTimer > o->os16F8) {
        o->oTimer = 0;
        o->os16F8 = CL_RandomMinMaxU16(30, 100);

        obj = spawn_object(o, MODEL_END_BUBBLE, bhvEndBubble);
        obj->oPosY -= 40.0f;
        obj->oMoveAngleYaw = o->oAngleToMario + CL_RandomMinMaxU16(0, 0x800) - 0x400;
        obj->oMoveAnglePitch = CL_RandomMinMaxU16(0, 0x600);
        obj->oForwardVel = CL_RandomMinMaxU16(12, 18);
        obj->os16F6 = CL_RandomMinMaxU16(120, 160);
        obj->oBehParams2ndByte = 1;

        if (o->oOpacity <= 0x40) {
            obj_scale(obj, sEndBubbleSizes[2]);
        } else if (o->oOpacity <= 0x80) {
            obj_scale(obj, sEndBubbleSizes[1]);
        } else {
            obj_scale(obj, sEndBubbleSizes[0]);
        }

        switch (CL_RandomMinMaxU16(0, 1)) {
            case 0:
                obj = spawn_object(o, MODEL_END_GOOMBA, bhvEndGoomba);
                obj->parentObj = obj;
                break;
            case 1:
                obj = spawn_object(o, MODEL_END_SHYGUY, bhvEndShyguy);
                break;
        }
        vec3f_set(&obj->oPosX, o->oPosX + (1600.0f * sins(o->oAngleToMario + 0x8000)), 
                    7406.0f, o->oPosZ + (1600.0f * coss(o->oAngleToMario + 0x8000)));

    }
        //SWIPE
    if (o->oSubAction == 0) {
        o->oFaceAngleYaw = o->oMoveAngleYaw;
        if (o->oDistanceToMario < 1800.0f && cur_obj_check_if_at_animation_end() && CL_RandomMinMaxU16(0, 2)) {
            o->oSubAction = 1;
            cur_obj_init_animation_with_sound(1);
        }
    } else {
        if (o->header.gfx.animInfo.animFrame < 50) {
            o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 1.4f, 0.02f);
            cur_obj_scale(o->header.gfx.scale[0]);
            o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, o->oAngleToMario, 0xA00);
            o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 5.0f, 1.0f);
        } else if (o->header.gfx.animInfo.animFrame <= 66) {
            o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, (s16)(o->oMoveAngleYaw + 0x8000), 0xA00);
            hitboxPos[1] = gMarioState->pos[1];
            hitboxPos[0] = o->oPosX + (sins(o->oFaceAngleYaw) * 350.0f);
            hitboxPos[2] = o->oPosZ + (coss(o->oFaceAngleYaw) * 350.0f);
            vec3f_get_dist_and_angle(hitboxPos, gMarioState->pos, &dist, &pitch, &yaw);
            if (dist < 500.0f && absf(gMarioState->pos[1] - o->oPosY) < 600.0f) {
                CL_get_hit(gMarioState, o, 2);            
            }
        } else {
            o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 1.0f, 0.06f);
            cur_obj_scale(o->header.gfx.scale[0]);
            o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, (s16)(o->oMoveAngleYaw), 0xA00);
            o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 22.0f, 1.3f);
            if (cur_obj_check_if_at_animation_end()) {
                o->oSubAction = 0;
                cur_obj_init_animation_with_sound(0);
            }
        }
    }

    //HEALTH/OPACITY
    if (o->oDistanceToMario < 1800.0f) {
        o->oFloatFC -= 0.16f;
        o->oOpacity = (s16)o->oFloatFC;
    }
    // print_text_fmt_int(80, 80, "%d", o->oOpacity, 0);
    if (o->oOpacity <= o->os16FA - 0x48 || gMarioState->heldObj == NULL) {
        o->oAction = CONTROLLER_ACT_RUN_END;
        kill_small_enemies();
        obj = cur_obj_nearest_object_with_behavior(bhvBossCage);
        if (obj != NULL) {
            // obj->oInteractionSubtype |= INT_SUBTYPE_DROP_IMMEDIATELY;
            set_mario_action(gMarioState, ACT_PLACING_DOWN, 0);
            obj->oFC = 1;
        }
    }
    
    if (o->oOpacity <= 0) {
        o->oAction = CONTROLLER_ACT_DEATH;
        vec3f_set(&o->oPosX, 1081.0f, 7556.0f, -7477.0f);
        o->oFaceAngleYaw = o->oMoveAngleYaw = 0;
        o->oFloatF4 = 0.0f;
        kill_small_enemies();
    }

    if (o->oAction != CONTROLLER_ACT_RUN) {
        o->oSubAction = 0;
    }
}


void controller_act_run_end(void) {
    Vec3f hitboxPos;
    f32 dist;
    s16 pitch;
    if (o->oSubAction == 0) {
        if (gMarioState->pos[1] <= gMarioState->floorHeight && gMarioState->action != ACT_PLACING_DOWN) {
            vec3f_get_dist_and_angle(gMarioState->pos, sEndBossMarioPoint, &dist, &pitch, &gMarioState->faceAngle[1]);
            mario_set_forward_vel(gMarioState, dist / 48.0f);
            gMarioState->vel[1] = 30.0f;
            set_mario_action(gMarioState, ACT_CUTSCENE_JUMP, 1);
            // o->oFloatFC = (dist * sins(gMarioState->faceAngle[1])) / 48;
            // o->oFloat100 = (dist * coss(gMarioState->faceAngle[1])) / 48;
            // gMarioState->faceAngle[1] = angle_to
            o->os16106 = 0x2490;
            o->oSubAction = 1;
        }
    } else {
        if (o->oTimer <= 48) {
            set_mario_action(gMarioState, ACT_CUTSCENE_JUMP, 1);
            if (gMarioState->vel[1] < 0.0f) {
                gMarioState->vel[1] = 0.0f;
            }
            o->os16106 += 0x492;
            gMarioState->pos[1] += sins(o->os16106) * 30.0f;
        } else {
            o->oSubAction = 2;
        }
    }


    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, 0, 0x400);
    o->oFaceAngleYaw = o->oMoveAngleYaw;

    // o->os16102 += 0x180;
    hitboxPos[0] = o->oHomeX + (1200.0f * coss(o->os16102));
    hitboxPos[1] = o->oHomeY + 100.0f + (150.0f * coss(o->os16102 / 3));
    hitboxPos[2] = o->oHomeZ + (300.0f * sins(o->os16102));
    o->oPosX = approach_f32_symmetric(o->oPosX, hitboxPos[0], 140.0f);
    o->oPosY = approach_f32_symmetric(o->oPosY, hitboxPos[1], 20.0f);
    o->oPosZ = approach_f32_symmetric(o->oPosZ, hitboxPos[2], 140.0f);
    if (o->oSubAction == 2 && !o->oMoveAngleYaw 
        && o->oPosX == hitboxPos[0] && o->oPosY == hitboxPos[1] && o->oPosZ == hitboxPos[2]) {
        o->oAction = CONTROLLER_ACT_DEFAULT;
    }
}


extern s32 gBossTitleTimer;

void controller_act_intro(void) {
    // print_text_fmt_int(80, 80, "%x", gMarioState->action, 0);
    switch (o->oSubAction) {
        case 0:
            gCamera->comitCutscene = 28;
            set_mario_npc_dialog(1);
            if (gMarioState->pos[1] <= gMarioState->floorHeight) {
                if (o->oTimer > 30) {
                    o->oSubAction = 1;
                    o->oTimer = 0;
                }
            } else {
                o->oTimer = 0;
            }
            break;
        case 1:
            gCamera->comitCutscene = 29;
            gComitCutsceneObject = o;
            gComitCutsceneTimer = 20;
            o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 1.0f, 0.02f);
            cur_obj_scale(o->header.gfx.scale[0]);
            o->oPosZ = approach_f32_asymptotic(o->oPosZ, -10281.0f, 0.04f);
            if (o->oTimer > 70 && cur_obj_check_if_at_animation_end()) {
                // o->oPosZ = o->oHomeZ = -10281.0f;
                o->oSubAction = 2;
                o->oTimer = 0;
                cur_obj_init_animation_with_sound(1);
            }
            break;
        case 2:
            gCamera->comitCutscene = 29;
            gComitCutsceneObject = o;
            gComitCutsceneTimer = 20;
            o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 1.4f, 0.02f);
            cur_obj_scale(o->header.gfx.scale[0]);
            if (o->oPosZ != -10281.0f) {
                o->oPosZ = o->oHomeZ = approach_f32_symmetric(o->oPosZ, -10281.0f, 15.0f);
            }

            if (o->header.gfx.animInfo.animFrame == 8) {
                gBossTitleTimer = 1;
            }
            if (o->header.gfx.animInfo.animFrame == 40) {
                cur_obj_play_sound_2(SOUND_OBJ2_BOWSER_ROAR);
                cur_obj_shake_screen(SHAKE_POS_LARGE);
                queue_rumble_data(5, 80);
            }

            if (cur_obj_check_if_at_animation_end()) {
                cur_obj_init_animation_with_sound(0);
                o->oSubAction = 3;
                o->oTimer = 0;
                // o->oAction = CONTROLLER_ACT_DEFAULT;
            }
            break;
        case 3:
            o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 1.0f, 0.07f);
            cur_obj_scale(o->header.gfx.scale[0]);
            o->oPosY = approach_f32_asymptotic(o->oPosY, o->oHomeY, 0.05f);
            if (o->oTimer > 25) {
                o->oSubAction = 0;
                o->oAction = CONTROLLER_ACT_DEATH;
                o->oOpacity = 0;
                o->oFloatF4 = 0.0f;
                // o->oAction = CONTROLLER_ACT_DEFAULT;
                set_mario_npc_dialog(0);
            }
            break;
    }
}


void controller_act_death(void) {
    gCamera->comitCutscene = 29;
    gComitCutsceneObject = o;
    gComitCutsceneTimer = 20;

    o->os16112 = approach_s16_symmetric(o->os16112, 0x100, 0x4);
    o->os16110 = approach_s16_symmetric(o->os16110, 0x3000, o->os16112);
    o->oFaceAngleYaw += o->os16110;
    switch (o->oSubAction) {
        case 0:
            // o->oFaceAngleYaw = approach_s16_asymptotic(o->oFaceAngleYaw, 0xD000, 0x10);
            o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, 0xD000, 0x400);
            o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 1.4f, 0.03f);
            o->header.gfx.scale[2] = o->header.gfx.scale[0];
            o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 0.7f, 0.022f);

            if (o->os16110 > 0x600) {
                o->oSubAction = 1;
                o->oFloatF4 = 0.001f;
            }
            break;
        case 1:
            o->header.gfx.scale[0] = approach_f32_asymptotic(o->header.gfx.scale[0], 0.15f, 0.13f);
            o->header.gfx.scale[2] = o->header.gfx.scale[0];
            o->oFloatF4 *= 1.2f;// approach_f32_symmetric(o->oFloatF4, 0.7f, 0.001f);
            o->header.gfx.scale[1] += o->oFloatF4;
            // o->header.gfx.scale[1] = approach_f32_asymptotic(o->header.gfx.scale[1], 6.0f, o->oFloatF4);
            if (o->header.gfx.scale[1] >= 3.0f) {
                if (o->oTimer > 15) {
                    CL_explode_object(o, 1);
                }
            } else {
                o->oTimer = 0;
            }
            // print_text_fmt_int(80, 80, "%d", (s32)(o->header.gfx.scale[1] * 100.0f), 1);
            break;
    }
}


s32 boss_attacks_incompatible(void) {
    s32 end1 = sEndAttacks[0]->oBehParams2ndByte;
    s32 end2 = sEndAttacks[1]->oBehParams2ndByte;
    if (end1 == end2) {
        return TRUE;
    }

    if (end1 == FBA_WALL && (end2 == FBA_BUBBLES || end2 == FBA_LOGS || end2 == FBA_LASER)) {
        return TRUE;
    }

    if (end2 == FBA_WALL && (end1 == FBA_BUBBLES || end1 == FBA_LOGS || end1 == FBA_LASER)) {
        return TRUE;
    }

    return FALSE;
}

void bhv_the_controller_loop(void) {
    struct Object *obj;
    f32 dist, posY;
    s16 pitch, yaw;
    s16 angle;
    Vec3f hitboxPos;

    // set_mario_animation_other(gMarioState, MARIO_ANIM_IDLE_HEAD_LEFT);

    switch (o->oAction) {
        case CONTROLLER_ACT_INTRO:
            controller_act_intro();
            break;
        case CONTROLLER_ACT_DEFAULT:
            //ANGLE
            o->oFaceAngleYaw = o->oMoveAngleYaw;

            //MOVE AROUND
            o->os16102 += 0x180;
            posY = o->oHomeY + 100.0f + (150.0f * coss(o->os16102 / 3));
            o->oPosY = approach_f32_symmetric(o->oPosY, posY, 15.0f);
            o->oPosX = o->oHomeX + (1200.0f * coss(o->os16102));
            o->oPosZ = o->oHomeZ + (300.0f * sins(o->os16102));


            //SPAWN BUBBLES
            if (o->oOpacity < 0xFF) {
                boss_spawn_arena_bubbles(1);
            }

            if (o->oTimer > 30 && cur_obj_nearest_object_with_behavior(bhvBossCage) == NULL && boss_attacks_finished())  {
                if (o->os16104 >= 3) {
                    if (o->oTimer > 75) {
                        obj = spawn_object(o, MODEL_HAUNTED_CAGE, bhvBossCage);
                        // vec3f_set(&obj->oPosX, 1081.0f, 8406.0f, -7477.0f);
                        obj->oFaceAngleYaw = obj->oMoveAngleYaw = 0x6C00;
                        vec3f_set(&obj->oPosX, -2020.0f, 7416.0f, -1518.0f);
                        o->os16104 = 0;
                    }
                } else {
                    o->oAction = CONTROLLER_ACT_ATTACKS;
                }
                break;
            }

            //SET TO OTHER ACTS
            if (o->oDistanceToMario < 1000.0f && cur_obj_check_if_at_animation_end() && CL_RandomMinMaxU16(0, 2)) {
                o->oAction = CONTROLLER_ACT_SWIPE;
                cur_obj_init_animation_with_sound(1);
            }
            if (gMarioState->heldObj != NULL) {
                o->oAction = CONTROLLER_ACT_RUN;
                o->os16F6 = o->oAngleToMario + 0x8000;
                o->os16F8 = CL_RandomMinMaxU16(30, 100);
                o->os16FA = o->oOpacity;
            }
            break;
        case CONTROLLER_ACT_ATTACKS:
            controller_act_attacks();
            break;
        case CONTROLLER_ACT_SWIPE:
            o->oFaceAngleYaw = o->oMoveAngleYaw;
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 20.0f);
            if (o->header.gfx.animInfo.animFrame < 50) {
                o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 1.4f, 0.02f);
                cur_obj_scale(o->header.gfx.scale[0]);
            } else if (o->header.gfx.animInfo.animFrame <= 66) {
                hitboxPos[1] = gMarioState->pos[1];
                hitboxPos[0] = o->oPosX + (sins(o->oMoveAngleYaw) * 350.0f);
                hitboxPos[2] = o->oPosZ + (coss(o->oMoveAngleYaw) * 350.0f);
                vec3f_get_dist_and_angle(hitboxPos, gMarioState->pos, &dist, &pitch, &yaw);
                if (dist < 500.0f && absf (gMarioState->pos[1] - o->oPosY) < 600.0f) {
                    CL_get_hit(gMarioState, o, 2);            
                }
            } else {
                o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 1.0f, 0.06f);
                cur_obj_scale(o->header.gfx.scale[0]);
            }

            if (cur_obj_check_if_at_animation_end()) {
                o->oAction = CONTROLLER_ACT_DEFAULT;
                cur_obj_init_animation_with_sound(0);
            }
            break;
        case CONTROLLER_ACT_RUN:
            controller_act_run();
            break;
        case CONTROLLER_ACT_RUN_END:
            controller_act_run_end();
            break;
        case CONTROLLER_ACT_DEATH:
            controller_act_death();
            break;
    }
    o->oInteractStatus = 0;
}