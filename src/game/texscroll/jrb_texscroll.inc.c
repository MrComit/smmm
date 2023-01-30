#include "levels/jrb/header.h"
#include "levels/jrb/texscroll.inc.c"
#include "levels/jrb/l3_sun/texscroll.inc.c"
#include "levels/jrb/sunflower/texscroll.inc.c"
#include "levels/jrb/standing_sunflower/texscroll.inc.c"
void scroll_textures_jrb() {
	scroll_jrb();
	scroll_jrb_level_geo_l3_sun();
	scroll_jrb_level_geo_sunflower();
	scroll_jrb_level_geo_standing_sunflower();
}
