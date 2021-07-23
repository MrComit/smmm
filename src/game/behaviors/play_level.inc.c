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