
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga1
 * make test
 *
 * Javni testni primeri:
 *
 * 01: iz besedila naloge
 * 02..04: a = b > 0
 * 05..07: a > b > 0
 * 01, 08..10: ni dodatnih omejitev glede a in b
 * 02, 04, 06, 08, 10: vsak bajt je bodisi 0 bodisi 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...

int main(int argc, char** argv) {

    FILE* vhodna1 = fopen(argv[1], "rb");
    FILE* vhodna2 = fopen(argv[2], "rb");
    FILE* izhodna = fopen(argv[3], "wb");

    unsigned char bajt1, bajt2;
    bool seVhodna1 = fread(&bajt1, 1, 1, vhodna1) > 0;
    bool seVhodna2 = fread(&bajt2, 1, 1, vhodna2) > 0;
    
    while(seVhodna1 || seVhodna2){
        // printf("%02x %02x\n", bajt1, bajt2);
        if(seVhodna1 && seVhodna2){
            if(bajt1 >= bajt2){
                fwrite(&bajt1, 1, 1, izhodna);
            }
            else{
                fwrite(&bajt2, 1, 1, izhodna);
            }
        }
        else if(seVhodna1){
            fwrite(&bajt1, 1, 1, izhodna);
        }
        else {
            fwrite(&bajt2, 1, 1, izhodna);
        }
        seVhodna1 = fread(&bajt1, 1, 1, vhodna1) > 0;
        seVhodna2 = fread(&bajt2, 1, 1, vhodna2) > 0;
    }

    fclose(vhodna1);
    fclose(vhodna2);
    fclose(izhodna);

    return 0;
}
