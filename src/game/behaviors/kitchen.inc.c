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