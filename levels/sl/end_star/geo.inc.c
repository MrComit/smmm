#include "src/game/envfx_snow.h"

const GeoLayout end_star_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(1, geo_star_color),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, end_star_star_mesh_layer_1),
			GEO_DISPLAY_LIST(LAYER_ALPHA, end_star_star_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, end_star_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, end_star_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
