#include "src/game/tile_scroll.h"
#define THWOMP_SPEED_FACTOR 0.05f


void reverse_scroll_lll_dl_Treadmill_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 170;
	int width = 32 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(lll_dl_Treadmill_mesh_layer_1_vtx_1);

	deltaY = (int)(-2.799999952316284 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void reverse_scroll_lll_dl_Treadmill_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 32;
	int width = 32 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(lll_dl_Treadmill_mesh_layer_1_vtx_2);

	deltaY = (int)(-5.599999904632568 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void reverse_scroll_sts_mat_lll_dl_Treadmill_layer1() {
	static int intervalTex0 = 2;
	static int curInterval0 = 2;
	Gfx *mat = segmented_to_virtual(mat_lll_dl_Treadmill_layer1);

	if (--curInterval0 <= 0) {
		shift_t_down(mat, 13, PACK_TILESIZE(0, -1));
		curInterval0 = intervalTex0;
	}
};

void reverse_scroll_sts_mat_lll_dl_TreadmillFAST_layer1() {
	Gfx *mat = segmented_to_virtual(mat_lll_dl_TreadmillFAST_layer1);
	shift_t_down(mat, 13, PACK_TILESIZE(0, -1));
};


void reverse_treadmill_scroll(void) {
    reverse_scroll_lll_dl_Treadmill_mesh_layer_1_vtx_1();
    reverse_scroll_lll_dl_Treadmill_mesh_layer_1_vtx_2();
    reverse_scroll_sts_mat_lll_dl_Treadmill_layer1();
    reverse_scroll_sts_mat_lll_dl_TreadmillFAST_layer1();
}



s32 gPowerOn = FALSE;
void bhv_exercise_bike_loop(void) {
    if (gLowGrav || cur_obj_nearest_object_with_behavior(bhvBikeShyguy)) {
        gPowerOn = TRUE;
    } else {
        gPowerOn = FALSE;
        reverse_treadmill_scroll();
    }
    
    if (!cur_obj_nearest_object_with_behavior(bhvBikeShyguy)) {
        if (o->header.gfx.animInfo.animFrame > 0) {
            o->header.gfx.animInfo.animFrame--;
        }
    }

}

void bhv_bike_shyguy_loop(void) {
    o->os16104 += 0xBA2;
    o->oFaceAnglePitch = 0x888 + (sins(o->os16104 - 0x4000) * 0x888);
    if (o->oInteractStatus & INT_STATUS_INTERACTED && o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
        spawn_mist_particles();
        obj_spawn_loot_yellow_coins(o, o->oNumLootCoins, 20.0f);
        o->activeFlags = 0;
        create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
    }
    o->oInteractStatus = 0;
}


void power_door_update_color(s32 val) {
    if (val) {
        o->os16F4 = approach_s16_symmetric(o->os16F4, 0x0, 0x6);
        o->os16F6 = approach_s16_symmetric(o->os16F6, 0x72, 0x6);
        o->os16F8 = approach_s16_symmetric(o->os16F8, 0xFF, 0x6);
    } else {
        o->os16F4 = approach_s16_symmetric(o->os16F4, 0x79, 0x6);
        o->os16F6 = approach_s16_symmetric(o->os16F6, 0x0, 0x6);
        o->os16F8 = approach_s16_symmetric(o->os16F8, 0x0, 0x6);
    }
}


Vec3s sPowerButtonCols[3] = {
{0xFF, 0x01, 0x99}, // magenta
{0xFF, 0xFF, 0x00}, // yellow
{0x03, 0x03, 0xFF}, // blue
};

s32 sPowerButtonsPressed = 0;
s32 sPowerButtonsReset = FALSE;


void bhv_power_bar_init(void) {
    o->os16F4 = sPowerButtonCols[o->oBehParams2ndByte][0];
    o->os16F6 = sPowerButtonCols[o->oBehParams2ndByte][1];
    o->os16F8 = sPowerButtonCols[o->oBehParams2ndByte][2];
    sPowerButtonsPressed = 0;
    sPowerButtonsReset = FALSE;

    switch (o->oBehParams2ndByte) {
        case 0:
            o->oObjFC = CL_obj_nearest_object_behavior_params(bhvPowerBar, 1 << 16);
            o->oObj100 = CL_obj_nearest_object_behavior_params(bhvPowerBar, 2 << 16);
            break;
        case 1:
            o->oObjFC = CL_obj_nearest_object_behavior_params(bhvPowerBar, 0);
            o->oObj100 = CL_obj_nearest_object_behavior_params(bhvPowerBar, 2 << 16);
            break;
        case 2:
            o->oObjFC = CL_obj_nearest_object_behavior_params(bhvPowerBar, 1 << 16);
            o->oObj100 = CL_obj_nearest_object_behavior_params(bhvPowerBar, 0);
            break;
    } 

    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_ENGINE_GATE_OPEN2) {
        o->oAction = 0xFF;
        o->os16FA = 5;
    } else {
        o->os16FA = 0;
    }
}


void bhv_power_bar_loop(void) {
    if (o->os16FA == 0) {
        o->header.gfx.scale[2] = 0.25f;
    } else if (o->os16FA > 5) {
        o->os16FA = 5;
    }
    o->header.gfx.scale[2] = approach_f32_symmetric(o->header.gfx.scale[2], (f32)o->os16FA, 0.13f);
    if (sPowerButtonsReset && o->oBehParams2ndByte == 2 && sPowerButtonsPressed == 0) {
        sPowerButtonsReset = FALSE;
    }
    switch (o->oAction) {
        case 0:
            if (o->header.gfx.scale[2] == (f32)(o->os16FA)) {
                if (sPowerButtonsPressed == 0b11111 && (o->os16FA < 5 || o->oBehParams2ndByte != 2)) {
                    sPowerButtonsReset = TRUE;
                    o->os16FA = 0;
                    o->oAction = 0;
                    o->oObjFC->os16FA = 0;
                    o->oObjFC->oAction = 0;
                    o->oObj100->os16FA = 0;
                    o->oObj100->oAction = 0;
                    play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                } else if (o->os16FA >= 5) {
                    o->oAction = 1;
                    play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gGlobalSoundSource);
                }
            }
            break;
        case 1:
            break;
    }
}


