#include "src/game/envfx_snow.h"

const GeoLayout luigi_bomb_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, luigi_bomb_luigi_bomb_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
