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
    o->oFloatF8 = -sins(o->os16F4) * 500.0f;
    o->oPosX = o->oHomeX + (sins(o->os16F4) * 500.0f) * sins(o->oFaceAngleYaw);
    o->oPosZ = o->oHomeZ + (sins(o->os16F4) * 500.0f) * coss(o->oFaceAngleYaw);
    f32 homeD = o->oHomeX * sins(o->oFaceAngleYaw) + o->oHomeZ * coss(o->oFaceAngleYaw);
    f32 posD = o->oPosX * sins(o->oFaceAngleYaw) + o->oPosZ * coss(o->oFaceAngleYaw);
    f32 riseSqr = (homeD - posD) * (homeD - posD);
    f32 yRise = sqrtf(1440000 - riseSqr);
    o->oPosY = o->oHomeY + (1200.0f - yRise);

    /*distance from pos -> (home + 1200) must = 1200
    distance formula: (homeX - posX)^2 + x^2 = 1200^2
        (homeX - posX)^2 + x^2 = 1200^2
        x = sqr(1440000 - (homeX - posX)^2)

    example: 500
        500^2 + c^2 = 1200^2
        c^2 = 1190000
        1090.8712114635714411502154487373
    */
}