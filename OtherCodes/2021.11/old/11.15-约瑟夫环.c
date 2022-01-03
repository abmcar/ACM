#include <stdio.h>

struct Node
{
    struct Node *next;
    int val;
} * strNode;
int array[100], arrSize, n, m;

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

int solve()
{
    struct Node *nowNode = strNode;
    while (nowNode->next != NULL)
        nowNode = nowNode->next;
    nowNode->next = strNode;
    nowNode = strNode;
    int cnt = 0;
    int nowOut = 0;
    while (nowNode->next != nowNode)
    {
        cnt++;
        if (cnt >= m-1)
        {
            printf("%d out\n",nowNode->next->val);
            nowNode->next = nowNode->next->next;
            cnt = 0;
            nowOut++;
            if (nowOut == n-1)
                return nowNode->val;
        }
        nowNode = nowNode->next;
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    strNode = (struct Node *)malloc(sizeof(struct Node));
    strNode->next = NULL;
    arrSize = n;
    for (int i = 0; i < n; i++)
        array[i] = i+1;
    strNode->val = array[0];
    for (int i = 1; i < arrSize; i++)
        insert(array[i], strNode);
    printf("%d",solve());
}