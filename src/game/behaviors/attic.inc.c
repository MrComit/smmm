void bhv_attic_rock_loop(void) {
    f32 spireHeight;
    struct Object *obj = cur_obj_nearest_object_with_behavior(bhvAtticSpire);
    if (obj == NULL) {
        return;
    }
    switch (o->oAction) {
        case 0:
            if (lateral_dist_between_objects(o, obj) < 100.0f) {
                o->oAction = 1;
            }
            break;
        case 1:
            spireHeight = obj->oPosY + (obj->header.gfx.scale[1] * 1000.0f);
            if (o->oPosY < spireHeight) {
                // o->oPosY = spireHeight;
                o->oFloatF8 = approach_f32_symmetric(o->oFloatF8, 2.5f + (spireHeight - o->oPosY), 0.5f + (spireHeight - o->oPosY) / 2.0f);
                o->oFloatFC = approach_f32_symmetric(o->oFloatFC, 70.0f, o->oFloatF8);
                o->oPosY = approach_f32_symmetric(o->oPosY, spireHeight, o->oFloatFC);

                o->oVelY = 0;
                o->oFloatF4 = 0;
            } else {
                o->oFloatF4 = approach_f32_symmetric(o->oFloatF4, 2.5f, 0.1f);
                o->oVelY = approach_f32_symmetric(o->oVelY, 70.0f, o->oFloatF4);
                o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, o->oVelY);
                o->oFloatF8 = 0;
                o->oFloatFC = 0;
                if (o->oPosY == o->oHomeY) {
                    o->oAction = 0;
                    o->oVelY = 0;
                    o->oFloatF4 = 0;
                }
            }
            break;
    }
}


void bhv_attic_bully_loop(void) {
    bhv_bully_loop();
}



void bhv_attic_spire_init(void) {
    o->header.gfx.scale[1] = 0.0f;
}


void bhv_attic_spire_loop(void) {
    switch (o->oAction) {
        case 0:

            o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 2.0f, 0.05f);

            if (o->header.gfx.scale[1] == 2.0f) {
                o->oAction = 1;
            }
            break;
        case 1:
            // o->oGraphYOffset = approach_f32_symmetric(o->oGraphYOffset, 500.0f, 20.0f);
            if (o->oTimer > 60) {
                o->header.gfx.scale[1] = approach_f32_symmetric(o->header.gfx.scale[1], 0.0f, 0.05f);
                o->oPosY += 50.0f;
                if (o->header.gfx.scale[1] == 0.0f) {
                    o->oAction = 2;
                    o->oPosY = o->oHomeY;
                }
            }
                o->os16F4 += 0x600;
                o->header.gfx.scale[1] += (sins(o->os16F4) * 0.0075f);
            break;
        case 2:
            if (o->oTimer > 60) {
                o->oAction = 0;
                o->os16F4 = 0;
            }
            break;
    }
}