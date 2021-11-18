#include <stdio.h>

struct Node
{
    struct Node *next;
    int val;
} * strNode;
int array[100], arrSize;

void insert(int num, struct Node *strNode)
{
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

void traveral(struct Node *strNode)
{
    struct Node *nowNode = strNode;
    printf("%d", nowNode->val);
    while (nowNode->next != NULL)
    {
        printf("-->%d", nowNode->next->val);
        nowNode = nowNode->next;
    }
    printf("\n");
}

int get(int arr[])
{
    int cnt = 0;
    int temp;
    while (scanf("%d", &temp))
    {
        if (temp == -1)
            break;
        arr[cnt++] = temp;
    }
    return cnt;
}

void erase(struct Node *strNode)
{
    struct Node *nowNode = strNode;
    while (nowNode->val % 2 == 0 && nowNode->next != NULL)
        nowNode = nowNode->next;
    while (nowNode->next != NULL)
    {
        if (nowNode->next->val % 2 == 0)
        {
            printf("erase:%d\n",nowNode->next->val);
            nowNode->next = nowNode->next->next;
            if (nowNode->next == NULL)
                break;
        }
        nowNode = nowNode->next;
    }
}

int main()
{
    printf("输入一串整数初始化链表,输入-1表示结束输入\n");
    strNode = (struct Node *)malloc(sizeof(struct Node));
    strNode->next = NULL;
    arrSize = get(array);
    strNode->val = array[0];
    for (int i = 1; i < arrSize; i++)
        insert(array[i], strNode);
    traveral(strNode);
    erase(strNode);
    traveral(strNode);
}