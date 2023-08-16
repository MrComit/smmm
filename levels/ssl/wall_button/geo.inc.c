#include "src/game/envfx_snow.h"

const GeoLayout wall_button_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(1, geo_set_color_env),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wall_button_button_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wall_button_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
