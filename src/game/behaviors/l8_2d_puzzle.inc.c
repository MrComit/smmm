static struct Object *sOutsideObjs[4][4] = {NULL};

struct ObjectHitbox sMind2DGoombaHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 1,
    /* numLootCoins:      */ 1,
    /* radius:            */ 72,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 42,
    /* hurtboxHeight:     */ 40,
};


s8 sMoundToColor[16] = {
    0, 4, 1, -1,
    3, 2, 3, 2,
    4, 3, 2, 1,
    0, 1, 4, 0,
};



s8 s2DGateVals[5] = {
    0,
    0,
    0,
    0,
    0,
};


Vec3s s2DGateColors[5] = {
    {0xFF, 0x00, 0x00}, // RED
    {0x00, 0xFF, 0x00}, // GREEN
    {0x00, 0x90, 0xFF}, // BLUE
    {0xFF, 0xFF, 0x00}, // YELLOW
    {0xFF, 0x00, 0xE0}, // PINK
};

#define COMIT_OBJECT(a, b, c, d, e, f, g, h) \
    obj = spawn_object_abs_with_rot(o, 0, a, h, b, c, d, DEGREES(e), DEGREES(f), DEGREES(g)); \
    obj->oRoom = o->oRoom; \
    obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;


void bhv_maze_gate_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioCurrentRoom == o->oRoom) {
                o->oAction = 1;
                if (save_file_get_newflags(1) & SAVE_TOAD_FLAG_MIND_MAZE) {
                    o->activeFlags = 0;
                }
            }
            break;
        case 1:
            o->oPosY = approach_f32(o->oPosY, o->oHomeY - 300.0f, 20.0f, 20.0f);
            if (save_file_get_newflags(1) & SAVE_TOAD_FLAG_MIND_MAZE) {
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



void bhv_maze_wins_loop(void) {
    struct Object *obj;
    if (o->oObjF4 == NULL || o->oObjF4->os1610A != o->oBehParams2ndByte) {
        if (o->oBehParams2ndByte < 2) {
            obj = spawn_object(o, MODEL_MAZE_WINS, bhvMazeWins);
            obj->oObjF4 = o->oObjF4;
            obj->oBehParams2ndByte = o->oBehParams2ndByte + 1;
        } else {
            if (o->oObjF4 != NULL) {
                o->oObjF4->oAction = 4;
            }
            gComitCutsceneTimer = 30;
        }
        o->activeFlags = 0;
    }
}


void bhv_mind_button_init(void) {
    struct Object *obj;
    if (save_file_get_newflags(1) & SAVE_TOAD_FLAG_MIND_MAZE) {
        o->oAction = 7;
        return;
    }
    obj = spawn_object(o, MODEL_MAZE_WINS, bhvMazeWins);
    obj->oObjF4 = o;
    obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
}


s32 check_maze_invalid(void) {
    s32 i;
    for (i = 0; i < 5; i++) {
        if (s2DGateVals[i] == 1 || s2DGateVals[i] == 2) {
            return TRUE;
        }
    }
    return FALSE;
}


void bhv_mind_button_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            if (save_file_get_newflags(1) & SAVE_TOAD_FLAG_MIND_MAZE) {
                o->oAction = 7;
                return;
            }
            if (gMarioObject->platform == o) {
                // if (check_maze_invalid()) {
                //     o->oAction = 5;
                // } else {
                    o->oAction = 1;
                    o->oFloatF4 = gMarioState->pos[0];
                    o->oFloatF8 = gMarioState->pos[2];
                // }
            }
            break;
        case 1:
            gMarioState->pos[0] = o->oFloatF4;
            gMarioState->pos[2] = o->oFloatF8;
            o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 0.3f, 0.08f);
            if (o->header.gfx.scale[1] == 0.3f) {
                o->oAction = 2;
                if (o->oBehParams2ndByte == 0) {
                    COMIT_OBJECT(MODEL_MIND_2D_GOOMBA, -8493, 9752, 8733, 0, -90, 0, bhvMind2DGoomba); // 1
                } else if (o->oBehParams2ndByte == 1) {
                    COMIT_OBJECT(MODEL_MIND_2D_GOOMBA, -12743, 9752, 5883, 0, 0, 0, bhvMind2DGoomba); // 2
                } else {
                    COMIT_OBJECT(MODEL_MIND_2D_GOOMBA, -9943, 9752, 11383, 0, -180, 0, bhvMind2DGoomba); // 3
                }
                obj->oObj104 = o;
                gComitCutsceneObject = obj;
                o->oBehParams2ndByte++;
                gCamera->comitCutscene = 20;
                set_mario_npc_dialog(1);
            }
            break;
        case 2:
            gMarioState->pos[0] = o->oFloatF4;
            gMarioState->pos[2] = o->oFloatF8;
            gCamera->comitCutscene = 20;
            set_mario_npc_dialog(1);
            break;
        case 3:
            set_mario_npc_dialog(0);
            gMarioState->pos[0] -= 500.0f;
            o->header.gfx.scale[1] = 1.0f;
            o->oBehParams2ndByte = 0;
            o->oAction = 0;
            if (o->os16108 >= 3) {
                o->os16108 = 0;
                o->os1610A++;
            }
            break;
        case 4:
            if (o->oTimer > 30) {
                gCamera->comitCutscene = 0xFF;
                gComitCutsceneTimer = 45;
                obj = cur_obj_nearest_object_with_behavior(bhvMazeGate);
                if (obj != NULL) {
                    vec3f_set(gComitCutscenePosVec, obj->oHomeX, obj->oHomeY + 200.0f, obj->oHomeZ + 1500.0f);
                    vec3f_copy(gComitCutsceneFocVec, &obj->oHomeX);
                } else {
                    o->oAction = 5;
                }
            } else if (o->oTimer == 30) {
                save_file_set_newflags(SAVE_TOAD_FLAG_MIND_MAZE, 1);
                play_puzzle_jingle();
            } else {

            }
            break;
        case 5:
            o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 0.3f, 0.08f);
            if (o->header.gfx.scale[1] == 0.3f) {
                if (CL_NPC_Dialog(DIALOG_072)) {
                    o->oAction = 6;
                }
            }
            break;
        case 6:
            if (gMarioObject->platform != o) {
                o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 1.0f, 0.1f);
                if (o->header.gfx.scale[1] == 1.0f) {
                    o->oAction = 0;
                }
            }
            break;
    }
}






