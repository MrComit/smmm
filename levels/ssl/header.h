#ifndef SSL_HEADER_H
#define SSL_HEADER_H

#include "types.h"
#include "game/moving_texture.h"

// geo
extern const GeoLayout ssl_geo_0005C0[];
extern const GeoLayout ssl_geo_0005D8[];
extern const GeoLayout ssl_geo_000618[];
extern const GeoLayout ssl_geo_000630[];
extern const GeoLayout ssl_geo_000648[];
extern const GeoLayout ssl_geo_000734[];
extern const GeoLayout ssl_geo_000764[];
extern const GeoLayout ssl_geo_000794[];
extern const GeoLayout ssl_geo_0007AC[];
extern const GeoLayout ssl_geo_0007CC[];
extern const GeoLayout ssl_geo_00088C[];

// leveldata
extern const u8 ssl_pyramid_sand[];
extern const u8 ssl_quicksand[];
extern const Gfx ssl_dl_quicksand_pit_begin[];
extern const Gfx ssl_dl_quicksand_pit_end[];
extern const Gfx ssl_dl_pyramid_quicksand_pit_begin[];
extern const Gfx ssl_dl_pyramid_quicksand_pit_end[];
extern Movtex ssl_movtex_tris_quicksand_pit[];
extern Movtex ssl_movtex_tris_pyramid_quicksand_pit[];
extern const Gfx ssl_dl_quicksand_pit[];
extern const Gfx ssl_dl_pyramid_quicksand_pit_static[];
extern const Gfx ssl_seg7_dl_07009F48[];
extern const Gfx ssl_seg7_dl_0700BA78[];
extern const Gfx ssl_seg7_dl_0700BC18[];
extern const Gfx ssl_seg7_dl_0700BD00[];
extern const Gfx ssl_seg7_dl_0700BF18[];
extern const Gfx ssl_seg7_dl_0700FCE0[];
extern const Collision ssl_seg7_area_1_collision[];
extern const MacroObject ssl_seg7_area_1_macro_objs[];
extern const Collision ssl_seg7_collision_pyramid_top[];
extern const Collision ssl_seg7_collision_tox_box[];
extern const struct MovtexQuadCollection ssl_movtex_puddle_water[];
extern const struct MovtexQuadCollection ssl_movtex_toxbox_quicksand_mist[];
extern const Gfx ssl_dl_quicksand_begin[];
extern const Gfx ssl_dl_quicksand_end[];
extern Movtex ssl_movtex_tris_pyramid_quicksand[];
extern const Gfx ssl_dl_pyramid_quicksand[];
extern Movtex ssl_movtex_tris_pyramid_corners_quicksand[];
extern const Gfx ssl_dl_pyramid_corners_quicksand[];
extern Movtex ssl_movtex_tris_sides_quicksand[];
extern const Gfx ssl_dl_sides_quicksand[];
extern const Gfx ssl_seg7_dl_0701EE80[];
extern const Gfx ssl_seg7_dl_0701F920[];
extern const Gfx ssl_seg7_dl_0701FCE0[];
extern const Gfx ssl_seg7_dl_07021A08[];
extern const Gfx ssl_seg7_dl_07021DE8[];
extern const Gfx ssl_seg7_dl_070220A8[];
extern const Gfx ssl_seg7_dl_070221E8[];
extern const Gfx ssl_seg7_dl_070228A8[];
extern const Gfx ssl_seg7_dl_070229E8[];
extern const Gfx ssl_seg7_dl_07022CF8[];
extern const Gfx ssl_seg7_dl_070233A8[];
extern const Gfx ssl_seg7_dl_070235C0[];
extern const Collision ssl_seg7_area_2_collision[];
extern const Collision ssl_seg7_area_3_collision[];
extern const MacroObject ssl_seg7_area_2_macro_objs[];
extern const MacroObject ssl_seg7_area_3_macro_objs[];
extern const Collision ssl_seg7_collision_grindel[];
extern const Collision ssl_seg7_collision_spindel[];
extern const Collision ssl_seg7_collision_0702808C[];
extern const Collision ssl_seg7_collision_pyramid_elevator[];
extern const Collision ssl_seg7_collision_07028274[];
extern const Collision ssl_seg7_collision_070282F8[];
extern const Collision ssl_seg7_collision_07028370[];
extern const Collision ssl_seg7_collision_070284B0[];
extern const Gfx ssl_dl_pyramid_sand_pathway_floor_begin[];
extern const Gfx ssl_dl_pyramid_sand_pathway_floor_end[];
extern const Gfx ssl_dl_pyramid_sand_pathway_begin[];
extern const Gfx ssl_dl_pyramid_sand_pathway_end[];
extern Movtex ssl_movtex_tris_pyramid_sand_pathway_front[];
extern const Gfx ssl_dl_pyramid_sand_pathway_front_end[];
extern Movtex ssl_movtex_tris_pyramid_sand_pathway_floor[];
extern Movtex ssl_movtex_tris_pyramid_sand_pathway_side[];
extern const Gfx ssl_dl_pyramid_sand_pathway_side_end[];

