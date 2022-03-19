struct ObjectHitbox s2DEnemyHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 72,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 42,
    /* hurtboxHeight:     */ 40,
};


void bhv_2d_goomba_init(void) {
    obj_set_hitbox(o, &s2DEnemyHitbox);
}

void bhv_2d_goomba_loop(void) {
    
}


void bhv_2d_koopa_init(void) {
    obj_set_hitbox(o, &s2DEnemyHitbox);
}

void bhv_2d_koopa_loop(void) {
    
}