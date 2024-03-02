#include <stdio.h>

#define BUFFER 10

// NE DELUJE

// int getline(char line[], int maxline);
void copy(char to[], char from[]);
void printArray(char line[], int length);

int main(){
    char line[BUFFER];
    int c, counter = 0;

    while(counter < BUFFER && (c = getchar()) != EOF && c != '\n'){

        line[counter] = c;

        if(counter = BUFFER-1){
            printArray(line, counter);
            counter = 0;
        }

        counter++;
    }

    printArray(line, counter);

    return 0;
}

/* int getline(char s[], int lim){
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
} */

void copy(char to[], char from[]){
    int i = 0;

    while((to[i] = from[i]) != '\0'){
        i++;
    }
}

void printArray(char line[], int length){

    for(int i = 0; i < length; i++){
        putchar(line[i]);
    }
}