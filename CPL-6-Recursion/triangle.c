#include <stdio.h>
#include <math.h>
int paint(int k, int x, int y);
int n;
char a[2500][1024]={0};
int main(){
    scanf("%d",&n);
    for (int i = 0; i < pow(2,n); ++i) {
        for (int j = 0; j < pow(2,n + 1); ++j) {
            a[i][j] == ' ';
        }
    }
    paint (n , 0, 0);
    for (int i = 0; i < pow(2,n); ++i) {
        for (int j = 0; j < pow(2,n + 1); ++j) {
            printf("%c",a[i][j]);
        }
        printf("\n");
    }

}
int paint(int k, int x, int y){
    if(k == 1){
        a[x][y] = ' ';
        a[x][y + 1] = '/';
        a[x][y + 2] = '\\';
        a[x][y + 3] = ' ';
        a[x + 1][y] = '/';
        a[x + 1][y + 1] = '_';
        a[x + 1][y + 2] = '_';
        a[x + 1][y + 3] = '\\';
        int ans;
        ans = 6;
        return ans;
    }
    else {
        paint(k - 1,  x, pow(2,   k - 1)+y );
        paint(k - 1, pow(2, k- 1) + x, y);
        paint(k - 1, pow(2,k - 1)+ x, pow(2, k) + y );
    }
}