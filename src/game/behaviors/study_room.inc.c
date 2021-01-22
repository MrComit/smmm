static struct ObjectHitbox sBucketHitbox = {
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


void bhv_appearing_book_init(void) {
    o->header.gfx.scale[0] = 3.0f;
    o->header.gfx.scale[1] = 6.0f;
    o->header.gfx.scale[2] = 6.0f;    
}



void bhv_appearing_book_loop(void) {
    if (gMarioCurrentRoom != o->oRoom)
        return;
    switch (o->oAction) {
        case 0:
            if (gMarioState->pos[1] <= gMarioState->floorHeight && gMarioState->pos[2] > 4596.0f) {
                o->oAction = 1;
                o->oFloatF4 = o->oHomeX - 641.0f;
            }
            break;
        case 1:
            if (o->oTimer > 15 * o->oBehParams2ndByte) {
                o->oAction = 2;
            }
            break;
        case 2:
            queue_rumble_data(5, 80);
            cur_obj_shake_screen(1);
            o->oPosX = approach_f32(o->oPosX, o->oFloatF4, 13.0f, 13.0f);
            if (o->oPosX == o->oFloatF4) {
                o->oAction = 3;
            }
    }
}



void bhv_spinning_book_init(void) {
    //bhv_platform_normals_init();
    o->header.gfx.scale[0] = 4.0f;
    o->header.gfx.scale[1] = 3.0f;
    o->header.gfx.scale[2] = 4.0f;
    o->o100 = 0x200;
    o->oBehParams2ndByte = CL_RandomMinMaxU16(0, 2);
    o->o104 = random_u16();
    o->oFaceAngleYaw = random_u16();
}


void bhv_spinning_book_loop(void) {
    //bhv_tilting_inverted_pyramid_loop();
    if (gMarioObject->platform == o) {
        o->o100 = 0xA00;
        o->oFloat108 = -35.0f;
    }
    o->o100 = approach_s16_symmetric(o->o100, 0x200, 0xA0);
    o->oFaceAngleYaw += o->o100;
    o->oFloat108 = approach_f32(o->oFloat108, 0, 1.0f, 1.0f);
    o->o104 += 0x400;
    o->oFloatF4 = o->oHomeY + (sins(o->o104) * 10.0f) + o->oFloat108;
    o->oPosY = approach_f32(o->oPosY, o->oFloatF4, 8.0f, 8.0f);
}



void bhv_l1_fireplace_init(void) {
    o->header.gfx.scale[0] = 11.0f;
    o->header.gfx.scale[1] = 9.5f;
    o->header.gfx.scale[2] = 11.0f;
}


void bhv_l1_fireplace_loop(void) {
    if (gMarioState->pos[2] > 6484.0f && gMarioState->pos[2] < 9128.0f && gMarioState->pos[0] > -10700.0f) {
        switch (o->oAction) {
            case 0:
                o->oF4 = CL_RandomMinMaxU16(50, 120);
                o->oAction = 1;
                break;
            case 1:
                if (o->oTimer > o->oF4) {
                    spawn_object(o, MODEL_RED_FLAME, bhvShootingFlame);
                    o->oAction = 0;
                }
                break;
        }
    }

    if (o->oDistanceToMario < 400.0f) {
        CL_Lava_Boost();
    }    
}


void bhv_shooting_flame_init(void) {
    o->oForwardVel = (dist_between_objects(o, gMarioObject) / 50);
    o->oVelY = 75.0f;
    o->oMoveAngleYaw = o->oAngleToMario;
    o->oPosX += 200.0f;
}


void bhv_shooting_flame_loop(void) {
    cur_obj_update_floor_and_walls();
    cur_obj_move_standard(-78);
    o->oForwardVel -= 0.15f;
    if (o->oForwardVel < 0)
        o->oForwardVel = 0;
    //o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x300);
    if (o->oTimer < 30)
        o->oMoveAngleYaw = o->oAngleToMario;
    if (o->oTimer > 300) {
        o->activeFlags = 0;
    }
    if (o->oMoveFlags & (OBJ_MOVE_HIT_WALL | OBJ_MOVE_LANDED)) {
        o->activeFlags = 0;
    }
}






void bucket_held_loop(void) {
    cur_obj_become_intangible();
    o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
    //cur_obj_init_animation(1);
    cur_obj_set_pos_relative(gMarioObject, 0, 60.0f, 60.0f);
}

void bucket_dropped_loop(void) {
    cur_obj_get_dropped();
    cur_obj_become_tangible();

    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    //cur_obj_init_animation(0);
    o->oF4 = 1;
    o->oTimer = 0;
    o->oHeldState = 0;
    //o->oAction = 0;
}

void bucket_thrown_loop(void) {
    cur_obj_enable_rendering_2();
    cur_obj_become_tangible();

    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    o->oF4 = 1;
    o->oTimer = 0;
    o->oHeldState = 0;
    o->oFlags &= ~0x8; /* bit 3 */
    o->oForwardVel = 25.0;
    o->oVelY = 20.0;
    //o->oAction = BOBOMB_ACT_LAUNCHED;
}


void bucket_free_loop(void) {
    struct Object *obj= cur_obj_nearest_object_with_behavior(bhvL1Fireplace);
    if (obj == NULL) {
        o->activeFlags = 0;
        return;
    }
    object_step();
    if (dist_between_objects(o, obj) < 200.0f) {
        CL_explode_object(o, 1);
        water_bomb_spawn_explode_particles(0, 3, 10);
        obj->activeFlags = 0;
    }

    if (o->oF4 == 1) {
        if (o->oTimer > 200) {
            o->oTimer = 0;
            o->oHeldState = 0;
            o->oPosX = o->oHomeX;
            o->oPosY = o->oHomeY;
            o->oPosZ = o->oHomeZ;
            o->oFaceAngleYaw = 0;
            o->oF4 = 0;
        }
    }
}
void bhv_water_bucket_init(void) {
    o->oGravity = 2.5;
    o->oFriction = 0.8;
    o->oBuoyancy = 1.3;
    obj_set_hitbox(o, &sBucketHitbox);
}

void bhv_water_bucket_loop(void) {
    switch (o->oHeldState) {
        case HELD_FREE:
            bucket_free_loop();
            break;

        case HELD_HELD:
            bucket_held_loop();
            break;

        case HELD_THROWN:
            bucket_thrown_loop();
            break;

        case HELD_DROPPED:
            bucket_dropped_loop();
            break;
    }
}


void bhv_sine_book_init(void) {
    o->header.gfx.scale[0] = 2.8f;
    o->header.gfx.scale[1] = 7.5f;
    o->header.gfx.scale[2] = 7.5f;
    o->oF4 = (o->oBehParams >> 24) << 8;
    if (o->oBehParams2ndByte) {
        o->oFaceAnglePitch = 0x8000;
        o->oFaceAngleYaw = 0xC000;
        o->oFaceAngleRoll = 0xC000;
    }
}


void bhv_sine_book_loop(void) {
    o->oF4 += 0x200;
    o->oPosY = o->oHomeY + (sins(o->oF4) * 500.0f);
}


void bhv_flip_book_init(void) {
    o->oObjF4 = CL_obj_nearest_object_behavior_params(bhvL1Gate, 0x00030000);
    if (o->oObjF4 == NULL) {
        o->oFaceAnglePitch = 0x8000;
        o->oAction = 2;
    }
}


void bhv_flip_book_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oObjF4->activeFlags == 0) {
                o->oFaceAnglePitch = 0x8000;
                o->oAction = 2;
            }
            load_object_collision_model();
            if (cur_obj_is_mario_ground_pounding_platform()) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oFaceAngleRoll = approach_s16_symmetric(o->oFaceAngleRoll, 0x7FFF, 0x400);
            if (o->oFaceAngleRoll == 0x7FFF) {
                o->oAction = 2;
                o->oObjF4->oF4++;
                play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gGlobalSoundSource);
            }
            break;
    }
}