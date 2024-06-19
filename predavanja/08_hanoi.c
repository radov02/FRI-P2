#include <stdio.h>
#include <stdlib.h>

int potez = 0;

void hanoi(int obroc, char zac, char vmes, char kon){

    if(obroc == 1){     // zgornji obroč
        potez++;
        printf("%c -> %c\n", zac, kon);
        return;
    }

    hanoi(obroc-1, zac, kon, vmes);     // nastavljanje premikov
    hanoi(1, zac, vmes, kon);   // dejanski premik obroča
    hanoi(obroc-1, vmes, zac, kon);     // premik odmaknjenih nazaj
}

int main(){

    int stObrocev;
    scanf("%d", &stObrocev);
    
    hanoi(stObrocev, 'A', 'B', 'C');

    printf("Potez (optimalno) = %d\n", potez);

    return 0;
}