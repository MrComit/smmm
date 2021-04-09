#include "src/game/envfx_snow.h"

const GeoLayout sunblock_Switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, sunblock_H_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout sunblock_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_update_layer_transparency),
			GEO_SWITCH_CASE(2, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_ALPHA, sunblock_H_mesh_layer_4),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, sunblock_Switch_opt1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, sunblock_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, sunblock_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
