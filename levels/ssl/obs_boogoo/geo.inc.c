#include "src/game/envfx_snow.h"

const GeoLayout obs_boogoo_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, obs_boogoo_obsb_mesh_layer_1_mat_override_BooGooObjectTrans_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout obs_boogoo_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_update_boogoo_object),
			GEO_SWITCH_CASE(2, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, obs_boogoo_obsb_mesh_layer_1),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, obs_boogoo_switch_opt1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, obs_boogoo_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, obs_boogoo_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
