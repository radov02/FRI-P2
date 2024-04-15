
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    
    int v, s;
    scanf("%d %d", &v, &s);

    long** matrika = calloc(v, sizeof(long*));
    int k = 0;  // stevilo nenicelnih elementov

    for(int i = 0; i < v; i++){ // po v vrsticah
        matrika[i] = calloc(s, sizeof(long));
        for(int j = 0; j < s; j++){ // po s stolpch
            scanf("%ld", &matrika[i][j]);
            if(matrika[i][j] != 0){
                k++;
            }
        }
    }

    long* A = calloc(k, sizeof(long));
    long* B = calloc(v+1, sizeof(long));
    int kumulativnaVsotaZaB = 0;
    B[0] = 0;
    long* C = calloc(k, sizeof(long));
    int iA = 0, iB = 1, iC = 0;

    for(int i = 0; i < v; i++){
        int nenicelnihVvrstici = 0;
        for(int j = 0; j < s; j++){
            if(matrika[i][j] != 0){
                nenicelnihVvrstici++;
                A[iA++] = matrika[i][j];
                C[iC++] = j;
            }
        }
        kumulativnaVsotaZaB += nenicelnihVvrstici;
        B[iB++] = kumulativnaVsotaZaB;
    }

    // izpis za A
    for(int i = 0; i < k; i++){
        printf("%ld", A[i]);
        if(i < k-1){
            printf("_");
        }
    }
    printf("\n");

    // izpis za B
    for(int i = 0; i < v+1; i++){
        printf("%ld", B[i]);
        if(i < v){
            printf("_");
        }
    }
    printf("\n");

    // izpis za C
    for(int i = 0; i < k; i++){
        printf("%ld", C[i]);
        if(i < k-1){
            printf("_");
        }
    }
    printf("\n");

    return 0;
}
