void scroll_sts_mat_hmc_dl_WoodFloor_layer1() {
	static int intervalTex1 = 3;
	static int curInterval1 = 3;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_WoodFloor_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 21, PACK_TILESIZE(0, 1));
		shift_t(mat, 21, PACK_TILESIZE(0, 2));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_hmc_dl_Wall_layer1() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_Wall_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 21, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_hmc_dl_BooGoo_layer1() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_BooGoo_layer1);
	shift_s(mat, 13, PACK_TILESIZE(0, 1));
	shift_s(mat, 21, PACK_TILESIZE(0, 1));
	shift_t(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_hmc_dl_Painting_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 4;
	int width = 64 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(hmc_dl_Painting_mesh_layer_1_vtx_1);

	deltaX = (int)(-0.5 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_hmc_dl_Painting_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 4;
	int width = 64 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(hmc_dl_Painting_mesh_layer_1_vtx_2);

	deltaX = (int)(0.5 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_hmc_dl_Painting_mesh_layer_1_vtx_4() {
	int i = 0;
	int count = 4;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 2.0;
	float frequencyX = 0.25;
	float offsetX = 0.0;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 2.0;
	float frequencyY = 0.25;
	float offsetY = 32.0;
	Vtx *vertices = segmented_to_virtual(hmc_dl_Painting_mesh_layer_1_vtx_4);

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

void scroll_hmc_dl_Painting_mesh_layer_1_vtx_5() {
	int i = 0;
	int count = 4;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(hmc_dl_Painting_mesh_layer_1_vtx_5);

	deltaX = (int)(7.5 * 0x20 * random_float() * random_sign()) % width;
	deltaY = (int)(10.0 * 0x20 * random_float() * random_sign()) % height;

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
	currentX += deltaX;	currentY += deltaY;
}

void scroll_sts_mat_hmc_dl_Parlor1_layer1() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_Parlor1_layer1);
	shift_t(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_hmc_dl_Cons1_layer1() {
	static int intervalTex0 = 20;
	static int curInterval0 = 20;
	static int intervalTex1 = 20;
	static int curInterval1 = 20;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_Cons1_layer1);

	if (--curInterval0 <= 0) {
		shift_t(mat, 13, PACK_TILESIZE(0, 16));
		curInterval0 = intervalTex0;
	}

	if (--curInterval1 <= 0) {
		shift_t(mat, 21, PACK_TILESIZE(0, 16));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_hmc_dl_CreepyEyes_layer1() {
	static int intervalTex0 = 2;
	static int curInterval0 = 2;
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_CreepyEyes_layer1);

	if (--curInterval0 <= 0) {
		shift_s(mat, 13, PACK_TILESIZE(0, 13));
		shift_t(mat, 13, PACK_TILESIZE(0, 2));
		curInterval0 = intervalTex0;
	}
	shift_s(mat, 21, PACK_TILESIZE(0, 1));
	shift_t(mat, 21, PACK_TILESIZE(0, 6));
};

void scroll_hmc() {
	scroll_sts_mat_hmc_dl_WoodFloor_layer1();
	scroll_sts_mat_hmc_dl_Wall_layer1();
	scroll_sts_mat_hmc_dl_BooGoo_layer1();
	scroll_hmc_dl_Painting_mesh_layer_1_vtx_1();
	scroll_hmc_dl_Painting_mesh_layer_1_vtx_2();
	scroll_hmc_dl_Painting_mesh_layer_1_vtx_4();
	scroll_hmc_dl_Painting_mesh_layer_1_vtx_5();
	scroll_sts_mat_hmc_dl_Parlor1_layer1();
	scroll_sts_mat_hmc_dl_Cons1_layer1();
	scroll_sts_mat_hmc_dl_CreepyEyes_layer1();
}
