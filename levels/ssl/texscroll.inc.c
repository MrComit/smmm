void scroll_sts_mat_ssl_dl_PalaceFloor_002_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_PalaceFloor_002_layer1);
	shift_s_down(mat, 10, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_ssl_dl_RedWall_002_layer1() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_RedWall_002_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 15, PACK_TILESIZE(0, 2));
		shift_t(mat, 15, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_ssl_dl_WoodFloorTrophyRoom_002_layer1() {
	static int intervalTex1 = 3;
	static int curInterval1 = 3;
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_WoodFloorTrophyRoom_002_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 16, PACK_TILESIZE(0, 1));
		shift_t(mat, 16, PACK_TILESIZE(0, 2));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_ssl_dl_BooGooContainerTrans_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_BooGooContainerTrans_layer5);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_ssl_dl_EngineWall_layer1() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_EngineWall_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 15, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_ssl_dl_LightBeam_002_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 11;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_LightBeam_002_mesh_layer_5_vtx_0);

	deltaY = (int)(-0.3499999940395355 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sts_mat_ssl_dl_WoodFloorTransparent_002_layer1() {
	static int intervalTex1 = 3;
	static int curInterval1 = 3;
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_WoodFloorTransparent_002_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 17, PACK_TILESIZE(0, 1));
		shift_t(mat, 17, PACK_TILESIZE(0, 2));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_ssl_dl_BooGooContainer_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_BooGooContainer_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_ssl_dl_WoodFloorTransparent_001_layer1() {
	static int intervalTex1 = 3;
	static int curInterval1 = 3;
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_WoodFloorTransparent_001_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 17, PACK_TILESIZE(0, 1));
		shift_t(mat, 17, PACK_TILESIZE(0, 2));
		curInterval1 = intervalTex1;
	}
};

void scroll_ssl_dl_Lava_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 4;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 1.0;
	float frequencyX = 0.10000000149011612;
	float offsetX = 0.0;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 1.0;
	float frequencyY = 0.10000000149011612;
	float offsetY = 0.5;
	Vtx *vertices = segmented_to_virtual(ssl_dl_Lava_mesh_layer_1_vtx_0);

	deltaX = (int)(amplitudeX * frequencyX * coss((frequencyX * timeX + offsetX) * (1024 * 16 - 1) / 6.28318530718) * 0x20);
	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	timeX += 1;	currentY += deltaY;	timeY += 1;
}

void scroll_sts_mat_ssl_dl_Lava_001_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_Lava_001_layer1);
	shift_t(mat, 14, PACK_TILESIZE(0, 1));
};

void scroll_ssl_dl_Lava_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 8;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 1.0;
	float frequencyX = 0.10000000149011612;
	float offsetX = 0.0;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 1.0;
	float frequencyY = 0.10000000149011612;
	float offsetY = 0.5;
	Vtx *vertices = segmented_to_virtual(ssl_dl_Lava_001_mesh_layer_5_vtx_0);

	deltaX = (int)(amplitudeX * frequencyX * coss((frequencyX * timeX + offsetX) * (1024 * 16 - 1) / 6.28318530718) * 0x20);
	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	timeX += 1;	currentY += deltaY;	timeY += 1;
}

void scroll_sts_mat_ssl_dl_LavaTrans_001_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_LavaTrans_001_layer5);
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_ssl_dl_WoodFloor_001_layer1() {
	static int intervalTex1 = 3;
	static int curInterval1 = 3;
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_WoodFloor_001_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 15, PACK_TILESIZE(0, 1));
		shift_t(mat, 15, PACK_TILESIZE(0, 2));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_ssl_dl_NightClouds_001_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_NightClouds_001_layer5);
	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_ssl_dl_NightCloudsNoCol_001_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_NightCloudsNoCol_001_layer5);
	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_ssl_dl_ObservatorySky_001_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_ObservatorySky_001_layer1);
	shift_s(mat, 14, PACK_TILESIZE(0, 2));
};

