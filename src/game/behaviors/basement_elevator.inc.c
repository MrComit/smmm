static struct ObjectHitbox sGhostBullyHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 3,
    /* numLootCoins:      */ 0,
    /* radius:            */ 70,
    /* height:            */ 180,
    /* hurtboxRadius:     */ 70,
    /* hurtboxHeight:     */ 180,
};

struct ObjectHitbox sHammerHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 1,
    /* numLootCoins:      */ 0,
    /* radius:            */ 72,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 42,
    /* hurtboxHeight:     */ 40,
};


enum ElevatorHazards {
    EH_ENEMIES,      // 0x00
    EH_FLAME,        // 0x01
    EH_FLAME2,       // 0x02
    EH_FLAMEFAST,    // 0x03
    EH_SAWBLADE,     // 0x04
    EH_SLAM,         // 0x05
    EH_WALL,         // 0x06
    EH_WALL2,        // 0x07
    EH_DUST,         // 0x08
    EH_ARROW,        // 0x09
    EH_SPECIAL,      // 0x0A
};


#define COMIT_OBJECT(a, b, c, d, e, f, g, h) \
    obj = spawn_object_abs_with_rot(o, 0, a, h, b, c, d, DEGREES(e), DEGREES(f), DEGREES(g)); \
    obj->oRoom = o->oRoom; \
    obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;



void bhv_elevator_door_init(void) {
    struct Object *obj;
    o->os16110 = 0;
    if (lateral_dist_between_objects(o, gMarioObject) < 500.0f || o->oBehParams2ndByte == 1) {
        o->oAction = 1;
        o->oPosY = o->oHomeY + 400.0f;
        o->header.gfx.scale[2] = 0.8f;
    }
    if (o->oBehParams2ndByte == 2 || o->oBehParams2ndByte == 3) {
        if (save_file_get_newflags(0) & SAVE_NEW_FLAG_ELEVATOR_BOSS) {
            o->os16112 = 1;
        } else if (((o->oBehParams >> 8) & 0xFF) == 0xAB) {
            obj = spawn_object(o, MODEL_NONE, bhvElevatorTeleporter);
            obj->oPosY = o->oHomeY + 10.0f;
            // obj->oPosZ += 20.0f;
            // obj->oRoom = o->oRoom;
            // obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
        }
    }
}

void bhv_elevator_door_loop(void) {
    if ((o->oBehParams2ndByte == 2 || o->oBehParams2ndByte == 3) && save_file_get_newflags(0) & SAVE_NEW_FLAG_ELEVATOR_BOSS) {
        o->os16112 = 1;
    } 
    switch (o->oAction) {
        case 0:
            cur_obj_unhide();
            o->header.gfx.scale[2] = approach_f32_symmetric(o->header.gfx.scale[2], 1.0f, 0.02f);
            if (o->oPosY != o->oHomeY) {
                o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 15.0f);
                if (o->os16112) {
                    o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 30.0f);
                }
                cur_obj_play_sound_1(SOUND_ENV_ELEVATOR1);
            }
            if (o->oBehParams2ndByte == 1) {
                if (cur_obj_nearest_object_with_behavior(bhvGhostBully) == NULL) {
                    o->oAction = 1;
                }
            } else {
                if (o->oDistanceToMario < 500.0f) {
                    o->oAction = 1;
                }
            }
            break;
        case 1:
            o->header.gfx.scale[2] = approach_f32_symmetric(o->header.gfx.scale[2], 0.8f, 0.02f);
            if (o->oPosY != o->oHomeY + 400.0f) {
                o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY + 400.0f, 15.0f);
                cur_obj_play_sound_1(SOUND_ENV_ELEVATOR1);
            } else {
                cur_obj_hide();
            }

            if (o->oBehParams2ndByte == 1) {
                if (cur_obj_nearest_object_with_behavior(bhvGhostBully) != NULL) {
                    o->oAction = 0;
                    // o->os16112 = 1;
                }
            } else {
                if (o->oDistanceToMario > 800.0f) {
                    o->oAction = 0;
                }
            }
            if (o->os16112) {
                if (absf(o->oPosZ - gMarioState->pos[2]) < 50.0f) {
                    if (o->os16110 == 0) {
                        o->oAction = 2;
                        sDelayedWarpOp = 0x10;
                        sDelayedWarpTimer = 12;
                        sSourceWarpNodeId = (o->oBehParams >> 8) & 0xFF;
                        // music_changed_through_warp(sSourceWarpNodeId);
                        play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 0x8, 0x00, 0x00, 0x00);
                    }
                } else if (o->oBehParams2ndByte == 3) {
                    if (gMarioState->pos[2] < o->oPosZ) {
                        o->os16110 = 1;
                    } else {
                        o->os16110 = 0;
                    }
                }
            }
            break;
        case 2:
            if (o->oTimer > 10) {
                if (lateral_dist_between_objects(o, gMarioObject) < 500.0f || o->oBehParams2ndByte == 1) {
                    o->oAction = 1;
                    o->oPosY = o->oHomeY + 400.0f;
                    o->header.gfx.scale[2] = 0.8f;
                } else {
                    o->oAction = 0;
                }
            }
            break;
    }
}









