
void obj_update_standard_actions(f32 scale);

static struct ObjectHitbox sOwlHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 120,
    /* height:            */ 150,
    /* hurtboxRadius:     */ 120,
    /* hurtboxHeight:     */ 150,
};

static struct ObjectHitbox sTreehouseLogHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 180,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 180,
    /* hurtboxHeight:     */ 50,
};

static struct ObjectHitbox sTreehouseSpikeHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 3,
    /* radius:            */ 90,
    /* height:            */ 90,
    /* hurtboxRadius:     */ 90,
    /* hurtboxHeight:     */ 90,
};

static u8 sSpikeAttackHandler[6] = {
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_KNOCKBACK,
};


void bhv_treehouse_log_init(void) {
    o->oForwardVel = 20.0f;
    obj_set_hitbox(o, &sTreehouseLogHitbox);
}


void bhv_treehouse_log_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oGraphYOffset = approach_f32_symmetric(o->oGraphYOffset, 30.0f, 1.0f);
            o->oFloatF4 = approach_f32_symmetric(o->oFloatF4, 1.0f, 0.033f);
            cur_obj_scale(o->oFloatF4);
            if (o->parentObj->header.gfx.animInfo.animFrame == 50) {
                o->oAction = 1;
            }
            break;
        case 1:
            o->oFaceAnglePitch += 0x600;
            cur_obj_update_floor_and_walls();
            cur_obj_move_standard(-78);
            if (o->oMoveFlags & OBJ_MOVE_HIT_WALL) {
                obj_explode_and_spawn_coins(46.0f, 0);
                create_sound_spawner(SOUND_GENERAL_BREAK_BOX);
                o->activeFlags = 0;
                o->parentObj->prevObj = NULL;
            }
            break;
    }
}

void bhv_spike_init(void) {
    // obj_set_hitbox(o, &sTreehouseSpikeHitbox);
}


void bhv_spike_loop(void) {
    // struct Object *obj;
    f32 x = absf((gMarioState->pos[0] - o->oPosX) * sins(o->oFaceAngleYaw + 0x4000));
    f32 z = absf((gMarioState->pos[2] - o->oPosZ) * coss(o->oFaceAngleYaw + 0x4000));
    switch (o->oAction) {
        case 0:
            if (x + z < 300.0f) {
                if (cur_obj_check_if_at_animation_end()) {
                    cur_obj_init_animation_with_sound(1);
                    o->oAction = 1;
                }
            }
            break;
        case 1:
            if (x + z >= 300.0f) {
                o->oAction = 0;
            }

            if (cur_obj_check_anim_frame(20)) {
                o->prevObj = spawn_object(o, MODEL_TREEHOUSE_LOG, bhvTreehouseLog);
                // o->prevObj->oPosY += 100.0f;
            }
            if (cur_obj_check_if_at_animation_end()) {
                o->oAction = 0;
                cur_obj_init_animation_with_sound(0);
            }
            break;
    }


    // if (obj_handle_attacks(&sTreehouseSpikeHitbox, o->oAction, sSpikeAttackHandler)) {
    //     mark_goomba_as_dead();
    // }
    obj_handle_attacks(&sTreehouseSpikeHitbox, o->oAction, sSpikeAttackHandler);
    obj_update_standard_actions(1.0f);
    // o->header.gfx.scale[1] = 0.5f;
    // print_text_fmt_int(80, 80, "%x", (s32)o->prevObj);
    o->oInteractStatus = 0;

}


void bhv_blue_owl_init(void) {
    obj_set_hitbox(o, &sOwlHitbox);
}


