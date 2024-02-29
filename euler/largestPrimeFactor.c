#include <stdio.h>

int main(){

    long int num = 600851475143l;

    for(int i = 2; i*i <= num; i++){
        if(num % i == 0){   // ce je stevilo deljivo, ga delimo z njim in postavimo nazaj (recimo večkratno deljenje z 2) - s prafaktorji
            num /= i;
            i--;
        }
    }

    if(num >= 2){
        printf("%ld\n", num);
    }

    return 0;
}

