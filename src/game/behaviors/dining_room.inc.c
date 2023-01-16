static struct ObjectHitbox sShyguyHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 2,
    /* radius:            */ 72,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 42,
    /* hurtboxHeight:     */ 40,
};

static struct ObjectHitbox sChairHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 110,
    /* height:            */ 80,
    /* hurtboxRadius:     */ 110,
    /* hurtboxHeight:     */ 80,
};

static struct ObjectHitbox sTeapotHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 70,
    /* height:            */ 70,
    /* hurtboxRadius:     */ 70,
    /* hurtboxHeight:     */ 70,
};

f32 sPlateGuyZPos[2] = {6815.44f, 6415.44f};


void bhv_shyguy_init(void) {
    obj_set_hitbox(o, &sShyguyHitbox);
    o->oOpacity = 0xFF;
}

void bhv_shyguy_loop(void) {
    struct Object *obj;
    cur_obj_scale(o->oGoombaScale);
    cur_obj_update_floor_and_walls();
    goomba_act_walk();
    cur_obj_move_standard(-78);
    if (o->oInteractStatus & INT_STATUS_INTERACTED && o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
            spawn_mist_particles();
            if (o->os16110) {
                obj = spawn_object(o, MODEL_SMALL_KEY, bhvSmallKey);
                obj->oBehParams2ndByte = o->oBehParams2ndByte;
                obj->oBehParams = obj->oBehParams2ndByte << 16;
                obj->oFaceAngleRoll = 0xF000;
                obj->oFaceAngleYaw = 0;
                // obj->oPosX = o->oHomeX;
                // obj->oPosZ = o->oHomeZ;
                obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
            } else {
                obj_spawn_loot_yellow_coins(o, o->oNumLootCoins, 20.0f);
            }
            o->activeFlags = 0;
            create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
    }
    o->oInteractStatus = 0;
}



void bhv_shyguy_plate_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            if (gMarioState->pos[2] > 6000.0f && gMarioState->pos[1] > 950.0f) {
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
            o->oPosZ = approach_f32(o->oPosZ, sPlateGuyZPos[o->oF4], 10.0f, 10.0f);
            if (gMarioState->pos[2] < 6000.0f || gMarioState->pos[1] < 950.0f) {
                o->oAction = 0;
            }
            break;
        case 2:
            obj = spawn_object(o, MODEL_PLATE, bhvSpinPlate);
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




void bhv_spin_plate_init(void) {
    o->oForwardVel = 15.0f;
    o->oAngleVelYaw = 0x300;
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


void bhv_table_barrier_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 180, 4);
            if (o->oOpacity == 180) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (cur_obj_nearest_object_with_behavior(bhvShyguyChair) == NULL) {
                o->oAction = 2;
            }
            break;
        case 2:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 6);
            if (o->oOpacity == 0) {
                o->activeFlags = 0;
            }
            break;
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
    struct Object *obj;
    s16 yaw;
    switch (o->oAction) {
        case 0:
            o->oOpacity = 0;
            cur_obj_disable();
            if (gMarioState->pos[1] > 100.0f) {
                if (gMarioState->pos[0] > 7002.0f && gMarioState->pos[0] < 7386.0f) {
                    if (gMarioState->pos[2] > 5181.0f && gMarioState->pos[2] < 5565.0f) {
                        o->oAction = 1;
                        o->oFC = 75;
                        obj = spawn_object(o, MODEL_TABLE_BARRIER, bhvTableBarrier);
                        obj->oPosY -= 362.0f;
                    }
                }
            }
            break;
        case 1:
            shyguy_clamp_mario_on_table(gMarioState);
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 10);
            if (o->oOpacity == 0)
                cur_obj_disable();
            if (o->oTimer > o->oFC) {
                o->oAction = 2;
            }
            if (o->oF4 > 4) {
                //cur_obj_set_behavior(bhvGoomba);
                //cur_obj_enable();
                //o->oAction = 3;
                obj = spawn_object(o, MODEL_SHYGUY, bhvShyguy);
                obj->oOpacity = 255;
                obj->oVelY = 20.0f;
                o->activeFlags = 0;
                cur_obj_play_sound_2(SOUND_OBJ_GOOMBA_ALERT);
            }
            break;
        case 2:
            shyguy_clamp_mario_on_table(gMarioState);
            if (o->oTimer == 0) {
                cur_obj_enable();
                obj = CL_obj_nearest_object_behavior_params(bhvDiningChair, o->oF4 << 16);
                if (obj == NULL) {
                    o->activeFlags = 0;
                    break;
                }
                o->oPosX = obj->oPosX;
                o->oPosZ = obj->oPosZ;
                yaw = cur_obj_angle_to_home();
                //yaw = CL_angle_between_points(&obj->oPosX, &o->oHomeX);
                o->oPosX = obj->oPosX - (75.0f * sins(yaw));
                o->oPosZ = obj->oPosZ - (75.0f * coss(yaw));
                o->oPosY = 275.0f;
                o->oFaceAngleYaw = (o->oMoveAngleYaw = yaw);
            }
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 50 + (o->oF4 * 10), 10);
            break;
        //case 3:
        //    bhv_shyguy_loop();
        //    break;
    }


}

