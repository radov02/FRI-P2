#include <stdio.h>
#include <stdbool.h>

int stevk(int stevilo){
    if(stevilo <= 0) return 0;

    return stevk(stevilo / 10) + 1;
}

void izpisi(int potencaDvojke, bool vecKot){

    if(potencaDvojke < 10){
        if(vecKot && potencaDvojke < 9){
            putchar('0' + (potencaDvojke+1));
            return;
        }
        else if(!vecKot){
            putchar('0' + potencaDvojke);
            return;
        }
    }

    if(vecKot){
        potencaDvojke++;
    }

    int stevke = stevk(potencaDvojke);
    int potencaDesetke = 1;

    for(int i = 0; i < stevke-1; i++){
        potencaDesetke = potencaDesetke * 10;
    }

    while(potencaDvojke > 0){
        int levaStevka = potencaDvojke / potencaDesetke;
        putchar('0' + levaStevka);
	
       	potencaDvojke = potencaDvojke - potencaDesetke * levaStevka;
        potencaDesetke = potencaDesetke / 10;
    }
}

int main(){

    int c = -1;
    int potencaDvojke = 0;
    bool vecKot = false;

    while((c = getchar()) != '\n' && (c  != ' ')){
        if(c == '1'){
            break;
        }
    }

    if(c == '1'){
        while((c = getchar()) != '\n' && (c  != ' ') && (c != EOF)){
            potencaDvojke++;
            if(c == '1'){
                vecKot = true;
            }
        }
    }

    //printf("%d, %d\n", potencaDvojke, vecKot);

    izpisi(potencaDvojke, vecKot);
    putchar('\n');

    return 0;
}
