#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* void izpisi(int* tabela, int n){
    for(int i = 0; i < n; i++){

    }
} */

bool igraOdstevanja(int n, int k, int stZetonov, bool beli, int indeks, int* tabela){  // true ce je zmagal beli

    if(n <= 0){
        if(!beli){
            printf("CRNI");
            return false;
        }
        else{
            bool bel = beli;
            for(int i = 0; i < indeks; i++){
                if(bel){
                    printf("%d", tabela[i]);
                }
                else{
                    printf("[%d]", tabela[i]);
                }
                bel = !bel;
                if(i < indeks-1){
                    printf(" -> ");
                }
            }
            printf("\n");
            return true;
        }
    }

    tabela[indeks] = stZetonov;

    for(int poberiZetonov = 1; poberiZetonov <= k; poberiZetonov++){
        if(igraOdstevanja(n-poberiZetonov, k, poberiZetonov, !beli, indeks+1, tabela)){
            
        }
    }
    return false;
}

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    int* tabela = malloc(n * sizeof(int));

    igraOdstevanja(n, k, 1, true, 0, tabela);

    return 0;
}