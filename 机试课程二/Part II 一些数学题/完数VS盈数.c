#include <stdio.h>
#define NUM 60
int judge(int num) {
    int i, sum = 0;
    for(i = 1; i < num; i++) {
        if(num % i == 0) {
            sum += i;
        }
    }
    if(sum == num) {
        return 1;           // 相等为完数
    } else if(sum > num) {
        return 0;           // 大于为盈数
    } else {
        return -1;          // 其他情况
    }
}
 
int main() {
    int e[NUM], g[NUM];
    int ecount = 0, gcount = 0;
    int i;

    // 判断2 - 60
    for(i = 2; i <= 60; i++) {
        if(judge(i) == 1) {
            e[ecount++] = i;
        } else if(judge(i) == 0) {
            g[gcount++] = i;
        }
    }
 
    //输出
    printf("E:");
    for(i = 0; i < ecount; i++) {
        printf(" %d", e[i]);
    }
    printf("\n");
    
    printf("G:");
    for(i = 0; i < gcount; i++) {
        printf(" %d", g[i]);
    }
    printf("\n");
    return 0;
}