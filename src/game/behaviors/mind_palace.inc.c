static struct Object *sMIPSObjs[4][4] = {NULL};



void bhv_mind_gate_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioCurrentRoom == o->oRoom) {
                o->oAction = 1;
                if (save_file_get_newflags(1) & SAVE_TOAD_FLAG_MIND_LEVER) {
                    o->activeFlags = 0;
                }
            }
            break;
        case 1:
            o->oPosY = approach_f32(o->oPosY, o->oHomeY - 300.0f, 20.0f, 20.0f);
            if (save_file_get_newflags(1) & SAVE_TOAD_FLAG_MIND_LEVER) {
                o->oAction = 2;
            }
            break;
        case 2:
            o->oPosY = approach_f32(o->oPosY, o->oHomeY, 10.0f, 10.0f);
            if (o->oPosY == o->oHomeY)
                o->activeFlags = 0;
            break;
    }
}




void bhv_mind_lever_loop(void) {
    if (o->oF4 == 0) {
        o->header.gfx.animInfo.animFrame = 0;
        if (save_file_get_newflags(1) & SAVE_TOAD_FLAG_MIND_LEVER) {
            o->oF4 = 1;
        }
        if (cur_obj_was_attacked_or_ground_pounded() != 0) {
            play_puzzle_jingle();
            save_file_set_newflags(SAVE_TOAD_FLAG_MIND_LEVER, 1);
            o->oF4 = 1;
        }
    }
}


void bhv_mind_mips_init(void) {
    struct Object *obj;
    u8 starFlags = 0;//save_file_get_currency_flags() & (1 << 1);
    if (!starFlags) {
        o->oBehParams2ndByte = 0;
        o->oMipsForwardVelocity = 50.0f;
    } else {
        o->activeFlags = 0;
    }

    o->oInteractionSubtype = INT_SUBTYPE_HOLDABLE_NPC;
    o->oGravity = -9.0f;
    //o->oFriction = 10.0f;
    //o->oBuoyancy = 1.2f;

    cur_obj_disable();

    cur_obj_init_animation(0);
    // COMIT_OBJECT(MODEL_POUND_LEGO, 10399, -161, 2839, 0, 0, 0, bhvPoundLego)
    // o->oObjF4 = obj;
    // o->oObjF4->oBehParams = 0x01000000;
    o->oObjF4 = CL_nearest_object_with_behavior_and_field(bhvMindMound, 0x14C, 0);
    // o->oObjF4 = cur_obj_nearest_object_with_behavior(bhvPoundLego);
    // if (o->oObjF4 == NULL) {
    //     o->activeFlags = 0;
    //     return;
    // }
    // vec3f_copy(&o->oObjF4->oHomeX, &o->oObjF4->oPosX);
    vec3f_copy(&o->oPosX, &o->oObjF4->oPosX);
}

void bhv_mind_mips_run_loop(void) {
    Vec3f pos;
    switch (o->oHeldState) {
        case HELD_FREE:
            if (o->oDistanceToMario > 2000.0f)
                o->oForwardVel = 0;
            else
                o->oForwardVel = 35.0f;
            
            if (o->oTimer > o->os1610A) {
                o->os1610C = CL_RandomMinMaxU16(1, 20);
                o->os1610A = CL_RandomMinMaxU16(30, 120);
            }
            o->os1610E += (0x20 * o->os1610C);
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->os1610E - o->oAngleToMario, 0x800);
            cur_obj_update_floor_and_walls();
            pos[1] = o->oPosY;
            pos[0] = o->oPosX + (sins(o->oMoveAngleYaw) * 100.0f);
            pos[2] = o->oPosZ + (coss(o->oMoveAngleYaw) * 100.0f);
            if (f32_find_wall_collision(&pos[0], &pos[1], &pos[2], 10.0f, 50.f)) {
                o->oPosY += 50.0f;
                cur_obj_reflect_move_angle_off_wall();
            }
            cur_obj_move_standard(0);

            if (o->oPosX < -16600.0f) {
                o->oPosX = -16600.0f;
            } else if (o->oPosX > -14100.0f) {
                o->oPosX = -14100.0f;
            }
            if (o->oPosZ < -4400.0f) {
                o->oPosZ = -4400.0f;
            } else if (o->oPosZ > -1900.0f) {
                o->oPosZ = -1900.0f;
            }

            if (cur_obj_check_if_near_animation_end() == TRUE) {
                cur_obj_play_sound_2(SOUND_OBJ_MIPS_RABBIT);
            }
            break;
        case HELD_HELD:
            bhv_mips_held();
            break;
        case HELD_THROWN:
            bhv_mips_thrown();
            o->os16FA = 0;
            break;
        case HELD_DROPPED:
            bhv_mips_dropped();
            o->os16FA = 0;
            break;
    }
}


