#include "game/object_helpers.h"
static struct ObjectHitbox sDiceEnemyHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 70,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 70,
    /* hurtboxHeight:     */ 100,
};

static struct ObjectHitbox sPoolBallHitbox = {
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

struct ObjectHitbox sToyMoleHitbox = {
    /* interactType:      */ INTERACT_BREAKABLE,
    /* downOffset:        */ 20,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 1,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 200,
    /* hurtboxRadius:     */ 100,
    /* hurtboxHeight:     */ 200,
};

Vec3s sPoolBallColors[9] = {
{0xff, 0xae, 0x01}, // 1
{0x2b, 0x67, 0xc2}, // 2
{0xf4, 0x00, 0x10}, // 3
{0x52, 0x1f, 0x92}, // 4
{0xf1, 0x5f, 0x00}, // 5
{0x12, 0x90, 0x26}, // 6
{0x64, 0x12, 0x00}, // 7
{0x00, 0x00, 0x00}, // 8
{0xFF, 0xFF, 0xFF}, // 16
};


Vec3f sToyMolePositions[3] = {
{8858.0f, 100.0f, 8386.0f},
{9483.0f, 100.0f, 8386.0f},
{9483.0f, 100.0f, 9011.0f},
};

#define BALL_TRAVEL_FRAMES 30

void bhv_pingpong_ball_init(void) {
    // o->oObjF4 = o->parentObj;
    o->oObjF8 = CL_nearest_object_with_behavior_and_field(bhvShyguyPingpong, 0x144, 1);
    if (o->oObjF8 == NULL) {
        o->activeFlags = 0;
    } else {
        o->oObjF8->oObjF4 = o;
    }
}

void pingpong_ball_update(struct Object *obj1, struct Object *obj2) {
    o->os16FC += 0x20000 / BALL_TRAVEL_FRAMES;
    o->oFloat100 = 175.0f + (coss(o->os16FC) * 65.0f);//o->oObjF8->oPosY + 150.0f;
    o->oPosY = approach_f32_symmetric(o->oPosY, o->oFloat100, 20.0f);
    o->oPosX = approach_f32_symmetric(o->oPosX, obj1->oPosX, 985.0f / BALL_TRAVEL_FRAMES);
    o->oPosZ = approach_f32_symmetric(o->oPosZ, o->oFloat10C, o->oFloat110);
    if (o->oPosX == obj1->oPosX) {
        if (obj1->oAction == 4) {
            obj1->oAction = 5;
            o->activeFlags = 0;
            obj2->oAction = 6;
            obj1->oObjF4 = NULL;
            obj2->oObjF4 = NULL;
            if (!gIsConsole) {
                spawn_mist_particles();
            }
        } else {
            obj1->oAction = 3;
            o->oAction ^= 1;
            o->os16FC = 0;
            if (obj2->oAction != 4) {
                obj2->oAction = 2;
                do {
                    obj2->os16F8 = random_u16();
                } while (absi(obj2->os16F8 - obj2->os16FA) < 0x2000);
                obj2->os16FA = obj2->os16F8;
                o->oFloat10C = obj2->oHomeZ + (sins(obj2->os16F8) * 180.0f);
            }
            o->oFloat110 = absf(o->oFloat10C - o->oPosZ) / BALL_TRAVEL_FRAMES;
        }
    }
}

void bhv_pingpong_ball_loop(void) {
    switch (o->oAction) {
        case 0:
            pingpong_ball_update(o->oObjF4, o->oObjF8);
            break;
        case 1:
            pingpong_ball_update(o->oObjF8, o->oObjF4);
            break;
    }
    if (o->os16104 == 0 && o->oDistanceToMario < 500.0f) {
        o->os16104 = 1;
    }
}

void bhv_shyguy_pingpong_init(void) {
    obj_set_hitbox(o, &sShyguyHitbox);
    o->oMoveAngleYaw = o->oFaceAngleYaw;
}

void bhv_shyguy_pingpong_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oTimer > 90 && cur_obj_nearest_object_with_behavior(bhvPoolBarrier) == NULL) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (o->oTimer < 30) {
                break;
            }
            if (o->oBehParams2ndByte == 0) {
                o->oObjF4 = spawn_object(o, MODEL_PINGPONG_BALL, bhvPingpongBall);
                o->oObjF4->oObjF4 = o;
            } else if (o->oObjF4 != NULL) {
                do {
                    o->os16F8 = random_u16();
                } while (absi(o->os16F8 - o->os16FA) < 0x2000);
                o->os16FA = o->os16F8;
                o->oObjF4->oFloat10C = o->oHomeZ + (sins(o->os16F8) * 180.0f);
                o->oObjF4->oFloat110 = absf(o->oObjF4->oFloat10C - o->oObjF4->oPosZ) / BALL_TRAVEL_FRAMES;
                o->oAction = 2;
            }
            break;
        case 2:
            o->oPosZ = approach_f32_asymptotic(o->oPosZ, o->oObjF4->oFloat10C, 0.1f);
            if (o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
                o->oAction = 4;
                o->oObjF4->oFloat10C = o->oPosZ;
            }
            break;
        case 3:
            if (o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
                o->oAction = 4;
                o->oObjF4->oFloat10C = o->oPosZ;
            }
            break;
        case 4:
            if (o->oTimer < 20) {
                o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, o->oAngleToMario, 0x800);
            } else if (o->oTimer < 30) {
                o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, o->oMoveAngleYaw, 0xC00);
            } else {
                o->oAction = 3;
            }
            break;
        case 5:
            spawn_mist_particles();
            // obj_spawn_loot_blue_coins(o, 1, 20.0f, 70);
            spawn_object(o, MODEL_BLUE_COIN, bhvMrIBlueCoin);
            o->activeFlags = 0;
            create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
            break;
        case 6:
            o->activeFlags = 0;
            spawn_object(o, MODEL_SHYGUY, bhvShyguy);
            break;
    }
    if (o->oObjF4 != NULL && o->oObjF4->os16104 && o->oOpacity < 255) {
        o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 0x8);
    }
    o->oInteractStatus = 0;
}


