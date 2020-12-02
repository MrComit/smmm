struct ObjectHitbox sCabinetHitbox = {
    /* interactType: */ INTERACT_BREAKABLE,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 1,
    /* numLootCoins: */ 0,
    /* radius: */ 90,
    /* height: */ 90,
    /* hurtboxRadius: */ 90,
    /* hurtboxHeight: */ 90,
};




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


void bhv_l1_cabinet_init(void) {
    obj_set_hitbox(o, &sCabinetHitbox);
}


void bhv_l1_cabinet_loop(void) {
    switch (o->oAction) {
        case 0:
            if (cur_obj_was_attacked_or_ground_pounded()) {
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