#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> vi;
    for(int i = 0;i < 10;i++) {
        vi.push_back(i);
    }

    // 访问方法
    cout << "直接利用数组：";
    for(int i = 0;i < 10;i++) {
        cout<< vi[i] << " ";
    }
    cout << endl;

    cout << "利用迭代器：" ;
    vector<int>::iterator it;
    for(it = vi.begin();it != vi.end();it++) {
        cout<< *it << " ";
    }
    cout << endl;

    for(int i = 0;i < 5;i++) {
        vi.pop_back();
    }

    for(int i = 0;i < vi.size();i++) {
        cout << vi[i] << " ";
    }
    cout << endl;

    vi.insert(vi.begin() + 2, -1);              //将-1插入vi[2]的位置
    for(int i = 0;i < vi.size();i++) {
        cout << vi[i] << " ";
    }
    cout << endl;

    vi.erase(vi.begin() + 2);                   //删除-1
    for(int i = 0;i < vi.size();i++) {
        cout << vi[i] << " ";
    }
    cout << endl;

    vi.erase(vi.begin(), vi.begin() + 2);                   //删除0, 1
    for(int i = 0;i < vi.size();i++) {
        cout << vi[i] << " ";
    }
    cout << endl;

    vi.clear();
    cout << vi.size() << endl;

    return 0;
}