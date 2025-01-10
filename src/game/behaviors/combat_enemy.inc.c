static struct ObjectHitbox sCombatEnmemyHitbox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 72,
    /* height:            */ 50,
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
    if (obj_handle_attacks(&sCombatEnmemyHitbox, o->oAction, sCombatEnemyAttackHandlers)) {
        play_sound(SOUND_GENERAL_COLLECT_1UP, gGlobalSoundSource);
        obj_die_if_health_non_positive();
    }
}