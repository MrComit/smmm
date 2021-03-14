#include "src/game/envfx_snow.h"

const GeoLayout mirror_Switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mirror_Rim_mesh_layer_1_mat_override_Mirror_Edge_teal_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout mirror_Switch_opt2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mirror_Rim_mesh_layer_1_mat_override_Mirror_Edge_purple_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout mirror_Switch_opt3[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mirror_Rim_mesh_layer_1_mat_override_Mirror_Edge_Gray_2),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout mirror_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mirror_Mirror_mesh_layer_1),
			GEO_SWITCH_CASE(3, geo_switch_bparam2),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mirror_Rim_mesh_layer_1),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, mirror_Switch_opt1),
				GEO_BRANCH(1, mirror_Switch_opt2),
				GEO_BRANCH(1, mirror_Switch_opt3),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, mirror_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
