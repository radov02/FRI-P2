#include <stdio.h>

#define IN 1
#define OUT 0

int main(){

    int c = -1;
    int stanjePrej = OUT;   // v ali izven besede
    int stanje = OUT;

    while((c = getchar()) != EOF){

        if(stanjePrej == IN && stanje == OUT){
            putchar('\n');
        }

        if(c != ' ' && c != '\n' && c != '\t'){
            stanje = IN;
        }
        else{
            stanje = OUT;
        }
        putchar(c);
        
        stanjePrej = stanje;
    }


    return 0;
}