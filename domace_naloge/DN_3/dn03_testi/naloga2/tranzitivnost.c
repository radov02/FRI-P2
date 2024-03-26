
/*

Prevajanje in poganjanje:

gcc -o test01 test01.c tranzitivnost.c -lm
./test01

*/

#include <stdio.h>
#include <stdbool.h>

#include "tranzitivnost.h"

bool tranzitivna(int x, int y, int z){
    //printf("tran: %d, %d, %d; %d, %d, %d\n", f(x, y), f(y, z), f(x, z), x, y, z);
    if(f(x, y) && f(y, z)){
        return f(x, z);
    }
    return true;
}

bool antitranzitivna(int x, int y, int z){
    if(f(x, y) && f(y, z)){
        return !f(x, z);
    }
    return true;
}

bool netranzitivna(int x, int y, int z){
    return (f(x, y) && f(y, z) && !f(x, z));
}

int tranzitivnost(int a, int b) {

    bool tranzitivnaf = true, antitranzitivnaf = true, netranzitivnaf = false;

    for(int x = a; x <= b; x++){
        for(int y = a; y <= b; y++){
            for(int z = a; z <= b; z++){

                //printf("tr, atr, netr: %d, %d, %d\n", tranzitivna(x, y, z), antitranzitivna(x, y, z), netranzitivna(x, y, z));

                if(tranzitivnaf && !(tranzitivna(x, y, z))){
                    //printf("prviif: %d, %d, %d; %d, %d, %d\n", f(x, y), f(y, z), f(x, z), x, y, z);
                    tranzitivnaf = false;
                }
                if(antitranzitivnaf && !(antitranzitivna(x, y, z))){
                    //printf("drugiif: %d, %d, %d; %d, %d, %d\n", f(x, y), f(y, z), f(x, z), x, y, z);
                    antitranzitivnaf = false;
                }
                if(!netranzitivnaf && netranzitivna(x, y, z)){
                    //printf("tretjiif: %d, %d, %d; %d, %d, %d\n", f(x, y), f(y, z), f(x, z), x, y, z);
                    netranzitivnaf = true;
                }

                if(!tranzitivnaf && !antitranzitivnaf && netranzitivnaf){
                    break;
                }
            }
        }
    }

    if(tranzitivnaf && antitranzitivnaf){
        return 1;
    }
    else if(tranzitivnaf){
        return 2;
    }
    else if(antitranzitivnaf){
        return 3;
    }
    else if(netranzitivnaf){
        return 4;
    }

    return -1;
}

// Ta datoteka NE SME vsebovati funkcij main in f!
// Funkciji main in f sta definirani v datoteki test01.c.
