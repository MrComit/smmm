#include "src/game/envfx_snow.h"

const GeoLayout new_chase_pieces_CToL_001[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, new_chase_pieces_start_cl_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout new_chase_pieces_RToL_001[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, new_chase_pieces_start_rl_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout new_chase_pieces_LToC[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, new_chase_pieces_start_lc_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout new_chase_pieces_CToC[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, new_chase_pieces_start_cc_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout new_chase_pieces_RToC[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, new_chase_pieces_start_rc_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout new_chase_pieces_LToR_001[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, new_chase_pieces_start_lr_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout new_chase_pieces_CToR[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, new_chase_pieces_start_cr_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout new_chase_pieces_RToR_001[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, new_chase_pieces_start_rr_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout new_chase_pieces_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(9, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, new_chase_pieces_ll_mesh_layer_1),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, new_chase_pieces_CToL_001),
				GEO_BRANCH(1, new_chase_pieces_RToL_001),
				GEO_BRANCH(1, new_chase_pieces_LToC),
				GEO_BRANCH(1, new_chase_pieces_CToC),
				GEO_BRANCH(1, new_chase_pieces_RToC),
				GEO_BRANCH(1, new_chase_pieces_LToR_001),
				GEO_BRANCH(1, new_chase_pieces_CToR),
				GEO_BRANCH(1, new_chase_pieces_RToR_001),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, new_chase_pieces_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
