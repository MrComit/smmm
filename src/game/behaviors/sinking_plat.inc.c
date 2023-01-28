

void bhv_lemon_loop(void) {
    f32 approach_pos;
    struct Object *obj = cur_obj_nearest_object_with_behavior(bhvL2Lava);
    if (obj == NULL) {
        o->activeFlags = 0;
        return;
    }

    if (gMarioObject->platform == o) {
        approach_pos = o->oHomeY - o->oFloatF8;
    } else {
        approach_pos = o->oHomeY;
    }
    o->oPosY = approach_f32(o->oPosY, approach_pos, o->oFloatF4 * 4, o->oFloatF4);
    o->oPosY += obj->oVelY;
    o->oHomeY += obj->oVelY;
}

extern s16 gComitCutsceneTimer;
extern Vec3f gComitCutscenePosVec;
extern Vec3f gComitCutsceneFocVec;

void bhv_bottled_lava_init(void) {
    struct Object *obj;
    o->header.gfx.scale[1] = (f32)o->oBehParams2ndByte;
    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_BAR_CUTSCENE) {
        o->activeFlags = 0;
        return;
    }

    if ((o->oBehParams >> 24) == 0) {
        obj = spawn_object(o, MODEL_BOTTLED_LAVA, bhvBottledLava);
        obj->oBehParams = 0x01010000;
        obj->oBehParams2ndByte = 1;
        obj->oRoom = o->oRoom;
        obj->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
        obj->oObjF4 = o;
    } else {
        o->oFaceAnglePitch = 0x8000;
        o->header.gfx.scale[0] = o->header.gfx.scale[2] = 0.3f;
    }
}

void bhv_bottled_lava_loop(void) {
    if ((o->oBehParams >> 24) == 0) {
        if (o->oTimer > 15) {
            o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 0.0f, 1.0f);
            if (o->header.gfx.scale[1] < 3.0f) {
                o->header.gfx.scale[0] = approach_f32_symmetric(o->header.gfx.scale[0], 0.0f, 0.2f);
                o->header.gfx.scale[2] = o->header.gfx.scale[0];
            }
            if (o->header.gfx.scale[1] == 0.0f && o->header.gfx.scale[0] == 0.0f) {
                o->activeFlags = 0;
            }
        }
    } else {
        switch (o->oAction) {
            case 0:
                if (o->oTimer > 15) {
                    o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 170.0f, 3.0f);
                    if (o->header.gfx.scale[1] == 170.0f && o->oObjF4->activeFlags == 0) {
                        o->oAction = 1;
                    }
                }
                break;
            case 1:
                o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 0.0f, 3.0f);
                o->oGraphYOffset = approach_f32_symmetric(o->oGraphYOffset, -1700.0f, 30.0f);
                if (o->header.gfx.scale[1] == 0.0f) {
                    o->activeFlags = 0;
                }
                break;
        }
    }
}


void bhv_l2_lava_init(void) {
    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_BAR_CUTSCENE) {
        o->oAction = 2;
    } else {
        o->oPosY -= 350.0f;
    }
}

void bhv_l2_lava_loop(void) {
    s32 arg = 0;
    f32 oldPos = o->oPosY;
    switch (o->oAction) {
        case 0:
            vec3f_set(gComitCutscenePosVec, -800.0f, 2607.0f, 1301.0f);
            vec3f_set(gComitCutsceneFocVec, 824.0f, 618.0f, -3364.0f);
            o->oAction = 1;
            break;
        case 1:
            set_mario_npc_dialog(1);
            gCamera->comitCutscene = 0xFF;
            if (o->oTimer > 70) {
                o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 3.1f);
                if (o->oPosY == o->oHomeY) {
                    o->oAction = 2;
                    save_file_set_newflags(SAVE_NEW_FLAG_BAR_CUTSCENE, 0);
                    gComitCutsceneTimer = 10;
                    set_mario_npc_dialog(0);
                }
            }
            break;
        case 2:
            o->oF4 += 0x140;
            o->oPosY = o->oHomeY + (sins(o->oF4) * 75.0f);
            o->oVelY = o->oPosY - oldPos;
            if (o->oTimer > 10 && gMarioState->pos[1] <= o->oPosY) {
                if (gMarioState->action == ACT_LAVA_BOOST) {
                    arg = 1;
                }
                CL_Lava_Boost(arg);
                gMarioState->actionArg = 1;
                o->oTimer = 0;
            }
            break;
    }
    if (((s32)(random_float() * 16.0f)) == 8) {
        play_sound(SOUND_GENERAL_QUIET_BUBBLE2, gGlobalSoundSource);
    }
}




void bhv_sinking_plat_init(void) {
    o->oFloatF4 = (f32)(o->oBehParams >> 24);
    o->oFloatF8 = (f32)((o->oBehParams >> 16) & 0xFF) * 10.0f;

}

void bhv_sinking_plat_loop(void) {
    f32 approach_pos;
    if (gMarioObject->platform == o) {
        approach_pos = o->oHomeY - o->oFloatF8;
    } else {
        approach_pos = o->oHomeY;
    }
    o->oPosY = approach_f32(o->oPosY, approach_pos, o->oFloatF4, o->oFloatF4);
}