s32 approach_f32_ptr(f32 *px, f32 target, f32 delta);
s32 sSunflowers = 0;

void bhv_poochy_boss_init(void) {
    cur_obj_disable();
}

void bhv_poochy_boss_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oTimer > 90) {
                o->oAction = 1;
                cur_obj_enable();
            }
            break;
        case 1:
            cur_obj_move_standard(-78);
            if (o->oMoveFlags & OBJ_MOVE_ON_GROUND) {
                o->oAction = 2;
                o->oObjF4 = spawn_object(o, MODEL_NONE, bhvGardenHoles);
                o->oObjF4->oPosX = o->oObjF4->oPosZ = 0;
                o->oObjF4->oPosY = -488.0f;
                o->oObjF4->oFaceAngleYaw = o->oObjF4->oMoveAngleYaw = 0;
            }
            break;
        case 2:
            cur_obj_move_standard(-78);
            cur_obj_update_floor_and_walls();
            if (o->oSubAction == 0) {
                o->oForwardVel = approach_f32(o->oForwardVel, 40.0f, 0.5f, 0.5f);
                o->oMoveAngleYaw += 0x100;
                if (o->oTimer > 180) {
                    o->oSubAction = 1;
                }
            } else {
                o->oForwardVel = approach_f32(o->oForwardVel, 30.0f, 1.0f, 1.0f);
                o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x180);
                if (o->oDistanceToMario < 1500.0f) {
                    o->oAction = 3;
                    o->oVelY = 77.0f;
                    o->oForwardVel = 40.0f;
                }
            }
            break;
        case 3:
            cur_obj_move_standard(-78);
            cur_obj_update_floor_and_walls();
            o->oForwardVel = approach_f32(o->oForwardVel, 8.0f, 0.5f, 0.5f);
            if (o->oMoveFlags & OBJ_MOVE_ON_GROUND) {
                o->oAction = 4;
            }
            break;
        case 4:
            break;
    }
}


void bhv_bounce_box_loop(void) {
    struct MarioState *m = gMarioState;
    switch (o->oAction) {
        case 0:
            if (gMarioObject->platform == o)
                o->oAction = 1;
            break;
        case 1:
            if (approach_f32_ptr(&o->header.gfx.scale[1], 0.5f, 0.25f)) {
                set_mario_action(m, ACT_CUTSCENE_JUMP, 1);
                m->vel[1] = 200.0f;
                m->faceAngle[1] = (m->angleVel[1] = o->oFaceAngleYaw + 0xC000);
                mario_set_forward_vel(m, 15.0f);
                o->oAction = 2;
            }
            break;
        case 2:
            if (approach_f32_ptr(&o->header.gfx.scale[1], 1.25f, 0.2f)) {
                o->oAction = 3;
            }

            if (gMarioObject->platform == o) {
                o->header.gfx.scale[1] = 1.0f;
                o->oAction = 1;
            }
            break;
        case 3:
            if (approach_f32_ptr(&o->header.gfx.scale[1], 1.0f, 0.2f)) {
                o->header.gfx.scale[1] = 1.0f;
                o->oAction = 0;
            }

            if (gMarioObject->platform == o) {
                o->header.gfx.scale[1] = 1.0f;
                o->oAction = 1;
            }
            break;
    }
}




void bhv_dirt_mound_init(void) {
    o->oRoom = 1;
}

void bhv_dirt_mound_loop(void) {
    switch (o->oAction) {
        case 0:
            if (cur_obj_is_mario_ground_pounding_platform())
                o->oAction = 1;
            break;
        case 1:
            o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 0, 0.2f);
            if (o->header.gfx.scale[1] == 0) {
                o->activeFlags = 0;
                spawn_mist_particles();
            }
            break;
    }
}



void bhv_sunflower_init(void) {
    sSunflowers = 0;
    o->oOpacity = 80;
    //o->oFloatF4 = 0.6f;
    o->header.gfx.scale[1] = 0.6f;
    //cur_obj_scale(o->oFloatF4);
}

void bhv_sunflower_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            o->header.gfx.animInfo.animFrame = 0;
            if (o->oDistanceToMario < 100.0f) {
                o->oAction = 1;
                play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gGlobalSoundSource);
                sSunflowers++;
            }
            break;
        case 1:
            obj = spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
            obj->oPosY += 200.0f;
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 12);
            o->header.gfx.scale[1] = approach_f32(o->header.gfx.scale[1], 0.9f, 0.02f, 0.02f);
            //cur_obj_scale(o->oFloatF4);
            if (o->header.gfx.scale[1] == 0.9f && o->oOpacity == 255) {
                o->oAction = 2;
            }
            break;
        case 2:
            break;
    }
}