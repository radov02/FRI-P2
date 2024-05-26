
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

Vozlisce* prepleti(Vozlisce** seznami, int n) {
    
    Vozlisce* novSeznam = malloc(sizeof(Vozlisce));
    Vozlisce* trenutnoVnovemSeznamu = NULL;
    int* zeOpravljeneVrstice = calloc(n, sizeof(int));

    int stNullov = 0, j = 0;
    while(stNullov < n){    // po j
        for(int i = 0; i < n; i++){
            if(zeOpravljeneVrstice[i] == 1){
                continue;
            }
            int tmpj = 0;
            Vozlisce* trenutno = seznami[i];
            while(tmpj != j && trenutno != NULL){
                trenutno = trenutno->naslednje;
                tmpj++;
            }
            if(zeOpravljeneVrstice[i] != 1 && trenutno == NULL){
                stNullov++;
                zeOpravljeneVrstice[i] = 1;
            }
            else{
                Vozlisce* novo = malloc(sizeof(Vozlisce));
                novo->podatek = trenutno->podatek;
                novo->naslednje = NULL;
                if(trenutnoVnovemSeznamu != NULL){
                    trenutnoVnovemSeznamu->naslednje = novo;
                }
                else{
                    novSeznam = novo;
                }
                trenutnoVnovemSeznamu = novo;
            }
        }
        j++;
    }

    free(zeOpravljeneVrstice);

    return novSeznam;
}

int main() {
    return 0;
}
