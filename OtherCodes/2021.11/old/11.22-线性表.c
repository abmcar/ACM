#include <stdio.h>

struct Node
{
    struct Node *next;
    int val;
} * strNode;
int array[100], arrSize;

void append(int num, struct Node *strNode)
{
    printf("append %d\n", num);
    struct Node *nowNode = strNode;
    struct Node *nextNode = strNode->next;
    while (nextNode != NULL)
    {
        nowNode = nextNode;
        nextNode = nowNode->next;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val = num;
    nowNode->next = newNode;
    newNode->next = NULL;
}

void insert(int num, struct Node *strNode)
{
    arrSize++;
    printf("insert %d\n", num);
    struct Node *nowNode = strNode;
    struct Node *nextNode = strNode->next;
    while (nextNode != NULL)
    {
        if (nowNode->next != NULL)
        if (num <= nowNode->next->val)
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

void traveral(struct Node *strNode)
{
    struct Node *nowNode = strNode;
    while (nowNode->next != NULL)
    {
        if (nowNode == strNode)
            printf("%d", nowNode->next->val);
        else
            printf("-->%d", nowNode->next->val);
        nowNode = nowNode->next;
    }
    printf("\n");
}

int find(int num, struct Node *strNode)
{
    struct Node *nowNode = strNode;
    int nowPos = 0;
    if (nowNode->val == num)
        return nowPos;
    while (nowNode->next != NULL)
    {
        nowPos++;
        if (nowNode->next->val == num)
            return nowPos;
        nowNode = nowNode->next;
    }
    return -1;
}

void initList(struct Node *nowNode)
{
    printf("init List\n");
    strNode = (struct Node *)malloc(sizeof(struct Node));
    strNode->next = NULL;
    strNode->val = 0;
}

int checkEmpty(struct Node *strNode)
{
    if (strNode == NULL || strNode->next == NULL)
        return 1;
    return 0;
}

void delete(int pos, struct Node *strNode)
{
    printf("Delete Node %d\n",pos);
    struct Node *nowNode = strNode;
    int nowPos = 0;
    while (nowNode->next != NULL && ++nowPos < pos)
        nowNode = nowNode->next;
    nowNode->next = nowNode->next->next;
}

int main()
{
    initList(strNode);
    printf("check empty result:%d\n", checkEmpty(strNode));
    append(1,strNode);
    traveral(strNode);
    printf("check empty result:%d\n", checkEmpty(strNode));
    initList(strNode);
    insert(5,strNode);
    insert(4,strNode);
    insert(3,strNode);
    insert(2,strNode);
    insert(1,strNode);
    traveral(strNode);
    insert(3, strNode);
    printf("check empty result:%d\n", checkEmpty(strNode));
    traveral(strNode);
    // delete(1,strNode);
    delete(1,strNode);
    // delete(1,strNode);
    delete(1,strNode);
    delete(1,strNode);
    traveral(strNode);
    // printf("find %d pos: %d\n", 4, find(4, strNode));
    printf("find %d pos: %d\n", 1, find(1, strNode));
    printf("find %d pos: %d\n", 2, find(2, strNode));
    printf("find %d pos: %d\n", 3, find(3, strNode));
    printf("find %d pos: %d\n", 4, find(4, strNode));
}