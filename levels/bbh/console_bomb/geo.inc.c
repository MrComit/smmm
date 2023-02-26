#include "src/game/envfx_snow.h"

const GeoLayout console_bomb_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, console_bomb_BobOmb_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, console_bomb_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
