#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXki 42

int tabelaNizov[100][42];

void izpisiBesedo(char* niz, int n, bool newln){
    for(int i = 0; i < n; i++){
        printf("%c", niz[i]);
    }
    if(newln)
        printf("\n");
}

void izpisi(char* niz, int beseda, int crka, int n){

    if(beseda >= n){    // smo že na koncu besed
        izpisiBesedo(niz, n, true);
        return;
    }


    niz[beseda] = tabelaNizov[beseda][crka];
    //printf("niz[%d] = %c\n", beseda, niz[beseda]);

    izpisi(niz, beseda+1, crka, n);

    if(tabelaNizov[beseda][crka+1] != 0){
        izpisi(niz, beseda, crka+1, n);
    }
    else if(beseda < n){
        izpisi(niz, beseda, crka, n);
    }

    return;
}

int main(){

    int n;
    scanf("%d", &n);
    getchar();

    for(int i = 0; i < n; i++){
        int j = 0;
        int charVnos = 0;
        while((char)(charVnos = getchar()) != '\n'){
            tabelaNizov[i][j++] = charVnos;
        }
    }

    char* niz = calloc(n, sizeof(char));
    izpisi(niz, 0, 0, n);

    /* printf("\n");
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 42; j++){
            printf("%d", tabelaNizov[i][j]);
        }
        printf("\n");
    } */

    

    return 0;
}