#include <set>
#include <iostream>
using namespace std;

int main() {
    set<int> st;
    st.insert(100);
    st.insert(200);
    st.insert(100);
    st.insert(300);

    for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    set<int>::iterator it = st.find(200);
    cout << *it << endl;

    st.erase(st.find(100));
    for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    st.erase(200);
    for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    st.insert(20);
    st.insert(10);
    st.insert(30);
    st.insert(40);
    it = st.find(30);
    st.erase(it, st.end());

    for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    st.clear();
    cout << st.size() << endl;

    return 0;
}