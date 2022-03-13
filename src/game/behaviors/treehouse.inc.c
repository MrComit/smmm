// void elastic_approach(f32 *cur, f32 *curVel, f32 goal, f32 speedDown, f32 speedUp) {
//     f32 diff = goal - *cur;
//     *curVel = approach_f32_asymptotic(*curVel, diff, *cur < goal ? speedUp : speedDown);
//     *cur = *cur + *curVel;
// }

void bhv_tight_rope_init(void) {
    o->os16F8 = 2560;
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
                o->oFloatFC = -m->vel[1];
                o->oFloat100 = 15.0f;
            }
            if (o->os16F6 != 0 && o->os16F4 == 0) {
                o->os16F6 = 0;
                o->os16F8 = 2560;
            }
            break;
        case 1:
            o->oFloatFC -= (o->oHomeY - o->oPosY) / 10.0f;
            o->oPosY -= o->oFloatFC;
            o->oFloatFC = approach_f32_symmetric(o->oFloatFC, 0.0f, 2.0f);
            if (o->oFloatFC > o->oFloat100) {
                o->oFloat100 = o->oFloatFC;
            } else {
                o->oFloat100 = approach_f32_symmetric(o->oFloat100, o->oFloatFC, 2.0f);
            }
            o->os16F4 = o->oHomeY - o->oPosY;
            o->os16F6 = (m->pos[2] - o->oPosZ) * coss(o->oFaceAngleYaw) + (m->pos[0] - o->oPosX) * sins(o->oFaceAngleYaw);
            m->pos[2] = o->oPosZ + o->os16F6 * coss(o->oFaceAngleYaw);
            m->pos[0] = o->oPosX + o->os16F6 * sins(o->oFaceAngleYaw);
            o->os16F8 = (s16)((500.0f - (f32)o->os16F6) / 1000.0f * 5120);
            if (gMarioObject->platform != o) {
                o->oAction = 0;
            }
            break;
    }
}