#include "src/game/envfx_snow.h"

const GeoLayout fist_indicator_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(20, geo_update_layer_transparency),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, fist_indicator_dl_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, fist_indicator_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