void bhv_mind_2d_gate_init(void) {
    o->os16F4 = s2DGateColors[o->oBehParams2ndByte][0];
    o->os16F6 = s2DGateColors[o->oBehParams2ndByte][1];
    o->os16F8 = s2DGateColors[o->oBehParams2ndByte][2];

    o->oFloatFC = 1.0f;
}


void bhv_mind_2d_gate_loop(void) {
    o->os16FA = s2DGateVals[o->oBehParams2ndByte];
    if (o->os16FA == 0) {
        o->header.gfx.scale[1] = 0.0f;
        cur_obj_hide();
    } else {
        cur_obj_unhide();
        o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 0.01f + (0.33f * o->os16FA), 0.05f);
        load_object_collision_model();
    }
    // o->header.gfx.scale[1] = 1.0f;
}



void bhv_mind_2d_goomba_init(void) {
    obj_set_hitbox(o, &sMind2DGoombaHitbox);
    o->oMoveAngleYaw = o->oFaceAngleYaw + 0x4000;
}


void bhv_mind_2d_goomba_loop(void) {
    cur_obj_update_floor_and_walls();
    cur_obj_move_standard(0);


    if (o->oMoveFlags & OBJ_MOVE_HIT_WALL /*|| cur_obj_dist_to_nearest_object_with_behavior(bhvMind2DGate) < 150.0f*/) {
        o->oMoveAngleYaw += 0x8000;
        cur_obj_move_standard(0);
    }

    if (o->oMoveFlags & OBJ_MOVE_IN_AIR) {
        o->oForwardVel = 0.0f;
    } else {
        o->oForwardVel = 40.0f;
    }

    if (o->oAction == 0) {
        if (o->oFloor != NULL && o->oFloorType == SURFACE_MAZE_WIN && o->oPosY - o->oFloorHeight < 100.0f) {
            o->oAction = 1;
            if (o->oObj104->os1610A == o->oFloor->force) {
                play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gGlobalSoundSource);
                o->oObj104->os16108++;
            }
        }
    } else {
        cur_obj_hide();
        o->oVelY = 0.0f;
        o->oForwardVel = 0.0f;
        if (o->oTimer > 20) {
            if (o->oObj104->oBehParams2ndByte >= 3) {
                o->oObj104->oAction = 3;
            } else {
                o->oObj104->oAction = 1;
            }

            gComitCutsceneObject = NULL;
            o->activeFlags = 0;
        }
    }


    if (o->oPosY < 7500.0f || o->oTimer > 500) {
        if (o->oObj104->oBehParams2ndByte >= 3) {
            o->oObj104->oAction = 3;
        } else {
            o->oObj104->oAction = 1;
        }
        gComitCutsceneObject = NULL;
        o->activeFlags = 0;
    }

    // if (o->oPosY < o->oHomeY - 150.0f) {
    //     o->activeFlags = 0;
    //     create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
    //     gMarioState->numCoins++;
    // }
    // if (o->oTimer & 0x10) {
    //     // o->header.gfx.scale[0] *= -1.0f;
    //     o->oFaceAngleYaw += 0x8000;
    //     o->oTimer = 0;
    // }
}




