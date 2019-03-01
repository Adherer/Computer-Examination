#include <stdio.h>
int m[6] = {100, 50, 20, 10, 5, 1};
int main() {
	int i, n;
	int ans;
 	while(scanf("%d",&n) != EOF) {
 		ans = 0;
	   	for(i = 0;i < 6;i++) {
	   		if(n && m[i] <= n) {
		    	ans += n / m[i];
				n = n % m[i];
	      	}
	    }
	    printf("%d\n",ans); 	 	
    }
    return 0;
}
