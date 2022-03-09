static void const *sForeroomCollision[] = {
    foreroom_chair_collision,
    foreroom_books_collision,
    foreroom_plant_collision,
    foreroom_table_collision,
    foreroom_vase_collision,
};

void bhv_foreroom_object_init(void) {
    o->collisionData = segmented_to_virtual(sForeroomCollision[o->oBehParams2ndByte]);
}


void bhv_foreroom_object_loop(void) {
    if (o->oFlags & OBJ_FLAG_KICKED_OR_PUNCHED || cur_obj_is_mario_ground_pounding_platform()) {
        o->activeFlags = 0;
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