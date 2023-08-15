// celebration_star.inc.c

void bhv_celebration_star_init(void) {
    o->oHomeX = gMarioObject->header.gfx.pos[0];
    o->oPosY = gMarioObject->header.gfx.pos[1] + 30.0f;
    o->oHomeZ = gMarioObject->header.gfx.pos[2];
    o->oMoveAngleYaw = gMarioObject->header.gfx.angle[1] + 0x8000;
    o->oCelebStarDiameterOfRotation = 100;

    //o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_STAR_PIECE];
    //cur_obj_scale(0.4f);
    cur_obj_scale(0.7f);
    o->oFaceAnglePitch = 0;
    o->oFaceAngleRoll = 0;
}

void celeb_star_act_spin_around_mario(void) {
    o->oPosX = o->oHomeX + sins(o->oMoveAngleYaw) * (f32)(o->oCelebStarDiameterOfRotation / 2);
    o->oPosZ = o->oHomeZ + coss(o->oMoveAngleYaw) * (f32)(o->oCelebStarDiameterOfRotation / 2);
    o->oPosY += 5.0f;
    o->oFaceAngleYaw += 0x1000;
    //if (!cur_obj_has_model(MODEL_STAR_CURRENCY)) {
        o->oFaceAnglePitch += 0x400;
        o->oMoveAngleYaw += 0x2000;
    //}

    if (o->oTimer == 40) {
        o->oAction = CELEB_STAR_ACT_FACE_CAMERA;
    }

    if (o->oTimer < 35) {
        spawn_object(o, MODEL_SPARKLES, bhvCelebrationStarSparkle);
        o->oCelebStarDiameterOfRotation++;
    } else {
        o->oCelebStarDiameterOfRotation -= 20;
    }
}

void celeb_star_act_face_camera(void) {
    if (o->oTimer < 10) {
#if BUGFIX_STAR_BOWSER_KEY
        if (o->oCelebStarUnkF4 == 0) {
            cur_obj_scale((f32) o->oTimer / 10.0);
        } else {
            cur_obj_scale((f32) o->oTimer / 30.0);
        }
#else
        cur_obj_scale((f32) o->oTimer / 10.0);
#endif
        o->oFaceAngleYaw += 0x1000;
        if (cur_obj_has_model(MODEL_STAR_CURRENCY) || cur_obj_has_model(MODEL_STAR))
            o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, 0, 0x500);
        else
            o->oFaceAnglePitch += 0x400;
    } else {
        //o->oFaceAngleYaw = gMarioObject->header.gfx.angle[1];
        o->oFaceAngleYaw += 0x400;
        if (cur_obj_has_model(MODEL_STAR_CURRENCY) || cur_obj_has_model(MODEL_STAR))
            o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, 0, 0x500);
        else
            o->oFaceAnglePitch += 0x400;
    }

    if (o->oTimer == 40 && cur_obj_has_model(MODEL_STAR)) {
        sDelayedWarpArg = 0;
        sDelayedWarpOp = 0x10;
        sSourceWarpNodeId = 0xB5;
        // val04 = !music_changed_through_warp(sSourceWarpNodeId);
        sDelayedWarpTimer = 20;
        play_transition(WARP_TRANSITION_FADE_INTO_CIRCLE, 0x14, 0x00, 0x00, 0x00);
    }

    if (o->oTimer == 59) {
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }
}

void bhv_celebration_star_loop(void) {
    switch (o->oAction) {
        case CELEB_STAR_ACT_SPIN_AROUND_MARIO:
            celeb_star_act_spin_around_mario();
            break;

        case CELEB_STAR_ACT_FACE_CAMERA:
            celeb_star_act_face_camera();
            break;
    }
}

void bhv_celebration_star_sparkle_loop(void) {
    o->oPosY -= 15.0f;

    if (o->oTimer == 12) {
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }
}

void bhv_star_key_collection_puff_spawner_loop(void) {
    spawn_mist_particles_variable(0, 10, 30.0f);
    o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
}




void celeb_key_act_spin_around_mario(void) {
    o->oPosX = o->oHomeX + sins(o->oMoveAngleYaw) * (f32)(o->oCelebStarDiameterOfRotation / 2);
    o->oPosZ = o->oHomeZ + coss(o->oMoveAngleYaw) * (f32)(o->oCelebStarDiameterOfRotation / 2);
    o->oPosY += 3.0f;
    o->oFaceAngleYaw += 0x1000;
    o->oMoveAngleYaw += 0x2000;

    if (o->oTimer == 40)
        o->oAction = 1;
    if (o->oTimer < 35) {
        spawn_object(o, MODEL_SPARKLES, bhvCelebrationStarSparkle);
        o->oCelebStarDiameterOfRotation++;
    } else
        o->oCelebStarDiameterOfRotation -= 20;
}

void celeb_key_act_face_camera(void) {
    if (o->oTimer < 10) {
        cur_obj_scale((f32) (o->oTimer) / 33.3);
        o->oFaceAngleYaw += 0x1000;
    } else {
        o->oFaceAngleYaw = gMarioObject->header.gfx.angle[1];
    }

    if (o->oTimer == 59)
        o->activeFlags = 0;
}




void bhv_celebration_key_loop(void) {
    switch (o->oAction) {
        case 0:
            cur_obj_scale(0.3f);
            celeb_key_act_spin_around_mario();
            break;

        case 1:
            celeb_key_act_face_camera();
            break;
    }
}