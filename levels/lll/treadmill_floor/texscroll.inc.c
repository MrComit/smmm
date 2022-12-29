void scroll_treadmill_floor_tfloor_mesh_layer_4_vtx_0() {
	int i = 0;
	int count = 4;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(treadmill_floor_tfloor_mesh_layer_4_vtx_0);

	deltaY = (int)(5.599999904632568 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_treadmill_floor_tfloor_mesh_layer_4_vtx_1() {
	int i = 0;
	int count = 4;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(treadmill_floor_tfloor_mesh_layer_4_vtx_1);

	deltaY = (int)(5.599999904632568 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_lll_level_geo_treadmill_floor() {
	scroll_treadmill_floor_tfloor_mesh_layer_4_vtx_0();
	scroll_treadmill_floor_tfloor_mesh_layer_4_vtx_1();
}
