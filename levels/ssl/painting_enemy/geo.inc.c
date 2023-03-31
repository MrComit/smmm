#include "src/game/envfx_snow.h"

const GeoLayout painting_enemy_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, painting_enemy_penemy_mesh_layer_6_mat_override_KoopaPainting_v4_001_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout painting_enemy_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, painting_enemy_bg_mesh_layer_1),
			GEO_ASM(20, geo_update_layer_transparency_and_color),
			GEO_SWITCH_CASE(2, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, painting_enemy_penemy_mesh_layer_6),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, painting_enemy_switch_opt1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, painting_enemy_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, painting_enemy_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
