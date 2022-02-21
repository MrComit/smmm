#include "src/game/envfx_snow.h"

const GeoLayout pingpong_paddle_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, pingpong_paddle_paddle_mesh_layer_5_mat_override_PaddleBlue_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout pingpong_paddle_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_update_layer_transparency),
			GEO_SWITCH_CASE(2, geo_switch_bparam2),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT, pingpong_paddle_paddle_mesh_layer_5),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, pingpong_paddle_switch_opt1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, pingpong_paddle_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
