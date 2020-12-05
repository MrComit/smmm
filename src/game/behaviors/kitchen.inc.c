#include "game/camera.h"

struct ObjectHitbox sBarrelHitbox = {
    /* interactType: */ INTERACT_IGLOO_BARRIER,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 1,
    /* numLootCoins: */ 0,
    /* radius: */ 100,
    /* height: */ 240,
    /* hurtboxRadius: */ 100,
    /* hurtboxHeight: */ 240,
};

static struct ObjectHitbox sPanHitbox = {
    /* interactType:      */ INTERACT_GRABBABLE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 65,
    /* height:            */ 113,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};



void bhv_burner_init(void) {
    if (o->oBehParams2ndByte == 1) {
        o->oFaceAngleRoll = 0x8000;
        o->oAction = 2;
    }

}


void bhv_burner_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oTimer > 45) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oFaceAngleRoll += 0x600;
            if (o->oFaceAngleRoll >= 0x8000) {
                o->oAction = 2;
                o->oFaceAngleRoll = 0x8000;
            }
            break;
        case 2:
            if (o->oTimer > 45) {
                o->oAction = 3;
            }
            break;
        case 3:
            o->oFaceAngleRoll -= 0x600;
            if (o->oFaceAngleRoll < 0) {
                o->oAction = 0;
                o->oFaceAngleRoll = 0;
            }
            break;
    }
}


void bhv_l1_cabinet_init(void) {
    if (o->oBehParams2ndByte == 1) {
        o->oObjF4 = spawn_object(o, MODEL_GOOMBA, bhvGoomba);
        o->oObjF4->oPosX -= 250.0f;
        o->oObjF4->oPosZ += 125.0f;
        o->oObjF4->parentObj = o->oObjF4;
        //o->oObjF4->oHomeX = o->oObjF4->oPosX;
        //o->oObjF4->oHomeZ = o->oObjF4->oPosZ;
    }
}

void bhv_l1_cabinet_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oFlags & OBJ_FLAG_KICKED_OR_PUNCHED) {
                o->oAction = 1;
            }
            if (o->oTimer > 1 && o->oObjF4 != NULL) {
                vec3f_copy(&o->oObjF4->oPosX, &o->oObjF4->oHomeX);
            }
            break;
        case 1:
            o->oFaceAngleYaw -= 0x4000;
            o->oFaceAngleYaw -= o->oFaceAngleYaw / 20;
            o->oFaceAngleYaw += 0x4000;
            if (o->oFaceAngleYaw == 0x4000) {
                o->oFaceAngleYaw = 0x4000;
                o->oAction = 2;
            }
            break;
        case 2:
            break;
    }
}


void bhv_l1_barrel_loop(void) {
    switch (o->oAction) {
        case 0:
            load_object_collision_model();
            if (o->oFlags & OBJ_FLAG_KICKED_OR_PUNCHED && absi(gMarioState->faceAngle[1] + 0x4000) < 0x2000) {
                o->oAction = 1;
                o->oMoveAngleYaw = 0xC000;
                o->oForwardVel = 5.0f;
                o->oFloatF8 = 1.0f;
                o->oCollisionDistance = 32767.0f;
                obj_set_hitbox(o, &sBarrelHitbox);
                //o->oGraphYOffset = 111.0f;
            }
            break;
        case 1:
            o->oF4 = approach_s16_symmetric(o->oF4, 0x900, 0x1C);
            o->oFloatF8 = approach_f32(o->oFloatF8, 1.05, 0.003f, 0.003f);
            o->oFaceAngleRoll += o->oF4;
            o->oForwardVel *= o->oFloatF8;
            o->oGraphYOffset = 256.86f * (absi((s16)o->oFaceAngleRoll) / 32768.0f);
            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(-78);
            if (o->oPosX <= 840.0f) {
                o->oForwardVel = 0;
                o->oVelX = (o->oVelZ = 0);
                o->oFaceAngleRoll = 0;
                o->oGraphYOffset = 0;
                o->oAction = 2;
                o->oCollisionDistance = 768.0f;
                queue_rumble_data(5, 80);
                cur_obj_shake_screen(2);
            }
            break;
        case 2:
            load_object_collision_model();
            break;
    }
}



