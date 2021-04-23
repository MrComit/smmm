#include "src/game/envfx_snow.h"

const GeoLayout pressure_plate_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_set_color_env),
			GEO_DISPLAY_LIST(5, pressure_plate_dl_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(5, pressure_plate_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
