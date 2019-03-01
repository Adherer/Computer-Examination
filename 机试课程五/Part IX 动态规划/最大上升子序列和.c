#include <stdio.h>
#define MAX(a, b) (a > b ? a : b)
#define MAX_SIZE 1005

int main() {
    int i, j, n;
    int maxsum;
    int num[MAX_SIZE], sum[MAX_SIZE];
    while(scanf("%d", &n) != EOF) {
        maxsum = 0;
        for(i = 0; i < n; i++) {
            scanf("%d", &num[i]);
            sum[i] = num[i];            // 初始化
        }
        for(i = 0; i < n; i++) {
            for(j = 0; j < i; j++) {
                if(num[i] > num[j]) {     //符合递增子序列
                    sum[i] = MAX(sum[j] + num[i], sum[i]);
                }
            }
        }
        maxsum = sum[0];
        for(i = 1; i < n; i++) {
            if(maxsum < sum[i]) {
                maxsum = sum[i];
            }
        }
        printf("%d\n", maxsum);
    }
    return 0;
}