void bhv_outside_mound_block_init(void) {
    // s2DGateVals[0] = 0;
    // s2DGateVals[1] = 0;
    // s2DGateVals[2] = 0;
    // s2DGateVals[3] = 0;
    // s2DGateVals[4] = 0;
    o->os16F4 = o->oBehParams2ndByte % 4;
    o->os16F6 = o->oBehParams2ndByte / 4;
    if (sOutsideObjs[o->os16F4][o->os16F6] == NULL) {
        // if ((o->oBehParams >> 24) == 1 && !(save_file_get_currency_flags() & (1 << 8))) {
        //     o->oBehParams = 8 << 24;
        //     spawn_default_star(o->oPosX - 879.0f, o->oPosY + 450.0f, o->oPosZ + 662.0f);
        // }
    } else {
        o->oPosX = sOutsideObjs[o->os16F4][o->os16F6]->oPosX;
        o->oPosZ = sOutsideObjs[o->os16F4][o->os16F6]->oPosZ;
    }


}

// void bhv_mind_mound_block_loop(void) {
//     switch (o->oAction) {
//         case 0:
//             o->oMoveAngleYaw = 0x8000;
//             if (gMarioState->wall != NULL && gMarioState->wall->object == o && gMarioState->flags & MARIO_UNKNOWN_31
//                 && gMarioState->wall->force == 1) {
//                 o->oForwardVel = 10.0f;
//                 CL_Move();
//                 gMarioState->pos[0] += o->oVelX;
//                 gMarioState->pos[2] += o->oVelZ;
//                 // if (o->oPosY - find_floor_height(o->oPosX, o->oPosY, o->oPosZ) > 100.0f) {
//                 //     o->oAction = 3;
//                 // }
//                 if (absf(o->oPosZ - o->oHomeZ) > 574.0f) {
//                     o->oAction = 3;
//                 }
//             }
//             break;
//         case 1:
//             mind_mound_block_act_1();
//             break;
//         case 2:
//             break;
//         case 3:
//             o->oFloat110 = approach_f32_symmetric(o->oFloat110, 70.0f, 3.0f);
//             o->oPosY = approach_f32_symmetric(o->oPosY, 5637.0f, o->oFloat110);
//             if (o->oPosY == 5637.0f) {
//                 o->oAction = 1;
//                 if (sOutsideObjs[3][0] != NULL) {
//                     sOutsideObjs[3][0]->os16FA = 1;
//                     sOutsideObjs[3][0]->oAction = 1;
//                 }
//                 bhv_mind_mound_block_init();
//                 play_puzzle_jingle();
//             }
//             break;
//     }
// }

