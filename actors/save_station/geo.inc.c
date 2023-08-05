#include "src/game/envfx_snow.h"

const GeoLayout save_station_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, save_station_SaveStation_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, save_station_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
