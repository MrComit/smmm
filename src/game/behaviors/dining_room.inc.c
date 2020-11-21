static struct ObjectHitbox sShyguyHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 72,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 42,
    /* hurtboxHeight:     */ 40,
};

f32 sPlateGuyZPos[2] = {6815.44f, 6415.44f};


void bhv_shyguy_init(void) {
    obj_set_hitbox(o, &sShyguyHitbox);
}


void bhv_shyguy_plate_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioState->pos[2] > 6000.0f && gMarioState->pos[1] > 950.0f) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (o->oTimer > 30) {
                o->oAction = 2;
            }
            o->oPosZ = approach_f32(o->oPosZ, sPlateGuyZPos[o->oF4], 10.0f, 10.0f);
            if (gMarioState->pos[2] < 6000.0f || gMarioState->pos[1] < 950.0f) {
                o->oAction = 0;
            }
            break;
        case 2:
            spawn_object(o, MODEL_PLATE, bhvSpinPlate);
            o->oAction = 1;
            if (o->oF4 == 0)
                o->oF4 = 1;
            else
                o->oF4 = 0;
            break;
    }

    if (o->oInteractStatus & INT_STATUS_INTERACTED && o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
            spawn_mist_particles();
            obj_spawn_loot_yellow_coins(o, o->oNumLootCoins, 20.0f);
            o->activeFlags = 0;
            create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
    }
    o->oInteractStatus = 0;
}




void bhv_spin_plate_init(void) {
    o->oForwardVel = 15.0f;
    o->oAngleVelYaw = 0x400;
    o->oFloatF4 = 1.8f;
}



void bhv_spin_plate_loop(void) {
    CL_Move();
    o->oFaceAngleYaw += o->oAngleVelYaw;
    //if (o->oPosX > 8220.0f)
    //    o->activeFlags = 0;
    if (o->oTimer > 145) {
        cur_obj_scale(o->oFloatF4);
        o->oFloatF4 -= 0.08f;
        if (o->oFloatF4 < 0.01f)
            o->activeFlags = 0;
    }
}