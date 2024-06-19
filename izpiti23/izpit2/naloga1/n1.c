#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

    // NI OK

    FILE* vhodna = fopen(argv[1], "r");
    FILE* izhodna = fopen(argv[2], "w");

    unsigned char bajt, prejsnji = '\0';

    while(fread(&bajt, 1, 1, vhodna) > 0){
        
        if(prejsnji == '\0' || bajt != prejsnji){
            fwrite(&bajt, 1, 1, izhodna);
        }

        prejsnji = bajt;
    }

    fclose(vhodna);
    fclose(izhodna);

    return 0;
}