void bhv_hammer_init(void) {
    o->oMoveAngleYaw = obj_angle_to_object(o, gMarioObject);
    o->oForwardVel = 15.0f + (dist_between_objects(o, gMarioObject) / 100.0f);
    o->oVelY = 50.0f;
    o->oGravity = -3.0f;
    o->oPosY += 50.0f;
    obj_set_hitbox(o, &sHammerHitbox);
}


void bhv_hammer_loop(void) {
    CL_Move();
    o->oFaceAnglePitch += 0x1000;
    if (o->oPosY < -3000.0f || o->oInteractStatus & INT_STATUS_INTERACTED) {
        o->activeFlags = 0;
        // spawn_mist_particles();
        spawn_mist_particles_variable(4, 0, 23.0f);
    }
}


void bhv_wall_goomba_loop(void) {
    f32 dist1, dist2;
    struct Object *obj;
    cur_obj_update_floor_and_walls();
    cur_obj_move_standard(0);
    dist1 = cur_obj_dist_to_nearest_object_with_behavior(bhvWallGoomba);
    dist2 = cur_obj_dist_to_nearest_object_with_behavior(bhvWallHammerBro);
    if (dist2 < dist1) {
        dist1 = dist2;
    }

    if (o->oMoveFlags & OBJ_MOVE_HIT_WALL || dist1 < 100.0f 
        || cur_obj_dist_to_nearest_object_with_behavior(bhvBreakableBoxNoChild) < 150.0f) {
        o->oMoveAngleYaw += 0x8000;
        cur_obj_move_standard(0);
    }

    switch (o->oAction) {
        case 0:
            // if (o->oDistanceToMario < 900.0f) {
                o->oAction = 1;
            // }
            // o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 0.0f, 1.0f);
            break;
        case 1:
            if (o->oDistanceToMario > 1050.0f) {
                o->oAction = 0;
            }
            o->oForwardVel = 10.0f;
            break;
    }

    if (o->oPosY < o->oHomeY - 150.0f) {
        o->activeFlags = 0;
        create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
        gMarioState->numCoins++;
    }
}

void bhv_wall_hammerbro_init(void) {
    o->oMoveAngleYaw = o->oFaceAngleYaw - 0x4000;
    if (cur_obj_has_model(MODEL_WALL_HAMMERBRO) && o->oObjFC != NULL) {
        vec3f_copy(&o->oFloat100, &o->oObjFC->oPosX);
        // o->os16100 = obj_angle_to_object(o, o->oObjFC);
        spawn_mist_particles();
    }
}


