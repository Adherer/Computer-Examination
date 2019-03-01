#include <stdio.h>
#define MIN(a, b) (a < b ? a : b)

int divide(int m, int n, int limit) {
	int i, sum = 0;
	//递归终止条件
	if (n == 1 || m == n) {
		return 1;
	}

	for (i = 1; i <= MIN(m - n, limit); i++) {
		sum += divide(m - n, i, i);
	}
	return sum;
}

int main() {
	int i, m, n, ans;
	while(scanf("%d %d", &m, &n) != EOF) {
		ans = 0;
		for (i = 1; i <= MIN(m, n); i++) {
			ans += divide(m, i, i);
		}
		printf("%d\n", ans);
	}
	return 0;
}