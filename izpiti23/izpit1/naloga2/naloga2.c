#include <stdio.h>
#include <stdlib.h>

void izpis(int* cleni, int indeks){
    for(int i = 0; i < indeks; i++){
        if(i < indeks-1){
            printf("%d+", cleni[i]);
        }
        else{
            printf("%d\n", cleni[i]);
        }
    }
}

void izpisi(int* cleni, int indeksCleni, int trenutnaVsota, int clen, int globina, int n, int a, int b){

    if(trenutnaVsota > n || globina > b){
        return;
    }
    if(trenutnaVsota == n){
        if(globina >= a){
            cleni[indeksCleni++] = clen;
            izpis(cleni, indeksCleni);
        }
        return;
    }

    if(clen != -1){
        cleni[indeksCleni] = clen;
    }
    else{
        clen = 1;
    }
    
    for(int i = clen; i <= n; i++){
        if((trenutnaVsota + i <= n && globina <= b)){
            izpisi(cleni, indeksCleni+1, trenutnaVsota + i, i, globina+1, n, a, b);
        }
    }

}

int main(){

    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    int* cleni = calloc(b, sizeof(int));
    izpisi(cleni, -1, 0, -1, 0, n, a, b);

    free(cleni);
    return 0;
}