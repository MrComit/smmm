static void const *sForeroomCollision[] = {
    foreroom_chair_collision,
    foreroom_books_collision,
    foreroom_plant_collision,
    foreroom_table_collision,
    foreroom_vase_collision,
    foreroom_wall_collision,
};

void bhv_opening_wall_loop(void) {
    struct Object *obj;
    switch (o->os16F4) {
        case 1:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 7);
            if (o->oOpacity == 0) {
                cur_obj_hide();
                o->os16F4 = 0;
            }
            break;
        case 2:
            cur_obj_unhide();
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 9);
            if (o->oOpacity == 255) {
                if (o->os16F6++ == 5) {
                    CL_call_warp(0, -5000.0f, 0);
                    obj = cur_obj_nearest_object_with_behavior(bhvCushionFriend);
                    if (obj != NULL) {
                        obj->oPosY -= 5000.0f;
                        obj->oAction = 4;
                    }
                } else if (o->os16F6 > 10) {
                    o->activeFlags = 0;
                }
            }
            break;
    }
}

extern s32 sOHRevert;

void cushion_friend_opening(void) {
    struct MarioState *m = gMarioState;
    struct Object *obj;
    switch (o->oAction) {
        case 1:
            if (o->oSubAction == 0) {
                if (m->pos[2] > o->oPosZ + 750.0f) {
                    o->oSubAction = 1;
                    o->os16F4++;
                }
            } else {
                if (m->pos[2] < o->oPosZ - 750.0f) {
                    o->oSubAction = 0;
                    o->os16F4++;
                }
            }
            if (o->os16F4 >= 5) {
                o->oAction = 2;
            }
            break;
        case 2:
            if (m->pos[2] > 7500.0f && m->pos[2] < 8000.0f) {
                o->oAction = 3;
            }
            break;
        case 3:
            if (CL_NPC_Dialog(DIALOG_036)) {
                sOHRevert = 1;
                obj = cur_obj_nearest_object_with_behavior(bhvOpeningWall);
                if (obj != NULL) {
                    obj->os16F4 = 2;
                }
                // CL_call_warp(0, -5000.0f, 0);
                o->oAction = 5;
            }
            break;
        case 4:
            if (CL_NPC_Dialog(DIALOG_037)) {
                o->oAction = 5;
            }
            break;
    }
}

#define COMIT_OBJECT(a, b, c, d, e, f, g, h) \
    obj = spawn_object_abs_with_rot(o, 0, a, h, b, c, d, DEGREES(e), DEGREES(f), DEGREES(g)); \
    obj->oRoom = o->oRoom; \
    obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;


extern Vec3f gComitCutscenePosVec;
extern Vec3f gComitCutsceneFocVec;

void cushion_friend_trophy_one(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            vec3f_set(&o->oPosX, 1500.0f, 0.0f, 12000.0f);
            if (CL_NPC_Dialog(DIALOG_039)) {
                o->oAction = 1;
                vec3f_set(gComitCutscenePosVec, -1919.0f, 2439.0f, 14421.0f);
                vec3f_set(gComitCutsceneFocVec, -500.0f, 300.0f, 10400.0f);
            }
            break;
        case 1:
            gCamera->comitCutscene = 0xFF;
            if (o->oTimer > 20) {
                COMIT_OBJECT(MODEL_TROPHY_RECTANGLE, 1578, 0, 10898, 0, 90, 0, bhvTrophyRect)
                obj->oBehParams = (32 << 24) | (3 << 16) | (1 << 8);
                obj->oBehParams2ndByte = 3;
                COMIT_OBJECT(MODEL_TROPHY_RECTANGLE, 1578, 0, 8893, 0, -90, 0, bhvTrophyRect)
                obj->oBehParams = (32 << 24) | (3 << 16) | (1 << 8);
                obj->oBehParams2ndByte = 3;
                COMIT_OBJECT(MODEL_TROPHY_OCTOGON, -455, 1600, 6514, 0, -22, 0, bhvTrophyPlatSpin)
                obj->oBehParams = 1 << 8;
                COMIT_OBJECT(MODEL_TROPHY_OCTOGON, 241, 1600, 5109, 0, 22, 0, bhvTrophyPlatSpin)
                obj->oBehParams = 1 << 8;
                play_puzzle_jingle();
                o->oAction = 2;
            }
            break;
        case 2:
            gCamera->comitCutscene = 0xFF;
            if (o->oTimer > 80) {
                o->oAction = 3;
                save_file_set_newflags(SAVE_TOAD_FLAG_SPAWN_PLATS, 1);
            }
            break;
    }
}

void cushion_friend_morning_room(void) {
    switch (o->oAction) {
        case 0:
            vec3f_set(&o->oPosX, 1630.0f, 0.0f, -5675.0f);
            if (gMarioState->pos[2] < -5700.0f || o->oTimer > 100) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (CL_NPC_Dialog(DIALOG_040)) {
                o->oAction = 2;
                save_file_set_newflags(SAVE_TOAD_FLAG_MORNING_ROOM, 1);
            }
            break;
    }
}

