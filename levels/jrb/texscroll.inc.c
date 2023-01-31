void scroll_sts_mat_jrb_dl_BooGoo_001_layer1() {
	Gfx *mat = segmented_to_virtual(mat_jrb_dl_BooGoo_001_layer1);
	shift_s(mat, 13, PACK_TILESIZE(0, 1));
	shift_s(mat, 21, PACK_TILESIZE(0, 1));
	shift_t(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_jrb_dl_Ground_002_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 16;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 1.0;
	float frequencyX = 0.15000000596046448;
	float offsetX = 32.0;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 1.0;
	float frequencyY = 0.15000000596046448;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(jrb_dl_Ground_002_mesh_layer_1_vtx_1);

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

void scroll_sts_mat_jrb_dl_Lava_001_layer1() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_jrb_dl_Lava_001_layer1);

	if (--curInterval1 <= 0) {
		shift_s(mat, 20, PACK_TILESIZE(0, 1));
		shift_t(mat, 20, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_jrb() {
	scroll_sts_mat_jrb_dl_BooGoo_001_layer1();
	scroll_jrb_dl_Ground_002_mesh_layer_1_vtx_1();
	scroll_sts_mat_jrb_dl_Lava_001_layer1();
}
