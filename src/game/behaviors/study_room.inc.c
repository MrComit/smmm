void bhv_appearing_book_init(void) {
    o->header.gfx.scale[0] = 3.0f;
    o->header.gfx.scale[1] = 6.0f;
    o->header.gfx.scale[2] = 6.0f;    
}



void bhv_appearing_book_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioState->pos[1] <= gMarioState->floorHeight && gMarioState->pos[2] > 4596.0f) {
                o->oAction = 1;
                o->oFloatF4 = o->oHomeX - 641.0f;
            }
            break;
        case 1:
            if (o->oTimer > 15 * o->oBehParams2ndByte) {
                o->oAction = 2;
            }
            break;
        case 2:
            queue_rumble_data(5, 80);
            cur_obj_shake_screen(1);
            o->oPosX = approach_f32(o->oPosX, o->oFloatF4, 13.0f, 13.0f);
            if (o->oPosX == o->oFloatF4) {
                o->oAction = 3;
            }
    }
}



void bhv_spinning_book_init(void) {
    //bhv_platform_normals_init();
    o->header.gfx.scale[0] = 4.0f;
    o->header.gfx.scale[1] = 3.0f;
    o->header.gfx.scale[2] = 4.0f;
    o->o100 = 0x200;
    o->oBehParams2ndByte = CL_RandomMinMaxU16(0, 2);
    o->o104 = random_u16();
    o->oFaceAngleYaw = random_u16();
}


void bhv_spinning_book_loop(void) {
    //bhv_tilting_inverted_pyramid_loop();
    if (gMarioObject->platform == o) {
        o->o100 = 0xA00;
        o->oFloat108 = -35.0f;
    }
    o->o100 = approach_s16_symmetric(o->o100, 0x200, 0xA0);
    o->oFaceAngleYaw += o->o100;
    o->oFloat108 = approach_f32(o->oFloat108, 0, 1.0f, 1.0f);
    o->o104 += 0x400;
    o->oFloatF4 = o->oHomeY + (sins(o->o104) * 10.0f) + o->oFloat108;
    o->oPosY = approach_f32(o->oPosY, o->oFloatF4, 8.0f, 8.0f);
}



void bhv_l1_fireplace_init(void) {
    o->header.gfx.scale[0] = 11.0f;
    o->header.gfx.scale[1] = 9.0f;
    o->header.gfx.scale[2] = 11.0f;



}


void bhv_l1_fireplace_loop(void) {
    if (gMarioState->pos[2] > 6484.0f && gMarioState->pos[2] < 9128.0f && gMarioState->pos[0] > -10700.0f) {
        switch (o->oAction) {
            case 0:
                o->oF4 = CL_RandomMinMaxU16(50, 120);
                o->oAction = 1;
                break;
            case 1:
                if (o->oTimer > o->oF4) {
                    spawn_object(o, MODEL_RED_FLAME, bhvShootingFlame);
                    o->oAction = 0;
                }
                break;
        }
    }

    if (o->oDistanceToMario < 180.0f) {
        CL_Lava_Boost();
    }    
}


void bhv_shooting_flame_init(void) {
    o->oForwardVel = (dist_between_objects(o, gMarioObject) / 50);
    o->oVelY = 75.0f;
    o->oMoveAngleYaw = o->oAngleToMario;
    o->oPosX += 200.0f;
}


void bhv_shooting_flame_loop(void) {
    cur_obj_update_floor_and_walls();
    cur_obj_move_standard(-78);
    o->oForwardVel -= 0.15f;
    if (o->oForwardVel < 0)
        o->oForwardVel = 0;
    //o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x300);
    if (o->oTimer < 30)
        o->oMoveAngleYaw = o->oAngleToMario;
    if (o->oTimer > 300) {
        o->activeFlags = 0;
    }
    if (o->oMoveFlags & (OBJ_MOVE_HIT_WALL | OBJ_MOVE_LANDED)) {
        o->activeFlags = 0;
    }
}