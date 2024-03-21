#include <stdio.h>
#include <stdbool.h>

bool ustrezenDesetiskiChar(int c){
    return (c >= '0' && c <= '9');
}

bool ustrezenSestnajstiskiChar(int c){
    return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'));
}

bool ustrezenOsmiskiChar(int c){
    return ((c >= '0' && c <= '7'));
}

bool ustrezenDvojiskiChar(int c){
    return (c == '0' || c == '1');
}

int main(){

    int c;
    int prva, druga;

    do{
        prva = -1, druga = -1;
        bool jeCelostKonst = true, osmiski = false, hex = false, binarni = false, samoEna = true, samoDve = true;

        while((c = getchar()) != '\n' && c != ' ' && c != EOF){
            if(prva == -1){
                prva = c;
                continue;
            }
            else if(druga == -1){
                samoEna = false;
                druga = c;
                continue;
            }
            samoDve = false;
                
            if(jeCelostKonst){
                if(prva == '0' && druga == 'x'){
                    hex = true;
                }
                else if(prva == '0' && druga == 'b'){
                    binarni = true;
                }
                else if(prva == '0'){
                    osmiski = true;
                }
                else if(!ustrezenDesetiskiChar(prva)){
                    jeCelostKonst = false;
                    continue;
                }
                
                if(hex && !ustrezenSestnajstiskiChar(c)){
                    jeCelostKonst = false;
                }
                else if(binarni && !ustrezenDvojiskiChar(c)){
                    jeCelostKonst = false;
                }
                else if(osmiski && (!ustrezenOsmiskiChar(c) || !ustrezenOsmiskiChar(druga))){
                    jeCelostKonst = false;
                }
                else if(!hex && !binarni && !osmiski && (!ustrezenDesetiskiChar(c) || !ustrezenDesetiskiChar(prva) || !ustrezenDesetiskiChar(druga))){
                    jeCelostKonst = false;
                }
            }
        }

        if(samoEna && !ustrezenSestnajstiskiChar(prva)){
            jeCelostKonst = false;
        }
        else if(!samoEna && samoDve && (!ustrezenSestnajstiskiChar(prva) || !ustrezenSestnajstiskiChar(druga))){
            jeCelostKonst = false;
        }
 
        if(jeCelostKonst){
            putchar('1');
        }
        else{
            putchar('0');
        }

    } while(c != '\n');

    return 0;
}