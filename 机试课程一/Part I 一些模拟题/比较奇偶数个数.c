#include <stdio.h>
#define MAX_SIZE 1005
int main() {
    int i, n, evenCount, oddCount;
    int a[MAX_SIZE];
    while(scanf("%d", &n) != EOF) {
        evenCount = 0;
        oddCount = 0;
        for(i = 0; i < n;i++) {
            scanf("%d", &a[i]);
            if(a[i] % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }
        if(oddCount < evenCount) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}