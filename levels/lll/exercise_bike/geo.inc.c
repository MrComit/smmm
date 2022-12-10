#include "src/game/envfx_snow.h"

const GeoLayout exercise_bike_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, exercise_bike_body_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, -111, 129, 73, exercise_bike_LCrank_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 1, 84, 88, exercise_bike_LPedal_mesh_layer_1),
			GEO_CLOSE_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, -111, 129, -65, exercise_bike_RCrank_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 2, -79, -88, exercise_bike_RPedal_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, exercise_bike_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
