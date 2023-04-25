void scroll_sts_mat_ssl_dl_RedWall_001_layer1() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_RedWall_001_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 15, PACK_TILESIZE(0, 2));
		shift_t(mat, 15, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_ssl_dl_WoodFloorTrophyRoom_001_layer1() {
	static int intervalTex1 = 3;
	static int curInterval1 = 3;
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_WoodFloorTrophyRoom_001_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 16, PACK_TILESIZE(0, 1));
		shift_t(mat, 16, PACK_TILESIZE(0, 2));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_ssl_dl_BooGoo_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_BooGoo_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_ssl_dl_PalaceFloor_001_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_PalaceFloor_001_layer1);
	shift_s_down(mat, 10, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_ssl_dl_BooGooContainer_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_BooGooContainer_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_ssl() {
	scroll_sts_mat_ssl_dl_RedWall_001_layer1();
	scroll_sts_mat_ssl_dl_WoodFloorTrophyRoom_001_layer1();
	scroll_sts_mat_ssl_dl_BooGoo_layer1();
	scroll_sts_mat_ssl_dl_PalaceFloor_001_layer1();
	scroll_sts_mat_ssl_dl_BooGooContainer_layer1();
}
