#include "levels/hmc/header.h"
#include "levels/hmc/texscroll.inc.c"
#include "levels/hmc/pool_barrier/texscroll.inc.c"
void scroll_textures_hmc() {
	scroll_hmc();
	scroll_hmc_level_geo_pool_barrier();
}
