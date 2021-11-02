
/**
 * Behaviors for bhvPoleGrabbing and bhvGiantPole.
 *
 * bhvPoleGrabbing is a generic behavior used almost anywhere the player can
 * grab onto and climb up another object.
 *
 * bhvGiantPole controls the large pole in Whomp's Fortress and differs from
 * other poles because it spawns a yellow ball that rests at its top.
 */



void bhv_horizontal_pole_loop(void) {
    if (o->oPosY - 10.0f < gMarioObject->oPosY
        && gMarioObject->oPosY < o->oPosY + o->hitboxHeight + 30.0f)
        if (o->oTimer > 10)
            if (!(gMarioStates[0].action & MARIO_PUNCHING))
                cur_obj_push_mario_away(70.0f);
}


void bhv_horizontal_pole_init(void) {
    s32 hitboxLength = o->oBehParams2ndByte * 5;
    o->oHomeY = (o->oFloatF8 = o->oPosY);
    o->oHomeX = o->oPosX + (sins(o->oFaceAngleYaw + 0x4000) * hitboxLength);
    o->oHomeZ = o->oPosZ + (coss(o->oFaceAngleYaw + 0x4000) * hitboxLength);
    o->oFloatFC = o->oPosX + (sins(o->oFaceAngleYaw - 0x4000) * hitboxLength);
    o->oFloatFC = o->oPosZ + (coss(o->oFaceAngleYaw - 0x4000) * hitboxLength);
}





/**
 * Initialize the hitbox height field for bhvPoleGrabbing.
 */
void bhv_pole_init(void) {
    /**
     * This is equivalent to using `o->oBehParams2ndByte` according to
     * `spawn_objects_from_info`.
     */
    s32 tenthHitboxHeight = (o->oBehParams >> 16) & 0xFF;
    o->hitboxHeight = tenthHitboxHeight * 10;
}

/**
 * Main loop for bhvGiantPole. It is equivalent to bhv_pole_base_loop() except
 * for the fact that it spawns a yellow sphere at the top of the pole on the
 * first frame.
 */
void bhv_giant_pole_loop(void) {
    if (o->oTimer == 0) {
        struct Object *topBall = spawn_object(o, MODEL_YELLOW_SPHERE, bhvYellowBall);
        topBall->oPosY += o->hitboxHeight + 50.0f;
    }
    bhv_pole_base_loop();
}
