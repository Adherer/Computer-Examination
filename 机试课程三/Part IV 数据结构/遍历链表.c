#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1005
typedef struct LNode {
    int data;
    struct LNode* next;
}LNode, *LinkList;

// 链表初始化
LinkList initList(){
    LinkList L = (LNode*)malloc(sizeof(LNode));
    L -> next = NULL;
    return L;
}

// 插入结点
void insertNode(LNode* L,int num){
    LNode *p = L -> next;
    LinkList pre = L;
    LinkList q;
    while(p) {
        if(p -> data < num) {
            pre = p;
            p = p -> next;
        } else {
            break;
        }
    }
    q = (LNode*)malloc(sizeof(LNode));
    q -> data = num;
    pre -> next = q;
    q -> next = p;
}

// 输出链表
void print(LinkList L){
    LinkList p = L -> next;
    while(p -> next) {
        printf("%d ",p -> data);
        p = p -> next;
    }
    printf("%d",p -> data);
}

// 销毁链表
void destroyList(LinkList L) {
    LNode *p = L, *temp;
    while (p) {
        temp = p;
        p = p -> next;
        free(temp);
    }
}

int main(){
    int i, n, num;
    while(scanf("%d",&n)!=EOF){
        LinkList L;
        L = initList();
        for(i = 0;i < n;i++) {
            scanf("%d", &num);
            insertNode(L, num);
        }
        print(L);
        destroyList(L);             // 销毁链表，防止内存泄漏
    }
    return 0;
}