void cushion_friend_trophy_two(void) {
    switch (o->oAction) {
        case 0:
            if (o->oRoom == gMarioCurrentRoom) {
                cur_obj_unhide();
            }
            vec3f_set(&o->oPosX, -2100.0f, 2185.0f, 3800.0f);
            if (gMarioState->pos[1] > 2000.0f && (gMarioState->pos[2] > 3450.0f || o->oTimer > 100)) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (CL_NPC_Dialog(DIALOG_043)) {
                o->oAction = 2;
                save_file_set_newflags(SAVE_TOAD_FLAG_TROPHY_TWO, 1);
            }
            break;
    }
}

void bhv_cushion_friend_init(void) {
    struct Object *obj;
    if (save_file_get_newflags(1) & SAVE_TOAD_FLAG_SPAWN_PLATS) {
        o->oRoom = 2;
        COMIT_OBJECT(MODEL_TROPHY_RECTANGLE, 578, 0, 10898, 0, 90, 0, bhvTrophyRect)
        obj->oBehParams = (32 << 24) | (3 << 16);
        obj->oBehParams2ndByte = 3;
        obj->oRoom = 2;
        COMIT_OBJECT(MODEL_TROPHY_RECTANGLE, 578, 0, 8893, 0, -90, 0, bhvTrophyRect)
        obj->oBehParams = (32 << 24) | (3 << 16);
        obj->oBehParams2ndByte = 3;
        obj->oRoom = 2;
        COMIT_OBJECT(MODEL_TROPHY_OCTOGON, -455, -100, 6514, 0, -22, 0, bhvTrophyPlatSpin)
        obj->oRoom = 2;
        COMIT_OBJECT(MODEL_TROPHY_OCTOGON, 241, -100, 5109, 0, 22, 0, bhvTrophyPlatSpin)
        obj->oRoom = 2;
    }
}


void bhv_cushion_friend_loop(void) {
    switch (o->oFC) {
        case 0:
            cushion_friend_opening();
            break;
        case 1:
            cushion_friend_trophy_one();
            break;
        case 2:
            cushion_friend_morning_room();
            break;
        case 3:
            cushion_friend_trophy_two();
            break;
    }
}





/* window behav

    init - check newflag, skip to open if so
    loop - check lever, do opening sequence (with puzzle jingle) if f4 == 1

*/

void bhv_foreroom_window_init(void) {
    if (o->oBehParams2ndByte) {
        o->os16F4 = o->oFaceAngleYaw + 0x3000;
    } else {
        o->os16F4 = o->oFaceAngleYaw - 0x3000;
    }
    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_FOREROOM_WINDOW) {
        o->oAction = 2;
        o->oFaceAngleYaw = o->os16F4;
    }
}


void bhv_foreroom_window_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            obj = cur_obj_nearest_object_with_behavior(bhvForeroomLever);
            if (obj == NULL || obj->oF4 == 1) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, o->os16F4, 0xC0);
            if (o->oFaceAngleYaw == o->os16F4) {
                o->oAction = 2;
                if (o->oBehParams2ndByte == 0) {
                    play_puzzle_jingle();
                }
            }
            break;
    }
}



void bhv_foreroom_lever_loop(void) {
    if (o->oF4 == 0) {
        o->header.gfx.animInfo.animFrame = 0;
        if (save_file_get_newflags(0) & SAVE_NEW_FLAG_FOREROOM_WINDOW) {
            o->oF4 = 1;
        }
        if (cur_obj_was_attacked_or_ground_pounded() != 0) {
            // play_puzzle_jingle();
            save_file_set_newflags(SAVE_NEW_FLAG_FOREROOM_WINDOW, 0);
            o->oF4 = 1;
        }
    }
}


void bhv_foreroom_object_init(void) {
    o->collisionData = segmented_to_virtual(sForeroomCollision[o->oBehParams2ndByte]);
    // o->oOpacity = 255;
    if (gIsConsole) {
        o->os16F4 = 200;
    } else {
        o->os16F4 = 225;
    }

    if (o->oBehParams2ndByte) {
        o->os16F4 -= 35;
    }

    o->os16F6 = 255 - o->os16F4;

    if (o->oBehParams2ndByte == 5) {
        o->oFlags &= ~(OBJ_FLAG_DISABLE_TO_ROOM_CLEAR | OBJ_FLAG_DISABLE_ON_ROOM_CLEAR);
    }
}


void bhv_foreroom_object_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oFlags & OBJ_FLAG_KICKED_OR_PUNCHED || cur_obj_is_mario_ground_pounding_platform()) {
                o->oAction = 1;
                cur_obj_play_sound_1(SOUND_GENERAL_VANISH_SFX);
            }
            if (o->oDistanceToMario < 800.0f) {
                if (gIsConsole) {
                    o->oOpacity = o->os16F4 + (o->oDistanceToMario / 800) * o->os16F6;
                } else {
                    o->oOpacity = o->os16F4 + (o->oDistanceToMario / 800) * o->os16F6;
                }
            } else {
                o->oOpacity = 255;
            }
            break;
        case 1:
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 0x10);
            if (o->oOpacity < 0x11) {
                o->activeFlags = 0;
                if (gMarioObject->platform == o) {
                    set_mario_action(gMarioState, ACT_FREEFALL, 0);
                }
            }
            break;
    }
}


