#include "src/game/envfx_snow.h"

const GeoLayout treadmill_floor_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, treadmill_floor_tfloor_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout treadmill_floor_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_update_layer_transparency_cutout2),
			GEO_SWITCH_CASE(2, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_ALPHA, treadmill_floor_tfloor_mesh_layer_4),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, treadmill_floor_switch_opt1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, treadmill_floor_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, treadmill_floor_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
