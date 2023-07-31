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
#include "levels/sl/texture.inc.c"
#include "levels/sl/areas/1/1/model.inc.c"
#include "levels/sl/areas/1/2/model.inc.c"
#include "levels/sl/areas/1/3/model.inc.c"
#include "levels/sl/areas/1/4/model.inc.c"
#include "levels/sl/areas/1/5/model.inc.c"
#include "levels/sl/areas/1/6/model.inc.c"
#include "levels/sl/areas/1/7/model.inc.c"
#include "levels/sl/snow_mound/model.inc.c"
#include "levels/sl/unused_cracked_ice/model.inc.c"
#include "levels/sl/unused_ice_shard/model.inc.c" // Used in the unused behavior when ground pounding the cracked ice show in the above model.
#include "levels/sl/areas/2/1/model.inc.c"
#include "levels/sl/areas/2/2/model.inc.c"
#include "levels/sl/areas/2/3/model.inc.c"
#include "levels/sl/areas/2/4/model.inc.c"
#include "levels/sl/areas/1/collision.inc.c"
#include "levels/sl/areas/1/macro.inc.c"
#include "levels/sl/snow_mound/collision.inc.c"
#include "levels/sl/unused_cracked_ice/collision.inc.c"
#include "levels/sl/areas/2/collision.inc.c"
#include "levels/sl/areas/2/macro.inc.c"
#include "levels/sl/areas/1/movtext.inc.c"

#include "levels/sl/leveldata.inc.c"

#include "levels/sl/thin_book_big/collision.inc.c"
#include "levels/sl/thin_book/model.inc.c"
#include "levels/sl/l10_pressure_plate/model.inc.c"
#include "levels/sl/l10_pressure_plate/collision.inc.c"
#include "levels/sl/purple_cushion/model.inc.c"
#include "levels/sl/purple_cushion/collision.inc.c"
#include "levels/sl/l10_gravity_button/model.inc.c"
#include "levels/sl/l10_gravity_button/collision.inc.c"
#include "levels/sl/l10_bounce_box/collision.inc.c"
#include "levels/sl/l10_bounce_box/model.inc.c"
#include "levels/sl/end_star/model.inc.c"
#include "levels/sl/boo_bubble/model.inc.c"
#include "levels/sl/jukebox/collision.inc.c"
#include "levels/sl/new_tv_static/model.inc.c"
#include "levels/sl/new_remote/model.inc.c"
#include "levels/sl/new_shyguy_group/model.inc.c"
#include "levels/sl/new_chase_pieces/model.inc.c"
#include "levels/sl/new_chase_piece_0/collision.inc.c"
#include "levels/sl/new_chase_piece_1/collision.inc.c"
#include "levels/sl/new_chase_piece_2/collision.inc.c"
#include "levels/sl/new_chase_piece_3/collision.inc.c"
#include "levels/sl/new_chase_piece_4/collision.inc.c"
#include "levels/sl/new_chase_piece_5/collision.inc.c"
#include "levels/sl/new_chase_piece_6/collision.inc.c"
#include "levels/sl/new_chase_piece_7/collision.inc.c"
#include "levels/sl/new_chase_piece_8/collision.inc.c"
#include "levels/sl/new_icecube/model.inc.c"
#include "levels/sl/new_icecube/collision.inc.c"
#include "levels/sl/new_button/collision.inc.c"
#include "levels/sl/new_button/model.inc.c"
#include "levels/sl/new_fridge/collision.inc.c"
#include "levels/sl/new_fridge/model.inc.c"
#include "levels/sl/blocker_bedroom/collision.inc.c"
#include "levels/sl/blocker_bedroom/model.inc.c"
#include "levels/sl/blocker_basement/model.inc.c"
#include "levels/sl/blocker_basement/collision.inc.c"
#include "levels/sl/blocker_entertainment/collision.inc.c"
#include "levels/sl/blocker_entertainment/model.inc.c"
#include "levels/sl/blocker_lounge/collision.inc.c"
#include "levels/sl/blocker_lounge/model.inc.c"