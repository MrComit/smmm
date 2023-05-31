#include "src/game/envfx_snow.h"

const GeoLayout end_laser_geo[] = {
	GEO_CULLING_RADIUS(32767),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, end_laser_Bubble_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, end_laser_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
