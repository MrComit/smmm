static struct ObjectHitbox sGhostBullyHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 3,
    /* numLootCoins:      */ 0,
    /* radius:            */ 115,
    /* height:            */ 235,
    /* hurtboxRadius:     */ 105,
    /* hurtboxHeight:     */ 225,
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
    EH_SAWBLADE,     // 0x03
    EH_SLAM,         // 0x04
    EH_WALL,         // 0x05
    EH_WALL2,        // 0x06
    EH_DUST,         // 0x07
    EH_ARROW,        // 0x08
};


#define COMIT_OBJECT(a, b, c, d, e, f, g, h) \
    obj = spawn_object_abs_with_rot(o, 0, a, h, b, c, d, DEGREES(e), DEGREES(f), DEGREES(g)); \
    obj->oRoom = o->oRoom; \
    obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;

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
        spawn_mist_particles();
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
    }
}

void bhv_wall_hammerbro_init(void) {
    o->oMoveAngleYaw = o->oFaceAngleYaw - 0x4000;
}


void bhv_wall_hammerbro_loop(void) {
    f32 dist;
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
            if (o->oDistanceToMario < 700.0f) {
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
            if (o->oDistanceToMario > 850.0f) {
                o->oAction = 0;
            }
            if ((o->oTimer & 0xF) == 0) {
                if (absi((o->oMoveAngleYaw & 0xFFFF) - (u16)o->oAngleToMario) > 0x4000) {
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
    struct Object *obj;

    COMIT_OBJECT(MODEL_WALL_GOOMBA, -49, -3000, -13397, 0, 0, 0, bhvWallGoomba);
    COMIT_OBJECT(MODEL_WALL_GOOMBA, 192, -3000, -13397, 0, 0, 0, bhvWallGoomba);
    COMIT_OBJECT(MODEL_WALL_GOOMBA, -646, -3000, -13397, 0, 0, 0, bhvWallGoomba);
    COMIT_OBJECT(MODEL_WALL_HAMMERBRO, -406, -3000, -13397, 0, 0, 0, bhvWallHammerBro);
    COMIT_OBJECT(MODEL_BREAKABLE_BOX, 500, -3000, -13437, 0, -90, 0, bhvBreakableBoxNoChild);

    if (left) {
        COMIT_OBJECT(MODEL_WALL_GOOMBA, -760, -3000, -13219, 0, 90, 0, bhvWallGoomba);
        COMIT_OBJECT(MODEL_WALL_GOOMBA, -760, -3000, -12691, 0, 90, 0, bhvWallGoomba);
        COMIT_OBJECT(MODEL_WALL_GOOMBA, -760, -3000, -12183, 0, 90, 0, bhvWallGoomba);
        COMIT_OBJECT(MODEL_WALL_GOOMBA, -760, -3000, -11501, 0, 90, 0, bhvWallGoomba);
        COMIT_OBJECT(MODEL_WALL_HAMMERBRO, -760, -3000, -12472, 0, 90, 0, bhvWallHammerBro);
        COMIT_OBJECT(MODEL_WALL_HAMMERBRO, -760, -3000, -11282, 0, 90, 0, bhvWallHammerBro);
        COMIT_OBJECT(MODEL_BREAKABLE_BOX, -800, -3000, -12976, 0, -90, 0, bhvBreakableBoxNoChild);
        COMIT_OBJECT(MODEL_BREAKABLE_BOX, -800, -3000, -11969, 0, -90, 0, bhvBreakableBoxNoChild);
    }
}


void ghost_bully_spawn_enemies(s32 dustBunnies) {
    struct Object *obj;
		COMIT_OBJECT(MODEL_NONE, 829, -3000, -12493, 0, 0, 0, bhvGoombaTripletSpawner);
		COMIT_OBJECT(MODEL_NONE, -250, -2800, -13387, 0, 0, 0, bhvSawbladeSpawn);
		COMIT_OBJECT(MODEL_NONE, 1250, -2800, -13387, 0, 0, 0, bhvSawbladeSpawn);
		COMIT_OBJECT(MODEL_SNUFIT, -404, -2800, -12299, 0, 0, 0, bhvSnufit);
		COMIT_OBJECT(MODEL_SNUFIT, 1454, -2800, -12989, 0, 0, 0, bhvSnufit);
		COMIT_OBJECT(MODEL_SNUFIT, 1371, -2800, -11374, 0, 0, 0, bhvSnufit);

    if (dustBunnies) {
		COMIT_OBJECT(MODEL_DUST_BUNNY, -420, -3000, -12445, 0, -180, 0, bhvDustBunny);
        obj->oBehParams = 2 << 16;
        obj->oBehParams2ndByte = 2;
		COMIT_OBJECT(MODEL_DUST_BUNNY, 1364, -3000, -12395, 0, -180, 0, bhvDustBunny);
        obj->oBehParams = 2 << 16;
        obj->oBehParams2ndByte = 2;
    }
}






void bhv_ghost_bully_init(void) {
    o->oForwardVel = 10.0f;
    obj_set_hitbox(o, &sGhostBullyHitbox);
}

void bhv_ghost_bully_loop(void) {
    if (gMarioCurrentRoom == o->oRoom) {
        ghost_bully_bounds_constraint();
        ghost_bully_mario_constraint();
    }
    switch (o->oAction) {
        case 0: // chase
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x400);
            o->oFaceAngleYaw = o->oMoveAngleYaw;
            CL_Move();
            o->oPosY = approach_f32_symmetric(o->oPosY, gMarioState->pos[1], 8.0f);
            if (o->oTimer > 180) {
                o->oAction = 1;
            }
            // if (o->oTimer > 180 && o->oDistanceToMario < 750.0f) {
            //     o->oAction = 3;
            //     o->oForwardVel = 40.0f;
            // }
            break;
        case 1: // start dash
            o->oFaceAngleYaw += 0x800;
            if (o->oTimer > 32) {
                o->oFaceAngleYaw = o->oMoveAngleYaw;
                o->oAction = 2;
                o->oForwardVel = 30.0f;
            }
            break;
        case 2: // dash
            CL_Move();
            if (o->oTimer > 45) {
                o->oAction = 0;
                o->oForwardVel = 10.0f;
            }
            break;
        case 3: // start slam
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x800);
            o->oFaceAngleYaw = o->oMoveAngleYaw;
            CL_Move();
            o->oPosY = approach_f32_symmetric(o->oPosY, gMarioState->pos[1] + 500.0f, 30.0f);
            if (lateral_dist_between_objects(o, gMarioObject) < 100.0f && o->oPosY > gMarioState->pos[1] + 400.0f) {
                o->oAction = 4;
                o->oFloatFC = gMarioState->pos[1];
            }
            break;
        case 4:
            if (o->oTimer > 15) {
                o->oPosY = approach_f32_symmetric(o->oPosY, o->oFloatFC, 30.0f);
                if (o->oInteractStatus) {
                    o->oTimer = 20;
                } 
                if (o->oTimer > 45) {
                    o->oAction = 0;
                    o->oForwardVel = 10.0f;
                }
            }
            break;
    }
    o->oInteractStatus = 0;
    if (gMarioState->input & INPUT_Z_PRESSED) {
        o->os16100 |= (1 << EH_ARROW);
        ghost_bully_spawn_wall_enemies(0);
        ghost_bully_spawn_enemies(1);
    }
}


void bhv_elevator_spawn_init(void) {
    o->oObjF8 = cur_obj_nearest_object_with_behavior(bhvGhostBully);
    if (o->oObjF8 == NULL) {
        o->activeFlags = 0;
    }
}



void bhv_elevator_moving_flame_init(void) {
    o->os16F4 = 255;
    o->os16F6 = 50;
    o->os16F8 = 0;
}


void bhv_elevator_moving_flame_loop(void) {
    if (o->oBehParams2ndByte) {
        o->oPosX += 15.0f;
    } else {
        o->oPosX -= 15.0f;
    }
    if (o->oTimer > (s32)(2500.0f / 15.0f)) {
        o->activeFlags = 0;
    }
}

void bhv_elevator_flame_spawn_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            if (o->oObjF8->os16100 & (1 << EH_FLAME)) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (o->oTimer > 90 + o->os16F4) { // was 45
                obj = spawn_object(o, MODEL_ENV_FLAME, bhvElevatorMovingFlame);
                if (o->oObjF8->os16100 & (1 << EH_FLAME2) && (random_u16() & 1)) {
                    obj->oBehParams2ndByte = 1;
                    obj->oPosX -= 2500.0f;
                }
                o->oTimer = 0;
                o->os16F6++;
                o->os16F4 = CL_RandomMinMaxU16(0, 30); // was max 25
            }

            if (!(o->oObjF8->os16100 & (1 << EH_FLAME))) {
                o->oAction = 0;
            }
            break;
    }
}

void bhv_sawblade_spawn_loop(void) {
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
        spawn_mist_particles();
        o->activeFlags = 0;
    }
}


void bhv_treadmill_floor_loop(void) {
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
            break;
    }
}