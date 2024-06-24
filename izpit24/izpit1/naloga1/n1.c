#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(int argc, char** argv){

    FILE* vhodna = fopen(argv[1], "r");
    FILE* izhodna = fopen(argv[2], "w");
    int n, p;
    fscanf(vhodna, "%d %d\n", &n, &p);
    char*** sprehodi = malloc(p*sizeof(char**));
    int* dolzineSprehodov = malloc(p*sizeof(int));

    char* vrstica = malloc(2*n*n*3*sizeof(char));
    int i = 0;
    while(fgets(vrstica, 2*n*n*3, vhodna) != NULL){
        sprehodi[i] = malloc(2*n*n*sizeof(char*));
        // printf("%s\n", vrstica);
        char* token = strtok(vrstica, " \n");
        int j = 0;
        while(token != NULL){
            sprehodi[i][j] = malloc(3*sizeof(char));
            strcpy(sprehodi[i][j], token);
            token = strtok(NULL, " \n");
            j++;
        }
        dolzineSprehodov[i] = j;
        i++;
    }

    for(int i = 0; i < p; i++){
        bool veljavno = true;
        // veljaven skakačev sprehod
        for(int j = 1; j < dolzineSprehodov[i]; j++){
            if(!((int)fabs((sprehodi[i][j][0] - 'a') - (sprehodi[i][j-1][0] - 'a')) * (int)fabs(sprehodi[i][j][1] - sprehodi[i][j-1][1]) == 2)){
                veljavno = false;
                break;
            }
        }

        // čez vsako polje natanko 1x
        if(veljavno && dolzineSprehodov[i] != n*n){
            veljavno = false;
        }
        if(veljavno){
            // vsi razlicni
            for(int j = 0; j < dolzineSprehodov[i]; j++){
                for(int k = j+1; k < dolzineSprehodov[i]; k++){
                    if(strcmp(sprehodi[i][j], sprehodi[i][k]) == 0){
                        veljavno = false;
                        goto ven;
                    }
                }
            }
        }
        ven:

        if(veljavno){
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