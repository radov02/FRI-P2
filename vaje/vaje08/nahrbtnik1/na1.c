#include <stdio.h>
#include <stdlib.h>

int MEMO[1001][1001];   // trenutni, V

int najvecjaCena(int trenutni, int V, int n, int* prostornine, int* cene){

    if(trenutni == n){
        return 0;
    }

    if(MEMO[trenutni][V] > 0){
        return MEMO[trenutni][V];
    }

    // brez predmeta:
    int najCena = najvecjaCena(trenutni+1, V, n, prostornine, cene);
    // z predmetom:
    if(V-prostornine[trenutni] >= 0){
        int cena = cene[trenutni] + najvecjaCena(trenutni+1, V-prostornine[trenutni], n, prostornine, cene);

        if(cena > najCena){
            najCena = cena;
        }
    }

    MEMO[trenutni][V] = najCena;

    return najCena;
}

int main(){

    int V, n;
    scanf("%d %d", &V, &n);
    int* prostornine = malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &prostornine[i]);
    }
    int* cene = malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &cene[i]);
    }

    printf("%d\n", najvecjaCena(0, V, n, prostornine, cene));

    return 0;
}