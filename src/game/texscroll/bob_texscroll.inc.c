#include "levels/bob/header.h"
#include "levels/bob/landchunk/texscroll.inc.c"
#include "levels/bob/chandelier/texscroll.inc.c"
#include "levels/bob/texscroll.inc.c"
#include "levels/bob/ghost_barrier/texscroll.inc.c"
void scroll_textures_bob() {
		scroll_bob_level_geo_landchunk();

	scroll_bob_level_geo_chandelier();

	scroll_bob();

		
	scroll_bob_level_geo_ghost_barrier();
}
