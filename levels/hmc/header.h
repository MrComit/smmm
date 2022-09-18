#ifndef HMC_HEADER_H
#define HMC_HEADER_H

#include "types.h"
#include "game/moving_texture.h"

// geo
extern const GeoLayout hmc_geo_000530[];
extern const GeoLayout hmc_geo_000548[];
extern const GeoLayout hmc_geo_000570[];
extern const GeoLayout hmc_geo_000588[];
extern const GeoLayout hmc_geo_0005A0[];
extern const GeoLayout hmc_geo_0005B8[];
extern const GeoLayout hmc_geo_0005D0[];
extern const GeoLayout hmc_geo_0005E8[];
extern const GeoLayout hmc_geo_000618[];
extern const GeoLayout hmc_geo_000658[];
extern const GeoLayout hmc_geo_0006A8[];
extern const GeoLayout hmc_geo_0006E0[];
extern const GeoLayout hmc_geo_000700[];
extern const GeoLayout hmc_geo_000748[];
extern const GeoLayout hmc_geo_000770[];
extern const GeoLayout hmc_geo_000798[];
extern const GeoLayout hmc_geo_0007F8[];
extern const GeoLayout hmc_geo_000850[];
extern const GeoLayout hmc_geo_0008D0[];
extern const GeoLayout hmc_geo_000938[];
extern const GeoLayout hmc_geo_000998[];
extern const GeoLayout hmc_geo_000A18[];
extern const GeoLayout hmc_geo_000A88[];
extern const GeoLayout hmc_geo_000AE8[];
extern const GeoLayout hmc_geo_000B48[];
extern const GeoLayout hmc_geo_000B90[];

// leveldata
extern const Gfx hmc_seg7_dl_070078B0[];
extern const Gfx hmc_seg7_dl_07007B50[];
extern const Gfx hmc_seg7_dl_070080E8[];
extern const Gfx hmc_seg7_dl_070093F0[];
extern const Gfx hmc_seg7_dl_0700E448[];
extern const Gfx hmc_seg7_dl_0700EF00[];
extern const Gfx hmc_seg7_dl_0700F3E8[];
extern const Gfx hmc_seg7_dl_0700FA40[];
extern const Gfx hmc_seg7_dl_0700FEF0[];
extern const Gfx hmc_seg7_dl_07010070[];
extern const Gfx hmc_seg7_dl_07013CA8[];
extern const Gfx hmc_seg7_dl_07013E80[];
extern const Gfx hmc_seg7_dl_07014300[];
extern const Gfx hmc_seg7_dl_07014B08[];
extern const Gfx hmc_seg7_dl_07014C00[];
extern const Gfx hmc_seg7_dl_07014E48[];
extern const Gfx hmc_seg7_dl_070173A8[];
extern const Gfx hmc_seg7_dl_07017C98[];
extern const Gfx hmc_seg7_dl_07018200[];
extern const Gfx hmc_seg7_dl_07019248[];
extern const Gfx hmc_seg7_dl_07019368[];
extern const Gfx hmc_seg7_dl_0701A080[];
extern const Gfx hmc_seg7_dl_0701A400[];
extern const Gfx hmc_seg7_dl_0701E820[];
extern const Gfx hmc_seg7_dl_0701F1B0[];
extern const Gfx hmc_seg7_dl_0701F690[];
extern const Gfx hmc_seg7_dl_0701F818[];
extern const Gfx hmc_seg7_dl_0701FD58[];
extern const Gfx hmc_seg7_dl_0701FFF8[];
extern const Gfx hmc_seg7_dl_07020FD0[];
extern const Gfx hmc_seg7_dl_07021760[];
extern const Gfx hmc_seg7_dl_07021BA0[];
extern const Gfx hmc_seg7_dl_070228A0[];
extern const Gfx hmc_seg7_dl_07022AA0[];
extern const Gfx hmc_seg7_dl_07022DA0[];
extern const Gfx hmc_seg7_dl_07023090[];
extern const Gfx hmc_seg7_dl_07023BC8[];
extern const Gfx hmc_seg7_dl_07023E10[];
extern const Gfx hmc_seg7_dl_07024110[];
extern const Gfx hmc_seg7_dl_07024268[];
extern const Gfx hmc_seg7_dl_070242A0[];
extern const u8 *const hmc_seg7_painting_textures_07025518[];
extern struct Painting cotmc_painting;
extern const Collision hmc_seg7_collision_level[];
extern const MacroObject hmc_seg7_macro_objs[];
extern const u8 hmc_seg7_rooms[];
extern const Collision hmc_seg7_collision_elevator[];
extern const Collision hmc_seg7_collision_0702B65C[];
extern const Collision hmc_seg7_collision_controllable_platform[];
extern const Collision hmc_seg7_collision_controllable_platform_sub[];
extern const Trajectory hmc_seg7_trajectory_0702B86C[];
extern const struct MovtexQuadCollection hmc_movtex_dorrie_pool_water[];
extern const struct MovtexQuadCollection hmc_movtex_toxic_maze_mist[];

// script
extern const LevelScript level_hmc_entry[];


#include "levels/hmc/header.inc.h"

#include "levels/hmc/dice_enemy/geo_header.h"

#include "levels/hmc/dice_enemy/anim_header.h"

#include "levels/hmc/pool_ball/geo_header.h"

#include "levels/hmc/pool_cue/geo_header.h"

