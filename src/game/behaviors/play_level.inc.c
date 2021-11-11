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



void bhv_frozen_goomba_init(void) {
    o->oFaceAngleYaw = random_u16();
    o->oFaceAnglePitch = random_u16();
    o->oFaceAngleRoll = random_u16();
}

void bhv_frozen_goomba_loop(void) {
    vec3f_copy(&o->oPosX, &o->parentObj->oPosX);
    //o->oPosY += 60.0f;
    o->header.gfx.animInfo.animFrame = 0;
}


s32 ice_cube_detect_wall(void) {
    s32 numCollisions;
    s32 i, k;
    struct Surface *wall;
    struct WallCollisionData collisionData;


    cur_obj_compute_vel_xz();
    for (k = 0; k < 4; k++) {
        collisionData.offsetY = 10.0f;
        collisionData.radius = 75.0f;
        collisionData.x = (s16) o->oPosX;// + o->oVelX;
        collisionData.y = (s16) o->oPosY;
        collisionData.z = (s16) o->oPosZ;// + o->oVelZ;

        numCollisions = find_wall_collisions(&collisionData);
        if (numCollisions != 0) {

            for (i = 1; i <= collisionData.numWalls; i++) {
                wall = collisionData.walls[collisionData.numWalls - i];

                if (wall->object == o->prevObj) {
                    continue;
                } else {
                    o->oPosX = collisionData.x;
                    o->oPosY = collisionData.y;
                    o->oPosZ = collisionData.z;
                }

                o->oWallAngle = atan2s(wall->normal.z, wall->normal.x);
                if (abs_angle_diff(o->oWallAngle, o->oMoveAngleYaw) > 0x4000) {
                    return TRUE;
                }
            }
        }

        cur_obj_move_using_vel_and_gravity();
    }

    return FALSE;
}


void bhv_ice_cube_loop(void) {
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

            //o->oFloatF4 = approach_f32_symmetric(o->oFloatF4, 5.0f, 0.5f);
            //o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 50.0f, o->oFloatF4);
            //CL_Move();
            spawn_mist_particles_variable(2, -40, 6.0f);
            break;
    }
}



void bhv_snow_pile_init(void) {
    vec3f_set(&o->oHomeX, -2359.0f, -500.0f, -2184.0f);
    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_PUSHED_SNOWPILE) {
        vec3f_copy(&o->oPosX, &o->oHomeX);
        o->oAction = 2;
    }
}

void bhv_snow_pile_loop(void) {
    struct MarioState *m = gMarioState;
    struct Object *obj;
    s32 whichSide = 0;
    switch (o->oAction) {
        case 0:
            o->oMoveAngleYaw = o->oFaceAngleYaw + 0x4000;
            if (m->faceAngle[1] - o->oFaceAngleYaw <= 0x6000 && m->faceAngle[1] - o->oFaceAngleYaw >= 0x2000)
                whichSide = 1;
            if (m->wall != NULL && m->wall->object == o && whichSide && m->action == ACT_WALKING) {
                o->oForwardVel = 10.0f;
                CL_Move();
                m->pos[0] += o->oVelX;
                m->pos[2] += o->oVelZ;
                if (o->oPosY - find_floor_height(o->oPosX, o->oPosY, o->oPosZ) > 100.0f) {
                    o->oAction = 1;
                }
            }
            break;
        case 1:
            set_mario_npc_dialog(1);
            gCamera->comitCutscene = 12;
            if (o->oTimer < 15) {
                o->oForwardVel = 10.0f;
                CL_Move();
            } else if (o->oTimer > 40) {
                o->oFloatF4 = approach_f32_symmetric(o->oFloatF4, 100.0f, 5.0f);
                o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, o->oFloatF4);
                if (o->oPosY == o->oHomeY) {
                    spawn_mist_particles();
                    save_file_set_newflags(SAVE_NEW_FLAG_PUSHED_SNOWPILE, 0);
                    cur_obj_shake_screen(1);
                    play_puzzle_jingle();
                    o->oAction = 2;
                    set_mario_npc_dialog(0);
                }
            }
            break;
        case 2:
            if (o->oTimer == 0) {
                obj = spawn_object(o, MODEL_SNOW_BOX, bhvBounceBoxes);
                obj->oBehParams = 0x010F0000;
                obj->oBehParams2ndByte = 0x0F;
                cur_obj_hide();
            }
            if (o->oTimer > 30) {
                gCamera->comitCutscene = 0;
                o->activeFlags = 0;
            }
            break;
    }
}


