#include "src/game/envfx_snow.h"

const GeoLayout new_koopa_root_ASpoonArma_001[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, new_koopa_root_root_spoon_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout new_koopa_root_AKnifeArma_002[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, new_koopa_root_root_knife_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout new_koopa_AForkArma[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(3, geo_switch_bparam2),
		GEO_OPEN_NODE(),
			GEO_NODE_START(),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, new_koopa_root_fork_mesh_layer_1),
			GEO_CLOSE_NODE(),
			GEO_BRANCH(1, new_koopa_root_ASpoonArma_001),
			GEO_BRANCH(1, new_koopa_root_AKnifeArma_002),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout new_koopa_root_BStaplerArma[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, new_koopa_root_root_dl_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout new_koopa_root_BPenArma[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, new_koopa_root_root_pendl_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout new_koopa_BPhoneArma[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(3, geo_switch_bparam2),
		GEO_OPEN_NODE(),
			GEO_NODE_START(),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, new_koopa_root_phonedl_mesh_layer_1),
			GEO_CLOSE_NODE(),
			GEO_BRANCH(1, new_koopa_root_BStaplerArma),
			GEO_BRANCH(1, new_koopa_root_BPenArma),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout new_koopa_CIcicleArma[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, new_koopa_root_dl_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout new_koopa_root_DHammer[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, new_koopa_root_root_hammer_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout new_koopa_root_DPaddle[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, new_koopa_root_root_paddle_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout new_koopa_DCue[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(3, geo_switch_bparam2),
		GEO_OPEN_NODE(),
			GEO_NODE_START(),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, new_koopa_root_cue_mesh_layer_1),
			GEO_CLOSE_NODE(),
			GEO_BRANCH(1, new_koopa_root_DHammer),
			GEO_BRANCH(1, new_koopa_root_DPaddle),
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
					GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, new_koopa_000_offset_001_mesh_layer_1),
					GEO_OPEN_NODE(),
						GEO_SWITCH_CASE(2, geo_switch_anim_state),
						GEO_OPEN_NODE(),
							GEO_NODE_START(),
							GEO_OPEN_NODE(),
								GEO_ANIMATED_PART(LAYER_OPAQUE, 114, 0, 0, new_koopa_000_offset_002_mesh_layer_1),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, -29, 39, 60, NULL),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, new_koopa_000_offset_003_mesh_layer_1),
							GEO_OPEN_NODE(),
								GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, new_koopa_000_offset_004_mesh_layer_1),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, -29, 39, -60, NULL),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, new_koopa_000_offset_005_mesh_layer_1),
							GEO_OPEN_NODE(),
								GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, new_koopa_000_offset_006_mesh_layer_1),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, 55, 25, -73, NULL),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, new_koopa_000_offset_007_mesh_layer_1),
							GEO_OPEN_NODE(),
								GEO_ANIMATED_PART(LAYER_OPAQUE, 54, 0, 0, new_koopa_000_offset_008_mesh_layer_1),
								GEO_OPEN_NODE(),
									GEO_SWITCH_CASE(6, geo_switch_level),
									GEO_OPEN_NODE(),
										GEO_NODE_START(),
										GEO_BRANCH(1, new_koopa_AForkArma),
										GEO_BRANCH(1, new_koopa_BPhoneArma),
										GEO_BRANCH(1, new_koopa_AForkArma),
										GEO_BRANCH(1, new_koopa_AForkArma),
										GEO_BRANCH(1, new_koopa_CIcicleArma),
										GEO_BRANCH(1, new_koopa_DCue),
									GEO_CLOSE_NODE(),
								GEO_CLOSE_NODE(),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, 55, 25, 74, NULL),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, new_koopa_000_offset_009_mesh_layer_1),
							GEO_OPEN_NODE(),
								GEO_ANIMATED_PART(LAYER_OPAQUE, 54, 0, 0, new_koopa_000_offset_010_mesh_layer_1),
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
