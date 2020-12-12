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

void tv_spawn_peepa(s32 count) {
    s32 i;
    for (i = 0; i < count; i++) {
        spawn_object_relative(i, 0, -50, -200, o, MODEL_PEEPA, bhvTVPeepa);
    }
}


void bhv_tv_static_loop(void) {
    if (o->oAnimState == 0) {
        switch (o->oAction) {
            case 0:
                tv_spawn_peepa(o->oBehParams2ndByte + 3);
                o->oAction = 1;
                break;
            case 1:
                if (count_room_objects_with_behavior(bhvTVPeepa, o->oRoom) == 0) {
                    o->oAnimState = 1;
                    o->oAction = 0;
                    o->oBehParams2ndByte++;
                    if (o->oBehParams2ndByte >= 4) {
                        o->activeFlags = 0;
                    }
                }
                break;
        }
    }
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
            o->header.gfx.scale[0] = approach_f32(o->header.gfx.scale[0], 1.1f, 0.04f, 0.04f);
            o->header.gfx.scale[2] = o->header.gfx.scale[0];
            if (o->oFloatF4 <= 0.6f) {
                o->oFloatF4 = 0.6f;
                o->oAction = 2;
            }
            break;
        case 2:
            o->oFloatF4 += 0.18f;
            o->header.gfx.scale[1] = o->oFloatF4;
            o->header.gfx.scale[0] = approach_f32(o->header.gfx.scale[0], 0.8f, 0.07f, 0.07f);
            o->header.gfx.scale[2] = o->header.gfx.scale[0];
            if (o->oFloatF4 >= 1.4f) {
                o->oFloatF4 = 1.4f;
                o->oAction = 3;
            }
            break;
        case 3:
            o->oFloatF4 -= 0.08f;
            o->header.gfx.scale[0] = approach_f32(o->header.gfx.scale[0], 1.0f, 0.04f, 0.04f);
            o->header.gfx.scale[2] = o->header.gfx.scale[0];
            if (o->oFloatF4 <= 1.0f) {
                o->header.gfx.scale[0] = (o->header.gfx.scale[2] = 1.0f);
                o->oFloatF4 = 1.0f;
                o->oAction = 0;
            }
            o->header.gfx.scale[1] = o->oFloatF4;
            break;
    }
    o->oInteractStatus = 0;
}


void bhv_tv_peepa_init(void) {
    o->oForwardVel = 15.0f;
    o->oF8 = o->oBehParams2ndByte * 15;
    o->oF4 = o->oBehParams2ndByte * 0x2000;
    o->oFC = o->oBehParams2ndByte * 0x2AAA;

    o->oObj108 = spawn_object(o, MODEL_NUMBER, bhvPeepaNumber);
    o->oObj108->oAnimState = o->oBehParams2ndByte;
}

void bhv_tv_peepa_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oTimer > o->oF8)
                CL_Move();
            o->oF4 += 0x800;
            o->oGraphYOffset = 25.0f * sins(o->oF4);
            if (o->oTimer > 120) {
                o->oAction = 1;
                o->oFloat100 = o->oPosX + (1550.0f * sins(o->oFC));
                o->oFloat104 = o->oPosZ + (1550.0f * coss(o->oFC));
            }
            break;
        case 1:
            o->oPosX = approach_f32(o->oPosX, o->oFloat100, 20.0f, 20.0f);
            o->oPosZ = approach_f32(o->oPosZ, o->oFloat104, 20.0f, 20.0f);
            if (o->oTimer > 60) {
                o->oAction = 2;
                o->oObj108->activeFlags = 0;
            }
            break;
        case 2:
            break;
    }
}


void bhv_peepa_number_loop(void) {
    if (o->parentObj == o)
        return o->activeFlags = 0;

    o->oPosX = o->parentObj->oPosX;
    o->oPosY = o->parentObj->oPosY + o->parentObj->oGraphYOffset + 100.0f;
    o->oPosZ = o->parentObj->oPosZ;
}