static struct ObjectHitbox sFloorPeepaHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 90,
    /* height:            */ 60,
    /* hurtboxRadius:     */ 70,
    /* hurtboxHeight:     */ 50,
};

void bhv_floor_peepa_init(void) {
    o->oFaceAnglePitch = CL_RandomMinMaxU16(0, 0x400);
    o->oPosY -= 50.0f;
}


void bhv_floor_peepa_loop(void) {
    obj_set_hitbox(o, &sFloorPeepaHitbox);
    o->os16F4 += 0x180;
    o->oPosY = o->oHomeY + (sins(o->os16F4) * 350.0f);
    o->os16F6 += 0x3C0;
    o->oFaceAnglePitch = sins(o->os16F6) * 0x400;
    o->oFaceAngleYaw += 0x500;

    o->oInteractStatus = 0;
}