void bhv_wall_hammerbro_loop(void) {
    f32 dist;
    s16 pitch, yaw;
    if (o->os16F4++ & 0x20) {
        o->oAnimState ^= 1;
        o->os16F4 = 0;
    }
    
    if (o->oAnimState && o->os16F4 == 0x10) {
        spawn_object(o, MODEL_HAMMER, bhvHammer);
    }

    cur_obj_update_floor_and_walls();
    cur_obj_move_standard(-78);

    switch (o->oAction) {
        case 0:
            if (o->oObjFC == NULL || o->oObjFC->activeFlags == 0) {
                o->oAction = 1;
            }
            if ((o->oTimer & 0x1F) == 0) {
                o->oMoveAngleYaw += 0x8000;
                o->oForwardVel = 15.0f;
                o->oVelY = 15.0f;
            }

            if ((o->oTimer & 0x7F) == 0) {
                o->oFaceAngleYaw += 0x8000;
            }

            break;
        case 1:
            if ((o->oTimer & 0xF) == 0) {
                vec3f_get_dist_and_angle(&o->oPosX, &o->oFloat100, &dist, &pitch, &yaw);
                if (absi((o->oMoveAngleYaw & 0xFFFF) - (u16)yaw) > 0x4000) {
                    o->oMoveAngleYaw += 0x8000;
                }
                o->oFaceAngleYaw = o->oMoveAngleYaw + 0x4000;
                o->oForwardVel = 20.0f;
                o->oVelY = 20.0f;
            }
            break;
    }

    dist = cur_obj_dist_to_nearest_object_with_behavior(bhvWallGoomba);
    if (dist < 80.0f) {
        o->oMoveAngleYaw += 0x8000;
        o->oFaceAngleYaw = o->oMoveAngleYaw + 0x4000;
        // do {
            cur_obj_move_standard(-78);
        //     dist = cur_obj_dist_to_nearest_object_with_behavior(bhvWallGoomba);
        // } while (dist <= 70.0f);
    }
    o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 0.0f, 1.0f);

    if (o->oPosY < o->oHomeY - 150.0f) {
        o->activeFlags = 0;
        create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
        gMarioState->numCoins++;
    }
}


void ghost_bully_bounds_constraint(void) {
    if (o->oPosX < -700.0f) {
        o->oPosX = -700.0f;
    } else if (o->oPosX > 1700.0f) {
        o->oPosX = 1700.0f;
    }

    if (o->oPosZ < -13337.0f) {
        o->oPosZ = -13337.0f;
    } else if (o->oPosZ > -10937.0f) {
        o->oPosZ = -10937.0f;
    }
}

void ghost_bully_mario_constraint(void) {
    struct MarioState *m = gMarioState;
    if (m->pos[0] < -700.0f) {
        m->pos[0] = -700.0f;
    }

    if (m->pos[2] < -13337.0f) {
        m->pos[2] = -13337.0f;
    }
}


void ghost_bully_spawn_wall_enemies(s32 left) {
    struct Object *obj, *obj2;

    if (!left) {
        COMIT_OBJECT(MODEL_WALL_GOOMBA, -49, -3000, -13397, 0, 0, 0, bhvWallGoomba);
        COMIT_OBJECT(MODEL_WALL_GOOMBA, 192, -3000, -13397, 0, 0, 0, bhvWallGoomba);
    }
    COMIT_OBJECT(MODEL_WALL_GOOMBA, -646, -3000, -13397, 0, 0, 0, bhvWallGoomba);
    obj2 = COMIT_OBJECT(MODEL_WALL_HAMMERBRO, -406, -3000, -13397, 0, 0, 0, bhvWallHammerBro);
    COMIT_OBJECT(MODEL_BREAKABLE_BOX, 500, -3000, -13437, 0, -90, 0, bhvBreakableBoxNoChild);
    obj2->oObjFC = obj;

    if (left) {
        // COMIT_OBJECT(MODEL_WALL_GOOMBA, -760, -3000, -13219, 0, 90, 0, bhvWallGoomba);
        // COMIT_OBJECT(MODEL_WALL_GOOMBA, -760, -3000, -12691, 0, 90, 0, bhvWallGoomba);
        COMIT_OBJECT(MODEL_WALL_GOOMBA, -760, -3000, -12183, 0, 90, 0, bhvWallGoomba);
        COMIT_OBJECT(MODEL_WALL_GOOMBA, -760, -3000, -11501, 0, 90, 0, bhvWallGoomba);
        obj2 = COMIT_OBJECT(MODEL_WALL_HAMMERBRO, -760, -3000, -12472, 0, 90, 0, bhvWallHammerBro);
        COMIT_OBJECT(MODEL_BREAKABLE_BOX, -800, -3000, -12976, 0, -90, 0, bhvBreakableBoxNoChild);
        obj2->oObjFC = obj;
        obj2 = COMIT_OBJECT(MODEL_WALL_HAMMERBRO, -760, -3000, -11282, 0, 90, 0, bhvWallHammerBro);
        COMIT_OBJECT(MODEL_BREAKABLE_BOX, -800, -3000, -11969, 0, -90, 0, bhvBreakableBoxNoChild);
        obj2->oObjFC = obj;
    }
}


