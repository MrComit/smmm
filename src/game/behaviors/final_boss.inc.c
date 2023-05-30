static struct ObjectHitbox sTheControllerHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 180,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 255,
    /* numLootCoins:      */ 0,
    /* radius:            */ 300,
    /* height:            */ 300,
    /* hurtboxRadius:     */ 300,
    /* hurtboxHeight:     */ 300,
};


void bhv_the_controller_init(void) {
    obj_set_hitbox(o, &sTheControllerHitbox);

}


void bhv_the_controller_loop(void) {
    o->oInteractStatus = 0;
}