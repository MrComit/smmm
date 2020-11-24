#include "src/game/envfx_snow.h"

const GeoLayout new_koopa_root_SpoonArma_001[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, new_koopa_root_root_spoon_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout new_koopa_root_KnifeArma_002[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, new_koopa_root_root_knife_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout new_koopa_ForkArma[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(3, geo_switch_bparam2),
		GEO_OPEN_NODE(),
			GEO_NODE_START(),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, new_koopa_root_fork_mesh),
			GEO_CLOSE_NODE(),
			GEO_BRANCH(1, new_koopa_root_SpoonArma_001),
			GEO_BRANCH(1, new_koopa_root_KnifeArma_002),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout new_koopa_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SHADOW(0, 155, 100),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_FORCE, 16384),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, new_koopa_000_offset_001_mesh),
					GEO_OPEN_NODE(),
						GEO_SWITCH_CASE(2, geo_switch_anim_state),
						GEO_OPEN_NODE(),
							GEO_NODE_START(),
							GEO_OPEN_NODE(),
								GEO_ANIMATED_PART(LAYER_OPAQUE, 114, 0, 0, new_koopa_000_offset_002_mesh),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, -29, 39, 60, NULL),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, new_koopa_000_offset_003_mesh),
							GEO_OPEN_NODE(),
								GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, new_koopa_000_offset_004_mesh),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, -29, 39, -60, NULL),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, new_koopa_000_offset_005_mesh),
							GEO_OPEN_NODE(),
								GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, new_koopa_000_offset_006_mesh),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, 55, 25, -73, NULL),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, new_koopa_000_offset_007_mesh),
							GEO_OPEN_NODE(),
								GEO_ANIMATED_PART(LAYER_OPAQUE, 54, 0, 0, new_koopa_000_offset_008_mesh),
								GEO_OPEN_NODE(),
									GEO_SWITCH_CASE(2, geo_switch_level),
									GEO_OPEN_NODE(),
										GEO_NODE_START(),
										GEO_BRANCH(1, new_koopa_ForkArma),
									GEO_CLOSE_NODE(),
								GEO_CLOSE_NODE(),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, 55, 25, 74, NULL),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, new_koopa_000_offset_009_mesh),
							GEO_OPEN_NODE(),
								GEO_ANIMATED_PART(LAYER_OPAQUE, 54, 0, 0, new_koopa_000_offset_010_mesh),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, new_koopa_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};