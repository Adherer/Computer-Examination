#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <queue>
using namespace std;
map<string, int> M;
queue<string> Q;

//将字符串i位与i+1位交换
string swapChar(string str, int i) {
    string newStr = str;
    char tmp = newStr[i];
    newStr[i] = newStr[i + 1];
    newStr[i + 1] = tmp;
    return newStr;
}

//判断字符串中是否含有"2012"
bool judge(string str) {
    if(str.find("2012", 0) == string::npos) {
        return false;
    }
    else {
        return true;
    }
}
 
int BFS(string str) {
    string newStr;
    M.clear();
    //清空队列
    while(!Q.empty()) {
        Q.pop();
    }
    Q.push(str);            //初始字符串作为起点放入队列
    M[str] = 0;             //初始字符串经历的交换次数是0
    while(!Q.empty()) {
        str = Q.front();
        Q.pop();            //取出队首，存入str
        for(int i = 0; i < str.size() - 1; i++){
            newStr = swapChar(str, i);
            //如果这个字符串没出现过
            if(M.find(newStr) == M.end()) {
                M[newStr] = M[str] + 1;           //现在出现过了，且交换次数比其父节点多1
                if(judge(newStr)) {
                    return M[newStr];             //符合要求返回结果
                } else {                          //不合要求，将其加入队列
                    Q.push(newStr);
                }
            } else {                //出现过的字符串，不用进行处理
                continue;
            }
        }
    }
    return -1;              //遍历完成，没发现符合要求的字符串，返回-1
}
 
int main() {
    int n;
    string str;
    while(cin >> n) {
        cin >> str;
        if(judge(str)) {
            cout << 0 << endl;
        } else {
            cout << BFS(str) << endl;
        }
    }
    return 0;
}