// script
extern const LevelScript level_ssl_entry[];


#include "levels/ssl/header.inc.h"

#include "levels/ssl/painting_enemy/geo_header.h"

#include "levels/ssl/painting_enemy/collision_header.h"

#include "levels/ssl/boogoo_goomba/geo_header.h"

#include "levels/ssl/boogoo_koopa/geo_header.h"

#include "levels/ssl/boogoo_shyguy/geo_header.h"

#include "levels/ssl/paintbrush/geo_header.h"

#include "levels/ssl/painting_brick/geo_header.h"

#include "levels/ssl/painting_brick/collision_header.h"

#include "levels/ssl/cage_goo/geo_header.h"

#include "levels/ssl/ag_boogoo/collision_header.h"

#include "levels/ssl/ag_boogoo/geo_header.h"

#include "levels/ssl/bg_asteroid/geo_header.h"

#include "levels/ssl/bg_asteroid/collision_header.h"

#include "levels/ssl/o2_boogoo/geo_header.h"

#include "levels/ssl/o2_boogoo/collision_header.h"

#include "levels/ssl/spinning_plat/geo_header.h"

#include "levels/ssl/spinning_plat/collision_header.h"

#include "levels/ssl/big_spinning_plat/geo_header.h"

#include "levels/ssl/big_spinning_plat/collision_header.h"

#include "levels/ssl/antenna_ball/geo_header.h"

#include "levels/ssl/suncube/geo_header.h"

#include "levels/ssl/lab_bg/geo_header.h"

#include "levels/ssl/lab_bg/collision_header.h"

#include "levels/ssl/o1_bg/geo_header.h"

#include "levels/ssl/o1_bg/collision_header.h"

#include "levels/ssl/mind_mound/geo_header.h"

#include "levels/ssl/mind_mound/collision_header.h"

#include "levels/ssl/mind_mound_block/collision_header.h"

#include "levels/ssl/mind_mound_block/geo_header.h"

#include "levels/ssl/mind_mips/geo_header.h"

#include "levels/ssl/l8_locked_cage/geo_header.h"

#include "levels/ssl/l8_locked_cage/collision_header.h"

#include "levels/ssl/mind_lever/collision_header.h"

#include "levels/ssl/mind_lever/geo_header.h"

#include "levels/ssl/mind_lever/anim_header.h"

#include "levels/ssl/mp_boogoo/geo_header.h"

#include "levels/ssl/mp_boogoo/collision_header.h"

#include "levels/ssl/mind_2d_goomba/geo_header.h"

#include "levels/ssl/mind_2d_gate/geo_header.h"

#include "levels/ssl/mind_2d_gate/collision_header.h"

#include "levels/ssl/mind_button/geo_header.h"

#include "levels/ssl/mind_button/collision_header.h"

#include "levels/ssl/maze_wins/geo_header.h"

#include "levels/ssl/yoshi_head/geo_header.h"

#include "levels/ssl/observatory_splat/collision_header.h"

#include "levels/ssl/observatory_splat/geo_header.h"

#include "levels/ssl/jenga_plat/collision_header.h"

#include "levels/ssl/jenga_plat/geo_header.h"

#include "levels/ssl/obs_boogoo/geo_header.h"

#include "levels/ssl/obs_boogoo/collision_header.h"

#include "levels/ssl/red_shadow/geo_header.h"

#include "levels/ssl/mem_plate/geo_header.h"

#include "levels/ssl/mem_plate/collision_header.h"

#include "levels/ssl/mem_wall/geo_header.h"

#include "levels/ssl/mem_wall/collision_header.h"

#include "levels/ssl/mem_bounce_box/geo_header.h"

#include "levels/ssl/mem_bounce_box/collision_header.h"

#include "levels/ssl/mem_fall_floor/geo_header.h"

#include "levels/ssl/mem_fall_floor/collision_header.h"

#include "levels/ssl/mem_bath_floor/geo_header.h"

#include "levels/ssl/mem_bath_floor/collision_header.h"

#include "levels/ssl/mem_morning_obj/geo_header.h"

#include "levels/ssl/mem_vase/collision_header.h"

#include "levels/ssl/mem_table/collision_header.h"

#include "levels/ssl/mem_chair/collision_header.h"

#include "levels/ssl/mem_books/collision_header.h"

#include "levels/ssl/mem_icecube/geo_header.h"

#include "levels/ssl/mem_icecube/collision_header.h"

#include "levels/ssl/mem_button/geo_header.h"

#include "levels/ssl/mem_button/collision_header.h"

#include "levels/ssl/mind_chandelier/geo_header.h"


extern const GeoLayout magic_carpet_geo[];
extern const s16 magic_carpet_static_vertex_data[];
extern const Gfx dl_magic_carpet_begin[];
extern const Gfx dl_magic_carpet_model_half[];
extern const Gfx dl_magic_carpet_end[];
extern const Collision magic_carpet_collision[];

#include "levels/ssl/toad_cage/geo_header.h"

#include "levels/ssl/toad_cage/collision_header.h"

#include "levels/ssl/map_l8/geo_header.h"

#endif