#include "levels/hmc/pool_barrier/geo_header.h"

#include "levels/hmc/pool_barrier/collision_header.h"

#include "levels/hmc/pool_floor/geo_header.h"

#include "levels/hmc/pool_floor/collision_header.h"

#include "levels/hmc/toy_mole/geo_header.h"

#include "levels/hmc/toy_mole/collision_header.h"

#include "levels/hmc/mole_cage/geo_header.h"

#include "levels/hmc/mole_cage/collision_header.h"

#include "levels/hmc/pingpong_ball/geo_header.h"

#include "levels/hmc/pingpong_paddle/geo_header.h"

#include "levels/hmc/trophy_octogon/geo_header.h"

#include "levels/hmc/trophy_octogon/collision_header.h"

#include "levels/hmc/trophy_rectangle/geo_header.h"

#include "levels/hmc/trophy_rectangle/collision_header.h"

#include "levels/hmc/music_insts/geo_header.h"

#include "levels/hmc/violin_col/collision_header.h"

#include "levels/hmc/drums_col/collision_header.h"

#include "levels/hmc/piano_col/collision_header.h"

#include "levels/hmc/guitar_col/collision_header.h"

#include "levels/hmc/foreroom_object/geo_header.h"

#include "levels/hmc/foreroom_chair/collision_header.h"

#include "levels/hmc/foreroom_books/collision_header.h"

#include "levels/hmc/foreroom_plant/collision_header.h"

#include "levels/hmc/foreroom_table/collision_header.h"

#include "levels/hmc/foreroom_vase/collision_header.h"

#include "levels/hmc/foreroom_lever/geo_header.h"

#include "levels/hmc/foreroom_lever/anim_header.h"

#include "levels/hmc/foreroom_lever/collision_header.h"

#include "levels/hmc/foreroom_wall/collision_header.h"

#include "levels/hmc/foreroom_window/geo_header.h"

#include "levels/hmc/foreroom_window/collision_header.h"

#include "levels/hmc/tight_rope/geo_header.h"

#include "levels/hmc/tight_rope/collision_header.h"

#include "levels/hmc/tree_limb/geo_header.h"

#include "levels/hmc/tree_limb/anim_header.h"

#include "levels/hmc/tree_limb/collision_header.h"

#include "levels/hmc/blue_owl/geo_header.h"

#include "levels/hmc/blue_owl/anim_header.h"

#include "levels/hmc/theater_screen/geo_header.h"

#include "levels/hmc/theater_screen/collision_header.h"

#include "levels/hmc/goomba_2d/geo_header.h"

#include "levels/hmc/koopa_2d/geo_header.h"

#include "levels/hmc/bulletbill_2d/geo_header.h"

#include "levels/hmc/theater_arena/geo_header.h"

#include "levels/hmc/theater_arena1/collision_header.h"

#include "levels/hmc/theater_arena2/collision_header.h"

#include "levels/hmc/theater_arena3/collision_header.h"

#include "levels/hmc/boom_boom_2d/geo_header.h"

#include "levels/hmc/theater_tomato/geo_header.h"

#include "levels/hmc/treehouse_log/geo_header.h"

#include "levels/hmc/treehouse_spike/geo_header.h"

#include "levels/hmc/treehouse_spike/anim_header.h"

#include "levels/hmc/cushion_friend/geo_header.h"

#include "levels/hmc/cushion_friend/collision_header.h"

#include "levels/hmc/static_tri/geo_header.h"

#include "levels/hmc/static_tri/collision_header.h"

#include "levels/hmc/static_wall/collision_header.h"

#include "levels/hmc/static_wall/geo_header.h"

#include "levels/hmc/vase_throw/geo_header.h"

#include "levels/hmc/sauna_grate/geo_header.h"

#include "levels/hmc/sauna_grate/collision_header.h"

#include "levels/hmc/bully_gate/geo_header.h"

#include "levels/hmc/bully_gate/collision_header.h"

#include "levels/hmc/sauna_rock_rise/geo_header.h"

#include "levels/hmc/sauna_rock_rise/collision_header.h"

#include "levels/hmc/fan_blades/geo_header.h"

#include "levels/hmc/fan_blades/collision_header.h"

#include "levels/hmc/attic_grate/geo_header.h"

#include "levels/hmc/attic_grate/collision_header.h"

#include "levels/hmc/attic_spire/geo_header.h"

#include "levels/hmc/attic_rock/geo_header.h"

#include "levels/hmc/attic_rock/collision_header.h"

#include "levels/hmc/attic_bully/geo_header.h"

#include "levels/hmc/attic_spike/geo_header.h"

#include "levels/hmc/attic_spike/collision_header.h"

#include "levels/hmc/attic_indicator/geo_header.h"

#include "levels/hmc/attic_wall/geo_header.h"

#include "levels/hmc/attic_wall/collision_header.h"

#include "levels/hmc/music_barrier/geo_header.h"

#include "levels/hmc/music_barrier/collision_header.h"

#include "levels/hmc/music_peepa/geo_header.h"

#include "levels/hmc/opening_wall/geo_header.h"

#include "levels/hmc/bully_trophy/geo_header.h"

#include "levels/hmc/bully_trophy/collision_header.h"

#include "levels/hmc/trophy_elevator/geo_header.h"

#include "levels/hmc/trophy_elevator/collision_header.h"

#endif
