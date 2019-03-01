#include<stdio.h>
#define MaxSize 500
#define MOD 1000000          //表示data数组中每个元素存储6位
typedef struct {
    int data[MaxSize];
    int len;
} BigInt;
BigInt multiply(BigInt x, int y) {
    int i, g = 0, z;                // g表示进位，z暂存中间结果
    for(i = 0; i < x.len; i++) {
        z = x.data[i] * y + g;
        x.data[i] = z % MOD;        // 得到向高位进位后的结果
        g = z / MOD;                // 得到进位
    }
    while(g) {
        x.data[i++] = g % MOD;      // 向最高位进位
        g /= MOD;
    }
    x.len = i;
    return x;
}
int main() {
    int i, n;
    BigInt r;
    while(scanf("%d", &n) != EOF) {
        r.data[0] = 1;
        r.len = 1;
        for(i = 2; i <= n; i++) {
            r = multiply(r, i);
        }
        //输出最高位
        printf("%d", r.data[r.len - 1]);
        //从后往前输出，每个元素输出六位，类似于计算机中的小端字节序存储数据
        for(i = r.len - 2; i >= 0; i--) {
            printf("%06d", r.data[i]);
        }
        printf("\n");
    }
    return 0;
}