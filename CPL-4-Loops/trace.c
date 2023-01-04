//
// Created by HW on 2022/10/22.
//
#include <stdio.h>
int main()
{
    int n,m,x0,y0;
    int count=0,COUNT=0;
    int i,j;
    scanf("%d %d %d %d\n",&n,&m,&x0,&y0);
    char board[51][51]={0};
    int bool_board[51][51]={0};
    int vectors[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    //input
    for (int row = 1; row <= n; ++row) {
        for (int col = 1; col <=m ; ++col) {
            scanf("%c",&board[row][col]);
            if(board[row][col]=='#'){
                count++;
            }
        }
        getchar();
    }
    printf("%d\n",count);

    //trace
    i=x0,j=y0;
    printf("%d %d",i,j);

    bool_board[x0][y0]=1;
    while(COUNT<count-2) {
        for (int k = 0; k < 4; ++k) {
            int newI = i + vectors[k][0];
            int newJ = j + vectors[k][1];
            if (board[newI][newJ] == '#' && bool_board[newI][newJ] == 0) {
                i = newI;
                j = newJ;
                printf("\n%d %d", i, j);
                bool_board[i][j] = 1;
                ++COUNT;
                break;
            }
        }
    }
    for (int k = 0; k < 4; ++k) {
        int newI = i + vectors[k][0];
        int newJ = j + vectors[k][1];
        if (board[newI][newJ] == '#' && bool_board[newI][newJ] == 0) {
            i = newI;
            j = newJ;
            printf("\n%d %d", i, j);
            bool_board[i][j] = 1;
            ++COUNT;
            break;
        }
    }
    return 0;
}