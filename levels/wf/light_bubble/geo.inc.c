#include "src/game/envfx_snow.h"

const GeoLayout light_bubble_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(5, geo_set_color_env),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, light_bubble_dl_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, light_bubble_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
