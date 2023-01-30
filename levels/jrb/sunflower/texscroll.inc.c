void scroll_sts_mat_sunflower_FlowerPetal_002_layer1() {
	Gfx *mat = segmented_to_virtual(mat_sunflower_FlowerPetal_002_layer1);
	shift_t_down(mat, 21, PACK_TILESIZE(0, 2));
};

void scroll_jrb_level_geo_sunflower() {
	scroll_sts_mat_sunflower_FlowerPetal_002_layer1();
}
