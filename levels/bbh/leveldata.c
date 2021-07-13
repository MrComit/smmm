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
#include "levels/bbh/texture.inc.c"
#include "levels/bbh/areas/1/1/model.inc.c"
#include "levels/bbh/areas/1/2/model.inc.c"
#include "levels/bbh/areas/1/3/model.inc.c"
#include "levels/bbh/areas/1/4/model.inc.c"
#include "levels/bbh/areas/1/5/model.inc.c"
#include "levels/bbh/areas/1/6/model.inc.c"
#include "levels/bbh/areas/1/7/model.inc.c"
#include "levels/bbh/areas/1/8/model.inc.c"
#include "levels/bbh/areas/1/9/model.inc.c"
#include "levels/bbh/areas/1/10/model.inc.c"
#include "levels/bbh/areas/1/11/model.inc.c"
#include "levels/bbh/areas/1/12/model.inc.c"
#include "levels/bbh/areas/1/13/model.inc.c"
#include "levels/bbh/areas/1/14/model.inc.c"
#include "levels/bbh/areas/1/15/model.inc.c"
#include "levels/bbh/areas/1/16/model.inc.c"
#include "levels/bbh/areas/1/17/model.inc.c"
#include "levels/bbh/areas/1/18/model.inc.c"
#include "levels/bbh/areas/1/19/model.inc.c"
#include "levels/bbh/areas/1/20/model.inc.c"
#include "levels/bbh/areas/1/21/model.inc.c"
#include "levels/bbh/areas/1/22/model.inc.c"
#include "levels/bbh/areas/1/23/model.inc.c"
#include "levels/bbh/areas/1/24/model.inc.c"
#include "levels/bbh/areas/1/25/model.inc.c"
#include "levels/bbh/areas/1/26/model.inc.c"
#include "levels/bbh/areas/1/27/model.inc.c"
#include "levels/bbh/areas/1/28/model.inc.c"
#include "levels/bbh/areas/1/29/model.inc.c"
#include "levels/bbh/areas/1/30/model.inc.c"
#include "levels/bbh/areas/1/31/model.inc.c"
#include "levels/bbh/areas/1/32/model.inc.c"
#include "levels/bbh/areas/1/33/model.inc.c"
#include "levels/bbh/areas/1/34/model.inc.c"
#include "levels/bbh/areas/1/35/model.inc.c"
#include "levels/bbh/areas/1/36/model.inc.c"
#include "levels/bbh/areas/1/37/model.inc.c"
#include "levels/bbh/areas/1/38/model.inc.c"
#include "levels/bbh/areas/1/39/model.inc.c"
#include "levels/bbh/staircase_step/model.inc.c"
#include "levels/bbh/tilting_trap_platform/model.inc.c"
#include "levels/bbh/tumbling_platform_far/model.inc.c"
#include "levels/bbh/tumbling_platform_near/model.inc.c"
#include "levels/bbh/moving_bookshelf/model.inc.c"
#include "levels/bbh/mesh_elevator/model.inc.c"
#include "levels/bbh/merry_go_round/model.inc.c"
#include "levels/bbh/coffin/model.inc.c"
#include "levels/bbh/areas/1/collision.inc.c"
#include "levels/bbh/areas/1/room.inc.c"
#include "levels/bbh/areas/1/macro.inc.c"
#include "levels/bbh/staircase_step/collision.inc.c"
#include "levels/bbh/tilting_trap_platform/collision.inc.c"
#include "levels/bbh/tumbling_platform_far/collision.inc.c"
#include "levels/bbh/tumbling_platform_near/collision.inc.c"
#include "levels/bbh/moving_bookshelf/collision.inc.c"
#include "levels/bbh/mesh_elevator/collision.inc.c"
#include "levels/bbh/merry_go_round/collision.inc.c"
#include "levels/bbh/coffin/collision.inc.c"
#include "levels/bbh/areas/1/movtext.inc.c"
#include "levels/bbh/leveldata.inc.c"

#include "levels/bbh/fake_dirt_wall/model.inc.c"
#include "levels/bbh/fake_dirt_wall/collision.inc.c"
#include "levels/bbh/bomb_rock/model.inc.c"
#include "levels/bbh/bomb_rock/collision.inc.c"