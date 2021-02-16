static struct ObjectHitbox sLightningHitbox = {
    /* interactType:      */ INTERACT_SHOCK,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 120,
    /* height:            */ 400,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};




void bhv_lightning_init(void) {
    o->oGravity = 2.5;
    o->oFriction = 0.8;
    o->oBuoyancy = 1.3;
    obj_set_hitbox(o, &sLightningHitbox);
}

void bhv_lightning_loop(void) {
    o->oOpacity = 255;
    o->oInteractStatus = 0;
}
