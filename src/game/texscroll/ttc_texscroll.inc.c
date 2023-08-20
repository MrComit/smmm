#include "levels/ttc/header.h"
#include "levels/ttc/c4_trophy_rectangle/texscroll.inc.c"
#include "levels/ttc/c4_trophy_octogon/texscroll.inc.c"
#include "levels/ttc/texscroll.inc.c"
#include "levels/ttc/c4_swinging_plat/texscroll.inc.c"
void scroll_textures_ttc() {
	scroll_ttc_level_geo_c4_trophy_rectangle();
	scroll_ttc_level_geo_c4_trophy_octogon();
	scroll_ttc();
	scroll_ttc_level_geo_c4_swinging_plat();
}
