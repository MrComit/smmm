#include "src/game/envfx_snow.h"

const GeoLayout l1_thin_book_Green[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -50, 0, 0, 0, 0, -90),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, l1_thin_book_root_Green_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout l1_thin_book_Purple[] = {
	GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -50, 0, 0, 0, 0, -90),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, l1_thin_book_root_Purple_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout l1_thin_book_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(3, geo_switch_bparam2),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -50, 0, 0, 0, 0, -90),
					GEO_OPEN_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, l1_thin_book_Red_mesh),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, l1_thin_book_Green),
				GEO_BRANCH(1, l1_thin_book_Purple),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, l1_thin_book_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
