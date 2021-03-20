#include "src/game/envfx_snow.h"

const GeoLayout dirt_mound_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
		GEO_OPEN_NODE(),
			GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_ALPHA, 0, 0, 0, dirt_mound_Billboard_mesh_layer_4),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, dirt_mound_Reg_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, dirt_mound_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, dirt_mound_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
