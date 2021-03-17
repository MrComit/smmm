#include "src/game/envfx_snow.h"

const GeoLayout sunflower_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_set_brightness_env),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, sunflower_Stem_mesh_layer_1),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, sunflower_Flower_skinned_mesh_layer_1),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 111, 0, -90, 0, -90),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, sunflower_Flower_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sunflower_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
