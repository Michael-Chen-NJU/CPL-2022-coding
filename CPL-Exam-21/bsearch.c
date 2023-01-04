//
// Created by HW on 2022/12/28.
//
#include <stdio.h>

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int array[10000] = {0};
    for (int i = 0; i < n; ++i) {
        scanf("%d", &array[i]);
    }
    int query[10000] = {0};
    for (int i = 0; i < q; ++i) {
        scanf("%d", &query[i]);
        getchar();
        int is_found = 0;
        int ask = query[i];
        int low = 0;
        int high = n - 1;
        int index = n / 2;
        while (low <= high) {
            if (ask > array[index]) {
                low = index + 1;
                if (array[high] == ask) {
                    printf("%d\n", high);
                    is_found = 1;
                    break;
                }
            } else if (ask < array[index]) {
                high = index - 1;
                if (array[low] == ask) {
                    printf("%d\n", low);
                    is_found = 1;
                    break;
                }
            } else if (ask == array[index]) {
                printf("%d\n", index);
                is_found = 1;
                break;
            }
            index = (high + low) / 2;
        }
        if (is_found == 0) {
            printf("-1\n");
        }
    }
}