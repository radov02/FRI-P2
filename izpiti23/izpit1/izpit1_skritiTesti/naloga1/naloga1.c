#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv){

    FILE* vhodna = fopen(argv[1], "rb");
    FILE* izhodna = fopen(argv[2], "wb");

    unsigned char bajt;
    bool predhodni1B = false;

    while(fread(&bajt, 1, 1, vhodna) > 0){
        if(predhodni1B){
            if(bajt != 0xC9){
                unsigned char b1 = 0x1B;
                fwrite(&b1, 1, 1, izhodna);
            }
            predhodni1B = false;
        }
        if(bajt == 0x1B){
            predhodni1B = true;
        }
        else{
            fwrite(&bajt, 1, 1, izhodna);
        }
    }

    if(predhodni1B){
        unsigned char b1 = 0x1B;
        fwrite(&b1, 1, 1, izhodna);
    }

    fclose(vhodna);
    fclose(izhodna);

    return 0;
}