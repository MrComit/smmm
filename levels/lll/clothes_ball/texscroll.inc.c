void scroll_sts_mat_clothes_ball_ClothesBall2_layer1() {
	Gfx *mat = segmented_to_virtual(mat_clothes_ball_ClothesBall2_layer1);
	shift_t(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_lll_level_geo_clothes_ball() {
	scroll_sts_mat_clothes_ball_ClothesBall2_layer1();
}
