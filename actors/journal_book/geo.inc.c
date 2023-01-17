#include "src/game/envfx_snow.h"

const GeoLayout journal_book_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, journal_book_Journal_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, journal_book_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
