
/*

Prevajanje in poganjanje:

gcc -o test01 test01.c inverz.c -lm
./test01

*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "inverz.h"

long vrniPolovicoIntervala(long a, long b){
    return (long)round((a + b) / 2.0);
}

long inverz(long y, long a, long b) {
    long x;

    do{
        x = vrniPolovicoIntervala(a, b);

        if(f(x) > y){
            b = x;
        }
        else{
            a = x;
        }

    } while(f(a) != y && f(b) != y);

    if(f(a) == y) return a;
    if(f(b) == y) return b;
    
    return -1;

   /*  50000000000000000
    49999999999999999 */
}

// Ta datoteka NE SME vsebovati funkcij main in f!
// Funkciji main in f sta definirani v datoteki test01.c.




