void ghost_bully_spawn_enemies(s32 dustBunnies) {
    struct Object *obj;
    s32 snufitCount = count_room_objects_with_behavior(bhvElevatorSnufit, o->oRoom);
    if (count_room_objects_with_behavior(bhvGoomba, o->oRoom) < 2) {
        COMIT_OBJECT(MODEL_GOOMBA, 829, -3000 + 1000, -12493, 0, 0, 0, bhvGoomba);
        obj->parentObj = obj;
    }
    if (snufitCount < 3) {
        COMIT_OBJECT(MODEL_SNUFIT, -404, -2800, -12299, 0, 0, 0, bhvElevatorSnufit);
        if (snufitCount < 2) {
            COMIT_OBJECT(MODEL_SNUFIT, 1454, -2800, -12989, 0, 0, 0, bhvElevatorSnufit);
            if (!dustBunnies) {
                COMIT_OBJECT(MODEL_SNUFIT, 1371, -2800, -11374, 0, 0, 0, bhvElevatorSnufit);
            }
        }
    }

    if (dustBunnies) {
        if (count_room_objects_with_behavior(bhvDustBunny, o->oRoom) < 2) {
            COMIT_OBJECT(MODEL_DUST_BUNNY, -420, -3000, -12445, 0, -180, 0, bhvDustBunny);
            obj->oBehParams = 2 << 16;
            obj->oBehParams2ndByte = 2;
            COMIT_OBJECT(MODEL_DUST_BUNNY, 1364, -3000, -12395, 0, -180, 0, bhvDustBunny);
            obj->oBehParams = 2 << 16;
            obj->oBehParams2ndByte = 2;
        }
    }
}


