#include <stdio.h>
#include <stdlib.h>

// kup 0 in kup 1
void particijiZistoVsoto(int trenutniListek, int vsotaKupaNic, int vsotaKupaEna, unsigned int* particiji, int* listki, int n){


    if(trenutniListek == n && vsotaKupaNic == vsotaKupaEna){
        for(int i = 0; i < trenutniListek; i++){
            printf("%d", particiji[i]);
        }
        printf("\nvsota=%d\n", vsotaKupaNic);
        return;
    }
    else if(trenutniListek >= n){
        return;
    }

    particiji[trenutniListek] = 0;
    particijiZistoVsoto(trenutniListek+1, vsotaKupaNic + listki[trenutniListek], vsotaKupaEna, particiji, listki, n);

    particiji[trenutniListek] = 1;
    particijiZistoVsoto(trenutniListek+1, vsotaKupaNic, vsotaKupaEna + listki[trenutniListek], particiji, listki, n);
}

int main(){

    int n;
    scanf("%d", &n);
    int* listki = malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &listki[i]);
    }

    unsigned int* particiji = malloc(n*sizeof(unsigned int));

    particijiZistoVsoto(0, 0, 0, particiji, listki, n);

    return 0;
}