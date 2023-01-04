//
// Created by HW on 2022/10/21.
//
#include <stdio.h>
#define LEN 9
int main()
{
    int k;
    int board[LEN][LEN]={
            {5,3,0,0,7,0,0,0,0},
            {6,0,0,1,9,5,0,0,0},
            {0,9,8,0,0,0,0,6,0},
            {8,0,0,0,6,0,0,0,3},
            {4,0,0,8,0,3,0,0,1},
            {7,0,0,0,2,0,0,0,6},
            {0,6,0,0,0,0,2,8,0},
            {0,0,0,4,1,9,0,0,5},
            {0,0,0,0,8,0,0,7,9}
            };
    int count[10][10] = {0};
    int COUNT[10][10] = {0};
    int count1[10]={0};
    int count2[10]={0};
    int count3[10]={0};
    int count4[10]={0};
    int count5[10]={0};
    int count6[10]={0};
    int count7[10]={0};
    int count8[10]={0};
    int count9[10]={0};
    for (int row = 0; row < LEN; ++row) {
        for (int col = 0; col < LEN; ++col) {
            scanf("%d",&board[row][col]);
            //printf("%d",board[row][col]);
        }
    }
    //scan col
    for (int row = 0; row < LEN; ++row) {
        for (int col = 0; col < LEN; ++col) {
            k=board[row][col];
            count[row][k]++;
            }
        }

    //scan row
    for (int col = 0; col < LEN; ++col) {
        for (int row = 0; row < LEN; ++row) {
            k=board[row][col];
            COUNT[k][col]++;
        }
    }
    //if row or col is wrong print no

//        for (int row = 0,col=0; row < LEN && col<LEN; ++row,++col) {
//           for (int k = 0; k < LEN; ++k) {
//               if (COUNT[k][col] != 1 && count[row][k]!= 1) {
//                   printf("NO");
//                   break;
//               }
//           }
//    }

    for (int row = 0; row <= 2; ++row) {
        for (int col = 0; col <= 2; ++col) {
            k=board[row][col];
            count1[k]++;
        }
    }
    for (int row = 3; row <= 5; ++row) {
        for (int col = 0; col <= 2; ++col) {
            k=board[row][col];
            count2[k]++;
        }
    } for (int row = 6; row <= 8; ++row) {
        for (int col = 0; col <= 2; ++col) {
            k=board[row][col];
            count3[k]++;
        }
    } for (int row = 0; row <= 2; ++row) {
        for (int col = 3; col <= 5; ++col) {
            k=board[row][col];
            count4[k]++;
        }
    } for (int row = 3; row <= 5; ++row) {
        for (int col = 3; col <= 5; ++col) {
            k=board[row][col];
            count5[k]++;
        }
    } for (int row = 6; row <= 8; ++row) {
        for (int col = 3; col <= 5; ++col) {
            k=board[row][col];
            count6[k]++;
        }
    } for (int row = 0; row <= 2; ++row) {
        for (int col = 6; col <= 8; ++col) {
            k=board[row][col];
            count7[k]++;
        }
    } for (int row = 3; row <= 5; ++row) {
        for (int col = 6; col <= 8; ++col) {
            k=board[row][col];
            count8[k]++;
        }
    } for (int row = 6; row <= 8; ++row) {
        for (int col = 6; col <= 8; ++col) {
            k=board[row][col];
            count9[k]++;
        }
    }
    for (int k = 1; k<= 9; ++k) {

        if (count1[k] == 1 && count2[k] == 1 && count3[k] == 1 && count4[k] == 1 && count5[k] == 1 && count6[k] == 1 &&
             count7[k] == 1 && count8[k] == 1 && count9[k] == 1
            && count[0][k] == 1 && count[1][k] == 1 && count[2][k] == 1 && count[3][k] == 1 && count[4][k] == 1 &&
            count[5][k] == 1 && count[6][k] == 1 && count[7][k] == 1 && count[8][k] == 1
            && COUNT[k][0] == 1 && COUNT[k][1] == 1 && COUNT[k][2] == 1 && COUNT[k][3] == 1 && COUNT[k][4] == 1 &&
            COUNT[k][5] == 1 && COUNT[k][6] == 1 && COUNT[k][7] == 1 && COUNT[k][8] == 1) {
            if(k==9){
                printf("YES");
            }
        } else {
            printf("NO");
            break;
        }
    }

}
