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
#include "levels/lll/texture.inc.c"
#include "levels/lll/areas/1/light.inc.c" // What the hell? Every level up until LLL hasn't needed this. Some models share lights, so we'll assume its a shared area file for level optimization.
#include "levels/lll/areas/1/1/model.inc.c"
#include "levels/lll/areas/1/2/model.inc.c"
#include "levels/lll/areas/1/3/model.inc.c"
#include "levels/lll/areas/1/4/model.inc.c"
#include "levels/lll/areas/1/5/model.inc.c"
#include "levels/lll/areas/1/6/model.inc.c"
#include "levels/lll/areas/1/7/model.inc.c"
#include "levels/lll/areas/1/8/model.inc.c"
#include "levels/lll/areas/1/9/model.inc.c"
#include "levels/lll/areas/1/10/model.inc.c"
#include "levels/lll/areas/1/11/model.inc.c"
#include "levels/lll/areas/1/12/model.inc.c"
#include "levels/lll/areas/1/13/model.inc.c"
#include "levels/lll/areas/1/14/model.inc.c"
#include "levels/lll/areas/1/15/model.inc.c"
#include "levels/lll/moving_octagonal_mesh_platform/model.inc.c"
#include "levels/lll/drawbridge_part/model.inc.c"
#include "levels/lll/rotating_block_fire_bars/model.inc.c"
#include "levels/lll/wooden_float_small/model.inc.c"
#include "levels/lll/wooden_float_large/model.inc.c"
#include "levels/lll/collapsing_wooden_platform/model.inc.c"
#include "levels/lll/long_wooden_bridge/model.inc.c"
#include "levels/lll/rotating_hexagonal_ring/model.inc.c"
#include "levels/lll/sinking_rectangular_platform/model.inc.c"
#include "levels/lll/sinking_square_platform/model.inc.c"
#include "levels/lll/tilting_square_platform/model.inc.c"
#include "levels/lll/puzzle_piece/model.inc.c"
#include "levels/lll/sinking_rock_block/model.inc.c"
#include "levels/lll/rolling_log/model.inc.c"
#include "levels/lll/areas/1/collision.inc.c"
#include "levels/lll/areas/1/macro.inc.c"
#include "levels/lll/moving_octagonal_mesh_platform/collision.inc.c"
#include "levels/lll/drawbridge_part/collision.inc.c"
#include "levels/lll/rotating_block_fire_bars/collision.inc.c"
#include "levels/lll/wooden_float_small/collision.inc.c"
#include "levels/lll/collapsing_wooden_platform/collision.inc.c"
#include "levels/lll/rotating_hexagonal_ring/collision.inc.c"
#include "levels/lll/sinking_rectangular_platform/collision.inc.c"
#include "levels/lll/sinking_square_platform/collision.inc.c"
#include "levels/lll/tilting_square_platform/collision.inc.c"
#include "levels/lll/puzzle_piece/collision.inc.c"
#include "levels/lll/sinking_rock_block/collision.inc.c"
#include "levels/lll/rolling_log/collision.inc.c"
#include "levels/lll/areas/1/10/collision.inc.c"
#include "levels/lll/areas/2/1/model.inc.c"
#include "levels/lll/areas/2/2/model.inc.c"
#include "levels/lll/areas/2/3/model.inc.c"
#include "levels/lll/areas/2/4/model.inc.c"
#include "levels/lll/areas/2/5/model.inc.c"
#include "levels/lll/volcano_falling_trap/model.inc.c"
#include "levels/lll/areas/2/collision.inc.c"
#include "levels/lll/areas/2/macro.inc.c"
#include "levels/lll/volcano_falling_trap/collision.inc.c"
#include "levels/lll/areas/2/trajectory.inc.c"
#include "levels/lll/areas/2/movtext.inc.c"

#include "levels/lll/leveldata.inc.c"

