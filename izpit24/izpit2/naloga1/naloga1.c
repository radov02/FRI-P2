
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga1
 * make test
 *
 * Javni testni primeri:
 *
 * 02..06: v vsakem podprimeru je "stevilo nizov enako 42
 * 01, 07..10: splo"sni primeri
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// po potrebi dopolnite ...

int V[] = {1, 1, 2, 2, -1, -1, -2, -2};
int S[] = {2, -2, 1, -1, -2, 2, -1, 1};

int main(int argc, char** argv) {
    
    FILE* vhodna = fopen(argv[1], "r");
    FILE* izhodna = fopen(argv[2], "w");

    int n, p;
    fscanf(vhodna, "%d %d\n", &n, &p);
    char*** vrstica = malloc(p*sizeof(char**));
    int* dolzineVrstic = malloc(p*sizeof(int));
    for(int i = 0; i < p; i++){
        vrstica[i] = malloc(100*sizeof(char*));

        char* prebrana = malloc(100*3*sizeof(char));
        fgets(prebrana, 100*3, vhodna);
        // printf("%s\n", prebrana);

        int j = 0;
        char* token = strtok(prebrana, " \n");
        while(token != NULL){
            vrstica[i][j] = malloc(3*sizeof(char));
            strcpy(vrstica[i][j], token);
            token = strtok(NULL, " \n");
            j++;
        }
        dolzineVrstic[i] = j;
    }

    for(int i = 0; i < p; i++){
        // printf("------\n");

        bool veljaven = true;
        bool* vektorjev = calloc(8, sizeof(bool));

        // veljavni premiki:
        for(int j = 1; j < dolzineVrstic[i]; j++){
            
            // printf("%s %s\n", vrstica[i][j], vrstica[i][j-1]);
            int dv = (vrstica[i][j][0] - 'a') - (vrstica[i][j-1][0] - 'a');
            int ds = vrstica[i][j][1] - vrstica[i][j-1][1];
            // printf("%d %d\n", dv, ds);
            if((int)fabs(dv) * (int)fabs(ds) != 2){
                // printf("1.\n");
                veljaven = false;
                break;
            }
            
            if(veljaven){
                for(int k = 0; k < 8; k++){
                    if(dv == V[k] && ds == S[k]){
                        vektorjev[k] = true;
                    }
                }
            }
        }

        // vsi vektorji premika:
        if(veljaven){
            // printf("vekt: ");
            for(int j = 0; j < 8; j++){
                // printf("%d ", vektorjev[j]);
                // printf("\n");
                if(!vektorjev[j]){
                    veljaven = false;
                    break;
                }
            }
        }

        if(veljaven){
            fprintf(izhodna, "1\n");
        }
        else{
            fprintf(izhodna, "0\n");
        }
    }


    fclose(vhodna);
    fclose(izhodna);

    return 0;
}
