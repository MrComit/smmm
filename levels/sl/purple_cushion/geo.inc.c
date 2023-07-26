#include "src/game/envfx_snow.h"

const GeoLayout purple_cushion_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(1, geo_set_brightness_env),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, purple_cushion_pcush_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, purple_cushion_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
