#include <PR/ultratypes.h>

#include "types.h"
#include "actors/common1.h"
#include "actors/group12.h"
#include "actors/group13.h"
#include "game/area.h"
#include "audio/external.h"
#include "behaviors/behavior_actions.h"
#include "behavior_data.h"
#include "game/camera.h"
#include "game/sm_debug.h"
#include "dialog_ids.h"
#include "engine/behavior_script.h"
#include "engine/graph_node.h"
#include "engine/math_util.h"
#include "engine/surface_collision.h"
#include "engine/surface_load.h"
#include "game/game_init.h"
#include "game/ingame_menu.h"
#include "game/interaction.h"
#include "level_misc_macros.h"
#include "level_table.h"
#include "game/level_update.h"
#include "levels/bob/header.h"
#include "levels/bowser_3/header.h"
#include "levels/castle_inside/header.h"
#include "levels/hmc/header.h"
#include "game/main.h"
#include "game/mario.h"
#include "game/mario_actions_cutscene.h"
#include "game/mario_step.h"
#include "game/obj_behaviors.h"
#include "game/obj_behaviors_2.h"
#include "object_constants.h"
#include "game/object_helpers.h"
#include "game/object_list_processor.h"
#include "game/paintings.h"
#include "game/platform_displacement.h"
#include "game/rendering_graph_node.h"
#include "game/save_file.h"
#include "seq_ids.h"
#include "sm64.h"
#include "game/spawn_object.h"
#include "game/spawn_sound.h"
#include "game/rumble_init.h"

#define o gCurrentObject


#include "game/object_list_processor.h"
#define o gCurrentObject
#include "include/object_constants.h"
#include "include/object_fields.h"
#include "include/types.h"

struct Struct8032F698 {
    void *unk0;
    s16 unk1;
    s16 unk2;
    s16 unk3;
    s16 unk4;
};


static s32 sCapSaveFlags[] = { SAVE_FLAG_HAVE_WING_CAP, SAVE_FLAG_HAVE_METAL_CAP, SAVE_FLAG_HAVE_VANISH_CAP };

// Boo Roll
static s16 sBooHitRotations[] = { 6047, 5664, 5292, 4934, 4587, 4254, 3933, 3624, 3329, 3046, 2775,
                     2517, 2271, 2039, 1818, 1611, 1416, 1233, 1063, 906,  761,  629,
                     509,  402,  308,  226,  157,  100,  56,   25,   4,    0 };
#include "game/behaviors/star_door.inc.c"
#include "game/behaviors/mr_i.inc.c"
#include "game/behaviors/pole.inc.c"
#include "game/behaviors/thi_top.inc.c"
#include "game/behaviors/capswitch.inc.c"
#include "game/behaviors/king_bobomb.inc.c"
#include "game/behaviors/beta_chest.inc.c"
#include "game/behaviors/water_objs.inc.c"
#include "game/behaviors/cannon.inc.c"
#include "game/behaviors/chuckya.inc.c"
#include "game/behaviors/breakable_wall.inc.c"
#include "game/behaviors/kickable_board.inc.c"
#include "game/behaviors/tower_door.inc.c"
#include "game/behaviors/rotating_platform.inc.c"
#include "game/behaviors/koopa_shell_underwater.inc.c"
#include "game/behaviors/warp.inc.c"
#include "game/behaviors/white_puff_explode.inc.c"

// not in behavior file
struct SpawnParticlesInfo sMistParticles = { 2, 20, MODEL_MIST, 0, 40, 5, 30, 20, 252, 30, 330.0f, 10.0f };

// generate_wind_puffs/dust (something like that)
void spawn_mist_particles_variable(s32 count, s32 offsetY, f32 size) {
    sMistParticles.sizeBase = size;
    sMistParticles.sizeRange = size / 20.0;
    sMistParticles.offsetY = offsetY;
    if (count == 0) {
        sMistParticles.count = 20;
    } else if (count > 20) {
        sMistParticles.count = count;
    } else {
        sMistParticles.count = 4;
    }
    cur_obj_spawn_particles(&sMistParticles);
}

