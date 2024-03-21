#include <stdio.h>
#include <stdbool.h>

bool jeStevkaAliPredznak(int c){
    return((c >= '0' && c <= '9') || c == '+' || c == '-' || c == ' ');
}

bool jePredznak(int c){
    if(jeStevkaAliPredznak(c))
        return (c == '+' || c == '-');
    return false;
}

int main() {

    int novZnak = ' ';
    bool jeDesetiskaKonstanta = true, naZacetku = true, zacetekZNiclo = false;
    int prejsnjiZnak = ' ';

    do{
        novZnak = getchar();

        if(!jeStevkaAliPredznak(novZnak) && novZnak != '\n'){
            jeDesetiskaKonstanta = false;
        }
        else if(!naZacetku && jePredznak(novZnak) && novZnak != '\n'){
            jeDesetiskaKonstanta = false;
        }
        if(novZnak == ' ' && jePredznak(prejsnjiZnak)){
            jeDesetiskaKonstanta = false;
        }
        if(zacetekZNiclo && novZnak == '0'){
            jeDesetiskaKonstanta = false;
        }
        else if(zacetekZNiclo && novZnak != ' '){
            jeDesetiskaKonstanta = false;
        }
        if((prejsnjiZnak == ' ' || jePredznak(prejsnjiZnak)) && novZnak == '0'){
            zacetekZNiclo = true;
        }        
        //printf("[%d %d %d], %c\n", zacetek, jeStevkaAliPredznak(novZnak), jePredznak(novZnak), novZnak);
        
        if(novZnak == ' ' || novZnak == '\n'){
            if(jeDesetiskaKonstanta) putchar('1');
            else putchar('0');
            if(novZnak == '\n'){
                break;
            }
            // putchar('\n');
            naZacetku = true;
            jeDesetiskaKonstanta = true;
            zacetekZNiclo = false;
        }
        else{
            naZacetku = false;
        }
        prejsnjiZnak = novZnak;

    } while(novZnak != '\n');

    putchar('\n');

    return 0;
}