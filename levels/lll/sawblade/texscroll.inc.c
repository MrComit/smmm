void scroll_sts_mat_sawblade_Sawblade2D() {
	Gfx *mat = segmented_to_virtual(mat_sawblade_Sawblade2D);
	shift_s(mat, 19, PACK_TILESIZE(0, 128));
};

void scroll_lll_level_geo_sawblade() {
	scroll_sts_mat_sawblade_Sawblade2D();
}
