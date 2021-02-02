#include "src/game/envfx_snow.h"

const GeoLayout heavyobject_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, heavyobject_Body_mesh_layer_1),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, 0, -90, 0, -90),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
				GEO_OPEN_NODE(),
					GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, 0, 0, 90, 90),
					GEO_OPEN_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, heavyobject_Sphere_mesh_layer_1),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, heavyobject_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
