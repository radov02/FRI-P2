#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){

    char* imeDatoteke = argv[1];
    int vrstica = atoi(argv[2]);
    int stolpec = atoi(argv[3]);

    FILE* datoteka = fopen(imeDatoteke, "rt");
    char format[3];
    int sirina, visina, maxBarva;
    fscanf(datoteka, "%2s", format);
    fscanf(datoteka, "%d %d %d", &sirina, &visina, &maxBarva);
    fgetc(datoteka);    // da prebere newline

    unsigned char* pike = malloc(3*sirina*visina * sizeof(char));
    fread(pike, sizeof(unsigned char), (sirina*visina*3), datoteka);

    int iskanaLokacija = (sirina*vrstica + stolpec) * 3;

    printf("%d %d %d", pike[iskanaLokacija], pike[iskanaLokacija+1], pike[iskanaLokacija+2]);

    fclose(datoteka);
    free(pike);

    return 0;
}