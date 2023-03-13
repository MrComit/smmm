#include "src/game/envfx_snow.h"

const GeoLayout map_l4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 519, 10, 1464, map_l4_1CITY_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 674, 10, 345, map_l4_2BCH_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 1689, 10, -1227, map_l4_3CITY2_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 2352, 10, -449, map_l4_4BOO_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 1250, 10, -487, map_l4_5STAR_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, map_l4_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
