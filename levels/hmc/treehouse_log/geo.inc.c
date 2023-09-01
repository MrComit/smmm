#include "src/game/envfx_snow.h"

const GeoLayout treehouse_log_geo[] = {
	GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0x9B, 200),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, treehouse_log_Log_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, treehouse_log_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
