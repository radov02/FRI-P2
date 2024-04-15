#include <stdio.h>
#include <math.h>

int main(){

    int m, n;
    scanf("%d %d", &m, &n);

    int steviloTrojic = 0;

    for(int c = m; c <= n; c++){
        for(int a = 1; a < c; a++){
            int bb = c*c - a*a;
            if(bb == round(sqrt(bb)) * round(sqrt(bb))){
                steviloTrojic++;
                break;
            }
        }
    }

    printf("%d\n", steviloTrojic);

    return 0;
}