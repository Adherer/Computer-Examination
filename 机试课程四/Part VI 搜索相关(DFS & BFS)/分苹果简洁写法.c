#include <stdio.h>

int divide(int m, int n) {
    if (m == 0 || n == 1) {
        return 1;
    } else if (n > m) {
        return divide(m, m);
    } else {
        return divide(m, n - 1) + divide(m - n, n);
    }
}
int main() {
    int m, n;
    while (scanf("%d %d", &m, &n) != EOF) {
        printf("%d\n", divide(m, n));
    }
    return 0;
}
