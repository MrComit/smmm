Vec3f sBedroomFlamePos[4] = {
{-5472.36f, 100.0f, -10234.8f},
{-5472.36f, 100.0f, -12334.8f},
{-7572.36f, 100.0f, -12334.8f},
{-7572.36f, 100.0f, -10234.8f},
};

u32 sBedroomFlameCol[4] = {0x00802000, 0x96008F00, 0x58009600, 0x96690000};


void bhv_shyguy_flame_init(void) {
    s16 param = o->oBehParams >> 24;
    o->oObj110 = spawn_object(o, MODEL_ENV_FLAME, bhvHeldEnvFlame);
    o->oObj110->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
    o->oObj110->oBehParams = sBedroomFlameCol[param];
    //vec3f_copy(&o->oObj110->oPosX, sBedroomFlamePos[param]);
    o->oOpacity = 0;
}


void bhv_shyguy_flame_loop(void) {
    s16 param = o->oBehParams >> 24;
    f32 dist = o->oDistanceToMario;
    if (o->oObj110 == NULL) {
        o->activeFlags = 0;
        return;
    }
    cur_obj_scale(o->oGoombaScale);
    cur_obj_update_floor_and_walls();
    goomba_act_walk();
    cur_obj_move_standard(-78);

    if (dist < 150.0f)
        dist = 150.0f;

    o->oOpacity = 255 * (150.0f / dist);

    o->oObj110->oPosX = o->oPosX + (sins(o->oFaceAngleYaw) * 50.0f);
    o->oObj110->oPosZ = o->oPosZ + (coss(o->oFaceAngleYaw) * 50.0f);
    o->oObj110->oPosY = o->oPosY + 60.0f;

    if (o->oInteractStatus & INT_STATUS_INTERACTED && o->oInteractStatus & INT_STATUS_WAS_ATTACKED) {
        //spawn_mist_particles();
        obj_spawn_loot_yellow_coins(o, o->oNumLootCoins, 20.0f);
        o->activeFlags = 0;
        create_sound_spawner(SOUND_OBJ_DYING_ENEMY1);
        o->oObj110->activeFlags = 0;
        o->oObj110 = spawn_object(o, MODEL_ENV_FLAME, bhvEnvFlame);
        o->oObj110->oFlags &= ~OBJ_FLAG_DISABLE_ON_ROOM_EXIT;
        o->oObj110->oBehParams = sBedroomFlameCol[param];
        vec3f_copy(&o->oObj110->oPosX, sBedroomFlamePos[param]);
    }
    o->oInteractStatus = 0;
}