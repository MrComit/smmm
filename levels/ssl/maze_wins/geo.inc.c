#include "src/game/envfx_snow.h"

const GeoLayout maze_wins_MazeWins2nd[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, maze_wins_start_m2_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout maze_wins_MazeWins3rd[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, maze_wins_start_m3_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout maze_wins_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(5, geo_update_layer_transparency_layer),
			GEO_SWITCH_CASE(3, geo_switch_bparam2),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT, maze_wins_m1_mesh_layer_5),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, maze_wins_MazeWins2nd),
				GEO_BRANCH(1, maze_wins_MazeWins3rd),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, maze_wins_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
