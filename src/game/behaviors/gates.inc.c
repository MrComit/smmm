extern s8 sLevelRoomOffsets[];
struct ObjectHitbox sLeverHitbox = {
    /* interactType: */ INTERACT_BREAKABLE,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 1,
    /* numLootCoins: */ 0,
    /* radius: */ 90,
    /* height: */ 90,
    /* hurtboxRadius: */ 90,
    /* hurtboxHeight: */ 90,
};

struct ObjectHitbox sStrayBookHitbox = {
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

Vec3f sStealerPos[6] = {
{5336.97f, 0, 12903.7f},
{4810.03f, 0, 13092.4f},
{3782.88f, 0, 13290.5f},
{4061.87f, 0, 13840.4f},
{4622.21f, 0, 13695.4f},
{5276.90f, 0, 13639.6f},
};

Vec3f sStrayBookPos = {-10783.0f, 186.0f, 3062.0f};



void bhv_ice_ceiling_gate_loop(void) {
    o->oRoom = 7;
    if (o->oBehParams2ndByte) {
        if (gMarioState->pos[2] > -7500.0f || gMarioState->pos[2] < -13888.0f) {
            cur_obj_hide();
        } else {
            cur_obj_unhide();
        }
    }
    switch (o->oAction) {
        case 0:
            if (gMarioCurrentRoom == o->oRoom) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (save_file_get_rooms((o->oRoom  + sLevelRoomOffsets[gCurrCourseNum - 1]) / 32) & (1 << ((o->oRoom  + sLevelRoomOffsets[gCurrCourseNum - 1]) % 32))) {
                o->oAction = 2;
            }
            break;
        case 2:
            o->oPosZ = approach_f32(o->oPosZ, o->oHomeZ + 4000.0f, 100.0f, 100.0f);
            if (o->oPosZ == o->oHomeZ)
                o->activeFlags = 0;
            break;
    }
}



void bhv_l1_room_gate_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioCurrentRoom == o->oRoom) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oPosY = approach_f32(o->oPosY, o->oHomeY - 300.0f, 20.0f, 20.0f);
            if (save_file_get_rooms((o->oRoom  + sLevelRoomOffsets[gCurrCourseNum - 1]) / 32) & (1 << ((o->oRoom  + sLevelRoomOffsets[gCurrCourseNum - 1]) % 32))) {
                o->oAction = 2;
            }
            break;
        case 2:
            o->oPosY = approach_f32(o->oPosY, o->oHomeY, 20.0f, 20.0f);
            if (o->oPosY == o->oHomeY)
                o->activeFlags = 0;
            break;
    }
}


void bhv_lever_loop(void) {
    obj_set_hitbox(o, &sLeverHitbox);

    if (o->oF4 == 0) {
        if (save_file_get_newflags(0) & SAVE_NEW_FLAG_MUDROOM_GATE) {
            o->oF4 = 1;
            cur_obj_init_anim_and_check_if_end(1);
        }
        if (cur_obj_was_attacked_or_ground_pounded() != 0) {
            cur_obj_init_anim_and_check_if_end(1);
            play_puzzle_jingle();
            save_file_set_newflags(SAVE_NEW_FLAG_MUDROOM_GATE, 0);
            o->oF4 = 1;
        }
    }
}




