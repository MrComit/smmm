#include "src/game/envfx_snow.h"

const GeoLayout mem_button_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, mem_button_RedButton_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, mem_button_RedButton_mesh_layer_2),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, mem_button_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, mem_button_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
