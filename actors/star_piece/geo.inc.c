#include "src/game/envfx_snow.h"

const GeoLayout star_piece_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, star_piece_dl_mesh_layer_1_mat_override_Ch2_v4_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout star_piece_switch_opt2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, star_piece_dl_mesh_layer_1_mat_override_Ch3_v4_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout star_piece_switch_opt3[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, star_piece_dl_mesh_layer_1_mat_override_Ch4_v4_2),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout star_piece_switch_opt4[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, star_piece_dl_mesh_layer_1_mat_override_Ch5_v4_3),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout star_piece_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(5, geo_switch_get_chapter),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, star_piece_dl_mesh_layer_1),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, star_piece_switch_opt1),
				GEO_BRANCH(1, star_piece_switch_opt2),
				GEO_BRANCH(1, star_piece_switch_opt3),
				GEO_BRANCH(1, star_piece_switch_opt4),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, star_piece_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
