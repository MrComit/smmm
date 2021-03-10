void bhv_mirror_light_init(void) {
    o->oFaceAnglePitch = 0x4000;
}



void bhv_mirror_light_loop(void) {
    Vec3f pos;
    struct Surface *wall;
    //o->oFaceAngleYaw += 0x400;
    switch (o->oAction) {
        case 0:
            o->header.gfx.scale[1] += 0.3f;
            pos[1] = o->oPosY;
            pos[0] = o->oPosX + ((o->header.gfx.scale[1] * 100.0f) * sins(o->oFaceAngleYaw));
            pos[2] = o->oPosZ + ((o->header.gfx.scale[1] * 100.0f) * coss(o->oFaceAngleYaw));
            o->oSurfF4 = resolve_and_return_wall_collisions(pos, 0, 30.0f);
            if (o->oSurfF4 == NULL || o->oSurfF4->type != SURFACE_MIRROR) {
                break;
            }
            o->oFaceAngleYaw = atan2s(o->oSurfF4->normal.z, o->oSurfF4->normal.x);
            o->header.gfx.scale[1] = 0.1f;
            vec3f_copy(&o->oPosX, pos);
            o->oAction = 1;
            break;
        case 1:
            o->oAction = 0;
            break;
    }
}