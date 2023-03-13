#include "src/game/envfx_snow.h"

const GeoLayout map_l5_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, -584, 10, 527, map_l5_1OASIS_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, -1111, 10, 231, map_l5_2TUNNEL_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 608, 10, 1106, map_l5_3CAVE_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 304, 10, 1446, map_l5_4CBOO_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 762, 10, -660, map_l5_5SNOW_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 525, 10, 359, map_l5_6UNDER_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 1942, 10, -1452, map_l5_7CASTLE_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, map_l5_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
