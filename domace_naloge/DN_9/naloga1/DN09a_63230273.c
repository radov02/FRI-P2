#include <stdio.h>

// vsota bo vecja ali enaka 16
int* razbitje[4];
int* vsoteRazbitij;

void razbitja(int i, int vKateroMnozico, int** razbitje1, int* trenutneVsoteRazbitij, int k, int* mnozica, int n){
    if(i == n){
        return;
    }

    trenutneVsoteRazbitij[vKateroMnozico] += mnozica[i];
    razbitje[vKateroMnozico][]

    razbitja(i+1, );
}

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    int* mnozica = calloc(n, sizeof(int));

    for(int i = 0; i < n; i++){
        scanf(&mnozica[i]);
    }

    razbitja(razbitje, vsoteRazbitij, k, mnozica, int n);   // k podmnozic z enako vsoto

    free(mnozica);

    return 0;
}