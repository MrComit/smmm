#include "src/game/envfx_snow.h"

const GeoLayout file_button_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, file_button_FileButton_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, file_button_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
