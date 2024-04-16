#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

bool SMO_ZE[1001][1001][11];
int MEMO[1001][1001][11];

int optimalnaCena(int stPredmetov, int* prostornine, int* cene, int index, int V, int stLihih){ // ker smo dodali en spreminjajoč argument moramo dodati dimenzijo v memoizaciji

    if(index == stPredmetov){
        return 0;
    }

    if(SMO_ZE[V][index][stLihih]){
        return MEMO[V][index][stLihih];
    }

    int najCena = optimalnaCena(stPredmetov, prostornine, cene, index+1, V, stLihih);

    if(prostornine[index] <= V && stLihih - prostornine[index] % 2 >= 0){   // ce je liho preveri ali bo še večje od 0, če je sodo bo true
        int c = cene[index] + optimalnaCena(stPredmetov, prostornine, cene, index+1, V - prostornine[index], stLihih - prostornine[index] % 2);
        if(c > najCena) najCena = c;
    }
    MEMO[V][index][stLihih] = najCena;
    SMO_ZE[V][index][stLihih] = true;
    return najCena;
}

int main(){

    int V, n, maksStLihih;
    scanf("%d %d %d", &V, &n, &maksStLihih);

    int* prostorninePredmetov = calloc(n, sizeof(int));
    int* cenePredmetov = calloc(n, sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &prostorninePredmetov[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &cenePredmetov[i]);
    }

    int rezultat2 = optimalnaCena(n, prostorninePredmetov, cenePredmetov, 0, V, maksStLihih);

    printf("%d", rezultat2);

    free(prostorninePredmetov);
    free(cenePredmetov);

    return 0;
}