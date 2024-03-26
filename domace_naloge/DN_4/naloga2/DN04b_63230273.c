#include <stdio.h>
#include <math.h>

long zaporedje[5 * 1000000];

long pridobiSteviloParov(long stevecParov, int n, int k){
    
    long predhodniParov = 0L;

    for(int i = 0; i < n; i++){
        long parov = 0L;
        for(int j = n-1; j > i; j--){
            if(j == i){
                return stevecParov;
            }
            if(zaporedje[i] + zaporedje[j] < k){
                break;
            }
            if(zaporedje[i] == zaporedje[i-1]){
                if(zaporedje[i] + zaporedje[i-1] == k){
                    predhodniParov--;
                }
                stevecParov += predhodniParov;
                parov = predhodniParov;
                break;
            }
            else if(zaporedje[i] + zaporedje[j] == k){
                parov++;
                stevecParov++;
                
            }
        }
        predhodniParov = parov;
        
        if(zaporedje[i] > (int)ceil(zaporedje[n-1] / 2.0)){
            i = n;
        }
    }
    return stevecParov;
}

int main(){

    int n = 0, k = 0;
    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++){
        scanf("%ld", &zaporedje[i]);
    }

    long stevecParov = pridobiSteviloParov(0L, n, k);

    printf("%ld\n", stevecParov);

    return 0;
}