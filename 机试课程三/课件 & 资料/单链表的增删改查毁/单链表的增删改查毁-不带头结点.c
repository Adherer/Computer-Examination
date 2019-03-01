#include <stdio.h>
#include <stdlib.h>
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode;
LNode *initNode(LNode *head);
void createList(LNode **head, int n);
void insertNode(LNode **head, int position, int length);
void deleteNode(LNode **head, int position, int length);
int searchNode(LNode *head, int elem);
void outputList(LNode *head);
void destroyList(LNode *head);

int main() {
    int n, m, flag;
    printf("Please enter the number of nodes in the list: ");
    scanf("%d", &n);
    LNode *head = NULL;               //链表初始化,初始时链表为空表
    createList(&head, n);              //创建一个含有n个结点的链表
    printf("The list is: ");
    outputList(head);                 //输出链表

    printf("Please enter the position to insert: ");
    scanf("%d", &m);
    insertNode(&head, m, n);              //插入结点
    printf("After being inserted, the list is: ");
    outputList(head);                 //输出链表

    printf("Please enter the position to delete: ");
    scanf("%d", &m);
    deleteNode(&head, m, n + 1);              //删除结点
    printf("After being deleted, the list is: ");
    outputList(head);                 //输出链表

    printf("Please enter the value of the element you are looking for: ");
    scanf("%d", &m);
    flag = searchNode(head, m);
    if (flag) {
        printf("%d is located at %d position\n", m, flag);
    } else {
        printf("%d is not in the list\n", m);
    }

    destroyList(head);                //释放链表占用的内存
    return 0;
}

LNode *initNode(LNode *head) {
    head = (LNode *)malloc(sizeof(LNode));
    head -> next = NULL;
    return head;
}

void createList(LNode **head, int n) {                   //尾插法创建链表
    int i, value;
    LNode *r = *head, *s;                         //链表的尾指针
    for (i = 0; i < n; i++) {
        s = (LNode *)malloc(sizeof(LNode));
        scanf("%d", &value);
        s -> data = value;
        if (i == 0) {
            (*head) = s;                //第一个结点单独处理
        } else {
            r -> next = s;
        }
        r = s;
    }
    r -> next = NULL;                   //表示链表已经到了尾部
}

//插入操作是将值为value的新结点插入到单链表的第position个位置上
//也就是说新插入的结点成为新的第position个数据结点
//position的取值范围为[1,length + 1]，其中length为表长
void insertNode(LNode **head, int position, int length) {
    if (position < 1 || position > length + 1) {
        printf("Insert Error!\n");
        return;
    }
    int count = 1, value;
    LNode *p = *head, *s;
    s = initNode(s);
    printf("Please enter the value of the node to be inserted: ");
    scanf("%d", &value);
    s -> data = value;
    if (position == 1) {                  //第一个结点单独处理
        s -> next = p;
        (*head) = s;
    } else {
        while (count < position - 1) {         //找到待插入位置的前驱结点
            p = p -> next;
            count++;
        }
        s -> next = p -> next;
        p -> next = s;
    }
}

//删除操作是将单链表的第position个结点删除
//position的取值范围为[1,length]，其中length为表长
void deleteNode(LNode **head, int position, int length) {
    if (position < 1 || position > length) {
        printf("Delete Error!\n");
        return;
    }
    int count = 1;
    LNode *p = *head, *s;               //p指向待删除结点的前驱结点(第一个结点除外)，s指向待删除的结点(包括第一个结点)
    if (position == 1) {                  //第一个结点单独处理
        s = p;
        (*head) = p -> next;
    } else {
        while (count < position - 1) {         //找到待删除结点的前驱结点
            p = p -> next;
            count++;
        }
        s = p -> next;
        p -> next = s -> next;
    }
    free(s);
}

int searchNode(LNode *head, int elem) {
    int count = 1;
    LNode *p = head;
    while (p) {
        if (p -> data == elem) {
            return count;
        } else {
            p = p -> next;
            count++;
        }
    }
    return 0;
}

void outputList(LNode *head) {
    LNode *p = head;
    while (p) {
        printf("%d ", p -> data);
        p = p -> next;
    }
    printf("\n");
}

void destroyList(LNode *head) {
    LNode *p = head, *temp;
    while (p) {
        temp = p;
        p = p -> next;
        free(temp);
    }
}