void bhv_power_button_init(void) {
    o->os16F4 = o->os16F6 = o->os16F8 = 0x20;

    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_ENGINE_GATE_OPEN2) {
        o->oAction = 0xFF;
        o->oPosY = o->oHomeY - 45.0f;
    }
}



void bhv_power_button_loop(void) {
    switch (o->oAction) {
        case 0:
            if (cur_obj_nearest_object_with_behavior(bhvBikeShyguy) == NULL) {
                o->oAction = 1;
                o->oObjFC = CL_obj_nearest_object_behavior_params(bhvPowerBar, 0);
                if (o->oObjFC == NULL) {
                    o->activeFlags = 0;
                }
            } else {
                o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY - 45.0f, 4.0f);
            }
            break;
        case 1:
            o->os16F4 = approach_s16_symmetric(o->os16F4, sPowerButtonCols[o->os16FA][0], 0x6);
            o->os16F6 = approach_s16_symmetric(o->os16F6, sPowerButtonCols[o->os16FA][1], 0x6);
            o->os16F8 = approach_s16_symmetric(o->os16F8, sPowerButtonCols[o->os16FA][2], 0x6);
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 4.0f);

            if (o->oObjFC->oAction != 0) {
                o->os16FA++;
                o->oObjFC = CL_obj_nearest_object_behavior_params(bhvPowerBar, o->os16FA << 16);
                if (o->oObjFC == NULL) {
                    o->activeFlags = 0;
                    return;
                }
            }

            if (gMarioObject->platform == o) {
                o->oAction = 2;
                o->oObjFC->os16FA += o->oBehParams2ndByte + 1;
                sPowerButtonsPressed |= (1 << o->oBehParams2ndByte);
            }
            break;
        case 2:
            o->os16F4 = approach_s16_symmetric(o->os16F4, sPowerButtonCols[o->os16FA][0] / 2, 0x6);
            o->os16F6 = approach_s16_symmetric(o->os16F6, sPowerButtonCols[o->os16FA][1] / 2, 0x6);
            o->os16F8 = approach_s16_symmetric(o->os16F8, sPowerButtonCols[o->os16FA][2] / 2, 0x6);
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY - 45.0f, 4.0f);

            if (sPowerButtonsReset && gMarioObject->platform != o) {
                o->oPosY = o->oHomeY;
                o->oAction = 1;
                o->os16FA = 0;
                o->oObjFC = CL_obj_nearest_object_behavior_params(bhvPowerBar, 0);
                if (o->oObjFC == NULL) {
                    o->activeFlags = 0;
                }
                sPowerButtonsPressed &= ~(1 << o->oBehParams2ndByte);
                spawn_mist_particles();
            }
            break;
    }
}





