#include "src/game/envfx_snow.h"

const GeoLayout mind_chandelier_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, mind_chandelier_Chandelier_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mind_chandelier_Chandelier_001_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, mind_chandelier_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mind_chandelier_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
