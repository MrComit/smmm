void bhv_static_wall_init(void) {
    o->oFloatF4 = o->oBehParams2ndByte * 100.0f;
}

void bhv_static_wall_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < (o->oFloatF4 * 2)) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->os16F8 = approach_s16_symmetric(o->os16F8, 0x4000, 0x20);
            o->oFloatFC = o->oFloatF4 * sins(o->os16F8);
            o->oPosX = o->oHomeX + (sins(o->oFaceAngleYaw) * o->oFloatFC);
            o->oPosZ = o->oHomeZ + (coss(o->oFaceAngleYaw) * o->oFloatFC);
            if (o->os16F8 == 0x4000) {
                o->oAction = 2;
            }
            break;
        case 2:
            break;
    }
}

void bhv_static_tri_init(void) {
    o->os16F8 = random_u16();
}

void bhv_static_tri_loop(void) {
    o->os16F8 += 0x300;
    o->oFloatF4 = sins(o->os16F8) * 250.0f;
    o->oPosX = o->oHomeX + (sins(o->oFaceAngleYaw + 0x4000) * o->oFloatF4);
    o->oPosZ = o->oHomeZ + (coss(o->oFaceAngleYaw + 0x4000) * o->oFloatF4);
}