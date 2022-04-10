static struct ObjectHitbox sVaseThrowHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 80,
    /* height:            */ 175,
    /* hurtboxRadius:     */ 80,
    /* hurtboxHeight:     */ 175,
};

void bhv_vase_throw_init(void) {
    obj_set_hitbox(o, &sVaseThrowHitbox);
    o->os16FA = 0x200 * random_sign();
}


void bhv_vase_throw_loop(void) {
    f32 dist;
    s16 pitch, yaw;
    switch (o->oAction) {
        case 0:
            o->os16F8 += o->os16FA;
            o->oPosY = o->oHomeY + (sins(o->os16F8) * 20.0f);
            o->oFloat100 = 1.0f + (sins(o->os16F8 * 2) * 0.1f);
            o->oFaceAnglePitch = sins(o->os16F8 / 2) * 0x400;
            cur_obj_scale(o->oFloat100);
            o->oFaceAngleYaw += 0x200;
            if (o->oDistanceToMario < 2000.0f) {
                o->oAction = 1;
            }
            break;
        case 1:
            vec3f_get_dist_and_angle(&o->oPosX, gMarioState->pos, &dist, &pitch, &yaw);
            o->oFloat100 = approach_f32_symmetric(o->oFloat100, 1.0f, 0.02f);
            cur_obj_scale(o->oFloat100);
            o->oMoveAnglePitch = pitch;
            o->oMoveAngleYaw = yaw;
            o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, -o->oMoveAnglePitch + 0x4000, 0x400);
            o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, o->oMoveAngleYaw, 0x400);
            if (o->oTimer > 15) {
                o->oAction = 2;
                cur_obj_scale(o->oFloat100 = 1.0f);
            }
            break;
        case 2:
            // if (o->oTimer < 10) {
                o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x1800 / (o->oTimer + 1));
            // }
            o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, o->oMoveAngleYaw, 0x400);
            o->oFloatF4 = approach_f32_symmetric(o->oFloatF4, 5.0f, 0.4f);
            o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 80.0f, o->oFloatF4);
            CL_Move_3d();
            cur_obj_update_floor_and_walls();
            if (o->oInteractStatus || o->oMoveFlags & OBJ_MOVE_HIT_WALL || o->oPosY < o->oFloorHeight) {
                spawn_mist_particles();
                cur_obj_hide();
                o->oAction = 3;
                vec3f_copy(&o->oPosX, &o->oHomeX);
                o->oFaceAnglePitch = 0;
            }
            break;
        case 3:
            if (o->oTimer > 45) {
                cur_obj_unhide();
                o->oFloatFC = approach_f32_symmetric(o->oFloatFC, 1.0f, 0.05f);
                cur_obj_scale(o->oFloatFC);
                if (o->oFloatFC == 1.0f) {
                    o->oAction = 0;
                    o->oFloatFC = 0.0f;
                    o->os16F8 = 0;
                    o->oFloatF4 = 0.0f;
                }
            }
            break;
    }
    o->oInteractStatus = 0;
}



void bhv_static_wall_init(void) {
    o->oFloatF4 = o->oBehParams2ndByte * 100.0f;
}

void bhv_static_wall_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < (o->oFloatF4 * 2)) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->os16F8 = approach_s16_symmetric(o->os16F8, 0x4000, 0x20);
            o->oFloatFC = o->oFloatF4 * sins(o->os16F8);
            o->oPosX = o->oHomeX + (sins(o->oFaceAngleYaw) * o->oFloatFC);
            o->oPosZ = o->oHomeZ + (coss(o->oFaceAngleYaw) * o->oFloatFC);
            if (o->os16F8 == 0x4000) {
                o->oAction = 2;
            }
            break;
        case 2:
            break;
    }
}

void bhv_static_tri_init(void) {
    o->os16F8 = random_u16();
}

void bhv_static_tri_loop(void) {
    o->os16F8 += 0x300;
    o->oFloatF4 = sins(o->os16F8) * 250.0f;
    o->oPosX = o->oHomeX + (sins(o->oFaceAngleYaw + 0x4000) * o->oFloatF4);
    o->oPosZ = o->oHomeZ + (coss(o->oFaceAngleYaw + 0x4000) * o->oFloatF4);
}