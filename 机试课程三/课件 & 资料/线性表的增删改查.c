#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 300

typedef struct {
    int data[MAX_SIZE];
    int length;
} SqList;

void createSqList(SqList *p, int n);
void insertElem(SqList *p, int n);
void deleteElem(SqList *p, int n);
void modifyElem(SqList *p, int n);
int searchElem(SqList *p, int elem);
void outputList(SqList *p);

int main() {
    int n, pos;
    SqList L, *p = &L;
    printf("Please enter the length of the SqList: ");
    scanf("%d", &n);
    createSqList(p, n);
    printf("The list is: ");
    outputList(p);

    printf("Please enter the position to be inserted: ");              //插入到顺序表中的第m个位置
    scanf("%d", &n);
    insertElem(p, n);
    outputList(p);

    printf("Please enter the position to be deleted: ");
    scanf("%d", &n);
    deleteElem(p, n);
    outputList(p);

    printf("Please enter the position to be modified: ");
    scanf("%d", &n);
    modifyElem(p, n);
    outputList(p);

    printf("Please enter the value to be searched: ");
    scanf("%d", &n);
    pos = searchElem(p, n);
    if (pos != 0) {
        printf("%d is the %dth element\n", n, pos);
    } else {
        printf("%d is not in the SqList\n", n);
    }
    return 0;
}

//为顺序表中元素赋初始值
void createSqList(SqList *p, int n) {
    int i = 0;
    p -> length = 0;
    for (; i < n; i++) {
        scanf("%d", &(p -> data[i]));
        p -> length++;
    }
}

//插入元素的操作
void insertElem(SqList *p, int n) {
    int i, elem;

    //判断插入位置是否合法，以及顺序表是否已满
    if (p -> length >= MAX_SIZE) {
        printf("SqList is full\n");
        return;
    }
    if (n < 1 || n > p -> length + 1) {
        printf("The position is illegal.\n");
        return;
    }

    printf("Please enter the value to be inserted: ");              //插入到顺序表中的第m个位置
    scanf("%d", &elem);

    //【从后往前】元素依次往后退一位，空出待插入的第n位(下标是n-1)
    for (i = p -> length; i >= n; i--) {             //结点后移
        p -> data[i] = p -> data[i - 1];
    }

    //插入，length + 1
    p -> data[n - 1] = elem;
    p -> length++;
}

//删除元素的操作
void deleteElem(SqList *p, int n) {
    int i;
    if (n < 1 || n > p -> length) {
        printf("The position is illegal.\n");
        return;
    }

    //【从前往后】元素依次往前进一位，覆盖掉待删除的第n位(下标是n-1)
    for (i = n; i < p -> length; i++) {
        p -> data[i - 1] = p -> data[i];
    }
    p -> length--;
}

//修改元素的操作
void modifyElem(SqList *p, int n) {
    int i, elem;
    if (n < 1 || n > p -> length) {
        printf("The position is illegal.\n");
        return;
    }

    printf("Please enter the value to be modify: ");              //插入到顺序表中的第m个位置
    scanf("%d", &elem);
    p -> data[n - 1] = elem;
}

//查询元素的操作,在顺序表中查找第一个值为elem的元素,并返回其位序,查找失败时返回0
int searchElem(SqList *p, int elem) {
    int i;
    for (i = 0; i < p -> length; i++) {
        if (p -> data[i] == elem) {
            return i + 1;
        }
    }
    return 0;              //查找失败
}

//输出元素的操作
void outputList(SqList *p) {
    int i;
    for (i = 0; i < p -> length; i++) {
        printf("%d ", p -> data[i]);
    }
    printf("\n");
}
