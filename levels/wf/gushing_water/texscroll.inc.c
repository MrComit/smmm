void scroll_gushing_water_Water_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 30;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(gushing_water_Water_mesh_layer_5_vtx_0);

	deltaX = (int)(30.0 * 0x20) % width;
	deltaY = (int)(20.0 * 0x20) % height;

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
void scroll_gushing_water_Water_mesh_layer_6_vtx_0() {
	int i = 0;
	int count = 24;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(gushing_water_Water_mesh_layer_6_vtx_0);

	deltaY = (int)(12.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;

}
void scroll_wf_level_geo_gushing_water() {
	scroll_gushing_water_Water_mesh_layer_5_vtx_0();
	scroll_gushing_water_Water_mesh_layer_6_vtx_0();
}
