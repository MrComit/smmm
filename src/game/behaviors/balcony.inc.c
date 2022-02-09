void obj_set_dist_from_home(f32 distFromHome);

static struct ObjectHitbox sLightningHitbox = {
    /* interactType:      */ INTERACT_SHOCK,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 290,
    /* height:            */ 2100,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};


void bhv_locked_cage_init(void) {
    if (save_file_get_flags() & (1 << (o->oBehParams2ndByte + 1))) {
        o->activeFlags = 0;
    }
}


void bhv_locked_cage_loop(void) {
    if (o->oDistanceToMario < 500.0f) {
        if (save_file_get_keys(0) & (1 << o->oBehParams2ndByte)) {
            CL_explode_object(o, 1);
            play_puzzle_jingle();
            save_file_set_keys(1 << o->oBehParams2ndByte, 1);
        }
    }
}




s32 clamp_pole_f32(f32 *value, f32 minimum, f32 maximum) {
    if (*value <= minimum) {
        *value = minimum;
    } else if (*value >= maximum) {
        *value = maximum;
    } else {
        return FALSE;
    }

    return TRUE;
}


void bhv_moving_vine_init(void) {
    //o->hitboxDownOffset = 100.0f;
    o->oFloatF8 = 100.0f * o->oBehParams2ndByte;
    o->header.gfx.scale[1] = 1.3f + (0.1f * (o->oBehParams >> 24));
}

void bhv_moving_vine_loop(void) {
    if (o->oTimer > 20) {
        o->oFloatFC += o->oFloatF4;

        if (clamp_pole_f32(&o->oFloatFC, 0.0f, o->oFloatF8)) {
            o->oFloatF4 = -o->oFloatF4;
            o->oTimer = 0;
        }
    }
    obj_set_dist_from_home(o->oFloatFC);
}


void bhv_lightning_init(void) {
    o->oOpacity = 0;
    obj_set_hitbox(o, &sLightningHitbox);
    if (o->oBehParams2ndByte) {
        o->oAction = 3;
    }

    if (o->oBehParams >> 24) {
        cur_obj_become_intangible();
        o->oAction = 4;
    }
}

void bhv_lightning_loop(void) {
    o->oInteractStatus = 0;
    switch (o->oAction) {
        case 0:
            cur_obj_become_intangible();
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 255, 5);
            if (o->oOpacity == 255) {
                o->oAction = 1;
                cur_obj_shake_screen(0);
            }
            break;
        case 1:
            cur_obj_become_tangible();
            if (o->oTimer > 30) {
                o->oAction = 2;
            }
            break;
        case 2:
            cur_obj_become_intangible();
            o->oOpacity = approach_s16_symmetric(o->oOpacity, 0, 30);
            if (o->oOpacity == 0) {
                o->oAction = 0;
            }
            break;
        case 3:
            if (o->oTimer > 45) {
                o->oAction = 0;
            }
            break;
    }
}
