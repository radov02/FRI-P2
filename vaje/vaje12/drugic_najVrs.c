#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){

    char* imeVhodne = argv[1];
    char* imeIzhodne = argv[2];
    FILE* vhodna = fopen(imeVhodne, "rt");
    FILE* izhodna = fopen(imeIzhodne, "w");

    int najvecjaDolzina = 0;
    char* najdaljsa = malloc(1000000*sizeof(char));
    char* vrstica = malloc(1000000*sizeof(char));
    while((vrstica = fgets(vrstica, 1000000, vhodna)) != NULL){
        int dolzina = strlen(vrstica);
        if(dolzina > najvecjaDolzina){
            najvecjaDolzina = dolzina;
            //najdaljsa = vrstica;    // NE! zdaj imamo 2 pointerja na isto stvar!
            strcpy(najdaljsa, vrstica);
        }
    }

    fprintf(izhodna, "%s", najdaljsa);

    free(vrstica);
    fclose(vhodna);
    fclose(izhodna);

    return 0;
}
