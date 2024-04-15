#include <stdio.h>

long vsotaPravihDeliteljev(long n){
    long vsota = 1;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            vsota += i;
            int desni = n/i;
            if(desni != i){
                vsota += n/i;
            }
        }
    }
    return vsota;
}

int main(){

    long n;
    scanf("%ld", &n);

    long moznoPrijateljsko = vsotaPravihDeliteljev(n);
    if(vsotaPravihDeliteljev(moznoPrijateljsko) == n){
        printf("%ld\n", moznoPrijateljsko);
    }
    else{
        printf("NIMA");
    }

    return 0;
}