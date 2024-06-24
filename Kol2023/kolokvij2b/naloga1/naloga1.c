#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...

int main(int argc, char** argv) {
    
    FILE* vhodna = fopen(argv[1], "r");
    FILE* izhodna = fopen(argv[2], "w");

    char* vrstica = malloc(100001*sizeof(char));
    while(fgets(vrstica, 100001, vhodna) != NULL){

        char trenutni = vrstica[0];
        int i = 0;
        while(trenutni != '\0' && trenutni == ' '){
            trenutni = vrstica[++i];
        }
        if(trenutni != '\0'){
            strcpy(vrstica, &vrstica[i]);
        }

        fprintf(izhodna, "%s", vrstica);
    }

    fclose(vhodna);
    fclose(izhodna);

    return 0;
}



                
