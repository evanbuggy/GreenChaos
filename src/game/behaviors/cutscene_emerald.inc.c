void bhv_cutscene_emerald_loop(void) {
    cur_obj_update_floor_and_walls();
    cur_obj_move_standard(-78);

    if (o->oMoveFlags & OBJ_MOVE_BOUNCE) {
        cur_obj_play_sound_2(SOUND_OBJ_POUNDING_LOUD);
    }
}