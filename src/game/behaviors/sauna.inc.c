void bhv_sauna_grate_init(void) {
    o->oAnimState = o->os16F4 = 2;
    o->oRoom = 14;
}

void bhv_sauna_grate_loop(void) {
    if (gMarioObject->platform == o && gMarioState->pos[1] <= gMarioState->floorHeight) {
        o->os16F4--;
    }
    if (o->os16F4 < 0) {
        o->os16F4 = 0;
    }


    if (o->oBehParams2ndByte && o->oAction == 0) {
        if (gMarioObject->platform == o) {
            struct Object *obj = spawn_object(o, MODEL_BULLY, bhvSmallBully);
            obj->oPosY += 1000.0f;
            o->oAction = 1;
        }
    }

    switch (o->os16F4) {
        case 0:
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY - 320.0f, 2.0f);
            break;
        case 1:
            break;
        case 2:
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 1.5f);
            break;
    }
    o->oAnimState = o->os16F4;
    o->os16F4 = 2;
}