void bhv_blue_owl_loop(void) {
    if (o->oDistanceToMario > o->oDrawingDistance && gIsConsole) {
        o->header.gfx.node.flags &= ~GRAPH_RENDER_ACTIVE;
    } else {
        o->header.gfx.node.flags |= GRAPH_RENDER_ACTIVE;
    }
    
    switch (o->oAction) {
        case 0:
            if (o->oDistanceToMario < 2000.0f) {
                o->oFaceAngleYaw = o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x800);
                if (cur_obj_check_if_at_animation_end()) {
                    cur_obj_init_animation_with_sound(1);
                    o->oAction = 1;
                }
            }
            break;
        case 1:
            o->oForwardVel = approach_f32_symmetric(o->oForwardVel, 50.0f, 2.0f);
            CL_Move();
            if (o->oTimer < 20) {
                o->oFaceAngleYaw = o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x800);
                o->oFloatF4 = gMarioState->pos[1] + 20.0f;
                if (o->oFloatF4 > o->oHomeY) {
                    o->oFloatF4 = o->oHomeY;
                }
            }
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oFloatF4, 20.0f);
            if (o->oTimer > 90 && o->oDistanceToMario > 1000.0f) {
                o->oAction = 2;
                cur_obj_init_animation_with_sound(0);
                o->oMoveAngleYaw = cur_obj_angle_to_home();
                o->oForwardVel = 30.0f;
            }
            break;
        case 2:
            o->oFaceAngleYaw = approach_s16_symmetric(o->oFaceAngleYaw, o->oMoveAngleYaw, 0x400);
            CL_Move();
            o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 20.0f);
            if (o->oTimer > 120) {
                vec3f_copy(&o->oHomeX, &o->oPosX);
                o->oForwardVel = 0;
                o->oAction = 0;
            }
            break;
    }
    o->oInteractStatus = 0;
}




void bhv_tree_limb_col_loop(void) {
    o->header.gfx.throwMatrix = &o->transform;
    vec3f_copy(&o->oPosX, o->transform[3]);
}


void bhv_tree_limb_loop(void) {
    Vec3f pos;
    if (cur_obj_check_if_at_animation_end()) {
        o->header.gfx.animInfo.animFrame = 0;
        o->oTimer = 0;
    }

}


void bhv_tight_rope_init(void) {
    o->header.gfx.scale[2] += (f32)o->oBehParams2ndByte * 0.02f;
    o->os16F8 = TIGHT_ROPE_HALF * o->header.gfx.scale[2];
}

//os16F4 = vert ycoord
//os16F6 = vert zcoord
//os16F8 = uv coord
void bhv_tight_rope_loop(void) {
    struct MarioState *m = gMarioState;
    switch (o->oAction) {
        case 0:
            o->oFloatFC -= (o->oHomeY - o->oPosY) / 10.0f;
            o->oPosY -= o->oFloatFC;
            o->oFloatFC = approach_f32_symmetric(o->oFloatFC, 0.0f, 2.0f);
            o->os16F4 = o->oHomeY - o->oPosY;
            // o->os16F8 = approach_s16_symmetric(o->os16F8, 2560, 320);
            if (gMarioObject->platform == o) {
                o->oAction = 1;
                if (m->vel[1] >= 0) {
                    o->oFloatFC = 15.0f;
                } else {
                    o->oFloatFC = -m->vel[1];
                }
                o->oFloat100 = 15.0f;
            }
            if (o->os16F6 != 0 && o->os16F4 == 0) {
                o->os16F6 = 0;
                o->os16F8 = TIGHT_ROPE_HALF * o->header.gfx.scale[2];
            }
            break;
        case 1:
            o->oFloatFC -= (o->oHomeY - o->oPosY) / 10.0f;
            o->oPosY -= o->oFloatFC;
            o->oFloatFC = approach_f32_symmetric(o->oFloatFC, 0.0f, 2.0f);
            if (-o->oFloatFC > o->oFloat100) {
                o->oFloat100 = -o->oFloatFC;
            } else {
                o->oFloat100 = approach_f32_symmetric(o->oFloat100, -o->oFloatFC, 0.5f);
            }
            if (o->oFloat100 > 40.0f) {
                o->oFloat100 = 40.0f;
            }
            o->os16F4 = o->oHomeY - o->oPosY;
            o->os16F6 = (m->pos[2] - o->oPosZ) * coss(o->oFaceAngleYaw) + (m->pos[0] - o->oPosX) * sins(o->oFaceAngleYaw);
            m->pos[2] = o->oPosZ + o->os16F6 * coss(o->oFaceAngleYaw);
            m->pos[0] = o->oPosX + o->os16F6 * sins(o->oFaceAngleYaw);
            o->os16F6 /= o->header.gfx.scale[2];
            o->os16F8 = (s16)((500.0f - (f32)o->os16F6) / 1000.0f * TIGHT_ROPE_MAX * o->header.gfx.scale[2]);
            if (gMarioObject->platform != o) {
                o->oAction = 0;
                o->oFloat100 = 0.0f;
            }
            break;
    }
}