#include "src/game/envfx_snow.h"

const GeoLayout poochy_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, poochy_Body_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, poochy_BLFoot_skinned_mesh_layer_1),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, poochy_BLFoot_mesh_layer_1),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, poochy_BRFoot_skinned_mesh_layer_1),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, poochy_BRFoot_mesh_layer_1),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, poochy_FLFoot_skinned_mesh_layer_1),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, poochy_FLFoot_mesh_layer_1),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, poochy_FRFoot_skinned_mesh_layer_1),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, poochy_FRFoot_mesh_layer_1),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, poochy_Face_skinned_mesh_layer_1),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, poochy_Face_mesh_layer_1),
			GEO_CLOSE_NODE(),
			GEO_ANIMATED_PART(LAYER_ALPHA, 0, 0, 0, poochy_Tail_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, poochy_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, poochy_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
