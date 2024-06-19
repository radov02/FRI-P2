#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void izpis(char* niz, int n, int* mejeRazbitij, int indeksMeje){
    for(int i = 0; i < n; i++){
        bool pipe = false;
        for(int j = 0; j < indeksMeje; j++){
            if(mejeRazbitij[j] == i){
                pipe = true;
            }
        }

        if(pipe && i < n-1){
            printf("%c|", niz[i]);
        }
        else{
            printf("%c", niz[i]);
        }
    }
    printf("\n");
}

void razbitja(int* mejeRazbitij, int indeksMeje_stRazbitijM1, int trenutni, char* niz, int n, int a, int b){

    if(indeksMeje_stRazbitijM1+1 >= a && indeksMeje_stRazbitijM1+1 <= b){
        mejeRazbitij[indeksMeje_stRazbitijM1++] = trenutni;
        izpis(niz, n, mejeRazbitij, indeksMeje_stRazbitijM1);
        return;
    }

    mejeRazbitij[indeksMeje_stRazbitijM1++] = trenutni;

    for(int i = trenutni+1; i < n; i++){
        if(indeksMeje_stRazbitijM1 < b){
            razbitja(mejeRazbitij, indeksMeje_stRazbitijM1, i, niz, n, a, b);
        }
    }
    indeksMeje_stRazbitijM1--;
}

int main(){

    char* niz = malloc(15*sizeof(char));
    scanf("%s", niz);
    int n, a, b;
    scanf("%d %d", &a, &b);
    n = strlen(niz);

    int* mejeRazbitij = malloc(n*sizeof(int));

    for(int trenutni = 0; trenutni < n-a+1; trenutni++){
        razbitja(mejeRazbitij, 0, trenutni, niz, n, a, b);
    }

    free(niz);

    return 0;
}