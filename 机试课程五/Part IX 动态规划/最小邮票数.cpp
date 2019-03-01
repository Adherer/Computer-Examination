#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int main() {
    int m,n;
    while(cin >> m >> n) {
        vector<int> num(n);
        for(int i = 0;i < n;i++) {
            cin >> num[i]; 
        }
        vector<int> dp(m+1);
        dp[0] = 0;
        for(int i = 1;i <= m;i++) {
            dp[i] = INF;
        }

        for(int i = 0;i < n;i++) {                     
            for(int j = m;j >= num[i];j--) {
                if(dp[j - num[i]] != INF) {
                    dp[j] = min(dp[j], dp[j - num[i]] + 1);
                }
            }
        }

        if(dp[m] == INF) {
            cout << 0 << endl;
        } else {
            cout<< dp[m] <<endl;
        }
    }
}