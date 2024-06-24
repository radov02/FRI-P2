#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

// vrača true za pobarvano in false za nepobarvano polje
bool sierpinski(int x, int y, int globina){

    if(globina == 0){   // samo eno polje
        return true;
    }

    int sirinaPodkvadrata = 1 << (globina - 1);

    int podkvadratX = x / sirinaPodkvadrata;
    int podkvadratY = y / sirinaPodkvadrata;

    if(podkvadratX == 0 && podkvadratY == 1){   // levi spodnji podkvadrat
        return false;
    }
    else{
        return sierpinski(x % sirinaPodkvadrata, y % sirinaPodkvadrata, globina-1);
    }
}

// HITRA VERZIJA:
int main(){

    int n, v, s, h, w;
    scanf("%d %d %d %d %d", &n, &v, &s, &h, &w);

    // izpiši število polnih celic:
    printf("%llu\n", (long long unsigned)pow(3, n));

    // za vsako polje znotraj željenega pravokotnika za izpis
    // bomo klicali rekurzivno funkcijo, ki izračuna ali je polje polno
    // (to izračuna glede na celoten kvadrat)
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            printf("%c", sierpinski(j+s, i+v, n) ? '*':'-');
        }
        printf("\n");
    }

    return 0;
}











/* // PREPOČASNO:
void sierpinski(int n, bool** table, int y, int x) {
    if(n == 0) {
        table[y][x] = 1;
        return;
    }

    int side_len = pow(2, n);

    sierpinski(n-1, table, y, x);
    sierpinski(n-1, table, y, x+side_len/2);
    sierpinski(n-1, table, y+side_len/2, x+side_len/2);
}

char color(int velikost, int v, int s){
    if(velikost == 1){
        return '*';
    }
    if((v >= velikost/2) && (s < velikost/2)) {
        return '-';
    }
    return color(velikost/2, v % (velikost/2), s % (velikost/2));
}

int main(){
    int n = 3;
    int side_len = pow(2, n);
    bool** table = calloc(side_len, sizeof(bool*));
    for(int i = 0; i < side_len; i++)
        table[i] = calloc(side_len, sizeof(bool));

    sierpinski(n, table, 0, 0);

    for(int i = 0; i < side_len; i++){
        for(int j = 0; j < side_len; j++){
            if(table[i][j])
            printf("*");
            else
            printf("-");
        }
        printf("\n");
    }

    for(int i = 0; i < side_len; i++){
        for(int j = 0; j < side_len; j++){
            printf("%c", color(side_len, i, j));
        }
        printf("\n");
    }

    return 0;
} */