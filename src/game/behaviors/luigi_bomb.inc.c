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
        spawn_triangle_break_particles(20, MODEL_DIRT_ANIMATION, 3.0f, 4);
        spawn_mist_particles_variable(0, 0, 100.0f);
        obj_mark_for_deletion(o);
    }
}