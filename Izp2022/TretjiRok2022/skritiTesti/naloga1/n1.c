#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

    FILE* vhodna = fopen(argv[1], "r");
    int prag = atoi(argv[2]);
    FILE* izhodna = fopen(argv[3], "w");

    char* P5 = malloc(2*sizeof(char));
    int w, h, dpp;
    fscanf(vhodna, "%s %d %d %d", P5, &w, &h, &dpp);
    fgetc(vhodna);

    fprintf(izhodna, "%s\n%d %d\n%d\n", P5, w, h, dpp);

    unsigned char** slika = malloc(h*sizeof(unsigned char*));
    for(int i = 0; i < h; i++){
        slika[i] = malloc(w*sizeof(unsigned char));
        for(int j = 0; j < w; j++){
            fread(&slika[i][j], 1, 1, vhodna);

            if(slika[i][j] >= prag){
                slika[i][j] = 255;
            }
            else{
                slika[i][j] = 0;
            }

            fwrite(&slika[i][j], 1, 1, izhodna);
        }
    }

    fclose(vhodna);
    fclose(izhodna);

    return 0;
}