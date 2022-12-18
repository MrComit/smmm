static struct ObjectHitbox sSawbladeHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 2,
    /* radius:            */ 90,
    /* height:            */ 90,
    /* hurtboxRadius:     */ 90,
    /* hurtboxHeight:     */ 90,
};


void bhv_sawblade_spawn_loop(void) {
    f32 m = coss(o->oFaceAngleYaw) / sins(o->oFaceAngleYaw);
    f32 b = o->oPosZ - (o->oPosX * m);
    f32 e1 = absf((m * gMarioState->pos[0]) - gMarioState->pos[2] + b);
    f32 d = e1 / sqrtf(m*m + 1);
    f32 yDif = absf(gMarioState->pos[1] - o->oPosY);
    if (d < 500.0f && yDif < 500.0f) {
        if (o->oTimer > 60) {
            spawn_object(o, MODEL_SAWBLADE, bhvSawbladeShoot);
            o->oTimer = 0;
        }
    } else {
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


void bhv_sawblade_move_init(void) {
    obj_set_hitbox(o, &sSawbladeHitbox);
    o->oFloatF8 = (o->oBehParams >> 24) * 10.0f;
    CL_drop_to_floor();
}


void bhv_sawblade_move_loop(void) {
    // o->oFaceAngleRoll -= 0x400;
    o->os16F4 += 0xC0;
    o->oPosX = o->oHomeX + (sins(o->os16F4) * o->oFloatF8);
    o->oPosZ = o->oHomeZ + (coss(o->os16F4) * o->oFloatF8);
    if (o->oBehParams >> 24) {
        o->oFaceAngleYaw = cur_obj_angle_to_home();
        CL_drop_to_floor();
    }
    o->oInteractStatus = 0;
}

void bhv_swinging_plat_loop(void) {
    o->os16F4 += 0x200;
    o->oFaceAnglePitch = -sins(o->os16F4) * 0x320;
    o->oFloatF8 = -sins(o->os16F4) * 500.0f;
    o->oPosX = o->oHomeX + (sins(o->os16F4) * 500.0f) * sins(o->oFaceAngleYaw);
    o->oPosZ = o->oHomeZ + (sins(o->os16F4) * 500.0f) * coss(o->oFaceAngleYaw);
    f32 homeD = o->oHomeX * sins(o->oFaceAngleYaw) + o->oHomeZ * coss(o->oFaceAngleYaw);
    f32 posD = o->oPosX * sins(o->oFaceAngleYaw) + o->oPosZ * coss(o->oFaceAngleYaw);
    f32 riseSqr = (homeD - posD) * (homeD - posD);
    f32 yRise = sqrtf(1440000 - riseSqr);
    o->oPosY = o->oHomeY + (1200.0f - yRise);
}