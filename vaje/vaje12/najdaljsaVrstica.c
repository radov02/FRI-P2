#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define N 1000000

int main(int argc, char** argv){

    /* int n = 1;
    FILE* datotekaZaBranje = fopen("ime.txt", "rt");
    fscanf(datotekaZaBranje, "%d", &n);
    fclose(datotekaZaBranje);
    FILE* datotekaZaPisanje = fopen("ime.txt", "wt");
    fprintf(datotekaZaPisanje, "%d", n);
    fclose(datotekaZaPisanje); */

    // fgets()
    // getline()
    //printf("%s", argv[0]);  // izpis imena datoteke ki jo izvajamo (./a.out)
    FILE* vhodna = fopen(argv[1],"rt");
    FILE* izhodna = fopen(argv[2], "wt");

    int najDolzina = 0;
    char* vrstica = calloc(N+1, sizeof(char));
    char* najdaljsa = calloc(N+1, sizeof(char));

    while(fgets(vrstica, N+1, vhodna) != NULL){ // FILE* hrani kje smo ostali z branjem - stream
        int dolzina = strlen(vrstica);
        if(dolzina > najDolzina){
            //najdaljsa = vrstica;    // NE MOREMO!
            strcpy(najdaljsa, vrstica);
            najDolzina = dolzina;
        }
    }

    fprintf(izhodna, "%s", najdaljsa);

    free(vrstica);
    fclose(vhodna);
    fclose(izhodna);

    return 0;
}