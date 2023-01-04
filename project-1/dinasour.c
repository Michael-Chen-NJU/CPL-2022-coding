//
// Created by HW on 2022/12/1.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

SDL_Event MainEvent;//主事件文档

//函数区
void LOAD_Main();

void LOAD_Dino(int x, int y, char *a);

void LOAD_Bird(int x, int y, char *a);

void LOAD_Cloud1(int x, int y);

void LOAD_Cloud2(int x, int y);

void LOAD_Cloud3(int x, int y);

void LOAD_Cactus1(int x, int y);

void LOAD_Cactus2(int x, int y);

void LOAD_PlayMain();

void LOAD_OBS();

int UP();

int DOWN();

int up(int i);

int down(int i);

void LOAD_Score(const char *a);

void LOAD_Score_();

void LOAD_PAUSE();

void Wait_to_Continue();

void Wait_to_Return();

void LOAD_GO();

void QUIT();

void PLAY();

void PLAY_WOD();

int RUN();

void PLAYMAIN();

void Score_Increase();

void TIME(double a);

int HIT();

int HIT2();

void GAME_OVER();

int random(int a, int b);

void judge_x();

//参数区
int count_jump = 0;
int count_play = 0;
int is_playing = 0;
int dino_x = 80;
int dino_y = 215;
int bird_x = 800;
int bird_y = 190;
int cloud_1_x = 900;
int cloud_2_x = 500;
int cloud_3_x = 200;
int cactus_1_x = 850;
int cactus_2_x = 1250;
char score_num[9999] = "0";
int history_score[100] = {0};
int highest_score = 0;
char p_highest_score[1000] = "0";

//定义一个窗口和画笔，并初始化
SDL_Window *Window = NULL;
SDL_Renderer *Renderer = NULL;

//定义一个背景以及它的纹理、大小
SDL_Surface *MainBackGroundSurface = NULL;
SDL_Texture *MainBackGroundTexture = NULL;
SDL_Rect MainBackGroundRect;

//定义小恐龙以及它的纹理、大小
SDL_Surface *DinoSurface = NULL;
SDL_Texture *DinoTexture = NULL;
SDL_Rect DinoRect;

//定义云朵1以及它的纹理、大小
SDL_Surface *Cloud1Surface = NULL;
SDL_Texture *Cloud1Texture = NULL;
SDL_Rect Cloud1Rect;

//定义云朵2以及它的纹理、大小
SDL_Surface *Cloud2Surface = NULL;
SDL_Texture *Cloud2Texture = NULL;
SDL_Rect Cloud2Rect;

//定义云朵3以及它的纹理、大小
SDL_Surface *Cloud3Surface = NULL;
SDL_Texture *Cloud3Texture = NULL;
SDL_Rect Cloud3Rect;

//定义仙人掌1以及它的纹理、大小
SDL_Surface *Cactus1Surface = NULL;
SDL_Texture *Cactus1Texture = NULL;
SDL_Rect Cactus1Rect;

//定义仙人掌2
SDL_Surface *Cactus2Surface = NULL;
SDL_Texture *Cactus2Texture = NULL;
SDL_Rect Cactus2Rect;

//定义下蹲动作
SDL_Surface *DownSurface = NULL;
SDL_Texture *DownTexture = NULL;
SDL_Rect DownRect;

//定义飞鸟
SDL_Surface *BirdSurface = NULL;
SDL_Texture *BirdTexture = NULL;
SDL_Rect BirdRect;

//定义开始界面的背景以及它的纹理、大小
SDL_Surface *PlayBackGroundSurface = NULL;
SDL_Texture *PlayBackGroundTexture = NULL;
SDL_Rect PlayBackGroundRect;

//定义暂停键
SDL_Surface *PauseSurface = NULL;
SDL_Texture *PauseTexture = NULL;
SDL_Rect PauseRect;

//定义继续键
SDL_Surface *GoSurface = NULL;
SDL_Texture *GoTexture = NULL;
SDL_Rect GoRect;

//定义分数的字体、颜色等
TTF_Font *Scorefont = NULL;
SDL_Surface *ScoreSurface = NULL;
SDL_Texture *ScoreTexture = NULL;
SDL_Rect ScoreRect;
SDL_Color FontColor = {0, 0, 0, 233};
//定义score
TTF_Font *Score_font = NULL;
SDL_Surface *Score_Surface = NULL;
SDL_Texture *Score_Texture = NULL;
SDL_Rect Score_Rect;
SDL_Color Font_Color = {0, 0, 0, 233};

//定义highset score
TTF_Font *HI_Score_font = NULL;
SDL_Surface *HI_Score_Surface = NULL;
SDL_Texture *HI_Score_Texture = NULL;
SDL_Rect HI_Score_Rect;
SDL_Color HI_Font_Color = {0, 0, 0, 233};

