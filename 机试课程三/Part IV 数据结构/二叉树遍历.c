#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 105
 
typedef struct Node {
    char c;
    struct Node *lchild;
    struct Node *rchild;
} Node;
int pos;           //标记字符串处理到哪了
char str[N];            //读取的字符串

// 创建新节点，返回结点指针
Node* createNode() {
    Node *ret = (Node*)malloc(sizeof(Node));
    ret -> lchild = NULL;
    ret -> rchild = NULL;
    return ret;
}
 
// 中序遍历
void inOrder(Node* T) {
    if (T) {
        inOrder(T -> lchild);
        printf("%c ", T -> c);
        inOrder(T -> rchild);
    }
}

// 释放二叉树所占内存
void del(Node* T) {
    // 删除左子树
    if(T -> lchild != NULL) {
        del(T -> lchild);
        T -> lchild = NULL;
    }
    // 删除右子树
    if(T -> rchild != NULL) {
        del(T -> rchild);
        T -> rchild = NULL;
    }
    // 删除根节点
    free(T);
}

// 根据字符串创立二叉树，并返回根节点指针 
Node* buildTree() {
    // 字符串处理完毕
    if(pos >= strlen(str)) {
        return NULL;
    }
    //创建空节点，即返回空指针
    if(str[pos] == '#') {
        pos++;              //准备处理下一个字符
        return NULL;
    }
    Node *p = createNode();           //创建一个空节点
    p -> c = str[pos++];              //先序，先获取根节点的字符信息
    p -> lchild = buildTree();        //创建左子树
    p -> rchild = buildTree();        //创建右子树
    return p;                         //返回根节点指针
}
 
int main() {
    while(gets(str)) {
        pos = 0;                        //标记字符串处理到哪了
        Node* T = buildTree();          //根据字符串构建整棵树
        inOrder(T);                     //中序遍历并输出
        printf("\n");
        del(T);                         //释放内存空间
    }
    return 0;
}
