#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

    char* imeVhodna = argv[1];
    int vrstica = atoi(argv[2]);
    int stolpec = atoi(argv[3]);

    FILE* vhodna = fopen(imeVhodna, "rt");
    char* trash = malloc(3*sizeof(char));
    fscanf(vhodna, "%2s", trash);
    int sirina, visina;
    fscanf(vhodna, "%d %d\n%s\n", &sirina, &visina, trash);

    unsigned char* pike = malloc(3*sirina*visina*sizeof(unsigned char));
    
    fread(pike, sizeof(unsigned char), 3*sirina*visina, vhodna);

    int iskanaLokacija = (sirina*vrstica + stolpec) * 3;

    printf("%d %d %d", pike[iskanaLokacija], pike[iskanaLokacija+1], pike[iskanaLokacija+2]);

    fclose(vhodna);
    free(pike);
    free(trash);

    return 0;
}