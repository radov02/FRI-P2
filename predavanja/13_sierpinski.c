#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

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

char barva(int velikost, int v, int s){
    if(velikost == 1){
        return '*';
    }
    if((v >= velikost/2) && (s < velikost/2)) {
        return '-';
    }
    return barva(velikost/2, v % (velikost/2), s % (velikost/2));
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
            printf("%c", barva(side_len, i, j));
        }
        printf("\n");
    }

    return 0;
}