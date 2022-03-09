static void const *sForeroomCollision[] = {
    foreroom_chair_collision,
    foreroom_books_collision,
    foreroom_plant_collision,
    foreroom_table_collision,
    foreroom_vase_collision,
};

void bhv_foreroom_object_init(void) {
    o->collisionData = segmented_to_virtual(sForeroomCollision[o->oBehParams2ndByte]);
    // o->oOpacity = 255;
}


void bhv_foreroom_object_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oFlags & OBJ_FLAG_KICKED_OR_PUNCHED || cur_obj_is_mario_ground_pounding_platform()) {
                o->oAction = 1;
            }
            if (o->oDistanceToMario < 800.0f) {
                if (gIsConsole) {
                    o->oOpacity = 200 + (o->oDistanceToMario / 800) * 55;
                } else {
                    o->oOpacity = 225 + (o->oDistanceToMario / 800) * 30;
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