void bhv_outside_mound_block_loop(void) {
    struct Object *obj;
    if (sOutsideObjs[0][0] == NULL) {
        return;
    }

    o->os16F4 = o->oBehParams2ndByte % 4;
    o->os16F6 = o->oBehParams2ndByte / 4;
    if (sOutsideObjs[o->os16F4][o->os16F6] == NULL) {
        return;
    }
    sOutsideObjs[o->os16F4][o->os16F6]->os16FA = 0;

    if (gMarioState->wall != NULL && gMarioState->wall->object == o && gMarioState->flags & MARIO_UNKNOWN_31) {
        switch (gMarioState->wall->force) {
            case 0:
                if (o->oBehParams2ndByte <= 3) {
                    play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                    break;
                }
                o->oBehParams2ndByte -= 4;
                obj = sOutsideObjs[o->oBehParams2ndByte % 4][o->oBehParams2ndByte / 4];
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
                obj = sOutsideObjs[o->oBehParams2ndByte % 4][o->oBehParams2ndByte / 4];
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
                obj = sOutsideObjs[o->oBehParams2ndByte % 4][o->oBehParams2ndByte / 4];
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
                obj = sOutsideObjs[o->oBehParams2ndByte % 4][o->oBehParams2ndByte / 4];
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
        obj = sOutsideObjs[o->oBehParams2ndByte % 4][o->oBehParams2ndByte / 4];
        if (obj != NULL) {
            o->oMoveAngleYaw = obj_angle_to_object(o, obj);
        }
    }

    o->os16F4 = o->oBehParams2ndByte % 4;
    o->os16F6 = o->oBehParams2ndByte / 4;
    if (sOutsideObjs[o->os16F4][o->os16F6] == NULL) {
        return;
    }
    sOutsideObjs[o->os16F4][o->os16F6]->os16FA = 1;
    o->oPosX = approach_f32_symmetric(o->oPosX, sOutsideObjs[o->os16F4][o->os16F6]->oPosX, absf(20.0f * sins(o->oMoveAngleYaw)));
    o->oPosZ = approach_f32_symmetric(o->oPosZ, sOutsideObjs[o->os16F4][o->os16F6]->oPosZ, absf(20.0f * coss(o->oMoveAngleYaw)));
}




void outside_mounds_check_adjacent(void) {
    struct Object *obj;
    if (o->os16F4 > 0) {
        obj = sOutsideObjs[o->os16F4 - 1][o->os16F6];
        if (obj != NULL && obj->os16F8 == 1 && obj->os16FA == 0) {
            obj->oAction = 3;
        }
    }
    if (o->os16F4 < 3) {
        obj = sOutsideObjs[o->os16F4 + 1][o->os16F6];
        if (obj != NULL && obj->os16F8 == 1 && obj->os16FA == 0) {
            obj->oAction = 3;
        }
    }

    if (o->os16F6 > 0) {
        obj = sOutsideObjs[o->os16F4][o->os16F6 - 1];
        if (obj != NULL && obj->os16F8 == 1 && obj->os16FA == 0) {
            obj->oAction = 3;
        }
    }
    if (o->os16F6 < 3) {
        obj = sOutsideObjs[o->os16F4][o->os16F6 + 1];
        if (obj != NULL && obj->os16F8 == 1 && obj->os16FA == 0) {
            obj->oAction = 3;
        }
    }

}


s32 check_outside_mound_key(void) {
    struct Object *obj;
    s32 i;
    for (i = 0; i < 16; i++) {
        obj = sOutsideObjs[i % 4][i / 4];
        if (obj == NULL || obj->os16F8 == 0) {
            return FALSE;
        }
    }
    return TRUE;
}


void despawn_all_outside_mounds(void) {
    struct Object *obj;
    s32 i;
    for (i = 0; i < 16; i++) {
        obj = sOutsideObjs[i % 4][i / 4];
        if (obj != NULL) {
            obj->activeFlags = 0;
            obj = NULL;
        }
    }
}


//F4 = column/horizontal
//F6 = row/vertical
void bhv_outside_mound_init(void) {
    o->os16F4 = o->oBehParams2ndByte % 4;
    o->os16F6 = o->oBehParams2ndByte / 4;
    sOutsideObjs[o->os16F4][o->os16F6] = o;

    o->os16F8 = o->oBehParams >> 24;
    if (o->os16F8) {
        o->oAction = 2;
        o->oPosY -= 150.0f;
    } else {
        if (sMoundToColor[o->oBehParams2ndByte] >= 0) {
            s2DGateVals[sMoundToColor[o->oBehParams2ndByte]]++;
        }
    }

    // if (save_file_get_currency_flags() & (1 << 8)) {
    //     o->activeFlags = 0;
    //     sOutsideObjs[o->os16F4][o->os16F6] = NULL;
    // }
}


void bhv_outside_mound_loop(void) {
    switch (o->oAction) {
        case 0:
            if (cur_obj_is_mario_ground_pounding_platform()) {
                o->oAction = 1;
                outside_mounds_check_adjacent();
                if (sMoundToColor[o->oBehParams2ndByte] >= 0) {
                    s2DGateVals[sMoundToColor[o->oBehParams2ndByte]]--;
                }
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

                    if (check_outside_mound_key()) {
                        o->oBehParams = 8 << 24;
                        spawn_default_star(o->oPosX, o->oPosY + 450.0f, o->oPosZ);
                        despawn_all_outside_mounds();
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
                if (sMoundToColor[o->oBehParams2ndByte] >= 0) {
                    s2DGateVals[sMoundToColor[o->oBehParams2ndByte]]++;
                }
            }
            break;
    }
}