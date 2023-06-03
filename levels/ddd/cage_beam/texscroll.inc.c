void scroll_sts_mat_cage_beam_BooGooContainer_layer5() {
	Gfx *mat = segmented_to_virtual(mat_cage_beam_BooGooContainer_layer5);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_ddd_level_geo_cage_beam() {
	scroll_sts_mat_cage_beam_BooGooContainer_layer5();
}
