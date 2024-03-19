#include <stdio.h>
#include <stdbool.h>

#define N 1000000000

int frekvence[N+1];   // prevelika tabela za na sklad; ker je med static data se inicializira na 0

int main(){

    int n = getchar() - '0';
    bool jePermMnozice = true;

    for(int i = 0; i < n; i++){
        int novo = 0;
        scanf("%d", &novo);
        if(novo >= 0 && novo <= N){
            frekvence[novo]++;
        }
        else{
            jePermMnozice = false;
        }
        
        if(frekvence[i] > 1){
            jePermMnozice = false;
        }
    }

    for(int i = 0; i < n; i++){
        if(frekvence[i] == 0){
            jePermMnozice = false;
        }
    }

    if(!jePermMnozice){
        printf("NE");
    }
    else{
        printf("DA");
    }

    return 0;
}