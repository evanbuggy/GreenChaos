#include "src/game/envfx_snow.h"

const GeoLayout luigi_head_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SHADOW(0, 128, 200),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, luigi_head_geo_000_displaylist_mesh_layer_1),
			GEO_ROTATION_NODE(LAYER_TRANSPARENT, 0, 0, 0),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