void scroll_ssl_dl_Observatory_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 68;
	int width = 256 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ssl_dl_Observatory_mesh_layer_1_vtx_0);

	deltaX = (int)(1.0 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ssl_dl_Observatory_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 333;
	int width = 256 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ssl_dl_Observatory_mesh_layer_1_vtx_1);

	deltaX = (int)(1.0 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_sts_mat_ssl_dl_ObservatoryWallDither_001_layer1() {
	static int intervalTex0 = 30;
	static int curInterval0 = 30;
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_ObservatoryWallDither_001_layer1);

	if (--curInterval0 <= 0) {
		shift_s(mat, 12, PACK_TILESIZE(0, 256));
		curInterval0 = intervalTex0;
	}
};

void scroll_sts_mat_ssl_dl_ObservatoryWall_001_layer1() {
	static int intervalTex0 = 30;
	static int curInterval0 = 30;
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_ObservatoryWall_001_layer1);

	if (--curInterval0 <= 0) {
		shift_s(mat, 11, PACK_TILESIZE(0, 256));
		curInterval0 = intervalTex0;
	}
};

void scroll_sts_mat_ssl_dl_LaundryWall_001() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_LaundryWall_001);

	if (--curInterval1 <= 0) {
		shift_s(mat, -1, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_ssl_dl_TideToad_002_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 8;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_TideToad_002_mesh_layer_5_vtx_0);

	deltaY = (int)(-0.20000000298023224 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ssl_dl_TideToad_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 4;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_TideToad_001_mesh_layer_5_vtx_0);

	deltaY = (int)(-0.20000000298023224 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sts_mat_ssl_dl_VaseYellow_001_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_VaseYellow_001_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 4));
};

void scroll_ssl_dl_Steam_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 8;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_Steam_001_mesh_layer_5_vtx_0);

	deltaY = (int)(-1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ssl() {
	scroll_sts_mat_ssl_dl_PalaceFloor_002_layer1();
	scroll_sts_mat_ssl_dl_RedWall_002_layer1();
	scroll_sts_mat_ssl_dl_WoodFloorTrophyRoom_002_layer1();
	scroll_sts_mat_ssl_dl_BooGooContainerTrans_layer5();
	scroll_sts_mat_ssl_dl_EngineWall_layer1();
	scroll_ssl_dl_LightBeam_002_mesh_layer_5_vtx_0();
	scroll_sts_mat_ssl_dl_WoodFloorTransparent_002_layer1();
	scroll_sts_mat_ssl_dl_BooGooContainer_layer1();
	scroll_sts_mat_ssl_dl_WoodFloorTransparent_001_layer1();
	scroll_ssl_dl_Lava_mesh_layer_1_vtx_0();
	scroll_sts_mat_ssl_dl_Lava_001_layer1();
	scroll_ssl_dl_Lava_001_mesh_layer_5_vtx_0();
	scroll_sts_mat_ssl_dl_LavaTrans_001_layer5();
	scroll_sts_mat_ssl_dl_WoodFloor_001_layer1();
	scroll_sts_mat_ssl_dl_NightClouds_001_layer5();
	scroll_sts_mat_ssl_dl_NightCloudsNoCol_001_layer5();
	scroll_sts_mat_ssl_dl_ObservatorySky_001_layer1();
	scroll_ssl_dl_Observatory_mesh_layer_1_vtx_0();
	scroll_ssl_dl_Observatory_mesh_layer_1_vtx_1();
	scroll_sts_mat_ssl_dl_ObservatoryWallDither_001_layer1();
	scroll_sts_mat_ssl_dl_ObservatoryWall_001_layer1();
	scroll_sts_mat_ssl_dl_LaundryWall_001();
	scroll_ssl_dl_TideToad_002_mesh_layer_5_vtx_0();
	scroll_ssl_dl_TideToad_001_mesh_layer_5_vtx_0();
	scroll_sts_mat_ssl_dl_VaseYellow_001_layer1();
	scroll_ssl_dl_Steam_001_mesh_layer_5_vtx_0();
}
