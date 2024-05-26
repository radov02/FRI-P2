// 10/10 javni
// 50/50 skriti

#include <stdio.h>
#include <stdlib.h>

#include "naloga2.h"

int* kopirajTabelo(int* tabela){
  int i = 0;
  while(tabela[i] != 0){
    i++;
  }

  int* kopija = malloc((i+1) * sizeof(int));
  for(int j = 0; j < i+1; j++){
    kopija[j] = tabela[j];
  }
  return kopija;
}

void pretvori(int** t){
    int i = 0;

    while(t[i] != NULL){
      int j = i+1;
      while(t[j] != NULL){

        if(t[i] == t[j]){
          t[j] = kopirajTabelo(t[i]);
        }
        j++;
      }

      i++;
    }
}

int main() {

  return 0;
}
