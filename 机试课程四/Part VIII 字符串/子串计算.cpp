#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        map<string, int> m;
        for (int i = 1;i <= s.size();i++)
            for (int j = 0;j < i;j++)
                m[s.substr(j, i - j)]++;
         
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it -> second > 1)
                cout << it -> first << ' ' << it -> second << endl;
        }
    }
    return 0;
}