void scroll_sts_mat_hole_wall_BooGooObjWall_layer1() {
	Gfx *mat = segmented_to_virtual(mat_hole_wall_BooGooObjWall_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_ddd_level_geo_hole_wall() {
	scroll_sts_mat_hole_wall_BooGooObjWall_layer1();
}
