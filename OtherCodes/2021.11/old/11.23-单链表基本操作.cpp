#include <bits/stdc++.h>

using namespace std;

typedef struct Node
{
    struct Node *next;
    int val;
} ListNode;
ListNode *strNode;

void InitList(ListNode *&L)
{
    L = (ListNode *)malloc(sizeof(ListNode));
    L->next = NULL;
    L->val = 0;
}

void ClearList(ListNode *&L)
{
    L->next = NULL;
}

bool EmptyList(ListNode *L)
{
    if (L->next == NULL)
        return true;
    return false;
}

int LengthList(ListNode L)
{
    int cnt = 0;
    ListNode *nowNode = &L;
    while (nowNode->next != NULL)
    {
        cnt++;
        nowNode = nowNode->next;
    }
    return cnt;
}

int GetList(ListNode *L, int i)
{

    ListNode *p;
    int j = 0;
    p = L->next;
    while (p->next != NULL && j < i - 1) //查找条件
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return NULL;
    else
        return p->val;
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

void TraveralList(ListNode *strNode)
{
    ListNode *nowNode = strNode;
    while (nowNode->next != NULL)
    {
        printf("%d ", nowNode->next->val);
        nowNode = nowNode->next;
    }
    printf("\n");
}

void DeleteNum(int pos, struct Node *strNode)
{
    struct Node *nowNode = strNode;
    int nowPos = 0;
    while (nowNode->next != NULL && ++nowPos < pos)
        nowNode = nowNode->next;
    if (nowNode->next != NULL)
        nowNode->next = nowNode->next->next;
}

void MergeList(ListNode *&la, ListNode *&lb, ListNode *&lc)
{
    InitList(lc);
    int lenA = LengthList(*la);
    int lenB = LengthList(*lb);
    int cntA = 1;
    int cntB = 1;
    int cntC = 1;
    while (cntA < lenA && cntB < lenB)
    {
        int nowA = GetList(la, cntA);
        int nowB = GetList(lb, cntB);
        if (nowA > nowB)
        {
            insertNum(nowB, cntC++, lc);
            cntB++;
        }
        else
        {
            insertNum(nowA, cntC++, lc);
            cntA++;
        }
    }
    while (cntA < lenA)
        insertNum(GetList(la, cntA++), cntC++, lc);
    while (cntB < lenB)
        insertNum(GetList(lb, cntB++), cntC++, lc);
}

int n, m;

int main()
{
    InitList(strNode);
    insertNum(1, 1, strNode);
    insertNum(2, 2, strNode);
    insertNum(3, 3, strNode);
    insertNum(4, 4, strNode);
    ListNode *s1, *s2;
    InitList(s1);
    insertNum(0, 1, s1);
    insertNum(1, 2, s1);
    insertNum(5, 3, s1);
    TraveralList(strNode);
    TraveralList(s1);
    MergeList(strNode, s1, s2);
    TraveralList(s2);
    cout << GetList(s1,1) << endl;
    cout << GetList(s1,2) << endl;
    cout << GetList(s1,3) << endl;
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