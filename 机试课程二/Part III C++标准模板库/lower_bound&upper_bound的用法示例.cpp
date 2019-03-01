#include <algorithm>
#include <iostream>
using namespace std;


int main() {
    int a[10] = {1, 2, 2, 3, 3, 3, 5, 5, 5, 5};

    //寻找-1
    int *lowerPos = lower_bound(a, a + 10, -1);
    int *upperPos = upper_bound(a, a + 10, -1);
    cout << lowerPos - a << " " << upperPos - a << endl;

    //寻找1
    lowerPos = lower_bound(a, a + 10, 1);
    upperPos = upper_bound(a, a + 10, 1);
    cout << lowerPos - a << " " << upperPos - a << endl;

    //寻找3
    lowerPos = lower_bound(a, a + 10, 3);
    upperPos = upper_bound(a, a + 10, 3);
    cout << lowerPos - a << " " << upperPos - a << endl;

    //寻找4
    lowerPos = lower_bound(a, a + 10, 4);
    upperPos = upper_bound(a, a + 10, 4);
    cout << lowerPos - a << " " << upperPos - a << endl;

    //寻找5
    lowerPos = lower_bound(a, a + 10, 5);
    upperPos = upper_bound(a, a + 10, 5);
    cout << lowerPos - a << " " << upperPos - a << endl;

    //寻找6
    lowerPos = lower_bound(a, a + 10, 6);
    upperPos = upper_bound(a, a + 10, 6);
    cout << lowerPos - a << " " << upperPos - a << endl;
    return 0;
}