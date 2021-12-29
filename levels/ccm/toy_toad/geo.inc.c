#include "src/game/envfx_snow.h"

const GeoLayout toy_toad_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, toy_toad_arms_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 29, 0, toy_toad_body_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 29, 0, toy_toad_bow_mesh_layer_1),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 89, 32, toy_toad_head_mesh_layer_1),
			GEO_CLOSE_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, toy_toad_feet_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, toy_toad_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
