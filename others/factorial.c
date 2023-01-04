//
// Created by HW on 2022/10/7.
//
#include <stdio.h>
int main()
{
    int n,a[25],b[10000],c[10000],i=0,j=1;
    scanf("%d",&n);
    a[0]=1;b[0]=1,c[0]=1;
    if(n<=12) {
        for (int i = 1; i < n; i++) {
            a[i] = a[(i - 1)] * (i + 1);
            c[i] = a[i] % 10007;
            b[i] = c[i] + b[(i - 1)];
            printf("%d %d %d\n",a[i],c[i],b[i]);
        }
    }
    else {

            for (int i = 1; i < 12; i++) {
                a[i] = a[(i - 1)] * (i + 1);
                c[i] = a[i] % 10007;
                b[i] = c[i] + b[(i - 1)];
                printf("%d %d %d\n",a[i],c[i],b[i]);
            }
            a[11]=479001600;c[11]=6538;b[11]=30521;
            for(i=12;12<=i&&i<n;i++){
                a[i]=c[(i-1)]*(i+1);
                c[i]=a[i]%10007;
                b[i]=c[i]+b[(i-1)];
                printf("%d %d %d\n",a[i],c[i],b[i]);
            }
        }
    b[(n-1)]=b[(n-1)]%10007;
            printf("%d",b[(n-1)]);
    return 0;
}