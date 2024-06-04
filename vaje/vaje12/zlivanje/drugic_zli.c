#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int vrniNajmanjsega(int* elementi, int n){
    int najmanjsiIndeks = 0;
    for(int i = 0; i < n; i++){
        if(elementi[i] != -1 && elementi[najmanjsiIndeks] > elementi[i]){
            najmanjsiIndeks = i;
        }
    }
    return elementi[najmanjsiIndeks];
}

int main(){

    int n;
    scanf("%d", &n);
    char* ime = malloc(100*sizeof(char));
    FILE** datoteke = malloc(10*sizeof(FILE*));
    for(int i = 0; i < n; i++){
        scanf("%s", ime);
        datoteke[i] = fopen(ime, "r");
    }
    scanf("%s", ime);
    FILE* izhodna = fopen(ime, "w");

    int steviloKoncanih = 0;
    int* elementi = calloc(n, sizeof(int));

    // prvic:
    for(int i = 0; i < n; i++){
        int stevilo = 0;
        if(fscanf(datoteke[i], "%d", &stevilo) != 0){
            elementi[i] = stevilo;
        }
    }

    while(steviloKoncanih != n){
        for(int i = 0; i < n; i++){
            if(elementi[i] == -1){
                int stevilo = 0;
                if(fscanf(datoteke[i], "%d", &stevilo) != 0){
                    elementi[i] = stevilo;
                }
                else if(elementi[i] > -1){
                    elementi[i] = -1;
                    steviloKoncanih++;
                }
            }
        }

        fprintf(izhodna, "%d", vrniNajmanjsega(elementi, n));
    }
    
    fclose(izhodna);
    for(int i = 0; i < n; i++){
        fclose(datoteke[i]);
    }
    free(datoteke);
    free(ime);
    free(elementi);

    return 0;
}