void bhv_mind_mips_loop(void) {
    struct Object *obj;
    Vec3f pos;
    struct Surface *floor;
    if (o->os16FA) {
        bhv_mind_mips_run_loop();
        //bhv_mips_act_idle();
        return;
    }
    switch (o->oAction) {
        case 0:
            if (o->oObjF4->oAction != 0) {
                // if (o->os16110 >= 3) {
                //     o->os16FA = 1;
                //     o->oAction = 0;
                //     o->oForwardVel = 35.0f;
                //     o->oInteractType = INTERACT_GRABBABLE;
                //     cur_obj_enable();
                //     break;
                // }
                o->oAction = 1;
                cur_obj_enable();
                cur_obj_init_animation(1);
                o->oForwardVel = 25.0f;
                o->oObjF4 = CL_nearest_object_with_behavior_and_field(bhvMindMound, 0x14C, 0);
                if (o->oObjF4 != NULL) {
                    o->oMoveAngleYaw = obj_angle_to_object(o, o->oObjF4);
                } else {
                    while ((o->oObjF4 = CL_nearest_object_with_behavior_and_field(bhvMindMound, 0x14C, 2)) != NULL) {
                        o->oObjF4->activeFlags = 0;
                    }
                    while ((o->oObjF4 = CL_nearest_object_with_behavior_and_field(bhvMindMound, 0x14C, 3)) != NULL) {
                        o->oObjF4->activeFlags = 0;
                    }
                    o->oObjF4 = cur_obj_nearest_object_with_behavior(bhvMindMoundBlock);
                    if (o->oObjF4 != NULL) {
                        o->oObjF4->oAction = 2;
                    }
                    o->os16FA = 1;
                    o->oAction = 0;
                    o->oForwardVel = 35.0f;
                    o->oInteractType = INTERACT_GRABBABLE;
                    cur_obj_enable();
                }
                break;
            }
            o->os16F8 += 0x400;
            o->oObjF4->oPosX = o->oObjF4->oHomeX + (sins(o->os16F8) * 3.0f);
            o->oObjF4->oPosZ = o->oObjF4->oHomeZ + (coss(o->os16F8 * 4) * 2.0f);
            if ((o->oTimer & 7) == 0)
                spawn_mist_particles_variable(1, -60, 4.0f);
            break;
        case 1:
            cur_obj_update_floor_and_walls();
            pos[1] = o->oPosY;
            pos[0] = o->oPosX + (sins(o->oMoveAngleYaw) * 100.0f);
            pos[2] = o->oPosZ + (coss(o->oMoveAngleYaw) * 100.0f);
            if (f32_find_wall_collision(&pos[0], &pos[1], &pos[2], 10.0f, 50.f)) {
                o->oPosY += 50.0f;
            }
            cur_obj_move_standard(0);
            if ((o->oTimer & 7) == 0) {
                cur_obj_play_sound_2(SOUND_OBJ_MIPS_RABBIT);
            }
            if (o->oTimer > 15) {
                o->oAction = 2;
                o->oForwardVel = 0;
                o->oVelY = 40.0f;
                o->oGravity = -5.0f;
            }
            break;
        case 2:
            CL_Move();
            if (o->oTimer > 10) {
                o->oAction = 0;
                // o->os16110++;
                o->oVelY = 0;
                o->oGravity = -9.0f;

                spawn_mist_particles();
                // o->oObjF4 = spawn_object(o, MODEL_POUND_LEGO, bhvPoundLego);
                // o->oObjF4->oFaceAngleYaw = 0;
                // do {
                //     o->oObjF4->oPosX = 9200.0f + (8200.0f * random_float());
                //     o->oObjF4->oPosZ = -2000.0f + (5200.0f * random_float());
                //     o->oObjF4->oPosY = find_floor(o->oObjF4->oPosX, o->oObjF4->oPosY + 5000.0f, o->oObjF4->oPosZ, &floor);
                //     vec3f_copy(&o->oObjF4->oHomeX, &o->oObjF4->oPosX);
                //     vec3f_copy(&o->oPosX, &o->oObjF4->oHomeX);
                // } while (floor->type == SURFACE_GENERAL_USE || 
                //         CL_objptr_dist_to_nearest_object_with_behavior(o->oObjF4, bhvPoundLego) < 500.0f);
                vec3f_copy(&o->oPosX, &o->oObjF4->oPosX);
                cur_obj_disable();
            }
            break;
        case 4:
            cur_obj_init_animation(0);
            // spawn_default_star(10668.0f, 379.0f, 729.0f);
            obj = spawn_object(o, MODEL_SMALL_KEY, bhvSmallKey);
            obj->oBehParams2ndByte = 11;
            obj->oBehParams = 11 << 16;
            obj->oFaceAngleRoll = 0xF000;
            obj->oFaceAngleYaw = 0;
            obj->oPosX = o->oHomeX;
            obj->oPosZ = o->oHomeZ;
            obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
            o->oAction = 5;
            o->os16FA = 0;
            o->oInteractType = INTERACT_IGLOO_BARRIER;
            break;
    }
}



