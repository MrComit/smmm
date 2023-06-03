#include "levels/ddd/header.h"
#include "levels/ddd/controller/texscroll.inc.c"
#include "levels/ddd/end_goomba/texscroll.inc.c"
#include "levels/ddd/end_shyguy/texscroll.inc.c"
#include "levels/ddd/end_boo/texscroll.inc.c"
#include "levels/ddd/end_cage/texscroll.inc.c"
#include "levels/ddd/end_fist/texscroll.inc.c"
#include "levels/ddd/end_bubble/texscroll.inc.c"
#include "levels/ddd/end_log/texscroll.inc.c"
#include "levels/ddd/end_spike/texscroll.inc.c"
#include "levels/ddd/end_laser/texscroll.inc.c"
#include "levels/ddd/hole_wall/texscroll.inc.c"
#include "levels/ddd/texscroll.inc.c"
#include "levels/ddd/hole_wall_ground/texscroll.inc.c"
#include "levels/ddd/bg_ground/texscroll.inc.c"
void scroll_textures_ddd() {
	scroll_ddd_level_geo_controller();
	scroll_ddd_level_geo_end_goomba();
	scroll_ddd_level_geo_end_shyguy();
	scroll_ddd_level_geo_end_boo();
	scroll_ddd_level_geo_end_cage();
	scroll_ddd_level_geo_end_fist();
	scroll_ddd_level_geo_end_bubble();
	scroll_ddd_level_geo_end_log();
	scroll_ddd_level_geo_end_spike();
	scroll_ddd_level_geo_end_laser();
	scroll_ddd_level_geo_hole_wall();
	scroll_ddd();
	scroll_ddd_level_geo_hole_wall_ground();
	scroll_ddd_level_geo_bg_ground();
}
