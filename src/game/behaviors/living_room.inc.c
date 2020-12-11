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


struct ObjectHitbox sCushionHitbox = {
    /* interactType: */ INTERACT_BOUNCE_TOP,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 1,
    /* numLootCoins: */ 0,
    /* radius: */ 150,
    /* height: */ 132,
    /* hurtboxRadius: */ 130,
    /* hurtboxHeight: */ 72,
};


void bhv_remote_init(void) {
   obj_set_hitbox(o, &sRemoteHitbox);
   o->oFloatF4 = 1.0f;
}



void bhv_remote_loop(void) {
    struct Object *obj = cur_obj_nearest_object_with_behavior(bhvTVStatic);
    struct Object *obj2;
    if (obj == NULL)
        return o->activeFlags = 0;
    o->oFaceAngleYaw += 0x380;
    switch (o->oAction) {
        case 0:
            if (obj->oAnimState == 0) {
                o->oAction = 1;
                o->oAnimState = 1;
            }
            if (o->oInteractStatus) {
                obj->oAnimState = 0;
                obj2 = spawn_object(o, MODEL_SPARKLES, bhvGoldenCoinSparkles);
                obj2->oPosY -= 50.0f;
                o->activeFlags = 0;
            }
            o->oFloatF4 = approach_f32(o->oFloatF4, 1.0f, 0.05f, 0.05f);
            obj_scale(o, o->oFloatF4);
            break;
        case 1:
            o->oFloatF4 = approach_f32(o->oFloatF4, 0.6f, 0.05f, 0.05f);
            obj_scale(o, o->oFloatF4);
            if (obj->oAnimState == 1) {
                o->oAction = 0;
                o->oAnimState = 0;
            }
            break;
    }
}


void bhv_tv_static_loop(void) {

}



void bhv_cushion_init(void) {
   obj_set_hitbox(o, &sCushionHitbox);
   o->oFloatF4 = 1.0f;
}


void bhv_cushion_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oInteractStatus)
                o->oAction = 1;
            break;
        case 1:
            o->oFloatF4 -= 0.15f;
            o->header.gfx.scale[1] = o->oFloatF4;
            if (o->oFloatF4 <= 0.6f) {
                o->oFloatF4 = 0.6f;
                o->oAction = 2;
            }
            break;
        case 2:
            o->oFloatF4 += 0.18;
            o->header.gfx.scale[1] = o->oFloatF4;
            if (o->oFloatF4 >= 1.4f) {
                o->oFloatF4 = 1.4f;
                o->oAction = 3;
            }
            break;
        case 3:
            o->oFloatF4 -= 0.08f;
            if (o->oFloatF4 <= 1.0f) {
                o->oFloatF4 = 1.0f;
                o->oAction = 0;
            }
            o->header.gfx.scale[1] = o->oFloatF4;
            break;
    }
    o->oInteractStatus = 0;
}