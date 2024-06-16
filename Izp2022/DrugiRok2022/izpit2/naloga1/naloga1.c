
/*
Ro"cno testiranje (npr. za primer test01.bin):

gcc naloga1.c
./a.out test01.bin

Samodejno testiranje:

export name=naloga1
make test

Testni primeri:

test01: primer iz besedila
test02: datoteka z bajtom 00000000
test03: datoteka z bajtom 10110111
test04..test06: samodejno izdelani, zgolj bajti 00000000 in 00000001
test07..test10: samodejno izdelani, splo"sni

.bin: testni vhod
.out: pri"cakovani izhod
.res: izhod va"sega programa (pri poganjanju z make)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int pridobiStEnic(unsigned char bajt){
    int enic = 0;
    if(bajt % 2 == 1) enic++;   // LSB
    int eksponent = 7;
    while(eksponent > 0){
        unsigned char tmp = bajt >> eksponent;
        // printf("bajt: %d, tmp: %d\n", bajt, tmp);
        if(tmp > 0){
            enic++;
            bajt -= (int)pow(2, eksponent);
        }
        eksponent--;
    }
    return enic;
}

int main(int argc, char** argv) {
    
    FILE* datoteka = fopen(argv[1], "rb");

    unsigned char bajt;
    int stevilo = 0;

    while(fread(&bajt, 1, 1, datoteka) > 0){
        stevilo += pridobiStEnic(bajt);
    }

    printf("%d\n", stevilo);

    fclose(datoteka);
}