#include <stdio.h>

#define MINCHARVAL 32
#define MAXCHARVAL 126

int main(){

    int possibleChars = MAXCHARVAL - MINCHARVAL + 1;
    int charfreq[possibleChars];
    for(int i = 0; i < possibleChars; i++){
        charfreq[i] = 0;
    }
    int c = -1;

    while((c = getchar()) != EOF){
        charfreq[c - MINCHARVAL]++;
    }

    for(int i = 0; i < possibleChars; i++){
        printf("'%c': ", i + MINCHARVAL);
        for(int j = 0; j < charfreq[i]; j++){
            putchar('#');
        }
        putchar('\n');
    }

    return 0;
}