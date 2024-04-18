#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXki 42

void izpisiNiz(char* niz, int length){
    for(int i = 0; i < length; i++){
        printf("%c", niz[i]);
    }
    printf("\n");
    return;
}

void izpisiPermutacije(int i, int j, char* permutacija, char** tabelaNizov, int n){
    
    permutacija[i+1] = tabelaNizov[i+1][j];
    izpisiNiz(permutacija, i+2);
    printf(" %d, %d, %d\n", i+1 ,j, n);

    if(i == n-2){
        //izpisiNiz(permutacija, n);
        printf("izpisiNIz\n");
        return;
    }

    int jj = 0;
    while(tabelaNizov[i+1][jj] != '\0'){
        izpisiPermutacije(i+1, jj, permutacija, tabelaNizov, n);
        printf("vrnjeno\n");
        jj++;
    }
    return;
}

int main(){

    int n;
    scanf("%d", &n);
    getchar();

    char** tabelaNizov = calloc(100, sizeof(char*));

    for(int i = 0; i < n; i++){
        tabelaNizov[i] = calloc(MAXki, sizeof(int));
        int j = 0;
        int charVnos = 0;
        while((char)(charVnos = getchar()) != '\n'){
            tabelaNizov[i][j++] = charVnos;
        }
    }

    char* permutacija = calloc(n, sizeof(char));
    izpisiPermutacije(-1, 0, permutacija, tabelaNizov, n);

    /* printf("\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < MAXki; j++){
            printf("%c", tabelaNizov[i][j]);
        }
        printf("\n");
    } */

    for(int i = 0; i < n; i++){
        free(tabelaNizov[i]);
    }
    free(tabelaNizov);

    return 0;
}



/*

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
} */