#include <stdio.h>
#include <stdlib.h>

void izpisi(char trenutni, char* niz, int indeks, int n, char c1, char c2){

    niz[indeks++] = trenutni;

    if(indeks > 0){
        niz[indeks] = '\0';
        printf("%s\n", niz);
        // ni returna, ker želimo izpisati tudi več kot enočrkovne nize
    }
    if(indeks >= n){
        return;
    }

    for(int i = c1; i <= c2; i++){
        izpisi(i, niz, indeks, n, c1, c2);
    }
}

int main(){

    int n;
    char c1, c2;
    scanf("%d %c %c", &n, &c1, &c2);

    char* niz = malloc((n+1)*sizeof(char));

    for(int i = c1; i <= c2; i++){
        izpisi(i, niz, 0, n, c1, c2);
    }
    
    return 0;
}