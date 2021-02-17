static struct ObjectHitbox sLightningHitbox = {
    /* interactType:      */ INTERACT_SHOCK,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 290,
    /* height:            */ 2100,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};


void bhv_lightning_init(void) {
    o->oOpacity = 0;
    obj_set_hitbox(o, &sLightningHitbox);
    if (o->oBehParams2ndByte) {
        o->oAction = 3;
    }
}

void bhv_lightning_loop(void) {
    o->oInteractStatus = 0;
    switch (o->oAction) {
        case 0:
            cur_obj_become_intangible();
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 5);
            if (o->oOpacity == 255) {
                o->oAction = 1;
                cur_obj_shake_screen(0);
            }
            break;
        case 1:
            cur_obj_become_tangible();
            if (o->oTimer > 30) {
                o->oAction = 2;
            }
            break;
        case 2:
            cur_obj_become_intangible();
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 30);
            if (o->oOpacity == 0) {
                o->oAction = 0;
            }
            break;
        case 3:
            if (o->oTimer > 45) {
                o->oAction = 0;
            }
            break;
    }
}
