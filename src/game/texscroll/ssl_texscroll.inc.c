#include "levels/ssl/header.h"
#include "levels/ssl/boogoo_goomba/texscroll.inc.c"
#include "levels/ssl/boogoo_koopa/texscroll.inc.c"
#include "levels/ssl/boogoo_shyguy/texscroll.inc.c"
#include "levels/ssl/cage_goo/texscroll.inc.c"
#include "levels/ssl/ag_boogoo/texscroll.inc.c"
#include "levels/ssl/texscroll.inc.c"
void scroll_textures_ssl() {
		scroll_ssl_level_geo_boogoo_goomba();
	scroll_ssl_level_geo_boogoo_koopa();
	scroll_ssl_level_geo_boogoo_shyguy();
	scroll_ssl_level_geo_cage_goo();
	scroll_ssl_level_geo_ag_boogoo();
	scroll_ssl();
}