#include "game/behaviors/sparkle_spawn_star.inc.c"
#include "game/behaviors/coin.inc.c"
#include "game/behaviors/collide_particles.inc.c"
#include "game/behaviors/door.inc.c"
#include "game/behaviors/thwomp.inc.c"
#include "game/behaviors/tumbling_bridge.inc.c"
#include "game/behaviors/elevator.inc.c"
#include "game/behaviors/water_mist_particle.inc.c"
#include "game/behaviors/break_particles.inc.c"
#include "game/behaviors/water_mist.inc.c"
#include "game/behaviors/ground_particles.inc.c"
#include "game/behaviors/wind.inc.c"
#include "game/behaviors/unused_particle_spawn.inc.c"
#include "game/behaviors/ukiki_cage.inc.c"
#include "game/behaviors/falling_rising_platform.inc.c"
#include "game/behaviors/fishing_boo.inc.c"
#include "game/behaviors/flamethrower.inc.c"
#include "game/behaviors/bouncing_fireball.inc.c"
#include "game/behaviors/shock_wave.inc.c"
#include "game/behaviors/flame_mario.inc.c"
#include "game/behaviors/beta_fish_splash_spawner.inc.c"
#include "game/behaviors/spindrift.inc.c"
#include "game/behaviors/tower_platform.inc.c"
#include "game/behaviors/tree_particles.inc.c"
#include "game/behaviors/square_platform_cycle.inc.c"
#include "game/behaviors/piranha_bubbles.inc.c"
#include "game/behaviors/purple_switch.inc.c"
#include "game/behaviors/metal_box.inc.c"
#include "game/behaviors/switch_hidden_objects.inc.c"
#include "game/behaviors/breakable_box.inc.c"

// not sure what this is doing here. not in a behavior file.
Gfx *geo_move_mario_part_from_parent(s32 run, UNUSED struct GraphNode *node, Mat4 mtx) {
    Mat4 sp20;
    struct Object *sp1C;

    if (run == TRUE) {
        sp1C = (struct Object *) gCurGraphNodeObject;
        if (sp1C == gMarioObject && sp1C->prevObj != NULL) {
            create_transformation_from_matrices(sp20, mtx, *gCurGraphNodeCamera->matrixPtr);
            obj_update_pos_from_parent_transformation(sp20, sp1C->prevObj);
            obj_set_gfx_pos_from_pos(sp1C->prevObj);
        }
    }
    return NULL;
}

#include "game/behaviors/heave_ho.inc.c"
#include "game/behaviors/spawn_star_exit.inc.c"
#include "game/behaviors/unused_poundable_platform.inc.c"
#include "game/behaviors/beta_trampoline.inc.c"
#include "game/behaviors/jumping_box.inc.c"

// not in behavior file
// n is the number of objects to spawn, r if the rate of change of phase (frequency?)
void spawn_sparkle_particles(s32 n, s32 a1, s32 a2, s32 r) {
    static s16 D_8035FF10;
    s32 i;
    s16 separation = 0x10000 / n; // Evenly spread around a circle
    for (i = 0; i < n; i++) {
        spawn_object_relative(0, sins(D_8035FF10 + i * separation) * a1, (i + 1) * a2,
                              coss(D_8035FF10 + i * separation) * a1, o, MODEL_NONE, bhvSparkleSpawn);
    }

    D_8035FF10 += r * 0x100;
}

#include "game/behaviors/beta_boo_key.inc.c"
#include "game/behaviors/grand_star.inc.c"
#include "game/behaviors/bowser_key.inc.c"
#include "game/behaviors/bullet_bill.inc.c"
#include "game/behaviors/bowser.inc.c"
#include "game/behaviors/bowser_falling_platform.inc.c"
#include "game/behaviors/bowser_flame.inc.c"
#include "game/behaviors/blue_fish.inc.c"

// Not in behavior file, duplicate of vec3f_copy except without bad return.
// Used in a few behavior files.
void vec3f_copy_2(Vec3f dest, Vec3f src) {
    dest[0] = src[0];
    dest[1] = src[1];
    dest[2] = src[2];
}

#include "game/behaviors/checkerboard_platform.inc.c"
#include "game/behaviors/ddd_warp.inc.c"
#include "game/behaviors/water_pillar.inc.c"
#include "game/behaviors/moat_drainer.inc.c"
#include "game/behaviors/bowser_key_cutscene.inc.c"
#include "game/behaviors/moat_grill.inc.c"
#include "game/behaviors/clock_arm.inc.c"
#include "game/behaviors/ukiki.inc.c"
#include "game/behaviors/lll_octagonal_rotating_mesh.inc.c"
#include "game/behaviors/lll_sinking_rock_block.inc.c"
#include "game/behaviors/lll_rotating_hex_flame.inc.c"
#include "game/behaviors/lll_floating_wood_piece.inc.c"
#include "game/behaviors/lll_volcano_flames.inc.c"
#include "game/behaviors/lll_hexagonal_ring.inc.c"
#include "game/behaviors/lll_sinking_rectangle.inc.c"
#include "game/behaviors/tilting_inverted_pyramid.inc.c"
#include "game/behaviors/koopa_shell.inc.c"
#include "game/behaviors/tox_box.inc.c"
#include "game/behaviors/piranha_plant.inc.c"
#include "game/behaviors/bowser_puzzle_piece.inc.c"

