#include "src/game/envfx_snow.h"

const GeoLayout fan_blades_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, fan_blades_Fan_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, fan_blades_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
