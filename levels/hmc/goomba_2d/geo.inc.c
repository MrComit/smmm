#include "src/game/envfx_snow.h"

const GeoLayout goomba_2d_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, goomba_2d_goomba_mesh_layer_4_mat_override_Goomba2_v4_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout goomba_2d_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(2, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_ALPHA, goomba_2d_goomba_mesh_layer_4),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, goomba_2d_switch_opt1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, goomba_2d_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
