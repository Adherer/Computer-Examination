#include <stdio.h>
#include <stdlib.h>
#define SOLUTION 92
#define COL_ROW_NUM 8
int count;                                    // 记录结果数
int sol[SOLUTION][COL_ROW_NUM];              // 存放结果
int maze[COL_ROW_NUM][COL_ROW_NUM];          // 标记位置
int position[COL_ROW_NUM];                  // 标记行

//判断当前摆放的皇后与前r-1行是否有冲突
int whetherConflict(int r, int c) {
    int i, j;
    for (i = 0;i < r;i++) {
        for (j = 0;j < COL_ROW_NUM;j++) {
            if (maze[i][j]) {
                if (c == j || r - i == abs(c - j)) {
                    return 0;                  //同一列或者位于同一对角线,不满足
                }
            }
        }
    }
    return 1;
}

void dfs(int step) {
    int i, c;
    if (step == COL_ROW_NUM) {
        for(i = 0; i < 8; i++) {
            sol[count][i] = position[i];
        }
        count++;
        return;
    }
    for (c = 0;c < COL_ROW_NUM;c++) {
        if (!maze[step][c]) {
            if (whetherConflict(step, c)) {
                position[step] = c + 1;
                maze[step][c] = 1;
                dfs(step + 1);
                maze[step][c] = 0;
            }
        }
    }
}

int main() {
    int i, n;
    dfs(0);
    while (scanf("%d", &n) != EOF) {
        for(i = 0; i < 8; i++){
            printf("%d", sol[n - 1][i]);
        }
        printf("\n");
    }
    return 0;
}