static struct Object *sMIPSObjs[4][4] = {NULL};

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
