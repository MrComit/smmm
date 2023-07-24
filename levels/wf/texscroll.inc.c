void scroll_sts_mat_wf_dl_SolidQuicksand_001_layer1() {
	Gfx *mat = segmented_to_virtual(mat_wf_dl_SolidQuicksand_001_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_wf_dl_Hallway_007_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 74;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(wf_dl_Hallway_007_mesh_layer_5_vtx_0);

	deltaX = (int)(0.3499999940395355 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_wf_dl_Steam_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 24;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_Steam_mesh_layer_5_vtx_0);

	deltaY = (int)(-1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_wf_dl_PoolRoom_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 8;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 2.0;
	float frequencyX = 0.05000000074505806;
	float offsetX = 32.0;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 2.0;
	float frequencyY = 0.05000000074505806;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(wf_dl_PoolRoom_mesh_layer_5_vtx_0);

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

void scroll_wf() {
	scroll_sts_mat_wf_dl_SolidQuicksand_001_layer1();
	scroll_wf_dl_Hallway_007_mesh_layer_5_vtx_0();
	scroll_wf_dl_Steam_mesh_layer_5_vtx_0();
	scroll_wf_dl_PoolRoom_mesh_layer_5_vtx_0();
}
