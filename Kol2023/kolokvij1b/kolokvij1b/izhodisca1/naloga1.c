
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// po potrebi dopolnite ...

int main() {
    
    int n;
    scanf("%d", &n);
    int* koordinate1 = malloc(n*sizeof(int));
    int* koordinate2 = malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &koordinate1[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &koordinate2[i]);
    }

    int razdalja = 0;
    for(int i = 0; i < n; i++){
        razdalja += (koordinate1[i] - koordinate2[i])*(koordinate1[i] - koordinate2[i]);
    }

    printf("%d\n", razdalja);

    return 0;
}
