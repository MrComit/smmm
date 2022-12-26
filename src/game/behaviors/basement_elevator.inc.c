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