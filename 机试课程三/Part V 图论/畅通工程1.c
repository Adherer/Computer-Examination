#include <stdio.h>
#define MAX_SIZE 1005
 
int parent[MAX_SIZE];       //parent[i]表示节点i的双亲是谁, -1表示其为根节点

//寻找x所在的树的根节点
int findRoot(int x) {
    int ret;
    if(parent[x] == -1) {
        return x;
    } else {
        ret = findRoot(parent[x]);
        parent[x] = ret;              //路径压缩
        return ret;
    }
}
 
int main() {
    int i, m, n, x, y;
    int count;
    while(scanf("%d", &n) != EOF && n) {
        scanf("%d", &m);
        for(i = 1; i <= n; i++) {
            parent[i] = -1;             //parent数组初始化，一开始全是根
        }
        while(m--) {
            scanf("%d %d", &x, &y);
            x = findRoot(x);
            y = findRoot(y);
            if(x != y) {                //不在同一棵树那就合并
                parent[y] = x;             
            }
        }
        count=0;                        //统计根节点数量，也就是统计连通分量的个数
        for(i = 1; i <= n; i++) {
            if(parent[i] == -1) {
                count++;  
            } 
        }
        printf("%d\n", count - 1);
    }
    return 0;
}