#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void izpisiClene(int* cleni, int ind){
    for(int i = 0; i < ind; i++){
        if(i < ind-1) printf("%d + ", cleni[i]);
        else printf("%d", cleni[i]);
    }
    printf("\n");
}

void izpisi(int n, int k, int* cleni, int indeks){  // spreminjajo se n in k

    if(n == 0){
        izpisiClene(cleni, indeks);
        return;
    }
    if(n < 0 || k <= 0){
        return;
    }

    cleni[indeks] = k;

    izpisi(n-k, k, cleni, indeks+1);
    izpisi(n, k-1, cleni, indeks);

}

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    int* cleni = calloc(30, sizeof(int));

    izpisi(n, k, cleni, 0);

    return 0;
}