void bhv_toy_mole_init(void) {
    o->oPosY -= 250.0f;
    o->oFaceAngleYaw = random_u16();
    if (o->oBehParams2ndByte == 3) {
        o->oObj100 = spawn_object(o, MODEL_STAR_PIECE, bhvStarPiece);
        o->oObj100->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
        o->oObj100->oBehParams = 0x10 << 24;
        o->oObj100->oBehParams2ndByte = 0;
        o->oObj100->oRoom = o->oRoom;
        vec3f_copy(&o->oObj100->oPosX, &o->oPosX);
    }
}


void bhv_toy_mole_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 10.0f);
            if (o->oTimer & 1) {
                o->oFaceAngleYaw += 0x1000;
            }
            if (o->oPosY == o->oHomeY) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (o->oBehParams2ndByte == 3) {
                o->oObj100->oPosY = o->oPosY + 100.0f;
                o->oObj100->oRoom = o->oRoom;
            }
            obj_set_hitbox(o, &sToyMoleHitbox);
            if (cur_obj_was_attacked_or_ground_pounded() != 0) {
                obj_explode_and_spawn_coins(46.0f, 1);
                create_sound_spawner(SOUND_GENERAL_BREAK_BOX);
                if (o->oBehParams2ndByte < 3) {
                    o->oObjFC = spawn_object(o, MODEL_TOY_MOLE, bhvToyMole);
                    o->oObjFC->oBehParams2ndByte = o->oBehParams2ndByte + 1;
                    vec3f_copy(&o->oObjFC->oPosX, sToyMolePositions[o->oBehParams2ndByte]);
                }
            }
            break;
    }
}



void bhv_pool_floor_init(void) {
    o->oOpacity = 255;
    o->oObjF4 = cur_obj_nearest_object_with_behavior(bhvPoolCue);
    if (o->oObjF4 == NULL) {
        o->oAction = 3;
    }
}

