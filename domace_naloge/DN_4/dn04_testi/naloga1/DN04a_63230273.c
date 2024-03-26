#include <stdio.h>
#include <stdbool.h>

int main(){

    int n = 0;
    scanf("%d", &n);

    int prvo[n];
    int drugo[n];

    for(int j = 0; j < n; j++){
        scanf("%d", &prvo[j]);
    }
    for(int j = 0; j < n; j++){
        scanf("%d", &drugo[j]);
    }

    int k = 0;
    int j = 0;
    for(; j < n; j++){     // po spodnji vrstici
        bool zacetek_a0 = true;
        int tmpj = j;
        for(int i = 0; i < n; i++){     // po zgornji vrstici
            //printf("primerjam: %d %d na %d %d\n", prvo[i], drugo[tmpj], i, tmpj);
            if(prvo[i] != drugo[tmpj++]){
                zacetek_a0 = false;
                break;
            }
            if(tmpj >= n) break;
        }
        
        if(zacetek_a0){
            //printf("zacetek_a0, n = %d, j = %d, k = %d\n", n, j, k);
            if(k == 0 || (n - j < k && n - j > 0)){
                bool ak_do_anm1 = true;
                for(int ii = n-j; ii < n; ii++){
                    if(prvo[ii] != drugo[ii - (n-j)]){
                        ak_do_anm1 = false;
                    }
                }
                //printf("k = %d - %d\n", n, j);
                if(ak_do_anm1) k = n - j;
            }
        }
    }
    // printf("j: %d\n", j);
    if(j == 1) printf("%d\n", 0);
    else printf("%d\n", k);

    return 0;
}