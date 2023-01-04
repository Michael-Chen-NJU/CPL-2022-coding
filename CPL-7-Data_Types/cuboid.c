//
// Created by HW on 2022/11/14.
//
#include <stdio.h>
int main(void)
{
    int T = 1;
     //scanf("%d",&T);

    // get the size of each cube
    int size[100][3];
    for (int i = 0; i < T; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            scanf("%d", &size[i][j]);
        }
    }
    // draw one basic cube
    for (int j = 0; j < T; ++j)
    {
        // print the first plane;
        int count1 = 0, count2 = 0,count3 = 0,count4 = 0;
        for (int l = 0; l < size[j][1]; ++l)
        {
            // print the first column
            for (int k = 0; k < 2 * (size[j][1] - count1); ++k)
            {
                printf(" ");
            }
            for (int i = 0; i < size[j][0]; ++i)
            {
                printf("+-");
            }
            printf("+");
            for (int i = 0; i < count4; ++i)
            {
                printf(" +");
            }
            printf("\n");
            // print the second column
            for (int k = 0; k < 2 * (size[j][1] - count1) - 1; ++k)
            {
                printf(" ");
            }
            for (int i = 0; i < size[j][0]; ++i)
            {
                printf("/ ");
            }
            printf("/|");
            if (size[j][1] <= size[j][2]){
                for (int h = 0; h < count2; ++h)
                {
                    printf("/|");
                }
            }
            else
            {
                count3 ++;
                for (int i = 0; i < count2; ++i)
                {
                    printf("/|");
                }
                if (count3 >= size[j][2] + 1)
                {
                    printf("/");
                }
            }
            printf("\n");
            count1++;
            if(count2 < size[j][2] - 1){
                count2++;
            }
            if (count4 < size[j][2] )
            {
                count4++;
            }
        }

        //print the main part
               if((size[j][2] - size[j][1]) > 0){
                   for (int l = 0; l < (size[j][2] - size[j][1]); l++)
                   {
                       for (int i = 0; i < size[j][0]; ++i)
                       {
                           printf("+-");
                       }
                       printf("+");
                       for (int i = 0; i < count4; ++i)
                       {
                           printf(" +");
                       }
                       printf("\n");
                       for (int i = 0; i < size[j][0] ; ++i)
                       {
                           printf("| ");
                       }
                       printf("|");
                       printf("/|");
                       for (int h = 0; h < count2 - 1; ++h)
                       {
                           printf("/|");
                       }
                       printf("\n");
                   }
                }


        // print the last part
//        if(count2 < size[j][2] - 1){
//            count2++;
//        }
//        if (count4 < size[j][2] )
//        {
//            count4++;
//        }
        //correct
        if(size[j][2] > size[j][1]) {
            for (int k = 0; k < size[j][2] - (size[j][2] - size[j][1]); ++k) {
                for (int i = 0; i < size[j][0]; ++i) {
                    printf("+-");
                }
                printf("+");
                for (int i = 0; i < count4; ++i) {
                    printf(" +");
                }
                printf("\n");
                for (int i = 0; i < size[j][0]; ++i)
                {
                    printf("| ");
                }
                printf("|/");
                    for (int h = 0; h < count2 - 1; ++h)
                    {
                        printf("|/");
                    }
                printf("\n");

                count1--;
                count2--;
                if (count4 < size[j][2]) {
                    count4--;
                }
            }
        }

        //bug
        else{
            for (int k = 0; k < size[j][2]; ++k) {
                for (int i = 0; i < size[j][0]; ++i) {
                    printf("+-");
                }
                printf("+");
                for (int i = 0; i < count4; ++i) {
                    printf(" +");
                }
                printf("\n");
                for (int i = 0; i < size[j][0]; ++i)
                {
                    printf("| ");
                }
                printf("|/");
                for (int i = 0; i < count4 - 1; ++i)
                {
                    printf("|/");
                }
//                if (count3 >= size[j][2] + 1)
//                {
//                    printf("/");
//                }
                printf("\n");
                count4--;
                count3 ++;
            }
        }
        //the very last column
        for (int i = 0; i < size[j][0]; ++i)
        {
            printf("+-");
        }
        printf("+");
        printf("\n");
    }
}