//
// Created by HW on 2022/10/8.
//
#include<stdio.h>
#include<math.h>
int main() {
    int xa, ya, xb, yb, xc, yc;
    int n;
    int a, b, c, d;
    int i, j, k, l;
    scanf("%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc);
    if(((ya<=yc)&&(yc<=yb)||((ya>=yc)&&(yc>=yb)))&&(xa==xb&&xb==xc))
    { n = abs(xa - xb) + abs(ya - yb)+2;}
    else if(((xa<=xc)&&(xc<=xb)||((xa>=xc)&&(xc>=xb)))&&(ya==yb&&yb==yc))
    { n = abs(xa - xb) + abs(ya - yb) + 2;}
    else {n = abs(xa - xb) + abs(ya - yb);}
    printf("%d\n", n);
    {
        if ((xb == xc&&xa!=xc) || (yc == ya&&yc!=yb) ) {
            if (yb >= ya) {
                for (a = 1; a <= (yb - ya); a++)
                    printf("U");
            } else if (ya > yb) {
                for (b = 1; b <= (ya - yb); b++)
                    printf("D");
            }
            if (xb >= xa) {
                for (c = 1; c <= (xb - xa); c++)
                    printf("R");
            } else if (xa > xb) {
                for (d = 1; d <= (xa - xb); d++)
                    printf("L");
            }
        } else if(((ya<=yc)&&(yc<=yb)||((ya>=yc)&&(yc>=yb)))&&(xa==xb&&xb==xc)){
            printf("R");
            if (yb >= ya) {
                for (a = 1; a <= (yb - ya); a++)
                    printf("U");
            } else if (ya > yb) {
                for (b = 1; b <= (ya - yb); b++)
                    printf("D");
            }
            printf("L");
        }
         else if(((xa<=xc)&&(xc<=xb)||((xa>=xc)&&(xc>=xb)))&&(ya==yb&&yb==yc)){
            printf("U");
            if (xb >= xa) {
                for (c = 1; c <= (xb - xa); c++)
                    printf("R");
            } else if (xa > xb) {
                for (d = 1; d <= (xa - xb); d++)
                    printf("L");
            }
            printf("D");
        }
        else{
            if(xa<=xb){
                for (i = 1; i <= (xb - xa); i++)
                    printf("R");
            } else if (xa > xb) {
                for (j = 1; j <= (xa - xb); j++)
                    printf("L");
            }
            if (yb >= ya) {
                for (k = 1; k <= (yb - ya); k++)
                    printf("U");
            } else if (ya > yb) {
                for (l = 1; l <= (ya - yb); l++)
                    printf("D");
            } }
    }
    return 0;
}