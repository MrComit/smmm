#include "src/game/envfx_snow.h"

const GeoLayout ghostsand_ball_geo[] = {
	GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0xC8, 130),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(1, ghostsand_ball_skinned_mesh_layer_1),
		GEO_DISPLAY_LIST(1, ghostsand_ball_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
