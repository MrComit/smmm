#include "game/object_helpers.h"

static struct ObjectHitbox sStalactiteHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 450,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 50,
    /* height:            */ 300,
    /* hurtboxRadius:     */ 50,
    /* hurtboxHeight:     */ 300,
};


static struct Object *sMoundObjs[3][3] = {NULL};


void bhv_sand_crab_loop(void) {
    if (gMarioObject->platform == o) {
        if (gMarioState->input & INPUT_Z_PRESSED) {
            sMoundObjs[o->oBehParams2ndByte % 3][o->oBehParams2ndByte / 3]->os16FA = 0;
            o->oBehParams2ndByte++;
            while (sMoundObjs[o->oBehParams2ndByte % 3][o->oBehParams2ndByte / 3]->os16F8 == 0) {
                o->oBehParams2ndByte++;
            }
        }

        if (gMarioState->input & INPUT_B_PRESSED) {
            sMoundObjs[o->oBehParams2ndByte % 3][o->oBehParams2ndByte / 3]->os16FA = 0;
            o->oBehParams2ndByte--;
            while (sMoundObjs[o->oBehParams2ndByte % 3][o->oBehParams2ndByte / 3]->os16F8 == 0) {
                o->oBehParams2ndByte--;
            }
        }

        o->oPosX = sMoundObjs[o->oBehParams2ndByte % 3][o->oBehParams2ndByte / 3]->oPosX;
        o->oPosZ = sMoundObjs[o->oBehParams2ndByte % 3][o->oBehParams2ndByte / 3]->oPosZ;
    }

    sMoundObjs[o->oBehParams2ndByte % 3][o->oBehParams2ndByte / 3]->os16FA = 1;
}




void sand_mounds_check_adjacent(void) {
    struct Object *obj;
    if (o->os16F4 > 0) {
        obj = sMoundObjs[o->os16F4 - 1][o->os16F6];
        if (obj->os16F8 == 1 && obj->os16FA == 0) {
            obj->oAction = 3;
        }
    }
    if (o->os16F4 < 2) {
        obj = sMoundObjs[o->os16F4 + 1][o->os16F6];
        if (obj->os16F8 == 1 && obj->os16FA == 0) {
            obj->oAction = 3;
        }
    }

    if (o->os16F6 > 0) {
        obj = sMoundObjs[o->os16F4][o->os16F6 - 1];
        if (obj->os16F8 == 1 && obj->os16FA == 0) {
            obj->oAction = 3;
        }
    }
    if (o->os16F6 < 2) {
        obj = sMoundObjs[o->os16F4][o->os16F6 + 1];
        if (obj->os16F8 == 1 && obj->os16FA == 0) {
            obj->oAction = 3;
        }
    }

}


s32 check_mound_star(void) {
    s32 i;
    for (i = 0; i < 9; i++) {
        if (sMoundObjs[i % 3][i / 3]->os16F8 == 0) {
            return FALSE;
        }
    }
    return TRUE;
}


void despawn_all_mounds(void) {
    s32 i;
    for (i = 0; i < 9; i++) {
        sMoundObjs[i % 3][i / 3]->activeFlags = 0;
    }
}


//F4 = column/horizontal
//F6 = row/vertical
void bhv_sand_mound_init(void) {
    o->os16F4 = o->oBehParams2ndByte % 3;
    o->os16F6 = o->oBehParams2ndByte / 3;
    sMoundObjs[o->os16F4][o->os16F6] = o;

    o->os16F8 = o->oBehParams >> 24;
    if (o->os16F8) {
        o->oAction = 2;
        o->oPosY -= 150.0f;
    }
}


