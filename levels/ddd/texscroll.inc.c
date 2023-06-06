void scroll_sts_mat_ddd_dl_BooGooObjWall_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_BooGooObjWall_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_ddd_dl_BooGooDropperPillars_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_BooGooDropperPillars_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_ddd_dl_BooGooObjWall_001_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_BooGooObjWall_001_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_ddd_dl_MountainExterior_002_mesh_layer_4_vtx_0() {
	int i = 0;
	int count = 48;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ddd_dl_MountainExterior_002_mesh_layer_4_vtx_0);

	deltaY = (int)(0.5 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ddd() {
	scroll_sts_mat_ddd_dl_BooGooObjWall_layer1();
	scroll_sts_mat_ddd_dl_BooGooDropperPillars_layer1();
	scroll_sts_mat_ddd_dl_BooGooObjWall_001_layer1();
	scroll_ddd_dl_MountainExterior_002_mesh_layer_4_vtx_0();
}
