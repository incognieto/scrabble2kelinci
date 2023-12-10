#include "highscores.h"

void sortHighscores(Player *pl, int ascending) {
    int i, j, index;
    Player temp;
    Player sortedPlayers[100];  // Tambahkan array untuk menyimpan hasil pengurutan

    for (i = 0; i < counter; i++) {
        sortedPlayers[i] = pl[i];
    }

    for (i = 0; i < counter - 1; i++) {
        index = i;
        for (j = i + 1; j < counter; j++) {
            if ((ascending && sortedPlayers[j].total_poin < sortedPlayers[index].total_poin) ||
                (!ascending && sortedPlayers[j].total_poin > sortedPlayers[index].total_poin)) {
                index = j;
            }
        }
        // Swap sortedPlayers[i] and sortedPlayers[index]
        temp = sortedPlayers[i];
        sortedPlayers[i] = sortedPlayers[index];
        sortedPlayers[index] = temp;
    }

    // Set peringkat berdasarkan urutan setelah diurutkan
    for (i = 0; i < counter; i++) {
        sortedPlayers[i].rank = i + 1;
    }

    // Menyalin hasil pengurutan ke array pemain utama
    for (i = 0; i < counter; i++) {
        pl[i] = sortedPlayers[i];
    }
}