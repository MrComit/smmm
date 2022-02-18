#include "src/game/envfx_snow.h"

const GeoLayout pool_ball_bswitch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, pool_ball_ball_mesh_layer_1_mat_override_BallStripe_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout pool_ball_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(1, geo_set_color_env),
			GEO_SWITCH_CASE(2, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, pool_ball_ball_mesh_layer_1),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, pool_ball_bswitch_opt1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, pool_ball_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
