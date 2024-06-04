#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1000000

int main(int argc, char** argv){

    FILE* vhodna = fopen(argv[1], "rt");
    FILE* izhodna = fopen(argv[2], "wt");

    char* najdaljsaVrstica = malloc((N+1) * sizeof(char));
    int najZnakov = 0;

    char* trenutnoPrebrana = malloc((N+1) * sizeof(char));
    while(fgets(trenutnoPrebrana, N+1, vhodna) != NULL){
        int dolzinaTrenutne = strlen(trenutnoPrebrana);
        if(dolzinaTrenutne > najZnakov){
            strcpy(najdaljsaVrstica, trenutnoPrebrana);
            najZnakov = dolzinaTrenutne;
        }
    }

    fprintf(izhodna, "%s\n", najdaljsaVrstica);

    free(trenutnoPrebrana);
    free(najdaljsaVrstica);
    fclose(vhodna);
    fclose(izhodna);

    return 0;
}