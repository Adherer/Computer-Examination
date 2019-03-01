#include <stdio.h>
#include <string.h>
#define N 10005
int top;

void push(int stack[N], int num) {
    stack[top++] = num;
}
 
void pop() {
    if(top > 0) {
        top--;
    }
}
 
void output(int stack[N]) {
    if(top == 0) {
        printf("E\n");
    } else {
        printf("%d\n", stack[top - 1]);
    }
}
 
int main() {
    int i, n, num;
    int stack[N];
    char c;
    while(scanf("%d", &n) != EOF && n > 0) {
        top = 0;                //栈顶指针初始化
        for(i = 0; i < n; i++) {
            c = getchar();
            scanf("%c", &c);
            switch(c){
                case 'A' : output(stack);
                           break;
                case 'P' : scanf("%d", &num); 
                           push(stack, num);
                           break;
                case 'O' : pop();
                           break;
            }
        }
        printf("\n");
    }
    return 0;
}