#include "src/game/envfx_snow.h"

const GeoLayout theater_arena_Background2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, theater_arena_start_bg2_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, theater_arena_start_bg2_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout theater_arena_Background3[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, theater_arena_start_bg3_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, theater_arena_start_bg3_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout theater_arena_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(3, geo_switch_bparam2),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, theater_arena_bg1_mesh_layer_1),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, theater_arena_Background2),
				GEO_BRANCH(1, theater_arena_Background3),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, theater_arena_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, theater_arena_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
