#include <stdio.h>
#define N 11
 
 //求result*a，结果存入result
void matrixPow(int result[N][N], int a[N][N], int n) {
    int i, j, k;
    int c[N][N];        //用来暂时保存结果
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            c[i][j]=0;
        }
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            for(k = 0; k < n; k++) {
                c[i][j] += result[i][k] * a[k][j];
            }
        }
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            result[i][j] = c[i][j];
        }
    }
}
 
int main() {
    int i, j;
    int n, k;
    int a[N][N], result[N][N];
    while(scanf("%d %d", &n ,&k) != EOF) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                scanf("%d", &a[i][j]);
                result[i][j]=a[i][j];
            }
        }
        for(i = 1; i < k; i++) {
            matrixPow(result, a, n);
        }
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                printf("%d", result[i][j]);
                if(j == n - 1) {
                    printf("\n");
                } else {
                    printf(" ");
                }
            }
        }
    }
    return 0;
}