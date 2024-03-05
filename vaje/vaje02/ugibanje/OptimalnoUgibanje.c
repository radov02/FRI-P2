#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(){

    int a = 0;
    int b = 0;

    scanf("%d%d", &a, &b);
    int vhod = 2;
    bool protislovje = false;

    while(vhod != 0){
        printf("Vnos:");
        scanf("%d", &vhod);

        int povp = round(a+b) / 2.0;

        printf("povp: %d, vhod: %d, a: %d, b: %d\n", povp, vhod, a, b);

        if(vhod == 1){
            a = povp+1;
        }
        else if(vhod == -1){
            b = povp-1;
        }
        else {
            break;
        }

        if(a > b) protislovje = true;
    }

    if(a == b){
        printf("%d\n", a);
    }
    else if(protislovje){
        printf("PROTISLOVJE\n");
    }
    else{
        printf("%d %d\n", a, b);
    }

    return 0;
}