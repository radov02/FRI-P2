#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv){

    FILE* vhodna = fopen(argv[1], "rt");
    FILE* izhodna = fopen(argv[2], "wt");

    char format[3];
    int sirina, visina, maxBarva;
    fscanf(vhodna, "%2s", format);
    fscanf(vhodna, "%d %d %d", &sirina, &visina, &maxBarva);
    fgetc(vhodna);  // newline

    // unsigned char* sivinePik = malloc(visina*sirina*sizeof(unsigned char));
    unsigned char* pike = malloc(visina*sirina*3*sizeof(unsigned char));
    fread(pike, sizeof(unsigned char), sirina*visina*3, vhodna);

    fprintf(izhodna, "P5\n%d %d\n%d\n", sirina, visina, maxBarva);

    for(int i = 0; i < sirina*visina*3; i+=3){
        unsigned char sivina = floor((30 * pike[i] + 59*pike[i+1] + 11*pike[i+2]) / 100);
        fprintf(izhodna, "%c", sivina);
    }

    free(pike);
    fclose(vhodna);
    fclose(izhodna);

    return 0;
}