#include "src/game/envfx_snow.h"

const GeoLayout red_spot_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, red_spot_RedSpot_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, red_spot_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
