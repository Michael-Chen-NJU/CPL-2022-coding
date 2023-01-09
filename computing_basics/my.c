//
// Created by asus on 2022/12/27.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>

#define spot_num 50
#define map_size 52
#define map_num 3
#define row 5
#define column 10
#define chance 20

char print_map[map_size][map_size];
bool position_a[spot_num] = {}; //地图位点是否放了卡牌
bool position_b[spot_num] = {};
bool position_c[spot_num] = {};
int a_size, b_size, c_size; // 地图上总放多少张卡牌
char a = 'a', b = 'b', c = 'c';
int cur_x = 0, cur_y = 0;//位点图上的坐标
typedef struct Card_ {
    char card[10][5];
    int index; // 挡了多少牌
} Card;
Card *position[row][column][map_num] = {};//三维位点图，每个位点放结构体
bool top[row][column] = {};
int chosen_card[chance + 1] = {};
int check[13] = {};
int num = 0;//记录卡槽现有多少张牌
int result = 3;
int total = 0;//记录总共地图上还剩多少张牌

Card *new_card() // 初始化一张新卡牌
{
    Card *card = (Card *) malloc(sizeof(Card));
    card->index = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            card->card[i][j] = '\0';
        }
    }
    return card;
}

void color(const unsigned short textColor) // 自定义函根据参数改变颜色
{
    if (textColor >= 0 && textColor <= 15)                                   // 参数在0-15的范围颜色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor); // 用一个参数，改变字体颜色
    else                                                                     // 默认的字体颜色是黑色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

HANDLE consoleHandle; // 操作控制台（也就是那个黑框框）需要的一个变量
int w, h;             // 高度，宽度，对应 y 和 x
// 在屏幕上 y, x 的位置打印一个 ch
void mvaddch(int y, int x, char ch) {
    COORD co = (COORD) {.X = x, .Y = y};
    SetConsoleCursorPosition(consoleHandle, co); // 设置你的光标位置
    putchar(ch);                                 // 在这里打印一个字符
}

void ScreenInit();

void Initialize();

void InitPrintMap();

char IsTop(int x, int y);

void PaintCard(Card *);

void PrintMap(int, int);

void GetInput();

void MarkCard(int, int);

void ChooseCard();

int Check();

void Restart();

int main() {
    printf("Let's play the game!\n");
    Sleep(2000);              // 程序暂停 2000 毫秒
    system("cls");
    Initialize();
    GetInput();
}

void Restart() {
    system("cls");
    printf("press any key to continue...\n");
    while (kbhit() != 0) {
        system("cls");
        printf("Let's play the game!\n");
        Sleep(2000);              // 程序暂停 2000 毫秒
        system("cls");
        Initialize();
        return;
    }
}

void Reset() {
    int reset[chance] = {};
    int temp = 0;
    for (int i = 0; i < chance; ++i) {
        reset[i] = 11;//初始化临时数组
    }
    for (int i = 0; i < chance; ++i) {
        if (chosen_card[i] != 11) {
            reset[temp++] = chosen_card[i];//把有意义的卡牌全往前移，保证不间隔空
        }
    }
    for (int i = 0; i < chance; ++i) {
        chosen_card[i] = reset[i];//再把临时数组复制给卡槽
    }
}

int Check() {
    for (int i = 0; i < 12; ++i) {
        check[i] = 0;
    }
    for (int i = 0; i < chance; ++i) {
        check[chosen_card[i]]++;//遍历卡槽，记录相同卡牌的数量
    }
    for (int i = 0; i < 11; ++i)//遍历计数的数组,但是要排除空白项
    {
        if (check[i] == 3)//一旦等于3张
        {
            int temp = i;
            for (int j = 0; j < chance; ++j)//找到这三张
            {
                if (chosen_card[j] == temp)//清空这三张,并重置卡槽
                {
                    chosen_card[j] = 11;
                }
            }
            Reset();
            num -= 3;
            total -= 3;
            return 2;
        }
    }
    total--;
    if (num == chance)//卡槽满了
    {
        return 1;
    } else if (total == 0)//已经清空所有卡牌
    {
        return 0;
    }
}

void ChooseCard() {
    for (int i = 0; i < 3; ++i)//从上往下找
    {
        if (position[cur_x][cur_y][i] != NULL) {
            chosen_card[num++] = position[cur_x][cur_y][i]->index;
            int ans = Check();
            if (ans == 0) {
                printf("You win!\n");
                Sleep(2000);              // 程序暂停 2000 毫秒
                result = 0;
                return;
            } else if (ans == 1) {
                printf("You lose!\n");
                Sleep(2000);              // 程序暂停 2000 毫秒
                result = 1;
                return;
            } else//继续游戏
            {
                result = 2;
                position[cur_x][cur_y][i] = NULL;//去掉被选中的牌
                //更新，重新标红一张牌
                for (int j = 0; j < 3; ++j) {
                    if (position[cur_x][cur_y][j] == NULL) {
                        top[cur_x][cur_y] = false;
                    }
                }
                while (!top[cur_x][cur_y])//找到第一张顶层牌
                {
                    if (cur_y == column - 1) {
                        if (cur_x == row - 1)//到达右下角后转到左上角继续寻找
                        {
                            cur_x = 0;
                            cur_y = 0;
                            continue;
                        } else {
                            cur_x++;
                            cur_y = 0;
                            continue;
                        }
                    }
                    cur_y++;
                }
                MarkCard(cur_x, cur_y);//初始状态，把它标红
                return;
            }
        }
    }
//    printf("You win!\n");
//    Sleep(2000);              // 程序暂停 2000 毫秒
//    result = 0;
}

void MarkCard(int x, int y) {
    system("cls");
    InitPrintMap();
    PrintMap(x, y);
}

void GetInput() {
    cur_x = 0, cur_y = 0;
    while (!top[cur_x][cur_y])//找到第一张顶层牌
    {
        if (cur_y == column - 1) {
            cur_x++;
            cur_y = 0;
            continue;
        }
        cur_y++;
    }
    MarkCard(cur_x, cur_y);//初始状态，把它标红
    while (1) {
        while (kbhit() != 0) {
            bool legal_input = true;
            char input = getch();
            if (input == 'A') {
                if (cur_y == 0) {
                    legal_input = false;
                } else {
                    cur_y--;
                    while (!top[cur_x][cur_y]) {
                        if (cur_y == 0) {
                            legal_input = false;
                            cur_y++;
                            break;
                        }
                        cur_y--;
                    }
                }
                if (legal_input) {
                    MarkCard(cur_x, cur_y);
                }
            } else if (input == 'D') {
                if (cur_y == column - 1)//不能继续键入D
                {
                    legal_input = false;
                } else {
                    cur_y++;
                    while (!top[cur_x][cur_y]) {
                        if (cur_y == column - 1)//不能继续键入D
                        {
                            legal_input = false;
                            cur_y--;
                            break;
                        }
                        cur_y++;
                    }
                }
                if (legal_input) {
                    MarkCard(cur_x, cur_y);
                }
            } else if (input == 'W') {
                if (cur_x == 0)//不能继续键入W
                {
                    legal_input = false;
                } else {
                    cur_x--;
                    while (!top[cur_x][cur_y]) {
                        if (cur_x == 0)//不能继续键入W
                        {
                            legal_input = false;
                            cur_x++;
                            break;
                        }
                        cur_x--;
                    }
                }
                if (legal_input) {
                    MarkCard(cur_x, cur_y);
                }
            } else if (input == 'S') {
                if (cur_x == row - 1)//不能继续键入S的情况：最底端
                {
                    legal_input = false;
                } else {
                    cur_x++;
                    while (!top[cur_x][cur_y]) {
                        if (cur_x == row - 1)//不能继续键入S的情况：最底端
                        {
                            legal_input = false;
                            cur_x--;
                            break;
                        }
                        cur_x++;
                    }
                }
                if (legal_input) {
                    MarkCard(cur_x, cur_y);
                }
            } else if (input == 'G') {
                ChooseCard();
            }
            Sleep(100);              // 程序暂停 100 毫秒
            if (result == 0 || result == 1) {
                Restart();
            }
        }
    }
}

void ScreenInit() {
    consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);  // 初始化这个操作器
    CONSOLE_SCREEN_BUFFER_INFO csbi;                  // 屏幕的信息
    GetConsoleScreenBufferInfo(consoleHandle, &csbi); // 获取屏幕信息
    w = csbi.dwSize.X;//宽度
    h = csbi.dwSize.Y; // 得到高度
    // 游戏里面，如果一直有输入的光标，就有点不好看。我们可以让它不显示
    CONSOLE_CURSOR_INFO cci; // 光标信息
    cci.dwSize = 100;
    cci.bVisible = FALSE;                      // 不可见
    SetConsoleCursorInfo(consoleHandle, &cci); // 将光标特性应用到控制台
    // 到这里，闪烁的光标就消失了。
}

