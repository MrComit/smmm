#include "src/game/envfx_snow.h"

const GeoLayout boss_graphic_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_ALPHA, 0, 0, 0, boss_graphic_graphic_mesh_layer_4_mat_override_BamGraphic_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout boss_graphic_switch_opt2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_ALPHA, 0, 0, 0, boss_graphic_graphic_mesh_layer_4_mat_override_WhamGraphic_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout boss_graphic_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(3, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_ALPHA, 0, 0, 0, boss_graphic_graphic_mesh_layer_4),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, boss_graphic_switch_opt1),
				GEO_BRANCH(1, boss_graphic_switch_opt2),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, boss_graphic_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
