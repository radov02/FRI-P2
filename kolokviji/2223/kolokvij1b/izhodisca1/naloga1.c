
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// po potrebi dopolnite ...

int main() {
    
    int n;
    scanf("%d", &n);

    int* prva = calloc(n, sizeof(int));
    int* druga = calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &prva[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &druga[i]);
    }

    int vsota = 0;
    for(int i = 0; i < n; i++){
        vsota += (prva[i] - druga[i]) * (prva[i] - druga[i]);
    }

    printf("%d\n", vsota);

    return 0;
}
