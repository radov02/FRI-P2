#include <stdio.h>

void zamenjaj(int* prvo, int* drugo, int* zaporedje){

}

int nacinov(int kateroPodzaporedje, int* podzaporedje, int n, int stZamenjav, int r, int* zaporedje){
    if(stZamenjav == 0){
        return 0;
    }

    for(int i = 0; i < r; i++){
        
    }

    strncpy(podzaporedje, zaporedje, r);
    for(int i = kateroPodzaporedje+3; i <= n-3; i++){

    }
}

int main(){

    int n, k, r;
    scanf("%d %d %d", &n, &k, &r);

    int* zaporedje = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &zaporedje[i]);
    }

    int stNacinov = nacinov(n, k, r, zaporedje);

    printf("%d\n", stNacinov);

    free(zaporedje);

    return 0;
}