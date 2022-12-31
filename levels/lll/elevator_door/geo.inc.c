#include "src/game/envfx_snow.h"

const GeoLayout elevator_door_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, elevator_door_Corridor_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, elevator_door_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
