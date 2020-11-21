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
            if (o->oTimer > 20) {
                cur_obj_init_anim_and_check_if_end(2);
            } else if (o->oTimer > 11) {
                cur_obj_init_anim_and_check_if_end(0);
            }
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


void shyguy_clamp_mario_on_table(struct MarioState *m) {
    if (m->pos[0] > 7586.0f)
        m->pos[0] = 7586.0f;
    else if (m->pos[0] < 6802.0f)
        m->pos[0] = 6802.0f;

    if (m->pos[2] > 5765.0f)
        m->pos[2] = 5765.0f;
    else if (m->pos[2] < 4981.0f)
        m->pos[2] = 4981.0f;
}


void bhv_shyguy_chair_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioState->pos[1] > 100.0f) {
                if (gMarioState->pos[0] > 6802.0f && gMarioState->pos[0] < 7586.0f) {
                    if (gMarioState->pos[2] > 4981.0f && gMarioState->pos[2] < 5765.0f) {
                        o->oAction = 1;
                    }
                }
            }
            break;
        case 1:
            shyguy_clamp_mario_on_table(gMarioState);
            if (o->oTimer > 90) {
                o->oAction = 2;
            }
            break;
        case 2:
            break;
    }


}

void bhv_dining_chair_init(void) {
    o->oF8 = 7 * o->oBehParams2ndByte;
    //o->oFC = 0x2AAA * o->oBehParams2ndByte;
    o->parentObj = cur_obj_nearest_object_with_behavior(bhvShyguyChair);
    if (o->parentObj == NULL)
        o->activeFlags = 0;
}


void bhv_dining_chair_loop(void) {
    s16 pitchApproach;
    switch (o->oAction) {
        case 0:
            load_object_collision_model();
            if (o->parentObj->oAction == 1) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (o->oTimer > o->oF8) {
                o->oPosY = 100.0f + (100.0f * -coss(o->oF4));
                o->oF4 += 0x600;
            }
            o->oPosX = 7194.0f + (sins(o->oFaceAngleYaw + 0x8000) * 642.0f);
            o->oPosZ = 5373.0f + (coss(o->oFaceAngleYaw + 0x8000) * 642.0f);
            o->oFaceAngleYaw += 0x300;
            if (o->parentObj->oAction == 2) {
                if (o->parentObj->oF4 == o->oBehParams2ndByte)
                    o->oAction = 3;
                else
                    o->oAction = 2;
            }
            break;
        case 2:
            o->oPosY = 100.0f + (100.0f * -coss(o->oF4));
            o->oF4 += 0x600;
            if (o->parentObj->oAction == 1) {
                o->oAction = 1;
            }
            break;
        case 3:
            o->oPosY = approach_f32(o->oPosY, 200.0f, 10.0f, 10.0f);
            //pitchApproach = CL_obj_pitch_to_mario() + 0x4000;
            //o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, pitchApproach, 0x200);
            //o->oFaceAngleRoll += 0x1200;
            o->oFaceAngleYaw += 0x1200;
            break;
    }
}