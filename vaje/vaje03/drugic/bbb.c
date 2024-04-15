#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int steviloStevk(long stevilo){
    int stevk = 0;
    long tmp = stevilo;
    while(tmp > 0){
        stevk++;
        tmp /= 10;
    }
    return stevk;
}

bool jePalindrom(int stevilo){
    int stevk = steviloStevk(stevilo);

    int j = 0;
    for(int i = 0; i <= floor(stevk/2.0); i++){
        //printf("%d\n", stevilo);
        int stevka = stevilo % 10;
        //printf("stevka: %d; st/pow: %d\n", stevka, (int)pow(10, stevk-j-1));
        if(stevka != stevilo / (int)pow(10, stevk-j-1)){
            return false;
        }
        stevilo -= (int)pow(10, stevk-j-1) * stevka;
        stevilo /= 10;
        j+=2;
    }
    return true;
}

long f(int n){
    // n prštej zrcalno sliko
    int stevk = steviloStevk(n);
    printf("n: %d\n", n);
    long zrcalno = 0, tmp = n;
    for(int i = 0; i < stevk; i++){
        zrcalno += (int)pow(10, stevk-i-1) * (tmp % 10);
        tmp /= 10;
    }
    printf("zrc: %ld\n", zrcalno);
    return n + zrcalno;
}

int main(){
    int k, a, b;
    scanf("%d %d %d", &k, &a, &b);

    int stevecDomnevnih = 0;

    for(int n = a; n <= b; n++){

        bool enoJePalindrom = false;
        long novo = 0;
        for(int iteracija = 0; iteracija < k; iteracija++){
            novo += f(n);
            //printf("novo: %ld\n", novo);
            if(novo > (int)pow(10, 17)){
                if(jePalindrom(novo)){
                    enoJePalindrom = true;
                }
                break;
            }
            if(jePalindrom(novo)){
                enoJePalindrom = true;
            }
        }

        if(!enoJePalindrom){
            stevecDomnevnih++;
        }

    }
    
    printf("%d\n", stevecDomnevnih);

    return 0;
}