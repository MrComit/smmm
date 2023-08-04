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

#include "levels/hmc/header.h"

#include "levels/hmc/areas/1/grill_door/geo.inc.c"
#include "levels/hmc/rolling_rock/geo.inc.c"
#include "levels/hmc/rolling_rock_fragment_1/geo.inc.c"
#include "levels/hmc/rolling_rock_fragment_2/geo.inc.c"
#include "levels/hmc/arrow_platform/geo.inc.c"
#include "levels/hmc/arrow_platform_button/geo.inc.c"
#include "levels/hmc/elevator_platform/geo.inc.c"
#include "levels/hmc/areas/1/geo.inc.c"

#include "levels/hmc/geo.inc.c"

#include "levels/hmc/dice_enemy/geo.inc.c"
#include "levels/hmc/pool_ball/geo.inc.c"
#include "levels/hmc/pool_cue/geo.inc.c"
#include "levels/hmc/pool_barrier/geo.inc.c"
#include "levels/hmc/pool_floor/geo.inc.c"
#include "levels/hmc/toy_mole/geo.inc.c"
#include "levels/hmc/mole_cage/geo.inc.c"
#include "levels/hmc/pingpong_ball/geo.inc.c"
#include "levels/hmc/pingpong_paddle/geo.inc.c"
#include "levels/hmc/trophy_octogon/geo.inc.c"
#include "levels/hmc/trophy_rectangle/geo.inc.c"
#include "levels/hmc/music_insts/geo.inc.c"
#include "levels/hmc/foreroom_object/geo.inc.c"
#include "levels/hmc/foreroom_lever/geo.inc.c"
#include "levels/hmc/foreroom_window/geo.inc.c"
#include "levels/hmc/tight_rope/geo.inc.c"
#include "levels/hmc/tree_limb/geo.inc.c"
#include "levels/hmc/blue_owl/geo.inc.c"
#include "levels/hmc/theater_screen/geo.inc.c"
#include "levels/hmc/goomba_2d/geo.inc.c"
#include "levels/hmc/koopa_2d/geo.inc.c"
#include "levels/hmc/bulletbill_2d/geo.inc.c"
#include "levels/hmc/theater_arena/geo.inc.c"
#include "levels/hmc/boom_boom_2d/geo.inc.c"
#include "levels/hmc/theater_tomato/geo.inc.c"
#include "levels/hmc/treehouse_log/geo.inc.c"
#include "levels/hmc/treehouse_spike/geo.inc.c"
#include "levels/hmc/cushion_friend/geo.inc.c"
#include "levels/hmc/static_tri/geo.inc.c"
#include "levels/hmc/static_wall/geo.inc.c"
#include "levels/hmc/vase_throw/geo.inc.c"
#include "levels/hmc/sauna_grate/geo.inc.c"
#include "levels/hmc/bully_gate/geo.inc.c"
#include "levels/hmc/sauna_rock_rise/geo.inc.c"
#include "levels/hmc/fan_blades/geo.inc.c"
#include "levels/hmc/attic_grate/geo.inc.c"
#include "levels/hmc/attic_spire/geo.inc.c"
#include "levels/hmc/attic_rock/geo.inc.c"
#include "levels/hmc/attic_bully/geo.inc.c"
#include "levels/hmc/attic_spike/geo.inc.c"
#include "levels/hmc/attic_indicator/geo.inc.c"
#include "levels/hmc/attic_wall/geo.inc.c"
#include "levels/hmc/music_barrier/geo.inc.c"
#include "levels/hmc/music_peepa/geo.inc.c"
#include "levels/hmc/opening_wall/geo.inc.c"
#include "levels/hmc/bully_trophy/geo.inc.c"
#include "levels/hmc/trophy_elevator/geo.inc.c"
#include "levels/hmc/plat_hall_wall/geo.inc.c"
#include "levels/hmc/map_l6/geo.inc.c"
#include "levels/hmc/red_vase/geo.inc.c"
#include "levels/hmc/l6_2d_red/geo.inc.c"