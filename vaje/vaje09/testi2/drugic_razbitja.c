#include <stdio.h>
#include <stdlib.h>

void izpis(int* elementi, int stevilo){
    printf("{");
    for(int i = 0; i < stevilo; i++){
        if(i < stevilo-1) printf("%d, ", elementi[i]);
        else printf("%d", elementi[i]);
    }
    printf("}\n");
}

void izpisi(int* mnozica, int indeksMnozica, int vsota, int n, int* elementi, int indeks, int ciljVsota){

    if(vsota == ciljVsota){
        izpis(mnozica, indeks);
        return;
    }

    for(int i = indeks; i < n; i++){
        if(vsota + elementi[i] <= ciljVsota){
            mnozica[indeksMnozica] = elementi[i];
            izpisi(mnozica, indeksMnozica+1, vsota+elementi[i], n, elementi, i, ciljVsota);
        }
    }
}

int main(){

    int n;
    scanf("%d", &n);
    int* elementi = calloc(n,sizeof(int));
    int vsota = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &elementi[i]);
        vsota += elementi[i];
    }

    int* mnozica = calloc(n, sizeof(int));
    mnozica[0] = 2;
    izpisi(mnozica, 1, 2, n, elementi, 1, vsota/2);

    free(elementi);
    free(mnozica);

    return 0;
}