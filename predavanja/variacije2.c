#include <stdio.h>
#include <math.h>

int main(){ // ??

    int n, k;
    scanf("%d %d", &n, &k);

    // 2 bita za eno črko (ker rabimo 3 stanja)
    int stevilo = 0;

    for(int i = 0; i < (int)pow(3, n); i++){    // info glede na vseh 10 bitov
        stevilo = i;
        if(stevilo % 3 == 0){
            stevilo++;
        }
        for(int j = 0; j < n*2; j+=2){
            if(i & (1 << j))
        }
    }


    return 0;
}