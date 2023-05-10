struct ObjectHitbox sFallingBombHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 3,
    /* numLootCoins:      */ 2,
    /* radius:            */ 200,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 200,
    /* hurtboxHeight:     */ 50,
};


void bhv_jenga_plat_init(void) {
    o->oObjF4 = cur_obj_nearest_object_with_behavior(bhvObservatorySpinningPlat);
}


void bhv_jenga_plat_loop(void) {
    if (o->oObjF4 == NULL) {
        o->activeFlags = 0;
        return;
    }
    switch (o->oAction) {
        case 0:
            if (o->oPosY <= o->oObjF4->oPosY + 50.0f) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oPosY = o->oObjF4->oPosY + 50.0f;
            if (o->oTimer > 30*o->oBehParams2ndByte) {
                o->oObjF8 = spawn_object(o, MODEL_BLACK_BOBOMB, bhvObservatoryBomb);
                vec3f_set(&o->oObjF8->oPosX, o->oPosX, o->oPosY + 800.0f, o->oPosZ);
                o->oAction = 2;
            }
            break;
        case 2:
            o->oPosY = o->oObjF4->oPosY + 50.0f;
            if (o->oObjF8 == NULL || o->oObjF8->activeFlags == 0) {
                CL_explode_object(o, 1);
            }
            break;
    }
}


void bhv_observatory_bomb_init(void) {
    obj_set_hitbox(o, &sFallingBombHitbox);
    // vec3f_set(&o->oPosX, gMarioState->pos[0], gMarioState->pos[1] + 600.0f, gMarioState->pos[2]);
    o->oFaceAngleYaw = random_u16();
    // vec3f_set(o->header.gfx.scale, 0.25f, 0.35f, 0.6f);
    // o->oGraphYOffset = -35.0f;
}

void bhv_observatory_bomb_loop(void) {
    struct Object *obj;
    o->oF8 += 0x800;
    // o->oFaceAngleRoll = 0x600 * sins(o->oF8);
    o->oFaceAnglePitch += 0x600;
    o->oFloatF4 = approach_f32_symmetric(o->oFloatF4, 30.0f, 1.2f);
    o->oPosY -= o->oFloatF4;
    if (o->oInteractStatus || object_step() & 1 || o->oTimer > 90) {
        obj = spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
        // obj->oGraphYOffset += 100.0f;
        obj->oIntangibleTimer = -1;
        o->activeFlags = 0;
        if (CL_RandomMinMaxU16(0, 20) == 0) {
            obj_force_spawn_loot_coins(o, 1, 20.0f, bhvSingleCoinGetsSpawned, 0, MODEL_YELLOW_COIN);
        }
    }
    // obj = cur_obj_nearest_object_with_behavior(bhvShyGuyBoss);
    // if (obj == NULL || obj->os16F6 == 0) {
    //     o->activeFlags = 0;
    // }
}


void observatory_spawn_bombs(void) {
    struct Object *obj;
    Vec3f pos;
    if (++o->os16F4 > o->os16F6) {
        o->os16F4 = 0;
        o->os16F6 = CL_RandomMinMaxU16(70, 120);
        obj = spawn_object(o, MODEL_BLACK_BOBOMB, bhvObservatoryBomb);
        vec3f_set(&obj->oPosX, gMarioState->pos[0], gMarioState->pos[1] + 600.0f, gMarioState->pos[2]);
    }


    if (++o->os16F8 > o->os16FA) {
        o->os16F8 = 0;
        o->os16FA = CL_RandomMinMaxU16(15, 35);
        obj = spawn_object(o, MODEL_BLACK_BOBOMB, bhvObservatoryBomb);
        pos[1] = o->oPosY + 800.0f;

        pos[0] = o->oPosX + (1500.0f * random_float()) - 750.0f;
        pos[2] = o->oPosZ + (1500.0f * random_float()) - 750.0f;

        vec3f_copy(&obj->oPosX, pos);
    }

}

void bhv_observatory_spinning_plat_init(void) {
    o->os16F6 = 90;
    o->os16FA = 20;
}

void bhv_observatory_spinning_plat_loop(void) {
    // return;
    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (o->oTimer > 50) {
                o->oAction = 2;
                o->oVelY = 5.0f;
            }
            break;
        case 2:
            observatory_spawn_bombs();
            o->os16FC = approach_s16_symmetric(o->os16FC, 0x80, 0xC);
            o->oFaceAngleYaw += o->os16FC;
            o->oPosY += 5.0f;
            // if (gMarioObject->platform == o) {
            //     gMarioState->pos[1] += 10.0f;
            //     if (gMarioState->vel[1] > 0.0f) {
            //         gMarioState->vel[1] += 10.0f;
            //     }
            // }
            break;
    }
    //     if (gMarioObject->platform == o) {
    //         o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY - 20.0f, 2.0f);
    //     } else {
    //         o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 2.0f);
    //     }
}
