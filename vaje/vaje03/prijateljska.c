#include <stdio.h>

int vsotaPravihDeliteljev(int stevilo){
    int vsota = 0;

    for(int i = 1; i*i <= stevilo; i++) {
        if(stevilo % i == 0){
            vsota += i;
            int desno = stevilo / i;
            if(desno != i) {
                vsota += desno;
            }
        }
    }

    // do korena in pomnozi...
    // time echo 10000000000000 | ./a.out

    return vsota;
}

int main(){

    int stevilo = 0;

    scanf("%d", &stevilo);

    int vsotaDel = vsotaPravihDeliteljev(stevilo);

    if(vsotaPravihDeliteljev(vsotaDel) == stevilo){
        printf("%d\n", vsotaDel);
    }
    else{
        printf("NIMA\n");
    }


    return 0;
}