#include <stdio.h>
#include <stdlib.h>

void izpisiVsoto(int* cleni, int stClenov){
    for(int i = 0; i < stClenov; i++){
        if(i > 0){
            printf(" + ");
        }
        printf("%d", cleni[i]);
    }
    printf("\n");
}

void nacini(int vsota, int najSumand, int* cleni, int stClenov){
    
    // if(najSumand > vsota) najSumand = vsota; // lepša rešitev
    if(vsota == 0){
        izpisiVsoto(cleni, stClenov);
        return;
    }
    if(vsota < 0 || najSumand <= 0){
        return;
    }
    
    cleni[stClenov] = najSumand;
 
    // vsote ki vsebujejo največji sumand
    nacini(vsota-najSumand, najSumand, cleni, stClenov+1);
    // vsote pri katerih so sumandi manjši od najSumand
    nacini(vsota, najSumand-1, cleni, stClenov);
}

int main(){

    int n, k;
    
    scanf("%d %d", &n, &k);

    int *cleni = malloc(n * sizeof(int));

    nacini(n, k, cleni, 0);

    return 0;
}