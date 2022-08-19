#include "src/game/envfx_snow.h"

const GeoLayout music_peepa_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, music_peepa_Main_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, music_peepa_Main_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout music_peepa_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_update_layer_transparency),
			GEO_SWITCH_CASE(2, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, music_peepa_Main_mesh_layer_1),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT, music_peepa_Main_mesh_layer_5),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, music_peepa_switch_opt1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, music_peepa_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, music_peepa_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
