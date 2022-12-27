#include "levels/lll/header.h"
#include "levels/lll/texscroll.inc.c"
#include "levels/lll/clothes_ball/texscroll.inc.c"
#include "levels/lll/dust_bunny/texscroll.inc.c"
#include "levels/lll/power_door/texscroll.inc.c"
#include "levels/lll/swinging_plat/texscroll.inc.c"
#include "levels/lll/sawblade/texscroll.inc.c"
#include "levels/lll/big_swinging_plat/texscroll.inc.c"
#include "levels/lll/power_plat/texscroll.inc.c"
#include "levels/lll/power_button/texscroll.inc.c"
#include "levels/lll/power_bar/texscroll.inc.c"
#include "levels/lll/wall_goomba/texscroll.inc.c"
#include "levels/lll/wall_hammerbro/texscroll.inc.c"
void scroll_textures_lll() {
	scroll_lll();
	scroll_lll_level_geo_clothes_ball();
	scroll_lll_level_geo_dust_bunny();
	scroll_lll_level_geo_power_door();
	scroll_lll_level_geo_swinging_plat();
	scroll_lll_level_geo_sawblade();
	scroll_lll_level_geo_big_swinging_plat();
	scroll_lll_level_geo_power_plat();
	scroll_lll_level_geo_power_button();
	scroll_lll_level_geo_power_bar();
	scroll_lll_level_geo_wall_goomba();
	scroll_lll_level_geo_wall_hammerbro();
}
