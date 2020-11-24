// breakable_box.c.inc

void bhv_breakable_box_loop(void) {
    cur_obj_update_floor_and_walls();
    cur_obj_move_standard(-78);
    if (o->oFloor != NULL && o->oFloor->object != NULL && obj_has_behavior(o->oFloor->object, bhvBreakableBoxChild)) {
        o->oAnimState = 1;
    } else {
        o->oAnimState = 0;
    }
    if (o->oTimer == 0)
        breakable_box_init();
}


void bhv_breakable_box_child_loop(void) {
    vec3f_copy(&o->oPosX, &o->parentObj->oPosX);
    obj_set_hitbox(o, &sBreakableBoxHitbox);
    if (cur_obj_was_attacked_or_ground_pounded() != 0) {
        obj_explode_and_spawn_coins(46.0f, 1);
        create_sound_spawner(SOUND_GENERAL_BREAK_BOX);
        o->parentObj->activeFlags = 0;
    }
}