//定义“HIGHST"
TTF_Font *HI_font = NULL;
SDL_Surface *HI_Surface = NULL;
SDL_Texture *HI_Texture = NULL;
SDL_Rect HI_Rect;
SDL_Color HI_Color = {0, 0, 0, 233};

//定义game over
TTF_Font *Overfont = NULL;
SDL_Surface *OverSurface = NULL;
SDL_Texture *OverTexture = NULL;
SDL_Rect OverRect;
SDL_Color OverColor = {0, 0, 0, 233};

//定义press here to restart
TTF_Font *Over_font = NULL;
SDL_Surface *Over_Surface = NULL;
SDL_Texture *Over_Texture = NULL;
SDL_Rect Over_Rect;
SDL_Color Over_Color = {0, 0, 0, 233};

char *background = "firstback.png";
char *dino1 = "standdino.png";
char *dino2 = "standdino2.png";
char *playback = "background.png";
char *cloud1 = "cloud.png";
char *cloud2 = "cloud.png";
char *cloud3 = "cloud.png";
char *cactus1 = "cactus1.png";
char *cactus2 = "cactus2.png";
char *score = "ScoreFont.ttf";
char *pause = "pause.png";
char *go_on = "go_on.png";
char *down1 = "Dino3.png";
char *down2 = "Dino4.png";
char *bird1 = "HighBird1.png";
char *bird2 = "HighBird2.png";

int SDL_main(int argc, char *argv[]) {
    //窗口初始化
    SDL_Init(SDL_INIT_VIDEO);//初始化库
    TTF_Init();
    Window = SDL_CreateWindow("Dinasour", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 412, SDL_WINDOW_SHOWN);
    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);

    //加载两个背景
    LOAD_Main();
    LOAD_PlayMain();


    //打印窗口
    SDL_RenderClear(Renderer);//当前画笔清空
    SDL_RenderCopy(Renderer, MainBackGroundTexture, NULL, &MainBackGroundRect);
    SDL_RenderPresent(Renderer);//刷新画笔
    //Sleep(100000);

    //交互
    while (SDL_WaitEvent(&MainEvent)) {
        switch (MainEvent.type) {
            case SDL_QUIT:
                QUIT();
                break;
            case SDL_KEYDOWN:
                switch (MainEvent.key.keysym.sym) {
                    case SDLK_SPACE:
                        printf("You are in the Play 1!\n");
                        is_playing = 1;
                        PLAYMAIN();
                    case SDLK_ESCAPE: {
                        QUIT();
                    }
                }
            case SDL_MOUSEBUTTONUP:
                printf("(%d,%d)\n", MainEvent.button.x, MainEvent.button.y);
                if (MainEvent.button.x > 356 && MainEvent.button.x < 444 && MainEvent.button.y > 153 &&
                    MainEvent.button.y < 241) {
                    printf("You are in the Play 1!\n");
                    is_playing = 1;
                    PLAYMAIN();
                } else if (MainEvent.button.x > 583 && MainEvent.button.x < 673 && MainEvent.button.y > 152 &&
                           MainEvent.button.y < 242) {
                    printf("You are in the RANKING!\n");
                    HI_font = TTF_OpenFont(score, 50);
                    HI_Surface = TTF_RenderUTF8_Blended(HI_font, "YOUR HIGHEST SCORE IS", HI_Color);
                    HI_Texture = SDL_CreateTextureFromSurface(Renderer, HI_Surface);
                    HI_Rect.x = 205;
                    HI_Rect.y = 90;
                    HI_Rect.w = 450;//宽
                    HI_Rect.h = 60;
                    HI_Score_font = TTF_OpenFont(score, 50);
                    HI_Score_Surface = TTF_RenderUTF8_Blended(HI_Score_font, p_highest_score, HI_Font_Color);
                    HI_Score_Texture = SDL_CreateTextureFromSurface(Renderer, HI_Score_Surface);
                    HI_Score_Rect.x = 368;
                    HI_Score_Rect.y = 168;
                    for (int i = 1; i < 10; ++i) {
                        if (p_highest_score[i] == '\0') {
                            HI_Score_Rect.w = 25 * i;
                            break;
                        }
                    }
                    HI_Score_Rect.h = 50;

                    Over_font = TTF_OpenFont(score, 50);
                    Over_Surface = TTF_RenderUTF8_Blended(Over_font, "Press Here To Return", Over_Color);
                    Over_Texture = SDL_CreateTextureFromSurface(Renderer, Over_Surface);
                    Over_Rect.x = 250;
                    Over_Rect.y = 280;
                    Over_Rect.w = 300;//宽
                    Over_Rect.h = 35;
                    SDL_RenderClear(Renderer);//当前画笔清空
                    SDL_RenderCopy(Renderer, PlayBackGroundTexture, NULL, &PlayBackGroundRect);
                    SDL_RenderCopy(Renderer, HI_Texture, NULL, &HI_Rect);
                    SDL_RenderCopy(Renderer, HI_Score_Texture, NULL, &HI_Score_Rect);
                    //SDL_RenderCopy(Renderer,PlayBackGroundTexture,NULL,&PlayBackGroundRect);
                    SDL_RenderCopy(Renderer, Over_Texture, NULL, &Over_Rect);
                    SDL_RenderPresent(Renderer);

                    //写一个wait_to_return的函数
                    Wait_to_Return();
                    //Sleep(10000);
                }
                break;
            default:
                break;
        }
    }

    QUIT();
}

