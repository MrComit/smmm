#include "src/game/envfx_snow.h"

const GeoLayout plat_hall_wall_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, plat_hall_wall_platwall_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout plat_hall_wall_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_update_layer_transparency),
			GEO_SWITCH_CASE(2, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, plat_hall_wall_platwall_mesh_layer_1),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, plat_hall_wall_switch_opt1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, plat_hall_wall_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, plat_hall_wall_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
