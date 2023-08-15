#include "src/game/envfx_snow.h"

const GeoLayout green_button_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(1, geo_set_color_env),
			GEO_ASM(2, geo_set_color_env),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, green_button_gbtn_mesh_layer_1),
			GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, green_button_gbtn_mesh_layer_2),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, green_button_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, green_button_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
