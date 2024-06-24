#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// PREPOČASNO:

int polnih = 0;

/* void prepisiVPolje(int memoIndeks, char** polje, int x1, int x2, int y1, int y2){
    for(int j = y1; j < y2; j++){
        for(int i = x1; i < x2; i++){
            polje[j][i] = memo[memoIndeks][j-y1][i-x1];
        }
    }
}

void prepisiVMemo(int memoIndeks, char** polje, int x1, int x2, int y1, int y2){
    for(int j = y1; j < y2; j++){
        for(int i = x1; i < x2; i++){
            memo[memoIndeks][j-y1][i-x1] = polje[j][i];
        }
    }
} */

// Depth First Search
void izpisiSierpinski(char** polje, int x1, int x2, int y1, int y2){

    if(x2 - x1 == 1 && y2 - y1 == 1){
        polje[y1][x1] = '*';
        polnih++;
        return;
    }

    int sredinskix = (x1 + x2) / 2;
    int sredinskiy = (y1 + y2) / 2;

    // Top-left triangle
    izpisiSierpinski(polje, x1, sredinskix, y1, sredinskiy);
    // Top-right triangle
    izpisiSierpinski(polje, sredinskix, x2, y1, sredinskiy);
    // Bottom-right triangle
    izpisiSierpinski(polje, sredinskix, x2, sredinskiy, y2);

    /* // Top-left triangle
    if(zePridobljeno[sredinskix - x1]){
        prepisiVPolje(sredinskix - x1, polje, x1, sredinskix, y1, sredinskiy);
    }
    else{
        izpisiSierpinski(polje, x1, sredinskix, y1, sredinskiy);
        prepisiVMemo(sredinskix - x1, polje, x1, sredinskix, y1, sredinskiy);
    }
    // Top-right triangle
    if(zePridobljeno[x2 - sredinskix]){
        prepisiVPolje(x2 - sredinskix, polje, sredinskix, x2, y1, sredinskiy);
    }
    else {
        izpisiSierpinski(polje, sredinskix, x2, y1, sredinskiy);
        prepisiVMemo(x2 - sredinskix, polje, sredinskix, x2, y1, sredinskiy);
    }
    // Bottom-right triangle
    if(zePridobljeno[x2 - sredinskix]){
        prepisiVPolje(x2 - sredinskix, polje, sredinskix, x2, sredinskiy, y2);
    }
    else{
        izpisiSierpinski(polje, sredinskix, x2, sredinskiy, y2);
        prepisiVMemo(x2 - sredinskix, polje, sredinskix, x2, sredinskiy, y2);
    } */
}

int main() {
    
    int n, v, s, h, w;
    scanf("%d %d %d %d %d", &n, &v, &s, &h, &w);

    int stranica = pow(2, n);
    char** polje = malloc(stranica*sizeof(char*));
    for(int i = 0; i < stranica; i++){
        polje[i] = calloc(stranica, sizeof(char));
        for(int j = 0; j < stranica; j++){
            polje[i][j] = '-';
        }
    }

    izpisiSierpinski(polje, 0, stranica, 0, stranica);

    printf("%d\n", polnih);
    for(int i = v; i < h+v; i++){
        for(int j = s; j < w+s; j++){
            printf("%c", polje[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < stranica; i++){
        free(polje[i]);
    }
    free(polje);


    return 0;
}