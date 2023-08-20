void scroll_sts_mat_ttc_dl_WoodFloorTrophyRoom_002_layer1() {
	static int intervalTex1 = 3;
	static int curInterval1 = 3;
	Gfx *mat = segmented_to_virtual(mat_ttc_dl_WoodFloorTrophyRoom_002_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 16, PACK_TILESIZE(0, 1));
		shift_t(mat, 16, PACK_TILESIZE(0, 2));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_ttc_dl_RedWall_002_layer1() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_ttc_dl_RedWall_002_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 15, PACK_TILESIZE(0, 2));
		shift_t(mat, 15, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_ttc_dl_TideToad_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 8;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ttc_dl_TideToad_mesh_layer_5_vtx_0);

	deltaY = (int)(-0.20000000298023224 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sts_mat_ttc_dl_WoodPlat_layer1() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_ttc_dl_WoodPlat_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 15, PACK_TILESIZE(0, 1));
		shift_t(mat, 15, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_ttc_dl_Treadmill_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 122;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ttc_dl_Treadmill_mesh_layer_1_vtx_1);

	deltaY = (int)(2.799999952316284 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sts_mat_ttc_dl_Treadmill_layer1() {
	static int intervalTex0 = 2;
	static int curInterval0 = 2;
	Gfx *mat = segmented_to_virtual(mat_ttc_dl_Treadmill_layer1);

	if (--curInterval0 <= 0) {
		shift_t_down(mat, 10, PACK_TILESIZE(0, 1));
		curInterval0 = intervalTex0;
	}
};

void scroll_ttc() {
	scroll_sts_mat_ttc_dl_WoodFloorTrophyRoom_002_layer1();
	scroll_sts_mat_ttc_dl_RedWall_002_layer1();
	scroll_ttc_dl_TideToad_mesh_layer_5_vtx_0();
	scroll_sts_mat_ttc_dl_WoodPlat_layer1();
	scroll_ttc_dl_Treadmill_mesh_layer_1_vtx_1();
	scroll_sts_mat_ttc_dl_Treadmill_layer1();
}
