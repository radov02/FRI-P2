#include <stdio.h>

int main(){

    int n = getchar() - '0';

    int prvo = -1, drugo = -1;

    for(int i = 0; i < n; i++){
        getchar();
        int novo = getchar() - '0';
        

        if(novo > prvo) {
            drugo = prvo;
            prvo = novo;
        }
        else if(novo > drugo) drugo = novo;
    }

    putchar(drugo + '0');

    return 0;
}