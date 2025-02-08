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

u32 timeSRank;
u32 timeARank;
u32 timeBRank;
u32 timeCRank;
u32 timeDRank;
u32 time[5] = {0, 0, 0, 0, 0};

void bhv_rank_init(void) {
    // Coin Requirements per rank:
    // Each level will have a minimum of 30 coins needed for at least an S rank.
    coinSRank = (o->oBehParams2ndByte) + 30;
    coinDRank = coinSRank / 5;
    coinCRank = coinDRank * 2;
    coinBRank = coinDRank * 3;
    coinARank = coinDRank * 4;

    // Combo Requirements per rank:
    // The param is doubled so when you are using a rank object, enter half the
    // highest combo you want for an S rank for the 2nd param.
    comboSRank = (o->oBehParams >> 24) * 2;
    comboDRank = comboSRank / 5;
    comboCRank = comboDRank * 2;
    comboBRank = comboDRank * 3;
    comboARank = comboDRank * 4;

    // Timer Requirements per rank:
    // The param is multiplied by 100 so when you are using the rank object enter
    // the time in frames in hundreds for the 3rd param.
    timeSRank = (o->oBehParams >> 8 & 0xFF) * 100;
    timeDRank = timeSRank * 5;
    timeCRank = timeDRank / 2;
    timeBRank = timeDRank / 3;
    timeARank = timeDRank / 4;

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

    time[0] = timeDRank;
    time[1] = timeCRank;
    time[2] = timeBRank;
    time[3] = timeARank;
    time[4] = timeSRank;

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

    osSyncPrintf("TIME RANKS (D-S):");
    osSyncPrintf("%d", timeDRank);
    osSyncPrintf("%d", timeCRank);
    osSyncPrintf("%d", timeBRank);
    osSyncPrintf("%d", timeARank);
    osSyncPrintf("%d", timeSRank);
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
                u32 temp = 0;
                if (gMarioState->stopTime > 0) {
                    temp = gMarioState->stopTime;
                }
                else {
                    temp = gGlobalTimer;
                }
                osSyncPrintf("%d", temp);

                if (temp > time[i]) {
                    gMarioState->rank = i;
                    break;
                }
                else {
                    gMarioState->rank = 4;
                }
            }
        }
    }
}