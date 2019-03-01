#include <stdio.h>
#include <algorithm>
#define N 105
using namespace std;
int Tree[N];
typedef struct Edge {
    int a, b;
    int cost;
} Edge;

int findRoot(int x) {
    if(Tree[x] == -1) {
        return x;
    } else {
        Tree[x] = findRoot(Tree[x]);        // 路径压缩
        return Tree[x];
    }
}

bool cmp(Edge a,Edge b) {
    return a.cost < b.cost;
}

int main() {
    int i, n, m;
    int a, b, ans, count;
    Edge e[N];
    while(scanf("%d%d",&n,&m)!=EOF && n) {
        for(i = 1;i <= m;i++) {
            Tree[i] = -1;
        }
        for(i = 0;i < n;i++) {
            scanf("%d %d %d",&e[i].a, &e[i].b, &e[i].cost);
        }
        sort(e, e+n, cmp);
        ans = 0;
        for(i = 0;i < n;i++) {
            a = findRoot(e[i].a);
            b = findRoot(e[i].b);
            if(a != b) {
                Tree[b] = a;       
                ans += e[i].cost;
            }
        }
        count = 0;
        for(i = 1;i <= m;i++) {
            if(Tree[i] == -1) {
                count++;
            }
        }
        if(count == 1) {
            printf("%d\n",ans);
        } else {
            puts("?");
        }
    }
    return 0;
}