void bhv_mirror_switch_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o) {
                o->oAction = 1;
            }
            break;
        case 1:
            cur_obj_scale_over_time(2, 3, 1.5f, 0.2f);
            if (o->oTimer == 3) {
                cur_obj_play_sound_2(SOUND_GENERAL2_PURPLE_SWITCH);
                o->oAction = 2;
                cur_obj_shake_screen(SHAKE_POS_SMALL);
                queue_rumble_data(5, 80);
            }
            break;
        case 2:
            if (gPlayer1Controller->buttonPressed & L_JPAD) {
                o->os16F4 += 0x2000;
            } else if (gPlayer1Controller->buttonPressed & R_JPAD) {
                o->os16F4 -= 0x2000;
            }

            if (gPlayer1Controller->buttonPressed & U_JPAD) {
                o->os16F6 = 0;
            } else if (gPlayer1Controller->buttonPressed & D_JPAD) {
                o->os16F6 = 1;
            }

            if (gMarioObject->platform != o) {
                o->oAction = 3;
            }
            break;
        case 3:
            cur_obj_scale_over_time(2, 3, 0.2f, 1.5f);
            if (o->oTimer == 3) {
                o->oAction = 0;
            }
            break;
    }
}



void bhv_mirror_init(void) {
    o->os16F6 = o->oFaceAngleYaw;
    o->oFloatF8 = 1.0f;
}


void bhv_mirror_loop(void) {
    struct Object *obj = CL_obj_nearest_object_behavior_params(bhvMirrorSwitch, o->oBehParams2ndByte << 16);
    if (obj == NULL)
        return;
    switch (o->oAction) {
        case 0:
            if (obj->os16F4 != o->os16F4 - o->os16F6) {
                o->oAction = 1;
                o->os16F4 = o->os16F6 + obj->os16F4;
            }

            if (obj->os16F6 == 1) {
                o->oAction = 2;
            }
            load_object_collision_model();
            break;
        case 1:
            o->oFaceAngleYaw = approach_s16_symmetric((s16)o->oFaceAngleYaw, o->os16F4, 0x200);
            if (o->oFaceAngleYaw == o->os16F4) {
                o->oAction = 0;
            }
            load_object_collision_model();
            break;
        case 2:
            if (o->oFloatF8 > 0.4f) {
                o->oFloatF8 -= 0.05f;
                cur_obj_scale(o->oFloatF8);
            }
            if (obj->os16F6 == 0) {
                o->oAction = 3;
            }
            break;
        case 3:
            o->oFloatF8 += 0.05f;
            if (o->oFloatF8 >= 1.0f) {
                o->oFloatF8 = 1.0f;
                o->oAction = 0;
            }
            cur_obj_scale(o->oFloatF8);
            break;
    }
}



void bhv_mirror_light_init(void) {
    o->oFaceAnglePitch = 0x4000;
}

void bhv_mirror_light_loop(void) {
    s32 i;
    Vec3f pos;
    struct Surface *wall;
    struct Object *obj;
    //o->oFaceAngleYaw += 0x400;
    switch (o->oAction) {
        case 0:
            if (gMarioState->input & INPUT_B_PRESSED) {
                o->oAction = 2;
            }
            break;
        case 2:
            for (i = 0; i < 4; i++) {
                o->header.gfx.scale[1] += 0.5f;
                pos[1] = o->oPosY;
                pos[0] = o->oPosX + ((o->header.gfx.scale[1] * 100.0f) * sins(o->oFaceAngleYaw));
                pos[2] = o->oPosZ + ((o->header.gfx.scale[1] * 100.0f) * coss(o->oFaceAngleYaw));
                o->oSurfF4 = resolve_and_return_wall_collisions(pos, 0, 40.0f);
                if (o->oSurfF4 != NULL) {
                    o->oAction = 1;
                    if (o->oSurfF4->type == SURFACE_MIRROR) {
                        obj = spawn_object(o, MODEL_MIRROR_LIGHT, bhvMirrorLight);
                        obj->oFaceAngleYaw = atan2s(o->oSurfF4->normal.z, o->oSurfF4->normal.x);
                        obj->oBehParams2ndByte = 1;
                        obj->oAction = 2;
                        vec3f_copy(&obj->oPosX, pos);
                    }
                    break;
                }
            }
            break;
        case 1:
            break;
    }
}