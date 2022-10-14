extern s16 gComitCutsceneTimer;

void bhv_security_cam_init(void) {
    o->oRoom = 4;
}


void bhv_security_cam_loop(void) {
    Vec3f point;
    f32 dist;
    s16 pitch, yaw;
    switch (o->oBehParams2ndByte) {
        case 0:
            o->os16F4 = -1335;
            o->os16F6 += 0x100;
            o->os16F8 = -1478;
            o->os16FA = (400 + 1100) + (sins(o->os16F6) * 1100);
            o->os16FC = 300;
            break;
        case 1:
            o->os16F4 = -835;
            o->os16F6 += 0x100;
            o->os16F8 = -400;
            o->os16FA = (800 + 1300) + (sins(o->os16F6) * 1300);
            o->os16FC = 500;
            break;
    }

    point[0] = ((f32)o->os16FA * sins(o->oFaceAngleYaw)) + ((f32)o->os16F8 * coss(o->oFaceAngleYaw)) + o->oPosX - 229;
    point[1] = gMarioState->pos[1];//o->os16F4 + o->oPosY;
    point[2] = ((f32)o->os16F8 * sins(o->oFaceAngleYaw)) + ((f32)o->os16FA * coss(o->oFaceAngleYaw)) + o->oPosZ - 229;
    vec3f_get_dist_and_angle(point, gMarioState->pos, &dist, &pitch, &yaw);
    if ((s16)dist < o->os16FC && absi((s16)gMarioState->pos[1] - (o->os16F4 + o->oPosY)) < 500) {
        play_puzzle_jingle();
    }
}


void bhv_champagne_init(void) {
    o->oObjF4 = cur_obj_nearest_object_with_behavior(bhvCellarBlockade);
    if (o->oObjF4 == NULL) {
        o->activeFlags = 0;
    }
}

void bhv_champagne_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oFlags & OBJ_FLAG_KICKED_OR_PUNCHED && gMarioState->faceAngle[1] < 0x6000 && gMarioState->faceAngle[1] > 0x2000) {
                o->oAction = 1;
                // o->oObjF4->oFC = 1;
                o->oFloatF8 = o->oObjF4->oPosX - 300.0f;
                o->oFloat104 = o->oObjF4->oPosY + 200.0f;
                vec3f_copy(gComitCutsceneFocVec, &o->oObjF4->oPosX);
                vec3f_set(gComitCutscenePosVec, -2000.0f, 3400.0f, 9800.0f);
                o->oFloatFC = 65.0f;
            }
            break;
        case 1:
            set_mario_npc_dialog(1);
            cur_obj_update_floor_and_walls();
            gCamera->comitCutscene = 0xFF;
            o->oFloatFC = approach_f32_asymptotic(o->oFloatFC, 5.0f, 0.2f);
            o->oPosX = approach_f32_symmetric(o->oPosX, o->oFloatF8, o->oFloatFC);
            if (o->oFloorHeight != o->oHomeY) {
                o->oFloat100 = approach_f32_symmetric(o->oFloat100, 100.0f, 2.4f);
                o->oPosY = approach_f32_symmetric(o->oPosY, o->oFloat104, o->oFloat100);
            }
            o->oFaceAngleRoll -= o->oFloat100 * 50;
            if (o->oPosX == o->oFloatF8 && o->oPosY == o->oFloat104) {
                o->oObjF4->oFC = 1;
                CL_explode_object(o, 1);
                play_puzzle_jingle();
            }
            break;
    }
}

void bhv_cellar_blockade_init(void) {
    o->oObj100 = cur_obj_nearest_object_with_behavior(bhvFlame);
    if (o->oObj100 == NULL) {
        o->activeFlags = 0;
    } else {
        o->oObj100->os16F4 = 0xFF;
    }
}

void bhv_cellar_blockade_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oFC) {
                o->oAction = 1;
                o->oObjF4 = spawn_object(o, MODEL_ENV_FLAME, bhvFlame);
                obj_scale(o->oObjF4, 0.0f);
                o->oObjF4->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
                // o->oFloatF8 = 7.0f;
                o->oObjF4->oIntangibleTimer = -1;
                o->oObjF4->os16F4 = 0xFF;
            }
            break;
        case 1:
            o->oObjF4->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
            gCamera->comitCutscene = 0xFF;
            o->oObjF4->oIntangibleTimer = -1;
            o->oObj100->os16F6 = o->oObjF4->os16F6 = approach_s16_symmetric(o->oObjF4->os16F6, 0xFF, 0xA);
            if (o->oObjF4->os16F6 >= 0x7F) {
                o->oObj100->os16F8 = o->oObjF4->os16F8 = approach_s16_symmetric(o->oObjF4->os16F8, 0xE0, 0x10);
            }
            o->oFloatF8 = approach_f32_symmetric(o->oFloatF8, 20.0f, 0.5f);
            obj_scale(o->oObjF4, o->oFloatF8);
            if (o->oFloatF8 == 20.0f) {
                o->oAction = 2;
                gComitCutsceneTimer = 30;
            }
            break;
        case 2:
            CL_explode_object(o, 1);
            o->oObjF4->activeFlags = 0;
            set_mario_npc_dialog(0);
            break;
    }
}