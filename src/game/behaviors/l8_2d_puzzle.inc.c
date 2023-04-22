static struct Object *sOutsideObjs[4][4] = {NULL};

void bhv_outside_mound_block_init(void) {
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
            }
            break;
    }
}