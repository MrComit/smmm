static struct ObjectHitbox sChandelierHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,//1400,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 400,
    /* height:            */ 600,
    /* hurtboxRadius:     */ 400,
    /* hurtboxHeight:     */ 600,
};


void bhv_chandelier_init(void) {
    obj_set_hitbox(o, &sChandelierHitbox); 
}


void bhv_chandelier_loop(void) {
    Vec3f point1, point2;
    point1[0] = o->oHomeX;
    point1[1] = o->oHomeY + 1500.0f;
    point1[2] = o->oHomeZ;
    o->oF8 += 0x200;
    o->oFaceAngleRoll = 0x2800 * sins(o->oF8);
    vec3f_set_dist_and_angle(point1, point2, 1500.0f, o->oFaceAngleRoll - 0x4000, 0x4000);
    vec3f_copy(&o->oPosX, point2);
    o->oInteractStatus = 0;
    if (gMarioCurrentRoom == o->oRoom && absi(o->oFaceAngleRoll) > 0x2000) {
        cur_obj_play_sound_2(SOUND_ENV_BOAT_ROCKING1);
    }
}