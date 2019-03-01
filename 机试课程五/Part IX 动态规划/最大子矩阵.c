#include <stdio.h>
#include <string.h>
#define MAX(a, b) (a > b ? a : b)
#define N 105
#define INF 0x3f3f3f3f
int martix[N][N];           //存储矩阵
int buf[N];                 //将相邻若干行合并成一行以后的结果
int n, maxSum;              //n是矩阵大小，maxSum是最大矩阵和
 
// 这里就是求解最大连续子段和
int findMax() {
   int i;
   int result = buf[0], sum = buf[0];
   for (i = 1; i < n; i++) {
       if (sum <= 0) {
           sum = buf[i];            //如果前面位置最大连续子序列和小于等于0，则以当前位置i结尾的最大连续子序列和为buf[i]  
       } else {
           sum += buf[i];           //如果前面位置最大连续子序列和大于0，则以当前位置i结尾的最大连续子序列和为它们两者之和
       }    

       result = MAX(result, sum);   //更新最大连续子序列和  
   }
   return result;
}
 
int main() {
    int i, j, k;
    while(scanf("%d", &n) != EOF) {
        if(n <= 0) {
            break;
        }
        maxSum = -INF;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                scanf("%d", &martix[i][j]);
            }
        }
        for(i = 0; i < n; i++) {
            // 数组b表示j ~ n - 1行，对应列元素的和
            // 将二维动态规划问题转化为一维动态规划问题
            memset(buf, 0, sizeof(buf));
            for(j = i; j < n; j++) {
                for(k = 0; k < n; k++) {
                    buf[k] += martix[j][k];
                }
               int temp = findMax();
               printf("%d\n", temp);
               maxSum = MAX(temp, maxSum);
            }
        }
        printf("%d\n", maxSum);
    }
}