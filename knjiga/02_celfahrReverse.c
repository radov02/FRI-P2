#include <stdio.h>

#define BEGINNING 300
#define END 0

int main(){

    for(int fahr = BEGINNING; fahr >= END; fahr-=10){
        printf("%3d F\t%6.1f C\n", fahr, 5.0/9 * (fahr-32));
    }
    return 0;
}