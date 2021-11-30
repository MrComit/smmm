
/**
 * Behaviors for bhvPoleGrabbing and bhvGiantPole.
 *
 * bhvPoleGrabbing is a generic behavior used almost anywhere the player can
 * grab onto and climb up another object.
 *
 * bhvGiantPole controls the large pole in Whomp's Fortress and differs from
 * other poles because it spawns a yellow ball that rests at its top.
 */



void bhv_hidden_horizontal_pole_init(void) {
    if (save_file_get_newflags(0) & SAVE_NEW_FLAG_CITY_POLE_OPEN) {
        spawn_object(o, MODEL_HORIZONTAL_POLE, bhvHorizontalPole);
        o->activeFlags = 0;
    } else {
        o->oPosY -= 400.0f;
        cur_obj_hide();
    }

}

void bhv_hidden_horizontal_pole_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            obj = cur_obj_nearest_object_with_behavior(bhvGenericSwitch);
            if (obj == NULL || obj->oF4) {
                set_mario_npc_dialog(1);
                gCamera->comitCutscene = 16;
                o->oAction = 1;
            }
            break;
        case 1:
            if (o->oTimer > 15) {
                cur_obj_unhide();
                o->oAction = 2;
            }
            break;
        case 2:
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 10.0f);
            if (o->oPosY == o->oHomeY) {
                o->oAction = 3;
                set_camera_shake_from_point(1, gCamera->pos[0], gCamera->pos[1], gCamera->pos[2]);
                play_puzzle_jingle();
            }
            break;
        case 3:
            if (o->oTimer > 30) {
                set_mario_npc_dialog(0);
                gCamera->comitCutscene = 0;
                spawn_object(o, MODEL_HORIZONTAL_POLE, bhvHorizontalPole);
                save_file_set_newflags(SAVE_NEW_FLAG_CITY_POLE_OPEN, 0);
                o->activeFlags = 0;
            }
        break;
    }
}



void bhv_horizontal_pole_loop(void) {
    if (o->oPosY - 10.0f < gMarioObject->oPosY
        && gMarioObject->oPosY < o->oPosY + o->hitboxHeight + 30.0f)
        if (o->oTimer > 10)
            if (!(gMarioStates[0].action & MARIO_PUNCHING))
                cur_obj_push_mario_away(70.0f);
}


void bhv_horizontal_pole_init(void) {
    s32 hitboxLength = o->oBehParams2ndByte * 5;
    o->oHomeY = (o->oFloatF8 = o->oPosY);
    o->oHomeX = o->oPosX + (sins(o->oFaceAngleYaw + 0x4000) * hitboxLength);
    o->oHomeZ = o->oPosZ + (coss(o->oFaceAngleYaw + 0x4000) * hitboxLength);
    o->oFloatFC = o->oPosX + (sins(o->oFaceAngleYaw - 0x4000) * hitboxLength);
    o->oFloatFC = o->oPosZ + (coss(o->oFaceAngleYaw - 0x4000) * hitboxLength);
}





/**
 * Initialize the hitbox height field for bhvPoleGrabbing.
 */
void bhv_pole_init(void) {
    /**
     * This is equivalent to using `o->oBehParams2ndByte` according to
     * `spawn_objects_from_info`.
     */
     //made it use bparam1 and 2 instead of just 2
    s32 tenthHitboxHeight = (o->oBehParams >> 16);
    o->hitboxHeight = tenthHitboxHeight * 10;
}

/**
 * Main loop for bhvGiantPole. It is equivalent to bhv_pole_base_loop() except
 * for the fact that it spawns a yellow sphere at the top of the pole on the
 * first frame.
 */
void bhv_giant_pole_loop(void) {
    if (o->oTimer == 0) {
        struct Object *topBall = spawn_object(o, MODEL_YELLOW_SPHERE, bhvYellowBall);
        topBall->oPosY += o->hitboxHeight + 50.0f;
    }
    bhv_pole_base_loop();
}