void bhv_engine_button_gate_init(void) {
    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_ENGINE_GATE_OPEN2) {
        o->activeFlags = 0;
    }
    o->oObjF4 = CL_obj_nearest_object_behavior_params(bhvPowerBar, 2 << 16);
    if (o->oObjF4 == NULL) {
        o->activeFlags = 0;
    }
}

void bhv_engine_button_gate_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioCurrentRoom == o->oRoom) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oPosY = approach_f32(o->oPosY, o->oHomeY - 300.0f, 20.0f, 20.0f);
            if (o->oObjF4->oAction != 0) {
                o->oAction = 2;
            }
            break;
        case 2:
            o->oPosY = approach_f32(o->oPosY, o->oHomeY, 20.0f, 20.0f);
            if (o->oPosY == o->oHomeY) {
                o->activeFlags = 0;
                save_file_set_newflags(SAVE_NEW_FLAG_ENGINE_GATE_OPEN2, 0);
                play_puzzle_jingle();
            }
            break;
    }
}







void bhv_button_door_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            cur_obj_unhide();
            o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 1.0f, 0.02f);
            if (o->oPosY != o->oHomeY) {
                o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 30.0f);
                cur_obj_play_sound_1(SOUND_ENV_ELEVATOR1);
            }
            obj = cur_obj_nearest_object_with_behavior(bhvBasementSwitch);
            if (obj == NULL || obj->oAction != 0) {
                o->oAction = 1;
            }
            power_door_update_color(0);
            break;
        case 1:
            o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 0.9f, 0.02f);
            if (o->oPosY != o->oHomeY + 900.0f) {
                o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY + 900.0f, 30.0f);
                cur_obj_play_sound_1(SOUND_ENV_ELEVATOR1);
            } else {
                cur_obj_hide();
                o->oAction = 2;
            }
            power_door_update_color(1);
            break;
    }
}

void bhv_leg_press_init(void) {
    if (o->oBehParams2ndByte) {
        o->oPosY = o->oHomeY + 667.0f;
        o->oAction = 1;
    }
    if (o->oBehParams >> 24) {
        o->oFloatF4 = 60.0f;
        o->os16F8 = 15;
    } else {
        o->oFloatF4 = 20.0f;
        o->os16F8 = 90;
    }
}

void bhv_leg_press_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oTimer > 30 || o->oBehParams >> 24) {
                o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY + 667.0f, o->oFloatF4);
                cur_obj_play_sound_1(SOUND_ENV_ELEVATOR1);
                if (o->oTimer > o->os16F8 && o->oPosY == o->oHomeY + 667.0f) {
                    if (gPowerOn) {
                        o->oAction = 1;
                    }
                }
            }
            break;
        case 1:
            if (o->oTimer > o->os16F8 || o->oBehParams >> 24) {
                o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 60.0f);

                if (o->oPosY == o->oHomeY && o->oTimer > o->os16F8) {
                    if (gPowerOn) {
                        o->oAction = 0;
                    }
                }
                if (o->oTimer == 75) {
                    cur_obj_play_sound_1(SOUND_OBJ_MAD_PIANO_CHOMPING);
                }
            }
            break;
    }
}


void bhv_heavy_weight_init(void) {
    o->os16FA = CL_RandomMinMaxU16(2, 20);
}


void bhv_heavy_weight_loop(void) {
    s32 i;
    if (!gLowGrav) {
        o->oAction = 0;
        o->oTimer = 0;
    } else {
    }

    switch (o->oAction) {
        case 0:
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 10.0f);
            if (o->oTimer > o->os16FA) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 10.0f);
            if (o->oTimer > 90) {
                o->oAction = 2;
                o->os16F6 = 0xC000;
            }
            break;
        case 2:
            o->os16F6 += 0x300;
            o->oPosY = o->oHomeY + 300.0f + (sins(o->os16F6) * 300.0f);
            if (o->oTimer > 180) {
                o->oAction = 1;
            }
            if (o->oDistanceToMario < 1200.0f || !gIsConsole) {
                for (i = 0; i < 3; i++) {
                    struct Object *wind = spawn_object(o, MODEL_MIST, bhvWind);
                    wind->oMoveAngleYaw = 0;
                    wind->oMoveAnglePitch = 1;
                    wind->oPosY = o->oHomeY - 200.0f;
                }
            }
            break;
    }

}


