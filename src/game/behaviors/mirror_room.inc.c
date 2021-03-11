void bhv_mirror_init(void) {
    o->os16F4 = o->oFaceAngleYaw;
}


void bhv_mirror_loop(void) {
    switch (o->oAction) {
        case 0:
            if (gMarioState->input & INPUT_A_PRESSED) {
                o->oAction = 1;
                o->os16F4 += 0x2000;
            }
            break;
        case 1:
            o->oFaceAngleYaw = approach_s16_symmetric((s16)o->oFaceAngleYaw, o->os16F4, 0x200);
            if (o->oFaceAngleYaw == o->os16F4) {
                o->oAction = 0;
            }
            break;
    }
}



void bhv_mirror_light_init(void) {
    o->oFaceAnglePitch = 0x4000;
}

void bhv_mirror_light_loop(void) {
    s32 i;
    Vec3f pos;
    struct Surface *wall;
    struct Object *obj;
    //o->oFaceAngleYaw += 0x400;
    switch (o->oAction) {
        case 0:
            if (gMarioState->input & INPUT_B_PRESSED) {
                o->oAction = 2;
            }
            break;
        case 2:
            for (i = 0; i < 4; i++) {
                o->header.gfx.scale[1] += 0.5f;
                pos[1] = o->oPosY;
                pos[0] = o->oPosX + ((o->header.gfx.scale[1] * 100.0f) * sins(o->oFaceAngleYaw));
                pos[2] = o->oPosZ + ((o->header.gfx.scale[1] * 100.0f) * coss(o->oFaceAngleYaw));
                o->oSurfF4 = resolve_and_return_wall_collisions(pos, 0, 40.0f);
                if (o->oSurfF4 != NULL) {
                    o->oAction = 1;
                    if (o->oSurfF4->type == SURFACE_MIRROR) {
                        obj = spawn_object(o, MODEL_MIRROR_LIGHT, bhvMirrorLight);
                        obj->oFaceAngleYaw = atan2s(o->oSurfF4->normal.z, o->oSurfF4->normal.x);
                        obj->oBehParams2ndByte = 1;
                        obj->oAction = 2;
                        vec3f_copy(&obj->oPosX, pos);
                    }
                    break;
                }
            }
            break;
        case 1:
            break;
    }
}