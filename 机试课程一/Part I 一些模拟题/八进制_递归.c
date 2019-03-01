#include <stdio.h>
 
void solve(int n) {
    if (n == 0) {
        return;
    } else {
        solve(n / 8);
        printf("%d", n % 8);
    }
}
 
int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        solve(N);
        printf("\n");
    }
    return 0;
}
