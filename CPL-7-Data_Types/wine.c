//
// Created by HW on 2022/11/12.
//
#include <stdio.h>
#include <stdbool.h>
int main()
{
    int n, L ;
    scanf("%d %d", &n, &L);
    //the types of every wine
    int wine_types[1000] = {0};
    for (int i = 0; i < n; ++i) {
        scanf("%d",&wine_types[i]);
    }

    //the max of every wine
    int wine_max[1000] = {0};
    for (int i = 0; i < n; ++i) {
        scanf("%d",&wine_max[i]);
    }

    //to see if every type of wine is used
    bool bmax[1000] = {0};

    //temporarily store the biggest type of wine
    int temp;

    int sum = 0;

    for (int j = 0; j < n; ++j) {

        //find the biggest type of wine
        for (int i = 0; i < n; ++i) {
            if(bmax[i] == 0){
                temp = i;
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            if(bmax[i] == 0) {
                if (wine_types[temp] >= wine_types[i]) {
                    temp = temp;
                } else {
                    temp = i;
                }
            }
        }

        //mark it as used
        bmax[temp] = 1;

        //use the biggest wine
        if(L != 0) {
            if (wine_max[temp] < L) {
                L -= wine_max[temp];
                sum += (wine_types[temp] * wine_max[temp]);
            } else if (wine_max[temp] >= L) {
                sum += (wine_types[temp] * L);
                L = 0;
            }
        }

        //count how many wines have been uesd and to see if it is the last used wine
//        int count = 0;
//        for (int i = 0; i < n; ++i) {
//            if(bmax[i] == 1){
//                count ++;
//                if(count == n - 1){
//                    for (int k = 0; k < n; ++k) {
//                        if(bmax[k] == 0){
//                            temp = k;
//                        }
//                    }
//                }
//            }
//        }
    }
    printf("%d ",sum);
}