void bhv_l1_gate_loop(void) {
    struct Object *obj;
    if (o->oBehParams2ndByte != 1) {
        o->oFlags &= ~(OBJ_FLAG_DISABLE_TO_ROOM_CLEAR | OBJ_FLAG_DISABLE_ON_ROOM_CLEAR);
    }
    switch (o->oAction) {
        case 0:
            switch (o->oBehParams2ndByte) {
                case 0:
                    obj = cur_obj_nearest_object_with_behavior(bhvLever);
                    if (obj == NULL || obj->oF4 == 1) {
                        o->oAction = 1;
                        break;
                    }
                    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_MUDROOM_GATE) {
                        o->activeFlags = 0;
                    }
                    break;
                case 1:
                    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_PARLOR_GATE) {
                        o->activeFlags = 0;
                        break;
                    }
                    if (cur_obj_nearest_object_with_behavior(bhvShyguyBookSteal) == NULL) {
                        o->oAction = 1;
                        save_file_set_newflags(SAVE_NEW_FLAG_PARLOR_GATE, 0);
                        play_puzzle_jingle();
                    }
                    break;
                case 2:
                    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_PRE_STUDY_GATE) {
                        o->activeFlags = 0;
                    }
                    break;
                case 3:
                    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_STUDY_GATE) {
                        o->activeFlags = 0;
                    }
                    if (o->oF4 > 3) {
                        o->oAction = 1;
                        save_file_set_newflags(SAVE_NEW_FLAG_STUDY_GATE, 0);
                        play_puzzle_jingle();
                    }
                    break;
                case 4:
                    o->collisionData = segmented_to_virtual(l1_gate_alt_collision);
                    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_LIBRARY_MAIN_GATE) {
                        o->activeFlags = 0;
                    }
                    if (cur_obj_nearest_object_with_behavior(bhvKoopaBoss) == NULL) {
                        o->oAction = 1;
                        save_file_set_newflags(SAVE_NEW_FLAG_LIBRARY_MAIN_GATE, 0);
                        play_puzzle_jingle();
                    }
                    break;
            }
            break;
        case 1:
            o->oPosY = approach_f32(o->oPosY, o->oHomeY + 300.0f, 10.0f, 10.0f);
            if (o->oPosY == o->oHomeY + 300.0f)
                o->activeFlags = 0;
            break;
    }
}




void bhv_l1_book_init(void) {
    struct Object *obj;
    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_PARLOR_GATE) {
        o->activeFlags = 0;
        return;
    }
    obj = spawn_object(o, MODEL_SHYGUY, bhvShyguyBookSteal);
    obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
    vec3f_copy(&obj->oPosX, sStealerPos[o->oBehParams >> 24]);
}


void bhv_l1_book_loop(void) {
    switch (o->oAction) {
        case 0:
            load_object_collision_model();
            break;
        case 1:
            break;
    }
}



void bhv_shyguy_book_steal_loop(void) {
    switch (o->oAction) {
        case 0:
            cur_obj_disable();
            if (save_file_get_boos() & 1) {
                o->oAction = 1;
                cur_obj_enable();
                o->parentObj->oFaceAngleRoll = 0x4000;
                o->parentObj->oAction = 1;
                obj_scale(o->parentObj, 0.7f);
                o->oForwardVel = 20.0f;
                o->oF8 = CL_RandomMinMaxU16(0x200, 0x800);
                o->oFC = CL_RandomMinMaxU16(20, 40);
            }
            break;
        case 1:
            o->parentObj->oPosX = o->oPosX - (50.0f * sins(o->oMoveAngleYaw - 0x6000));
            o->parentObj->oPosZ = o->oPosZ - (50.0f * coss(o->oMoveAngleYaw - 0x6000));
            o->parentObj->oPosY = o->oPosY + 140.0f;
            o->parentObj->oFaceAngleYaw = o->oMoveAngleYaw;

            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(-78);
            o->oMoveAngleYaw += o->oF8;
            if (o->oTimer > o->oFC) {
                o->oF8 = CL_RandomMinMaxU16(0x200, 0x800);
                o->oFC = CL_RandomMinMaxU16(20, 40);
                o->oTimer = 0;
            }
            if (o->oInteractStatus & INT_STATUS_INTERACTED && o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
                    spawn_mist_particles();
                    obj_spawn_loot_yellow_coins(o, o->oNumLootCoins, 20.0f);
                    o->activeFlags = 0;
                    o->parentObj->activeFlags = 0;
                    create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
            }
            o->oInteractStatus = 0;
            break;
    }
}


