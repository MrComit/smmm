#include "src/game/envfx_snow.h"

const GeoLayout teardrop_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, teardrop_Tear_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, teardrop_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
