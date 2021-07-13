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