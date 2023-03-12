#include "src/game/envfx_snow.h"

const GeoLayout map_l3_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, -136, 10, 77, map_l3_1GARDEN_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, -809, 10, -363, map_l3_2DOG_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 391, 9, 965, map_l3_3UNDER_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, -363, 10, 749, map_l3_4CONS_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, map_l3_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
