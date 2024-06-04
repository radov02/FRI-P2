#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void izpisi(char* niz, int indeks, int n, char c1, char c2){

    if(strlen(niz) != 0){
        for(int i = 0; i < indeks; i++){
            printf("%c", niz[i]);
        }
        printf("\n");
    }

    if(n == 0){
        return;
    }

    for(int i = c1; i <= c2; i++){
        niz[indeks] = i;
        izpisi(niz, indeks+1, n-1, c1, c2);
    }
}

int main(){

    int n;
    char c1, c2;
    scanf("%d %c %c", &n, &c1, &c2);
    char* niz = malloc(n*sizeof(char));
    izpisi(niz, 0, n, c1, c2);

    return 0;
}