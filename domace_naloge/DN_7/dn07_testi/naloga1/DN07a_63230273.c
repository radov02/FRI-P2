#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int visinaDrevesa(int indeks, int** tabela){

    int visina = 0;
    if(tabela[indeks][0] != 0){
        visina = 1 + visinaDrevesa(indeks + tabela[indeks][0], tabela);
    }
    if(tabela[indeks][1] != 0){
        int visinaDesna = 1 + visinaDrevesa(indeks + tabela[indeks][1], tabela);
        if(visina < visinaDesna){
            visina = visinaDesna;
        }
    }
    
    return visina;
}

int main(){

    int n;
    scanf("%d", &n);

    int **tabela = calloc(n, sizeof(int*));

    for(int i = 0; i < n; i++){
        tabela[i] = calloc(2, sizeof(int));
        scanf("%d %d", &tabela[i][0], &tabela[i][1]);
    }

    int visina = visinaDrevesa(0, tabela);
    
    printf("%d\n", visina);

    return 0;
}