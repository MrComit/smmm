#include "src/game/envfx_snow.h"

const GeoLayout l1_2d_red_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, l1_2d_red_2DRedCoin_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, l1_2d_red_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
