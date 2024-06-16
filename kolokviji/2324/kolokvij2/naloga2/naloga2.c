
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga2
 * make test
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VRSTIC 100
#define MAX_NIZOV 100
#define MAX_ZNAKOV_NIZA 100

// po potrebi dopolnite ...

int main(int argc, char** argv) {

    FILE* vhodna = fopen(argv[1], "rt");
    FILE* izhodna = fopen(argv[2], "wt");
    int m = atoi(argv[3]);

    // naslovna vrstica:
    char** naslovnaVrstica = calloc(m, sizeof(char*));
    int stolpcev = 0;
    while(fscanf(vhodna, "%s", naslovnaVrstica[stolpcev++]) != EOF);

    // celoten array:
    char*** tabela = malloc((MAX_VRSTIC+1) * sizeof(char**));
    tabela[0] = naslovnaVrstica;
    int indeksVrstice = 1;
    char* vrstica = malloc(MAX_NIZOV * MAX_ZNAKOV_NIZA * sizeof(char));
    
    // čez vse vrstice:
    while(fgets(vrstica, MAX_NIZOV*MAX_ZNAKOV_NIZA, vhodna) != NULL){

        int indeksStolpca = 0;
        tabela[indeksVrstice] = malloc(stolpcev * sizeof(char*));

        char* token = strtok(vrstica, " ");
        for(int i = 0; i < m; i++){
            if(token == NULL){
                break;
            }
            tabela[indeksVrstice][indeksStolpca] = malloc((strlen(token)+1) * sizeof(char));
            strcpy(tabela[indeksVrstice][indeksStolpca], token);
            indeksStolpca++;
            token = strtok(NULL, " ");  // vrne naslednji token za vrstica
        }
        indeksVrstice++;
    }
    
    fclose(vhodna);
    fclose(izhodna);

    return 0;
}
