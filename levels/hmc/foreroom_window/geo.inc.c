#include "src/game/envfx_snow.h"

const GeoLayout foreroom_window_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, foreroom_window_Window_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, foreroom_window_Window_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, foreroom_window_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, foreroom_window_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
