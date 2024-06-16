#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PRAZNIH 25

int DVR[] = {1, 2, 2, 1, -1, -2, -2, -1}; // vrstični premiki
int DST[] = {2, 1, -1, -2, -2, -1, 1, 2}; // stolpčni premiki
int najdaljsa = 0;
int najdaljsaPot[MAX_PRAZNIH][2];

void izpisNajdaljsePoti(){
    for(int i = 1; i < najdaljsa; i++){
        printf("%d/%d\n", najdaljsaPot[i][0], najdaljsaPot[i][1]);
    }
}

bool zeObiskano(int y, int x){
    for(int i = 0; i < najdaljsa; i++){
        if(najdaljsaPot[i][0] == y && najdaljsaPot[i][1] == x){
            return true;
        }
    }
    return false;
}

void izpisiNajdaljso(int** pot, int indeksPot, int x, int y, int n, bool** ovire){

    pot[indeksPot][0] = y;
    pot[indeksPot++][1] = x;

    // printf("%d %d\n", x, y); fflush(stdout);

    if(indeksPot > najdaljsa){
        najdaljsa = indeksPot;
        // prepisi pot:
        for(int i = 0; i < indeksPot; i++){
            najdaljsaPot[i][0] = pot[i][0];
            najdaljsaPot[i][1] = pot[i][1];
        }
    }

    for(int i = 0; i < 8; i++){
        if(y+DST[i] >= 0 && y+DST[i] < n && x+DVR[i] >= 0 && x+DVR[i] < n && !ovire[y+DST[i]][x+DVR[i]] && !zeObiskano(y+DST[i], x+DVR[i])){
            izpisiNajdaljso(pot, indeksPot, x+DVR[i], y+DST[i], n, ovire);
        }
    }
}

int main() {

    int n, k;
    scanf("%d %d", &n, &k);
    bool** ovire = calloc(n, sizeof(bool*));
    for(int i = 0; i < n; i++){
        ovire[i] = calloc(n, sizeof(bool));
    }
    for(int i = 0; i < k; i++){
        int y, x;
        scanf("%d %d", &y, &x);
        ovire[y][x] = true;
    }

    /* for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", ovire[i][j]); fflush(stdout);
        }
        printf("\n");
    } */

    int** pot = calloc(MAX_PRAZNIH, sizeof(int*));
    for(int i = 0; i < MAX_PRAZNIH; i++){
        pot[i] = malloc(2*sizeof(int));
    }
    izpisiNajdaljso(pot, 0, 0, 0, n, ovire);

    izpisNajdaljsePoti();

    return 0;
}