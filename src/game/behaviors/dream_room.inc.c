s32 absi(s32 x);

void bhv_yoshi_head_init(void) {
    // o->oF4 = 1;
}

void bhv_yoshi_head_loop(void) {
    s32 i = 0;
    f32 length, sin, cos;
    f32 divisor;
    struct Surface *wall;
    struct MarioState *m = gMarioState;
    o->oMoveAngleYaw += 0x100;

    // RAYCAST TYPE THING
    o->oHomeY = o->oPosY;
    length = 0;
    sin = sins(o->oMoveAngleYaw);
    cos = coss(o->oMoveAngleYaw);
    while (wall == NULL) {
        length += 50.0f;
        if (length >= 2000.0f) {
            length = 2000.0f;
            break;
        }
        o->oHomeX = o->oPosX + (length * sin);
        o->oHomeZ = o->oPosZ + (length * cos);
        wall = resolve_and_return_wall_collisions(&o->oHomeX, 0, 90.0f);
        if (wall != NULL) {
            length -= 10.0f;
            while (o->oSurfF8 == NULL) {
                length += 10.0f;
                o->oHomeX = o->oPosX + (length * sin);
                o->oHomeZ = o->oPosZ + (length * cos);
                o->oSurfF8 = resolve_and_return_wall_collisions(&o->oHomeX, 0, 40.0f);
                if (o->oSurfF8 != NULL) {
                    length -= 10.0f;
                    o->oSurfF8 = NULL;
                    break;
                }
                i++;
                if (i >= 20) {
                    return;
                }
            }
            break;
        }

    }
    // LENGTH SET
    o->oF4 = length;


    //MARIO DISTANCE FROM LINE
    // m1 = coss(o->oMoveAngleYaw) / sins(o->oMoveAngleYaw);
    // b = o->oPosZ - (o->oPosX * m1);
    // e1 = absf((m1 * m->pos[0]) - m->pos[2] + b);
    // d = e1 / sqrtf(m1*m1 + 1);
    // yDif = absf(m->pos[1] - o->oPosY);
    // if ((s16)o->oDistanceToMario < o->oF4 && d < (o->oDistanceToMario / 10.0f) && yDif < 500.0f 
    //     && absi(o->oAngleToMario - (s16)o->oMoveAngleYaw) < 0x400) {
    //     if (o->oTimer > 60) {
    //         CL_get_hit(gMarioState, gMarioObject, 0);
    //         // spawn_object(o, MODEL_SAWBLADE, bhvSawbladeShoot);
    //         o->oTimer = 0;
    //     }
    // }

    divisor = (f32)o->oF4 / 1024.0f;
    if ((s16)o->oDistanceToMario < o->oF4 && absi(o->oAngleToMario - (s16)o->oMoveAngleYaw) < (o->oDistanceToMario / divisor)) {
        if (o->oTimer > 60) {
            CL_get_hit(gMarioState, gMarioObject, 0);
            // spawn_object(o, MODEL_SAWBLADE, bhvSawbladeShoot);
            o->oTimer = 0;
        }
    }
    print_text_fmt_int(80, 80, "%x", absi(o->oAngleToMario - (s16)o->oMoveAngleYaw), 0);
    print_text_fmt_int(80, 40, "%x", (s32)(o->oDistanceToMario / divisor), 0);


}
