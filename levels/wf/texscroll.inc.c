void scroll_wf_dl_Hallway_005_mesh_layer_6_vtx_0() {
	int i = 0;
	int count = 72;
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
void scroll_wf_dl_Hallway_005_mesh_layer_1_vtx_4() {
	int i = 0;
	int count = 5;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_Hallway_005_mesh_layer_1_vtx_4);

	deltaY = (int)(0.3499999940395355 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;

}
void scroll_wf_dl_Steam_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 24;
	int width = 32 * 0x20;
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
void scroll_wf_dl_Den_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 24;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_Den_mesh_layer_1_vtx_3);

	deltaY = (int)(0.3499999940395355 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;

}
void scroll_wf_dl_Servant_s_Quarters_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 8;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_Servant_s_Quarters_mesh_layer_1_vtx_3);

	deltaY = (int)(0.3499999940395355 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;

}
void scroll_wf_dl_Office_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 17;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_Office_mesh_layer_1_vtx_3);

	deltaY = (int)(0.3499999940395355 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;

}
void scroll_wf() {
	scroll_wf_dl_Hallway_005_mesh_layer_6_vtx_0();
	scroll_wf_dl_Hallway_005_mesh_layer_1_vtx_4();
	scroll_wf_dl_Steam_mesh_layer_5_vtx_0();
	scroll_wf_dl_Den_mesh_layer_1_vtx_3();
	scroll_wf_dl_Servant_s_Quarters_mesh_layer_1_vtx_3();
	scroll_wf_dl_Office_mesh_layer_1_vtx_3();
}
