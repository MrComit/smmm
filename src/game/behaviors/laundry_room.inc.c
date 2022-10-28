s32 absi(s32 a0);
struct ObjectHitbox sClothesShotHitbox = {
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

void bhv_clothes_shot_init(void) {
    obj_set_hitbox(o, &sClothesShotHitbox);
    o->oForwardVel = 24.0f;
    // o->oMoveAngleYaw = o->parentObj->oFaceAngleYaw;
    // o->oMoveAnglePitch = -o->parentObj->oFaceAnglePitch;
    o->oPosY += 100.0f;

    // o->os16F4 = 0x00;
    // o->os16F6 = 0xA0;
    // o->os16F8 = 0xFF;
    s32 hue = CL_RandomMinMaxU16(0, 360);
    f32 sat = (random_float() * 0.3f) + 0.7f;
    f32 val = (random_float() * 0.2f) + 0.8f;
    CL_HSVtoRGB(hue, sat, val, &o->os16F4, &o->os16F6,  &o->os16F8);
}

void bhv_clothes_shot_loop(void) {
    CL_Move();
    o->oFaceAngleYaw += 0x200;
    o->oFaceAngleRoll += 0x400;
    // if (absi((u16)o->oAngleToMario - (u16)o->oMoveAngleYaw) < 0x2000) {
        o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x380);
    // }

    if (o->oTimer > 15) {
        cur_obj_update_floor_and_walls();
        if (o->oFloor != NULL && o->oFloorType == SURFACE_GENERAL_USE && o->oFloor->object != NULL) {
            o->oFloor->object->oAction = 1;
            o->activeFlags = 0;
            spawn_mist_particles();
            play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gGlobalSoundSource);
        }

        if (o->oMoveFlags & OBJ_MOVE_HIT_WALL || o->oInteractStatus & INT_STATUS_INTERACTED || o->oTimer > 500) {
            o->activeFlags = 0;
            spawn_mist_particles();
        }
    }
}



void bhv_basement_dryer_init(void) {


}

void bhv_basement_dryer_loop(void) {
    switch (o->oAction) {
        case 1:
            cur_obj_init_animation(0);
            o->oAction = 2;
            o->collisionData = segmented_to_virtual(&basement_dryer_collision);
            break;
    }
}


void bhv_basement_washer_init(void) {


}

void bhv_basement_washer_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 1750.0f && absi((u16)o->oAngleToMario - (u16)o->oFaceAngleYaw) < 0x2C00) {
                if (o->oTimer > 5) {
                    cur_obj_init_animation(1);
                    o->oAction = 1;
                }
            } else {
                o->oTimer = 0;
            }

            break;
        case 1:
            if (cur_obj_set_anim_if_at_end(0)) {
                o->oAction = 2;
                o->oObjF4 = spawn_object(o, MODEL_CLOTHES_BALL, bhvClothesShot);
            }
            break;
        case 2:
            if (cur_obj_set_anim_if_at_end(2)) {
                if (o->oObjF4->activeFlags == 0) {
                    o->oObjF4 = NULL;
                    o->oAction = 0;
                }
            }
            break;
    }
}