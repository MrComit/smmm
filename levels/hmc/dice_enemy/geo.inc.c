#include "src/game/envfx_snow.h"

const GeoLayout dice_enemy_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_ALPHA, -35, 70, 0, dice_enemy_eyes_mesh_layer_4_mat_override_Eye2_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout dice_enemy_switch_opt2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_ALPHA, -35, 70, 0, dice_enemy_eyes_mesh_layer_4_mat_override_Eye3_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout dice_enemy_switch_opt3[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_ALPHA, -35, 70, 0, dice_enemy_eyes_mesh_layer_4_mat_override_Eye4_2),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout dice_enemy_switch_opt4[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_ALPHA, -35, 70, 0, dice_enemy_eyes_mesh_layer_4_mat_override_Eye5_3),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout dice_enemy_switch_opt5[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_ALPHA, -35, 70, 0, dice_enemy_eyes_mesh_layer_4_mat_override_Eye6_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout dice_enemy_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, 0, 0, 90, 0),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
					GEO_OPEN_NODE(),
						GEO_ASM(1, geo_set_color_env),
						GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 65, 0, dice_enemy_dice_mesh_layer_1),
						GEO_SWITCH_CASE(6, geo_switch_anim_state),
						GEO_OPEN_NODE(),
							GEO_NODE_START(),
							GEO_OPEN_NODE(),
								GEO_ANIMATED_PART(LAYER_ALPHA, -35, 70, 0, dice_enemy_eyes_mesh_layer_4),
							GEO_CLOSE_NODE(),
							GEO_BRANCH(1, dice_enemy_switch_opt1),
							GEO_BRANCH(1, dice_enemy_switch_opt2),
							GEO_BRANCH(1, dice_enemy_switch_opt3),
							GEO_BRANCH(1, dice_enemy_switch_opt4),
							GEO_BRANCH(1, dice_enemy_switch_opt5),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
					GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 30, -23, dice_enemy_leg1_mesh_layer_1),
					GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 30, 23, dice_enemy_leg2_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, dice_enemy_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, dice_enemy_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
