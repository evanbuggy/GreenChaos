u16 coinSRank;
u16 coinARank;
u16 coinBRank;
u16 coinCRank;
u16 coinDRank;
u16 coin[5] = {0, 0, 0, 0, 0};

u16 comboSRank;
u16 comboARank;
u16 comboBRank;
u16 comboCRank;
u16 comboDRank;
u16 combo[5] = {0, 0, 0, 0, 0};

void bhv_rank_init(void) {
    coinSRank = o->oBehParams2ndByte;
    coinDRank = coinSRank / 5;
    coinCRank = coinDRank * 2;
    coinBRank = coinDRank * 3;
    coinARank = coinDRank * 4;

    comboSRank = o->oBehParams >> 24;
    comboDRank = comboSRank / 5;
    comboCRank = comboDRank * 2;
    comboBRank = comboDRank * 3;
    comboARank = comboDRank * 4;

    coin[0] = coinDRank;
    coin[1] = coinCRank;
    coin[2] = coinBRank;
    coin[3] = coinARank;
    coin[4] = coinSRank;

    combo[0] = comboDRank;
    combo[1] = comboCRank;
    combo[2] = comboBRank;
    combo[3] = comboARank;
    combo[4] = comboSRank;

    osSyncPrintf("COMBO RANKS (D-S):");
    osSyncPrintf("%d", comboDRank);
    osSyncPrintf("%d", comboCRank);
    osSyncPrintf("%d", comboBRank);
    osSyncPrintf("%d", comboARank);
    osSyncPrintf("%d", comboSRank);

    osSyncPrintf("COIN RANKS (D-S):");
    osSyncPrintf("%d", coinDRank);
    osSyncPrintf("%d", coinCRank);
    osSyncPrintf("%d", coinBRank);
    osSyncPrintf("%d", coinARank);
    osSyncPrintf("%d", coinSRank);
}

void bhv_rank_loop(void) {
    for (u8 i = 0; i < 5; i++) {
        if (gMarioState->numCoins < coin[i]) {
            gMarioState->rank = i;
            break;
        }
        else {
            if (gMarioState->highestCombo < combo[i]) {
                gMarioState->rank = i;
                break;
            }
            else {
                gMarioState->rank = 4;
            }
        }
    }
    //osSyncPrintf("%d", gMarioState->rank);
}