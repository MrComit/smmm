#include "src/game/envfx_snow.h"

const GeoLayout lever_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, lever_base_mesh),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, 0, -90, 0, -90),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
				GEO_OPEN_NODE(),
					GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, 0, 0, 90, 90),
					GEO_OPEN_NODE(),
						GEO_ANIMATED_PART(LAYER_ALPHA, 0, 0, 0, lever_ball_mesh),
					GEO_CLOSE_NODE(),
					GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, 0, 0, 90, 90),
					GEO_OPEN_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, lever_handle_mesh),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lever_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, lever_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