void bhv_engine_lever_loop(void) {
    struct Object *obj;
    if (o->oF4 == 0) {
        o->header.gfx.animInfo.animFrame = 0;
        if (save_file_get_newflags(0) & SAVE_NEW_FLAG_ENGINE_GATE_OPEN) {
            o->oF4 = 1;
        }
        if (cur_obj_was_attacked_or_ground_pounded() != 0) {
            save_file_set_newflags(SAVE_NEW_FLAG_FOREROOM_WINDOW, 0);
            o->oF4 = 1;
            obj = cur_obj_nearest_object_with_behavior(bhvEngineSmallGate);
            if (obj != NULL) {
                obj->oF4 = 1;
            }
            obj = cur_obj_nearest_object_with_behavior(bhvEngineGate);
            if (obj != NULL) {
                obj->oF4 = 1;
            }
        }
    }
}

void bhv_engine_small_gate_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioCurrentRoom == o->oRoom) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oPosY = approach_f32(o->oPosY, o->oHomeY - 300.0f, 20.0f, 20.0f);
            if (o->oF4) {
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


void bhv_engine_gate_init(void) {
    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_ENGINE_GATE_OPEN) {
        o->activeFlags = 0;
    }
}


void bhv_engine_gate_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oF4) {
                play_puzzle_jingle();
                o->oAction = 1;
            }
            break;
        case 1:
            cur_obj_play_sound_1(SOUND_ENV_ELEVATOR1);
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY + 700.0f, 25.0f);
            if (o->oPosY == o->oHomeY + 700.0f) {
                o->activeFlags = 0;
                save_file_set_newflags(SAVE_NEW_FLAG_ENGINE_GATE_OPEN, 0);
            }
            break;
    }
}


void bhv_power_door_loop(void) {
    if (o->oBehParams2ndByte) {
        o->oAction = gLowGrav^1;
    } else {
        o->oAction = gLowGrav;
    }
    
    power_door_update_color(gLowGrav);

    switch (o->oAction) {
        case 0:
            cur_obj_unhide();
            o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 1.0f, 0.02f);
            if (o->oPosY != o->oHomeY) {
                o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 30.0f);
                cur_obj_play_sound_1(SOUND_ENV_ELEVATOR1);
            }
            break;
        case 1:
            o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 0.9f, 0.02f);
            if (o->oPosY != o->oHomeY + 900.0f) {
                o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY + 900.0f, 30.0f);
                cur_obj_play_sound_1(SOUND_ENV_ELEVATOR1);
            } else {
                cur_obj_hide();
            }
            break;
    }
}


void bhv_power_plat_loop(void) {
    if (o->oBehParams2ndByte) {
        o->oAction = gLowGrav^1;
    } else {
        o->oAction = gLowGrav;
    }
    
    power_door_update_color(gLowGrav);

    switch (o->oAction) {
        case 0:
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 12.0f);
            break;
        case 1:
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY + 1000.0f, 15.0f);
            break;
    }
}


void bhv_engine_gear_init(void) {
    cur_obj_update_floor_and_walls();
    o->os16F6 = random_u16();
    o->oFaceAngleYaw = random_u16();
}


void bhv_engine_gear_loop(void) {
    if (o->os16F4 != gLowGrav) {
        o->os16F4 = gLowGrav;
        o->oFloatF8 = 0.0f;
    }
    switch (gLowGrav) {
        case 0:
            o->oFloatF8 = approach_f32_symmetric(o->oFloatF8, 50.0f, 4.0f);
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oFloorHeight - 50.0f, o->oFloatF8);
            o->os16100 = approach_s16_symmetric(o->os16100, 0, 0x40);
            break;
        default:
            o->os16F6 += 0x400;
            o->oFloatFC = sins(o->os16F6) * o->oBehParams2ndByte * 10.0f;
            o->oFloatF8 = approach_f32_symmetric(o->oFloatF8, 30.0f, 1.5f);
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY + o->oFloatFC, o->oFloatF8);
            o->os16100 = approach_s16_symmetric(o->os16100, 0x400, 0x40);
            load_object_collision_model();
            break;
    }
    o->oFaceAngleYaw += o->os16100;
}



