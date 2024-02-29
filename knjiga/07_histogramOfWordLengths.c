#include <stdio.h>

void printHistogramLine(int len){
    for(int i = 0; i < len; i++){
        putchar('#');
    }
    putchar('\n');
    return;
}

int main(){

    int c = -1;
    int length = 0;

    while((c = getchar()) != EOF){

        if(c == ' ' || c == '\t' || c == '\n'){
            printHistogramLine(length);
            length = 0;
        }
        else{
            length++;
        }
    }

    return 0;
}