void bhv_mind_mound_block_init(void) {
    o->os16F4 = o->oBehParams2ndByte % 4;
    o->os16F6 = o->oBehParams2ndByte / 4;
    if (sMIPSObjs[o->os16F4][o->os16F6] == NULL) {
        // if ((o->oBehParams >> 24) == 1 && !(save_file_get_currency_flags() & (1 << 8))) {
        //     o->oBehParams = 8 << 24;
        //     spawn_default_star(o->oPosX - 879.0f, o->oPosY + 450.0f, o->oPosZ + 662.0f);
        // }
    } else {
        o->oPosX = sMIPSObjs[o->os16F4][o->os16F6]->oPosX;
        o->oPosZ = sMIPSObjs[o->os16F4][o->os16F6]->oPosZ;
    }


}

void bhv_mind_mound_block_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oMoveAngleYaw = 0x8000;
            if (gMarioState->wall != NULL && gMarioState->wall->object == o && gMarioState->flags & MARIO_UNKNOWN_31
                && gMarioState->wall->force == 1) {
                o->oForwardVel = 10.0f;
                CL_Move();
                gMarioState->pos[0] += o->oVelX;
                gMarioState->pos[2] += o->oVelZ;
                // if (o->oPosY - find_floor_height(o->oPosX, o->oPosY, o->oPosZ) > 100.0f) {
                //     o->oAction = 3;
                // }
                if (absf(o->oPosZ - o->oHomeZ) > 574.0f) {
                    o->oAction = 3;
                }
            }
            break;
        case 1:
            mind_mound_block_act_1();
            break;
        case 2:
            break;
        case 3:
            o->oFloat110 = approach_f32_symmetric(o->oFloat110, 70.0f, 3.0f);
            o->oPosY = approach_f32_symmetric(o->oPosY, 5637.0f, o->oFloat110);
            if (o->oPosY == 5637.0f) {
                o->oAction = 1;
                if (sMIPSObjs[3][0] != NULL) {
                    sMIPSObjs[3][0]->os16FA = 1;
                    sMIPSObjs[3][0]->oAction = 1;
                }
                bhv_mind_mound_block_init();
                play_puzzle_jingle();
            }
            break;
    }
}

