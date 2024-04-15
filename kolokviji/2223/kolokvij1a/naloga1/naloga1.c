
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    
    int n = -1;
    scanf("%d", &n);

    int* zaporedje = (int*) calloc(n, sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &zaporedje[i]);
    }

    bool jePalindromsko = true;
    long vsota = 0l;

    for(int i = 0; i < n; i++){
        if(i == n/2 && jePalindromsko){
            vsota = 2 * vsota + zaporedje[i];
            break;
        }
        if(zaporedje[i] != zaporedje[n - 1 - i]){

            jePalindromsko = false;
        }
        vsota += zaporedje[i];
    }

    if(jePalindromsko){
        printf("DA\n%ld\n", vsota);
    }
    else {
        printf("NE\n%ld\n", vsota);
    }

    free(zaporedje);

    return 0;
}
