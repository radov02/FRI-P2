#include <stdio.h>
#include <stdbool.h>

int steviloStevk(int absolutnaVrednostStevila){
    if(absolutnaVrednostStevila <= 0) return 0;

    return steviloStevk(absolutnaVrednostStevila / 10) + 1;
}

void izpisi(int vsota){

    bool negativno = vsota < 0 ? true : false;
    int vsotaAbs = negativno ? -vsota : vsota;
    int stevk = steviloStevk(vsotaAbs);
    int potencaDesetke = 1;
    int stevkaLeva = -1;

    // printf("stevk: %d\n", stevk);

    for(int i = 0; i < stevk - 1; i++){
        potencaDesetke = potencaDesetke * 10;
    }

    if(negativno) putchar('-');

    while(potencaDesetke > 0){
        stevkaLeva = vsotaAbs / potencaDesetke;
        //printf("stevkaLeva: %d\n", stevkaLeva);
        putchar('0' + stevkaLeva);

        vsotaAbs = vsotaAbs - potencaDesetke * stevkaLeva;
        potencaDesetke = potencaDesetke / 10;
    }
}

int preberiStevilo(void){
    int c = -1;
    bool negative = false;
    int stevilo = 0;

    while((c = getchar()) != ' ' && c != EOF && c != '\n'){
        //printf("c: %d\n", (c-'0'));
        if(c == '-'){
            negative = true;
        }
        else{
            if(stevilo == 0){
                stevilo = c - '0';
            }
            else{
                stevilo = stevilo * 10;
                stevilo = stevilo + (c - '0');
            }
        }
    }

    return (negative ? -stevilo : stevilo);
}

int main(){

    int a = preberiStevilo();
    int b = preberiStevilo();

    //printf("a: %d in b: %d\n", a, b);

    long vsota = a + b;
    //printf("vsota: %ld\n", vsota);

    izpisi(vsota);

    return 0;
}