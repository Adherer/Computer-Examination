#include <queue>
#include <iostream>
using namespace std;

int main() {
    queue<int> q;
    for (int i = 1; i <= 5; i++) {
        q.push(i);
    }
    cout << q.front() << " " << q.back() << endl;

    for (int i = 1; i <= 3; i++) {
        q.pop();
    }
    cout << q.front() << " " << q.back() << endl;

    if (q.empty()) {
        cout << "Empty" << endl;
    } else {
        cout << "Not Empty" << endl;
    }

    cout << q.size() << endl;
    return 0;
}