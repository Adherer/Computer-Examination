#include <stdio.h>
#define MAX_SIZE 1000
void solve(int n) {
    int i, a[MAX_SIZE];
    while(n / 8) {
        a[i] = n % 8;
        n /= 8;
        i++;
    }
    printf("%d",n);
    i--;
    for(; i >= 0; i--) {
        printf("%d",a[i]);
    }
    printf("\n");
}
int main() {
    int n;
    while(scanf("%d",&n) != EOF) {
        solve(n);
    }
    return 0;
}