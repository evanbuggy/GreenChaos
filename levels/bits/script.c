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
#include "make_const_nonconst.h"
#include "levels/bits/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bits_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bits_segment_7SegmentRomStart, _bits_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _wdw_skybox_yay0SegmentRomStart, _wdw_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _sky_yay0SegmentRomStart, _sky_yay0SegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0xb, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_15), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, bits_geo_000430), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, bits_geo_000448), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_05, bits_geo_000460), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_06, bits_geo_000478), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_07, bits_geo_000490), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_08, bits_geo_0004A8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_09, bits_geo_0004C0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0A, bits_geo_0004D8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0B, bits_geo_0004F0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0C, bits_geo_000508), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0D, bits_geo_000520), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0E, bits_geo_000538), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0F, bits_geo_000550), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_10, bits_geo_000568), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_11, bits_geo_000580), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_12, bits_geo_000598), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_13, bits_geo_0005B0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_14, bits_geo_0005C8), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_SLIDING_PLATFORM, bits_geo_0005E0), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_TWIN_SLIDING_PLATFORMS, bits_geo_0005F8), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_OCTAGONAL_PLATFORM, bits_geo_000610), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_BLUE_PLATFORM, bits_geo_000628), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_FERRIS_WHEEL_AXLE, bits_geo_000640), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_ARROW_PLATFORM, bits_geo_000658), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_SEESAW_PLATFORM, bits_geo_000670), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_TILTING_W_PLATFORM, bits_geo_000688), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_STAIRCASE, bits_geo_0006A0), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_STAIRCASE_FRAME1, bits_geo_0006B8), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_STAIRCASE_FRAME2, bits_geo_0006D0), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_STAIRCASE_FRAME3, bits_geo_0006E8), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_STAIRCASE_FRAME4, bits_geo_000700), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_TREE, bg_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_TREE, bg_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_TREE, bg_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_TREE, bg_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_TREE, bg_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_TREE, bg_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_TREE, bg_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_TREE, bg_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_TREE, bg_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_TREE, bg_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_TREE, bg_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_TREE, bg_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_TREE, bg_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_TREE, bg_tree_geo), 
	/* Fast64 begin persistent block [level commands] */
	LOAD_MODEL_FROM_GEO(MODEL_MR_L, mr_l_geo),
	LOAD_MODEL_FROM_GEO(MODEL_LUIGI_BOMB, luigi_bomb_geo),
	LOAD_MODEL_FROM_GEO(MODEL_BITS_TREE,  bg_tree_geo),
	/* Fast64 end persistent block [level commands] */

	AREA(1, bits_area_1),
		WARP_NODE(0x0A, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE_GROUNDS, 0x02, 0x08, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_MR_L, 0, -360, -679, 0, 0, 0, 0x00000000, bhvBossLuigi),
		MARIO_POS(0x01, 180, 0, 1625, 847),
		OBJECT(MODEL_YELLOW_COIN, 1073, -403, 3, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -1082, -403, 3, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 0, -403, -1060, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 0, -403, 1065, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_NONE, 0, 1625, 847, 0, 180, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, 1634, -270, 0, 0, 0, 0, (0 << 24) | (0 << 16) | (30 << 8), bhvRank),
		OBJECT(MODEL_BITS_TREE, -3495, 20, -4250, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BITS_TREE, -3198, -89, -4776, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BITS_TREE, -4312, -21, -3156, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BITS_TREE, 4794, 930, -5582, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BITS_TREE, 4427, 682, -6606, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BITS_TREE, 4484, 1600, 4192, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BITS_TREE, 4962, 2004, 4766, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BITS_TREE, -1368, -701, -7823, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BITS_TREE, -2579, 499, -7315, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BITS_TREE, -944, -900, -6171, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BITS_TREE, -6100, -140, 431, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BITS_TREE, -4725, -286, 431, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BITS_TREE, -5715, 246, -3156, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BITS_TREE, -4542, 654, -5274, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BITS_TREE, -2263, -24, -5928, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BITS_TREE, -1001, 2075, 5856, 0, 0, 0, 0x00000000, bhvTree),
		TERRAIN(bits_area_1_collision),
		MACRO_OBJECTS(bits_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LUIGI_FINAL_BOSS),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 180, 0, 1625, 847),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};