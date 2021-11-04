#include "src/game/envfx_snow.h"

const GeoLayout sand_mound_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sand_mound_Mound_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, sand_mound_Mound_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sand_mound_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, sand_mound_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
