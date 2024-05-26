
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VOZLISC 1000

int trenutnoIndeks = 0;

void izpis(int* pot, int indeks){
    for(int i = 0; i < indeks; i++){
        printf("%d\n", pot[i]);
    }
}

void izpisi(int* pot, int indeksPot, int iskano, int* vnosi, int n){

    if(vnosi[trenutnoIndeks] == iskano){
        pot[indeksPot] = vnosi[trenutnoIndeks];
        izpis(pot, indeksPot+1);
        return;
    }

    pot[indeksPot] = vnosi[trenutnoIndeks];

    for(int i = 1; i <= n; i++){
        trenutnoIndeks += 2;
        izpisi(pot, indeksPot+1, iskano, vnosi, vnosi[trenutnoIndeks+1]);
    }
}

int main() {
    
    int iskano, n;
    scanf("%d", &iskano);
    int* vnosi = malloc(MAX_VOZLISC*sizeof(int));
    for(int i = 0; i < MAX_VOZLISC; i++){ // 2. stevilo pove koliko ma otrok
        scanf("%d", &vnosi[i]);
        if(i == 1){
            n = vnosi[i];
        }
    }

    int* pot = malloc(MAX_VOZLISC * sizeof(int));
    izpisi(pot, 0, iskano, vnosi, n);

    free(pot);
    free(vnosi);

    return 0;
}
