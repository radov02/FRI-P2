#include <stdio.h>
#include <stdbool.h>

void izpisi(bool jeDesetiskaKonstanta){
    if(jeDesetiskaKonstanta){
        putchar(1);
    }
    else{
        putchar(0);
    }
}

int main() {

    int c = -1;
    
    bool novNiz = true;
    
    while((c = getchar()) != '\n'){
        int predhodniZnak = ' ';
        bool desetiskaKonst = false;

        while(c != ' '){
            c = getchar();
            predhodniZnak = c;
            if(c == '\n') break;

            if(predhodniZnak != ' ' && (c < '0' && c > '9' || c == '+' && predhodniZnak < '0' && predhodniZnak > '9' || c == '-' && predhodniZnak < '0' && predhodniZnak > '9')){
                desetiskaKonst = false;
            }
            else if(predhodniZnak == ' ' && !(c == '+' || c == '-' || (c <= '9' && c > '0'))){
                desetiskaKonst = false;
            }
        }

        if(predhodniZnak == ' ' && c == '0'){
            izpisi(true);
        }
        else{
            izpisi(desetiskaKonst);
        }
    }


    return 0;
}