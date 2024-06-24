#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv){

    FILE* vhodna = fopen(argv[1], "rb");
    FILE* izhodna = fopen(argv[2], "wb");

    char* P6 = malloc(3*sizeof(char));
    int w, h, dpp;
    fscanf(vhodna, "%s\n%d %d\n%d\n", P6, &w, &h, &dpp);

    fprintf(izhodna, "P5\n%d %d\n255\n", w, h);

    unsigned char* pika = malloc(3*sizeof(unsigned char));
    while(fread(pika, sizeof(unsigned char), 3, vhodna) > 0){
        // printf("%d %d %d\n", pika[0], pika[1], pika[2]);
        unsigned char sivinska = floor((30*pika[0] + 59*pika[1] + 11*pika[2]) / 100);
        // printf("%d\n", sivinska);
        fwrite(&sivinska, sizeof(unsigned char), 1, izhodna);
    }

    fclose(vhodna);
    fclose(izhodna);

    return 0;
}