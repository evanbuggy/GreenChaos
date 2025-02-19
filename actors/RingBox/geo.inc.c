#include "src/game/envfx_snow.h"

const GeoLayout RingBox_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, RingBox_RingBox_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, RingBox_RingBox_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
