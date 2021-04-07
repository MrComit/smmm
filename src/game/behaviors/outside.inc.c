s32 approach_f32_ptr(f32 *px, f32 target, f32 delta);

struct ObjectHitbox sPoochyHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 3,
    /* numLootCoins:      */ 0,
    /* radius:            */ 400,
    /* height:            */ 550,
    /* hurtboxRadius:     */ 400,
    /* hurtboxHeight:     */ 550,
};


s32 sSunflowers = 0;

void bhv_flower_wall_init(void) {
    o->oOpacity = 0xFF;
    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_FLOWER_DOOR) {
        o->activeFlags = 0;
    }
    o->activeFlags = 0;
}


void bhv_flower_wall_loop(void) {
    switch (o->oAction) {
        case 0:
            if (sSunflowers >= 3) {
               o->oAction = 1;
               play_puzzle_jingle();
            }
            break;
        case 1:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 10);
            if (o->oOpacity < 10) {
                o->activeFlags = 0;
                save_file_set_newflags(SAVE_NEW_FLAG_FLOWER_DOOR, 0);
            }
            break;
    }
}


void bhv_poochy_boss_init(void) {
    cur_obj_disable();
    obj_set_hitbox(o, &sPoochyHitbox);
}

void bhv_poochy_boss_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oTimer > 90) {
                o->oAction = 1;
                cur_obj_enable();
            }
            break;
        case 1:
            cur_obj_move_standard(-78);
            if (o->oMoveFlags & OBJ_MOVE_ON_GROUND) {
                o->oAction = 2;
                o->oObjF4 = spawn_object(o, MODEL_NONE, bhvGardenHoles);
                o->oObjF4->oPosX = o->oObjF4->oPosZ = 0;
                o->oObjF4->oPosY = -488.0f;
                o->oObjF4->oFaceAngleYaw = o->oObjF4->oMoveAngleYaw = 0;
            }
            break;
        case 2:
            cur_obj_move_standard(-78);
            cur_obj_update_floor_and_walls();
            if (o->os16FA == 0) {
                o->oForwardVel = approach_f32(o->oForwardVel, 40.0f, 0.5f, 0.5f);
                o->oMoveAngleYaw += 0x100;
                if (o->oTimer > 180) {
                    o->os16FA = 1;
                }
            } else {
                o->oForwardVel = approach_f32(o->oForwardVel, 30.0f, 1.0f, 1.0f);
                o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x180);
                if (o->oDistanceToMario < 1500.0f && (absi(o->oMoveAngleYaw - o->oAngleToMario) < 0x1000 || o->os16F8 != 0)) {
                    if (o->os16F8 > (2 - o->oHealth)) {
                        o->oAction = 3;
                    } else {
                        o->oAction = 6;
                    }
                    o->oVelY = 77.0f;
                    o->oForwardVel = 40.0f;
                    o->os16FA = 0;
                }
            }
            break;
        case 3:
            cur_obj_move_standard(-78);
            cur_obj_update_floor_and_walls();
            o->oForwardVel = approach_f32(o->oForwardVel, 8.0f, 0.5f, 0.5f);
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x20);
            if (o->oMoveFlags & OBJ_MOVE_ON_GROUND) {
                o->oAction = 4;
                o->oPosY -= 200.0f;
                o->os16F8 = 0;
            }
            if (dist_between_objects(o, gMarioObject) < 400.0f) {
                CL_get_hit(gMarioState, o, 2);
                o->oAction = 2;
                o->os16F8 = 0;
            }
            o->oInteractType = INTERACT_BOUNCE_TOP;
            break;
        case 4:
            if (o->oSubAction == 0) {
                if (o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
                    o->oHealth--;
                    o->oSubAction = 1;
                    o->oTimer = 0;
                }
            } else {
                if (o->oTimer > 90) {
                    o->oAction = 2;
                    o->oPosY += 200.0f;
                    o->oInteractType = INTERACT_DAMAGE;
                }
                if (o->oHealth == 0) {
                    o->oAction = 5;
                }
            }
            break;
        case 5:
            o->activeFlags = 0;
            o->oObjF4->activeFlags = 0;
            break;
        case 6:
            cur_obj_move_standard(-78);
            cur_obj_update_floor_and_walls();
            o->oForwardVel = approach_f32(o->oForwardVel, 8.0f, 0.5f, 0.5f);
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x20);
            if (o->oMoveFlags & OBJ_MOVE_ON_GROUND) {
                o->oAction = 2;
                o->os16F8++;
                o->os16FA = 1;
                if (absi(o->oAngleToMario - o->oMoveAngleYaw) < 0x3000)
                    o->oMoveAngleYaw = o->oAngleToMario;
                else
                    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x3000);
            }

            if (dist_between_objects(o, gMarioObject) < 400.0f) {
                CL_get_hit(gMarioState, o, 2);
                o->oAction = 2;
                o->os16F8 = 0;
            }
            //o->oInteractType = INTERACT_BOUNCE_TOP;
            break;
    }
    o->oInteractStatus = 0;
}