s32 set_obj_anim_with_accel_and_sound(s16 a0, s16 a1, s32 a2) {
    f32 sp1C;
    if ((sp1C = o->header.gfx.animInfo.animAccel / (f32) 0x10000) == 0)
        sp1C = 1.0f;
    if (cur_obj_check_anim_frame_in_range(a0, sp1C) || cur_obj_check_anim_frame_in_range(a1, sp1C)) {
        cur_obj_play_sound_2(a2);
        return 1;
    }
    return 0;
}

#include "game/behaviors/tuxie.inc.c"
#include "game/behaviors/fish.inc.c"
#include "game/behaviors/express_elevator.inc.c"
#include "game/behaviors/bub.inc.c"
#include "game/behaviors/exclamation_box.inc.c"
#include "game/behaviors/sound_spawner.inc.c"
#include "game/behaviors/ddd_sub.inc.c"
#include "game/behaviors/sushi.inc.c"
#include "game/behaviors/jrb_ship.inc.c"
#include "game/behaviors/white_puff.inc.c"
#include "game/behaviors/blue_coin.inc.c"
#include "game/behaviors/grill_door.inc.c"
#include "game/behaviors/wdw_water_level.inc.c"
#include "game/behaviors/tweester.inc.c"
#include "game/behaviors/boo.inc.c"
#include "game/behaviors/bbh_tilting_trap.inc.c"
#include "game/behaviors/bbh_haunted_bookshelf.inc.c"
#include "game/behaviors/bbh_merry_go_round.inc.c"
#include "game/behaviors/static_checkered_platform.inc.c"
#include "game/behaviors/beta_bowser_anchor.inc.c"
#ifndef VERSION_JP
#include "game/behaviors/music_touch.inc.c"
#endif
#include "game/behaviors/castle_floor_trap.inc.c"
#include "game/behaviors/pole_base.inc.c"
#include "game/behaviors/sparkle_spawn.inc.c"
#include "game/behaviors/scuttlebug.inc.c" // :scuttleeyes:
#include "game/behaviors/whomp.inc.c"
#include "game/behaviors/water_splashes_and_waves.inc.c"
#include "game/behaviors/strong_wind_particle.inc.c"
#include "game/behaviors/sl_snowman_wind.inc.c"
#include "game/behaviors/sl_walking_penguin.inc.c"
#include "game/behaviors/sinking_plat.inc.c"
#include "game/behaviors/chandelier.inc.c"
#include "game/behaviors/dining_room.inc.c"
#include "game/behaviors/new_boo.inc.c"
#include "game/behaviors/gates.inc.c"
#include "game/behaviors/books.inc.c"
#include "game/behaviors/kitchen.inc.c"
#include "game/behaviors/living_room.inc.c"
#include "game/behaviors/study_room.inc.c"
#include "game/behaviors/library.inc.c"
#include "game/behaviors/mm_engine_bhv.inc.c"
#include "game/behaviors/lounge.inc.c"
#include "game/behaviors/balcony.inc.c"
#include "game/behaviors/bathroom.inc.c"
#include "game/behaviors/mirror_room.inc.c"
#include "game/behaviors/outside.inc.c"
#include "game/behaviors/bedroom.inc.c"
#include "game/behaviors/servants_quarters.inc.c"
#include "game/behaviors/master_bedroom.inc.c"
#include "game/behaviors/city_level.inc.c"
#include "game/behaviors/play_level.inc.c"
#include "game/behaviors/game_room.inc.c"
#include "game/behaviors/trophy_room.inc.c"
#include "game/behaviors/music_room.inc.c"
#include "game/behaviors/treehouse.inc.c"
#include "game/behaviors/theater.inc.c"
#include "game/behaviors/platforming_hall.inc.c"
#include "game/behaviors/sauna.inc.c"
