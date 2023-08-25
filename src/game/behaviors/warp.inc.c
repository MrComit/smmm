// warp.inc.c

void bhv_warp_loop(void) {
    if (o->oTimer == 0) {
        u16 sp6 = (o->oBehParams >> 24) & 0xFF;

        if (sp6 == 0) {
            o->hitboxRadius = 50.0f;
        } else if (sp6 == 0xFF) {
            o->hitboxRadius = 10000.0f;
        } else {
            o->hitboxRadius = sp6 * 10.0;
        }
        o->hitboxHeight = 50.0f;
    }

    o->oInteractStatus = 0;


    if (cur_obj_has_behavior(bhvWarpPipe)) {
        if (((o->oBehParams >> 8) & 0xFF) == 0) {
            load_object_collision_model();
            if (o->oFaceAngleRoll != 0) {
                o->hitboxDownOffset = 100.0f;
            }
        } else {
            cur_obj_become_intangible();
        }
    }
}

extern s32 gRedCoinMissionActive;
extern s16 gComitCutsceneTimer;
extern Vec3f gComitCutscenePosVec;
extern Vec3f gComitCutsceneFocVec;

void fading_warp_active_check(s16 param) {
    struct Object *obj;
    s32 val = FALSE;
    switch (param) {
        case 1:
            if (save_file_get_keys(0) & (1 << 2)) {
                val = TRUE;
                o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 15.0f);
                if (!(save_file_get_newflags(1) & SAVE_TOAD_FLAG_WARP_CUTSCENE)) {
                    gCamera->comitCutscene = 0xFF;
                    gComitCutsceneTimer = 15;
                    vec3f_set(gComitCutscenePosVec, o->oPosX, o->oPosY + 700.0f, o->oPosZ - 2500.0f);
                    vec3f_copy(gComitCutsceneFocVec, &o->oPosX);
                    // set_mario_npc_dialog(1);
                    if (o->oPosY == o->oHomeY) {
                        // set_mario_npc_dialog(0);
                        save_file_set_newflags(SAVE_TOAD_FLAG_WARP_CUTSCENE, 1);
                    }
                }
            } else {
                o->oPosY = o->oHomeY + 1000.0f;
            }
            break;
        case 2:
            if (save_file_get_boos() & (1 << 0x9)) {
                val = TRUE;
            }
            break;
        case 3:
            if (save_file_get_boos() & (1 << 0x10)) {
                val = TRUE;
            }
            break;
        case 4:
            obj = cur_obj_nearest_object_with_behavior(bhvBasementSwitch);
            if (obj == NULL || obj->oAction != 0) {
                val = TRUE;
                o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 25.0f);
            } else {
                o->oPosY = o->oHomeY + 700.0f;
            }
            break;
        case 5:
            obj = cur_obj_nearest_object_with_behavior(bhvBrokenKey);
            if (obj == NULL) {
                val = TRUE;
                o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 15.0f);
            } else {
                o->oPosY = o->oHomeY + 700.0f;
            }
            break;
        case 6:
            obj = cur_obj_nearest_object_with_behavior(bhvCityBridge2);
            if (obj != NULL && obj->oF4) {
                val = TRUE;
                o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 15.0f);
            } else {
                o->oPosY = o->oHomeY + 700.0f;
            }
            break;
        case 7:
            if (o->oF4) {
                val = TRUE;
            }
            break;
        case 8:
            if (gRedCoinMissionActive) {
                val = TRUE;
            }
            break;
        case 9:
            if (save_file_get_keys(0) & (1 << 2)) {
                val = TRUE;
            }
            break;
        case 10:
            if (save_file_get_boos() & (1 << 0xA)) {
                val = TRUE;
            }
            break;
    }
    if (val) {
        cur_obj_enable();
    } else {
        cur_obj_disable();
    }
}


// identical to the above function except for o->hitboxRadius
void bhv_fading_warp_loop() {
    s16 param;
    if (o->oTimer == 0) {
        u16 sp6 = (o->oBehParams >> 24) & 0xFF;

        if (sp6 == 0) {
            o->hitboxRadius = 85.0f;
        } else if (sp6 == 0xFF) {
            o->hitboxRadius = 10000.0f;
        } else {
            o->hitboxRadius = sp6 * 10.0;
        }
        o->hitboxHeight = 50.0f;
    }

    o->oInteractStatus = 0;
    param = (o->oBehParams >> 8) & 0xFF;
    if (param) {
        fading_warp_active_check(param);
    }
}
