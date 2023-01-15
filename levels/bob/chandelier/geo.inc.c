#include "src/game/envfx_snow.h"

const GeoLayout chandelier_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, chandelier_Chandelier_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, chandelier_Chandelier_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, chandelier_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, chandelier_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
