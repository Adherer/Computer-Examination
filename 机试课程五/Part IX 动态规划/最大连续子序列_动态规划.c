#include <stdio.h>
#define MAX_SIZE 10005
int a[MAX_SIZE];
struct DP {      
    int left;   //子序列起点
    int right;  //子序列终点
    int val;    //子序列和
} dp[MAX_SIZE];

void solve(int k) {
    int i;
    int maxLeft, maxRight, maxVal;  //记录最大连续子序列起点，终点，和
    dp[0].left = dp[0].right = 0;         // 初始化
    dp[0].val = a[0];
    for(i = 1;i < k;i++) {
        if(a[i] < dp[i - 1].val + a[i]) {
            dp[i].left = dp[i - 1].left;
            dp[i].right = i;
            dp[i].val = dp[i - 1].val + a[i];
        } else{
            dp[i].left = i;
            dp[i].right = i;
            dp[i].val = a[i];
        }
    }
    maxVal = dp[0].val;
    for(i = 1;i < k;i++) {
        if(dp[i].val > maxVal) {
            maxVal = dp[i].val;
            maxLeft = dp[i].left;
            maxRight = dp[i].right;
        }
    }
    printf("%d %d %d\n",maxVal, a[maxLeft], a[maxRight]);
}
int main(){
    int i, k, flag;
    while(scanf("%d",&k) != EOF && k){
        flag = 1;
        for(i = 0;i < k;i++) {
            scanf("%d",&a[i]);
            if (a[i] >= 0) {
                flag = 0;
            }
        }
        if(flag) {
            printf("0 %d %d\n", a[0], a[k - 1]);
        } else {
            solve(k);
        }
    }
    return 0;
}