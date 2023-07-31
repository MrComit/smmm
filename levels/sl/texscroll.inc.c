void scroll_sts_mat_sl_dl_Wall_002() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_sl_dl_Wall_002);

	if (--curInterval1 <= 0) {
		shift_s(mat, -1, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_sl_dl_FlowerPetal_002_v4_002_layer1() {
	Gfx *mat = segmented_to_virtual(mat_sl_dl_FlowerPetal_002_v4_002_layer1);
	shift_t_down(mat, 15, PACK_TILESIZE(0, 2));
};

void scroll_sl_dl_KitchenGround_005_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 4;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 0.20000000298023224;
	float frequencyX = 0.20000000298023224;
	float offsetX = 0.0;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.20000000298023224;
	float frequencyY = 0.20000000298023224;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(sl_dl_KitchenGround_005_mesh_layer_5_vtx_0);

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

void scroll_sl_dl_Treadmill_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 86;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(sl_dl_Treadmill_mesh_layer_1_vtx_1);

	deltaY = (int)(2.799999952316284 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sts_mat_sl_dl_Treadmill_layer1() {
	static int intervalTex0 = 2;
	static int curInterval0 = 2;
	Gfx *mat = segmented_to_virtual(mat_sl_dl_Treadmill_layer1);

	if (--curInterval0 <= 0) {
		shift_t_down(mat, 10, PACK_TILESIZE(0, 1));
		curInterval0 = intervalTex0;
	}
};

void scroll_sl_dl_KitchenGround_003_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 4;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 0.20000000298023224;
	float frequencyX = 0.20000000298023224;
	float offsetX = 0.0;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.20000000298023224;
	float frequencyY = 0.20000000298023224;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(sl_dl_KitchenGround_003_mesh_layer_5_vtx_0);

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

void scroll_sl() {
	scroll_sts_mat_sl_dl_Wall_002();
	scroll_sts_mat_sl_dl_FlowerPetal_002_v4_002_layer1();
	scroll_sl_dl_KitchenGround_005_mesh_layer_5_vtx_0();
	scroll_sl_dl_Treadmill_mesh_layer_1_vtx_1();
	scroll_sts_mat_sl_dl_Treadmill_layer1();
	scroll_sl_dl_KitchenGround_003_mesh_layer_5_vtx_0();
}