void bhv_pool_floor_loop(void) {
    if (o->oOpacity > 0xF) {
        load_object_collision_model();
    }
    switch (o->oAction) {
        case 0:
            if (o->oObjF4->os16FA > 3) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->os16FA = (o->oObjF4->os16FA * 0x40);
            o->os16F8 += o->os16FA;
            o->oOpacity = 128 + (127 * coss(o->os16F8));
            if (o->oObjF4->oAction >= 4) {
                o->oAction = 2;
            }
            break;
        case 2:
            o->oOpacity = approach_f32_symmetric(o->oOpacity, 255, 0x10);
            if (o->oOpacity == 255) {
                o->oAction = 3;
            }
            break;
    }
    if (o->oOpacity <= 0xF && gMarioObject->platform == o) {
        set_mario_action(gMarioState, ACT_FREEFALL, 0);
    }
}


void bhv_pool_barrier_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oObjF4 = cur_obj_nearest_object_with_behavior(bhvPoolCue);
            if (o->oObjF4 == NULL || o->oObjF4->oAction == 5) {
                o->activeFlags = 0;
            } else if (o->oObjF4->oAction == 1) {
                o->oAction = 1;
            }
            break;
        case 1:
            load_object_collision_model();
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 0x8);
            if (o->oObjF4 == NULL || o->oObjF4->oAction == 4) {
                o->oAction = 2;
            }
            break;
        case 2:
            load_object_collision_model();
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 0x8);
            if (o->oOpacity < 10) {
                o->activeFlags = 0;
            }
            break;
    }
}

void bhv_pool_cue_init(void) {
    vec3f_set(&o->oPosX, 6658.0f, 247.0f, 8292.0f);
    if (cur_obj_nearest_object_with_behavior(bhvPoolBall) == NULL) {
        o->oAction = 5;
        o->oGraphYOffset = 9.0f;
    }
}