void bhv_book_thrower_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 1000.0f && absf(gMarioState->pos[0] - o->oPosX) < 200.0f && gMarioState->pos[1] < 550.0f) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (absf(gMarioState->pos[0] - o->oPosX) > 200.0f || gMarioState->pos[1] > 550.0f) {
                o->oAction = 0;
                break;
            }
            obj = spawn_object(o, MODEL_L1_BOOK, bhvStrayBook);
            obj->oPosY = gMarioState->pos[1] + 80.0f;
            obj->oBehParams2ndByte = CL_RandomMinMaxU16(0, 2);
            if (o->oBehParams2ndByte)
                obj->oF4 = 1;
            //obj->oPosX = gMarioState->pos[0];
            o->oAction = 2;
            break;
        case 2:
            break;
    }
}


void bhv_stray_book_init(void) {
    //s16 pitch, yaw;
    //f32 dist;
    //vec3f_get_dist_and_angle(&o->oPosX, gMarioState->pos, &dist, &pitch, &yaw);
    //o->oMoveAnglePitch = pitch;
    //o->oMoveAngleYaw = yaw;
    o->oForwardVel = 40.0f;
    obj_set_hitbox(o, &sStrayBookHitbox);

}

void bhv_stray_book_loop(void) {
    struct Object *obj;
    if (o->oF4) {
        spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
    }
    switch (o->oAction) {
        case 0:
            CL_Move();
            cur_obj_update_floor_and_walls();
            o->oFaceAngleYaw += 0xC00;
            o->oFaceAngleRoll += 0xC00;
            o->oFaceAnglePitch += 0xC00;
            if (o->oF4) {
                o->oForwardVel = 25.0f;
                if (o->oDistanceToMario < 120.0f && gMarioState->flags & (MARIO_PUNCHING | MARIO_KICKING)) {
                    o->oMoveAngleYaw = gMarioState->faceAngle[1];
                    o->oForwardVel = 52.0f;
                    o->oAction = 1;
                    break;
                }
            }
            if (o->oTimer > 30 || o->oMoveFlags & OBJ_MOVE_HIT_WALL || o->oInteractStatus & INT_STATUS_INTERACTED) {
                spawn_mist_particles_variable(0, 0, 25.0f);
                spawn_triangle_break_particles(6, 138, 1.0f, 4);
                create_sound_spawner(SOUND_GENERAL_HAUNTED_CHAIR_MOVE);
                o->activeFlags = 0;
                o->parentObj->oAction = 1;
            }
            break;
        case 1:
            CL_Move();
            cur_obj_update_floor_and_walls();
            o->oFaceAngleYaw += 0xC00;
            o->oFaceAngleRoll += 0xC00;
            o->oFaceAnglePitch += 0xC00;
            if (o->oTimer > 60) {
                spawn_mist_particles_variable(0, 0, 25.0f);
                spawn_triangle_break_particles(6, 138, 1.0f, 4);
                create_sound_spawner(SOUND_GENERAL_HAUNTED_CHAIR_MOVE);
                o->activeFlags = 0;
                o->parentObj->oAction = 1;
                break;
            }
            if (o->oMoveFlags & OBJ_MOVE_HIT_WALL && o->oPosZ > 2863.0f && o->oPosZ < 3313.0f) {
                create_sound_spawner(SOUND_GENERAL_HAUNTED_CHAIR_MOVE);
                o->oAction = 2;
                o->parentObj->activeFlags = 0;
                vec3f_copy(&o->oPosX, sStrayBookPos);
                o->header.gfx.scale[1] = 1.0f;
                o->oFaceAngleYaw = 0x4000;
                o->oFaceAngleRoll = 0;
                o->oFaceAnglePitch = 0;
                obj = CL_obj_nearest_object_behavior_params(bhvL1Gate, 0x00020000);
                if (obj != NULL) {
                    obj->oAction = 1;
                    save_file_set_newflags(SAVE_NEW_FLAG_PRE_STUDY_GATE, 0);
                    play_puzzle_jingle();
                }
            }
            break;
        case 2:
            break;
    }
}