void mind_mound_block_act_1(void) {
    struct Object *obj;
    if (sMIPSObjs[0][0] == NULL) {
        return;
    }

    o->os16F4 = o->oBehParams2ndByte % 4;
    o->os16F6 = o->oBehParams2ndByte / 4;
    if (sMIPSObjs[o->os16F4][o->os16F6] == NULL) {
        return;
    }
    sMIPSObjs[o->os16F4][o->os16F6]->os16FA = 0;

    if (gMarioState->wall != NULL && gMarioState->wall->object == o && gMarioState->flags & MARIO_UNKNOWN_31) {
        switch (gMarioState->wall->force) {
            case 0:
                if (o->oBehParams2ndByte <= 3) {
                    play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                    break;
                }
                o->oBehParams2ndByte -= 4;
                obj = sMIPSObjs[o->oBehParams2ndByte % 4][o->oBehParams2ndByte / 4];
                if (obj == NULL || obj->os16F8 == 0) {
                    o->oBehParams2ndByte += 4;
                    play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                    break;
                }

                // if ((struct Object *)cur_obj_nearest_object_with_behavior(bhvSandCrab)->oBehParams2ndByte == o->oBehParams2ndByte) {
                //     o->oBehParams2ndByte += 4;
                //     play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                //     break;
                // }
                break;
            case 1:
                if (o->oBehParams2ndByte % 4 == 0) {
                    play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                    break;
                }
                o->oBehParams2ndByte -= 1;
                obj = sMIPSObjs[o->oBehParams2ndByte % 4][o->oBehParams2ndByte / 4];
                if (obj == NULL || obj->os16F8 == 0) {
                    o->oBehParams2ndByte += 1;
                    play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                    break;
                }

                // if ((struct Object *)cur_obj_nearest_object_with_behavior(bhvSandCrab)->oBehParams2ndByte == o->oBehParams2ndByte) {
                //     o->oBehParams2ndByte += 1;
                //     play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                //     break;
                // }
                break;
            case 2:
                if (o->oBehParams2ndByte >= 12) {
                    play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                    break;
                }
                o->oBehParams2ndByte += 4;
                obj = sMIPSObjs[o->oBehParams2ndByte % 4][o->oBehParams2ndByte / 4];
                if (obj == NULL || obj->os16F8 == 0) {
                    o->oBehParams2ndByte -= 4;
                    play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                    break;
                }

                // if ((struct Object *)cur_obj_nearest_object_with_behavior(bhvSandCrab)->oBehParams2ndByte == o->oBehParams2ndByte) {
                //     o->oBehParams2ndByte -= 4;
                //     play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                //     break;
                // }
                break;
            case 3:
                if (o->oBehParams2ndByte % 4 == 3) {
                    play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                    break;
                }
                o->oBehParams2ndByte += 1;
                obj = sMIPSObjs[o->oBehParams2ndByte % 4][o->oBehParams2ndByte / 4];
                if (obj == NULL || obj->os16F8 == 0) {
                    o->oBehParams2ndByte -= 1;
                    play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                    break;
                }

                // if ((struct Object *)cur_obj_nearest_object_with_behavior(bhvSandCrab)->oBehParams2ndByte == o->oBehParams2ndByte) {
                //     o->oBehParams2ndByte -= 1;
                //     play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                //     break;
                // }
                break;
        }
        obj = sMIPSObjs[o->oBehParams2ndByte % 4][o->oBehParams2ndByte / 4];
        if (obj != NULL) {
            o->oMoveAngleYaw = obj_angle_to_object(o, obj);
        }
    }

    o->os16F4 = o->oBehParams2ndByte % 4;
    o->os16F6 = o->oBehParams2ndByte / 4;
    if (sMIPSObjs[o->os16F4][o->os16F6] == NULL) {
        return;
    }
    sMIPSObjs[o->os16F4][o->os16F6]->os16FA = 1;
    o->oPosX = approach_f32_symmetric(o->oPosX, sMIPSObjs[o->os16F4][o->os16F6]->oPosX, absf(20.0f * sins(o->oMoveAngleYaw)));
    o->oPosZ = approach_f32_symmetric(o->oPosZ, sMIPSObjs[o->os16F4][o->os16F6]->oPosZ, absf(20.0f * coss(o->oMoveAngleYaw)));
}




