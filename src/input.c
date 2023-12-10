#include "input.h"

void inputPlayerhuman(Player pl[100]) {
    manualPaddingleft(); printf("+-------------------------------------------------------------------------------+\n");
    manualPaddingleft(); printf("|                                P1 VS P2                                       |\n");
    manualPaddingleft(); printf("+-------------------------------------------------------------------------------+\n");
    for (int i = 0; i < 2; i++) {
        manualPaddingleft(); printf("| [Data for Player %d]                                                           |\n", i + 1);
        
        manualPaddingleft(); printf("        >>> Username    :"); scanf(" %[^\n]", &pl[i].name);
        
        manualPaddingleft(); printf("        >>> Score       :"); scanf("%d", &pl[i].score);

        time_t currentTime;
        struct tm *timeInfo;

        time(&currentTime);
        timeInfo = localtime(&currentTime);

        strftime(pl[i].date, sizeof(pl[i].date), "%A, %d/%m/%Y", timeInfo);

        pl[i].total_poin = get_total_poin(pl[i]);
    }
}

void inputPlayercomp(Player pl[100]) {
    printf("+-------------------------------------------------------------------------------+\n");
    printf("|                                P1 VS COMP                                     |\n");
    printf("+-------------------------------------------------------------------------------+\n");
    for (int i = 0; i < 1; i++) {
        printf("| [Data for Player %d]                                                           |\n", i + 1);
        printf("        >>> Username  :");
        scanf(" %[^\n]", pl[i].name);
    }
}