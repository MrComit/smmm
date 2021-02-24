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
#include "levels/wf/texture.inc.c"
#include "levels/wf/areas/1/1/model.inc.c"
#include "levels/wf/areas/1/2/model.inc.c"
#include "levels/wf/areas/1/3/model.inc.c"
#include "levels/wf/areas/1/4/model.inc.c"
#include "levels/wf/areas/1/5/1.inc.c"
#include "levels/wf/areas/1/5/2.inc.c"
#include "levels/wf/areas/1/6/1.inc.c"
#include "levels/wf/areas/1/6/2.inc.c"
#include "levels/wf/areas/1/7/model.inc.c"
#include "levels/wf/areas/1/8/model.inc.c"
#include "levels/wf/areas/1/9/model.inc.c"
#include "levels/wf/areas/1/10/1.inc.c"
#include "levels/wf/areas/1/10/2.inc.c"
#include "levels/wf/areas/1/11/model.inc.c"
#include "levels/wf/areas/1/12/1.inc.c"
#include "levels/wf/areas/1/12/2.inc.c"
#include "levels/wf/areas/1/13/model.inc.c"
#include "levels/wf/areas/1/14/model.inc.c"
#include "levels/wf/areas/1/15/1.inc.c"
#include "levels/wf/areas/1/15/2.inc.c"
#include "levels/wf/areas/1/15/3.inc.c"
#include "levels/wf/areas/1/16/model.inc.c"
#include "levels/wf/areas/1/17/model.inc.c"
#include "levels/wf/areas/1/18/model.inc.c"
#include "levels/wf/areas/1/19/model.inc.c"
#include "levels/wf/small_bomp/1.inc.c"
#include "levels/wf/small_bomp/2.inc.c"
#include "levels/wf/large_bomp/model.inc.c"
#include "levels/wf/tumbling_bridge_near/model.inc.c"
#include "levels/wf/tumbling_bridge_far/model.inc.c"
#include "levels/wf/rotating_wooden_platform/1.inc.c"
#include "levels/wf/rotating_wooden_platform/2.inc.c"
#include "levels/wf/sliding_platform/model.inc.c"
#include "levels/wf/beta_extending_platform/model.inc.c"
#include "levels/wf/extending_platform/model.inc.c"
#include "levels/wf/breakable_wall_right/model.inc.c"
#include "levels/wf/breakable_wall_left/model.inc.c"
#include "levels/wf/kickable_board/1.inc.c"
#include "levels/wf/kickable_board/2.inc.c"
#include "levels/wf/tower_door/model.inc.c"
#include "levels/wf/small_bomp/collision.inc.c"
#include "levels/wf/large_bomp/collision.inc.c"
#include "levels/wf/rotating_wooden_platform/collision.inc.c"
#include "levels/wf/sliding_platform/collision.inc.c"
#include "levels/wf/tumbling_bridge_near/collision.inc.c"
#include "levels/wf/beta_extending_platform/collision.inc.c"
#include "levels/wf/extending_platform/collision.inc.c"
#include "levels/wf/breakable_wall_right/collision.inc.c"
#include "levels/wf/breakable_wall_left/collision.inc.c"
#include "levels/wf/kickable_board/collision.inc.c"
#include "levels/wf/tower_door/collision.inc.c"
#include "levels/wf/rotating_platform/collision.inc.c" // This is odd... TODO: investigate this.
#include "levels/wf/areas/1/10/collision.inc.c"
#include "levels/wf/areas/1/11/collision.inc.c"
#include "levels/wf/areas/1/collision.inc.c"
#include "levels/wf/areas/1/macro.inc.c"
#include "levels/wf/areas/1/movtext.inc.c"
#include "levels/wf/leveldata.inc.c"

#include "levels/wf/heavyobject/model.inc.c"
#include "levels/wf/heavyobject/anims/data.inc.c"
#include "levels/wf/heavyobject/anims/table.inc.c"
#include "levels/wf/heavyobject/collision.inc.c"
#include "levels/wf/heavyswitch/model.inc.c"
#include "levels/wf/heavyswitch/collision.inc.c"
#include "levels/wf/l2_gate/model.inc.c"
#include "levels/wf/l2_gate/collision.inc.c"
#include "levels/wf/l2_lava/model.inc.c"
#include "levels/wf/l2_lava/collision.inc.c"
#include "levels/wf/lemon/model.inc.c"
#include "levels/wf/lemon/collision.inc.c"
#include "levels/wf/lightning/model.inc.c"
#include "levels/wf/lightning/anims/data.inc.c"
#include "levels/wf/lightning/anims/table.inc.c"
#include "levels/wf/moving_vine/model.inc.c"
#include "levels/wf/locked_cage/collision.inc.c"
#include "levels/wf/locked_cage/model.inc.c"
#include "levels/wf/l2_falling_floor/collision.inc.c"
#include "levels/wf/l2_falling_floor/model.inc.c"