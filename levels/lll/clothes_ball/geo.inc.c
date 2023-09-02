#include "src/game/envfx_snow.h"

const GeoLayout clothes_ball_geo[] = {
	GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0x9B, 115),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(1, geo_set_color_env),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, clothes_ball_ball_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, clothes_ball_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
