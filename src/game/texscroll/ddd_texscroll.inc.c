#include "levels/ddd/header.h"
#include "levels/ddd/controller/texscroll.inc.c"
#include "levels/ddd/end_goomba/texscroll.inc.c"
#include "levels/ddd/end_shyguy/texscroll.inc.c"
#include "levels/ddd/end_boo/texscroll.inc.c"
#include "levels/ddd/end_cage/texscroll.inc.c"
#include "levels/ddd/end_fist/texscroll.inc.c"
#include "levels/ddd/end_bubble/texscroll.inc.c"
void scroll_textures_ddd() {
	scroll_ddd_level_geo_controller();
	scroll_ddd_level_geo_end_goomba();
	scroll_ddd_level_geo_end_shyguy();
	scroll_ddd_level_geo_end_boo();
	scroll_ddd_level_geo_end_cage();
	scroll_ddd_level_geo_end_fist();
	scroll_ddd_level_geo_end_bubble();
}
