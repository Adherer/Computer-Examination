#include<stdio.h>
#include<vector>
#define N 1005
#define INF 0x3f3f3f3f
using namespace std;

struct E{
    int next;
    int cost;
    int dis;
};

vector<E> edge[N];				// 存放图
bool mark[N];					// 标记点是否已经找到最短路径
int dis[N];						// 用来存储最短路径，表示从起始点到当前点的最短路径
int cost[N];					// 用来存储路径上的花费，表示从起始点到当前点的花费

int main(){
    int m, n;
    int a, b, d, p;
    E temp;
    int s,t;
    while(scanf("%d %d",&n, &m) != EOF) {
        if(m == 0 && n == 0) {
        	break;
        }

        for(int i = 1;i <= n;i++) {
        	edge[i].clear();
            dis[i] = -1;
            cost[i] = 0;
            mark[i] = false;
        }
        while(m--) {
            scanf("%d %d %d %d",&a, &b, &d, &p);
            temp.dis = d;
            temp.cost = p;
            temp.next = b;
            edge[a].push_back(temp);				// 无向图，所以要添加双向的边
            temp.next = a;
            edge[b].push_back(temp);
        }
        scanf("%d %d",&s, &t);
        int newP = s;
        mark[s] = true;
        dis[s] = 0;
        // 找源点到其他n-1个点的最短路径
        for(int i = 1;i < n;i++) {
        	// 遍历newP所有邻接边，重复的边也会遍历
            for(int j = 0;j < edge[newP].size();j++) {
                int next = edge[newP][j].next;
                int p = edge[newP][j].cost;
                int d = edge[newP][j].dis;
                if(mark[next] == true) {				// 已经找到最短路径
                	continue;
                }
                // 满足条件则更新dis数组和cost数组
                if(dis[next] == -1 || dis[next] > dis[newP] + d || (dis[next] == dis[newP] + d && cost[next] > cost[newP] + p)) {
                    dis[next] = dis[newP] + d;
                    cost[next] = cost[newP] + p;
                }
            }
            int min = INF;
            // 找到本轮迭代的最短路径
            for(int j = 1;j <= n;j++) {
            	if(mark[j] == false && dis[j] != -1 && dis[j] < min) {
                    min = dis[j];
                    newP = j;
                }
            }
            // 标记已找到最短路径
            mark[newP] = true;
        }
        printf("%d %d\n",dis[t], cost[t]);
    }
    return 0;
}