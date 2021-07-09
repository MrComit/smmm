void scroll_bbh_dl_Water_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 12;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 4.0;
	float frequencyX = 0.10000000149011612;
	float offsetX = 32.0;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 4.0;
	float frequencyY = 0.10000000149011612;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(bbh_dl_Water_mesh_layer_5_vtx_0);

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
	currentX += deltaX;
	timeX += 1;
	currentY += deltaY;
	timeY += 1;

}
void scroll_bbh_dl_Waterfall_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 30;
	int width = 32 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bbh_dl_Waterfall_mesh_layer_5_vtx_0);

	deltaY = (int)(1.5 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;

}
void scroll_bbh_dl_Waterfall_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 21;
	int width = 32 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bbh_dl_Waterfall_mesh_layer_5_vtx_1);

	deltaY = (int)(0.5 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;

}
void scroll_bbh_dl_Waterfall_mesh_layer_5_vtx_2() {
	int i = 0;
	int count = 6;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 4.0;
	float frequencyX = 0.10000000149011612;
	float offsetX = 32.0;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 4.0;
	float frequencyY = 0.10000000149011612;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(bbh_dl_Waterfall_mesh_layer_5_vtx_2);

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
	currentX += deltaX;
	timeX += 1;
	currentY += deltaY;
	timeY += 1;

}
void scroll_bbh() {
	scroll_bbh_dl_Water_mesh_layer_5_vtx_0();
	scroll_bbh_dl_Waterfall_mesh_layer_5_vtx_0();
	scroll_bbh_dl_Waterfall_mesh_layer_5_vtx_1();
	scroll_bbh_dl_Waterfall_mesh_layer_5_vtx_2();
}
