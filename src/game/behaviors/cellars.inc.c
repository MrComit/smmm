extern s16 gComitCutsceneTimer;

extern s16 s8DirModeBaseYaw;


Vec3s sBasementSwitchCols[5] = {
{0xCE, 0x00, 0x11}, // CE0011
{0x1C, 0x19, 0xAF}, // 1C19AF
{0x25, 0xA2, 0x7C}, // 25A27C
{0xBD, 0xCB, 0x24}, // BDCB24
{0x6D, 0x37, 0x11}, // 6D3711
};


void bhv_colored_gate_init(void) {
    o->os16F4 = sBasementSwitchCols[o->oBehParams2ndByte][0];
    o->os16F6 = sBasementSwitchCols[o->oBehParams2ndByte][1];
    o->os16F8 = sBasementSwitchCols[o->oBehParams2ndByte][2];
    if (save_file_get_newflags(0) & (SAVE_NEW_FLAG_BASEMENT_SWITCH1 << o->oBehParams2ndByte)) {
        o->activeFlags = 0;
    }
}


void bhv_colored_gate_loop(void) {
    switch (o->oAction) {
        case 0:
            if (save_file_get_newflags(0) & (SAVE_NEW_FLAG_BASEMENT_SWITCH1 << o->oBehParams2ndByte)) {
                o->oAction = 1;
                vec3f_copy(gComitCutsceneFocVec, &o->oPosX);
                vec3f_set(gComitCutscenePosVec, o->oPosX, 484.0f, -6550.0f);
            }
            break;
        case 1:
            if (set_mario_npc_dialog(1)) {
                gCamera->comitCutscene = 0xFF;
                if (o->oTimer > 15) {
                    o->oAction = 2;
                    play_puzzle_jingle();
                }
            } else {
                o->oTimer = 0;
            }
            break;
        case 2:
            gCamera->comitCutscene = 0xFF;
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY + 1200.0f, 15.0f);
            if (o->oPosY >= o->oHomeY + 600.0f) {
                cur_obj_play_sound_1(SOUND_ENV_ELEVATOR1);
            }
            if (o->oPosY >= o->oHomeY + 1200.0f) {
                o->activeFlags = 0;
                set_mario_npc_dialog(0);
            }
            break;
    }
}




void bhv_basement_switch_init(void) {
    o->os16F4 = sBasementSwitchCols[o->oBehParams2ndByte][0];
    o->os16F6 = sBasementSwitchCols[o->oBehParams2ndByte][1];
    o->os16F8 = sBasementSwitchCols[o->oBehParams2ndByte][2];
    if (save_file_get_newflags(0) & (SAVE_NEW_FLAG_BASEMENT_SWITCH1 << o->oBehParams2ndByte)) {
        o->oAction = 2;
        o->header.gfx.scale[1] = 0.2f;
    }
}


void bhv_basement_switch_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o && !(gMarioStates[0].action & MARIO_UNKNOWN_13)) {
                if (lateral_dist_between_objects(o, gMarioObject) < 127.5f) {
                    o->oAction = 1;
                    save_file_set_newflags(SAVE_NEW_FLAG_BASEMENT_SWITCH1 << o->oBehParams2ndByte, 0);
                }
            }
            break;
        case 1:
            cur_obj_scale_over_time(2, 3, 1.5f, 0.2f);
            if (o->oTimer == 3) {
                cur_obj_play_sound_2(SOUND_GENERAL2_PURPLE_SWITCH);
                o->oAction = 2;
                cur_obj_shake_screen(SHAKE_POS_SMALL);
                queue_rumble_data(5, 80);
            }
            break;
    }
}



s32 security_cam_respawn(Vec3f pos, s16 faceAngle, s16 damage) {
    if (gMarioState->health <= 0x280) {
        level_trigger_warp(gMarioState, WARP_OP_WARP_FLOOR);
        o->oAction = 2;
        return 0;
    } else {
        switch (o->os16FE) {
            case 0:
                play_transition(WARP_TRANSITION_FADE_INTO_CIRCLE, 0x10, 0x00, 0x00, 0x00);
                break;
            case 13:
                vec3f_copy(gMarioState->pos, pos);
                CL_set_camera_pos(pos, pos);
                gMarioState->faceAngle[1] = faceAngle;
                s8DirModeBaseYaw = (s16)(faceAngle & 0xC000) - 0x4000;
                set_mario_action(gMarioState, ACT_JUMP_LAND_STOP, 0);
                break;
            case 16:
                play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 0xC, 0x00, 0x00, 0x00);
                gMarioState->hurtCounter = 4 * damage;
                o->os16FE = 0;
                return 1;
                break;
        }
    }
    o->os16FE++;
    return 0;
}


void bhv_security_cam_init(void) {
    o->oRoom = 4;
    switch (o->oBehParams2ndByte) {
        case 0:
            o->os16F4 = -2435;
            o->os16F8 = -101;
            o->os16FC = 300;
            break;
        case 1:
            o->os16F4 = -835;
            o->os16F8 = -400;
            o->os16FC = 500;
            break;
        case 2:
            o->oRoom = 5;
            o->os16F4 = -2235;
            o->os16FA = 960;
            o->os16FC = 400;
            break;
    }
}


