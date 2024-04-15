#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define N 1000000

char tabela[N];

int steviloStevk(int n){
    if(n == 0) return 1;
    int stevec = 0;
    while(n > 0){
        stevec++;
        n /= 10;
    }
    return stevec;
}

int zapisiVTabelo(int indeks, char znak, int ponovitev, bool nespremenjeno){
    
    if(!nespremenjeno || znak == '#'){
        tabela[indeks++] = '#';
        tabela[indeks++] = znak;
        int stevk = steviloStevk(ponovitev);
        for(int i = 0; i < stevk; i++){
            int stevka = ponovitev / (int)pow(10, stevk-1-i);
            tabela[indeks++] = stevka + '0';
            ponovitev -= stevka * (int)pow(10, stevk-1-i);
        }
        tabela[indeks++] = '#';
    }
    else{
        for(int i = 0; i < ponovitev; i++){
            tabela[indeks++] = znak;
        }
    }

    /* for(int i = 0; i < 36; i++){
        printf("%c ", tabela[i]);
    }
    printf("\n"); */
    return indeks;
}

int main(){

    int u = getchar() - '0';
    getchar();
    int indeksTabela = 0;
    char trenutni = '\0', prejsnji = '\0';
    int zaporednoEnakih = 0;

    do{
        trenutni = getchar();
        switch(u){
            case 1: {   // kodiramo
                if(trenutni == prejsnji || prejsnji == '\0'){
                    zaporednoEnakih++;
                }
                else{
                    if(zaporednoEnakih > 4){
                        indeksTabela = zapisiVTabelo(indeksTabela, prejsnji, zaporednoEnakih, false);
                    }
                    else{
                        indeksTabela = zapisiVTabelo(indeksTabela, prejsnji, zaporednoEnakih, true);
                    }
                    zaporednoEnakih = 1;
                }
            }; break;
            case 2: {   // dekodiramo
                // ...
            }; break;
            default: break;
        }
        prejsnji = trenutni;
    }
    while(trenutni != '\n');

    for(int i = 0; i < indeksTabela; i++){
        printf("%c", tabela[i]);
    }
    printf("\n");

    return 0;
}