#include "src/game/envfx_snow.h"

const GeoLayout unstable_rock_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(1, unstable_rock_Snow_002_mesh_layer_1),
		GEO_DISPLAY_LIST(1, unstable_rock_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