void bhv_l1_shelf_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            obj = cur_obj_nearest_object_with_behavior(bhvL1Barrel);
            if (obj == NULL) {
                o->activeFlags = 0;
                break;
            }
            if (obj->oAction == 2) {
                o->oAction = 1;
            }
            break;
        case 1:
            //o->oFaceAnglePitch = approach_s16_symmetric(o->oFaceAnglePitch, 0x4000, 0x400);
            o->oFaceAnglePitch -= 0x4000;
            o->oFaceAnglePitch -= o->oFaceAnglePitch / 18;
            o->oFaceAnglePitch += 0x4000;
            if (o->oFaceAnglePitch == 0x4000) {
                o->oAction = 2;
                play_puzzle_jingle();
            }
            break;
        case 2:
            break;
    }
}


void bhv_kitchen_door_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 800.0f) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oFaceAngleYaw -= 0xA000;
            o->oFaceAngleYaw -= o->oFaceAngleYaw / 48;
            o->oFaceAngleYaw += 0xA000;
            if (o->oFaceAngleYaw == 0xA000) {
                o->oAction = 2;
            }
            break;
        case 2:
            break;
    }
}


void bhv_fridge_spawner_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            obj = cur_obj_nearest_object_with_behavior(bhvFridgeDoor);
            if (obj == NULL) {
                o->activeFlags = 0;
                break;
            }
            if (obj->oAction != 0) {
                o->oAction = 1;
            }
            break;
        case 1:
            if (o->oTimer > 30) {
                o->oAction = 2;
            }
            break;
        case 2:
            obj = spawn_object(o, MODEL_BLACK_BOBOMB, bhvIceBobomb);
            obj->oMoveAngleYaw = 0x4000;
            obj->oVelY = 30.0f;
            obj->oForwardVel = 13.0f;
            o->oAction = 1;
            break;
    }
}



void bhv_stove_button_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oFlags & OBJ_FLAG_KICKED_OR_PUNCHED) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oFloatF4 -= 0.08f;
            if (o->oFloatF4 < 0) {
                o->oFloatF4 = 0.1f;
                o->oAction = 2;
            }
            o->header.gfx.scale[2] = o->oFloatF4;
            break;
        case 2:
            break;
    }
}

void pan_held_loop(void) {
    cur_obj_become_intangible();
    o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
    //cur_obj_init_animation(1);
    cur_obj_set_pos_relative(gMarioObject, 0, 60.0f, 60.0f);
    vec3f_copy(&o->oObjF4->oPosX, &o->oPosX);
    o->oObjF4->oPosY += 25.0f;
}

void pan_dropped_loop(void) {
    cur_obj_get_dropped();
    cur_obj_become_tangible();

    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    //cur_obj_init_animation(0);

    o->oHeldState = 0;
    //o->oAction = 0;
}

void pan_thrown_loop(void) {
    cur_obj_enable_rendering_2();
    cur_obj_become_tangible();

    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    o->oHeldState = 0;
    o->oFlags &= ~0x8; /* bit 3 */
    o->oForwardVel = 25.0;
    o->oVelY = 20.0;
    //o->oAction = BOBOMB_ACT_LAUNCHED;
}


void pan_free_loop(void) {
    struct Object *obj;
    object_step();
    switch (o->oAction) {
        case 0:
            cur_obj_become_intangible();
            if (o->oObjF8->oAction != 0) {
                o->oAction = 1;
                cur_obj_become_tangible();
                o->oObjF4 = spawn_object(o, MODEL_RED_FLAME, bhvPanFlame);
            }
            break;
        case 1:
            vec3f_copy(&o->oObjF4->oPosX, &o->oPosX);
            obj = cur_obj_nearest_object_with_behavior(bhvFridgeSpawner);
            if (obj == NULL) {
                o->activeFlags = 0;
                return;
            }
            if (dist_between_objects(o, obj) < 200.0f) {
                CL_explode_object(o, 1);
                obj->activeFlags = 0;
                o->oObjF4->activeFlags = 0;
            }
            break;
    }

}
void bhv_frying_pan_init(void) {
    o->oGravity = 2.5;
    o->oFriction = 0.8;
    o->oBuoyancy = 1.3;
    obj_set_hitbox(o, &sPanHitbox);
    o->oObjF8 = cur_obj_nearest_object_with_behavior(bhvStoveButton);
    if (o->oObjF8 == NULL)
        o->activeFlags = 0;

}

void bhv_frying_pan_loop(void) {
    switch (o->oHeldState) {
        case HELD_FREE:
            pan_free_loop();
            break;

        case HELD_HELD:
            pan_held_loop();
            break;

        case HELD_THROWN:
            pan_thrown_loop();
            break;

        case HELD_DROPPED:
            pan_dropped_loop();
            break;
    }
}