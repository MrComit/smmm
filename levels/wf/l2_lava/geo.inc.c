#include "src/game/envfx_snow.h"

const GeoLayout l2_lava_geo[] = {
	GEO_CULLING_RADIUS(8192),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(1, l2_lava_Lava_001_mesh_layer_1),
		GEO_DISPLAY_LIST(1, l2_lava_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
