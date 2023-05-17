static void const *sMemForeroomCollision[] = {
    mem_chair_collision,
    mem_books_collision,
    NULL,
    mem_table_collision,
    mem_vase_collision,
};


f32 sMemPlateZPos[2] = {-28510.0f, -28910.0f};

void bhv_frozen_star_piece_init(void) {
    o->oFaceAngleYaw = random_u16();
    o->oFaceAnglePitch = random_u16();
    o->oFaceAngleRoll = random_u16();
    o->parentObj->oObj100 = o;
}

void bhv_frozen_star_piece_loop(void) {
    vec3f_copy(&o->oPosX, &o->parentObj->oPosX);
    o->header.gfx.animInfo.animFrame = 0;
}


void bhv_mem_ice_cube_child_loop(void) {
    vec3f_copy(&o->oPosX, &o->parentObj->oPosX);
    if (o->parentObj->oAction == 0) {
        load_object_collision_model();
    }
}


void bhv_mem_ice_cube_init(void) {
    struct Object *obj;
    if (o->oBehParams2ndByte == 0) {
        obj = spawn_object_at_origin(o, 0, MODEL_STAR_PIECE, bhvFrozenStarPiece);
        obj->oBehParams = 0x17 << 24;
    }
    obj_copy_pos_and_angle(obj, o);
    obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
    o->prevObj = obj;
}


void bhv_mem_ice_cube_loop(void) {
    struct Object *obj;
    s16 x, z;
    // if (sCubesMelt == 0xF) {
    //     o->oAction = 2;
    // } else {
        obj = cur_obj_nearest_object_with_behavior(bhvRedButton);
        if (obj != NULL && obj->oAction == 2) {
            o->oAction = 0;
            o->oForwardVel = 0;
            o->oFloatF8 = 0;
            o->oFloatF4 = 0;
            vec3f_copy(&o->oPosX, &o->oHomeX);
        }
    // }
    switch (o->oAction) {
        case 0:
            if (o->prevObj->oFlags & OBJ_FLAG_KICKED_OR_PUNCHED) {
                o->oAction = 1;

                if (absi((u16)(gMarioState->faceAngle[1]) - (u16)(gMarioState->faceAngle[1] & 0xC000)) < 0x2000) {
                    o->oMoveAngleYaw = gMarioState->faceAngle[1] & 0xC000;
                } else {
                    o->oMoveAngleYaw = (gMarioState->faceAngle[1] & 0xC000) + 0x4000;
                }

            }
            break;
        case 1:
            o->oFloatF4 = approach_f32_symmetric(o->oFloatF4, 4.0f, 0.5f);
            o->oFloatF8 = approach_f32_symmetric(o->oFloatF8, 40.0f, o->oFloatF4);
            o->oForwardVel = o->oFloatF8 / 4;
            if (ice_cube_detect_wall()) {
                o->oAction = 0;
                o->oForwardVel = 0;
                o->oFloatF8 = 0;
                o->oFloatF4 = 0;
                break;
            }

            cur_obj_update_floor();
            if (o->oFloorType == SURFACE_CUBE_MELT && o->oBehParams2ndByte == 0) {
                // if (!(sCubesMelt & k)) {
                //     play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gGlobalSoundSource);
                // }
                o->oAction = 2;
            }
            spawn_mist_particles_variable(2, -40, 6.0f);
            break;
        case 2:
            o->oFloatFC = approach_f32_symmetric(o->oFloatFC, 0.0f, 0.013f);
            cur_obj_scale(o->oFloatFC);
            cur_obj_play_sound_1(SOUND_AIR_BOBOMB_LIT_FUSE);
            if (o->oFloatFC <= 0.02f) {
                o->activeFlags = 0;
                o->prevObj->activeFlags = 0;
                o->oObj100->activeFlags = 0;
                obj = spawn_object(o, MODEL_STAR_PIECE, bhvStarPiece);
                obj->oBehParams = 0x17 << 24;
            }
            break;
    }
}


void bhv_mem_foreroom_object_init(void) {
    o->collisionData = segmented_to_virtual(sMemForeroomCollision[o->oBehParams2ndByte]);
    // o->oOpacity = 255;
    if (gIsConsole) {
        o->os16F4 = 200;
    } else {
        o->os16F4 = 225;
    }

    if (o->oBehParams2ndByte) {
        o->os16F4 -= 35;
    }
    if (o->oBehParams2ndByte == 4) {
        o->os16F4 -= 50;
    }

    o->os16F6 = 255 - o->os16F4;

    if (o->oBehParams2ndByte == 5) {
        o->oFlags &= ~(OBJ_FLAG_DISABLE_TO_ROOM_CLEAR | OBJ_FLAG_DISABLE_ON_ROOM_CLEAR);
    }
}


void bhv_mem_foreroom_object_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            if (o->oFlags & OBJ_FLAG_KICKED_OR_PUNCHED || cur_obj_is_mario_ground_pounding_platform()) {
                o->oAction = 1;
                cur_obj_play_sound_1(SOUND_GENERAL_VANISH_SFX);
            }
            if (o->oDistanceToMario < 800.0f) {
                if (gIsConsole) {
                    o->oOpacity = o->os16F4 + (o->oDistanceToMario / 800) * o->os16F6;
                } else {
                    o->oOpacity = o->os16F4 + (o->oDistanceToMario / 800) * o->os16F6;
                }
            } else {
                o->oOpacity = 255;
            }
            break;
        case 1:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 0x10);
            if (o->oOpacity < 0x11) {
                obj = spawn_object(o, MODEL_BG_GOOMBA, bhvGoomba);
                obj->parentObj = obj;
                spawn_mist_particles();
                o->activeFlags = 0;
                if (gMarioObject->platform == o) {
                    set_mario_action(gMarioState, ACT_FREEFALL, 0);
                }
            }
            break;
    }
}




void bhv_mem_bath_floor_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioState->pos[1] < 3200.0f && gMarioState->pos[1] > -2000.0f) {
                if (o->oTimer > 60) {
                    if (o->oTimer & 1) {
                        o->oPosY -= 2.0f;
                    } else {
                        o->oPosY += 2.0f;
                    }
                }
                if (o->oTimer > 100) {
                    o->oAction = 1;
                }
            } else {
                o->oTimer = 0;
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
