#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 10

int n, k, r;
int zaporedje[MAX_N];

bool jeUrejeno(int* zaporedje, int len){
    int max = zaporedje[0];
    for(int i = 1; i < len; i++){
        if(zaporedje[i] <= max){
            return false;
        }
    }
    return true;
}

int st_nacinov(int trenutno){

    if(jeUrejeno(zaporedje, n)){
        return 1;
    }

    int nacinov = 0;
    for(int i = trenutno+r; i <= n-r; i++){
        for(int j = )
        nacinov += st_nacinov(i, n, k, r, zaporedje);
    }

    return nacinov;
}

int main(){

    scanf("%d %d %d", &n, &k, &r);
    for(int i = 0; i < n; i++){
        scanf("%d", &zaporedje[i]);
    }

    int stNacinov = st_nacinov();

    printf("%d\n", stNacinov);

    return 0;
}