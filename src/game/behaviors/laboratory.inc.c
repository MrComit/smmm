extern s32 gJoystickSwitch;

void bhv_antenna_ball_init(void) {
    o->os16F4 = 0x30;
    o->os16F6 = 0x30;
    o->os16F8 = 0x48;
}


void bhv_antenna_ball_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioState->pos[0] > 11000.0f && gMarioState->pos[0] < 17500.0f) {
                o->oAction = 1;
                if (o->oBehParams2ndByte) {
                    gJoystickSwitch = CL_RandomMinMaxU16(0x1800, 0xE800);
                    // gMarioState->particleFlags |= PARTICLE_DIZZY;
                    set_mario_action(gMarioState, ACT_CUTSCENE_DIZZY, 0);
                    // set_mario_animation(gMarioState, MARIO_ANIM_DYING_FALL_OVER);
                }
            }
            o->os16F4 = approach_s16_symmetric(o->os16F4, 0x30, 0x6);
            o->os16F6 = approach_s16_symmetric(o->os16F6, 0x30, 0x6);
            o->os16F8 = approach_s16_symmetric(o->os16F8, 0x48, 0x7);
            o->oFloatFC = approach_f32_symmetric(o->oFloatFC, 1.0f, 0.025f);
            break;
        case 1:
            if (gMarioState->pos[0] < 10500.0f || gMarioState->pos[0] > 18000.0f) {
                o->oAction = 0;
                if (o->oBehParams2ndByte) {
                    gJoystickSwitch = 0;
                    // gMarioState->particleFlags &= ~PARTICLE_DIZZY;
                }
            }
            // set_mario_animation(gMarioState, MARIO_ANIM_DYING_FALL_OVER);
            o->os16F4 = approach_s16_symmetric(o->os16F4, 0x0, 0x6);
            o->os16F6 = approach_s16_symmetric(o->os16F6, 0xB0, 0x6);
            o->os16F8 = approach_s16_symmetric(o->os16F8, 0xFF, 0x7);
            o->oFloatFC = approach_f32_symmetric(o->oFloatFC, 1.5f, 0.025f);
            break;
    }
    cur_obj_scale(o->oFloatFC);
}