static void const *sForeroomCollision[] = {
    foreroom_chair_collision,
    foreroom_books_collision,
    foreroom_plant_collision,
    foreroom_table_collision,
    foreroom_vase_collision,
    foreroom_wall_collision,
};

/* window behav

    init - check newflag, skip to open if so
    loop - check lever, do opening sequence (with puzzle jingle) if f4 == 1

*/



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
}


void bhv_foreroom_object_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oFlags & OBJ_FLAG_KICKED_OR_PUNCHED || cur_obj_is_mario_ground_pounding_platform()) {
                o->oAction = 1;
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


void bhv_trophy_plat_spin_loop(void) {
    if (gMarioObject->platform == o) {
        o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY - 20.0f, 2.0f);
    } else {
        o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 2.0f);
    }
}

void bhv_trophy_rect_loop(void) {
    o->os16F4 += (o->oBehParams >> 24) << 4;
    o->oPosX = o->oHomeX + sins(o->oFaceAngleYaw + 0x4000) * (sins(o->os16F4) * (o->oBehParams2ndByte * 100.0f));
    o->oPosZ = o->oHomeZ + coss(o->oFaceAngleYaw + 0x4000) *(sins(o->os16F4) * (o->oBehParams2ndByte * 100.0f));
}



void bhv_trophy_plat_rise_loop(void) {
    o->os16F4 += (o->oBehParams >> 24) << 4;
    o->oPosY = o->oHomeY + (sins(o->os16F4) * (o->oBehParams2ndByte * 100.0f));
}