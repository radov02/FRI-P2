#include <stdio.h>
#include <stdbool.h>

bool SMO_ZE[401][401];
long MEMO[401][401];

long stNacinov(long vsota, int k, int n){   // spreminjata se vsota in k

    if(vsota == n){
        return 1;
    }
    if(vsota > n){
        return 0;
    }

    if(SMO_ZE[vsota][k]){
        return MEMO[vsota][k];
    }

    int nacinov = 0;
    for(int i = k; i > 0; i--){
        long spodnjih = stNacinov(vsota+i, i, n);
        nacinov += spodnjih;

        MEMO[vsota+i][i] = spodnjih;
        SMO_ZE[vsota+i][i] = true;
    }

    return nacinov;
}

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    long steviloNacinov = stNacinov(0l, k, n);

    printf("%ld", steviloNacinov);

    return 0;
}