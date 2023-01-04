//
// Created by HW on 2022/10/6.
//
#include<stdio.h>
int main()
{
    int hang,lie;
    int i,j,k,l,m,n,o,p,q,r;
    scanf("%d%d",&hang,&lie);
    for(i=1;i<=hang;i++)
    {
        if(i<=hang)
        {
            for(j=1;j<=lie;j++)
            {
                if(j<lie)
                    printf("|*****");
                else if(j=lie)
                    printf("|*****|\n");
            }
            for(k=1;k<=lie;k++)
            {
                if(k<lie)
                    printf("|  |  ");
                else if(k=lie)
                    printf("|  |  |\n");
            }
            for(l=1;l<=lie;l++)
            {
                if(l<lie)
                    printf("|--+--");
                else if(l=lie)
                    printf("|--+--|\n");
            }
            for(m=1;m<=lie;m++)
            {
                if(m<lie)
                    printf("|  |  ");
                else if(m=lie)
                    printf("|  |  |\n");
            }


        }


        }
    for(r=1;r<=lie;r++)
    {
        if(r<lie)
            printf("|*****");
        else if(r=lie)
            printf("|*****|\n");
    }
    return 0;
    }