void bhv_dining_chair_init(void) {
    o->oF8 = 7 * o->oBehParams2ndByte;
    o->oFloatFC = 1.0f;
    //o->oFC = 0x2AAA * o->oBehParams2ndByte;
    o->parentObj = cur_obj_nearest_object_with_behavior(bhvShyguyChair);
    if (o->parentObj == NULL)
        o->activeFlags = 0;
}


void bhv_dining_chair_loop(void) {
    f32 dist;
    s16 pitch, yaw;
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
            o->o100 = approach_s16_symmetric(o->o100, 0x300, 0x10);
            o->oFaceAngleYaw += o->o100;
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
            create_sound_spawner(SOUND_GENERAL_SWISH_AIR_2);
            o->oPosY = approach_f32(o->oPosY, 330.0f, 10.0f, 10.0f);
            //pitchApproach = CL_obj_pitch_to_mario() + 0x4000;
            //o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, pitchApproach, 0x200);
            //o->oFaceAngleRoll += 0x1200;
            o->oFaceAngleYaw += 0x1C00;
            o->oFloatFC = approach_f32(o->oFloatFC, 0.87f, 0.06f, 0.06f);
            cur_obj_scale(o->oFloatFC);
            if (o->oTimer > 30) {
                o->oAction = 4;
                o->oForwardVel = 65.0f;
                //vec3f_get_dist_and_angle(&o->oPosX, gMarioState->pos, &dist, &pitch, &yaw);
                o->oMoveAngleYaw = o->oAngleToMario;//yaw;
                o->oMoveAnglePitch = 0xF500;//pitch;
                obj_set_hitbox(o, &sChairHitbox);
            }
            break;
        case 4:
            o->oFaceAngleYaw += 0x1C00;
            CL_Move_3d();
            cur_obj_update_floor_and_walls();
            if (o->oMoveFlags & OBJ_MOVE_HIT_WALL || o->oMoveFlags & OBJ_MOVE_ON_GROUND 
            || o->oInteractStatus & INT_STATUS_INTERACTED) {
                obj_explode_and_spawn_coins(46.0f, 0);
                create_sound_spawner(SOUND_GENERAL_HAUNTED_CHAIR_MOVE);
                o->parentObj->oF4++;
                o->parentObj->oAction = 1;
                o->parentObj->oFC = CL_RandomMinMaxU16(30, 50);
            }
            break;
    }
}


void bhv_blocking_chair_init(void) {
    if (save_file_get_rooms(o->oRoom / 32) & (1 << (o->oRoom % 32))) {
        o->activeFlags = 0;
    }
}


