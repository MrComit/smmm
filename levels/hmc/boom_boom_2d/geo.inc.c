#include "src/game/envfx_snow.h"

const GeoLayout boom_boom_2d_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, boom_boom_2d_boomboom_mesh_layer_4_mat_override_BoomBoom1_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout boom_boom_2d_switch_opt2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, boom_boom_2d_boomboom_mesh_layer_4_mat_override_BoomBoom2_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout boom_boom_2d_switch_opt3[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, boom_boom_2d_boomboom_mesh_layer_4_mat_override_BoomBoom3_2),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout boom_boom_2d_switch_opt4[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, boom_boom_2d_boomboom_mesh_layer_4_mat_override_BoomBoom4_3),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout boom_boom_2d_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(5, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_ALPHA, boom_boom_2d_boomboom_mesh_layer_4),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, boom_boom_2d_switch_opt1),
				GEO_BRANCH(1, boom_boom_2d_switch_opt2),
				GEO_BRANCH(1, boom_boom_2d_switch_opt3),
				GEO_BRANCH(1, boom_boom_2d_switch_opt4),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, boom_boom_2d_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
