void scroll_bob_dl_ArrowSIgn_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 8;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bob_dl_ArrowSIgn_mesh_layer_1_vtx_0);

	deltaX = (int)(-3.0 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_bob_dl_ArrowSign2_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 8;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bob_dl_ArrowSign2_mesh_layer_1_vtx_0);

	deltaX = (int)(-3.0 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_bob_dl_ArrowSign2_001_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 24;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bob_dl_ArrowSign2_001_mesh_layer_1_vtx_0);

	deltaX = (int)(-3.0 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_bob() {
	scroll_bob_dl_ArrowSIgn_mesh_layer_1_vtx_0();
	scroll_bob_dl_ArrowSign2_mesh_layer_1_vtx_0();
	scroll_bob_dl_ArrowSign2_001_mesh_layer_1_vtx_0();
};