#include "levels/lll/cellar_blockade/model.inc.c"
#include "levels/lll/cellar_blockade/collision.inc.c"
#include "levels/lll/champagne/model.inc.c"
#include "levels/lll/champagne/collision.inc.c"
#include "levels/lll/security_cam/collision.inc.c"
#include "levels/lll/security_cam/model.inc.c"
#include "levels/lll/security_cam/anims/data.inc.c"
#include "levels/lll/security_cam/anims/table.inc.c"
#include "levels/lll/lightbeam/model.inc.c"
#include "levels/lll/basement_switch/model.inc.c"
#include "levels/lll/basement_switch/collision.inc.c"
#include "levels/lll/basement_washer/model.inc.c"
#include "levels/lll/basement_washer/collision.inc.c"
#include "levels/lll/basement_washer/anims/data.inc.c"
#include "levels/lll/basement_washer/anims/table.inc.c"
#include "levels/lll/basement_dryer/model.inc.c"
#include "levels/lll/basement_dryer/anims/data.inc.c"
#include "levels/lll/basement_dryer/anims/table.inc.c"
#include "levels/lll/basement_dryer/collision.inc.c"
#include "levels/lll/basement_dryer2/collision.inc.c"
#include "levels/lll/clothes_ball/model.inc.c"
#include "levels/lll/laundry_bounce_box/model.inc.c"
#include "levels/lll/laundry_bounce_box/collision.inc.c"
#include "levels/lll/dust_bunny/model.inc.c"
#include "levels/lll/laundry_shirts1/model.inc.c"
#include "levels/lll/laundry_shirts2/model.inc.c"
#include "levels/lll/laundry_shirts3/model.inc.c"
#include "levels/lll/laundry_shirts1/collision.inc.c"
#include "levels/lll/laundry_shirts2/collision.inc.c"
#include "levels/lll/laundry_shirts3/collision.inc.c"
#include "levels/lll/gravity_button/model.inc.c"
#include "levels/lll/gravity_button/collision.inc.c"
#include "levels/lll/thwomp_block/model.inc.c"
#include "levels/lll/thwomp_block/collision.inc.c"
#include "levels/lll/engine_gear/model.inc.c"
#include "levels/lll/engine_gear/collision.inc.c"
#include "levels/lll/power_door/model.inc.c"
#include "levels/lll/power_door/collision.inc.c"
#include "levels/lll/engine_gate/model.inc.c"
#include "levels/lll/engine_gate/collision.inc.c"
#include "levels/lll/engine_lever/model.inc.c"
#include "levels/lll/engine_lever/anims/data.inc.c"
#include "levels/lll/engine_lever/anims/table.inc.c"
#include "levels/lll/engine_lever/collision.inc.c"
#include "levels/lll/heavy_weight/model.inc.c"
#include "levels/lll/heavy_weight/collision.inc.c"
#include "levels/lll/leg_press/model.inc.c"
#include "levels/lll/leg_press/collision.inc.c"
#include "levels/lll/exercise_bike/model.inc.c"
#include "levels/lll/exercise_bike/collision.inc.c"
#include "levels/lll/exercise_bike/anims/data.inc.c"
#include "levels/lll/exercise_bike/anims/table.inc.c"
#include "levels/lll/swinging_plat/model.inc.c"
#include "levels/lll/swinging_plat/collision.inc.c"
#include "levels/lll/sawblade/model.inc.c"
#include "levels/lll/big_swinging_plat/model.inc.c"
#include "levels/lll/big_swinging_plat/collision.inc.c"
#include "levels/lll/crumble_floor/collision.inc.c"
#include "levels/lll/crumble_floor/model.inc.c"
#include "levels/lll/power_plat/model.inc.c"
#include "levels/lll/power_plat/collision.inc.c"
#include "levels/lll/power_button/model.inc.c"
#include "levels/lll/power_button/collision.inc.c"
#include "levels/lll/power_bar/model.inc.c"