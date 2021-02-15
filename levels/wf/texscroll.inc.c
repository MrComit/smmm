void scroll_wf_dl_Hallway_mesh_layer_1_vtx_4() {
	int i = 0;
	int count = 5;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_Hallway_mesh_layer_1_vtx_4);

	deltaY = (int)(0.3499999940395355 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;

}
void scroll_wf_dl_Hallway_005_mesh_layer_6_vtx_0() {
	int i = 0;
	int count = 74;
	int width = 64 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(wf_dl_Hallway_005_mesh_layer_6_vtx_0);

	deltaX = (int)(0.3499999940395355 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;

}
void scroll_wf_dl_Cloud_002_mesh_layer_4_vtx_0() {
	int i = 0;
	int count = 24;
	int width = 16 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_Cloud_002_mesh_layer_4_vtx_0);

	deltaX = (int)(4.849999904632568 * 0x20 * random_float() * random_sign()) % width;
	deltaY = (int)(3.0799999237060547 * 0x20 * random_float() * random_sign()) % height;

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
	currentX += deltaX;
	currentY += deltaY;

}
void scroll_wf_dl_Lightning_mesh_layer_4_vtx_0() {
	int i = 0;
	int count = 24;
	int width = 16 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_Lightning_mesh_layer_4_vtx_0);

	deltaX = (int)(4.849999904632568 * 0x20 * random_float() * random_sign()) % width;
	deltaY = (int)(3.0799999237060547 * 0x20 * random_float() * random_sign()) % height;

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
	currentX += deltaX;
	currentY += deltaY;

}
void scroll_wf() {
	scroll_wf_dl_Hallway_mesh_layer_1_vtx_4();
	scroll_wf_dl_Hallway_005_mesh_layer_6_vtx_0();
	scroll_wf_dl_Cloud_002_mesh_layer_4_vtx_0();
	scroll_wf_dl_Lightning_mesh_layer_4_vtx_0();
}
