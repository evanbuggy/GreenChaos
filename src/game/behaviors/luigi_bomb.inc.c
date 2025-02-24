void bhv_luigi_bomb_init(void) {
    o->oForwardVel = 70.0f + (random_float() * 60);
}

void bhv_luigi_bomb_loop(void) {
    cur_obj_rotate_yaw_toward(o->oAngleToMario, 0xFFF);
    cur_obj_update_floor_and_walls();
    cur_obj_move_standard(-78);

    if (o->oMoveFlags & OBJ_MOVE_BOUNCE) {
        cur_obj_play_sound_2(SOUND_OBJ_POUNDING_LOUD);
        spawn_object_relative_with_scale(OBJ_BP_NONE, 0, 0, 0, 2, o, MODEL_NONE, bhvExplosion);
        obj_mark_for_deletion(o);
    }
}