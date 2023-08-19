#include "src/game/envfx_snow.h"

const GeoLayout c2_lemon_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, c2_lemon_Lemon_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, c2_lemon_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
