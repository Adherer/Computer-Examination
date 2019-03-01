#include <stdio.h>
#include <string.h>
#define MAX_N 410

void solve(char *str1,char *str2) {

    int ded[MAX_N] = {0};
    int i, j, len1, len2;

    //临时变量设置初始值
    len1 = strlen(str1);
    len2 = strlen(str2);
    i = len1 - 1;
    j = len2 - 1;

    //模拟竖式运算, 从右往左的运算顺序
    while (i >= 0 && j >= 0) {
        ded[i] = str1[i] - str2[j];  //将相减后的结果转化成整型
        i--;
        j--;
    }
    
    //剩余部分
    while(i >= 0){
        ded[i] = str1[i] - '0';
        i--;
    }
    
    //处理借位
    for (i = len1 - 1; i > 0; i--) {
        if (ded[i] < 0) {
            ded[i] += 10;
            ded[i - 1] -= 1;
        }
    }

    //寻找第一个不为0的位
    for(i = 0; i < len1 - 1; i++) {
        if(ded[i] != 0) {
            break;
        }
    }

    for (; i <= len1 - 1; i++) {
        printf("%d", ded[i]);
    }
    printf("\n");
}
int main(){
    char str1[MAX_N], str2[MAX_N];
    while (scanf("%s %s", str1, str2) != EOF) {
        solve(str1,str2);
    }
    return 0;
}