void ghost_bully_phases(void) {
    s32 wall2 = 0;
    struct Object *obj;
    s32 goombasDead = (CL_obj_find_nearest_object_with_behavior_room(o, bhvGoomba, o->oRoom) == NULL);
    s32 snufitsDead = (CL_obj_find_nearest_object_with_behavior_room(o, bhvElevatorSnufit, o->oRoom) == NULL);
    s32 bunniesDead = (CL_obj_find_nearest_object_with_behavior_room(o, bhvDustBunny, o->oRoom) == NULL);
    s32 wallGoombasDead = (CL_obj_find_nearest_object_with_behavior_room(o, bhvWallGoomba, o->oRoom) == NULL);
    s32 wallHammerbrosDead = (CL_obj_find_nearest_object_with_behavior_room(o, bhvWallHammerBro, o->oRoom) == NULL);
    switch (o->os16102) {
        case 0:
            o->os16100 |= (1 << EH_ENEMIES) | (1 << EH_FLAME);
            o->os16102 = 1;
            cur_obj_play_sound_2(SOUND_OBJ_BOO_LAUGH_LONG);
            break;
        case 1:
            if (o->os16104 > 25*30 || (goombasDead && snufitsDead)) {
                if (o->os16108++ > 2*30) {
                    o->os16102 = 2;
                    cur_obj_play_sound_2(SOUND_OBJ_BOO_LAUGH_LONG);
                    o->os16100 |= (1 << EH_ENEMIES) | (1 << EH_FLAME2);
                }
                // if (!goombasDead || !snufitsDead) {
                //     kill_
                //     obj = CL_obj_find_nearest_object_with_behavior_room(o, bhvGoomba, o->oRoom);
                //     while (obj != NULL) {
                //         obj->activeFlags = 0;
                //     }
                //     obj = CL_obj_find_nearest_object_with_behavior_room(o, bhvElevatorSnufit, o->oRoom);
                //     while (obj != NULL) {
                //         obj->activeFlags = 0;
                //     }
                // }
            } else {
                o->os16108 = 0;
            }
            break;
        case 2:
            if (o->os16104 > 10*30 || (goombasDead && snufitsDead)) {
                o->os16100 |= (1 << EH_FLAMEFAST) | (1 << EH_SPECIAL);;
                if (o->os16108++ > 10*30) {
                    o->os16102 = 3;
                    cur_obj_play_sound_2(SOUND_OBJ_BOO_LAUGH_LONG);
                    o->os16100 |= (1 << EH_ENEMIES) | (1 << EH_SAWBLADE);
                    // o->os16100 &= ~(1 << EH_FLAME);
                }
            } else {
                o->os16108 = 0;
            }
            break;
        case 3:
            if (o->os16104 > 20*30 || (goombasDead && snufitsDead)) {
                o->os16100 |= (1 << EH_SLAM);
                if (o->os16108++ > 5*30) {
                    o->os16102 = 4;
                    cur_obj_play_sound_2(SOUND_OBJ_BOO_LAUGH_LONG);
                    o->os16100 |= (1 << EH_WALL);
                    o->os16100 &= ~(1 << EH_SAWBLADE);
                }
            } else {
                o->os16108 = 0;
            }
            break;
        case 4:
            if (wallGoombasDead && wallHammerbrosDead) {
                if (o->os16108++ > 2*30) {
                    o->os16102 = 5;
                    cur_obj_play_sound_2(SOUND_OBJ_BOO_LAUGH_LONG);
                    o->os16100 |= (1 << EH_WALL) | (1 << EH_WALL2) | (1 << EH_ENEMIES) | (1 << EH_ARROW) | (1 << EH_SAWBLADE);
                    o->os16100 &= ~(1 << EH_FLAME);
                }
            } else {
                o->os16108 = 0;
            }
            break;
        case 5:
            if (o->os16104 > 30*30 || (wallGoombasDead && wallHammerbrosDead)) {
                if (o->os16108++ > 2*30) {
                    o->os16102 = 6;
                    cur_obj_play_sound_2(SOUND_OBJ_BOO_LAUGH_LONG);
                    o->os16100 |= (1 << EH_ENEMIES) | (1 << EH_DUST) | (1 << EH_FLAME);
                    o->os16100 &= ~(1 << EH_SAWBLADE);
                }
            } else {
                o->os16108 = 0;
            }
            break;
        case 6:
            if (o->os16104 > 25*30 || (goombasDead && snufitsDead && bunniesDead)) {
                if (o->os16108++ > 2*30) {
                    o->os16102 = 7;
                    cur_obj_play_sound_2(SOUND_OBJ_BOO_LAUGH_LONG);
                    o->os16100 |= (1 << EH_ENEMIES); //| (1 << EH_ARROW);
                    // o->os16100 &= ~(1 << EH_SAWBLADE);
                    if (wallGoombasDead && wallHammerbrosDead) {
                        o->os16100 |= (1 << EH_WALL);
                        o->os16100 &= ~(1 << EH_WALL2);
                    }
                }
            } else {
                o->os16108 = 0;
            }
            break;
        case 7:
            if (goombasDead && snufitsDead && bunniesDead && wallGoombasDead && wallHammerbrosDead) {
                o->os16102 = 8;
                // o->os16100 |= (1 << EH_SPECIAL);
                o->os16100 &= ~((1 << EH_ARROW) | (1 << EH_SAWBLADE) | (1 << EH_FLAME));
                o->oAction = 11;
                cur_obj_play_sound_1(SOUND_OBJ_BOO_LAUGH_LONG);
                stop_background_music(SEQUENCE_ARGS(4, SEQ_BASEMENT_BOSS));
            }
            break;
        case 8:
            break;
    }

    if (o->os16100 & (1 << EH_ENEMIES)) {
        ghost_bully_spawn_enemies(o->os16100 & (1 << EH_DUST));
        o->os16100 &= ~(1 << EH_ENEMIES);
    }
    
    if (o->os16100 & (1 << EH_WALL)) {
        if (o->os16100 & (1 << EH_WALL2)) {
            wall2 = 1;
        }
        ghost_bully_spawn_wall_enemies(wall2);
        o->os16100 &= ~(1 << EH_WALL);
    }

}



extern s32 gBossPrecoins;

