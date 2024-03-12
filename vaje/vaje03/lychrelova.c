#include <stdio.h>
#include <stdbool.h>
#include <math.h>

long obrni(long stevilo){

    long obrnjeno = 0;

    while(stevilo > 0){
        obrnjeno *= 10;
        obrnjeno += (stevilo % 10);
        stevilo -= (stevilo % 10);
        stevilo /= 10;
    }

    return obrnjeno;
}

bool jePalindrom(long stevilo){
    return (obrni(stevilo) == stevilo);
}

bool jeDomnevnoLychrelovo(int n, int k){

    long f = n + obrni(n);
    int iteracija = 0;

    while(iteracija <= k){
        f += obrni(f);
        iteracija++;
        if(f > pow(10, 17)){
            if(jePalindrom(f)){
                return false;
            }
            else{
                return true;
            }
        }
        if(jePalindrom(f)){
            return false;
        }
    }
    
    return true;
}

int main(){

    int k = 0, a = 0, b = 0;
    
    scanf("%d %d %d", &k, &a, &b);

    int stevec = 0;

    for(int i = a; i <= b; i++){
        if(jeDomnevnoLychrelovo(i, k)){
            printf("%d\n", i);
            stevec++;
        }
    }

    printf("%d", stevec);

    return 0;
}