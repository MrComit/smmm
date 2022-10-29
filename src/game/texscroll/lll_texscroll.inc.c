#include "levels/lll/header.h"
#include "levels/lll/texscroll.inc.c"
#include "levels/lll/clothes_ball/texscroll.inc.c"
#include "levels/lll/dust_bunny/texscroll.inc.c"
void scroll_textures_lll() {
	scroll_lll();
	scroll_lll_level_geo_clothes_ball();
	scroll_lll_level_geo_dust_bunny();
}