void bhv_ghost_bully_init(void) {
    o->oForwardVel = 12.0f;
    o->os16102 = -1;
    obj_set_hitbox(o, &sGhostBullyHitbox);
    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_ELEVATOR_BOSS) {
        o->activeFlags = 0;
    }
    cur_obj_become_intangible();
}

void bhv_ghost_bully_loop(void) {
    struct Object *obj;
    s16 actCheck = o->os16102;
    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_ELEVATOR_BOSS) {
        o->activeFlags = 0;
        return;
    }
    if (gMarioCurrentRoom == o->oRoom) {
        ghost_bully_bounds_constraint();
        ghost_bully_mario_constraint();
        ghost_bully_phases();
        if (o->os16102 != actCheck) {
            o->os16104 = 0;
            o->os16108 = 0;
        } else {
            o->os16104++;
        }
    }
    obj_set_hitbox(o, &sGhostBullyHitbox);
    switch (o->oAction) {
        case 0:
            if (o->oTimer > 90) {
                o->oAction = 9;
                gBossPrecoins = gMarioState->numCoins;
            }
            break;
        case 1: // chase
            o->os16112 += 0x400 + (o->os16102 * 0x100);
            o->oFaceAngleRoll = sins(o->os16112) * (0xC0 * o->os16102);
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x400);
            o->oFaceAngleYaw = o->oMoveAngleYaw;
            CL_Move();
            o->oPosY = approach_f32_symmetric(o->oPosY, gMarioState->pos[1], 8.0f);
            if (o->oTimer > 90 + o->os16106) { // was 180
                o->os16106 = CL_RandomMinMaxU16(0, 45);
                if (o->os16100 & (1 << EH_SLAM) && (random_u16() & 1) && o->oDistanceToMario < 1000.0f) {
                    o->oAction = 4;
                    o->oForwardVel = 40.0f;
                } else {
                    o->oAction = 2;
                    cur_obj_play_sound_1(SOUND_ACTION_TWIRL);
                }
            }
            if (o->os16100 & (1 << EH_SPECIAL)) {
                o->oAction = 6;
                o->os16100 &= ~(1 << EH_SPECIAL);
                o->oFloat10C = o->header.gfx.scale[0] + 1.5f;
                o->os16110 = 0;
            }
            // if (o->oTimer > 180 && o->oDistanceToMario < 750.0f) {
            //     o->oAction = 4;
            //     o->oForwardVel = 40.0f;
            // }
            break;
        case 2: // start dash
            o->oFaceAngleYaw += 0xD00;
            if (o->oTimer > 8 && absi((s16)o->oFaceAngleYaw - o->oAngleToMario) <= 0xD00) {
                o->oFaceAngleYaw = o->oAngleToMario;
                o->oMoveAngleYaw = o->oFaceAngleYaw;
                o->oAction = 3;
                o->oForwardVel = 45.0f;
            }
            break;
        case 3: // dash
            cur_obj_play_sound_1(SOUND_MOVING_FLYING);
            CL_Move();
            if (o->oTimer > 45) {
                o->oAction = 1;
                o->oForwardVel = 12.0f;
            }
            break;
        case 4: // start slam
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x1000);
            o->oFaceAngleYaw = o->oMoveAngleYaw;
            CL_Move();
            o->oPosY = approach_f32_symmetric(o->oPosY, gMarioState->pos[1] + 500.0f, 30.0f);
            if (lateral_dist_between_objects(o, gMarioObject) < 100.0f && o->oPosY > gMarioState->pos[1] + 400.0f) {
                o->oAction = 5;
                o->oFloatFC = gMarioState->pos[1];
            }
            break;
        case 5: // slam
            if (o->oTimer == 30) {
                cur_obj_play_sound_1(SOUND_OBJ_THWOMP);
            }
            if (o->oTimer > 15) {
                o->oFloat10C = approach_f32_symmetric(o->oFloat10C, 80.0f, 8.0f);
                o->oPosY = approach_f32_symmetric(o->oPosY, o->oFloatFC, o->oFloat10C);
                if (o->oInteractStatus) {
                    o->oTimer = 20;
                } 
                if (o->oTimer > 45) {
                    o->oAction = 1;
                    o->oFloat10C = 0.0f;
                    o->oForwardVel = 10.0f;
                }
            }
            break;
        case 6: // pre big dash
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x1800);
            o->oFaceAngleYaw = o->oMoveAngleYaw;
            o->oPosY = approach_f32_symmetric(o->oPosY, gMarioState->pos[1], 30.0f);
            if (o->oTimer > 45) {
                o->oAction = 7;
            }
            break;
        case 7: // big dash
            if (o->os16110 < 3) {
                o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x1C00);
                o->oFaceAngleYaw = o->oMoveAngleYaw;
                o->oPosY = approach_f32_symmetric(o->oPosY, gMarioState->pos[1], 30.0f);
                if (o->oTimer > 15) {
                    o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], o->oFloat10C, 0.5f);
                    o->header.gfx.scale[2] = o->header.gfx.scale[1] = o->header.gfx.scale[0];
                    cur_obj_shake_screen(SHAKE_POS_SMALL);
                    if (o->header.gfx.scale[0] == o->oFloat10C) {
                        cur_obj_play_sound_2(SOUND_OBJ_KING_BOBOMB_JUMP);
                        o->os16110++;
                        o->oFloat10C = o->header.gfx.scale[0] + 1.5f;
                        o->oTimer = 0;
                        o->oForwardVel = 80.0f;
                    }
                }
            } else {
                if (o->oTimer > 20) {
                    CL_Move();
                    cur_obj_play_sound_1(SOUND_ENV_METAL_BOX_PUSH);
                    if (o->oTimer > 65) {
                        o->oAction = 8;
                        o->oForwardVel = 12.0f;
                        o->oFloat10C = o->header.gfx.scale[0] - 4.5f;
                    }
                }
            }
            break;
        case 8: // post big dash
            o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], o->oFloat10C, 0.5f);
            o->header.gfx.scale[2] = o->header.gfx.scale[1] = o->header.gfx.scale[0];
            if (o->header.gfx.scale[0] == o->oFloat10C) {
                o->oFloat10C = 0;
                o->os16110 = 0;
                o->oAction = 1;
            }
            break;
        case 9:
            cur_obj_play_sound_1(SOUND_ENV_ELEVATOR1);
            if (o->oTimer > 90) {
                if (o->oTimer == 91) {
                    cur_obj_play_sound_2(SOUND_GENERAL2_PYRAMID_TOP_EXPLOSION);
                }
                if (o->oTimer < 105) {
                    cur_obj_shake_screen(SHAKE_POS_SMALL);
                } else {
                    o->oAction = 10;
                }
            }
            break;
        case 10:
            if (o->oTimer > 30) {
                o->os16102 = 0;
                o->oAction = 1;
                cur_obj_unhide();
                cur_obj_become_tangible();
                play_music(0, SEQUENCE_ARGS(4, SEQ_BASEMENT_BOSS), 0);
            }
            break;
        case 11:
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY - 1500.0f, 20.0f);
            if (o->oPosY == o->oHomeY - 1500.0f) {
                o->activeFlags = 0;
                save_file_set_newflags(SAVE_NEW_FLAG_ELEVATOR_BOSS, 0);
                gMarioState->numCoins += 100;

                play_course_clear();
                obj = spawn_object(o, MODEL_NONE, bhvChapterEndPrompt);
                obj->oBehParams2ndByte = DIALOG_061;
                obj->oF4 = 3;
            }
            break;
    }
    o->oInteractStatus = 0;
    // if (gMarioState->input & INPUT_Z_PRESSED) {
    //     o->os16100 |= (1 << EH_ARROW);
    //     ghost_bully_spawn_wall_enemies(0);
    //     ghost_bully_spawn_enemies(1);
    // }
}


