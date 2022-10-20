void bhv_basement_dryer_init(void) {


}


void bhv_basement_dryer_loop(void) {
    switch (o->oAction) {
        case 0:
            if (cur_obj_is_mario_ground_pounding_platform()) {
                cur_obj_init_animation(0);
                o->oAction = 1;
            }
            break;
    }
}


void bhv_basement_washer_init(void) {


}

void bhv_basement_washer_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oTimer > 30) {
                cur_obj_init_animation(1);
                if (cur_obj_set_anim_if_at_end(0)) {
                    o->oAction = 1;
                }
            }

            break;
        case 1:
            if (cur_obj_set_anim_if_at_end(2)) {
                o->oAction = 0;
            }
            break;
    }
}