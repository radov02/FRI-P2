#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int najdiMinimumIndeks(int* buffer, int n){
    int minIndeks = -1;
    for(int i = 0; i < n; i++){
        if((minIndeks < 0 || buffer[i] < buffer[minIndeks]) && buffer[i] != -1){
            minIndeks = i;
        }
    }
    return minIndeks;
}

int main(){

    int n;
    scanf("%d", &n);
    char* imeDatoteke = malloc(101*sizeof(char));

    FILE** datoteke = malloc(n*sizeof(FILE*));
    for(int i = 0; i < n; i++){
        scanf("%s", imeDatoteke);
        datoteke[i] = fopen(imeDatoteke, "r");
    }
    FILE* izhodna = malloc(sizeof(FILE));
    scanf("%s", imeDatoteke);
    izhodna = fopen(imeDatoteke, "w");

    int stKoncanih = 0;
    int* buffer = calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        if(fscanf(datoteke[i], "%d", &buffer[i]) < 0){
            stKoncanih++;
            buffer[i] = -1;
        }
    }
    int minIndeks = 0;
    while(stKoncanih < n){
        minIndeks = najdiMinimumIndeks(buffer, n);
        fprintf(izhodna, "%d\n", buffer[minIndeks]);
        if(fscanf(datoteke[minIndeks], "%d", &buffer[minIndeks]) < 0){
            stKoncanih++;
            buffer[minIndeks] = -1;
        }
    }

    for(int i = 0; i < n; i++){
        fclose(datoteke[i]);
    }
    fclose(izhodna);
    free(datoteke);
    free(buffer);
    free(imeDatoteke);

    return 0;
}