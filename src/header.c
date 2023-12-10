#include "header.h"

void manualPaddingleft(){
    printf("                            ");
}

void manualPaddingtop(){
    printf("\n");
}

int get_total_poin(Player pl) {
    int total;
    total = pl.score + 99;
    return total;
}