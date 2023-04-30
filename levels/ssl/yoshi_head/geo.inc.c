#include "src/game/envfx_snow.h"

const GeoLayout yoshi_head_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_generate_spotlight),
			// GEO_DISPLAY_LIST(LAYER_TRANSPARENT, yoshi_head_spotlight_mesh_layer_5),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, yoshi_head_yhead_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, yoshi_head_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, yoshi_head_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