char IsTop(int x, int y)//传的是投影地图上的坐标
{

    if (position[x / 10][y / 5][0] != NULL) // 说明是a层，一定在顶端
    {
        top[x / 10][y / 5] = true;
        return a;
    } else if (position[(x - 4) / 10][(y + 2) / 5][1] != NULL)//说明是b层，不一定在顶端
    {
        if ((y + 2) / 5 == 0 && position[(x - 4) / 10][(y + 2) / 5][0] == NULL) // 说明是b层最左列
        {
            if ((x - 4) / 10 == row - 1 || position[(x - 4) / 10 + 1][(y + 2) / 5][0] == NULL) // 左下角或者正常
            {
                top[(x - 4) / 10][(y + 2) / 5] = true;
                return b;
            }
            return 'f';
        } else if (position[(x - 4) / 10][(y + 2) / 5][0] == NULL &&
                   position[(x - 4) / 10][(y + 2) / 5 - 1][0] == NULL && (x - 4) / 10 == row - 1) // 说明是b层最后一行
        {
            top[(x - 4) / 10][(y + 2) / 5] = true;
            return b;
        } else {
            if (position[(x - 4) / 10][(y + 2) / 5][0] == NULL &&
                position[(x - 4) / 10 + 1][(y + 2) / 5][0] == NULL &&
                position[(x - 4) / 10][(y + 2) / 5 - 1][0] == NULL &&
                position[(x - 4) / 10 + 1][(y + 2) / 5 - 1][0] == NULL) {
                top[(x - 4) / 10][(y + 2) / 5] = true;
                return b;
            }
            return 'f';
        }
        //top[(x - 4) / 10][(y + 2) / 5] = false;
    } else if (position[x / 10][y / 5][2] != NULL)//说明是c层，不一定在顶端
    {
        if (x / 10 == 0 && position[(x - 4) / 10][(y + 2) / 5][1] == NULL) // 第一行
        {
            if (y / 5 == column - 1 || position[(x - 4) / 10][(y + 2) / 5 + 1][1] == NULL) // 右上角或者正常
            {
                top[x / 10][y / 5] = true;
                return c;
            }
            return 'f';
        } else if (y / 5 == column - 1 && position[(x - 4) / 10 - 1][(y + 2) / 5][1] == NULL &&
                   position[(x - 4) / 10][(y + 2) / 5][1] == NULL) // 最右列
        {
            top[x / 10][y / 5] = true;
            return c;
        } else {
            if (position[(x - 4) / 10][(y + 2) / 5 + 1][1] == NULL && position[(x - 4) / 10][(y + 2) / 5][1] == NULL &&
                position[(x - 4) / 10 - 1][(y + 2) / 5][1] == NULL &&
                position[(x - 4) / 10 - 1][(y + 2) / 5 + 1][1] == NULL) {
                top[x / 10][y / 5] = true;
                return c;
            }
            return 'f';
        }
        //top[(x - 4) / 10][(y + 2) / 5] = false;
    }
    return 'f';
}

