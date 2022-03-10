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