f32 sTrophyElevatorPos[3] = {0.0f, 3000.0f, -2000.0f};


void bhv_trophy_elevator_loop(void) {
    f32 target = sTrophyElevatorPos[o->os16F4] + o->oHomeY;
    if (target != o->oPosY) {
        o->oPosY = approach_f32_symmetric(o->oPosY, target, 15.0f);
        cur_obj_play_sound_1(SOUND_ENV_ELEVATOR1);
        return;
    }

    if (o->os16F6 == 0 && save_file_get_newflags(1) & SAVE_TOAD_FLAG_TROPHY_TWO) {
        o->os16F6 = 1;
    }
    if (o->os16F8) {
        if (gMarioState->floor != NULL && gMarioState->floor->object != o) {
            o->os16F8 = 0;
        } else {
            return;
        }
    }

    switch (o->os16F4) {
        case 0:
            if (gMarioObject->platform == o || gMarioState->pos[1] - o->oHomeY > 1500.0f) {
                o->os16F4 = 1;
                o->os16F8 = 1;
            }

            if (o->os16F6 && gMarioState->pos[1] - o->oHomeY < -1000.0f) {
                o->os16F4 = 2;
                o->os16F8 = 1;
            }
            break;
        case 1:
            if (gMarioObject->platform == o) {
                if (o->os16F6) {
                    o->os16F4 = 2;
                } else {
                    o->os16F4 = 0;
                }

                o->os16F8 = 1;
            }
            if (gMarioState->pos[1] - o->oHomeY < 1500.0f) {
                if (o->os16F6 && gMarioState->pos[1] - o->oHomeY < -1000.0f) {
                    o->os16F4 = 2;
                } else {
                    o->os16F4 = 0;
                }
                o->os16F8 = 1;
            }
            break;
        case 2:
            if (gMarioObject->platform == o || gMarioState->pos[1] - o->oHomeY > 1500.0f) {
                o->os16F4 = 1;
                o->os16F8 = 1;
            }
            if (gMarioState->pos[1] - o->oHomeY < 1500.0f && gMarioState->pos[1] - o->oHomeY > -1000.0f) {
                o->os16F4 = 0;
                o->os16F8 = 1; 
            }
            break;
    }
}

void bhv_bully_trophy_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            if (save_file_get_boos() & (1 << 0x12)) {
                o->oAction = 1;
                cur_obj_unhide();
                obj = spawn_object(o, MODEL_TOKEN, bhvToken);
                obj->oBehParams2ndByte = 2;
                obj->oBehParams = 0x00022900;
                obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
                vec3f_set(&obj->oPosX, -6559.0f, 100.0f, 3950.0f);
            }
            break;
        case 1:
            load_object_collision_model();
            break;
    }
}




void bhv_trophy_plat_spin_loop(void) {
    if ((o->oBehParams >> 8) & 0xFF && o->oAction == 0) {
        o->oHomeY = approach_f32_symmetric(o->oHomeY, -100.0f, 50.0f);
        o->oPosY = o->oHomeY;
        if (o->oHomeY == -100.0f) {
            o->oAction = 1;
        }
    } else {
        if (gMarioObject->platform == o) {
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY - 20.0f, 2.0f);
        } else {
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 2.0f);
        }
    }
}

void bhv_trophy_rect_loop(void) {
    o->os16F4 += (o->oBehParams >> 24) << 4;
    o->oPosX = o->oHomeX + sins(o->oFaceAngleYaw + 0x4000) * (sins(o->os16F4) * (o->oBehParams2ndByte * 100.0f));
    o->oPosZ = o->oHomeZ + coss(o->oFaceAngleYaw + 0x4000) *(sins(o->os16F4) * (o->oBehParams2ndByte * 100.0f));
    if ((o->oBehParams >> 8) & 0xFF) {
        o->oHomeX = approach_f32_symmetric(o->oHomeX, 578.0f, 30.0f);
    }
}


// void bhv_trophy_rect_spin_loop(void) {
//     switch (o->oAction) {
//         case 0:
//             if (o->oTimer > 30) {
//                 o->os16F4 = o->oFaceAnglePitch + 0x8000;
//                 o->oAction = 1;
//             }
//             break;
//         case 1:
//             o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, o->os16F4, 0x200);
//             if (o->oFaceAnglePitch == o->os16F4) {
//                 o->oAction = 0;
//             }
//             break;
//     }
// }

void bhv_trophy_plat_rise_loop(void) {
    o->os16F4 += (o->oBehParams >> 24) << 4;
    o->oPosY = o->oHomeY + (sins(o->os16F4) * (o->oBehParams2ndByte * 100.0f));
}