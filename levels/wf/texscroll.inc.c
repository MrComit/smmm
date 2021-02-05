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
void scroll_wf() {
	scroll_wf_dl_Hallway_mesh_layer_1_vtx_4();
}
