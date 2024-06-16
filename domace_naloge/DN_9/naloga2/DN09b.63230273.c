#include <stdio.h>

void izpisiVseStavke(char* poved, int i, char*** samostalniki, int s, char** glagoli, int g, int m){
    if(m == 0){
        return;
    }

    if(i == 0){
        poved += *samostalniki[i][0];
    } 
    else{
        poved += *samostalniki[i][1];
    }
    for(int j = 0; j < g; j++){
        poved += *glagoli[j];
        for(int k = i+1; k < s; k++){
            izpisiVseStavke(poved, m+1);
        }
    }
}

int main(){

    int s;
    scanf("%d", s);
    char*** samostalniki = calloc(s, sizeof(char**));
    for(int i = 0; i < s; i++){
        samostalniki[i] = calloc(2, sizeof(char*));
        scanf("%s %s", &samostalniki[i][0], &samostalniki[i][1]);
    }

    int g;
    scanf("%d", &g);
    char** glagoli = calloc(g, sizeof(char*));
    for(int i = 0; i < g; i++){
        scanf("%s", &glagoli[i]);
    }

    int m;
    scanf("%d", &m);

    izpisiVseStavke("", 0, samostalniki, s, glagoli, g, m);

    return 0;
}