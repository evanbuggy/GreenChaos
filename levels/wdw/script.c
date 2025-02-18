#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"
#include "actors/group0.h"

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/wdw/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_wdw_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _wdw_segment_7SegmentRomStart, _wdw_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _grass_yay0SegmentRomStart, _grass_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _wdw_skybox_yay0SegmentRomStart, _wdw_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _wdw_segment_7SegmentRomStart, _wdw_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xb, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd), 
	LOAD_MIO0(0xa, _cloud_floor_skybox_mio0SegmentRomStart, _cloud_floor_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_SQUARE_FLOATING_PLATFORM, wdw_geo_000580), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_ARROW_LIFT, wdw_geo_000598), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_WATER_LEVEL_DIAMOND, wdw_geo_0005C0), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_HIDDEN_PLATFORM, wdw_geo_0005E8), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_EXPRESS_ELEVATOR, wdw_geo_000610), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_RECTANGULAR_FLOATING_PLATFORM, wdw_geo_000628), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_ROTATING_PLATFORM, wdw_geo_000640), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_DOLL, luigi_doll_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_DOLL, luigi_doll_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_DOLL, luigi_doll_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_DOLL, luigi_doll_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_DOLL, luigi_doll_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_DOLL, luigi_doll_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_DOLL, luigi_doll_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_DOLL, luigi_doll_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_DOLL, luigi_doll_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_DOLL, luigi_doll_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_DOLL, luigi_doll_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_DOLL, luigi_doll_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_DOLL, luigi_doll_geo), 

	/* Fast64 begin persistent block [level commands] */
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_DOLL, luigi_doll_geo),
	/* Fast64 end persistent block [level commands] */

	AREA(1, wdw_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x01, LEVEL_ENDING, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 41, 606, 145, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 10754, -2055, 5677, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 5456, -681, 10230, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_LUIGI_DOLL, 5419, -1948, 7351, 0, 180, 0, (0 << 16), bhvCombatEnemy),
		OBJECT(MODEL_WOODEN_SIGNPOST, 837, 447, 4224, 0, -35, 0, (61 << 16), bhvMessagePanel),
		MARIO_POS(0x01, 180, 0, 583, 4760),
		OBJECT(MODEL_RED_COIN, 41, 1374, 2177, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -783, 1951, -8597, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3544, 281, -7051, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 5499, -284, 372, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 5499, -1490, -2230, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 1396, -262, 2177, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 8273, -691, 12318, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 10156, -1621, -1720, 0, 0, 0, (0 << 16), bhvRedCoin),
		OBJECT(MODEL_NONE, 1013, 716, 5253, 0, 90, 0, 0x00000000, bhvHiddenRedCoinStar),
		OBJECT(MODEL_NONE, -2105, 109, 9039, 0, 0, 0, (0 << 24) | (0 << 16) | (60 << 8), bhvRank),
		OBJECT(MODEL_WOODEN_SIGNPOST, -100, 131, -6500, 0, 0, 0, (61 << 16), bhvMessagePanel),
		OBJECT(MODEL_WOODEN_SIGNPOST, 4617, -1064, -2848, 0, 180, 0, (61 << 16), bhvMessagePanel),
		OBJECT(MODEL_WOODEN_SIGNPOST, 4617, -1921, 5832, 0, 180, 0, (61 << 16), bhvMessagePanel),
		OBJECT(MODEL_WOODEN_SIGNPOST, 8278, -690, 13033, 0, -180, 0, (61 << 16), bhvMessagePanel),
		OBJECT(MODEL_WOODEN_SIGNPOST, 4717, -341, 2959, 0, 180, 0, (61 << 16), bhvMessagePanel),
		OBJECT(MODEL_WOODEN_SIGNPOST, 10007, -2039, 7720, 0, 0, 0, (61 << 16), bhvMessagePanel),
		OBJECT(MODEL_WOODEN_SIGNPOST, 10748, -2039, -1920, 0, 0, 0, (61 << 16), bhvMessagePanel),
		OBJECT(MODEL_LUIGI_DOLL, 10761, -2037, 4654, 0, 0, 0, (1 << 16), bhvCombatEnemy),
		OBJECT(MODEL_1UP, 11184, -2037, -1720, 0, 0, 0, (5 << 24) | (14 << 16), bhvSpring),
		OBJECT(MODEL_WF_BUBBLY_TREE, -4986, 1233, -3035, 0, -130, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_NONE, 0, 583, 4760, 0, 180, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(wdw_area_1_collision),
		MACRO_OBJECTS(wdw_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 180, 0, 583, 4760),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
