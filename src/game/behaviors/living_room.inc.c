struct ObjectHitbox sRemoteHitbox = {
    /* interactType: */ INTERACT_COIN,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 0,
    /* numLootCoins: */ 0,
    /* radius: */ 120,
    /* height: */ 84,
    /* hurtboxRadius: */ 0,
    /* hurtboxHeight: */ 0,
};


void bhv_remote_init(void) {
   obj_set_hitbox(o, &sRemoteHitbox);
   o->oFloatF4 = 1.0f;
}



void bhv_remote_loop(void) {
    struct Object *obj;
    o->oFaceAngleYaw += 0x380;
    if (o->oInteractStatus) {
        //obj = spawn_object(o, MODEL_SPARKLES, bhvGoldenCoinSparkles);
        //obj->oPosY -= 50.0f;
        //o->activeFlags = 0;
        o->oAnimState = 1;
        o->oFloatF4 = approach_f32(o->oFloatF4, 0.6f, 0.05f, 0.05f);
        obj_scale(o, o->oFloatF4);
    }
}


void bhv_tv_static_loop(void) {


    
}