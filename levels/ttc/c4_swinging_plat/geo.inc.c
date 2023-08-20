#include "src/game/envfx_snow.h"

const GeoLayout c4_swinging_plat_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, c4_swinging_plat_splat_mesh_layer_1),
			GEO_ASM(0, geo_generate_plat_chain),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, c4_swinging_plat_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
