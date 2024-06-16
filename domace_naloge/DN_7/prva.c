#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int visinaDrevesa(int trenutno, int** vozlisca, int n){

    int visina = 0;
    if(vozlisca[trenutno][0] != 0){
        visina = 1 + visinaDrevesa(vozlisca[trenutno][0] + trenutno, vozlisca, n);
    }
    if(vozlisca[trenutno][1] != 0){
        int desnaVisina = 1 + visinaDrevesa(vozlisca[trenutno][1] + trenutno, vozlisca, n);
        if(desnaVisina > visina){
            visina = desnaVisina;
        }
    }

    return visina;
}

int main(){

    int n;
    scanf("%d", &n);
    int** vozlisca = malloc(n*sizeof(int*));
    for(int i = 0; i < n; i++){
        vozlisca[i] = malloc(2*sizeof(int));
        scanf("%d%d", &vozlisca[i][0], &vozlisca[i][1]);
    }

    int visina = visinaDrevesa(0, vozlisca, n);
    printf("%d\n", visina);

    return 0;
}