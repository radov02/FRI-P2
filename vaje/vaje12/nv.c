#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN_VRSTICA 1000000

int main(int argc, char** argv){

    FILE* vhodna = fopen(argv[1], "r");
    FILE* izhodna = fopen(argv[2], "w");

    int najdaljsa = 0;
    char* najdaljsaVrstica = malloc((MAX_LEN_VRSTICA+1)*sizeof(char));
    char* vrstica = malloc((MAX_LEN_VRSTICA+1)*sizeof(char));
    while(fgets(vrstica, MAX_LEN_VRSTICA, vhodna) != NULL){
        int dolzina = strlen(vrstica);
        if(dolzina > najdaljsa){
            najdaljsa = dolzina;
            strcpy(najdaljsaVrstica, vrstica);
        }
    }

    fprintf(izhodna, "%s", najdaljsaVrstica);

    fclose(vhodna);
    fclose(izhodna);

    return 0;
}