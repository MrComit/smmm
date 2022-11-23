void scroll_sts_mat_lll_dl_CorridorWall_layer1() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_lll_dl_CorridorWall_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 21, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_lll_dl_Fog_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 20;
	int width = 32 * 0x20;
	int height = 128 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(lll_dl_Fog_mesh_layer_5_vtx_0);

	deltaY = (int)(0.10000000149011612 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sts_mat_lll_dl_Fog_001_layer5() {
	static int intervalTex1 = 3;
	static int curInterval1 = 3;
	Gfx *mat = segmented_to_virtual(mat_lll_dl_Fog_001_layer5);

	if (--curInterval1 <= 0) {
		shift_s_down(mat, 21, PACK_TILESIZE(0, 1));
		shift_t(mat, 21, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_lll_dl_LaundryWall_002() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_lll_dl_LaundryWall_002);

	if (--curInterval1 <= 0) {
		shift_s(mat, -1, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_lll_dl_TideToad_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 12;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(lll_dl_TideToad_mesh_layer_5_vtx_0);

	deltaY = (int)(-0.20000000298023224 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sts_mat_lll_dl_GymWall() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_lll_dl_GymWall);

	if (--curInterval1 <= 0) {
		shift_s(mat, -1, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_lll_dl_CellarWall() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_lll_dl_CellarWall);

	if (--curInterval1 <= 0) {
		shift_s(mat, -1, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_lll_dl_LockerWall_001() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_lll_dl_LockerWall_001);

	if (--curInterval1 <= 0) {
		shift_s(mat, -1, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_lll_dl_BooGooContainer_layer1() {
	Gfx *mat = segmented_to_virtual(mat_lll_dl_BooGooContainer_layer1);
	shift_s(mat, 13, PACK_TILESIZE(0, 1));
	shift_s(mat, 21, PACK_TILESIZE(0, 1));
	shift_t(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_lll_dl_EngineWall_layer1() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_lll_dl_EngineWall_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 21, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_lll_dl_BooGoo_layer1() {
	Gfx *mat = segmented_to_virtual(mat_lll_dl_BooGoo_layer1);
	shift_s(mat, 13, PACK_TILESIZE(0, 1));
	shift_s(mat, 21, PACK_TILESIZE(0, 1));
	shift_t(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_lll_dl_Buttons_layer1() {
	static int intervalTex1 = 15;
	static int curInterval1 = 15;
	Gfx *mat = segmented_to_virtual(mat_lll_dl_Buttons_layer1);

	if (--curInterval1 <= 0) {
		shift_t(mat, 21, PACK_TILESIZE(0, 128));
		curInterval1 = intervalTex1;
	}
};

void scroll_lll_dl_EngineRoom_002_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 24;
	int width = 32 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(lll_dl_EngineRoom_002_mesh_layer_5_vtx_0);

	deltaY = (int)(-1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_lll() {
	scroll_sts_mat_lll_dl_CorridorWall_layer1();
	scroll_lll_dl_Fog_mesh_layer_5_vtx_0();
	scroll_sts_mat_lll_dl_Fog_001_layer5();
	scroll_sts_mat_lll_dl_LaundryWall_002();
	scroll_lll_dl_TideToad_mesh_layer_5_vtx_0();
	scroll_sts_mat_lll_dl_GymWall();
	scroll_sts_mat_lll_dl_CellarWall();
	scroll_sts_mat_lll_dl_LockerWall_001();
	scroll_sts_mat_lll_dl_BooGooContainer_layer1();
	scroll_sts_mat_lll_dl_EngineWall_layer1();
	scroll_sts_mat_lll_dl_BooGoo_layer1();
	scroll_sts_mat_lll_dl_Buttons_layer1();
	scroll_lll_dl_EngineRoom_002_mesh_layer_5_vtx_0();
}
