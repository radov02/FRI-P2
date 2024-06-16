
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// po potrebi dopolnite ...


int main() {

    int n;
    scanf("%d", &n);
    bool palindromsko = true;
    int vsota = 0;
    int* stevke = malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &stevke[i]);
    }

    for(int i = 0; i < n/2; i++){
        if(stevke[i] != stevke[n-i-1]){
            palindromsko = false;
        }
        vsota += 2*stevke[i];
    }
    if(palindromsko && n % 2 != 0)
        vsota += stevke[n/2];

    if(palindromsko){
        printf("DA\n");
    }
    else{
        vsota = vsota / 2;
        for(int j = n/2; j < n; j++){
            vsota += stevke[j];
        }
        printf("NE\n");
    }
    printf("%d\n", vsota);

    return 0;
}
