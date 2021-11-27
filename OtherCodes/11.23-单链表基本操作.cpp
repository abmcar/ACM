#include <bits/stdc++.h>

using namespace std;

typedef struct Node
{
    struct Node *next;
    int val;
} ListNode;
ListNode *strNode;

ListNode *initList()
{
    ListNode *strNode;
    strNode = (ListNode *)malloc(sizeof(ListNode));
    strNode->next = NULL;
    strNode->val = 0;
    return strNode;
}

void insertNum(int num, int pos, ListNode *strNode)
{
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
    if (nowPos == pos)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->val = num;
        nowNode->next = newNode;
        newNode->next = NULL;
    }
}

void traveralList(ListNode *strNode)
{
    ListNode *nowNode = strNode;
    while (nowNode->next != NULL)
    {
        printf("%d ", nowNode->next->val);
        nowNode = nowNode->next;
    }
    printf("\n");
}

void deleteNum(int pos, struct Node *strNode)
{
    struct Node *nowNode = strNode;
    int nowPos = 0;
    while (nowNode->next != NULL && ++nowPos < pos)
        nowNode = nowNode->next;
    if (nowNode->next != NULL)
    nowNode->next = nowNode->next->next;
}

int n, m;

int main()
{
    strNode = initList();
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        insertNum(temp, i, strNode);
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int opt, pos, val;
        cin >> opt >> pos;
        if (opt == 1)
        {
            if (pos != 0)
                deleteNum(pos, strNode);
            continue;
        }
        cin >> val;
        insertNum(val, pos + 1, strNode);
    }
    traveralList(strNode);
    return 0;
}
/* 
1
100
6
0 2 8
0 9 6
0 0 7
1 10
1 6
0 6 233

 */