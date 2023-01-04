//
// Created by HW on 2022/10/12.
//
#include<stdio.h>
#include <stdbool.h>

int main()
{
    int n, number;
    int i, j;
    int count[1000] ={0} ;
    bool prime = 1;
    scanf_s("%d\n", &n);
    for (i = 1; i <= n; i++)
    {
        scanf_s("%d", &number);
        for(;number != -1;)
        {
            for (j = 2; j <= (number/2); j++)
            {
                if (number % j == 0)
                {
                    prime = 0;
                    break;
                }
            }

            if (prime)
            {
                count[i]++;
                prime = 1;
            }
            else
            {
                count[i]=count[i];
                prime=1;
            }
            scanf_s("%d", &number);
        }
        printf("%d\n", count[i]);
    }
    return 0;
}