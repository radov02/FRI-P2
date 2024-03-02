#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);

main(){
    int currentLineLength;
    int maxLineLength;
    char line[MAXLINE];
    char longest[MAXLINE];

    maxLineLength = 0;
    while((currentLineLength = getline(line, MAXLINE)) > 0){
        if(currentLineLength > maxLineLength){
            maxLineLength = currentLineLength;
            copy(longest, line);
        }
    }

    if(maxLineLength > 0){
        printf("%s", longest);
    }

    return 0;
}

int getline(char s[], int lim){
    int c, i;

    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++){
        s[i] = c;
    }

    if(c == '\n'){
        s[i] = c;
        i++;
    }
    s[i] = '\0';    // na koncu dodamo null character
    
    return i;
}

void copy(char to[], char from[]){
    int i = 0;

    while((to[i] = from[i]) != '\0'){
        i++;
    }
}