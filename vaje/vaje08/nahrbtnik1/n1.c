#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool SMO_ZE[1001][1001];  // klic za podatka: predmet, prostornina
int MEMO[1001][1001];

// gremo cez vsak predmet in poskusimo z dodajanjem ali z nedodajanjem le tega
// backtracking - najCena predmetov se vrača
int preveriNajCeno(int trenutniPredmet, int V, int predmetov, int** predmeti){

    if(trenutniPredmet == predmetov){
        return 0;
    }

    if(SMO_ZE[trenutniPredmet][V]){
        return MEMO[trenutniPredmet][V];
    }

    // ce ne dodamo:
    int cena = preveriNajCeno(trenutniPredmet+1, V, predmetov, predmeti);
    // ce dodamo:
    if(V-predmeti[trenutniPredmet][0] >= 0){
        int cenaZdodajanjem = predmeti[trenutniPredmet][1] + preveriNajCeno(trenutniPredmet+1, V-predmeti[trenutniPredmet][0], predmetov, predmeti);

        // primerjamo in vzamemo najvecjo ceno:
        if(cena < cenaZdodajanjem){
            cena = cenaZdodajanjem;
        }
    }

    SMO_ZE[trenutniPredmet][V] = true;
    MEMO[trenutniPredmet][V] = cena;

    return cena;
}

int main(){
    
    int V, predmetov;
    scanf("%d %d", &V, &predmetov);
    int** predmeti = malloc(predmetov*sizeof(int*));
    for(int i = 0; i < predmetov; i++){
        predmeti[i] = malloc(2*sizeof(int));
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < predmetov; j++){
            scanf("%d", &predmeti[j][i]);
        }
    }

    int najCena = preveriNajCeno(0, V, predmetov, predmeti);
    printf("%d\n", najCena);

    return 0;
}