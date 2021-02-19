#include "src/game/envfx_snow.h"

const GeoLayout boocoin_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(4, boocoin_BooCoin_mesh_layer_4),
		GEO_DISPLAY_LIST(4, boocoin_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
