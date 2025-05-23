static struct ObjectHitbox sCombatEnemyHitbox = {
    /* interactType:      */ INTERACT_COMBAT_ENEMY,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 5,
    /* numLootCoins:      */ 1,
    /* radius:            */ 100,
    /* height:            */ 200,
    /* hurtboxRadius:     */ 1,
    /* hurtboxHeight:     */ 1,   
};

static u8 sCombatEnemyAttackHandlers[6] = {
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_NOP,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_SPIN_SAW:              */ ATTACK_HANDLER_KNOCKBACK,
};

// These structs were all stolen from Goomba


void bhv_combat_enemy_init(void) {
    o->oInvFrames = 0;
    o->oHitstopFrames = 0;
}

void bhv_combat_enemy_loop(void) {

    if ((o->oAction & OBJ_ACT_SPIN_SAWED) && (o->oBehParams2ndByte != 0)) {
        obj_act_spin_sawed();
    }

    // if (obj_update_standard_actions(1)) {
        cur_obj_update_floor_and_walls();
        if (obj_handle_attacks(&sCombatEnemyHitbox, o->oAction, sCombatEnemyAttackHandlers) == ATTACK_KICK_OR_TRIP) {
            play_sound(SOUND_GENERAL_COIN_DROP, gGlobalSoundSource);
            cur_obj_become_intangible();
            enable_time_stop_including_mario();

            // Makes Mario invincible while launching the enemy (for 2 seconds)
            gMarioState->invincTimer = 30;
            
            if (o->oBehParams2ndByte != 0) {
                o->oHealth--;
            }

            o->oForwardVel = 0.0f;
            if ((o->oMoveFlags & OBJ_MOVE_LANDED) || (o->oMoveFlags & OBJ_MOVE_ON_GROUND)) {
                o->oVelY = 100.0f;
                // This defines how long Mario has in frames to cancel his kick into a jump after hitting this enemy.
                gMarioState->jumpTimer = 10;
            }
            else {
                o->oVelY = 60.0f;
                gMarioState->airComboCancel = 1;
            }

            // This defines how long the enemy is invincible for in frames before it can be attacked again.
            // This is to prevent attacks like the kick from hitting multiple times.
            o->oInvFrames = 6;

            o->oHitstopFrames = 3;

            obj_die_if_health_non_positive();
        }

        if (o->oInvFrames > 0) {
            o->oInvFrames--;
        }
        else {
            cur_obj_become_tangible();
        }

        if (o->oHitstopFrames > 0) {
            o->oHitstopFrames--;
        }
        else {
            disable_time_stop_including_mario();
        }

        if (o->oMoveFlags & OBJ_MOVE_BOUNCE) {
            if (o->oMoveFlags & OBJ_MOVE_ABOVE_DEATH_BARRIER) {
                obj_mark_for_deletion(o);
            }
            o->oForwardVel = 0.0f;
            cur_obj_play_sound_2(SOUND_OBJ_POUNDING_LOUD);
        }

        // Movement functions, commented out ones were used for testing and may be used later
        cur_obj_move_standard(-78);
        //obj_act_knockback(0.0f);

        //cur_obj_move_using_vel_and_gravity();
    //}
}