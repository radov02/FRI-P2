#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool jePitagorejsko(int c){
    
        for(int a = 1; a < c; a++){
            for(int b = a+1; b < c; b++){
                if(a*a + b*b == c*c){
                    return true;
                }
            }
        }
        return false;
}

bool jePitagorejskoHitreje(int c){
    for(int a = 1; a < c; a++){
        int b2 = c*c - a*a;
        int b = round(sqrt(b2));
        if(b*b == b2){
            return true;
        }
    }
    return false;
}

int main(){

    int spMeja = 0;
    int zgMeja = 0;
    scanf("%d%d", &spMeja, &zgMeja);

    // a ne more biti enak b, b je vecji od a, b = sqrt(c² - a²) in je celo stevilo

    int stevec = 0;
    
    for(int c = spMeja; c <= zgMeja; c++){  // preverimo ali lahko c zapisemo kot c² = a² + b²
        
        if(jePitagorejsko(c)){
            stevec++;
        }
        
        
    }

    printf("%d\n", stevec);

    return 0;
}

/*
for(int i = spMeja; i <= zgMeja; i++){
        for(int j = 1; j < zgMeja; j++){
            for(int k = j; k <= zgMeja; k++){
                if(j*j + k*k == i*i){
                    //printf("%d + %d = %d\n", j*j, k*k, i*i);
                    stevec++;
                }
            }
        }
    }
*/