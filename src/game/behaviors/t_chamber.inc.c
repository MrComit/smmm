static struct ObjectHitbox sSawbladeHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 2,
    /* radius:            */ 90,
    /* height:            */ 90,
    /* hurtboxRadius:     */ 90,
    /* hurtboxHeight:     */ 90,
};

void bhv_sawblade_init(void) {
    obj_set_hitbox(o, &sSawbladeHitbox);
}


void bhv_sawblade_loop(void) {
    // o->oFaceAngleRoll -= 0x400;

    o->oInteractStatus = 0;
}

void bhv_swinging_plat_loop(void) {
    o->os16F4 += 0x200;
    o->oPosX = o->oHomeX + (sins(o->os16F4) * 500.0f);
}