void bhv_sand_mound_loop(void) {
    switch (o->oAction) {
        case 0:
            if (cur_obj_is_mario_ground_pounding_platform()) {
                o->oAction = 1;
                sand_mounds_check_adjacent();
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

                    if (check_mound_star()) {
                        o->oBehParams = 8 << 24;
                        spawn_default_star(o->oPosX, o->oPosY + 450.0f, o->oPosZ);
                        despawn_all_mounds();
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



void bhv_stalactite_init(void) {
    obj_set_hitbox(o, &sStalactiteHitbox);
}


void bhv_stalactite_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oPosY = approach_f32(o->oPosY, o->oHomeY, 30.0f, 30.0f);
            if (gMarioState->pos[1] < o->oPosY && absf(o->oPosX - gMarioState->pos[0]) < 125.0f) {
                if (o->oTimer > 4) {
                    o->oFaceAngleRoll = 0;
                    o->oAction = 1;
                    cur_obj_play_sound_2(SOUND_GENERAL_OPEN_IRON_DOOR);
                }
            } else {
                o->oTimer = 0;
            }
            if (gMarioState->pos[1] < o->oPosY && absf(o->oPosX - gMarioState->pos[0]) < 300.0f) {
                o->oFaceAngleRoll += o->oF8;
                o->oF8 = -o->oF8;
            }
            break;
        case 1:
            cur_obj_update_floor_height();
            o->oFloatF4 = approach_f32(o->oFloatF4, 30.0f, 3.0f, 3.0f);
            o->oPosY -= o->oFloatF4;
            if (o->oInteractStatus || absf(o->oFloorHeight - (o->oPosY - 200.0f)) < 16.0f) {
                obj_explode_and_spawn_coins(46.0f, 0);
                create_respawner(MODEL_STALACTITE, bhvStalactite, 100);
            }
            break;
    }
    o->oInteractStatus = 0;
}


void bhv_snowflake_init(void) {
    o->oFaceAngleYaw = random_u16();
    if (o->oBehParams2ndByte)
        o->oF8 = 155;
    else
        o->oF8 = 255;
}

void bhv_snowflake_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioState->floor != NULL && gMarioState->floor->type == SURFACE_SNOWFLAKE_SPAWN &&
                absf(gMarioState->pos[1] - gMarioState->floorHeight) < 20.0f) {
                if (o->oTimer > 20)
                    o->oAction = 1;
            } else {
                o->oTimer = 0;
            }
            break;
        case 1:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, o->oF8, o->oF8 / 15);
            if (o->oOpacity == o->oF8) {
                o->oAction = 2;
                if (o->oBehParams >> 24 == 1) {
                    play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
                }
            }
            break;
        case 2:
            o->oFaceAngleYaw += 0xC0;
            if (o->oBehParams2ndByte == 0)
                load_object_collision_model();
            if (gMarioObject->platform == o) {
                o->oPosY = approach_f32_asymptotic(o->oPosY, o->oHomeY - 20.0f, 0.2f);
                o->oFaceAngleYaw += 0x140;
            } else {
                o->oPosY = approach_f32_asymptotic(o->oPosY, o->oHomeY, 0.1f);
            }
            if (save_file_get_currency_flags() & (1 << 0xD)) {
                    o->oAction = 3;
                }
            break;
        case 3:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, o->oF8 / 20);
            if (o->oOpacity == 0)
                o->activeFlags = 0;
            break;
    }

}


void bhv_unstable_rock_init(void) {
    o->os16F4 = o->os16F6 = o->os16F8 = 0;
}


void bhv_unstable_rock_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o) {
                o->oPosY = approach_f32(o->oPosY, o->oHomeY - 20.0f, 4.0f, 4.0f);
                if (o->oTimer > 5) {
                    o->oAction = 1;
                    o->oPosY = o->oHomeY - 20.0f;
                    o->oHomeY = o->oPosY;
                }
            } else {
                o->oTimer = 0;
                o->oPosY = approach_f32(o->oPosY, o->oHomeY, 3.0f, 3.0f);
            }
            break;
        case 1:
            o->oPosY = o->oHomeY + o->oFloat100;
            o->oFloat100 = -o->oFloat100;
            if (o->oTimer > 25) {
                o->oAction = 2;
                o->oGraphYOffset = 0;
            }
            break;
        case 2:
            o->oPosY = approach_f32(o->oPosY, o->oHomeY - 300.0f, 35.0f, 35.0f);
            o->os16F4 = approach_s16_symmetric(o->os16F4, 0xA0, 0x18);
            o->os16F6 = o->os16F8 = o->os16F4;
            if (o->oPosY == o->oHomeY - 300.0f) {
                o->oAction = 3;
                o->os16F4 = o->os16F6 = o->os16F8 = 0x80;
                o->oHomeY += 20.0f;
            }
            break;
        case 3:
            if (o->oTimer > 60) {
                o->oPosY = approach_f32(o->oPosY, o->oHomeY, 14.0f, 14.0f);
                o->os16F4 = approach_s16_symmetric(o->os16F4, 0, 0xA);
                o->os16F6 = o->os16F8 = o->os16F4;
                if (o->oPosY == o->oHomeY) {
                    o->oAction = 0;
                    o->os16F4 = o->os16F6 = o->os16F8 = 0;
                }
            }
            break;
    }
}




void bhv_fake_wall_init(void) {
    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_FAKE_WALL) {
        o->activeFlags = 0;
    }
}

void bhv_fake_wall_loop(void) {
    struct Object *obj = cur_obj_nearest_object_with_behavior(bhvGenericSwitch);
    if (obj == NULL) {
        o->activeFlags = 0;
        return;
    }
    switch (o->oAction) {
        case 0:
            if (obj->oF4) {
                o->oAction = 1;
                o->oForwardVel = -10.0f;
                gCamera->comitCutscene = 6;
                set_mario_npc_dialog(1);
            }
            break;
        case 1:
            set_mario_npc_dialog(1);
            o->oForwardVel = approach_f32(o->oForwardVel, 0.0f, 0.35f, 0.35f);
            CL_Move();
            if (o->oForwardVel == 0.0f) {
                o->oPosY += 50.0f;
                if (o->oPosY >= o->oHomeY + 1100.0f) {
                    o->oAction = 2;
                }
            }
            break;
        case 2:
            if (o->oTimer > 30) {
                o->activeFlags = 0;
                gCamera->comitCutscene = 0;
                set_r_button_camera(gCamera);
                set_mario_npc_dialog(0);
                save_file_set_newflags(SAVE_NEW_FLAG_FAKE_WALL, 0);
            }
            break;
    }

}