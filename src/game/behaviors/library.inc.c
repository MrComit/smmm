void koopa_boss_move(void) {
    switch ((o->oF8 & 2) >> 1) {
        case 0:
            o->oPosZ += 30.0f;
            if (o->oPosZ > 19200.0f) {
                o->oF8 |= 2;
            }
            break;
        case 1:
            o->oPosZ -= 30.0f;
            if (o->oPosZ < 16400.0f) {
                o->oF8 &= ~2;
            }
            break;
    }
}



void koopa_boss_clamp_mario(void) {
    struct MarioState *m = gMarioState;
    switch (o->oF8 & 1) {
        case 0:
            if (m->pos[2] > 15630.0f) {
                m->pos[2] = 15630.0f;
            }
            if (m->pos[0] > -7360.0f)
                o->oF8 |= 1;
            break;
        case 1:
            if (m->pos[0] < -7360.0f) {
                m->pos[0] = -7360.0f;
            }
            break;
    }
}




void bhv_koopa_boss_loop(void) {
    koopa_boss_clamp_mario();
    switch (o->oAction) {
        case 0:
            cur_obj_hide();
            if (gMarioState->pos[2] > 18790.0f) {
                o->oAction = 1;
                cur_obj_unhide();
            }
            break;
        case 1:
            o->oFloatF4 = approach_f32(o->oFloatF4, 1.0f, 0.015f, 0.015);
            cur_obj_scale(o->oFloatF4);
            o->oGraphYOffset += 11.34825f;
            if (o->oFloatF4 >= 0.8f) {
                o->header.gfx.scale[0] = 0.8f;
                o->header.gfx.scale[2] = 0.8f;
            }
            if (o->oFloatF4 == 1.0f) {
                o->oAction = 2;
                cur_obj_init_animation_with_sound(3);
            }
            break;
        case 2:
            koopa_boss_move();
            break;
    }
}