void PLAYMAIN() {
    //参数画面归零
    count_jump = 0;
    //is_playing = 0;
    dino_x = 80;
    dino_y = 215;
    cloud_1_x = 900;
    cloud_2_x = 500;
    cloud_3_x = 200;
    cactus_1_x = 820;
    cactus_2_x = 1150;
    bird_x = 1900;
    bird_y = random(120, 250);
    for (int i = 0; i < 100; ++i) {
        score_num[i] = '0';
    }
    while (1) {
        while (SDL_PollEvent(&MainEvent)) {
            switch (MainEvent.type) {
                case SDL_QUIT:
                    QUIT();
                    break;
                case SDL_MOUSEBUTTONUP:
                    printf("(%d,%d)\n", MainEvent.button.x, MainEvent.button.y);
                    if (MainEvent.button.x > 0 && MainEvent.button.x < 50 && MainEvent.button.y > 0 &&
                        MainEvent.button.y < 50) {
                        LOAD_GO();
                        SDL_RenderClear(Renderer);//当前画笔清空
                        SDL_RenderCopy(Renderer, PlayBackGroundTexture, NULL, &PlayBackGroundRect);
                        SDL_RenderCopy(Renderer, GoTexture, NULL, &GoRect);
                        SDL_RenderPresent(Renderer);
                        Wait_to_Continue();
                        //PLAYMAIN();
                    }
                    break;
                case SDL_KEYDOWN:
                    switch (MainEvent.key.keysym.sym) {
                        case SDLK_RETURN:
                            PLAY();
                            break;
                        case SDLK_ESCAPE:
                            SDL_RenderClear(Renderer);//当前画笔清空
                            SDL_RenderCopy(Renderer, MainBackGroundTexture, NULL, &MainBackGroundRect);
                            SDL_RenderPresent(Renderer);
                            QUIT();
                            break;
                        case SDLK_DOWN:
                            if (DOWN() == 0) {
                                return;
                            } else {
                                break;
                            }
                        case SDLK_SPACE:
                            if (UP() == 0) {
                                return;
                            } else {
                                break;
                            }
                        case SDLK_UP:
                            if (UP() == 0) {
                                return;
                            } else {
                                break;
                            }
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
        if (is_playing == 1) {
            if (RUN() == 0) {
                return;
            }
        }
    }
}


void Wait_to_Continue() {
    while (SDL_WaitEvent(&MainEvent)) {
        switch (MainEvent.type) {
            case SDLK_ESCAPE: {
                QUIT();
            }
            case SDL_QUIT:
                QUIT();
                break;
            case SDL_MOUSEBUTTONUP:
                if (MainEvent.button.x > 425 && MainEvent.button.x < 525 && MainEvent.button.y > 110 &&
                    MainEvent.button.y < 214) {
                    printf("You are in the Play 2!\n");
                    is_playing = 1;
                    SDL_RenderClear(Renderer);//当前画笔清空
                    SDL_RenderCopy(Renderer, PlayBackGroundTexture, NULL, &PlayBackGroundRect);
                    SDL_RenderCopy(Renderer, DinoTexture, NULL, &DinoRect);
                    SDL_RenderCopy(Renderer, Cloud1Texture, NULL, &Cloud1Rect);
                    SDL_RenderCopy(Renderer, Cloud2Texture, NULL, &Cloud2Rect);
                    SDL_RenderCopy(Renderer, Cloud3Texture, NULL, &Cloud3Rect);
                    SDL_RenderCopy(Renderer, Cactus1Texture, NULL, &Cactus1Rect);
                    SDL_RenderCopy(Renderer, Cactus2Texture, NULL, &Cactus2Rect);
                    SDL_RenderCopy(Renderer, ScoreTexture, NULL, &ScoreRect);
                    SDL_RenderCopy(Renderer, Score_Texture, NULL, &Score_Rect);
                    SDL_RenderCopy(Renderer, PauseTexture, NULL, &PauseRect);
                    SDL_RenderPresent(Renderer);
                    return;
                }
        }
    }
}

void Wait_to_Return() {
    while (SDL_WaitEvent(&MainEvent)) {
        switch (MainEvent.type) {
            case SDLK_ESCAPE: {
                QUIT();
            }
            case SDL_QUIT:
                QUIT();
                break;
            case SDL_MOUSEBUTTONUP:
                if (MainEvent.button.x > 250 && MainEvent.button.x < 630 && MainEvent.button.y > 280 &&
                    MainEvent.button.y < 315) {
                    printf("You are in the Play 2!\n");
                    is_playing = 1;
                    SDL_RenderClear(Renderer);//当前画笔清空
                    SDL_RenderCopy(Renderer, MainBackGroundTexture, NULL, &MainBackGroundRect);
                    SDL_RenderPresent(Renderer);
                    return;
                }
        }
    }
}

//加载图片
void LOAD_Main() {
    MainBackGroundSurface = IMG_Load(background);
    MainBackGroundTexture = SDL_CreateTextureFromSurface(Renderer, MainBackGroundSurface);
    //图片转换成纹理
    MainBackGroundRect.x = 0;
    MainBackGroundRect.y = 0;
    MainBackGroundRect.w = MainBackGroundSurface->w;//宽
    MainBackGroundRect.h = MainBackGroundSurface->h;//高
}

void LOAD_Dino(int x, int y, char *a) {
    //加载小恐龙
    DinoSurface = IMG_Load(a);
    DinoTexture = SDL_CreateTextureFromSurface(Renderer, DinoSurface);
    //图片转换成纹理
    DinoRect.x = x;
    DinoRect.y = y;
    DinoRect.w = DinoSurface->w;//宽
    DinoRect.h = DinoSurface->h;
}

void LOAD_Bird(int x, int y, char *a) {
    BirdSurface = IMG_Load(a);
    BirdTexture = SDL_CreateTextureFromSurface(Renderer, BirdSurface);
    //图片转换成纹理
    BirdRect.x = x;
    BirdRect.y = y;
    BirdRect.w = BirdSurface->w;//宽
    BirdRect.h = BirdSurface->h;
}

void LOAD_PlayMain() {
    //加载游戏背景
    PlayBackGroundSurface = IMG_Load(playback);
    PlayBackGroundTexture = SDL_CreateTextureFromSurface(Renderer, PlayBackGroundSurface);
    //图片转换成纹理
    PlayBackGroundRect.x = 0;
    PlayBackGroundRect.y = 0;
    PlayBackGroundRect.w = PlayBackGroundSurface->w;//宽
    PlayBackGroundRect.h = PlayBackGroundSurface->h;//高
}

void LOAD_Cloud1(int x, int y) {
    Cloud1Surface = IMG_Load(cloud1);
    Cloud1Texture = SDL_CreateTextureFromSurface(Renderer, Cloud1Surface);
    //图片转换成纹理
    Cloud1Rect.x = x;
    Cloud1Rect.y = y;
    Cloud1Rect.w = Cloud1Surface->w;//宽
    Cloud1Rect.h = Cloud1Surface->h;
}

void LOAD_Cloud2(int x, int y) {
    Cloud2Surface = IMG_Load(cloud2);
    Cloud2Texture = SDL_CreateTextureFromSurface(Renderer, Cloud2Surface);
    //图片转换成纹理
    Cloud2Rect.x = x;
    Cloud2Rect.y = y;
    Cloud2Rect.w = Cloud2Surface->w;//宽
    Cloud2Rect.h = Cloud2Surface->h;
}

void LOAD_Cloud3(int x, int y) {
    Cloud3Surface = IMG_Load(cloud3);
    Cloud3Texture = SDL_CreateTextureFromSurface(Renderer, Cloud3Surface);
    //图片转换成纹理
    Cloud3Rect.x = x;
    Cloud3Rect.y = y;
    Cloud3Rect.w = Cloud3Surface->w;//宽
    Cloud3Rect.h = Cloud3Surface->h;
}

void LOAD_Cactus1(int x, int y) {
    Cactus1Surface = IMG_Load(cactus1);
    Cactus1Texture = SDL_CreateTextureFromSurface(Renderer, Cactus1Surface);
    //图片转换成纹理
    Cactus1Rect.x = x;
    Cactus1Rect.y = y;
    Cactus1Rect.w = Cactus1Surface->w;//宽
    Cactus1Rect.h = Cactus1Surface->h;
}

void LOAD_Cactus2(int x, int y) {
    Cactus2Surface = IMG_Load(cactus2);
    Cactus2Texture = SDL_CreateTextureFromSurface(Renderer, Cactus2Surface);
    //图片转换成纹理
    Cactus2Rect.x = x;
    Cactus2Rect.y = y;
    Cactus2Rect.w = Cactus2Surface->w;//宽
    Cactus2Rect.h = Cactus2Surface->h;
}

void LOAD_Score(const char *a) {
    Scorefont = TTF_OpenFont(score, 50);
    ScoreSurface = TTF_RenderUTF8_Blended(Scorefont, a, FontColor);
    ScoreTexture = SDL_CreateTextureFromSurface(Renderer, ScoreSurface);
    ScoreRect.x = 680;
    ScoreRect.y = 46;
    for (int i = 1; i < 10; ++i) {
        if (*(a + i) == '\0') {
            ScoreRect.w = 15 * i;
            break;
        }
    }
    ScoreRect.h = 30;
}

void LOAD_Score_() {
    Score_font = TTF_OpenFont(score, 50);
    Score_Surface = TTF_RenderUTF8_Blended(Score_font, "SCORE", Font_Color);
    Score_Texture = SDL_CreateTextureFromSurface(Renderer, Score_Surface);
    Score_Rect.x = 600;
    Score_Rect.y = 46;
    Score_Rect.w = 70;//宽
    Score_Rect.h = 30;
}

void Score_Increase() {
    int score_i = atoi(score_num);
    score_i += 3;
    itoa(score_i, score_num, 10);
}

int down(int i) {
    PLAY_WOD();
    if (i % 2 == 0) {
        LOAD_Dino(dino_x, dino_y, down1);
        LOAD_Bird(bird_x, bird_y, bird2);
    } else {
        LOAD_Dino(dino_x, dino_y, down2);
        LOAD_Bird(bird_x, bird_y, bird1);
    }
    if (HIT2() == 0) {
        return 0;
    }
    LOAD_OBS();
    LOAD_Cloud1(cloud_1_x, 80);
    LOAD_Cloud2(cloud_2_x, 110);
    LOAD_Cloud3(cloud_3_x, 10);
    cloud_1_x -= 5;
    cloud_2_x -= 5;
    cloud_3_x -= 5;
    if (atoi(score_num) >= 1000 && atoi(score_num) <= 5000) {
        TIME(0.08);
    } else if (atoi(score_num) > 5000) {
        TIME(0.05);
    } else {
        TIME(0.1);
    }
    return 1;
}

int DOWN() {
    is_playing = 0;
    dino_x -= 8;
    dino_y += 13;
    for (int i = 0; i < 14; ++i) {
        if (down(i) == 0) {
            return 0;
        }
    }
    dino_x += 8;
    dino_y -= 13;
    is_playing = 1;
    return 1;
}

int up(int i) {
    if (i < 9) {
        dino_y -= 15;
    } else {
        dino_y += 15;
    }
    PLAY_WOD();
    if (i % 2 == 0) {
        LOAD_Dino(dino_x, dino_y, dino2);
        LOAD_Bird(bird_x, bird_y, bird2);
    } else {
        LOAD_Dino(dino_x, dino_y, dino1);
        LOAD_Bird(bird_x, bird_y, bird1);
    }
    if (HIT() == 0) {
        return 0;
    }
    LOAD_OBS();
    LOAD_Cloud1(cloud_1_x, 80);
    LOAD_Cloud2(cloud_2_x, 110);
    LOAD_Cloud3(cloud_3_x, 10);
    cloud_1_x -= 5;
    cloud_2_x -= 5;
    cloud_3_x -= 5;
    if (atoi(score_num) >= 1000 && atoi(score_num) <= 5000) {
        TIME(0.08);
    } else if (atoi(score_num) > 5000) {
        TIME(0.05);
    } else {
        TIME(0.1);
    }
    return 1;
}

int UP() {
    printf("%d\n", count_jump);
    count_jump++;
    is_playing = 0;
    for (int i = 0; i < 18; ++i) {
        if (up(i) == 0) {
            return 0;
        }
    }
    is_playing = 1;
    return 1;
}

void TIME(double a) {
    double eps = 75e-4;
    clock_t start, finish;
    double duration;
    /* 测量一个事件持续的时间*/
    start = clock();
    while (1) {

        SDL_RenderCopy(Renderer, DinoTexture, NULL, &DinoRect);
        SDL_RenderPresent(Renderer);

        finish = clock();
        duration = (double) (finish - start) / CLOCKS_PER_SEC;
        if (fabs(duration - a) <= eps) {
            LOAD_OBS();
            //只需加入树和分数在移动的函数即可
            SDL_RenderCopy(Renderer, Cactus1Texture, NULL, &Cactus1Rect);
            SDL_RenderCopy(Renderer, Cactus2Texture, NULL, &Cactus2Rect);
            SDL_RenderCopy(Renderer, BirdTexture, NULL, &BirdRect);
            SDL_RenderCopy(Renderer, ScoreTexture, NULL, &ScoreRect);
            SDL_RenderPresent(Renderer);
        }
        if (fabs(duration - a) <= eps) {
            break;
        }
    }
    printf("%f seconds ", duration);
}

int random(int a, int b) {
    int lower = a, upper = b;
    srand(time(0));
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

void PLAY() {
    SDL_RenderClear(Renderer);//当前画笔清空
    SDL_RenderCopy(Renderer, PlayBackGroundTexture, NULL, &PlayBackGroundRect);
    SDL_RenderCopy(Renderer, DinoTexture, NULL, &DinoRect);
    SDL_RenderCopy(Renderer, Cloud1Texture, NULL, &Cloud1Rect);
    SDL_RenderCopy(Renderer, Cloud2Texture, NULL, &Cloud2Rect);
    SDL_RenderCopy(Renderer, Cloud3Texture, NULL, &Cloud3Rect);
    SDL_RenderCopy(Renderer, Cactus1Texture, NULL, &Cactus1Rect);
    SDL_RenderCopy(Renderer, Cactus2Texture, NULL, &Cactus2Rect);
    SDL_RenderCopy(Renderer, Cactus2Texture, NULL, &Cactus2Rect);
    SDL_RenderCopy(Renderer, ScoreTexture, NULL, &ScoreRect);
    SDL_RenderCopy(Renderer, Score_Texture, NULL, &Score_Rect);
    SDL_RenderCopy(Renderer, BirdTexture, NULL, &BirdRect);
    SDL_RenderCopy(Renderer, PauseTexture, NULL, &PauseRect);
    SDL_RenderPresent(Renderer);
}

//打印除了小恐龙之外的画面
void PLAY_WOD() {
    SDL_RenderClear(Renderer);//当前画笔清空
    SDL_RenderCopy(Renderer, PlayBackGroundTexture, NULL, &PlayBackGroundRect);
    SDL_RenderPresent(Renderer);
    SDL_RenderCopy(Renderer, Cloud1Texture, NULL, &Cloud1Rect);
    SDL_RenderCopy(Renderer, Cloud2Texture, NULL, &Cloud2Rect);
    SDL_RenderCopy(Renderer, Cloud3Texture, NULL, &Cloud3Rect);
    SDL_RenderCopy(Renderer, Cactus1Texture, NULL, &Cactus1Rect);
    SDL_RenderCopy(Renderer, Cactus2Texture, NULL, &Cactus2Rect);
    SDL_RenderCopy(Renderer, BirdTexture, NULL, &BirdRect);
    SDL_RenderCopy(Renderer, ScoreTexture, NULL, &ScoreRect);
    SDL_RenderCopy(Renderer, Score_Texture, NULL, &Score_Rect);
    SDL_RenderCopy(Renderer, PauseTexture, NULL, &PauseRect);
    SDL_RenderPresent(Renderer);
}

void LOAD_OBS() {
    Score_Increase();
    LOAD_Score(score_num);
    LOAD_Score_();
    cactus_1_x -= 5;
    cactus_2_x -= 5;
    bird_x -= 5;
    LOAD_Cactus1(cactus_1_x, 203);
    LOAD_Cactus2(cactus_2_x, 203);
    PLAY();
}

int RUN() {
    int count_run = 0;
    //左移一遍
    Score_Increase();
    LOAD_Score(score_num);
    LOAD_PAUSE();
    LOAD_Score_();
    LOAD_Dino(dino_x, dino_y, dino1);
    if (HIT() == 0) {
        return 0;
    }
    LOAD_Cloud1(cloud_1_x, 80);
    LOAD_Cloud2(cloud_2_x, 110);
    LOAD_Cloud3(cloud_3_x, 10);
    LOAD_Cactus1(cactus_1_x, 203);
    LOAD_Cactus2(cactus_2_x, 203);
    LOAD_Bird(bird_x, bird_y, bird1);
    cloud_1_x -= 5;
    cloud_2_x -= 5;
    cloud_3_x -= 5;
    cactus_1_x -= 5;
    cactus_2_x -= 5;
    bird_x -= 5;
    PLAY();
    if (atoi(score_num) >= 1000 && atoi(score_num) <= 5000) {
        TIME(0.08);
    } else if (atoi(score_num) > 5000) {
        TIME(0.05);
    } else {
        TIME(0.1);
    }
    count_run++;
    printf("%d\n", count_run);
    //第二遍
    Score_Increase();
    LOAD_Score(score_num);
    LOAD_Dino(dino_x, dino_y, dino2);
    if (HIT() == 0) {
        return 0;
    }
    LOAD_Cloud1(cloud_1_x, 80);
    LOAD_Cloud2(cloud_2_x, 110);
    LOAD_Cloud3(cloud_3_x, 10);
    LOAD_Cactus1(cactus_1_x, 203);
    LOAD_Cactus2(cactus_2_x, 203);
    LOAD_Bird(bird_x, bird_y, bird2);
    cloud_1_x -= 5;
    cloud_2_x -= 5;
    cloud_3_x -= 5;
    cactus_1_x -= 5;
    cactus_2_x -= 5;
    bird_x -= 5;
    if (cloud_1_x <= -100) {
        cloud_1_x = 1000;
    }
    if (cloud_2_x <= -100) {
        cloud_2_x = 1000;
    }
    if (cloud_3_x <= -100) {
        cloud_3_x = 1000;
    }
    //随机生成1到3中的一个数字
    if (cactus_1_x <= -10) {
        cactus_1_x = random(1000, 2000);
        judge_x();
    }
    if (cactus_2_x <= -10) {
        cactus_2_x = random(1000, 2000);
        judge_x();
    }
    if (bird_x <= -10) {
        bird_x = random(1000, 2000);
        bird_y = random(120, 250);
        judge_x();
    }

    PLAY();
    if (atoi(score_num) >= 1000 && atoi(score_num) <= 5000) {
        TIME(0.08);
    } else if (atoi(score_num) > 5000) {
        TIME(0.05);
    } else {
        TIME(0.1);
    }
    count_run++;
    printf("%d\n", count_run);
    return 1;
}

void judge_x() {
    for (int i = 0; i < 10000; ++i) {
        if (abs(cactus_1_x - cactus_2_x) <= 300 && cactus_1_x > 1000 && cactus_2_x > 1000) {
            cactus_1_x = random(1000, 2000);
            cactus_2_x = random(1000, 2000);
        } else if (abs(cactus_2_x - bird_x) <= 300 && bird_x > 1000 && cactus_2_x > 1000) {
            cactus_2_x = random(1000, 2000);
            bird_x = random(1600, 2000);
            bird_y = random(120, 250);
        } else if (abs(cactus_1_x - bird_x) <= 300 && bird_x > 1000 && cactus_1_x > 1000) {
            cactus_1_x = random(1000, 2000);
            bird_x = random(1600, 2000);
            bird_y = random(120, 250);
        } else {
            break;
        }
    }
}

int HIT() {
    //奔跑和跳起时候的碰撞判定
    //右上角接触仙人掌
    if (((dino_x + 42) > cactus_1_x && (dino_x + 42) < (cactus_1_x + 29) && dino_y > 203 && dino_y < 259) ||
        ((dino_x + 42) > cactus_2_x && (dino_x + 42) < (cactus_2_x + 29) && dino_y > 203 && dino_y < 259) ||
        ((dino_x + 42) > bird_x && (dino_x + 42) < (bird_x + 40) && dino_y > bird_y && dino_y < (bird_y + 28))) {
        GAME_OVER();
        return 0;
    }
        //左上角接触仙人掌
    else if ((dino_x > cactus_1_x && dino_x < (cactus_1_x + 29) && dino_y > 203 && dino_y < 259) ||
             (dino_x > cactus_2_x && dino_x < (cactus_2_x + 29) && dino_y > 203 && dino_y < 259) ||
             (dino_x > bird_x && dino_x < (bird_x + 40) && dino_y > bird_y && dino_y < (bird_y + 28))) {
        GAME_OVER();
        return 0;
    }
        //右下角接触仙人掌
    else if (((dino_x + 42) > cactus_1_x && (dino_x + 42) < (cactus_1_x + 29) && (dino_y + 40) > 203 &&
              (dino_y + 40) < 259) ||
             ((dino_x + 42) > cactus_2_x && (dino_x + 42) < (cactus_2_x + 29) && (dino_y + 40) > 203 &&
              (dino_y + 40) < 259) ||
             ((dino_x + 42) > bird_x && (dino_x + 42) < (bird_x + 40) && (dino_y + 40) > bird_y &&
              (dino_y + 40) < (bird_y + 28))) {
        GAME_OVER();
        return 0;
    }
        //左下角接触仙人掌
    else if ((dino_x > cactus_1_x && dino_x < (cactus_1_x + 29) && (dino_y + 40) > 203 && (dino_y + 40) < 259) ||
             (dino_x > cactus_2_x && dino_x < (cactus_2_x + 29) && (dino_y + 40) > 203 && (dino_y + 40) < 259) ||
             (dino_x > bird_x && dino_x < (bird_x + 40) && (dino_y + 40) > bird_y && (dino_y + 40) < (bird_y + 28))) {
        GAME_OVER();
        return 0;
    } else {
        return 1;
    }
}

int HIT2() {
    //下蹲时候的碰撞判定
    //右上角接触仙人掌
    if (((dino_x + 55) > cactus_1_x && (dino_x + 55) < (cactus_1_x + 29) && dino_y > 203 && dino_y < 259) ||
        ((dino_x + 55) > cactus_2_x && (dino_x + 55) < (cactus_2_x + 29) && dino_y > 203 && dino_y < 259) ||
        ((dino_x + 55) > bird_x && (dino_x + 55) < (bird_x + 40) && dino_y > bird_y && dino_y < (bird_y + 28))) {
        GAME_OVER();
        return 0;
    }
        //左上角接触仙人掌
    else if ((dino_x > cactus_1_x && dino_x < (cactus_1_x + 29) && dino_y > 203 && dino_y < 259) ||
             (dino_x > cactus_2_x && dino_x < (cactus_2_x + 29) && dino_y > 203 && dino_y < 259) ||
             (dino_x > bird_x && dino_x < (bird_x + 40) && dino_y > bird_y && dino_y < (bird_y + 28))) {
        GAME_OVER();
        return 0;
    }
        //右下角接触仙人掌
    else if (((dino_x + 55) > cactus_1_x && (dino_x + 55) < (cactus_1_x + 29) && (dino_y + 29) > 203 &&
              (dino_y + 29) < 259) ||
             ((dino_x + 55) > cactus_2_x && (dino_x + 55) < (cactus_2_x + 29) && (dino_y + 29) > 203 &&
              (dino_y + 29) < 259) ||
             ((dino_x + 55) > bird_x && (dino_x + 55) < (bird_x + 40) && (dino_y + 29) > bird_y &&
              (dino_y + 29) < (bird_y + 28))) {
        GAME_OVER();
        return 0;
    }
        //左下角接触仙人掌
    else if ((dino_x > cactus_1_x && dino_x < (cactus_1_x + 29) && (dino_y + 29) > 203 && (dino_y + 29) < 259) ||
             (dino_x > cactus_2_x && dino_x < (cactus_2_x + 29) && (dino_y + 29) > 203 && (dino_y + 29) < 259) ||
             (dino_x > bird_x && dino_x < (bird_x + 40) && (dino_y + 29) > bird_y && (dino_y + 29) < (bird_y + 28))) {
        GAME_OVER();
        return 0;
    } else {
        return 1;
    }
}

void LOAD_PAUSE() {
    PauseSurface = IMG_Load(pause);
    PauseTexture = SDL_CreateTextureFromSurface(Renderer, PauseSurface);
    //图片转换成纹理
    PauseRect.x = 0;
    PauseRect.y = 0;
    PauseRect.w = PauseSurface->w;//宽
    PauseRect.h = PauseSurface->h;//高
}

void LOAD_GO() {
    GoSurface = IMG_Load(go_on);
    GoTexture = SDL_CreateTextureFromSurface(Renderer, GoSurface);
    //图片转换成纹理
    GoRect.x = 350;
    GoRect.y = 110;
    GoRect.w = GoSurface->w;//宽
    GoRect.h = GoSurface->h;//高
}

void GAME_OVER() {
    count_play++;
    history_score[count_play] = atoi(score_num);
    if (history_score[count_play] >= highest_score) {
        highest_score = history_score[count_play];
    }
    itoa(highest_score, p_highest_score, 10);
    printf("%d\n", highest_score);
    Overfont = TTF_OpenFont(score, 50);
    OverSurface = TTF_RenderUTF8_Blended(Overfont, "GAME OVER", OverColor);
    OverTexture = SDL_CreateTextureFromSurface(Renderer, OverSurface);
    OverRect.x = 210;
    OverRect.y = 80;
    OverRect.w = 400;//宽
    OverRect.h = 150;

    Over_font = TTF_OpenFont(score, 50);
    Over_Surface = TTF_RenderUTF8_Blended(Over_font, "Press Here To Restart", Over_Color);
    Over_Texture = SDL_CreateTextureFromSurface(Renderer, Over_Surface);
    Over_Rect.x = 260;
    Over_Rect.y = 280;
    Over_Rect.w = 300;//宽
    Over_Rect.h = 35;
    SDL_RenderClear(Renderer);//当前画笔清空
    SDL_RenderCopy(Renderer, PlayBackGroundTexture, NULL, &PlayBackGroundRect);
    SDL_RenderCopy(Renderer, OverTexture, NULL, &OverRect);
    SDL_RenderCopy(Renderer, Over_Texture, NULL, &Over_Rect);
    SDL_RenderPresent(Renderer);
    while (SDL_WaitEvent(&MainEvent)) {
        switch (MainEvent.type) {
            case SDLK_ESCAPE: {
                QUIT();
            }
            case SDL_MOUSEBUTTONUP:
                if (MainEvent.button.x > 270 && MainEvent.button.x < 570 && MainEvent.button.y > 280 &&
                    MainEvent.button.y < 315) {
                    printf("You are in the Play UI!\n");
                    is_playing = 1;
                    SDL_RenderClear(Renderer);//当前画笔清空
                    SDL_RenderCopy(Renderer, MainBackGroundTexture, NULL, &MainBackGroundRect);
                    SDL_RenderPresent(Renderer);
                    return;
                }
                //printf("(%d,%d)\n",MainEvent.button.x,MainEvent.button.y);
                break;
            case SDL_QUIT:
                QUIT();
                break;
            default:
                break;
        }
    }
}

void QUIT() {
    printf("Game Over");
    SDL_FreeSurface(MainBackGroundSurface);
    SDL_FreeSurface(PlayBackGroundSurface);
    SDL_FreeSurface(DinoSurface);
    SDL_FreeSurface(Cactus1Surface);
    SDL_FreeSurface(Cloud1Surface);
    SDL_FreeSurface(Cloud2Surface);
    SDL_FreeSurface(Cloud3Surface);
    SDL_FreeSurface(ScoreSurface);

    SDL_DestroyTexture(MainBackGroundTexture);
    SDL_DestroyTexture(PlayBackGroundTexture);
    SDL_DestroyTexture(DinoTexture);
    SDL_DestroyTexture(Cactus1Texture);
    SDL_DestroyTexture(Cloud1Texture);
    SDL_DestroyTexture(Cloud2Texture);
    SDL_DestroyTexture(Cloud3Texture);
    SDL_DestroyTexture(ScoreTexture);

    TTF_CloseFont(Scorefont);

    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();
}