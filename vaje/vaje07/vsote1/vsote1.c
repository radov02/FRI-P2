#include <stdio.h>
#include <stdbool.h>

// slika...
void printnivo(int n){
    for(int i = 0; i < n; i++){
        printf("   ");
    }
}

// TIPI in ČASOVNE OMEJITVE
long MEMO[401][401];
bool SMO_ZE[401][401];

long stNacinov(int vsota, int najSumand, int nivo){

    if(vsota == 0){
        return 1;
    }
    if(vsota < 0 || najSumand <= 0){
        return 0;
    }

    if(SMO_ZE[vsota][najSumand]){
        return MEMO[vsota][najSumand];
    }

    printf("nacini(%ld, %ld)\n", vsota - najSumand, najSumand);
    long prvi = stNacinov(vsota - najSumand, najSumand, nivo+1);
    printf("nacin(%ld, %ld)\n", vsota, najSumand-1);
    long drugi = stNacinov(vsota, najSumand-1, nivo+1);

    MEMO[vsota][najSumand] = prvi + drugi;
    SMO_ZE[vsota][najSumand] = true;

    return prvi + drugi;
}

int main(){
    int n, k;

    scanf("%d %d", &n, &k);

    long rezultat = stNacinov(n, k, 0);
    printf("%ld\n", rezultat);

    return 0;
}