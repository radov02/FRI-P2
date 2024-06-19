#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIDE 8
#define ST_KRALJIC 8

int board[BOARD_SIDE];

// NE DELA!

void izrisiPostavitev(){
    for(int i = 1; i <= BOARD_SIDE; i++){    // vrstice
        for(int j = 1; j <= BOARD_SIDE; j++){    // stolpci
            if(board[i] == j){
                printf("#");
            }
            else{
                printf("o");
            }
        }
        printf("\n");
    }
}

bool postavitveBrezNapadanja(int vrstica, int postavljenih){    // postavljenih steje tudi stolpce

    if(postavljenih == ST_KRALJIC){
        izrisiPostavitev();
        return true;
    }
    
    bool ret = false;
    for(int i = 1; i <= BOARD_SIDE; i++){    // cez vrstice
        
        bool postavi = true;
        // zelimo postaviti na [i, postavljenih]

        // pregled stolpca:
        for(int vrstica = 1; vrstica <= BOARD_SIDE; vrstica++){
            if(board[vrstica] > 0 && board[vrstica] != i){
                postavi = false;
            }
        }

        // pregled vrstice:
        for(int stolpec = 1; stolpec <= BOARD_SIDE; stolpec++){
            if(board[vrstica] == stolpec && stolpec != postavljenih){
                postavi = false;
            }
        }

        // pregled diagonal:
        int y = i, x = postavljenih;
        while(y > 0 && y <= BOARD_SIDE && x > 0 && x <= BOARD_SIDE){
            if(y != i && x != postavljenih && board[i] != x){

            }
            y++;
            x++;
        }

        ret = ret || (postavitveBrezNapadanja(i, postavljenih+1));    //ce se ne napadajo klic naprej
        
    }
    return ret;
}

int main(){

    if(!postavitveBrezNapadanja(0, 0)){
        printf("Ni možnih postavitev!\n");
    }

    return 0;
}