void InitPrintMap() {
    for (int i = 0; i < map_size; ++i) {
        for (int j = 0; j < map_size; ++j) {
            print_map[i][j] = '\0';
        }
    }
    for (int i = 0; i < map_size; ++i) // 边框
    {
        print_map[0][i] = '+';
        print_map[map_size - 1][i] = '+';
        print_map[i][0] = '|';
        print_map[i][map_size - 1] = '|';
    }
    for (int i = 0; i < row; ++i) // 先打印最底层的地图
    {
        for (int j = 0; j < column; ++j) {
            if (position[i][j][2] != NULL) // c层这里有卡牌
            {
                int spot = 10 * i + j;
                for (int k = 0; k < 10; ++k) {
                    for (int l = 0; l < 5; ++l) // 把位点的结构体里存的卡牌画到位点在地图上对应的位置上
                    {
                        print_map[10 * (spot / 10) + 1 + k][5 * (spot % 10) + 1 + l] = position[i][j][2]->card[k][l];
                    }
                }
            }
        }
    }
    for (int i = 0; i < row; ++i) // 逐层向上覆盖
    {
        for (int j = 0; j < column; ++j) {
            if (position[i][j][1] != NULL) // b层这里有牌
            {
                int spot = 10 * i + j;
                if (j == 0 && i != (row - 1)) // 最左列且不包含左下角
                {
                    for (int k = 0; k < 10; ++k) {
                        for (int l = 2; l < 5; ++l) {
                            print_map[10 * (spot / 10) + 5 + k][5 * (spot % 10) - 1 +
                                                                l] = position[i][j][1]->card[k][l];
                        }
                    }
                } else if (i == row - 1) // 最后一行
                {
                    if (j == 0) // 左下角
                    {
                        for (int k = 0; k < 6; ++k) {
                            for (int l = 2; l < 5; ++l) {
                                print_map[10 * (spot / 10) + 5 + k][5 * (spot % 10) - 1 +
                                                                    l] = position[i][j][1]->card[k][l];
                            }
                        }
                    } else {
                        for (int k = 0; k < 6; ++k) {
                            for (int l = 0; l < 5; ++l) {
                                print_map[10 * (spot / 10) + 5 + k][5 * (spot % 10) - 1 +
                                                                    l] = position[i][j][1]->card[k][l];
                            }
                        }
                    }
                } else {
                    for (int k = 0; k < 10; ++k) {
                        for (int l = 0; l < 5; ++l) {
                            print_map[10 * (spot / 10) + 5 + k][5 * (spot % 10) - 1 +
                                                                l] = position[i][j][1]->card[k][l];
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < row; ++i) // 先打印最底层的地图
    {
        for (int j = 0; j < column; ++j) {
            if (position[i][j][0] != NULL) // a层这里有卡牌
            {
                int spot = 10 * i + j;
                for (int k = 0; k < 10; ++k) {
                    for (int l = 0; l < 5; ++l) {
                        print_map[10 * (spot / 10) + 1 + k][5 * (spot % 10) + 1 + l] = position[i][j][0]->card[k][l];
                    }
                }
            }
        }
    }
}

void PrintMap(int temp_x, int temp_y) {
    for (int i = 0; i < map_size; ++i) // 打印地图
    {
        for (int j = 0; j < map_size; ++j) {
            if (print_map[i][j] != '\0') // 非空格，需要更换颜色
            {
                // int k = ((i - 1) / 10) * 10 + (j - 1) / 5;//从坐标对应回位点编号
                if (i == 0 || i == map_size - 1 || j == 0 || j == map_size - 1) // 边框
                {
                    color(6);
                } else if ((i - 1) / 10 == temp_x && (j - 1) / 5 == temp_y &&//表示现在打印的这个坐标在我们所选标红卡牌范围内
                           IsTop(i - 1, j - 1) == a)//a层
                {
                    color(4);//被选中的为红色
                } else if (i >= 5 && (i - 5) / 10 == temp_x && (j + 1) / 5 == temp_y &&
                           IsTop(i - 1, j - 1) == b)//说明是b层
                {
                    color(4);//被选中的为红色
                } else if ((i - 1) / 10 == temp_x && (j - 1) / 5 == temp_y && IsTop(i - 1, j - 1) == c) {
                    color(4);//被选中的为红色
                } else if (IsTop(i - 1, j - 1) != 'f')// 说明这时打印的是最上层的牌
                {
                    color(15); // 最上层为黑色
                } else {
                    color(14); // 下层为浅黄色，表示遮挡关系
                }
                printf("%c", print_map[i][j]);
            } else
                printf(" ");
        }
        printf("\n");
    }
    printf("\n");
    //打印卡槽
    for (int i = 0; i < chance; ++i) {
        if (chosen_card[i] == 11) {
            printf("_  ");
        } else {
            printf("%d  ", chosen_card[i]);
        }
    }
    printf("\n");
}

void PaintCard(Card *cur) {
    for (int i = 0; i < 5; ++i) {
        cur->card[0][i] = cur->card[9][i] = '-';
    }
    for (int j = 1; j < 9; ++j) {
        cur->card[j][0] = cur->card[j][4] = '|';
    }
    int kind;
    kind = rand() % 10;
    cur->card[5][2] = kind + 48;
    cur->index = kind;
}

void Initialize() {
    for (int k = 0; k < map_num; ++k) {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                position[i][j][k] = NULL;
                top[i][j] = false;
            }
        }
    }
    for (int i = 0; i < chance; ++i) {
        chosen_card[i] = 11;
    }
    for (int i = 0; i < 12; ++i) {
        check[i] = 0;
    }
    // map_initialize
    for (int i = 0; i < spot_num; ++i) {
        position_a[i] = position_b[i] = position_c[i] = false;//没放牌
    }
    // 每张地图分别画几张卡牌(25-35)
    srand((unsigned) time(NULL));
    a_size = rand() % 11 + 25;
    b_size = rand() % 11 + 25;
    c_size = rand() % 11 + 25;
    total = a_size + b_size + c_size;
    // 在地图上随机位点生成size张卡牌
    int counter = 0;
    for (; counter < a_size;) {
        Card *cur_card = new_card();
        int k = rand() % spot_num; // k表示位点数（第几个位点）
        if (!position_a[k]) {
            position[k / 10][k % 10][0] = cur_card;
            PaintCard(cur_card);
            counter++;
            position_a[k] = true;
        } else
            continue;
    }
    counter = 0;
    for (; counter < b_size;) {
        Card *cur_card = new_card();
        int k = rand() % spot_num; // k表示位点数（第几个位点）
        if (!position_b[k]) {
            position[k / 10][k % 10][1] = cur_card;
            PaintCard(cur_card);
            counter++;
            position_b[k] = true;
        } else
            continue;
    }
    counter = 0;
    for (; counter < c_size;) {
        Card *cur_card = new_card();
        int k = rand() % spot_num; // k表示位点数（第几个位点）
        if (!position_c[k]) {
            position[k / 10][k % 10][2] = cur_card;
            PaintCard(cur_card);
            counter++;
            position_c[k] = true;
        } else
            continue;
    }
    InitPrintMap();
    PrintMap(row, column);
}