
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga1
 * make test
 *
 * Javni testni primeri:
 * 02..06: v vsakem podprimeru je "stevilo polj enako n^2
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int main(int argc, char** argv) {

    FILE* vhodna = fopen(argv[1], "rt");
    FILE* izhodna = fopen(argv[2], "wt");

    int n, p;
    fscanf(vhodna, "%d %d", &n, &p);
    fgetc(vhodna);  // '\n' na koncu

    char*** sprehodi = calloc(p, sizeof(char**));
    for(int sprehod = 0; sprehod < p; sprehod++){
        sprehodi[sprehod] = calloc(2*n*n, sizeof(char*));

        char* prebranaVrstica = malloc(2*n*n*3*sizeof(char));
        fgets(prebranaVrstica, 2*n*n*3, vhodna);    // rabimo da prebere vrstico kot en niz

        char* niz = malloc(3*sizeof(char));
        niz = strtok(prebranaVrstica, " \n");   // vrne naslednji token oziroma NULL
        int i = 0;
        while(niz != NULL){
            sprehodi[sprehod][i++] = niz;
            niz = strtok(NULL, " \n");
        }

        bool ena = true;
        if(i != n*n){    // vsa polja
            ena = false;
        }

        if(ena){    // veljavnost (skakanje skakača)
            for(int j = 0; j < i-1; j++){
                if((int)fabs((sprehodi[sprehod][j][0] - 'a') - (sprehodi[sprehod][j+1][0] - 'a')) * (int)fabs(sprehodi[sprehod][j][1] - sprehodi[sprehod][j+1][1]) != 2){
                    ena = false;
                    break;
                }
            }
        }

        if(ena){
            for(int j = 0; j < i; j++){ // ponavljanje polj
                for(int k = j+1; k < i; k++){
                    if(strcmp(sprehodi[sprehod][j], sprehodi[sprehod][k]) == 0){
                        ena = false;
                        goto ven;
                    }
                }
            }
        }
        ven:

        if(ena){
            fprintf(izhodna, "%c\n", '1');
        }
        else{
            fprintf(izhodna, "%c\n", '0');
        }
    }

    fclose(vhodna);
    fclose(izhodna);

    return 0; 
}
