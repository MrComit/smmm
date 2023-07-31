#include "levels/sl/header.h"
#include "levels/sl/texscroll.inc.c"
#include "levels/sl/blocker_bedroom/texscroll.inc.c"
#include "levels/sl/blocker_basement/texscroll.inc.c"
#include "levels/sl/blocker_entertainment/texscroll.inc.c"
#include "levels/sl/blocker_lounge/texscroll.inc.c"
void scroll_textures_sl() {
	scroll_sl();
	scroll_sl_level_geo_blocker_bedroom();
	scroll_sl_level_geo_blocker_basement();
	scroll_sl_level_geo_blocker_entertainment();
	scroll_sl_level_geo_blocker_lounge();
}
