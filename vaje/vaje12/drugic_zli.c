#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int vrniNajmanjsegaIndeks(int* elementi, int n){
    int najmanjsiIndeks = -1;
    for(int i = 0; i < n; i++){
        if(elementi[i] != -1 && (najmanjsiIndeks < 0 || elementi[i] < elementi[najmanjsiIndeks])){
            najmanjsiIndeks = i;
        }
    }
    return najmanjsiIndeks;
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
        if(fscanf(datoteke[i], "%d", &elementi[i]) < 0){
            steviloKoncanih++;
            elementi[i] = -1;
        }
    }

    while(steviloKoncanih < n){
        int izDatotekeIndeks = minimalniElementIndeks(elementi, n);
        fprintf(izhodna, "%d\n", elementi[izDatotekeIndeks]);
        if(fscanf(datoteke[izDatotekeIndeks], "%d", &elementi[izDatotekeIndeks]) < 0){    // če je EOF (negativno)
            steviloKoncanih++;
            elementi[izDatotekeIndeks] = -1;
        }
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