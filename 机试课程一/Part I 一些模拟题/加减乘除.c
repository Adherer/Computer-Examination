#include <stdio.h>
void solve(int a, char op) {
    int i, b, count;
    if(op == '!') {  
        count = 1;
        for(i = a;i >= 1;i--) {
            count = count * i;
        }
        printf("%d\n",count);
    } else {
        scanf("%d",&b);
        if(op =='+') {
            printf("%d\n",a + b);
        }
        if(op == '-') {
            printf("%d\n",a - b);
        }
        if(op == '*') {
            printf("%d\n",a * b);
        }
        if(op == '/') {  
            if(b != 0) {
                printf("%d\n",a / b);
            } else {
                printf("error\n");
            }
        }
        if(op == '%') {
            if(b != 0) {
                printf("%d\n",a % b);
            } else {
                printf("error\n");
            }
        }
    }
}
int main() {
    int a;
    char op;
    while(scanf("%d %c",&a,&op) != EOF) {
        solve(a, op);
    }
    return 0;
}