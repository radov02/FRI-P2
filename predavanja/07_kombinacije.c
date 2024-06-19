#include <stdio.h>
#include <stdlib.h>

void izpis(int* kombinacija, int indeks){
    for(int i = 0; i <= indeks; i++){
        printf("%d", kombinacija[i]);
    }
    printf("\n");
}

void kombinacije(int stevka, int* kombinacija, int indeks, int n, int k){

    if(indeks == n-1){
        kombinacija[indeks] = stevka;
        izpis(kombinacija, indeks);
        return;
    }

    kombinacija[indeks] = stevka;

    for(int i = 0; i < k; i++){
        kombinacije(i, kombinacija, indeks+1, n, k);
    }
}

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    int* kombinacija = calloc(n, sizeof(int));
    for(int i = 0; i < k; i++){
        kombinacije(i, kombinacija, 0, n, k);
    }

    free(kombinacija);

    return 0;
}