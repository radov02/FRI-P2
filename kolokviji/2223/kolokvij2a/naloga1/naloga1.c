#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ZNAKOV 100000

int main(int argc, char** argv){

    char* imeVhodne = argv[1];
    char* imeIzhodne = argv[2];

    FILE* vhodna = fopen(imeVhodne, "r");
    FILE* izhodna = fopen(imeIzhodne, "w");

    bool aktivno = false;
    char novi = '\0';
    while((novi = fgetc(vhodna)) > 0){

        if(aktivno && (novi == 'C' || novi == 'c' || novi == 'S' || novi == 's' || novi == 'Z' || novi == 'z')){
            fprintf(izhodna, "%c", novi);
            aktivno = false;
        }
        else if(novi == '"'){
            if(aktivno){
                fprintf(izhodna, "\"");
            }
            aktivno	= true;
            continue;
        }
        else if(aktivno){
            fprintf(izhodna, "\"%c", novi);
            aktivno = false;
        }
        else{
            fprintf(izhodna, "%c", novi);
        }
    }

    fclose(vhodna);
    fclose(izhodna);

    return 0;
}