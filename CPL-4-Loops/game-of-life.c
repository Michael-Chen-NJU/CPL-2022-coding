//
// Created by HW on 2022/10/21.
//
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define SIZE 6
int board[SIZE][SIZE]={
        {0},
        {0,1,1,0,0,0},
        {0,1,1,0,0,0},
        {0,0,1,1,0,0},
        {0,0,1,1,0,0},
        {0}
};
int main()
{
    //extend [SIZE] to [SIZE+2]
    int old_board[SIZE+2][SIZE+2]={0};
    for (int row = 0; row < SIZE+2; ++row) {
        for (int col = 0; col < SIZE+2; ++col) {
            if(row == 0||row== SIZE + 1||col == 0||col == SIZE + 1){
                old_board[row][col]=0;
            }else{
                old_board[row][col]=board[row - 1][col - 1];
            }
        }
    }

    //print the original board
    system("clear");
    for (int row = 1; row <= SIZE; ++row) {
        for (int col = 1; col <= SIZE; ++col) {
            printf("%c",old_board[row][col]?'*' : ' ');
        }
        printf("\n");
    }


    int next_board[SIZE+ 2 ][SIZE + 2] = {0};
    for (int round = 0; round <=10 ; ++round) {

        for (int row = 1; row <= SIZE; ++row) {
            for (int col = 1; col <= SIZE; ++col) {
                //count the neighbours of old[row][col] in the old_board
                int neighbors =
                        old_board[row - 1][col - 1] +
                        old_board[row - 1][col] +
                        old_board[row - 1][col + 1] +
                        old_board[row][col - 1] +
                        old_board[row][col + 1] +
                        old_board[row + 1][col - 1] +
                        old_board[row + 1][col] +
                        old_board[row + 1][col + 1];

                //evaluate next_board[row][col] on the next_board

                if (old_board[row][col]) {
                    next_board[row][col] = (neighbors == 2 || neighbors == 3);
                } else {
                    next_board[row][col] = (neighbors == 3);
                }
            }
        }
    }

    Sleep(1000);
    for (int row = 1; row <= SIZE; ++row) {
        for (int col = 1; col <= SIZE; ++col) {
            printf("%c",next_board[row][col]?'*' : ' ');
        }
        printf("\n");
    }

    //copy
    return 0;
}