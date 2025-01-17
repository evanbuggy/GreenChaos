static struct ObjectHitbox sCombatEnmemyHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 20,
    /* numLootCoins:      */ 1,
    /* radius:            */ 200,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 42,
    /* hurtboxHeight:     */ 40,
};

static u8 sCombatEnemyAttackHandlers[6] = {
    /* ATTACK_PUNCH:                 */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_KICK_OR_TRIP:          */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_ABOVE:            */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_GROUND_POUND_OR_TWIRL: */ ATTACK_HANDLER_SQUISHED,
    /* ATTACK_FAST_ATTACK:           */ ATTACK_HANDLER_KNOCKBACK,
    /* ATTACK_FROM_BELOW:            */ ATTACK_HANDLER_KNOCKBACK,
};

void bhv_combat_enemy_loop(void) {
    if (obj_handle_attacks(&sCombatEnmemyHitbox, o->oAction, sCombatEnemyAttackHandlers) == ATTACK_KICK_OR_TRIP) {
        obj_die_if_health_non_positive();
        // This defines how long Mario has in frames to cancel his kick into a jump after hitting this enemy.
        gMarioState->jumpTimer = 10;
        
        //o->oHealth--;
        o->oForwardVel = 0.0f;
        o->oVelY = 70.0f;
    }
    cur_obj_move_standard(-78);
    //obj_act_knockback(0.0f);
    //cur_obj_update_floor_and_walls();
    //cur_obj_move_using_vel_and_gravity();
}