
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 *
 * Javni testni primeri:
 *
 * 02..03: k = 1
 * 01, 07..10: splo"sni primeri
 * 01, 02 in 04 se nana"sajo na drevo na izpitnem listu
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...

void izpisi(int nivo, unsigned char trenutno, unsigned char** vozlisca, int k){

    if(nivo == k){
        printf("%d\n", trenutno);
        return;
    }

    //printf("nivo: %d, v0: %d, v1: %d\n", nivo, vozlisca[trenutno][0], vozlisca[trenutno][1]);

    if(vozlisca[trenutno][0] > 0){
        izpisi(nivo+1, vozlisca[trenutno][0], vozlisca, k);   // levo
    }
    if(vozlisca[trenutno][1] > 0){
        izpisi(nivo+1, vozlisca[trenutno][1], vozlisca, k);   // desno
    }
}

int main() {
    
    char* imeVhodne = malloc(20*sizeof(char));
    int n, k;
    scanf("%s %d %d", imeVhodne, &n, &k);
    FILE* vhodna = fopen(imeVhodne, "rb");

    unsigned char** vozlisca = malloc((n+1)*sizeof(unsigned char*));
    for(int i = 0; i <= n; i++){
        vozlisca[i] = malloc(3*sizeof(unsigned char));
    }

    unsigned char* datoteka = malloc(2*n*sizeof(unsigned char));
    
    fread(datoteka, 1, 2*n, vhodna);
    /*for(int i = 0; i < 2*n; i++){
        printf("%d ", datoteka[i]);
    }*/

    for(int i = 1; i <= n; i++){
        vozlisca[i][0] = datoteka[2*i-2];  // levi sosed
        vozlisca[i][1] = datoteka[2*i-1];  // desni sosed

        //printf("%d %d\n", (int)vozlisca[i][0], (int)vozlisca[i][1]);
    }

    izpisi(0, 1, vozlisca, k);

    fclose(vhodna);

    return 0;
}
