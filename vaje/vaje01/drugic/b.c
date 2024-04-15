#include <stdio.h>
#include <stdbool.h>

int main(){

    int n = getchar() - '0';

    bool enaka = true;
    int prejsnje = -1;
    for(int i = 0; i < n; i++){
        int novo = getchar() - '0';
        if(prejsnje != -1 && novo != prejsnje){
            enaka = false;
        }
        prejsnje = novo;
    }

    if(enaka) putchar('1');
    else putchar('0');

    return 0;
}