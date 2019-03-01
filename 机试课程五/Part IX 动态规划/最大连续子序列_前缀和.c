#include <stdio.h>
#define MAX_SIZE 10005
#define MAX_NUM 0x3f3f3f3f
#define MAX(a, b) (a > b ? a : b)
int a[MAX_SIZE], sum[MAX_SIZE];

void solve(int k) {
	int i, j;
	int flag = 1, maxSum = -MAX_NUM;
	int start, end;
	for (i = 0; i < k; i++) {
    	scanf("%d", &a[i]);
    	if (a[i] >= 0) {
    		flag = 0;
    	}
        sum[i + 1] = sum[i] + a[i];
    }
    if (flag) {
    	printf("0 %d %d\n", a[0], a[k - 1]);
    } else {
    	for (i = 0; i <= k; i++) {
	    	for (j = i + 1; j <= k; j++) {
	    		if (maxSum < sum[j] - sum[i]) {
	    			maxSum = sum[j] - sum[i];
	    			start = i;
	    			end = j - 1;
	    		}
	    	}
    	}
    	printf("%d %d %d\n", maxSum, a[start], a[end]);
    }
}

int main() {
    int k;
    while (scanf("%d", &k) != EOF && k) {
        solve(k);
    }
    return 0;
}