void bhv_thwomp_block_init(void) {
    o->os16100 = 0xC000;
    o->os16FA = CL_RandomMinMaxU16(0, 2);
    if (o->oBehParams2ndByte) {
        o->oFloat104 = o->oBehParams2ndByte * 100.0f;
        if (o->oBehParams >> 24) {
            o->oFloat104 += 50.0f;
        }
    } else {
        o->oFloat104 = 1000.0f;
    }
    o->oFloat108 = (o->oFloat104 * THWOMP_SPEED_FACTOR) / 32.0f;
}

void bhv_thwomp_block_loop(void) {
    if (o->oTimer > 30) {
        switch (o->oAction) {
            case 0:
                o->oPosY += o->oFloat108;
                if (o->oFloat108 >= o->oFloat104 * THWOMP_SPEED_FACTOR) {
                    o->oFloat108 = o->oFloat104 * THWOMP_SPEED_FACTOR;
                } else if (o->oTimer & 1) {
                    o->oFloat108 *= 2;
                }
                if (o->oPosY >= o->oHomeY + o->oFloat104) {
                    o->oPosY = o->oHomeY + o->oFloat104;
                    o->oFloat108 = (o->oFloat104 * THWOMP_SPEED_FACTOR) / 32.0f;
                    o->oAction = 1;
                }
                break;
            case 1:
                o->oPosY -= o->oFloat108;
                if (o->oFloat108 >= o->oFloat104 * THWOMP_SPEED_FACTOR) {
                    o->oFloat108 = o->oFloat104 * THWOMP_SPEED_FACTOR;
                } else if (o->oTimer & 1) {
                    o->oFloat108 *= 2;
                }
                if (o->oPosY <= o->oHomeY) {
                    o->oPosY = o->oHomeY;
                    o->oFloat108 = (o->oFloat104 * THWOMP_SPEED_FACTOR) / 32.0f;
                    o->oAction = 0;
                }
                break;
        }
    } else if (!gLowGrav) {
        o->oTimer = 0;
        if (o->oOpacity) {
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 7);
        }
        if (o->os16100 != 0xC000) {
            o->os16100 = 0xC000;
        }
    }
    if (gLowGrav) {
        o->os16100 += 0x400;
        o->oOpacity = 70 + (sins(o->os16100) * 70);
        switch (o->os16FA) {
            case 0:
                o->os16F4 = 0xA0;
                o->os16F6 = 0;
                o->os16F8 = 0x60;
                if ((u16)o->os16100 == 0xC000) {
                    o->os16FA = 1;
                }
                break;
            case 1:
                o->os16F4 = 0;
                o->os16F6 = 0;
                o->os16F8 = 0xA0;
                if ((u16)o->os16100 == 0xC000) {
                    o->os16FA = 2;
                }
                break;
            case 2:
                o->os16F4 = 0xA0;
                o->os16F6 = 0xA0;
                o->os16F8 = 0;
                if ((u16)o->os16100 == 0xC000) {
                    o->os16FA = 0;
                }
                break;
        }
    }
}


void bhv_gravity_button_init(void) {
    if (gLowGrav) {
        o->os16F6 = 0xFF;
        o->os16100 = 120;
    } else {
        o->os16F4 = 0xFF;
    }
}

void bhv_gravity_button_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oFlags & OBJ_FLAG_KICKED_OR_PUNCHED) {
                o->oAction = 1;
                gLowGrav ^= 1;
            }
            break;
        case 1:
            o->header.gfx.scale[2] = approach_f32_symmetric(o->header.gfx.scale[2], 0.2f, 0.1f);
            if (o->header.gfx.scale[2] == 0.2f) {
                o->oAction = 2;
            }
            break;
        case 2:
            o->header.gfx.scale[2] = approach_f32_symmetric(o->header.gfx.scale[2], 1.0f, 0.1f);
            if (o->header.gfx.scale[2] == 1.0f) {
                o->oAction = 0;
            }
            break;
    }

    o->os16FA += 0x600;
    if (gLowGrav) {
        o->os16F6 = approach_s16_symmetric(o->os16F6, 215 + (sins(o->os16FA) * 40), 10);
        o->os16F4 = approach_s16_symmetric(o->os16F4, 0, 10);
    } else {
        o->os16F4 = approach_s16_symmetric(o->os16F4, 215 + (sins(o->os16FA) * 40), 10);
        o->os16F6 = approach_s16_symmetric(o->os16F6, 0, 10);
    }
}