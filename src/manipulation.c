#include "manipulation.h"

void printDataPlayer(Player pl[100]) {
    if (counter == 0) {
        printf("|                       Ups! Nampaknya data masih kosong.                       |\n");
    } else {
        for (int i = 0; i < counter; i++) {
            manualPaddingleft(); printf("| %s \t\t|\t %d \t|\t%d \t| %s \t|\n", pl[i].name, pl[i].rank, pl[i].total_poin, pl[i].date);
        }
    }
}

void readDataPlayer(Player (*pl)[100]) {
    dataPlayer = fopen("scores.txt", "r");
    int i = 0;
    int hasil;

    while (!feof(dataPlayer)) {
        hasil = fscanf(dataPlayer, "%[^#]#%d#%d#%[^\n]\n", (*pl)[i].name, &(*pl)[i].rank, &(*pl)[i].score, (*pl)[i].date);
        if (hasil == 4) {
            (*pl)[i].total_poin = get_total_poin((*pl)[i]);
            i++;
        }
    }

    counter = i;
    fclose(dataPlayer);
}

void saveDataPlayer(Player pl[100]) {
    dataPlayer = fopen("scores.txt", "a");
    for (int i = 0; i < 2; i++) {
        pl[i].rank = counter + i + 1;
        fprintf(dataPlayer, "%s#%d#%d#%s\n", pl[i].name, pl[i].rank, pl[i].score, pl[i].date);
    }
    fclose(dataPlayer);
    printf("Data input Berhasil Disimpan di scores.txt !\n");
}

void saveSortedData(Player pl[100], char *filename) {
    dataPlayer = fopen(filename, "w");
    for (int i = 0; i < counter; i++) {
        fprintf(dataPlayer, "%s#%d#%d#%s\n", pl[i].name, pl[i].rank, pl[i].score, pl[i].date);
    }
    fclose(dataPlayer);
    manualPaddingleft(); printf("\t\t\t[!] data sorted saved in %s!\n", filename);
}

void saveHighscoresDescending(Player pl[100]) {
    saveSortedData(pl, "top_score.txt");
}
