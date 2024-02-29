#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool jePalindrom(long stevilo){
    int mest = (int) (log10(stevilo)) + 1;

    int enica = stevilo % 10;
    int leva = enica * pow(10, mest-1);
    bool jePal = false;

    while(stevilo - leva < pow(10, mest-1)){
        jePal = true;
        stevilo -= leva;
        stevilo = stevilo / 10;
        if(stevilo - leva >= pow(10, mest-1)){
            jePal = false;
            break;
        }
        if(stevilo <= 0) break;
    }

    return jePal;
}

int main(){

    long stevilo = -1;
    
    for(int i = 999; i >= 100; i--){
        for(int j = 999; j >= 100; j--){
            stevilo = i * j;
            if(jePalindrom(stevilo)){
                printf("%ld\n", stevilo);
                break;
            }
        }
    }

    return 0;
}