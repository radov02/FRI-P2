#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(){

    int a, b;
    scanf("%d %d", &a, &b);

    int odziv;
    bool protislovje = false;

    while((odziv = getchar() - '0') != 0){

        int sredina = floor((b - a) / 2 + a);

        if(odziv == 1){
            a = sredina+1;
        }
        else if(odziv == -1){
            b = sredina-1;
        }
        else{
            break;
        }

        if(a > b) protislovje = true;
    }

    if(a == b){
        printf("%d\n", a);
    }
    else if(protislovje){
        printf("PROTISLOVJE");
    }
    else{
        printf("%d %d\n", a, b);
    }

    return 0;
}