void mind_mounds_check_adjacent(void) {
    struct Object *obj;
    if (o->os16F4 > 0) {
        obj = sMIPSObjs[o->os16F4 - 1][o->os16F6];
        if (obj != NULL && obj->os16F8 == 1 && obj->os16FA == 0) {
            obj->oAction = 3;
        }
    }
    if (o->os16F4 < 3) {
        obj = sMIPSObjs[o->os16F4 + 1][o->os16F6];
        if (obj != NULL && obj->os16F8 == 1 && obj->os16FA == 0) {
            obj->oAction = 3;
        }
    }

    if (o->os16F6 > 0) {
        obj = sMIPSObjs[o->os16F4][o->os16F6 - 1];
        if (obj != NULL && obj->os16F8 == 1 && obj->os16FA == 0) {
            obj->oAction = 3;
        }
    }
    if (o->os16F6 < 3) {
        obj = sMIPSObjs[o->os16F4][o->os16F6 + 1];
        if (obj != NULL && obj->os16F8 == 1 && obj->os16FA == 0) {
            obj->oAction = 3;
        }
    }

}


s32 check_mind_mound_key(void) {
    struct Object *obj;
    s32 i;
    for (i = 0; i < 16; i++) {
        obj = sMIPSObjs[i % 4][i / 4];
        if (obj == NULL || obj->os16F8 == 0) {
            return FALSE;
        }
    }
    return TRUE;
}


void despawn_all_mind_mounds(void) {
    struct Object *obj;
    s32 i;
    for (i = 0; i < 16; i++) {
        obj = sMIPSObjs[i % 4][i / 4];
        if (obj != NULL) {
            obj->activeFlags = 0;
            obj = NULL;
        }
    }
}


//F4 = column/horizontal
//F6 = row/vertical
void bhv_mind_mound_init(void) {
    o->os16F4 = o->oBehParams2ndByte % 4;
    o->os16F6 = o->oBehParams2ndByte / 4;
    sMIPSObjs[o->os16F4][o->os16F6] = o;

    o->os16F8 = o->oBehParams >> 24;
    if (o->os16F8) {
        o->oAction = 2;
        o->oPosY -= 150.0f;
    }

    // if (save_file_get_currency_flags() & (1 << 8)) {
    //     o->activeFlags = 0;
    //     sMIPSObjs[o->os16F4][o->os16F6] = NULL;
    // }
}


void bhv_mind_mound_loop(void) {
    switch (o->oAction) {
        case 0:
            if (cur_obj_is_mario_ground_pounding_platform()) {
                o->oAction = 1;
                mind_mounds_check_adjacent();
            }
            break;
        case 1:
            o->header.gfx.scale[1] = approach_f32_asymptotic(o->header.gfx.scale[1], 0.0f, 0.2f);
            if (o->header.gfx.scale[1] < 0.1f) {
                o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 0.0f, 0.1f);
                o->header.gfx.scale[2] = o->header.gfx.scale[0];
                if (o->header.gfx.scale[0] < 0.1f) {
                    o->oAction = 2;
                    o->header.gfx.scale[0] = o->header.gfx.scale[1] = o->header.gfx.scale[2] = 1.0f;
                    o->oPosY -= 150.0f;
                    o->os16F8 = 1;

                    if (check_mind_mound_key()) {
                        o->oBehParams = 8 << 24;
                        spawn_default_star(o->oPosX, o->oPosY + 450.0f, o->oPosZ);
                        despawn_all_mind_mounds();
                    }
                }
            }
            break;
        case 2:
            cur_obj_hide();
            break;
        case 3:
            cur_obj_unhide();
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 20.0f);
            if (o->oPosY == o->oHomeY) {
                o->oAction = 0;
                o->os16F8 = 0;
            }
            break;
    }
}
