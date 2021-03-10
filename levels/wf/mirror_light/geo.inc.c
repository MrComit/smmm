#include "src/game/envfx_snow.h"

const GeoLayout mirror_light_geo[] = {
	GEO_CULLING_RADIUS(16384),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(5, mirror_light_Light_mesh_layer_5),
		GEO_DISPLAY_LIST(5, mirror_light_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
