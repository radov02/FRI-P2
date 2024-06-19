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

// kličemo za vsako polje:
void solve(int i, int j){

    // če smo na koncu polj samo izpišemo rešen sudoku:
    if(i == 9 && j == 0){   
        for(int ii = 0; ii < 9; ii++){
            for(int jj = 0; jj < 9; jj++){
                printf("%d", sudoku[ii][jj]);
            }
            printf("\n");
        }
        printf("\n");
        return;
    }

    // polje je že zasedeno, kličemo naslednje polje:
    if(sudoku[i][j] != 0){  
        if(j == 8){
            solve(i+1, 0);  // v novo vrstico
        }
        else{
            solve(i, j+1);
        }
        return;
    }

    // polje ni zasedeno, poskušamo z vsemi števkami:
    for(int n = 1; n <= 9; n++){
        bool ok = true;
        // preverimo po vrstici in stolpcu:
        for(int jj = 0; jj < 9; jj++){
            ok = ok && (sudoku[i][jj] != n);
        }
        for(int ii = 0; ii < 9; ii++){
            ok = ok && (sudoku[ii][j] != n);
        }
        // najdemo zgronje levo polje kvadrata in preverimo kvadrat:
        int i0 = (i/3)*3;
        int j0 = (j/3)*3;
        for(int ii = 0; ii < 3; ii++){
            for(int jj = 0; jj < 3; jj++){
                ok = ok && (sudoku[i0+ii][j0+jj] != n);
            }
        }

        // kličemo naslednje polje:
        if(ok){
            sudoku[i][j] = n;
            // SKUŠAMO REŠITI ZA TO MOŽNOST:
            if(j == 8){
                solve(i+1, 0);  // v novo vrstico
            }
            else{
                solve(i, j+1);
            }
            // ČE NAM NE USPE REŠITI, BOMO DALI NAZAJ NA 0 IN SKUŠALI Z DRUGO MOŽNOSTJO:
            sudoku[i][j] = 0;
        }
    }
}

void printBoard(char** board, int boardSize, int* boardColSize){
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < boardColSize[i]; j++){
            printf("%d", board[i][j]);
        }
        printf("\n");
    }
}

bool eden = true;

void solve1(int i, int j, char** board, int boardSize, int* boardColSize){
    if(i == 9 && j == 0 && eden){
        // when it is solved
        printBoard(board, boardSize, boardColSize);
        eden = false;
        return;
    }

    if(board[i][j] != '.'){ // not empty
        if(j == 8){
            solve1(i+1, 0, board, boardSize, boardColSize);
        }
        else{
            solve1(i, j+1, board, boardSize, boardColSize);
        }
    }
    
    // empty:
    for(int insert = 1; insert <= 9; insert++){
        bool ok = true;
        for(int ii = 0; ii < 9; ii++){
            ok = ok && (board[ii][j] != insert);
        }
        if(ok){
            for(int jj = 0; jj < 9; jj++){
                ok = ok && (board[i][jj] != insert);
            }
        }
        if(ok){
            int i0 = (i / 3)*3;
            int j0 = (j / 3)*3;
            for(int ii = 0; ii < 3; ii++){
                for(int jj = 0; jj < 3; jj++){
                    ok = ok && (board[i0+ii][j0+jj] != insert);
                }
            }
        }

        if(ok){ // if 'insert' is eligible for this position
            board[i][j] = insert;
            if(j == 8){
                solve1(i+1, 0, board, boardSize, boardColSize);
            }
            else{
                solve1(i, j+1, board, boardSize, boardColSize);
            }
            board[i][j] = 0;    // if 'insert' does not solve this one right, we try another suitable number
        }
    }
}

void solveSudoku(char** board, int boardSize, int* boardColSize){
    solve1(0, 0, board, boardSize, boardColSize);
}

int main(){

    /* char originalBoard[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    char** board = (char**)malloc(9 * sizeof(char*));
    for (int i = 0; i < 9; i++) {
        board[i] = (char*)malloc(9 * sizeof(char));
        for (int j = 0; j < 9; j++) {
            board[i][j] = originalBoard[i][j];
        }
    }
    int boardColSize[9] = {9, 9, 9, 9, 9, 9, 9, 9, 9};
    solveSudoku(board, 9, boardColSize); */

    solve(0, 0);
    
    return 0;
}