
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga1
 * make test
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...

int main(int argc, char** argv) {
   
    FILE* vhodna = fopen(argv[1], "rb");
    FILE* izhodna = fopen(argv[2], "wb");

    unsigned char bajt;
    unsigned char prejsnji = '\0';

    while(fread(&bajt, 1, 1, vhodna) > 0){
        if(prejsnji == bajt){
            continue;
        }
        else{
            fwrite(&bajt, 1, 1, izhodna);
        }
        prejsnji = bajt;
    }

    fclose(vhodna);
    fclose(izhodna);

    return 0;
}
