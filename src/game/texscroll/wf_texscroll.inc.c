#include "levels/wf/header.h"
#include "levels/wf/texscroll.inc.c"
#include "levels/wf/lightning/texscroll.inc.c"
#include "levels/wf/gushing_water/texscroll.inc.c"
void scroll_textures_wf() {
	scroll_wf();
	scroll_wf_level_geo_lightning();
	scroll_wf_level_geo_gushing_water();
}
