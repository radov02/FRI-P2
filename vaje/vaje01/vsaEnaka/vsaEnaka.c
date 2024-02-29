#include <stdio.h>
#include <stdbool.h>

int main(){

    int n = getchar() - '0';
    getchar();

    bool vsaEnaka = true;
    int prejsnje = -1;  // vedno inicializirajmo, sicer dobi neko nakjlučno vrednost ki je na tistem delu pomnilnika

    for(int i = 0; i < n; i++){
        int stevilo = getchar() - '0';
        getchar();

        if(i == 0){
            prejsnje = stevilo;
        }
        else if(prejsnje != stevilo){
            vsaEnaka = false;
        }
    }

    putchar(vsaEnaka ? '1':'0');
    putchar('\n');

    return 0;
}