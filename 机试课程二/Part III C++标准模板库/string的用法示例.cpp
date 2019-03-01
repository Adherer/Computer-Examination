#include <iostream>
#include <string>
#include <climits>
using namespace std;

int main () {
    string str1 = "Hello";
    string str2 = "World";
    string str3;

    str3 = str1;
    cout << "str3 : " << str3 << endl;

    str3 = str1 + str2;
    cout << "str1 + str2 : " << str3 << endl;

    cout << "str3.length() :  " << str3.length() << endl;
    cout << "str3.size() :  " << str3.size() << endl;

    str3.insert(5, " ");
    cout << "str3 : " << str3 << endl;

    str3.insert(str3.begin() + 6, str1.begin(), str1.end());
    cout << "str3 : " << str3 << endl;

    str2.erase(str2.begin() + 3);
    cout << "str2 : " << str2 << endl;

    str2.erase(str2.begin() + 1, str2.end());
    cout << "str2 : " << str2 << endl;

    str3.erase(6, 5);
    cout << "str3 : " << str3 << endl;


    cout << str3.substr(0, 5) << endl;
    cout << str3.find("World") << endl;
    cout << str3.find("Word") << endl;
    cout << UINT_MAX << endl;

    cout << "str3 : " << str3 << endl;
    cout << str3.replace(0, 3, "Word") << endl;

    str3.clear();
    cout << "str3.length() :  " << str3.length() << endl;
    return 0;
}