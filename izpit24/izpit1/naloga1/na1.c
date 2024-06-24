#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// NE DELA

int main(int argc, char** argv){

    FILE* vhodna = fopen(argv[1], "r");
    FILE* izhodna = fopen(argv[2], "w");
    int n, p;
    fscanf(vhodna, "%d %d\n", &n, &p);  // preberi \n !!!
    char*** vrstice = malloc(p*sizeof(char**));
    int* dolzineVrstic = malloc(p*sizeof(int));
    for(int i = 0; i < p; i++){
        vrstice[i] = malloc(2*n*n*sizeof(char*));

        char* vrstica = malloc(2*n*n*3*sizeof(char));
        while(fgets(vrstica, (2*n*n*3+1), vhodna) != NULL){
            // if(i == 0)printf("%s_v\n", vrstica);

            char* token = strtok(vrstica, " \n");
            int j = 0;
            while(token != NULL){
                vrstice[i][j] = malloc(3*sizeof(char));
                strcpy(vrstice[i][j], token);
                token = strtok(NULL, " \n");
                j++;
            }
            dolzineVrstic[i] = j;
        }
    }

    for(int i = 0; i < p; i++){
        bool veljavno = true;

        // veljaven skok
        for(int j = 1; j < dolzineVrstic[i]; j++){
            if(!((int)fabs((vrstice[i][j][0]-'a') - (vrstice[i][j-1][0]-'a')) * (int)fabs((int)vrstice[i][j][1] - (int)vrstice[i][j-1][1]) == 2)){
                printf("niveljavenSkok, i:%d, j: %d, %d, %d, %s, %s\n", i, j, (int)fabs((vrstice[i][j][0]-'a') - (vrstice[i][j-1][0]-'a')), (int)fabs(vrstice[i][j][1] - vrstice[i][j-1][1]), vrstice[i][j], vrstice[i][j-1]);
                veljavno = false;
                break;
            }
        }

        // vsako polje natanko 1x (n*n in brez ponavljanj)
        if(veljavno){
            if(dolzineVrstic[i] == n*n){
                for(int j = 0; j < dolzineVrstic[i]; j++){
                    for(int k = j+1; k < dolzineVrstic[i]; k++){
                        if(strcmp(vrstice[i][j], vrstice[i][k]) == 0){
                            // printf("ponavljajo se\n");
                            veljavno = false;
                            goto ven;
                        }
                    }
                }
            }
            else{
                veljavno = false;
                // printf("niNxN\n");
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