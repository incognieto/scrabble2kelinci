#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

typedef struct {
    char name[50];
    int rank;
    char date[50];
    int score;
    int total_poin;
} Player;

Player pl[100];
FILE *dataPlayer;
int counter;

void manualPaddingleft();
void manualPaddingtop();
int get_total_poin(Player pl);



