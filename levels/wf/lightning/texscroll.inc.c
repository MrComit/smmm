void scroll_lightning_lightning_mesh_layer_4_vtx_0() {
	int i = 0;
	int count = 24;
	int width = 16 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(lightning_lightning_mesh_layer_4_vtx_0);

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
void scroll_wf_level_geo_lightning() {
	scroll_lightning_lightning_mesh_layer_4_vtx_0();
}
