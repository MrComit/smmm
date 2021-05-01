#include "src/game/envfx_snow.h"

const GeoLayout shadow_boss_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(6, geo_set_color_env),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, shadow_boss_dl_mesh_layer_1),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, shadow_boss_dl_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, shadow_boss_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, shadow_boss_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
