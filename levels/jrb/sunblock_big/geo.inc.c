#include "src/game/envfx_snow.h"

const GeoLayout sunblock_big_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, sunblock_big_Sunblock_001_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, sunblock_big_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
