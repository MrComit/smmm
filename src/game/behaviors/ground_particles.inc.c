// ground_particles.inc.c
// #include "include/sm64.h"
static struct SpawnParticlesInfo sGPMistParticles = {
    /* behParam:        */ 3,
    /* count:           */ 1,
    /* model:           */ MODEL_MIST,
    /* offsetY:         */ 20,
    /* forwardVelBase:  */ 4,
    /* forwardVelRange: */ 2,
    /* velYBase:        */ 0,
    /* velYRange:       */ 0,
    /* gravity:         */ 0,
    /* dragStrength:    */ 50,
    /* sizeBase:        */ 7.0f,
    /* sizeRange:       */ 1.5f,
};


void bhv_dizzy_triangle_init(void) {
    o->oAnimState = 4;
    o->oFloatF8 = 0.01f;
    cur_obj_scale(0.01f);
    o->oFaceAnglePitch = o->os16F4;
    o->oFaceAngleRoll = o->os16F4;
    o->oFaceAngleYaw = o->os16F4;
}


void bhv_dizzy_triangle_loop(void) {
    o->os16F4 += 0x300;
    o->oPosY = gMarioState->pos[1] + 163.0f;
    o->oPosX = gMarioState->pos[0] + (40.0f * sins(o->os16F4));
    o->oPosZ = gMarioState->pos[2] + (40.0f * coss(o->os16F4));
    o->oFaceAnglePitch += 0x600;
    o->oFaceAngleRoll += 0x600;
    o->oFaceAngleYaw += 0x600;
    if (!(gMarioState->particleFlags & PARTICLE_DIZZY)) {
        o->oFloatF8 -= 0.02f;
        cur_obj_scale(o->oFloatF8);
        if (o->oFloatF8 < 0.03f) {
            o->activeFlags = 0;
        }
    } else {
        o->oFloatF8 = approach_f32_symmetric(o->oFloatF8, 0.16f, 0.02f);
        cur_obj_scale(o->oFloatF8);  
    }
}


void bhv_dizzy_particle_spawn_init(void) {
    o->oObjF4 = spawn_object(o, MODEL_CARTOON_STAR, bhvDizzyTriangle);
    o->oObjF4->parentObj = o;
    o->oObjF8 = spawn_object(o, MODEL_CARTOON_STAR, bhvDizzyTriangle);
    o->oObjF8->parentObj = o;
    o->oObjF8->os16F4 = 0x5555;
    o->oObjFC = spawn_object(o, MODEL_CARTOON_STAR, bhvDizzyTriangle);
    o->oObjFC->parentObj = o;
    o->oObjFC->os16F4 = 0xAAAA;
}



void bhv_dizzy_particle_spawn_loop(void) {
    if (!(gMarioState->particleFlags & PARTICLE_DIZZY)) {
        o->activeFlags = 0;
        clear_particle_flags(ACTIVE_PARTICLE_DIZZY);
    }
}


void bhv_gp_white_puffs_init(void) {
    clear_particle_flags(ACTIVE_PARTICLE_GP_MIST_CIRCLE);
    cur_obj_spawn_particles(&sGPMistParticles);
}



void bhv_pound_white_puffs_init(void) {
    clear_particle_flags(ACTIVE_PARTICLE_MIST_CIRCLE);
    spawn_mist_from_global();
}





static struct SpawnParticlesInfo sGlobalMistParticles = {
    /* behParam:        */ 3,
    /* count:           */ 20,
    /* model:           */ MODEL_MIST,
    /* offsetY:         */ 20,
    /* forwardVelBase:  */ 10,
    /* forwardVelRange: */ 5,
    /* velYBase:        */ 0,
    /* velYRange:       */ 0,
    /* gravity:         */ 0,
    /* dragStrength:    */ 30,
    /* sizeBase:        */ 30.0f,
    /* sizeRange:       */ 1.5f,
};

void spawn_mist_from_global(void) {
    cur_obj_spawn_particles(&sGlobalMistParticles);
}

static struct SpawnParticlesInfo sSandParticles = {
    /* behParam:        */ 0,
    /* count:           */ 5,
    /* model:           */ MODEL_SAND_DUST,
    /* offsetY:         */ 0,
    /* forwardVelBase:  */ 0,
    /* forwardVelRange: */ 20,
    /* velYBase:        */ 20,
    /* velYRange:       */ 0,
    /* gravity:         */ 252,
    /* dragStrength:    */ 30,
    /* sizeBase:        */ 5.0f,
    /* sizeRange:       */ 2.0f,
};

void bhv_ground_sand_init(void) {
    clear_particle_flags(ACTIVE_PARTICLE_DIRT);
    cur_obj_spawn_particles(&sSandParticles);
}

static s16 sSmokeMovementParams[] = { 2, -8, 1, 4 };

void spawn_smoke_with_velocity(void) {
    struct Object *smoke = spawn_object_with_scale(o, MODEL_SMOKE, bhvWhitePuffSmoke2, 1.0f);

    smoke->oForwardVel = sSmokeMovementParams[0];
    smoke->oVelY = sSmokeMovementParams[1];
    smoke->oGravity = sSmokeMovementParams[2];

    obj_translate_xyz_random(smoke, sSmokeMovementParams[3]);
}

// TODO Fix name
void clear_particle_flags(u32 flags) {
    o->parentObj->oActiveParticleFlags &= flags ^ 0xFFFFFFFF; // Clear the flags given (could just be ~flags)
}

static struct SpawnParticlesInfo sSnowParticles = {
    /* behParam:        */ 0,
    /* count:           */ 5,
    /* model:           */ MODEL_WHITE_PARTICLE_DL,
    /* offsetY:         */ 0,
    /* forwardVelBase:  */ 0,
    /* forwardVelRange: */ 20,
    /* velYBase:        */ 20,
    /* velYRange:       */ 0,
    /* gravity:         */ 252,
    /* dragStrength:    */ 30,
    /* sizeBase:        */ 2.0f,
    /* sizeRange:       */ 2.0f,
};

void bhv_ground_snow_init(void) {
    clear_particle_flags(ACTIVE_PARTICLE_SNOW);
    cur_obj_spawn_particles(&sSnowParticles);
}
