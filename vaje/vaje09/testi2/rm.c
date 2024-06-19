#include <stdio.h>
#include <stdlib.h>

int* kazalciNaPodmnozice[20];
int ind = 0;

// NE DELA OK

void izpis(int* podmnozica, int indeks){
    printf("{");
    for(int i = 0; i < indeks; i++){
        if(i < indeks-1){
            printf("%d, ", podmnozica[i]);
        }
        else{
            printf("%d}\n", podmnozica[i]);
        }
    }
}

void razbij(int* podmnozica, int indeks, int* mnozica, int trenutniElement, int n, int vsotaZaPodmnozico){

    if(vsotaZaPodmnozico == 0){
        kazalciNaPodmnozice[ind] = calloc(indeks+1, sizeof(int));
        for(int i = 0; i < indeks; i++){
            kazalciNaPodmnozice[ind][i] = podmnozica[i];
        }
        ind++;
        //izpis(podmnozica, indeks);
        return;
    }
    if(trenutniElement == n){
        return;
    }

    // ne dodamo trenutnega elementa v mnozico:
    razbij(podmnozica, indeks, mnozica, trenutniElement+1, n, vsotaZaPodmnozico);
    // dodamo trenutni element v mnozico:
    if(vsotaZaPodmnozico - mnozica[trenutniElement] >= 0){
        podmnozica[indeks++] = mnozica[trenutniElement];
        vsotaZaPodmnozico -= mnozica[trenutniElement];
        razbij(podmnozica, indeks, mnozica, trenutniElement+1, n, vsotaZaPodmnozico);
    }
}

int main(){

    int n;
    scanf("%d", &n);
    int* mnozica = malloc(n*sizeof(int));
    int vsota = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &mnozica[i]);
        vsota += mnozica[i];
    }
    int* podmnozica = malloc(n*sizeof(int));
    podmnozica[0] = mnozica[0];
    razbij(podmnozica, 1, mnozica, 1, n, vsota/2 - mnozica[0]);

    // izpis:
    for(int i = ind-1; i >= 0; i--){
        printf("{");
        int j = 0;
        while(kazalciNaPodmnozice[i][j] != 0){
            if(kazalciNaPodmnozice[i][j+1] != 0){
                printf("%d, ", kazalciNaPodmnozice[i][j]);
            }
            else{
                printf("%d}\n", kazalciNaPodmnozice[i][j]);
            }
            j++;
        }
    }

    return 0;
}