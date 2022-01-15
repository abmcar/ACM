typedef int DataType;

typedef struct Node
{
    struct Node *next;
    DataType val;
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

int LengthList(ListNode *L)
{
    int cnt = 0;
    while (L->next != NULL)
    {
        cnt++;
        L = L->next;
    }
    return cnt;
}

DataType GetList(ListNode *L, int i)
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
        return -1;
    else
        return p->val;
}

void insertNum(DataType num, int pos, ListNode *strNode)
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
    int lenA = LengthList(la);
    int lenB = LengthList(lb);
    int cntA = 1;
    int cntB = 1;
    int cntC = 1;
    while (cntA <= lenA && cntB <= lenB)
    {
        DataType nowA = GetList(la, cntA);
        DataType nowB = GetList(lb, cntB);
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
    while (cntA <= lenA)
        insertNum(GetList(la, cntA++), cntC++, lc);
    while (cntB <= lenB)
        insertNum(GetList(lb, cntB++), cntC++, lc);
}
