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
    // o->oAction = 5; // DEBUG
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