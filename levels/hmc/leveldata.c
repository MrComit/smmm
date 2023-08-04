#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "level_misc_macros.h"
#include "macro_preset_names.h"
#include "special_preset_names.h"
#include "textures.h"
#include "dialog_ids.h"

#include "make_const_nonconst.h"
#include "levels/hmc/texture.inc.c"
#include "levels/hmc/areas/1/1/model.inc.c"
#include "levels/hmc/areas/1/2/model.inc.c"
#include "levels/hmc/areas/1/3/model.inc.c"
#include "levels/hmc/areas/1/4/model.inc.c"
#include "levels/hmc/areas/1/5/model.inc.c"
#include "levels/hmc/areas/1/6/model.inc.c"
#include "levels/hmc/areas/1/7/model.inc.c"
#include "levels/hmc/areas/1/8/model.inc.c"
#include "levels/hmc/areas/1/9/model.inc.c"
#include "levels/hmc/areas/1/10/model.inc.c"
#include "levels/hmc/areas/1/11/model.inc.c"
#include "levels/hmc/areas/1/12/model.inc.c"
#include "levels/hmc/areas/1/13/model.inc.c"
#include "levels/hmc/areas/1/14/model.inc.c"
#include "levels/hmc/areas/1/15/model.inc.c"
#include "levels/hmc/areas/1/16/model.inc.c"
#include "levels/hmc/areas/1/17/model.inc.c"
#include "levels/hmc/areas/1/18/model.inc.c"
#include "levels/hmc/areas/1/19/model.inc.c"
#include "levels/hmc/areas/1/20/model.inc.c"
#include "levels/hmc/areas/1/21/model.inc.c"
#include "levels/hmc/areas/1/22/model.inc.c"
#include "levels/hmc/areas/1/23/model.inc.c"
#include "levels/hmc/areas/1/24/model.inc.c"
#include "levels/hmc/areas/1/25/model.inc.c"
#include "levels/hmc/areas/1/26/model.inc.c"
#include "levels/hmc/areas/1/27/model.inc.c"
#include "levels/hmc/areas/1/28/model.inc.c"
#include "levels/hmc/areas/1/grill_door/model.inc.c"
#include "levels/hmc/areas/1/29/model.inc.c"
#include "levels/hmc/areas/1/30/model.inc.c"
#include "levels/hmc/areas/1/31/model.inc.c"
#include "levels/hmc/areas/1/32/model.inc.c"
#include "levels/hmc/elevator_platform/model.inc.c"
#include "levels/hmc/arrow_platform/model.inc.c"
#include "levels/hmc/arrow_platform_button/model.inc.c"
#include "levels/hmc/rolling_rock/model.inc.c"
#include "levels/hmc/rolling_rock_fragment_1/model.inc.c"
#include "levels/hmc/rolling_rock_fragment_2/model.inc.c"
#include "levels/hmc/areas/1/painting.inc.c"
#include "levels/hmc/areas/1/collision.inc.c"
#include "levels/hmc/areas/1/macro.inc.c"
#include "levels/hmc/areas/1/room.inc.c"
#include "levels/hmc/elevator_platform/collision.inc.c"
#include "levels/hmc/areas/1/grill_door/collision.inc.c" // This is odd, but the model data for this is in the middle of area 1. I have to conclude it is an area local object, despite the fact it has collision. Let's hope this is the only oddity...
#include "levels/hmc/arrow_platform/collision.inc.c"
#include "levels/hmc/arrow_platform_button/collision.inc.c"
#include "levels/hmc/areas/1/trajectory.inc.c"
#include "levels/hmc/areas/1/movtext.inc.c"

#include "levels/hmc/leveldata.inc.c"

