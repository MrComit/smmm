void bhv_appearing_book_init(void) {
    o->header.gfx.scale[0] = 3.0f;
    o->header.gfx.scale[1] = 6.0f;
    o->header.gfx.scale[2] = 6.0f;    
}



void bhv_appearing_book_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioState->pos[1] <= gMarioState->floorHeight && absf(gMarioState->pos[2] - o->oPosZ) < 800.0f) {
                o->oAction = 1;
                o->oFloatF4 = o->oHomeX - 641.0f;
            }
            break;
        case 1:
            queue_rumble_data(5, 80);
            cur_obj_shake_screen(1);
            o->oPosX = approach_f32(o->oPosX, o->oFloatF4, 13.0f, 13.0f);
            if (o->oPosX == o->oFloatF4) {
                o->oAction = 2;
            }
            break;
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