#include "src/game/envfx_snow.h"

const GeoLayout tv_static_Switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, tv_static_Static_mesh_layer_1_mat_override_Black_v4_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout tv_static_Switch2_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, tv_static_Light_mesh_layer_6_mat_override_Blank_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout tv_static_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(2, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, tv_static_Static_mesh_layer_1),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, tv_static_Switch_opt1),
			GEO_CLOSE_NODE(),
			GEO_SWITCH_CASE(2, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, tv_static_Light_mesh_layer_6),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, tv_static_Switch2_opt1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, tv_static_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, tv_static_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
