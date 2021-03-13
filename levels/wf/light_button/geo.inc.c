#include "src/game/envfx_snow.h"

const GeoLayout light_button_Switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, light_button_Main_mesh_layer_1_mat_override_Yellow_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout light_button_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_anim_state),
		GEO_OPEN_NODE(),
			GEO_NODE_START(),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, light_button_Main_mesh_layer_1),
			GEO_CLOSE_NODE(),
			GEO_BRANCH(1, light_button_Switch_opt1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, light_button_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