void check_ghost_bully_death(void) {
    if (o->oObjF8 == NULL || o->oObjF8->activeFlags == 0) {
        o->activeFlags = 0;
    }
}


void bhv_elevator_spawn_init(void) {
    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_ELEVATOR_BOSS) {
        o->activeFlags = 0;
        return;
    }
    o->oObjF8 = cur_obj_nearest_object_with_behavior(bhvGhostBully);
    if (o->oObjF8 == NULL) {
        o->activeFlags = 0;
    }
}



void bhv_elevator_moving_flame_init(void) {
    struct Object *obj;
    o->oFloatFC = 12.0f;
    obj = cur_obj_nearest_object_with_behavior(bhvGhostBully);
    if (obj != NULL && obj->os16100 & (1 << EH_FLAMEFAST)) {
        o->oFloatFC += 8.0f;
    }

    if (o->oBehParams2ndByte) {
        o->oPosZ += 200.0f;
        o->os16F4 = 100;
        o->os16F6 = 100;
        o->os16F8 = 255;
        o->oFloatFC *= -1;
    } else {
        o->os16F4 = 255;
        o->os16F6 = 50;
        o->os16F8 = 0;
    }
}


void bhv_elevator_moving_flame_loop(void) {
    o->oPosX -= o->oFloatFC;
    if (o->oTimer > (s32)(2500.0f / 12.0f)) {
        o->activeFlags = 0;
    }
}

