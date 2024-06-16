
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga2
 * make test
 *
 * Testni primeri:
 * 02--06: a = 1, b = n
 * 01, 07--10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 15

void izpis(char* niz, int len, int* mejeRazbitij, int indeks){

    for(int i = 0; i < len; i++){
        printf("%c", niz[i]);
        if(i < len-1){
            for(int j = 0; j < indeks; j++){    // za|nk|a ... meje razbitij sta a in k (1 in 3)
                if(i == mejeRazbitij[j]){
                    printf("|");
                    break;
                }
            }
        }
    }
    printf("\n");
}

void izpisRazbitij(int trenutniZacetek, int* mejeRazbitij, int indeks, char* niz, int stRazbitij, int dolzinaNiza, int a, int b){

    if(stRazbitij >= a){
        mejeRazbitij[indeks++] = trenutniZacetek;
        izpis(niz, dolzinaNiza, mejeRazbitij, indeks);
        return;
    }

    mejeRazbitij[indeks++] = trenutniZacetek;   // za njim izpisujemo |

    for(int i = trenutniZacetek+1; i < dolzinaNiza; i++){
        if(stRazbitij + 1 <= b){
            izpisRazbitij(i, mejeRazbitij, indeks, niz, stRazbitij+1, dolzinaNiza, a, b);
        }
    }
}

int main() {

    char* niz = malloc(MAX_N * sizeof(char));
    for(int i = 0; i < MAX_N; i++){
        scanf("%c", &niz[i]);
        if(niz[i] == ' '){
            niz[i] = '\0';
            break;
        }
    }
    int a, b;
    scanf("%d %d", &a, &b);

    int* mejeRazbitij = malloc((b-1)*sizeof(int));
    int dolzinaNiza = strlen(niz);

    for(int j = 0; j < dolzinaNiza-(a-1); j++){
        izpisRazbitij(j, mejeRazbitij, 0, niz, 1, dolzinaNiza, a, b);
    }

    return 0;
}
