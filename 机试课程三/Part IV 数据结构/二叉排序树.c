#include <stdio.h>
typedef struct TNode {
    int data;
    struct TNode *left, *right;
} *BiTree, TNode;

int loc;
TNode T[101];

BiTree creat() {
    T[loc].left = T[loc].right = NULL;
    return &T[loc++];
}

BiTree insertNode(BiTree T, int x, int father) {
    if(!T) {
        T = creat();
        T -> data = x;
        printf("%d\n",father);
        return T;
    }
    if(x < T -> data) {
        T -> left = insertNode(T -> left, x, T -> data);
    } else if(x > T -> data) {
        T -> right = insertNode(T -> right, x, T -> data);
    }
    return T;
}
int main() {
    int i, n, temp;
    TNode* T;
    while(scanf("%d",&n) != EOF) {
        T = NULL;
        loc = 0;
        for(i = 0;i < n;i++) {
            scanf("%d",&temp);
            T = insertNode(T, temp, -1);
        }
    }
    return 0;
} 