#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(int a, int b) {
    return a > b;
}

int main() {
    vector<int> vi;
    vi.push_back(3);
    vi.push_back(1);
    vi.push_back(2);
    sort(vi.begin(), vi.end(), cmp);
    for (int i = 0; i < 3; i++) {
        cout << vi[i] << " ";
    }
    cout << endl;
    return 0;
}