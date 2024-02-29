#include <stdio.h>

int main(){

    int c, blanks = 0, tabs = 0, newlines = 0;
    while((c = getchar()) != EOF){
        if(c == ' '){
            blanks++;
        }
        else if(c == '\t'){
            tabs++;
        }
        else if(c == '\n'){
            newlines++;
        }
    }

    printf("%d, %d, %d", blanks, tabs, newlines);

    return 0;
}