void bhv_blocking_chair_loop(void) {
    struct Object *obj = cur_obj_nearest_object_with_behavior(bhvBlockedDoor);
    if (obj != NULL)
        obj->oF4 = 1;
    switch (o->oAction) {
        case 0:
            if (save_file_get_rooms(o->oRoom / 32) & (1 << (o->oRoom % 32))) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY - 300.0f, 8.0f);
            if (o->oPosY == o->oHomeY - 300.0f) {
                o->activeFlags = 0;
                if (obj != NULL)
                    obj->oF4 = 0;
            }
            break;
    }
}


void bhv_teapot_spawn_loop(void) {
    switch (o->oBehParams2ndByte) {
        case 0:
            o->oFloatF4 = absf(o->oPosX - gMarioState->pos[0]);
            o->oFloatF8 = o->oPosZ - gMarioState->pos[2];
            break;
        case 1:
            o->oFloatF4 = absf(o->oPosZ - gMarioState->pos[2]);
            o->oFloatF8 = o->oPosX - gMarioState->pos[0];
            break;
        case 2:
            o->oFloatF4 = absf(o->oPosX - gMarioState->pos[0]);
            o->oFloatF8 = gMarioState->pos[2] - o->oPosZ;
            break;
        case 3:
            o->oFloatF4 = absf(o->oPosZ - gMarioState->pos[2]);
            o->oFloatF8 = gMarioState->pos[0] - o->oPosX;
            break;
    }

    switch (o->oAction) {
        case 0:
            if (o->oFloatF4 < 600.0f) {
                if (o->oFloatF8 > 0.0f && o->oFloatF8 < 1000.0f) {
                    o->oAction = 1;
                    o->oFC = CL_RandomMinMaxU16(35, 60);
                }
            }
            break;
        case 1:
            if (o->oFloatF4 > 600.0f || o->oFloatF8 < 0.0f || o->oFloatF8 > 1000.0f) {
                o->oAction = 0;
            }
            if (o->oTimer > o->oFC) {
                spawn_object(o, MODEL_TEAPOT, bhvTeapot);
                o->oAction = 2;
            }
            break;
        case 2:
            break;
    }
}

void bhv_teapot_init(void) {
    s16 pitch, yaw;
    f32 dist;
    vec3f_get_dist_and_angle(&o->oPosX, gMarioState->pos, &dist, &pitch, &yaw);
    o->oMoveAnglePitch = pitch;
    o->oMoveAngleYaw = yaw;
    obj_set_hitbox(o, &sTeapotHitbox);
    cur_obj_become_intangible();

}

void bhv_teapot_loop(void) {
    s16 pitch, yaw;
    f32 dist;
    o->oFaceAngleYaw += 0x1C00;
    switch (o->oAction) {
        case 0:
            vec3f_get_dist_and_angle(&o->oPosX, gMarioState->pos, &dist, &pitch, &yaw);
            o->oMoveAnglePitch = pitch;
            o->oFaceAnglePitch = -pitch + 0x4000;
            o->oMoveAngleYaw = yaw;
            if (o->oTimer > 30) {
                o->oAction = 1;
                cur_obj_become_tangible();
            }
            break;
        case 1:
            o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 52.0f, 3.0f);
            CL_Move_3d();
            cur_obj_update_floor_and_walls();
            // o->oFaceAngleRoll += 0x1C00;
            // o->oFaceAnglePitch += 0x1C00;
            if (o->oTimer > 30 || o->oMoveFlags & OBJ_MOVE_HIT_WALL || o->oMoveFlags & OBJ_MOVE_ON_GROUND 
            || o->oInteractStatus & INT_STATUS_INTERACTED) {
                spawn_mist_particles_variable(0, 0, 25.0f);
                spawn_triangle_break_particles(6, 138, 1.0f, 4);
                create_sound_spawner(SOUND_GENERAL_HAUNTED_CHAIR_MOVE);
                o->activeFlags = 0;
                o->parentObj->oAction = 1;
                o->parentObj->oFC = CL_RandomMinMaxU16(35, 60);
            }
            break;
    }
}