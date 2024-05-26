
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ZNAKOV 10000

int main(int argc, char** argv) {
    
    char* imeVhodna = argv[1];
    int n = atoi(argv[2]);
    int k = atoi(argv[3]);

    FILE* vhodna = fopen(imeVhodna, "r");
    char* buffer = malloc(MAX_ZNAKOV * sizeof(char));
    int i = 1;
    while(i < n){
        fgets(buffer, MAX_ZNAKOV, vhodna);
        i++;
    }
    
    fgets(buffer, MAX_ZNAKOV, vhodna);
    
    int beseda = 1, j = 1;
    char znak = buffer[0];
    while(beseda != k){
        znak = buffer[j++];
        if(znak == ' '){
            beseda++;
        }
    }
    if(beseda != 1)
        znak = buffer[j++];

    while(znak != ' ' && znak != '\n'){
        printf("%c", znak);
        znak = buffer[j++];
    }

    free(buffer);
    fclose(vhodna);

    return 0;
}
