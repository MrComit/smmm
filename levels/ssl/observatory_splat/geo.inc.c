#include "src/game/envfx_snow.h"

const GeoLayout observatory_splat_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_dynamic_observatory_spinning_plat),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, observatory_splat_osplat_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, observatory_splat_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
