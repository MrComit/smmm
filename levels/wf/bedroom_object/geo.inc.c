#include "src/game/envfx_snow.h"

const GeoLayout bedroom_object_2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bedroom_object_Start_2_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bedroom_object_3[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bedroom_object_Start_3_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bedroom_object_4[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bedroom_object_Start_4_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bedroom_object_Start_4_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bedroom_object_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_update_layer_transparency_cutout),
			GEO_SWITCH_CASE(4, geo_switch_bparam2),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_ALPHA, 0, 0, 0, bedroom_object_1_mesh_layer_4),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, bedroom_object_2),
				GEO_BRANCH(1, bedroom_object_3),
				GEO_BRANCH(1, bedroom_object_4),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bedroom_object_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bedroom_object_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
