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
}
