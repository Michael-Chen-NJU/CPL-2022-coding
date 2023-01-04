//
// Created by HW on 2022/12/28.
//
#include <stdio.h>

int main() {
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        int m, n;
        scanf("%d%d", &n, &m);
        int array[1005] = {0};
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &array[j]);
        }
        int operator[1005] = {0};
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &operator[j]);
        }

        //进行操作
        for (int j = 1; j <= m; ++j) {
            int index = operator[j];
            array[0] = array[index];
            for (int k = index; k >= 1; --k) {
                array[k] = array[k - 1];
            }
            array[0] = 0;
        }

//        for (int j = 1; j <= n; ++j) {
//            printf("%d ", array[j]);
//        }
//        printf("\n");
        int is_sorted = 1;
        //判断是否按照升序排列
        for (int j = 1; j < n; ++j) {
            if (array[j] <= array[j + 1]) {

            } else {
                is_sorted = 0;
                printf("mayi is a good teacher\n");
                break;
            }
        }
        if (is_sorted == 1) {
            printf("I love C programming language\n");
        }
    }
}
