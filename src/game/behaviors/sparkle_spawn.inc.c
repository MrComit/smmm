
/**
 * Behavior for bhvSparkleSpawn.
 *
 * This spawns the sparkles used by various objects. After being given a
 * random local position and scale, each sparkle's behavior is thereafter
 * controlled by bhvSparkle. This spawner is deleted after 1 frame.
 */

void bhv_sparkle_spawn_loop(void) {
    struct Object *sparkle = try_to_spawn_object(0, 1.0f, o, MODEL_SPARKLES_ANIMATION, bhvSparkle);
    if (sparkle != NULL) {
        obj_translate_xyz_random(sparkle, 90.0f);
        obj_scale_random(sparkle, 1.0f, 0.0f);
        if (o->oF4) {
            sparkle->oFlags |= OBJ_FLAG_MULTIROOM;
            sparkle->oRoom2 = gMarioCurrentRoom;
        }
    }
    if (o->oTimer > 1) {
        obj_mark_for_deletion(o);
    }
}


void bhv_red_sparkle_spawn_loop(void) {
    struct Object *sparkle = try_to_spawn_object(0, 1.0f, o, MODEL_RED_SPARKLES_ANIMATION, bhvSparkle);
    if (sparkle != NULL) {
        obj_translate_xyz_random(sparkle, 90.0f);
        obj_scale_random(sparkle, 1.0f, 0.0f);
    }
    if (o->oTimer > 1) {
        obj_mark_for_deletion(o);
    }
}
