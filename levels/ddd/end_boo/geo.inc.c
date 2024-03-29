#include "src/game/envfx_snow.h"

const GeoLayout end_boo_001_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, end_boo_000_displaylist_mesh_layer_1_mat_override_BooGooObjTrans_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout end_boo_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_SHADOW(0, 150, 70),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_FORCE, 26214),
			GEO_OPEN_NODE(),
				GEO_ASM(0, geo_update_boogoo_color),
				GEO_SWITCH_CASE(2, geo_switch_anim_state),
				GEO_OPEN_NODE(),
					GEO_NODE_START(),
					GEO_OPEN_NODE(),
						GEO_DISPLAY_LIST(LAYER_OPAQUE, end_boo_000_displaylist_mesh_layer_1),
					GEO_CLOSE_NODE(),
					GEO_BRANCH(1, end_boo_001_switch_opt1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, end_boo_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, end_boo_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
