//
// Created by HW on 2022/10/22.
//
#include <stdio.h>
int main() {
    int n = 0;
    int row, col;
    scanf("%d", &n);
    getchar();
    int board[100][100] = {0};
    int new_board[100][100] = {0};
    int vectors[8][2] = {{0,  1},
                         {0,  -1},
                         {1,  0},
                         {-1, 0},
                         {-1,-1},
                         {-1,1},
                         {1,-1},
                         {1,1}};

    //input
    for (int row = 1; row <= n; ++row) {
        for (int col = 1; col <= n; ++col) {
            scanf("%c", &board[row][col]);
            //printf("%c ",board[row][col]);
        }
        getchar();
    }
    //sum up the total number
    for (int row = 1; row <= n; ++row) {
        for (int col = 1; col <= n; ++col) {
            if (board[row][col] == 'o') {
                for (int k = 0; k < 8; ++k) {
                    int newI = row + vectors[k][0];
                    int newJ = col + vectors[k][1];
                    if (board[newI][newJ] == '*') {
                        new_board[row][col]++;
                    }
                }
            }
        }
    }
    //output the new board
    for (int row = 1; row <= n; ++row) {
        for (int col = 1; col <= n; ++col) {
        if(board[row][col]=='*'){
            printf("*");
        }
        if(board[row][col]=='o'){
            printf("%d", new_board[row][col]);
        }
        }
        printf("\n");
    }
}