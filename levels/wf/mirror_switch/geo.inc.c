#include "src/game/envfx_snow.h"

const GeoLayout mirror_switch_Switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, mirror_switch_Group_mesh_layer_1_mat_override_TealSwitch_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout mirror_switch_Switch_opt2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, mirror_switch_Group_mesh_layer_1_mat_override_PurpleSwitch_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout mirror_switch_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(3, geo_switch_bparam2),
		GEO_OPEN_NODE(),
			GEO_NODE_START(),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, mirror_switch_Group_mesh_layer_1),
			GEO_CLOSE_NODE(),
			GEO_BRANCH(1, mirror_switch_Switch_opt1),
			GEO_BRANCH(1, mirror_switch_Switch_opt2),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, mirror_switch_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
