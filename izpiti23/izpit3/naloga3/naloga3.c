
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 *
 * Javni testni primeri:
 *
 * 01: iz besedila naloge
 * 02..04: znaki v nizu so padajo"ce urejeni
 * 01, 05..10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LEN 200

int indeks = 0;
int presledkov = 0;

void izpis(char* niz, int zacetek, int konec) {

    for(int i = 0; i < presledkov; i++){
        printf(" ");
    }

    for(int i = zacetek; i < konec; i++){
        printf("%c", niz[i]);
    }
    printf("\n");
}

void izpisStopnicast(char* niz, int zacetek, int konec){

    for(int i = 0; i < presledkov; i++){
        printf(" ");
    }

    for(int i = zacetek; i < konec; i++){
        printf("%c\n", niz[i]);
        presledkov++;
    }
}

void izpisi(int zacetek, int konec, char* niz, int nizlen, char znak);

void narediIzpis(int i, char* niz, int zacetek, int konec, char znak, int nizlen){
    izpis(niz, zacetek, konec); 
    if(i - zacetek > 0){
        izpisStopnicast(niz, zacetek, i);
    }
    else{
        printf("%c\n", niz[zacetek]);
    }
    for(int j = 0; j < i-zacetek; j++){
        printf(" ");
        presledkov++;
    }
    printf("%c\n", znak);
    presledkov++;
    izpisi(i+1, konec, niz, nizlen, znak);
}

void izpisi(int zacetek, int konec, char* niz, int nizlen, char znak){

    int i = zacetek;
    for(; i < konec; i++){
        if(niz[i] == znak){
            narediIzpis(i, niz, zacetek, konec, znak, nizlen);
            break;
        }
    }
}

int main() {
    
    char* niz = calloc(MAX_LEN, sizeof(char));
    scanf("%s", niz);
    char najvecjiASCII = 0;
    for(int i = 0; i < strlen(niz); i++){
        if(niz[i] > najvecjiASCII){
            najvecjiASCII = niz[i];
        }
    }

    int nizLen = strlen(niz);
    izpisi(0, nizLen, niz, nizLen, najvecjiASCII);

    free(niz);

    return 0;
}
