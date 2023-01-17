#include "src/game/envfx_snow.h"

const GeoLayout hallway_fakewall_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_update_layer_transparency_cutout),
			GEO_DISPLAY_LIST(LAYER_ALPHA, hallway_fakewall_hallDL_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hallway_fakewall_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
