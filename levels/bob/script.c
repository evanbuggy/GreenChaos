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

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/bob/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bob_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_yay0SegmentRomStart, _generic_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group3_yay0SegmentRomStart, _group3_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group3_geoSegmentRomStart, _group3_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xb, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd), 
	LOAD_MIO0(0xa, _bbh_skybox_mio0SegmentRomStart, _bbh_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_4), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_CHAIN_CHOMP_GATE, bob_geo_000440), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM, bob_geo_000458), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS, bob_geo_000470), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x01, LEVEL_ENDING, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 7522, 815, -4664, 0, -95, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 5607, 3874, -10439, 0, 130, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_AMP, 5599, 3889, -10462, 0, 130, 0, 0x00000000, bhvCirclingAmp),
		OBJECT(MODEL_BUG_LUIGI, 2, 491, -4792, 0, -180, 0, 0x00000000, bhvBugLuigi),
		OBJECT(MODEL_ELECTRO_LUIGI, 3269, 491, -4682, 0, 90, 0, 0x00000000, bhvElectroLuigi),
		OBJECT(MODEL_GOOMBA, 10154, 5334, -10340, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 7245, 5334, -10340, 0, -90, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_NONE, 12206, 333, -4702, 0, -95, 0, 0x00000000, bhvGoombaTripletSpawner),
		MARIO_POS(0x01, 180, 0, 130, 3231),
		OBJECT(MODEL_RED_COIN, 5877, 1356, -4803, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 9060, 4022, -5869, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_YELLOW_COIN, 7768, 1887, -4803, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 13227, 2418, -4139, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 9458, 2149, -4933, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 9286, 2537, -6902, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_GOOMBA, 8024, 2809, -5913, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YELLOW_COIN, 13324, 2977, -5867, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 10186, 3136, -11587, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 9061, 3777, -9666, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 12170, 2587, -4735, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 13227, 1859, -5279, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 13227, 1118, -4139, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 4719, 3224, -11844, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_GOOMBA, 9299, 3015, -4827, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 9857, 3310, -6518, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 7968, 3676, -5805, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_YELLOW_COIN, 10155, 4028, -9340, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 73, 5467, -10250, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, -2060, 5270, -10434, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, -3443, 5046, -11620, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, -3574, 4761, -13489, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 1855, 4810, -14495, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 3870, 5164, -13520, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 4594, 5519, -11084, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 3126, 2787, -9514, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 11181, 4457, -9636, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_NONE, 1509, 146, 0, 0, 0, 0, (60 << 24) | (30 << 16) | (30 << 8), bhvRank),
		OBJECT(MODEL_GOOMBA, 0, 1, 2780, 0, 180, 0, (8 << 24) | (8 << 16), bhvSpring),
		OBJECT(MODEL_STAR, 3792, 2381, -7915, 0, 180, 0, (20 << 24) | (20 << 16), bhvStar),
		OBJECT(MODEL_GOOMBA, 3070, 5694, -8305, 0, -32, 0, 0x00000000, bhvCombatEnemy),
		OBJECT(MODEL_NONE, 0, 130, 3231, 0, 180, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_HIGHWAY),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 180, 0, 130, 3231),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
