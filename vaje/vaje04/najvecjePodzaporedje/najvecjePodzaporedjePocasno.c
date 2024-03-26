#include <stdio.h>
#include <limits.h>

#define MAKS_DOLZINA 1000000

int zaporedje[MAKS_DOLZINA];

int main(){     // NE dela

    int n;
    scanf("%d", &n);

    int maxVsota = INT_MIN;     // najmanjši int

    for(int i = 0; i < n; i++){
        scanf("%d", &zaporedje[i]);
        int vsota = 0;

        for(int j = i; j < n; j++){
            vsota += zaporedje[j];


            if(vsota > maxVsota){
                maxVsota = vsota;
            }
        }
    }

    printf("%d\n", maxVsota);

    return 0;
}