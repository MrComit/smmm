#include "src/game/envfx_snow.h"

const GeoLayout heavyswitch_Switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, heavyswitch_Group_mesh_layer_1_mat_override_BlueSwitch_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout heavyswitch_Switch_opt2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, heavyswitch_Group_mesh_layer_1_mat_override_YellowSwitch_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout heavyswitch_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(3, geo_switch_bparam2),
		GEO_OPEN_NODE(),
			GEO_NODE_START(),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, heavyswitch_Group_mesh_layer_1),
			GEO_CLOSE_NODE(),
			GEO_BRANCH(1, heavyswitch_Switch_opt1),
			GEO_BRANCH(1, heavyswitch_Switch_opt2),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, heavyswitch_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
