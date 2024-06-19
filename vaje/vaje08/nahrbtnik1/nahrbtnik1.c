#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

bool SMO_ZE[1001][1001];    // da optimiziramo tudi klice kjer je cena 0
int MEMO[1001][1001];   // shranimo kar funkcija vrne

int pridobiNajvecjoCeno(int trenutnaProstornina, int najvecjaCena, int indeks, int* prostorninePredmetov, int* cenePredmetov, int V, int n){
    // ima preveč spreminjajočih parametrov (3) za memoizacijo - ne moremo
    if(indeks == n){
        return najvecjaCena;
    }
    
    int trenutnaCena = 0;

    // dodamo element ali pa ne
    int cenaBrez = pridobiNajvecjoCeno(trenutnaProstornina, najvecjaCena, indeks+1, prostorninePredmetov, cenePredmetov, V, n);
    if(trenutnaProstornina + prostorninePredmetov[indeks] <= V){
        int cenaZ = cenePredmetov[indeks] + pridobiNajvecjoCeno(trenutnaProstornina + prostorninePredmetov[indeks], najvecjaCena, indeks+1, prostorninePredmetov, cenePredmetov, V, n);

        if(cenaZ > cenaBrez){
            trenutnaCena = cenaZ;
        }
        else{
            trenutnaCena = cenaBrez;
        }
    }
    else{
        trenutnaCena = cenaBrez;
    }
    
    if(trenutnaCena > najvecjaCena){
        najvecjaCena = trenutnaCena;
    }
    
    return najvecjaCena;
}

// rešitev:
int optimalnaCena(int stPredmetov, int* prostornine, int* cene, int index, int V){  // cim manj parametrov, memoiziramo spreminjajoče argumente

    if(index == stPredmetov){   // ne ustavimo se ko je prostornina < 0 ker smo takrat že dodali tisti predmet - to preverimo pred klicem
        return 0;
    }

    if(SMO_ZE[V][index]){
        return MEMO[V][index];
    }

    // moznost 1: predmeta z indeksom index ne dodamo v nahrbtnik
    int najCena = optimalnaCena(stPredmetov, prostornine, cene, index+1, V);
    // moznost 2: predmet z indeksom index dodamo v nahrbtnik
    if(prostornine[index] <= V){    // preverimo da ne dodajamo prevelikega predmeta
        int c = cene[index] + optimalnaCena(stPredmetov, prostornine, cene, index+1, V - prostornine[index]);
        // izbremo boljšo:
        if(c > najCena) najCena = c;
    }
    MEMO[V][index] = najCena;
    SMO_ZE[V][index] = true;
    return najCena;
}

int main(){

    int V, n;
    scanf("%d %d", &V, &n);

    int* prostorninePredmetov = calloc(n, sizeof(int));
    int* cenePredmetov = calloc(n, sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &prostorninePredmetov[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &cenePredmetov[i]);
    }

    //int rezultat = pridobiNajvecjoCeno(0, 0, 0, prostorninePredmetov, cenePredmetov, V, n);
    int rezultat2 = optimalnaCena(n, prostorninePredmetov, cenePredmetov, 0, V);

    printf("%d", rezultat2);

    free(prostorninePredmetov);
    free(cenePredmetov);

    return 0;
}