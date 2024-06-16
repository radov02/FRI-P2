#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void izpis(int* sumandi, int len){
    for(int i = 1; i < len; i++){
        if(i < len-1) printf("%d+", sumandi[i]);
        else printf("%d\n", sumandi[i]);
    }
}

void izpisi(int* sumandi, int indeksSumandi, int trenutniSumand, int sumandov, int vsota, int n, int a, int b){

    if(sumandov > b) return;
    if(vsota == n && sumandov >= a){
        sumandi[indeksSumandi++] = trenutniSumand;
        izpis(sumandi, indeksSumandi);
        return;
    }

    sumandi[indeksSumandi++] = trenutniSumand;

    for(int i = trenutniSumand; i <= n-vsota; i++){     // lahko gremo samo do n-vsota
        if(vsota + i <= n && sumandov < b){
            izpisi(sumandi, indeksSumandi, i, sumandov+1, vsota+i, n, a, b);
        }
    }
}

int main(){

    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    int sumandi[b]; // hitreje od kopice

    izpisi(sumandi, 0, 1, 0, 0, n, a, b);

    return 0;
}