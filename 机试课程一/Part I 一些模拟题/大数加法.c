#include <stdio.h>
#include <string.h>
#define MAX(a, b) (a > b ? a : b)
#define MAX_N 410

void solve(char *str1, char *str2) {
    int ans[MAX_N] = {0};
    int i, j, len1, len2, maxLen, tempMaxLen;

    //临时变量设置初始值
    len1 = strlen(str1);
    len2 = strlen(str2);
    i = len1 - 1;
    j = len2 - 1;
    maxLen = MAX(len1, len2);
    tempMaxLen = maxLen;

    //模拟竖式运算, 从右往左的运算顺序, 空出第0位不用, 以作为最高位的进位位
    while (i >= 0 && j >= 0) {
        ans[tempMaxLen] = str1[i] + str2[j] - 2 * '0';  //将相加后的结果转化成整型
        tempMaxLen--;
        i--;
        j--;
    }

    //将剩余部分相加
    for (i = 0; i < len1 - len2; i++) {
        ans[i + 1] = str1[i] - '0';
    }
    for (i = 0; i < len2 - len1; i++) {
        ans[i + 1] = str2[i] - '0';
    }

    //处理进位
    for (int i = maxLen; i > 0; i--) {
        if (ans[i] >= 10) {             //说明该位相加后的结果需要进位
            ans[i] -= 10;               //“该位” - 10
            ans[i - 1] += 1;            // 向前一位进1
        }
    }

    //看最高位的进位位是否为1
    //为1则说明有低位向最高位进位,则需从第
    //则不为1则没有,从第1位开始输出即可
    i = ans[0] == 1 ? 0 : 1;
    for (; i <= maxLen; i++) {
        printf("%d", ans[i]);
    }
    printf("\n");
}

int main() {
    char str1[MAX_N], str2[MAX_N];
    while(scanf("%s %s", str1, str2)!=EOF) {
        solve(str1, str2);
    }
}