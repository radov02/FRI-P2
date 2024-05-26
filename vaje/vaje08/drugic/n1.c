#include <stdio.h>
#include <stdlib.h>

int najvecjaMoznaCena(int maxCena, int indeks, int V, int n, int* prostorninePredm, int* cenePredm){

    if(V == 0){
        return cenePredm[indeks];
    }
    if(V < 0){
        return 0;
    }
    
    int cena = cenePredm[indeks];
    for(int i = indeks+1; i < n; i++){
        cena += najvecjaMoznaCena(maxCena, i, V-prostorninePredm[indeks], n, prostorninePredm, cenePredm);
    }

    if(cena > maxCena){
        maxCena = cena;
    }

    return maxCena;
}

int main(){

    int V, n;
    scanf("%d %d", &V, &n);
    int* prostorninePredm = malloc(n*sizeof(int));
    int* cenePredm = malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &prostorninePredm[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &cenePredm[i]);
    }

    int cena = najvecjaMoznaCena(0, 0, V, n, prostorninePredm, cenePredm);
    printf("%d\n", cena);

    return 0;
}