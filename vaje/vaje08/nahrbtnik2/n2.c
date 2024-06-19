#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool SMO_ZE[1001][1001][11];
int MEMO[1001][1001][11];   // memoizirati je potrebno glede na vse spreminjajaoče parametre

int najSkupnaCena(int indeksPredmet, int** predmeti, int V, int n, int k){

    if(indeksPredmet == n){
        return 0;
    }

    if(SMO_ZE[indeksPredmet][V][k]){
        return MEMO[indeksPredmet][V][k];
    }

    // ne dodamo tega predmeta:
    int cena = najSkupnaCena(indeksPredmet+1, predmeti, V, n, k);
    // dodamo tudi ta predmet:
    if(V - predmeti[indeksPredmet][0] >= 0 && ((predmeti[indeksPredmet][0] % 2 == 1 && k > 0) || predmeti[indeksPredmet][0] % 2 == 0)){
        int cenaZtrenutnim = predmeti[indeksPredmet][1] + najSkupnaCena(indeksPredmet+1, predmeti, V-predmeti[indeksPredmet][0], n, (predmeti[indeksPredmet][0] % 2 == 0 ? k:k-1));

        if(cena < cenaZtrenutnim){
            cena = cenaZtrenutnim;
        }
    }

    SMO_ZE[indeksPredmet][V][k] = true;
    MEMO[indeksPredmet][V][k] = cena;

    return cena;
}

int main(){

    int V, n, k;
    scanf("%d %d %d", &V, &n, &k);
    int** predmeti = malloc(n*sizeof(int*));
    for(int i = 0; i < n; i++){
        predmeti[i] = malloc(2*sizeof(int));
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &predmeti[j][i]);
        }
    }

    int najCena = najSkupnaCena(0, predmeti, V, n, k);

    printf("%d\n", najCena);

    return 0;
}