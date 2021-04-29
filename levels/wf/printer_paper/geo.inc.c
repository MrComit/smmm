#include "src/game/envfx_snow.h"

const GeoLayout printer_paper_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(1, printer_paper_Paper_mesh_layer_1),
		GEO_DISPLAY_LIST(1, printer_paper_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
