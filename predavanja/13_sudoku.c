#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int sudoku[9][9] = {
        {0,0,0,0,0,0,0,0,8},
        {0,1,0,0,0,7,0,0,0},
        {2,0,0,5,0,0,0,0,0},
        {0,0,0,0,0,3,0,0,0},
        {0,5,6,0,7,0,0,0,0},
        {0,0,9,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,3,0},
        {0,4,0,0,2,0,6,5,0},
        {0,0,0,0,0,0,0,0,9}
    };

void solve(int i, int j){
    if(i == 9 && j == 0){   // če smo na koncu polj
        for(int ii = 0; ii < 9; ii++){
            for(int jj = 0; jj < 9; jj++){
                printf("%d", sudoku[ii][jj]);
            }
            printf("\n");
        }
        printf("\n");
        return;
    }

    if(sudoku[i][j] != 0){  // polje je že zasedeno
        if(j == 8){
            solve(i+1, 0);
        }
        else{
            solve(i, j+1);
        }
        return;
    }

    for(int n = 1; n <= 9; n++){    // poskušamo z vsemi števkami
        bool ok = true;
        for(int jj = 0; jj < 9; jj++){
            ok = ok && (sudoku[i][jj] != n);
        }
        for(int ii = 0; ii < 9; ii++){
            ok = ok && (sudoku[ii][j] != n);
        }
        // najdemo zgronje levo polje kvadrata:
        int i0 = (i/3)*3;
        int j0 = (j/3)*3;
        for(int ii = 0; ii < 3; ii++){
            for(int jj = 0; jj < 3; jj++){
                ok = ok && (sudoku[i0+ii][j0+jj] != n);
            }
        }

        if(ok){
            sudoku[i][j] = n;
            if(j == 8){
                solve(i+1, 0);  // v novo vrstico
            }
            else{
                solve(i, j+1);
            }
            sudoku[i][j] = 0;
        }
    }
}

int main(){

    solve(0, 0);

    return 0;
}