void bhv_security_cam_loop(void) {
    struct Object *obj;
    Vec3f point;
    f32 dist, xComp, zComp;
    s16 pitch, yaw;
    switch (o->oBehParams2ndByte) {
        case 0:
            o->os16F6 += 0x100;
            o->os16FA = (400 + 1100) + (sins(o->os16F6) * 1100);
            break;
        case 1:
            o->os16F6 += 0x100;
            o->os16FA = (600 + 850) + (sins(o->os16F6) * 850);
            break;
        case 2:
            o->os16F6 += 0xA0;
            o->os16F8 = (-300 - 850) + (sins(o->os16F6) * -850);
            break;
    }

    switch (o->oAction) {
        case 0:
            xComp = (f32)o->os16F8 - 441.0f;
            zComp = (f32)o->os16FA + 441.0f;
            point[0] = (xComp * coss(o->oFaceAngleYaw)) + (zComp * sins(o->oFaceAngleYaw)) + o->oPosX;
            point[1] = gMarioState->pos[1];//o->os16F4 + o->oPosY;
            point[2] = (zComp * coss(o->oFaceAngleYaw)) + (xComp * sins(o->oFaceAngleYaw)) + o->oPosZ;
            vec3f_get_dist_and_angle(point, gMarioState->pos, &dist, &pitch, &yaw);

            if ((s16)dist < o->os16FC && absi((s16)gMarioState->pos[1] - (o->os16F4 + o->oPosY)) < 800) {
                // play_puzzle_jingle();
                o->oAction = 1;
                CL_get_hit(gMarioState, gMarioObject, 0);
            }
            break;
        case 1:
            obj = cur_obj_nearest_object_with_behavior(bhvAirborneDeathWarp);
            if (obj != NULL) {
                if (security_cam_respawn(&obj->oPosX, -obj->oFaceAngleYaw, 2)) {
                    o->oAction = 0;
                }
            }
            break;
    }
}


void bhv_champagne_init(void) {
    o->oObjF4 = cur_obj_nearest_object_with_behavior(bhvCellarBlockade);
    if (o->oObjF4 == NULL) {
        o->activeFlags = 0;
    }
}

void bhv_champagne_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oFlags & OBJ_FLAG_KICKED_OR_PUNCHED && gMarioState->faceAngle[1] < -0x2000 && gMarioState->faceAngle[1] > -0x6000) {
                o->oAction = 1;
                // o->oObjF4->oFC = 1;
                o->oFloatF8 = o->oObjF4->oPosX - 300.0f;
                o->oFloat104 = o->oObjF4->oPosY + 200.0f;
                vec3f_copy(gComitCutsceneFocVec, &o->oObjF4->oPosX);
                vec3f_set(gComitCutscenePosVec, -2500.0f, 3400.0f, 9800.0f);
                o->oFloatFC = 65.0f;
            }
            break;
        case 1:
            set_mario_npc_dialog(1);
            cur_obj_update_floor_and_walls();
            gCamera->comitCutscene = 0xFF;
            o->oFloatFC = approach_f32_asymptotic(o->oFloatFC, 5.0f, 0.17f);
            o->oPosX = approach_f32_symmetric(o->oPosX, o->oFloatF8, o->oFloatFC);
            if (o->oFloorHeight != o->oHomeY) {
                o->oFloat100 = approach_f32_symmetric(o->oFloat100, 100.0f, 2.4f);
                o->oPosY = approach_f32_symmetric(o->oPosY, o->oFloat104, o->oFloat100);
            }
            o->oFaceAngleRoll -= o->oFloat100 * 50;
            if (o->oPosX == o->oFloatF8 && o->oPosY == o->oFloat104) {
                o->oObjF4->oFC = 1;
                CL_explode_object(o, 1);
                play_puzzle_jingle();
            }
            break;
    }
}

void bhv_cellar_blockade_init(void) {
    o->oObj100 = cur_obj_nearest_object_with_behavior(bhvFlame);
    if (o->oObj100 == NULL) {
        o->activeFlags = 0;
    } else {
        o->oObj100->os16F4 = 0xFF;
    }
}

void bhv_cellar_blockade_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oFC) {
                o->oAction = 1;
                o->oObjF4 = spawn_object(o, MODEL_ENV_FLAME, bhvFlame);
                obj_scale(o->oObjF4, 0.0f);
                o->oObjF4->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
                // o->oFloatF8 = 7.0f;
                o->oObjF4->oIntangibleTimer = -1;
                o->oObjF4->os16F4 = 0xFF;
            }
            break;
        case 1:
            o->oObjF4->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
            gCamera->comitCutscene = 0xFF;
            o->oObjF4->oIntangibleTimer = -1;
            o->oObj100->os16F6 = o->oObjF4->os16F6 = approach_s16_symmetric(o->oObjF4->os16F6, 0xFF, 0xA);
            if (o->oObjF4->os16F6 >= 0x7F) {
                o->oObj100->os16F8 = o->oObjF4->os16F8 = approach_s16_symmetric(o->oObjF4->os16F8, 0xE0, 0x10);
            }
            o->oFloatF8 = approach_f32_symmetric(o->oFloatF8, 20.0f, 0.5f);
            obj_scale(o->oObjF4, o->oFloatF8);
            if (o->oFloatF8 == 20.0f) {
                o->oAction = 2;
                gComitCutsceneTimer = 30;
            }
            break;
        case 2:
            CL_explode_object(o, 1);
            o->oObjF4->activeFlags = 0;
            set_mario_npc_dialog(0);
            break;
    }
}