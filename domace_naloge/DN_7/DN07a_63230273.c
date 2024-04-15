#include <stdio.h>

int visinaDrevesa(int **tabela, int indeks, int maxVisina){
    // levi otrok je na tabela[]
    
    if(tabela[tabela[][]] == 0){

    }

    int visinaPoLevi = visinaDrevesa(tabela, tabela[indeks][0] - 1);
    int visinaPoDesni = visinaDrevesa(tabela, tabela[indeks][1] - 1);

    
}

int main(){

    int n;
    scanf("%d", &n);

    int **tabela = calloc(n * sizeof(int*));

    for(int i = 0; i < n; i++){
        tabela[i] = malloc(2 * sizeof(int));
        scanf("%d %d", &tabela[i][0], &tabela[i][1]);
    }

    int visina = visinaDrevesa(tabela, 0, );
    printf("%d\n", visina);

    return 0;
}