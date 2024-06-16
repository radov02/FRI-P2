
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
.outB: pri"cakovani izhod za 0.3 to"cke (poljubna permutacija vrstic je tudi v redu)
.res: izhod va"sega programa (pri poganjanju z make)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void izpis(char* niz, int len){
    for(int i = 0; i < len; i++){
        printf("%c", niz[i]);
    }
    printf("\n");
}

void izpisi(int trenutnaCrka, char* noviNiz, int indeks, int n, int* frekvencePojavitevCrk, int dolzinaNiza, char* niz){

    if(indeks == n-1){
        noviNiz[indeks++] = niz[trenutnaCrka];
        izpis(noviNiz, indeks);
        return;
    }

    noviNiz[indeks++] = niz[trenutnaCrka];
    frekvencePojavitevCrk[trenutnaCrka]++;

    for(int i = 0; i < dolzinaNiza; i++){
        if(frekvencePojavitevCrk[i] < 3 && indeks < n){
            izpisi(i, noviNiz, indeks, n, frekvencePojavitevCrk, dolzinaNiza, niz);
        }
    }
    frekvencePojavitevCrk[trenutnaCrka]--;  // potrebno je odstraniti pojavitev ko vrnemo
}

int main(){

    int d, n;
    scanf("%d", &d);
    char* S = malloc((d+1)*sizeof(char));
    scanf("%s %d", S, &n);
    char* noviNiz = calloc((n+1), sizeof(char));

    for(int i = 0; i < d; i++){
        int* frekvencePojavitevCrk = calloc(d, sizeof(int));
        izpisi(i, noviNiz, 0, n, frekvencePojavitevCrk, d, S);
        free(frekvencePojavitevCrk);
    }

    free(noviNiz);
    free(S);

    return 0;
}
