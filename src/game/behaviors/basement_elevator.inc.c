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


void bhv_ghost_bully_init(void) {
    o->oForwardVel = 10.0f;
    obj_set_hitbox(o, &sGhostBullyHitbox);
}

void bhv_ghost_bully_loop(void) {
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
}



void bhv_elevator_flame_spawn_loop(void) {
    struct Object *obj;
    if (o->oTimer > 45 + o->os16F4) {
        obj = spawn_object(o, MODEL_ENV_FLAME, bhvElevatorMovingFlame);
        if (o->os16F6 > 15 && (random_u16() & 1)) {
            obj->oBehParams2ndByte = 1;
            obj->oPosX -= 2500.0f;
        }
        o->oTimer = 0;
        o->os16F6++;
        o->os16F4 = CL_RandomMinMaxU16(0, 25);
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


void bhv_sawblade_spawn_loop(void) {
    if (o->oTimer > 45) {
        spawn_object(o, MODEL_SAWBLADE, bhvSawbladeShoot);
        o->oTimer = 0;
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