#include <map>
#include <iostream>
using namespace std;

int main() {
    map<char, int> mp;
    mp['a'] = 1;
    mp['b'] = 2;
    mp['c'] = 3;

    map<char, int>::iterator it = mp.find('b');
    cout << it -> first << " " << it -> second << endl << endl;
    
    mp.erase(it);
    for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        cout << it -> first << " " << it -> second << endl;
    }
    cout << endl;

    mp.erase('c');
    for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        cout << it -> first << " " << it -> second << endl;
    }
    cout << endl;

    mp['d'] = 4;
    mp['e'] = 5;
    for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        cout << it -> first << " " << it -> second << endl;
    }
    cout << endl;

    it = mp.find('d');
    mp.erase(it, mp.end());
    for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        cout << it -> first << " " << it -> second << endl;
    }
    cout << endl;

    cout << mp.size() << endl;

    mp.clear();
    cout << mp.size() << endl;
    return 0;
}