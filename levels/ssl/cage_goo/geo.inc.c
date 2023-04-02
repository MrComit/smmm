#include "src/game/envfx_snow.h"

const GeoLayout cage_goo_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_update_boogoo_color),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, cage_goo_cgoo_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cage_goo_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
