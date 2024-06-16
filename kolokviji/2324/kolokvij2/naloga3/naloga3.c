#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PRAZNIH_POLJ 25

int DVR[] = {1, 2, 2, 1, -1, -2, -2, -1}; // vrstični premiki
int DST[] = {2, 1, -1, -2, -2, -1, 1, 2}; // stolpčni premiki
int najdaljsa = 0;

bool vsebuje(int** zeObiskanaPolja, int zeObiskanih, int x, int y){
    for(int i = 0; i < zeObiskanih; i++){
        if(zeObiskanaPolja[i][0] == y && zeObiskanaPolja[i][1] == x){
            return true;
        }
    }
    return false;
}

void izpisiNajdaljso1(int trenutniY, int trenutniX, int n, bool** ovire, int** zeObiskanaPolja, int zeObiskanih, int** najdaljsaPot){

    // dodamo trenutno polje v trenutno pot:
    zeObiskanaPolja[zeObiskanih][0] = trenutniY;
    zeObiskanaPolja[zeObiskanih][1] = trenutniX;
    zeObiskanih++;

    // preverimo, ali je trenutna pot najdaljša:
    if(zeObiskanih > najdaljsa){
        najdaljsa = zeObiskanih;
        for(int a = 0; a < zeObiskanih; a++){   // kopiranje
            najdaljsaPot[a][0] = zeObiskanaPolja[a][0];
            najdaljsaPot[a][1] = zeObiskanaPolja[a][1];
        }
    }

    // preverimo vse možne skoke naprej:
    for(int i = 0; i < 8; i++){
        int noviX = trenutniX + DST[i];
        int noviY = trenutniY + DVR[i];

        if(noviY >= 0 && noviX >= 0 && noviY < n && noviX < n && !ovire[noviY][noviX] && !vsebuje(zeObiskanaPolja, zeObiskanih, noviX, noviY) && zeObiskanih < MAX_PRAZNIH_POLJ){
            izpisiNajdaljso1(noviY, noviX, n, ovire, zeObiskanaPolja, zeObiskanih, najdaljsaPot);
        }
    }

    zeObiskanih--;  // če ni več skokov naprej, gremo na prejšnjo pozicijo
}

int izpisiNajdaljso2(int trenutniY, int trenutniX, int n, bool** ovire, int** zeObiskanaPolja, int zeObiskanih, int** najdaljsaPot){

    // trenutno polje dodamo (je že obiskano):
    zeObiskanaPolja[zeObiskanih][0] = trenutniY;
    zeObiskanaPolja[zeObiskanih][1] = trenutniX;
    zeObiskanih++;

    // preverjamo vse možne premike iz trenutnega polja:
    for(int i = 0; i < 8; i++){
        int noviX = trenutniX + DST[i];
        int noviY = trenutniY + DVR[i];

        if(noviX >= 0 && noviX < n && noviY >= 0 && noviY < n && !ovire[noviY][noviX] && !vsebuje(zeObiskanaPolja, zeObiskanih, noviX, noviY) && zeObiskanih < MAX_PRAZNIH_POLJ){
            int dolzina = izpisiNajdaljso2(noviY, noviX, n, ovire, zeObiskanaPolja, zeObiskanih, najdaljsaPot);

            if(dolzina > najdaljsa){
                najdaljsa = dolzina;
                for (int a = 0; a < dolzina; a++) {
                    najdaljsaPot[a][0] = zeObiskanaPolja[a][0];
                    najdaljsaPot[a][1] = zeObiskanaPolja[a][1];
                }
            }
        }
    }

    return zeObiskanih;
}

int main() {
    
    int n, stOvir;
    scanf("%d %d", &n, &stOvir);
    bool** ploscaZOvirami = calloc(n, sizeof(bool*));
    for(int i = 0; i < n; i++){
        ploscaZOvirami[i] = calloc(n, sizeof(bool));
    }
    for(int i = 0; i < stOvir; i++){
        int x, y;
        scanf("%d %d", &y, &x);
        ploscaZOvirami[y][x] = true;
    }

    int** zeObiskanaPolja = calloc(MAX_PRAZNIH_POLJ, sizeof(int*));
    int** najdaljsaPot = calloc(MAX_PRAZNIH_POLJ, sizeof(int*));
    for(int i = 0; i < MAX_PRAZNIH_POLJ; i++){
        zeObiskanaPolja[i] = calloc(2, sizeof(int));
        najdaljsaPot[i] = calloc(2, sizeof(int));
    }

    //izpisiNajdaljso1(0, 0, n, ploscaZOvirami, zeObiskanaPolja, 0, najdaljsaPot);
    izpisiNajdaljso2(0, 0, n, ploscaZOvirami, zeObiskanaPolja, 0, najdaljsaPot);

    for(int i = 1; i < najdaljsa; i++){
        printf("%d/%d\n", najdaljsaPot[i][0], najdaljsaPot[i][1]);
    }

    return 0;
}
