// 10/10 javni
// 50/50 skriti

#include <stdio.h>
#include <stdlib.h>

int main() {

  int n;
  scanf("%d", &n);
  int* stevila = malloc(n * sizeof(int));
  int vsota = 0;
  double povprecje = 0.0;
  int d = n;

  for(int i = 0; i < n; i++){
    scanf("%d", &stevila[i]);
    if(stevila[i] <= povprecje && d == n){
      d = i;
    }
    vsota += stevila[i];
    povprecje = (double)(vsota)/(double)(i+1);
  }

  printf("%d\n", d);
  
  free(stevila);
  return 0;
}
