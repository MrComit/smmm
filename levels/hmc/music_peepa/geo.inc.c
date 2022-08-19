#include "src/game/envfx_snow.h"

const GeoLayout music_peepa_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(1, geo_set_color_env),
			GEO_ASM(5, geo_set_color_env),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, music_peepa_Main_mesh_layer_1),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, music_peepa_Main_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, music_peepa_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, music_peepa_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
