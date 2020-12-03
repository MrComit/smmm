void bhv_burner_init(void) {
    if (o->oBehParams2ndByte == 1) {
        o->oFaceAngleRoll = 0x8000;
        o->oAction = 2;
    }

}


void bhv_burner_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oTimer > 45) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oFaceAngleRoll += 0x600;
            if (o->oFaceAngleRoll >= 0x8000) {
                o->oAction = 2;
                o->oFaceAngleRoll = 0x8000;
            }
            break;
        case 2:
            if (o->oTimer > 45) {
                o->oAction = 3;
            }
            break;
        case 3:
            o->oFaceAngleRoll -= 0x600;
            if (o->oFaceAngleRoll < 0) {
                o->oAction = 0;
                o->oFaceAngleRoll = 0;
            }
            break;
    }
}


void bhv_l1_cabinet_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioState->flags & (MARIO_KICKING | MARIO_PUNCHING) && gMarioState->wall != NULL && gMarioState->wall->object == o) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oFaceAngleYaw += 0x300;
            if (o->oFaceAngleYaw >= 0x4000) {
                o->oFaceAngleYaw = 0x4000;
                o->oAction = 2;
            }
            break;
        case 2:
            break;
    }
}


void bhv_l1_barrel_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioState->flags & (MARIO_KICKING | MARIO_PUNCHING) && gMarioState->wall != NULL && gMarioState->wall->object == o 
            && absi(gMarioState->faceAngle[1] + 0x4000) < 0x2000) {
                o->oAction = 1;
                o->oMoveAngleYaw = 0xC000;
                o->oForwardVel = 5.0f;
                o->oFloatF8 = 1.0f;
                //o->oGraphYOffset = 111.0f;
            }
            break;
        case 1:
            o->oF4 = approach_s16_symmetric(o->oF4, 0x600, 0x20);
            o->oFloatF8 = approach_f32(o->oFloatF8, 1.08, 0.001f, 0.001f);
            o->oFaceAngleRoll += o->oF4;
            o->oForwardVel *= o->oFloatF8;
            o->oGraphYOffset = 111.0f * (absi((s16)o->oFaceAngleRoll) / 32768.0f);
            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(-78);
            
            break;
        case 2:
            break;
    }
}