static struct Object *sMoundObjs[4][4] = {NULL};

void bhv_sand_crab_loop(void) {
    if (sMoundObjs[0][0] == NULL) {
        return;
    }

    o->os16F4 = o->oBehParams2ndByte % 4;
    o->os16F6 = o->oBehParams2ndByte / 4;
    sMoundObjs[o->os16F4][o->os16F6]->os16FA = 0;

    if (gMarioState->wall != NULL && gMarioState->wall->object == o) {
        switch (gMarioState->wall->force) {
            case 0:
                if (o->oBehParams2ndByte <= 3) {
                    play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                    break;
                }
                o->oBehParams2ndByte -= 4;
                if (sMoundObjs[o->oBehParams2ndByte % 4][o->oBehParams2ndByte / 4]->os16F8 == 0) {
                    o->oBehParams2ndByte += 4;
                    play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                    break;
                }
                break;
            case 1:
                if (o->oBehParams2ndByte % 4 == 0) {
                    play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                    break;
                }
                o->oBehParams2ndByte -= 1;
                if (sMoundObjs[o->oBehParams2ndByte % 4][o->oBehParams2ndByte / 4]->os16F8 == 0) {
                    o->oBehParams2ndByte += 1;
                    play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                    break;
                }
                break;
            case 2:
                if (o->oBehParams2ndByte >= 12) {
                    play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                    break;
                }
                o->oBehParams2ndByte += 4;
                if (sMoundObjs[o->oBehParams2ndByte % 4][o->oBehParams2ndByte / 4]->os16F8 == 0) {
                    o->oBehParams2ndByte -= 4;
                    play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                    break;
                }
                break;
            case 3:
                if (o->oBehParams2ndByte % 4 == 3) {
                    play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                    break;
                }
                o->oBehParams2ndByte += 1;
                if (sMoundObjs[o->oBehParams2ndByte % 4][o->oBehParams2ndByte / 4]->os16F8 == 0) {
                    o->oBehParams2ndByte -= 1;
                    play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
                    break;
                }
                break;
        }
    }

    o->os16F4 = o->oBehParams2ndByte % 4;
    o->os16F6 = o->oBehParams2ndByte / 4;
    sMoundObjs[o->os16F4][o->os16F6]->os16FA = 1;
    o->oPosX = approach_f32_symmetric(o->oPosX, sMoundObjs[o->os16F4][o->os16F6]->oPosX, 20.0f);
    o->oPosZ = approach_f32_symmetric(o->oPosZ, sMoundObjs[o->os16F4][o->os16F6]->oPosZ, 20.0f);
}




void sand_mounds_check_adjacent(void) {
    struct Object *obj;
    if (o->os16F4 > 0) {
        obj = sMoundObjs[o->os16F4 - 1][o->os16F6];
        if (obj->os16F8 == 1 && obj->os16FA == 0) {
            obj->oAction = 3;
        }
    }
    if (o->os16F4 < 3) {
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
    if (o->os16F6 < 3) {
        obj = sMoundObjs[o->os16F4][o->os16F6 + 1];
        if (obj->os16F8 == 1 && obj->os16FA == 0) {
            obj->oAction = 3;
        }
    }

}


s32 check_mound_star(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (sMoundObjs[i % 4][i / 4]->os16F8 == 0) {
            return FALSE;
        }
    }
    return TRUE;
}


void despawn_all_mounds(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        sMoundObjs[i % 4][i / 4]->activeFlags = 0;
        sMoundObjs[i % 4][i / 4] = NULL;
    }
}


//F4 = column/horizontal
//F6 = row/vertical
void bhv_sand_mound_init(void) {
    o->os16F4 = o->oBehParams2ndByte % 4;
    o->os16F6 = o->oBehParams2ndByte / 4;
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