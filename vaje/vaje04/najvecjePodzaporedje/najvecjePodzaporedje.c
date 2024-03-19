#include <stdio.h>
#include <limits.h>

int main(){

    int n = 0;
    scanf("%d", &n);

    int trenutnaVsota = 0;
    int najvecjaVsota = INT_MIN;    // najmanjsi int

    for(int i = 0; i < n; i++){
        int stevilo = -1;
        scanf("%d", &stevilo);
        
        trenutnaVsota += stevilo;
    
        if(trenutnaVsota > najvecjaVsota){
            najvecjaVsota = trenutnaVsota;
        }

        if(trenutnaVsota < 0){
            trenutnaVsota = 0;
        }
    }

    printf("%d", najvecjaVsota);

    return 0;
}