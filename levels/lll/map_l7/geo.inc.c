#include "src/game/envfx_snow.h"

const GeoLayout map_l7_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, -331, 10, -1053, map_l7_10LAB_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 75, 10, 41, map_l7_1CORRIDOR_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 828, 10, 879, map_l7_2LAUNDRY_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, -874, 10, -354, map_l7_3GYM_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, -260, 10, 906, map_l7_4WINE_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, -245, 10, 486, map_l7_5ROOT_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, -645, 10, 471, map_l7_6MEAT_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 813, 10, 34, map_l7_7ENGINE_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 885, 10, -923, map_l7_8CHAMBER_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 50, 10, -1194, map_l7_9ELEVATOR_mesh_layer_1),
			GEO_TRANSLATE_NODE(LAYER_OPAQUE, -428, 10, 483),
			GEO_TRANSLATE_NODE(LAYER_OPAQUE, 828, 10, 879),
			GEO_TRANSLATE_NODE(LAYER_OPAQUE, 325, 10, 24),
			GEO_TRANSLATE_NODE(LAYER_OPAQUE, -494, 10, 80),
			GEO_TRANSLATE_NODE(LAYER_OPAQUE, -373, 10, 633),
			GEO_TRANSLATE_NODE(LAYER_OPAQUE, 948, 10, -415),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, map_l7_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
