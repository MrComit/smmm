#include "src/game/envfx_snow.h"

const GeoLayout ice_cube_cracked_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ice_cube_cracked_IceCubeCracked_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ice_cube_cracked_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};