#include <stdio.h>
#include <limits.h>

int main(){

    int n = getchar() - '0';

    int najvecjaVsota = INT_MIN;
    int trenutnaVsota = 0;

    for(int i = 0; i < n; i++){
        int st;
        scanf("%d", &st);

        trenutnaVsota += st;

        if(trenutnaVsota > najvecjaVsota){
            najvecjaVsota = trenutnaVsota;
        }
        
        if(trenutnaVsota < 0){
            trenutnaVsota = 0;
        }
    }

    printf("%d\n", najvecjaVsota);

    return 0;
}