//
// Created by HW on 2022/12/29.
//
#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    getchar();
    for (int i = 0; i < T; ++i) {
        //定义一个棋盘
        char board[20][20];
        int is_jugde = 0;

        //输入一个初始状态用来判断
        for (int j = 0; j < 20; ++j) {
            for (int k = 0; k < 20; ++k) {
                scanf("%c", &board[j][k]);
            }
            getchar();
        }

        //判断后手获胜 即后手连成四个
        for (int j = 0; j < 20; ++j) {
            for (int k = 0; k < 20; ++k) {
                //遍历全盘 对于每一个*检查有无三种可能的胜利情况
                //第一种 横向4颗
                //横向****_
                if (k <= 15) {
                    if (board[j][k] == '*') {
                        if (board[j][k + 1] == '*') {
                            if (board[j][k + 2] == '*') {
                                if (board[j][k + 3] == '*') {
                                    if (board[j][k + 4] == '_') {
                                        if (is_jugde == 0) {
                                            printf("Lose\n");
                                            is_jugde = 2;
                                            break;
                                        }
                                    }
                                }
                                    //横向***_*
                                else if (board[j][k + 3] == '_') {
                                    if (board[j][k + 4] == '*') {
                                        if (is_jugde == 0) {
                                            printf("Lose\n");
                                            is_jugde = 2;
                                            break;
                                        }
                                    }
                                }
                            }
                                //横向**_**
                            else if (board[j][k + 2] == '_') {
                                if (board[j][k + 3] == '*') {
                                    if (board[j][k + 4] == '*') {
                                        if (is_jugde == 0) {
                                            printf("Lose\n");
                                            is_jugde = 2;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                            //*_***
                        else if (board[j][k + 1] == '_') {
                            if (board[j][k + 2] == '*') {
                                if (board[j][k + 3] == '*') {
                                    if (board[j][k + 4] == '*') {
                                        if (is_jugde == 0) {
                                            printf("Lose\n");
                                            is_jugde = 2;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                        //_****
                    else if (board[j][k] == '_') {
                        if (board[j][k + 1] == '*') {
                            if (board[j][k + 2] == '*') {
                                if (board[j][k + 3] == '*') {
                                    if (board[j][k + 4] == '*') {
                                        if (is_jugde == 0) {
                                            printf("Lose\n");
                                            is_jugde = 2;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                //第二种 纵向获胜
                //****_
                if (j <= 15) {
                    if (board[j][k] == '*') {
                        if (board[j + 1][k] == '*') {
                            if (board[j + 2][k] == '*') {
                                if (board[j + 3][k] == '*') {
                                    if (board[j + 4][k] == '_') {
                                        if (is_jugde == 0) {
                                            printf("Lose\n");
                                            is_jugde = 2;
                                            break;
                                        }
                                    }
                                }
                                    //***_*
                                else if (board[j + 3][k] == '_') {
                                    if (board[j + 4][k] == '*') {
                                        if (is_jugde == 0) {
                                            printf("Lose\n");
                                            is_jugde = 2;
                                            break;
                                        }
                                    }
                                }
                            }
                                //**_**
                            else if (board[j + 2][k] == '_') {
                                if (board[j + 3][k] == '*') {
                                    if (board[j + 4][k] == '*') {
                                        if (is_jugde == 0) {
                                            printf("Lose\n");
                                            is_jugde = 2;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                            //*_***
                        else if (board[j + 1][k] == '_') {
                            if (board[j + 2][k] == '*') {
                                if (board[j + 3][k] == '*') {
                                    if (board[j + 4][k] == '*') {
                                        if (is_jugde == 0) {
                                            printf("Lose\n");
                                            is_jugde = 2;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                        //_****
                    else if (board[j][k] == '_') {
                        if (board[j + 1][k] == '*') {
                            if (board[j + 2][k] == '*') {
                                if (board[j + 3][k] == '*') {
                                    if (board[j + 4][k] == '*') {
                                        if (is_jugde == 0) {
                                            printf("Lose\n");
                                            is_jugde = 2;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                //第三种斜向获胜
                //****_
                if (j <= 15 && k <= 15) {
                    if (board[j][k] == '*') {
                        if (board[j + 1][k + 1] == '*') {
                            if (board[j + 2][k + 2] == '*') {
                                if (board[j + 3][k + 3] == '*') {
                                    if (board[j + 4][k + 4] == '_') {
                                        if (is_jugde == 0) {
                                            printf("Lose\n");
                                            is_jugde = 2;
                                            break;
                                        }
                                    }
                                }
                                    //***_*
                                else if (board[j + 3][k + 3] == '_') {
                                    if (board[j + 4][k + 4] == '*') {
                                        if (is_jugde == 0) {
                                            printf("Lose\n");
                                            is_jugde = 2;
                                            break;
                                        }
                                    }
                                }
                            }
                                //**_**
                            else if (board[j + 2][k + 2] == '_') {
                                if (board[j + 3][k + 3] == '*') {
                                    if (board[j + 4][k + 4] == '*') {
                                        if (is_jugde == 0) {
                                            printf("Lose\n");
                                            is_jugde = 2;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                            //*_***
                        else if (board[j + 1][k + 1] == '_') {
                            if (board[j + 2][k + 2] == '*') {
                                if (board[j + 3][k + 3] == '*') {
                                    if (board[j + 4][k + 4] == '*') {
                                        if (is_jugde == 0) {
                                            printf("Lose\n");
                                            is_jugde = 2;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                        //_****
                    else if (board[j][k] == '_') {
                        if (board[j + 1][k + 1] == '*') {
                            if (board[j + 2][k + 2] == '*') {
                                if (board[j + 3][k + 3] == '*') {
                                    if (board[j + 4][k + 4] == '*') {
                                        if (is_jugde == 0) {
                                            printf("Lose\n");
                                            is_jugde = 2;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        //判断先手获胜 即后手连成四个
        //如果后手没有获胜
        int count_four = 0;
        if (is_jugde != 2) {
            for (int j = 0; j < 20; ++j) {
                for (int k = 0; k < 20; ++k) {
                    //遍历棋局 观察是否有两个四个连珠的情况出现
                    //对于每一个棋子都要检查是否有三种情况的 一种或者两种
                    //####_
                    if (k <= 15) {
                        if (board[j][k] == '#') {
                            if (board[j][k + 1] == '#') {
                                if (board[j][k + 2] == '#') {
                                    if (board[j][k + 3] == '#') {
                                        if (board[j][k + 4] == '_') {
                                            count_four++;
                                        }
                                    }
                                        //###_#
                                    else if (board[j][k + 3] == '_') {
                                        if (board[j][k + 4] == '#') {
                                            count_four++;
                                        }
                                    }
                                }
                                    //##_##
                                else if (board[j][k + 2] == '_') {
                                    if (board[j][k + 3] == '#') {
                                        if (board[j][k + 4] == '#') {
                                            count_four++;
                                        }
                                    }
                                }
                            }
                                //#_###
                            else if (board[j][k + 1] == '_') {
                                if (board[j][k + 2] == '#') {
                                    if (board[j][k + 3] == '#') {
                                        if (board[j][k + 4] == '#') {
                                            count_four++;
                                        }
                                    }
                                }
                            }
                        }
                            //_####
                        else if (board[j][k] == '_') {
                            if (board[j][k + 1] == '#') {
                                if (board[j][k + 2] == '#') {
                                    if (board[j][k + 3] == '#') {
                                        if (board[j][k + 4] == '#') {
                                            count_four++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    //第二种 纵向获胜
                    //####_
                    if (j <= 15) {
                        if (board[j][k] == '#') {
                            if (board[j + 1][k] == '#') {
                                if (board[j + 2][k] == '#') {
                                    if (board[j + 3][k] == '#') {
                                        if (board[j + 4][k] == '_') {
                                            count_four++;
                                        }
                                    }
                                        //###_#
                                    else if (board[j + 3][k] == '_') {
                                        if (board[j + 4][k] == '#') {
                                            count_four++;
                                        }
                                    }
                                }
                                    //##_##
                                else if (board[j + 2][k] == '_') {
                                    if (board[j + 3][k] == '#') {
                                        if (board[j + 4][k] == '#') {
                                            count_four++;
                                        }
                                    }
                                }
                            }
                                //#_###
                            else if (board[j + 1][k] == '_') {
                                if (board[j + 2][k] == '#') {
                                    if (board[j + 3][k] == '#') {
                                        if (board[j + 4][k] == '#') {
                                            count_four++;
                                        }
                                    }
                                }
                            }
                        }
                            //_####
                        else if (board[j][k] == '_') {
                            if (board[j + 1][k] == '#') {
                                if (board[j + 2][k] == '#') {
                                    if (board[j + 3][k] == '#') {
                                        if (board[j + 4][k] == '#') {
                                            count_four++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    //第三种斜向获胜
                    //####_
                    if (j <= 15 && k <= 15) {
                        if (board[j][k] == '#') {
                            if (board[j + 1][k + 1] == '#') {
                                if (board[j + 2][k + 2] == '#') {
                                    if (board[j + 3][k + 3] == '#') {
                                        if (board[j + 4][k + 4] == '_') {
                                            count_four++;
                                        }
                                    }
                                        //###_#
                                    else if (board[j + 3][k + 3] == '_') {
                                        if (board[j + 4][k + 4] == '#') {
                                            count_four++;
                                        }
                                    }
                                }
                                    //##_##
                                else if (board[j + 2][k + 2] == '_') {
                                    if (board[j + 3][k + 3] == '#') {
                                        if (board[j + 4][k + 4] == '#') {
                                            count_four++;

                                        }
                                    }
                                }
                            }
                                //#_###
                            else if (board[j + 1][k + 1] == '_') {
                                if (board[j + 2][k + 2] == '#') {
                                    if (board[j + 3][k + 3] == '#') {
                                        if (board[j + 4][k + 4] == '#') {
                                            count_four++;
                                        }
                                    }
                                }
                            }
                        }
                            //_####
                        else if (board[j][k] == '_') {
                            if (board[j + 1][k + 1] == '#') {
                                if (board[j + 2][k + 2] == '#') {
                                    if (board[j + 3][k + 3] == '#') {
                                        if (board[j + 4][k + 4] == '#') {
                                            count_four++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (count_four >= 2) {
            printf("Win\n");
            is_jugde = 1;
        }
        if (is_jugde == 0) {
            printf("Not Sure\n");
        }
    }
}