#include "levels/hmc/dice_enemy/model.inc.c"
#include "levels/hmc/dice_enemy/anims/data.inc.c"
#include "levels/hmc/dice_enemy/anims/table.inc.c"
#include "levels/hmc/pool_ball/model.inc.c"
#include "levels/hmc/pool_cue/model.inc.c"
#include "levels/hmc/pool_barrier/model.inc.c"
#include "levels/hmc/pool_barrier/collision.inc.c"
#include "levels/hmc/pool_floor/model.inc.c"
#include "levels/hmc/pool_floor/collision.inc.c"
#include "levels/hmc/toy_mole/model.inc.c"
#include "levels/hmc/toy_mole/collision.inc.c"
#include "levels/hmc/mole_cage/model.inc.c"
#include "levels/hmc/mole_cage/collision.inc.c"
#include "levels/hmc/pingpong_ball/model.inc.c"
#include "levels/hmc/pingpong_paddle/model.inc.c"
#include "levels/hmc/trophy_octogon/model.inc.c"
#include "levels/hmc/trophy_octogon/collision.inc.c"
#include "levels/hmc/trophy_rectangle/model.inc.c"
#include "levels/hmc/trophy_rectangle/collision.inc.c"
#include "levels/hmc/music_insts/model.inc.c"
#include "levels/hmc/violin_col/collision.inc.c"
#include "levels/hmc/drums_col/collision.inc.c"
#include "levels/hmc/piano_col/collision.inc.c"
#include "levels/hmc/guitar_col/collision.inc.c"
#include "levels/hmc/foreroom_object/model.inc.c"
#include "levels/hmc/foreroom_chair/collision.inc.c"
#include "levels/hmc/foreroom_books/collision.inc.c"
#include "levels/hmc/foreroom_plant/collision.inc.c"
#include "levels/hmc/foreroom_table/collision.inc.c"
#include "levels/hmc/foreroom_vase/collision.inc.c"
#include "levels/hmc/foreroom_lever/model.inc.c"
#include "levels/hmc/foreroom_lever/anims/data.inc.c"
#include "levels/hmc/foreroom_lever/anims/table.inc.c"
#include "levels/hmc/foreroom_lever/collision.inc.c"
#include "levels/hmc/foreroom_wall/collision.inc.c"
#include "levels/hmc/foreroom_window/model.inc.c"
#include "levels/hmc/foreroom_window/collision.inc.c"
#include "levels/hmc/tight_rope/model.inc.c"
#include "levels/hmc/tight_rope/collision.inc.c"
#include "levels/hmc/tree_limb/model.inc.c"
#include "levels/hmc/tree_limb/anims/data.inc.c"
#include "levels/hmc/tree_limb/anims/table.inc.c"
#include "levels/hmc/tree_limb/collision.inc.c"
#include "levels/hmc/blue_owl/model.inc.c"
#include "levels/hmc/blue_owl/anims/data.inc.c"
#include "levels/hmc/blue_owl/anims/table.inc.c"
#include "levels/hmc/theater_screen/model.inc.c"
#include "levels/hmc/theater_screen/collision.inc.c"
#include "levels/hmc/goomba_2d/model.inc.c"
#include "levels/hmc/koopa_2d/model.inc.c"
#include "levels/hmc/bulletbill_2d/model.inc.c"
#include "levels/hmc/theater_arena/model.inc.c"
#include "levels/hmc/theater_arena1/collision.inc.c"
#include "levels/hmc/theater_arena2/collision.inc.c"
#include "levels/hmc/theater_arena3/collision.inc.c"
#include "levels/hmc/boom_boom_2d/model.inc.c"
#include "levels/hmc/theater_tomato/model.inc.c"
#include "levels/hmc/treehouse_log/model.inc.c"
#include "levels/hmc/treehouse_spike/model.inc.c"
#include "levels/hmc/treehouse_spike/anims/data.inc.c"
#include "levels/hmc/treehouse_spike/anims/table.inc.c"
#include "levels/hmc/cushion_friend/model.inc.c"
#include "levels/hmc/cushion_friend/collision.inc.c"
#include "levels/hmc/static_tri/model.inc.c"
#include "levels/hmc/static_tri/collision.inc.c"
#include "levels/hmc/static_wall/collision.inc.c"
#include "levels/hmc/static_wall/model.inc.c"
#include "levels/hmc/vase_throw/model.inc.c"
#include "levels/hmc/sauna_grate/model.inc.c"
#include "levels/hmc/sauna_grate/collision.inc.c"
#include "levels/hmc/bully_gate/model.inc.c"
#include "levels/hmc/bully_gate/collision.inc.c"
#include "levels/hmc/sauna_rock_rise/model.inc.c"
#include "levels/hmc/sauna_rock_rise/collision.inc.c"
#include "levels/hmc/fan_blades/model.inc.c"
#include "levels/hmc/fan_blades/collision.inc.c"
#include "levels/hmc/attic_grate/model.inc.c"
#include "levels/hmc/attic_grate/collision.inc.c"
#include "levels/hmc/attic_spire/model.inc.c"
#include "levels/hmc/attic_rock/model.inc.c"
#include "levels/hmc/attic_rock/collision.inc.c"
#include "levels/hmc/attic_bully/model.inc.c"
#include "levels/hmc/attic_spike/model.inc.c"
#include "levels/hmc/attic_spike/collision.inc.c"
#include "levels/hmc/attic_indicator/model.inc.c"
#include "levels/hmc/attic_wall/model.inc.c"
#include "levels/hmc/attic_wall/collision.inc.c"
#include "levels/hmc/music_barrier/model.inc.c"
#include "levels/hmc/music_barrier/collision.inc.c"
#include "levels/hmc/music_peepa/model.inc.c"
#include "levels/hmc/opening_wall/model.inc.c"
#include "levels/hmc/bully_trophy/model.inc.c"
#include "levels/hmc/bully_trophy/collision.inc.c"
#include "levels/hmc/trophy_elevator/model.inc.c"
#include "levels/hmc/trophy_elevator/collision.inc.c"
#include "levels/hmc/plat_hall_wall/model.inc.c"
#include "levels/hmc/map_l6/model.inc.c"
#include "levels/hmc/red_vase/model.inc.c"
#include "levels/hmc/red_vase/collision.inc.c"
#include "levels/hmc/l6_2d_red/model.inc.c"
#include "levels/hmc/l6_2d_red/collision.inc.c"