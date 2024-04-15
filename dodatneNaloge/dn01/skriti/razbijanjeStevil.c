#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int steviloStevk(long n){
    if(n == 0) return 1;
    int stevec = 0;
    while(n > 0){
        stevec++;
        n /= 10;
    }
    return stevec;
}

int main(){

    long n, m;
    scanf("%ld %ld", &n, &m);

    int stDelov = steviloStevk(m);
    // printf("%d\n",stDelov);
    int stevkPrve = steviloStevk(n);
    int indeksPriPrvi = 0;

    for(int i = 0; i < stDelov; i++){
        int potenca = (long)pow(10, stDelov - 1 - i);
        int dolzinaDela = m / potenca;
        bool predhodneNicle = true;
        // printf("dolzinaDela: %d\n", dolzinaDela);
        for(int j = 0; j < dolzinaDela; j++){
            long potenca10 = (long)pow(10, stevkPrve - 1 - indeksPriPrvi);
            // printf("potenca10: %ld\n", potenca10);
            int stevka = n / potenca10;
            if(stevka != 0){
                predhodneNicle = false;
            }
            if(!predhodneNicle ||  dolzinaDela == 1)
                putchar(stevka + '0');
            n -= stevka * potenca10;
            indeksPriPrvi++;
        }
        m -= dolzinaDela * potenca;
        putchar('\n');
    }

    return 0;
}