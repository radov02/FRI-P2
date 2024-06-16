
/*
Ro"cno testiranje (npr. za primer 01):

gcc naloga1.c
./a.out vhod01.pgm 150 izhod01.pgm
cmp izhod01.pgm ref01.pgm

Samodejno testiranje:

export name=naloga1
make test

Lahko si pomagate tudi s programom hexdump:

hexdump -C datoteka.pgm

Testni primeri:

01: primer iz besedila
02..07: vsaka pika je bodisi 0 bodisi 255
08..12: splo"sni primeri

Testne datoteke:

test*.par: argumenti ukazne vrstice
vhod*.pgm: vhodna slika
ref*.pgm: pri"cakovana izhodna slika
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Lahko dodate "se kak #include, pomo"zno funkcijo ipd.

//============================================================================

int main(int argc, char** argv) {
    setbuf(stdout, NULL);
    
    FILE* vhodna = fopen(argv[1], "rb");
    int prag = atoi(argv[2]);
    FILE* izhodna = fopen(argv[3], "wb");

    char* str = malloc(3*sizeof(char));
    int w, h;
    char* a255 = malloc(3*sizeof(char));
    fscanf(vhodna, "%s %d %d %s", str, &w, &h, a255);

    fgetc(vhodna);
    fprintf(izhodna, "%s\n%d %d\n%s\n", str, w, h, a255);

    unsigned char* vrstica = malloc(w*sizeof(unsigned char));
    for(int i = 0; i < h; i++){
        fread(vrstica, 1, w, vhodna);
        for(int j = 0; j < w; j++){
            printf("vrstica[%d] = %d\n", j, vrstica[j]);
            if(vrstica[j] >= prag){
                vrstica[j] = 255;
            }
            else{
                vrstica[j] = 0;
            }
        }
        for(int i = 0; i < w; i++){
            printf("%d\n", vrstica[i]);
        }
        printf("\n");
        fwrite(vrstica, 1, w, izhodna);
    }

    fclose(vhodna);
    fclose(izhodna);
}
