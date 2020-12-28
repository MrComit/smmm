#include "game/camera.h"

void koopa_boss_move(void) {
    switch ((o->oF8 & 2) >> 1) {
        case 0:
            o->oPosZ += 30.0f;
            if (o->oPosZ > 18700.0f) {
                o->oF8 |= 2;
            }
            break;
        case 1:
            o->oPosZ -= 30.0f;
            if (o->oPosZ < 16100.0f) {
                o->oF8 &= ~2;
            }
            break;
    }
}

void koopa_boss_clamp_mario(void) {
    struct MarioState *m = gMarioState;
    switch (o->oF8 & 1) {
        case 0:
            if (m->pos[2] > 15630.0f) {
                m->pos[2] = 15630.0f;
            }
            if (m->pos[0] > -7300.0f)
                o->oF8 |= 1;
            break;
        case 1:
            if (m->pos[0] < -7300.0f) {
                m->pos[0] = -7300.0f;
            }
            break;
    }
}




void bhv_koopa_boss_loop(void) {
    struct Object *obj;
    koopa_boss_clamp_mario();
    switch (o->oAction) {
        case 0:
            cur_obj_hide();
            if (gMarioState->pos[2] > 18000.0f) {
                o->oAction = 1;
                cur_obj_unhide();
            }
            break;
        case 1:
            o->oFloatF4 = approach_f32(o->oFloatF4, 1.1f, 0.015f, 0.015);
            cur_obj_scale(o->oFloatF4);
            o->oGraphYOffset += 11.34825f;
            if (o->oFloatF4 >= 0.8f) {
                o->header.gfx.scale[0] = 0.8f;
                o->header.gfx.scale[2] = 0.8f;
            }
            if (o->oFloatF4 == 1.1f) {
                o->oAction = 2;
                o->oFC = 120;
                cur_obj_init_animation_with_sound(3);
            }
            break;
        case 2:
            koopa_boss_move();
            if (o->oTimer > o->oFC) {
                obj = spawn_object(o, MODEL_L1_THIN_BOOK, bhvFlamingBossBook);
                obj->oPosY += 1800.0f;
                obj->oPosX += 600.0f;
                o->o100 += 1;
                if (o->o100 >= 5) {
                    obj->oBehParams |= 1 << 24;
                    o->o100 = 0;
                }
                o->oFC = CL_RandomMinMaxU16(45, 90);
                o->oTimer = 0;
            }
            break;
    }
}

void boss_book_flaming_loop(void) {
    vec3f_copy(&o->oObjF4->oPosX, &o->oPosX);
    if (o->oTimer > 90 || o->oMoveFlags & OBJ_MOVE_HIT_WALL || o->oInteractStatus & INT_STATUS_INTERACTED) {
        spawn_mist_particles_variable(0, 0, 25.0f);
        spawn_triangle_break_particles(6, 138, 1.0f, 4);
        create_sound_spawner(SOUND_GENERAL_HAUNTED_CHAIR_MOVE);
        o->activeFlags = 0;
        o->oObjF4->activeFlags = 0;
        //o->parentObj->oAction = 1;
    }
}

void boss_book_sparkling_loop(void) {
    spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 300.0f) {
                o->oAction = 1;
                o->oMoveAnglePitch = 0;
                o->oMoveAngleYaw = 0xC000;
                o->oForwardVel = 90.0f;
            }
            if (o->oMoveFlags & OBJ_MOVE_HIT_WALL || o->oInteractStatus & INT_STATUS_INTERACTED) {
                spawn_mist_particles_variable(0, 0, 25.0f);
                spawn_triangle_break_particles(6, 138, 1.0f, 4);
                create_sound_spawner(SOUND_GENERAL_HAUNTED_CHAIR_MOVE);
                o->activeFlags = 0;
                //o->parentObj->oAction = 1;
            }
            break;
        case 1:
            break;
    }
}



void bhv_flaming_boss_book_loop(void) {
    CL_Move_3d();
    cur_obj_update_floor_and_walls();
    o->oFaceAngleYaw += 0xC00;
    o->oFaceAngleRoll += 0xC00;
    o->oFaceAnglePitch += 0xC00;
    switch (o->oBehParams >> 24) {
        case 0:
            boss_book_flaming_loop();
            break;
        case 1:
            boss_book_sparkling_loop();
            break;
    }
}



void bhv_flaming_boss_book_init(void) {
    s16 pitch, yaw;
    f32 dist;
    Vec3f point;
    if (o->oBehParams >> 24 == 1) {
        cur_obj_scale(1.6f);
        o->oForwardVel = 30.0f;
        point[0] = -6824.0f;
        point[1] = 1944.0f;
        if (gMarioState->pos[2] > o->parentObj->oHomeZ)
            point[2] = 16641.0f;
        else
            point[2] = 18177.0f;
    } else {
        vec3f_copy(point, gMarioState->pos);
        o->oObjF4 = spawn_object(o, MODEL_RED_FLAME, bhvFlameDecoration);
        obj_scale(o->oObjF4, 10.0f);
        o->oForwardVel = 70.0f;
    }
    vec3f_get_dist_and_angle(&o->oPosX, point, &dist, &pitch, &yaw);
    o->oMoveAnglePitch = pitch;
    o->oMoveAngleYaw = yaw;
    o->oBehParams2ndByte = CL_RandomMinMaxU16(0, 2);
    //obj_set_hitbox(o, &sStrayBookHitbox);
}


void bhv_l1_lock_loop(void) {
    struct Object *obj = cur_obj_nearest_object_with_behavior(bhvFlamingBossBook);
    if (obj == NULL) {
        return;
    }
    if (dist_between_objects(o, obj) < 300.0f) {
        CL_explode_object(o, 1);
        obj->activeFlags = 0;
    }

}