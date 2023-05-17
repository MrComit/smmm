void scroll_sts_mat_mem_morning_obj_VaseYellow_layer1() {
	Gfx *mat = segmented_to_virtual(mat_mem_morning_obj_VaseYellow_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 4));
};

void scroll_ssl_level_geo_mem_morning_obj() {
	scroll_sts_mat_mem_morning_obj_VaseYellow_layer1();
}
