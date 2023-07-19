void scroll_sts_mat_bob_dl_BooGoo_001_layer1() {
	Gfx *mat = segmented_to_virtual(mat_bob_dl_BooGoo_001_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_bob_dl_Vase_v4_003_layer1() {
	Gfx *mat = segmented_to_virtual(mat_bob_dl_Vase_v4_003_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 4));
};

void scroll_bob_dl_KitchenGround_005_mesh_layer_5_vtx_0() {
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
	Vtx *vertices = segmented_to_virtual(bob_dl_KitchenGround_005_mesh_layer_5_vtx_0);

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

void scroll_bob_dl_Steam_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 8;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bob_dl_Steam_mesh_layer_5_vtx_0);

	deltaY = (int)(-1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bob() {
	scroll_sts_mat_bob_dl_BooGoo_001_layer1();
	scroll_sts_mat_bob_dl_Vase_v4_003_layer1();
	scroll_bob_dl_KitchenGround_005_mesh_layer_5_vtx_0();
	scroll_bob_dl_Steam_mesh_layer_5_vtx_0();
}
