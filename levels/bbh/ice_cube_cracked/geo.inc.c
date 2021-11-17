#include "src/game/envfx_snow.h"

const GeoLayout ice_cube_cracked_IceCubeBonus_001[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ice_cube_cracked_root_dl_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ice_cube_cracked_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ice_cube_cracked_dl_mesh_layer_5),
			GEO_SWITCH_CASE(2, geo_switch_bparam2),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ice_cube_cracked_dl2_mesh_layer_5),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, ice_cube_cracked_IceCubeBonus_001),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ice_cube_cracked_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
