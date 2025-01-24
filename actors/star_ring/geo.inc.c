#include "src/game/envfx_snow.h"

const GeoLayout star_ring_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SHADOW(0, 155, 500),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_FORCE, 16384),
			GEO_OPEN_NODE(),
				GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_OPAQUE, 0, 0, 0, star_ring_emerald_mesh_layer_1),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, star_ring_ring_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
