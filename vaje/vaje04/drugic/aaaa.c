#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){

    int n = getchar() - '0';
    getchar();
    int* pojavitve = calloc(n+1, sizeof(int));
    bool perm = true;

    for(int i = 0; i < n; i++){
        int stevilo = getchar() - '0';
        //printf("%d\n", pojavitve[stevilo]);
        getchar();

        if(pojavitve[stevilo] > 0){
            perm = false;
        }
        pojavitve[stevilo]++;
    }

    for(int i = 0; i < n; i++){
        if(pojavitve[i] < 1){
            perm = false;
        }
        printf("%d ", pojavitve[i]);
    }
    printf("\n");

    if(perm){
        printf("DA\n");
    }
    else{
        printf("NE\n");
    }

    return 0;
}