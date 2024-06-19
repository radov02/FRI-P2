#include <stdio.h>

int main(){

    int n = getchar() - '0';
    getchar();

    int najvecje = -1;
    int drugoNajvecje = -1;

    for(int i = 0; i < n; i++){
        int novoSt = getchar() - '0';
        getchar();

        if(novoSt > najvecje){
            drugoNajvecje = najvecje;
            najvecje = novoSt;
        }
        else if(novoSt > drugoNajvecje){
            drugoNajvecje = novoSt;
        }
    }

    putchar(drugoNajvecje + '0');
    putchar('\n');

    return 0;
}