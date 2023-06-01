#include "src/game/envfx_snow.h"

const GeoLayout controller_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_TRANSPARENT, 342, -83, 56, controller_LDW_mesh_layer_5),
				GEO_ANIMATED_PART(LAYER_TRANSPARENT, 326, 46, -94, controller_LUW_mesh_layer_5),
				GEO_ANIMATED_PART(LAYER_TRANSPARENT, -342, -83, 56, controller_RDW_mesh_layer_5),
				GEO_ANIMATED_PART(LAYER_TRANSPARENT, -326, 46, -94, controller_RUW_mesh_layer_5),
				GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, controller_body_mesh_layer_5),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, controller_body_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, controller_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, controller_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
