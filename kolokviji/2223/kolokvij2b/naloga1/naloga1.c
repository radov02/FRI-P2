#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ZNAKOV 100000

int main(int argc, char** argv){

    char* imeVhodne = argv[1];
    char* imeIzhodne = argv[2];
    FILE* vhodna = fopen(imeVhodne, "r");
    FILE* izhodna = fopen(imeIzhodne, "w");

    bool prejsnjiPresledek = false;
    bool novaVrstica = true;
    char znak = '\0';
    while((znak = fgetc(vhodna)) >= 0){
        
        if(znak == '\n'){
            novaVrstica = true;
            fprintf(izhodna, "\n");
            continue;
        }
        if(novaVrstica && znak == ' '){
            prejsnjiPresledek = true;
            continue;
        }
        else{
            prejsnjiPresledek = false;
            fprintf(izhodna, "%c", znak);
        }

        novaVrstica = false;

        /* if(znak == ' '){
            if(!prejsnjiPresledek){
                fprintf(izhodna, " ");
            }
            prejsnjiPresledek = true;
        }
        else{
            prejsnjiPresledek = false;
            fprintf(izhodna, "%c", znak);
        } */
    }

    fclose(vhodna);
    fclose(izhodna);

    return 0;
}