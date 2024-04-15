#include <stdio.h>
#include <math.h>

int main(){

    int n, k;
    scanf("%d, %d", &n, &k);

    for(int i = 0; i < (1 << n); i++){  // v i-ju je zapis števila

        for(int j = n-1; j >= 0; j--){     // z j-jem bomo ugotovili kje je 0 in 1 (za izpis)
            if(i & (1 << j)){
                printf("B");
            }
            else{
                printf("A");
            }
        }
        printf("\n");
    }

    return 0;
}