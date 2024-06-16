
/*
Ro"cno testiranje (npr. za primer test01.in):

gcc naloga3.c
./a.out < test01.in

Samodejno testiranje:

export name=naloga3
make test

Testni primeri:

test01: primer iz besedila
test02..test08: "se nekaj dodatnih testov

.in: testni vhod
.outA: pri"cakovani izhod (poljubna permutacija vrstic je tudi v redu)
.outB: pri"cakovani izhod za 0.6 to"cke (poljubna permutacija vrstic je tudi v redu)
.outC: pri"cakovani izhod za 0.3 to"cke (poljubna permutacija vrstic je tudi v redu)
.res: izhod va"sega programa (pri poganjanju z make)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Lahko dodate "se kak #include, pomo"zno funkcijo ipd.

void izpis(char* niz, int len){
    for(int i = 0; i < len; i++){
        printf("%c", niz[i]);
    }
    printf("\n");
}

void izpisi(char novi, char* niz, int dolzinaNiz, bool mala, bool velika, bool stevka, char* S, int d, int zahtevanaDolzinaNizov){
    
    if(dolzinaNiz > zahtevanaDolzinaNizov) return;
    if(dolzinaNiz == zahtevanaDolzinaNizov && mala && velika && stevka){
        izpis(niz, dolzinaNiz);
        return;
    }
    if(dolzinaNiz == zahtevanaDolzinaNizov && (!mala || !velika || !stevka)){
        return;
    }

    // niz[dolzinaNiz++] = novi;
    // izpis(niz, dolzinaNiz);

    for(int i = 0; i < d; i++){
        char noviChar = S[i];
        bool m = false, v = false, s = false;
        if(noviChar >= 'a' && noviChar <= 'z'){
            m = true;
        }
        if(noviChar >= 'A' && noviChar <= 'Z'){
            v = true;
        }
        if(noviChar >= '0' && noviChar <= '9'){
            s = true;
        }
        niz[dolzinaNiz] = noviChar;
        izpisi(noviChar, niz, dolzinaNiz+1, (m || mala), (v || velika), (s || stevka), S, d, zahtevanaDolzinaNizov);
    }
}

int main(){

    int d, dolzinaNizov;
    scanf("%d", &d);
    char* S = malloc(d*sizeof(char));
    scanf("%s %d", S, &dolzinaNizov);

    char* niz = malloc(dolzinaNizov * sizeof(char));

    izpisi('*', niz, 0, false, false, false, S, d, dolzinaNizov);

    return 0;
}