void bhv_pool_cue_loop(void) {
    Vec3f point;
    f32 dist;
    s16 pitch, yaw;
    o->oAction = 5; // DEBUG
    switch (o->oAction) {
        case 0:
            if (o->oTimer > 30) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oPosX = approach_f32_symmetric(o->oPosX, o->oHomeX, 30.0f);
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 30.0f);
            o->oPosZ = approach_f32_symmetric(o->oPosZ, o->oHomeZ, 30.0f);
            vec3f_get_dist_and_angle(&o->oPosX, gMarioState->pos, &dist, &pitch, &yaw);
            o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, -pitch, 0x200);
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x200);
            if (o->oPosX == o->oHomeX && o->oPosY == o->oHomeY && o->oPosZ == o->oHomeZ) {
                o->oAction = 2;
            }
            break;
        case 2:
            o->os16F8 += 0x200;
            o->oFloatF4 = gMarioState->pos[2] + (coss(o->os16F8) * 200.0f);
            o->oPosZ = approach_f32_symmetric(o->oPosZ, o->oFloatF4, 30.0f);
            o->oPosX = approach_f32_symmetric(o->oPosX, o->oHomeX, 15.0f);
            o->oFloat104 = (o->oDistanceToMario / 8) + gMarioState->pos[1];
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY + o->oFloat104, 15.0f);
            vec3f_get_dist_and_angle(&o->oPosX, gMarioState->pos, &dist, &pitch, &yaw);
            pitch += sins(o->os16F8) * 0x400;
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, yaw, 0x400);
            o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, -pitch, 0x400);

            if (o->oObjFC == NULL) {
                if (o->oTimer > 10) {
                    o->oObjFC = CL_nearest_object_with_behavior_and_field(bhvPoolBall, 0x188, o->os16FA << 16);
                    if (o->oObjFC == NULL) {
                        o->oFloat10C = o->oPosY / 15;
                        o->os16108 = (o->oFaceAnglePitch / 15);
                        o->os1610A = (o->oFaceAngleYaw / 15);
                        o->oAction = 4;
                        return;
                    }
                    o->oObjFC->parentObj = o;
                    o->oAction = 3;
                }
            } else {
                o->oTimer = 0;
            }
            break;
        case 3:
            vec3f_set_dist_and_angle(&o->oPosX, point, 350.0f, -o->oFaceAnglePitch, o->oMoveAngleYaw);
            if (o->oTimer == 0) {
                vec3f_get_dist_and_angle(point, &o->oObjFC->oPosX, &o->oFloat100, &pitch, &yaw);
                o->oFloat100 /= 15.0f;
            }

            if (o->oTimer <= 25) {
                vec3f_get_dist_and_angle(&o->oPosX, gMarioState->pos, &dist, &pitch, &yaw);
                o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, yaw, 0x800);
                o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, -pitch, 0x800);

                o->oObjFC->oPosX = approach_f32_symmetric(o->oObjFC->oPosX, point[0], o->oFloat100);
                o->oObjFC->oPosY = approach_f32_symmetric(o->oObjFC->oPosY, point[1], o->oFloat100);
                o->oObjFC->oPosZ = approach_f32_symmetric(o->oObjFC->oPosZ, point[2], o->oFloat100);
                o->oObjFC->header.gfx.scale[0] = approach_f32_symmetric(o->oObjFC->header.gfx.scale[0], 2.0f, 0.1f);
                o->oObjFC->header.gfx.scale[2] = o->oObjFC->header.gfx.scale[1] = o->oObjFC->header.gfx.scale[0];
                o->oObjFC->oGraphYOffset = approach_f32_symmetric(o->oObjFC->oGraphYOffset, -18.0f, 3.0f);

                if (o->oTimer == 25) {
                    o->oObjFC->oMoveAnglePitch = -o->oFaceAnglePitch;
                    o->oObjFC->oMoveAngleYaw = o->oMoveAngleYaw;
                    o->oObjFC->oForwardVel = 65.0f;
                }
            } else if (o->oTimer <= 35) {
                o->oForwardVel = -5.0f;
                o->oMoveAnglePitch = -o->oFaceAnglePitch;
                CL_Move_3d();
            } else if (o->oTimer <= 40) {
                o->oForwardVel = 30.0f;
                o->oMoveAnglePitch = -o->oFaceAnglePitch;
                CL_Move_3d();
            } else {
                o->oObjFC->oAction = 1;
                o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 0.0f, 5.0f);
                CL_Move_3d();
                if (o->oForwardVel == 0) {
                    o->oAction = 2;
                }
            }
            break;
        case 4:
            o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, 0, o->os16108);
            o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, 0, o->os1610A);
            o->oPosY = approach_f32_symmetric(o->oPosY, 0.0f, o->oFloat10C);
            o->oGraphYOffset = approach_f32_symmetric(o->oGraphYOffset, 10.0f, 1.0f);
            if (o->oTimer > 30) {
                o->oAction = 5;
            }
            break;
    }
}


void bhv_pool_ball_init(void) {
    if (o->oBehParams2ndByte > 7) {
        o->oBehParams2ndByte -= 8;
        o->oAnimState = 1;
    }
    o->os16F4 = sPoolBallColors[o->oBehParams2ndByte][0];
    o->os16F6 = sPoolBallColors[o->oBehParams2ndByte][1];
    o->os16F8 = sPoolBallColors[o->oBehParams2ndByte][2];
}


void bhv_pool_ball_loop(void) {
    if (o->oAction) {
        o->oFaceAnglePitch += 0x800;
        obj_set_hitbox(o, &sPoolBallHitbox);
        CL_Move_3d();
        cur_obj_update_floor_and_walls();
        if (o->oMoveFlags & OBJ_MOVE_HIT_WALL || absf(o->oPosY - o->oFloorHeight) < 40.0f 
        || o->oInteractStatus & INT_STATUS_INTERACTED || o->oTimer > 30) {
            // obj_explode_and_spawn_coins(46.0f, 0);
            create_sound_spawner(SOUND_GENERAL_HAUNTED_CHAIR_MOVE);
            spawn_mist_particles_variable(10, 0, 15.0f);
            o->parentObj->os16FA++;
            if (o->parentObj->os16FA == 15) {
                o->parentObj->os16FA++;
            }
            o->parentObj->oObjFC = NULL;
            o->parentObj->oAction = 2;
            o->activeFlags = 0;
        }
    }
}