void bhv_elevator_flame_spawn_loop(void) {
    struct Object *obj;
    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_ELEVATOR_BOSS) {
        o->activeFlags = 0;
        return;
    }
    switch (o->oAction) {
        case 0:
            if (o->oObjF8->os16100 & (1 << EH_FLAME)) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (o->oTimer > 90 + o->os16F4) { // was 45
                obj = spawn_object(o, MODEL_ENV_FLAME_SHADOW, bhvElevatorMovingFlame);
                if (o->oObjF8->os16100 & (1 << EH_FLAME2) && (random_u16() & 1)) {
                    obj->oBehParams2ndByte = 1;
                    obj->oPosX -= 2500.0f;
                }
                obj->oPosZ += (random_float() - 0.5f) * 200.0f;
                o->oTimer = 0;
                o->os16F6++;
                o->os16F4 = CL_RandomMinMaxU16(0, 30); // was max 25
                if (o->oObjF8->os16100 & (1 << EH_FLAMEFAST)) {
                    o->os16F4 -= 20;
                }
            }

            if (!(o->oObjF8->os16100 & (1 << EH_FLAME))) {
                o->oAction = 0;
            }
            break;
    }
    check_ghost_bully_death();
}

void bhv_sawblade_spawn_loop(void) {
    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_ELEVATOR_BOSS) {
        o->activeFlags = 0;
        return;
    }
    switch (o->oAction) {
        case 0:
            if (o->oObjF8->os16100 & (1 << EH_SAWBLADE)) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (o->oTimer > 45) {
                spawn_object(o, MODEL_SAWBLADE, bhvSawbladeShoot);
                o->oTimer = 0;
            }
            if (!(o->oObjF8->os16100 & (1 << EH_SAWBLADE))) {
                o->oAction = 0;
            }
            break;
    }
    check_ghost_bully_death();
}


void bhv_sawblade_shoot_init(void) {
    obj_set_hitbox(o, &sSawbladeHitbox);
    o->oForwardVel = 50.0f;
    o->oFaceAnglePitch = 0x4000;
    o->oBehParams2ndByte = 1;
}


void bhv_sawblade_shoot_loop(void) {
    CL_Move();
    cur_obj_update_floor_and_walls();
    if (o->oInteractStatus || o->oMoveFlags & OBJ_MOVE_HIT_WALL || o->oTimer > 180) {
        // spawn_mist_particles();
        spawn_mist_particles_variable(4, 0, 23.0f);
        o->activeFlags = 0;
    }
}


void bhv_treadmill_floor_loop(void) {
    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_ELEVATOR_BOSS) {
        o->activeFlags = 0;
        return;
    }
    switch (o->oAction) {
        case 0:
            if (o->oObjF8->os16100 & (1 << EH_ARROW)) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (o->oOpacity < 255) {
                o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 0x6);
            }
            load_object_collision_model();
            if (!(o->oObjF8->os16100 & (1 << EH_ARROW))) {
                o->oAction = 2;
            }
            break;
        case 2:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 0x8);
            if (o->oOpacity > 100) {
                load_object_collision_model();
            } else if (o->oOpacity == 0) {
                o->activeFlags = 0;
            }
            break;
    }
    check_ghost_bully_death();
}