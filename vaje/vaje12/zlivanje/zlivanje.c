#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_DOLZINA_IMENA 101

int minimalniElementIndeks(int* elementi, int elementov) {
    int najmanjsi = INT_MAX;
    int indeksMin = -1;
    for(int i = 0; i < elementov; i++){
        if(elementi[i] != -1 && (indeksMin > 0 || elementi[i] < najmanjsi)){
            najmanjsi = elementi[i];
            indeksMin = i;
        }
    }
    return indeksMin;
}

int main(){
    // size_t je tip, ki pove število bajtov

    int n;
    scanf("%d", &n);
    char* imeDatoteke = malloc(MAX_DOLZINA_IMENA * sizeof(char));

    FILE** tabelaDatotek = malloc(n * sizeof(FILE*));
    for(int i = 0; i < n; i++){
        scanf("%s", imeDatoteke);
        tabelaDatotek[i] = fopen(imeDatoteke, "rt");
    }
    scanf("%s", imeDatoteke);
    FILE* izhodna = fopen(imeDatoteke, "wt");
    
    int stKoncanih = 0;
    int* elementi = calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        if(fscanf(tabelaDatotek[i], "%d", &elementi[i]) < 0){    // če je EOF (negativno)
            stKoncanih++;
            elementi[0] = -1;
        }
    }
    
    while(stKoncanih != n){
        int izDatotekeIndeks = minimalniElementIndeks(elementi, n);
        fprintf(izhodna, "%d", elementi[izDatotekeIndeks]);
        if(fscanf(tabelaDatotek[izDatotekeIndeks], "%d", &elementi[izDatotekeIndeks]) < 0){    // če je EOF (negativno)
            stKoncanih++;
            elementi[izDatotekeIndeks] = -1;
        }
    }

    free(elementi);
    free(imeDatoteke);
    for(int i = 0; i < n; i++){
        fclose(tabelaDatotek[i]);
    }
    free(tabelaDatotek);
    fclose(izhodna);

    return 0;
}