void dice_enemy_move(void) {
    if (cur_obj_nearest_object_with_behavior(bhvPoolBarrier)) {
        cur_obj_disable();
        return;
    } else {
        cur_obj_enable();
    }
    cur_obj_update_floor_and_walls();
    cur_obj_init_animation_with_accel_and_sound(o->oBehParams2ndByte, 0.6f + o->oAnimState / 3.0f);
    // treat_far_home_as_mario(3000.0f);

    if (o->oGoombaTurningAwayFromWall) {
        o->oGoombaTurningAwayFromWall = obj_resolve_collisions_and_turn(o->oGoombaTargetYaw, 0x200);
    } else {
        if (o->oDistanceToMario >= 25000.0f) {
            o->oGoombaTargetYaw = o->oAngleToMario;
            o->oGoombaWalkTimer = random_linear_offset(20, 30);
        }
        if (!(o->oGoombaTurningAwayFromWall =
                  obj_bounce_off_walls_edges_objects(&o->oGoombaTargetYaw))) {
            if (o->oDistanceToMario < 1000.0f) {
                if (o->oTimer > o->os1610E) {
                    o->os1610C = (random_float() - 0.5f) * 0x2000;
                    o->os1610E = CL_RandomMinMaxU16(20, 90);
                    o->oTimer = 0;
                }
                o->oGoombaTargetYaw = o->oAngleToMario + o->os1610C;
                o->oForwardVel = 5.0f + o->oAnimState * 2.0f;
            } else {
                o->oForwardVel = 4.0f;

                if (o->oGoombaWalkTimer != 0) {
                    o->oGoombaWalkTimer--;
                } else {
                    if (random_u16() & 3) {
                        o->oGoombaTargetYaw = obj_random_fixed_turn(0x2000);
                        o->oGoombaWalkTimer = random_linear_offset(100, 100);
                    } else {
                        o->oGoombaTargetYaw = obj_random_fixed_turn(0x6000);
                    }
                }
            }
        }

        cur_obj_rotate_yaw_toward(o->oGoombaTargetYaw, 0x200 + o->oAnimState * 0x80);
    }
    cur_obj_move_standard(-78);
}

void bhv_dice_enemy_init(void) {
    obj_set_hitbox(o, &sDiceEnemyHitbox);
    o->oAnimState = o->oBehParams2ndByte;
    o->os16F6 = 0;
}


void bhv_dice_enemy_loop(void) {
    struct Object *obj;
    s32 i;
    // o->oAnimState = o->oBehParams2ndByte;
    if (o->oAnimState) {
        o->oInteractType = INTERACT_DAMAGE;
        o->os16F4 = approach_s16_symmetric(o->os16F4, 0xFF, 0x24);
        o->os16F8 = approach_s16_symmetric(o->os16F8, 0, 0x24);
    } else {
        o->oInteractType = INTERACT_BOUNCE_TOP;
        o->os16F8 = approach_s16_symmetric(o->os16F8, 0xFF, 0x24);
        o->os16F4 = approach_s16_symmetric(o->os16F4, 0, 0x24);
        if (o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
            o->activeFlags = 0;
            obj_spawn_loot_yellow_coins(o, o->oNumLootCoins, 20.0f);
            for (i = 0; i < 6 - o->oBehParams2ndByte; i++) {
                obj = CL_nearest_object_with_behavior_and_field(bhvDiceEnemy, 0x188, (o->oBehParams & 0xFF000000) + (i << 16));
                if (obj != NULL) {
                    obj->oBehParams -= 0x10000;
                    obj->oAnimState -= 1;
                }
            }
        }
    }
    dice_enemy_move();
    o->oInteractStatus = 0;
}