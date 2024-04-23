#include <stdio.h>
#include <stdbool.h>

/*  NI OK, KER DELA SAMO ZA NIZE DOLŽINE 2
void izpisi(int n, int c1, int c2, int zacetna, int koncna, bool enaCrka){

    if(c1 == c2 && c2 == koncna){
        return;
    }

    if(c1 == koncna+1){
        return;
    }

    if(enaCrka){
        printf("%c\n", c1);
    }
    printf("%c%c\n", c1, c2);
    
    enaCrka = false;

    if(c2 != koncna){
        izpisi(n, c1, c2+1, zacetna, koncna, false);
    }
    else {
        izpisi(n, c1+1, zacetna, zacetna, koncna, true);
    }
}*/

void izpisi(char* niz, int ix, int n, char zacetni, char koncni){

    if(ix <= n){

        if(ix > 0){
            niz[ix] = '\0';
            printf("%s\n", niz);
        }

        for(char znak = zacetni; znak <= koncni; znak++){
            niz[ix] = znak;
            izpisi(niz, ix+1, n, zacetni, koncni);
        }
    }
}

int main(){

    int n;
    char c1, c2;
    scanf("%d %c %c", &n, &c1, &c2);

    //izpisi(n, c1, c1, c1, c2, true);

    char* niz = malloc((n+1)*sizeof(char));
    izpisi(niz, 0, n, c1, c2);

    return 0;
}