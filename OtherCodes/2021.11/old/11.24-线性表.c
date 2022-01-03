#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *next;
    int val;
} ListNode;
ListNode *strNode;

ListNode *initList() {
    ListNode *strNode;
    printf("List created!\n");
    strNode = (ListNode *) malloc(sizeof(ListNode));
    strNode->next = NULL;
    strNode->val = 0;
    return strNode;
}

int checkEmpty(ListNode *strNode) {
    if (strNode != NULL)
        if (strNode->next == NULL)
            return 1;
    return 0;
}

void insertNum(int num,int pos, ListNode *strNode) {
    printf("insert num %d\n", num);
    struct Node *nowNode = strNode;
    struct Node *nextNode = strNode->next;
    int nowPos = 1;
    while (nextNode != NULL)
    {
        if (nowNode->next != NULL)
        if (nowPos++ == pos)
        {
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->val = num;
            nowNode->next = newNode;
            newNode->next = nextNode;
            return;
        }
        nowNode = nextNode;
        nextNode = nowNode->next;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val = num;
    nowNode->next = newNode;
    newNode->next = NULL;
}

void traveralList(ListNode *strNode) {
    ListNode *nowNode = strNode;
    while (nowNode->next != NULL) {
        if (nowNode == strNode)
            printf("%d", nowNode->next->val);
        else
            printf("-->%d", nowNode->next->val);
        nowNode = nowNode->next;
    }
    printf("\n");
}

int findNum(int num, ListNode *strNode) {
    ListNode *nowNode = strNode;
    int nowPos = 0;
    if (nowNode->val == num)
        return nowPos;
    while (nowNode->next != NULL) {
        nowPos++;
        if (nowNode->next->val == num)
            return nowPos;
        nowNode = nowNode->next;
    }
    return -1;
}

void deleteNum(int targetNum, ListNode *strNode) {
    printf("Delete Num %d\n", targetNum);
    ListNode *nowNode = strNode;
    int nowPos = 0;
    while (nowNode->next != NULL && nowNode->next->val != targetNum)
        nowNode = nowNode->next;
    if (nowNode->next == NULL)
        return;
    ListNode *oldNode = nowNode->next;
    nowNode->next = nowNode->next->next;
    free(oldNode);
}

int main() {
    strNode = initList();
    printf("check empty result:%d\n", checkEmpty(strNode));
    insertNum(1, 1, strNode);
    traveralList(strNode);
    insertNum(9, 1, strNode);
    traveralList(strNode);
    insertNum(1, 1, strNode);
    traveralList(strNode);
    insertNum(9, 1, strNode);
    traveralList(strNode);
    insertNum(8, 1, strNode);
    traveralList(strNode);
    insertNum(1, 1, strNode);
    traveralList(strNode);
    insertNum(0, 1, strNode);
    traveralList(strNode);
    printf("check empty result:%d\n", checkEmpty(strNode));
    printf("find %d result %d\n", 1, findNum(1, strNode));
    printf("find %d result %d\n", 2, findNum(2, strNode));
    printf("find %d result %d\n", 3, findNum(3, strNode));
    printf("find %d result %d\n", 4, findNum(4, strNode));
    printf("find %d result %d\n", 5, findNum(5, strNode));
    deleteNum(3, strNode);
    traveralList(strNode);
    deleteNum(1, strNode);
    traveralList(strNode);
    deleteNum(5, strNode);
    traveralList(strNode);
    printf("find %d result %d\n", 1, findNum(1, strNode));
    printf("find %d result %d\n", 2, findNum(2, strNode));
    printf("find %d result %d\n", 3, findNum(3, strNode));
    printf("find %d result %d\n", 4, findNum(4, strNode));
    printf("find %d result %d\n", 5, findNum(5, strNode));
    deleteNum(2, strNode);
    deleteNum(4, strNode);
    printf("check empty result:%d\n", checkEmpty(strNode));
}