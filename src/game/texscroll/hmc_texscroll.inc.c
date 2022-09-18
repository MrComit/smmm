#include "levels/hmc/header.h"
#include "levels/hmc/texscroll.inc.c"
#include "levels/hmc/pool_barrier/texscroll.inc.c"
#include "levels/hmc/pool_floor/texscroll.inc.c"
#include "levels/hmc/trophy_octogon/texscroll.inc.c"
#include "levels/hmc/trophy_rectangle/texscroll.inc.c"
#include "levels/hmc/static_wall/texscroll.inc.c"
#include "levels/hmc/vase_throw/texscroll.inc.c"
#include "levels/hmc/sauna_rock_rise/texscroll.inc.c"
#include "levels/hmc/foreroom_object/texscroll.inc.c"
#include "levels/hmc/attic_spire/texscroll.inc.c"
#include "levels/hmc/attic_indicator/texscroll.inc.c"
#include "levels/hmc/attic_wall/texscroll.inc.c"
#include "levels/hmc/music_barrier/texscroll.inc.c"
#include "levels/hmc/opening_wall/texscroll.inc.c"
#include "levels/hmc/trophy_elevator/texscroll.inc.c"
void scroll_textures_hmc() {
	scroll_hmc();
	scroll_hmc_level_geo_pool_barrier();
	scroll_hmc_level_geo_pool_floor();
	scroll_hmc_level_geo_trophy_octogon();
	scroll_hmc_level_geo_trophy_rectangle();
	scroll_hmc_level_geo_static_wall();
	scroll_hmc_level_geo_vase_throw();
	scroll_hmc_level_geo_sauna_rock_rise();
	scroll_hmc_level_geo_foreroom_object();
	scroll_hmc_level_geo_attic_spire();
	scroll_hmc_level_geo_attic_indicator();
	scroll_hmc_level_geo_attic_wall();
	scroll_hmc_level_geo_music_barrier();
	scroll_hmc_level_geo_opening_wall();
	scroll_hmc_level_geo_trophy_elevator();
}
