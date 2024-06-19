#include <stdio.h>
#include <stdlib.h>

int najdiIndeksNajmanjsega(int* tabela, int len){
    int min = -1;
    for(int i = 0; i < len; i++){
        if(tabela[i] != -1 && (min == -1 || tabela[i] < tabela[min])){
            min = i;
        }
    }
    return min;
}

int main(){

    int n;
    scanf("%d", &n);
    FILE** datoteke = malloc(n*sizeof(FILE*));
    for(int i = 0; i < n; i++){
        char* ime = malloc(100*sizeof(char));
        scanf("%s", ime);
        FILE* dat = fopen(ime, "r");
        datoteke[i] = dat;
    }
    char* imeIzhodne = malloc(100*sizeof(char));
    scanf("%s", imeIzhodne);
    FILE* izhodna = fopen(imeIzhodne, "w");

    int stevila[n];
    int min = 0;
    int koncanih = 0;
    for(int i = 0; i < n; i++){
        if(fscanf(datoteke[i], "%d", &stevila[i]) < 0){
            koncanih++;
            stevila[i] = -1;
        }
    }

    while(koncanih < n){
        /* for(int i = 0; i < n; i++){
            printf("%d ", stevila[i]);
        }
        printf("\n"); */
        int najmanjsi = najdiIndeksNajmanjsega(stevila, n);
        if(stevila[najmanjsi] != -1){
            fprintf(izhodna, "%d\n", stevila[najmanjsi]);
        }

        if(fscanf(datoteke[najmanjsi], "%d", &stevila[najmanjsi]) == EOF){
            koncanih++;
            stevila[najmanjsi] = -1;
        }
    }

    for(int i = 0; i < n; i++){
        fclose(datoteke[i]);
    }
    fclose(izhodna);

    return 0;
}