void bhv_bounce_box_loop(void) {
    struct MarioState *m = gMarioState;
    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o)
                o->oAction = 1;
            break;
        case 1:
            if (approach_f32_ptr(&o->header.gfx.scale[1], 0.5f, 0.25f)) {
                set_mario_action(m, ACT_CUTSCENE_JUMP, 1);
                m->vel[1] = 200.0f;
                m->faceAngle[1] = (m->angleVel[1] = o->oFaceAngleYaw + 0xC000);
                mario_set_forward_vel(m, 15.0f);
                o->oAction = 2;
            }
            break;
        case 2:
            if (approach_f32_ptr(&o->header.gfx.scale[1], 1.25f, 0.2f)) {
                o->oAction = 3;
            }

            if (gMarioObject->platform == o) {
                o->header.gfx.scale[1] = 1.0f;
                o->oAction = 1;
            }
            break;
        case 3:
            if (approach_f32_ptr(&o->header.gfx.scale[1], 1.0f, 0.2f)) {
                o->header.gfx.scale[1] = 1.0f;
                o->oAction = 0;
            }

            if (gMarioObject->platform == o) {
                o->header.gfx.scale[1] = 1.0f;
                o->oAction = 1;
            }
            break;
    }
}




void bhv_dirt_mound_init(void) {
    o->oRoom = 1;
}

void bhv_dirt_mound_loop(void) {
    switch (o->oAction) {
        case 0:
            if (cur_obj_is_mario_ground_pounding_platform())
                o->oAction = 1;
            break;
        case 1:
            o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 0, 0.2f);
            if (o->header.gfx.scale[1] == 0) {
                o->activeFlags = 0;
                spawn_mist_particles();
            }
            break;
    }
}



void bhv_sunflower_init(void) {
    sSunflowers = 0;
    o->oOpacity = 80;
    //o->oFloatF4 = 0.6f;
    o->header.gfx.scale[1] = 0.6f;
    //cur_obj_scale(o->oFloatF4);
    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_FLOWER_DOOR) {
        o->oAction = 1;
    }
}

void bhv_sunflower_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            o->header.gfx.animInfo.animFrame = 0;
            if (o->oDistanceToMario < 100.0f) {
                o->oAction = 1;
                play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gGlobalSoundSource);
                sSunflowers++;
            }
            break;
        case 1:
            obj = spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
            obj->oPosY += 200.0f;
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 12);
            o->header.gfx.scale[1] = approach_f32(o->header.gfx.scale[1], 0.9f, 0.02f, 0.02f);
            //cur_obj_scale(o->oFloatF4);
            if (o->header.gfx.scale[1] == 0.9f && o->oOpacity == 255) {
                o->oAction = 2;
            }
            break;
        case 2:
            break;
    }
}