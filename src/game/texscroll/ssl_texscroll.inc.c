#include "levels/ssl/header.h"
#include "levels/ssl/boogoo_goomba/texscroll.inc.c"
#include "levels/ssl/boogoo_koopa/texscroll.inc.c"
#include "levels/ssl/boogoo_shyguy/texscroll.inc.c"
#include "levels/ssl/cage_goo/texscroll.inc.c"
#include "levels/ssl/ag_boogoo/texscroll.inc.c"
#include "levels/ssl/bg_asteroid/texscroll.inc.c"
#include "levels/ssl/o2_boogoo/texscroll.inc.c"
#include "levels/ssl/texscroll.inc.c"
#include "levels/ssl/spinning_plat/texscroll.inc.c"
#include "levels/ssl/big_spinning_plat/texscroll.inc.c"
#include "levels/ssl/lab_bg/texscroll.inc.c"
#include "levels/ssl/o1_bg/texscroll.inc.c"
#include "levels/ssl/mind_mound/texscroll.inc.c"
#include "levels/ssl/mind_mips/texscroll.inc.c"
void scroll_textures_ssl() {
		scroll_ssl_level_geo_boogoo_goomba();
	scroll_ssl_level_geo_boogoo_koopa();
	scroll_ssl_level_geo_boogoo_shyguy();
	scroll_ssl_level_geo_cage_goo();
	scroll_ssl_level_geo_ag_boogoo();
		scroll_ssl_level_geo_bg_asteroid();
	scroll_ssl_level_geo_o2_boogoo();
	scroll_ssl();
	scroll_ssl_level_geo_spinning_plat();
	scroll_ssl_level_geo_big_spinning_plat();
	scroll_ssl_level_geo_lab_bg();
	scroll_ssl_level_geo_o1_bg();
	scroll_ssl_level_geo_mind_mound();
	scroll_ssl_level_geo_mind_mips();
}
