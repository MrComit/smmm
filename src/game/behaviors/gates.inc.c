struct ObjectHitbox sLeverHitbox = {
    /* interactType: */ INTERACT_BREAKABLE,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 1,
    /* numLootCoins: */ 0,
    /* radius: */ 90,
    /* height: */ 90,
    /* hurtboxRadius: */ 90,
    /* hurtboxHeight: */ 90,
};


void bhv_lever_loop(void) {
    obj_set_hitbox(o, &sLeverHitbox);

    if (o->oF4 == 0 && cur_obj_was_attacked_or_ground_pounded() != 0) {
        cur_obj_init_anim_and_check_if_end(1);
        play_puzzle_jingle();
        o->oF4 = 1;
    }
}


void bhv_l1_gate_loop(void) {
    struct Object *obj;
    switch (o->oAction) {
        case 0:
            switch (o->oBehParams2ndByte) {
                case 0:
                    obj = cur_obj_nearest_object_with_behavior(bhvLever);
                    if (obj == NULL || obj->oF4 == 1) {
                        o->oAction = 1;
                    }
                    break;
                case 1:
                    break;
            }
            break;
        case 1:
            o->oPosY = approach_f32(o->oPosY, o->oHomeY + 300.0f, 10.0f, 10.0f);
            if (o->oPosY == o->oHomeY + 300.0f)
                o->activeFlags = 0;
            break;
    }
}