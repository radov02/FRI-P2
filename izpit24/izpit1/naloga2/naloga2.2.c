
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

// po potrebi dopolnite ...

int main(int argc, char** argv) {

    char* vhodnaIme = argv[1];
    char* izhodnaIme = argv[2];
    int m = atoi(argv[3]);
    char** izhodStolpci = calloc(m, sizeof(char*));
    for(int i = 4; i < argc; i++){
        izhodStolpci[i-4] = argv[i];
    }

    FILE* vhodna = fopen(vhodnaIme, "rt");
    FILE* izhodna = fopen(izhodnaIme, "wt");
    
    char*** csvTabela = malloc(100*sizeof(char**));
    char* vrstica = malloc(m*101*sizeof(char));
    int iVrstica = 0;

    while(fgets(vrstica, m*101, vhodna) > 0){
        csvTabela[iVrstica] = malloc(m*sizeof(char*));

        // prvi string iz vrstice:
        char* token1 = strtok(vrstica, " \n");
        csvTabela[iVrstica][0] = malloc(101*sizeof(char));
        strcpy(csvTabela[iVrstica][0], token1);

        // ostali stringi iz vrstice:
        for(int i = 1; i < m; i++){     
            char* token = strtok(NULL, " \n");
            csvTabela[iVrstica][i] = malloc(101*sizeof(char));
            strcpy(csvTabela[iVrstica][i], token);
        }
        iVrstica++;
    }

    /* // izpis tabele csv:
    for(int i = 0; i < iVrstica; i++){
        for(int j = 0; j < m; j++){
            printf("csvTabela[%d][%d]=%s\n", i, j, csvTabela[i][j]);
        }
        printf("\n");
    } */

    int* indeksiStolpcev = malloc((argc-4)*sizeof(int));    // 4, 2, 1
    int indeks = 0;
    int pregledujem = 0;    // beseda iz izhodStolpci[]
    while(izhodStolpci[pregledujem] != NULL){
        for(int i = 0; i < m; i++){
            if(strcmp(izhodStolpci[pregledujem], csvTabela[0][i]) == 0){
                indeksiStolpcev[indeks++] = i;
            }
        }
        pregledujem++;
    }

    for(int i = 0; i < iVrstica; i++){
        for(int j = 0; j < indeks; j++){
            if(j < indeks-1){
                fprintf(izhodna, "%s,", csvTabela[i][indeksiStolpcev[j]]);
            }
            else{
                fprintf(izhodna, "%s", csvTabela[i][indeksiStolpcev[j]]);
            }
        }
        fprintf(izhodna, "\n");
    }

    // ------ free -------
    /* for(int i = 0; i < m; i++){
        free(izhodStolpci[i]);
    }
    free(izhodStolpci);

    for(int i = 0; i < iVrstica; i++){
        for(int j = 0; j < m; j++){
            free(csvTabela[i][j]);
        }
        free(csvTabela[i]);
    }
    free(csvTabela);

    free(vrstica);

    free(indeksiStolpcev); */

    fclose(vhodna);
    fclose(izhodna);
    
    return 0;
}