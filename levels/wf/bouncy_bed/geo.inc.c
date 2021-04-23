#include "src/game/envfx_snow.h"

const GeoLayout bouncy_bed_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_set_color_env),
			GEO_DISPLAY_LIST(5, bouncy_bed_dl_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(5, bouncy_bed_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
