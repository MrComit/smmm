#ifndef JRB_HEADER_H
#define JRB_HEADER_H

#include "types.h"
#include "game/moving_texture.h"

// geo
extern const GeoLayout jrb_geo_000900[];
extern const GeoLayout jrb_geo_000918[];
extern const GeoLayout jrb_geo_000930[];
extern const GeoLayout jrb_geo_000948[];
extern const GeoLayout jrb_geo_000960[];
extern const GeoLayout jrb_geo_000978[];
extern const GeoLayout jrb_geo_000990[];
extern const GeoLayout jrb_geo_0009B0[];
extern const GeoLayout jrb_geo_0009C8[];
extern const GeoLayout jrb_geo_0009E8[];
extern const GeoLayout jrb_geo_000A00[];
extern const GeoLayout jrb_geo_000A18[];
extern const GeoLayout jrb_geo_000AFC[];

// leveldata
extern const Gfx jrb_seg7_dl_07002FD0[];
extern const Gfx jrb_seg7_dl_07004940[];
extern const Gfx jrb_seg7_dl_07004C78[];
extern const Gfx jrb_seg7_dl_070058C8[];
extern const Gfx jrb_seg7_dl_070069B0[];
extern const Gfx jrb_seg7_dl_07007570[];
extern const Gfx jrb_seg7_dl_07007718[];
extern const Gfx jrb_seg7_dl_07007AC8[];
extern const Gfx jrb_seg7_dl_07007DC8[];
extern const Gfx jrb_seg7_dl_070080F8[];
extern const Gfx jrb_seg7_dl_07008FD8[];
extern const Gfx jrb_seg7_dl_070090B0[];
extern const Gfx jrb_seg7_dl_07009A58[];
extern const Gfx jrb_seg7_dl_07009B30[];
extern const Gfx jrb_seg7_dl_0700A608[];
extern const Gfx jrb_seg7_dl_0700AC68[];
extern const Gfx jrb_seg7_dl_0700AE48[];
extern const Gfx jrb_seg7_dl_0700AFB0[];
extern const Collision jrb_seg7_area_1_collision[];
extern const MacroObject jrb_seg7_area_1_macro_objs[];
extern const Collision jrb_seg7_collision_rock_solid[];
extern const Collision jrb_seg7_collision_floating_platform[];
extern const Collision jrb_seg7_collision_floating_box[];
extern const Collision jrb_seg7_collision_in_sunken_ship_3[];
extern const Collision jrb_seg7_collision_in_sunken_ship[];
extern const Collision jrb_seg7_collision_0700CEF0[];
extern const Collision jrb_seg7_collision_in_sunken_ship_2[];
extern const Collision jrb_seg7_collision_pillar_base[];
extern const Collision jrb_seg7_collision_0700D1DC[];
extern const Trajectory jrb_seg7_trajectory_unagi_1[];
extern const Trajectory jrb_seg7_trajectory_unagi_2[];
extern const struct MovtexQuadCollection jrb_movtex_water[];
extern const struct MovtexQuadCollection jrb_movtex_initial_mist[];
extern const Gfx jrb_seg7_dl_0700EF00[];
extern const Gfx jrb_seg7_dl_0700FE48[];
extern const Gfx jrb_seg7_dl_07010548[];
extern const Collision jrb_seg7_area_2_collision[];
extern const MacroObject jrb_seg7_area_2_macro_objs[];
extern const struct MovtexQuadCollection jrb_movtex_sunken_ship_water[];

// script
extern const LevelScript level_jrb_entry[];

#include "levels/jrb/header.inc.h"

#include "levels/jrb/sunflower/geo_header.h"

#include "levels/jrb/sunflower/anim_header.h"

#include "levels/jrb/dirt_mound/collision_header.h"

#include "levels/jrb/dirt_mound/geo_header.h"

#include "levels/jrb/bounce_box/geo_header.h"

#include "levels/jrb/bounce_box/collision_header.h"

#include "levels/jrb/poochy/geo_header.h"

#include "levels/jrb/garden_holes/collision_header.h"

#include "levels/jrb/flower_wall/geo_header.h"

#include "levels/jrb/flower_wall/collision_header.h"

#include "levels/jrb/l3_sun/geo_header.h"

#include "levels/jrb/l3_sun/anim_header.h"

#include "levels/jrb/sunblock/geo_header.h"

#include "levels/jrb/sunblock/collision_header.h"

#include "levels/jrb/dark_piranha/geo_header.h"

#include "levels/jrb/standing_sunflower/geo_header.h"

#include "levels/jrb/sunflower_pellet/geo_header.h"

#include "levels/jrb/sunblock_big/collision_header.h"

#include "levels/jrb/sunblock_big/geo_header.h"

#include "levels/jrb/garden_gate_alt/collision_header.h"

#include "levels/jrb/garden_gate/geo_header.h"

#include "levels/jrb/exit_wall/geo_header.h"

#include "levels/jrb/poochy/anim_header.h"

#include "levels/jrb/garden_holes/geo_header.h"

#include "levels/jrb/bucket_top/geo_header.h"

#include "levels/jrb/bucket_top/collision_header.h"

#include "levels/jrb/map_l3/geo_header.h"

#endif
