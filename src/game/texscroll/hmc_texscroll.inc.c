#include "levels/hmc/header.h"
#include "levels/hmc/texscroll.inc.c"
#include "levels/hmc/pool_barrier/texscroll.inc.c"
#include "levels/hmc/pool_floor/texscroll.inc.c"
#include "levels/hmc/trophy_octogon/texscroll.inc.c"
#include "levels/hmc/trophy_rectangle/texscroll.inc.c"
void scroll_textures_hmc() {
	scroll_hmc();
	scroll_hmc_level_geo_pool_barrier();
	scroll_hmc_level_geo_pool_floor();
	scroll_hmc_level_geo_trophy_octogon();
	scroll_hmc_level_geo_trophy_rectangle();
}
