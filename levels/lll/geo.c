#include <ultra64.h>
#include "sm64.h"
#include "geo_commands.h"

#include "game/level_geo.h"
#include "game/geo_misc.h"
#include "game/camera.h"
#include "game/moving_texture.h"
#include "game/screen_transition.h"
#include "game/paintings.h"

#include "make_const_nonconst.h"

#include "levels/lll/header.h"

#include "levels/lll/areas/1/4/geo.inc.c"
#include "levels/lll/areas/1/5/geo.inc.c"
#include "levels/lll/areas/1/6/geo.inc.c"
#include "levels/lll/areas/1/7/geo.inc.c"
#include "levels/lll/areas/1/8/geo.inc.c"
#include "levels/lll/areas/1/9/geo.inc.c"
#include "levels/lll/areas/1/10/geo.inc.c"
#include "levels/lll/areas/1/11/geo.inc.c"
#include "levels/lll/areas/1/12/geo.inc.c"
#include "levels/lll/areas/1/13/geo.inc.c"
#include "levels/lll/areas/1/14/geo.inc.c"
#include "levels/lll/areas/1/15/geo.inc.c"
#include "levels/lll/moving_octagonal_mesh_platform/geo.inc.c"
#include "levels/lll/drawbridge_part/geo.inc.c"
#include "levels/lll/rotating_block_fire_bars/geo.inc.c"
#include "levels/lll/wooden_float_small/geo.inc.c"
#include "levels/lll/wooden_float_large/geo.inc.c"
#include "levels/lll/collapsing_wooden_platform/geo.inc.c"
#include "levels/lll/long_wooden_bridge/geo.inc.c"
#include "levels/lll/rotating_hexagonal_ring/geo.inc.c"
#include "levels/lll/sinking_rectangular_platform/geo.inc.c"
#include "levels/lll/sinking_square_platform/geo.inc.c"
#include "levels/lll/tilting_square_platform/geo.inc.c"
#include "levels/lll/puzzle_piece/geo.inc.c"
#include "levels/lll/sinking_rock_block/geo.inc.c"
#include "levels/lll/rolling_log/geo.inc.c"
#include "levels/lll/areas/1/geo.inc.c"
#include "levels/lll/volcano_falling_trap/geo.inc.c"
#include "levels/lll/areas/2/geo.inc.c"

#include "levels/lll/geo.inc.c"

#include "levels/lll/cellar_blockade/geo.inc.c"
#include "levels/lll/champagne/geo.inc.c"
#include "levels/lll/security_cam/geo.inc.c"
#include "levels/lll/basement_switch/geo.inc.c"
#include "levels/lll/basement_washer/geo.inc.c"
#include "levels/lll/basement_dryer/geo.inc.c"
#include "levels/lll/clothes_ball/geo.inc.c"
#include "levels/lll/laundry_bounce_box/geo.inc.c"
#include "levels/lll/dust_bunny/geo.inc.c"
#include "levels/lll/laundry_shirts1/geo.inc.c"
#include "levels/lll/laundry_shirts2/geo.inc.c"
#include "levels/lll/laundry_shirts3/geo.inc.c"
#include "levels/lll/gravity_button/geo.inc.c"
#include "levels/lll/thwomp_block/geo.inc.c"
#include "levels/lll/engine_gear/geo.inc.c"
#include "levels/lll/power_door/geo.inc.c"
#include "levels/lll/engine_gate/geo.inc.c"
#include "levels/lll/engine_lever/geo.inc.c"
#include "levels/lll/heavy_weight/geo.inc.c"
#include "levels/lll/leg_press/geo.inc.c"
#include "levels/lll/exercise_bike/geo.inc.c"
#include "levels/lll/swinging_plat/geo.inc.c"
#include "levels/lll/sawblade/geo.inc.c"
#include "levels/lll/big_swinging_plat/geo.inc.c"
#include "levels/lll/crumble_floor/geo.inc.c"
#include "levels/lll/power_plat/geo.inc.c"
#include "levels/lll/power_button/geo.inc.c"
#include "levels/lll/power_bar/geo.inc.c"
#include "levels/lll/colored_gate/geo.inc.c"
#include "levels/lll/ghost_bully/geo.inc.c"