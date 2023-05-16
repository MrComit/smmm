f32 sMemPlateZPos[2] = {-28510.0f, -28910.0f};



void bhv_mem_bath_floor_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioState->pos[1] < 3200.0f && gMarioState->pos[1] > -2000.0f) {
                if (o->oTimer & 1) {
                    o->oPosY -= 2.0f;
                } else {
                    o->oPosY += 2.0f;
                }
                if (o->oTimer > 100) {
                    o->oAction = 1;
                }
            }
            break;
        case 1:
            o->oFloatF4 = approach_f32_symmetric(o->oFloatF4, 150.0f, 10.0f);
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY + 2270.0f, o->oFloatF4);
            if (o->oPosY == o->oHomeY + 2270.0f) {
                o->oAction = 2;
                o->oFloatF4 = 0.0f;
            }
            break;
        case 2:
            if (o->oTimer > 50) {
                o->oFloatF4 = approach_f32_symmetric(o->oFloatF4, 150.0f, 10.0f);
                o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, o->oFloatF4);
                if (o->oPosY == o->oHomeY) {
                    o->oAction = 0;
                    o->oFloatF4 = 0.0f;
                }
            }
            break;
    }
}


void bhv_mem_falling_floor_init(void) {
    o->oFloatF4 = 10.0f;
}


void bhv_mem_falling_floor_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oFloatF4 = approach_f32(o->oFloatF4, 60.0f, 1.1f, 1.1f);
            o->oPosY -= o->oFloatF4;
            if (o->oPosY < o->oHomeY - 2200.0f) {
                CL_explode_object(o, 1);
                o->oAction = 2;
            }
            break;
    }
}









void bhv_spin_plate_big_init(void) {
    o->oForwardVel = 37.0f;
    o->oAngleVelYaw = 0x300;
    o->oFloatF4 = 4.5f;
    o->oGraphYOffset = 30.0f;
    o->oPosY -= 30.0f;
}



void bhv_spin_plate_big_loop(void) {
    switch (o->oAction) {
        case 0:
            if (cur_obj_nearest_object_with_behavior(bhvMemShyguyPlate) == NULL) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (o->oTimer > 20) {
                o->oAction = 2;
                cur_obj_unhide();
            }
            break;
        case 2:
            CL_Move();
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 1.5f);
            o->oGraphYOffset = approach_f32_symmetric(o->oGraphYOffset, 0.0f, 1.5f);
            o->oFaceAngleYaw += o->oAngleVelYaw;
            //if (o->oPosX > 8220.0f)
            //    o->activeFlags = 0;
            if (o->oPosX > -21900.0f) {
                cur_obj_scale(o->oFloatF4);
                o->oFloatF4 -= 0.20f;
                if (o->oFloatF4 < 0.01f)
                    o->activeFlags = 0;
            }
            break;
    }
}



void bhv_mem_wall_loop(void) {
    struct Object *obj = cur_obj_nearest_object_with_behavior(bhvMemSpinPlateBig);
    if (obj == NULL || obj->oPosX > -23175.0f) {
        CL_explode_object(o, 1);
    }
}

void bhv_mem_shyguy_plate_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            if (gMarioState->pos[2] > -29100.0f && gMarioState->pos[1] > 7900.0f) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (o->oTimer > 20) {
                o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, 0x2000, 0x200);
            } else {
                o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, 0, 0x200);
            }
            if (o->oTimer > 30) {
                o->oAction = 2;
            }
            o->oPosZ = approach_f32(o->oPosZ, sMemPlateZPos[o->oF4], 10.0f, 10.0f);
            if (gMarioState->pos[2] < -29100.0f || gMarioState->pos[1] < 7900.0f) {
                o->oAction = 0;
            }
            break;
        case 2:
            obj = spawn_object(o, MODEL_MEM_PLATE, bhvMemSpinPlate);
            obj->oFaceAnglePitch = 0;
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
