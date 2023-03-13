#include "src/game/envfx_snow.h"

const GeoLayout map_l1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, -1021, 10, 865, map_l1_10STUDY_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, -844, 10, 1475, map_l1_11LIBRARY_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, -471, 10, 1381, map_l1_12HALLWAY2_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 15, 10, 1166, map_l1_13HALLWAY3_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, -238, 10, 1166, map_l1_14TREASURY_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 10, 2824, map_l1_1MUDROOM_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 10, 1993, map_l1_2MAINHALL_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 455, 10, 1383, map_l1_3PARLOR_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 465, 10, 1665, map_l1_4GARAGE_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, -145, 10, 685, map_l1_5HALLWAYS_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 717, 10, 536, map_l1_6DINING_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 230, 10, 449, map_l1_7KITCHEN_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 78, 10, 438, map_l1_8PANTRY_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, -569, 10, 723, map_l1_9LIVING_mesh_layer_1),
			GEO_TRANSLATE_NODE(LAYER_OPAQUE, 395, 10, 793),
			GEO_TRANSLATE_NODE(LAYER_OPAQUE, 0, 10, 1271),
			GEO_TRANSLATE_NODE(LAYER_OPAQUE, -140, 10, 1166),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, map_l1_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};