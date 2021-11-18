#include <bits/stdc++.h>
using namespace std;

typedef struct ThreadNode
{
    int data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

ThreadNode *preNode = NULL; // ȫ�ֱ�����������¼��ǰ����ǰ�����

// ����������ÿһ�����
void travel(ThreadNode *nowNode)
{
    if (NULL == nowNode->lchild)
    { // ��ǰ����ǰ��Ϊ�գ�Ϊ������ǰ������
        nowNode->lchild = preNode;
        nowNode->ltag = 1;
    }

    if (NULL != preNode && NULL == preNode->rchild)
    { // Ϊǰ����㽨���������
        preNode->rchild = nowNode;
        preNode->rtag = 1;
    }
    preNode = nowNode; // ���ƣ��Ա������һ�����
}

// ������������ʼ��
void InitThreadTree(ThreadTree &T)
{
    T == NULL;
}

// ��������
void InThread(ThreadTree T)
{
    if (NULL != T)
    {
        InThread(T->lchild); // �ݹ����������
        travel(T);            // ���ʸ��ڵ�
        InThread(T->rchild); // �ݹ����������
    }
}

// ������������㲢���ؽ���ַ
ThreadNode *CreateNode(int data)
{
    struct ThreadNode *node = (ThreadNode *)malloc(sizeof(ThreadNode));
    node->ltag = 0;
    node->rtag = 0;
    node->lchild = NULL;
    node->rchild = NULL;
    node->data = data;
    return node;
}

vector<int> nums;
int preNodeValue[10005];
int aftNodeValue[10005];

// ����������
void CreateBiTree(ThreadTree &T)
{
    int temp;
    cin >> temp;
    nums.push_back(temp);
    T = CreateNode(temp);
    // ���д��浱ǰ��ڵ�
    queue<ThreadNode *> Q;
    Q.push(T);
    while (!Q.empty())
    {
        ThreadNode *nowNode = Q.front();
        Q.pop();
        int l, r;
        cin >> l >> r;
        nums.push_back(l);
        nums.push_back(r);
        // ����ǿ�ѹ�����
        if (l != 0)
        {
            nowNode->lchild = CreateNode(l);
            Q.push(nowNode->lchild);
        }
        if (r != 0)
        {
            nowNode->rchild = CreateNode(r);
            Q.push(nowNode->rchild);
        }
    }
    cin >> temp;
}

// ������������������
void CreateInThread(ThreadTree T)
{
    preNode = NULL;
    if (NULL != T)
    {
        InThread(T); // ��һ�������ֱ�����ʽ����������������ʽ
        if (NULL == preNode->rchild)
        { // �����������һ�����������
            preNode->rtag = 1;
        }
    }
}
// �ҵ���pΪ���������У���һ������������Ľ��
ThreadNode *FirstNode(ThreadNode *p)
{
    while (0 == p->ltag)
    { // ѭ���ҵ������½��
        p = p->lchild;
    }
    return p;
}

// �����������������ҵ����p�ĺ�̽��
ThreadNode *NextNode(ThreadNode *p)
{
    if (0 == p->rtag)
    {
        // �����������е������½��
        return FirstNode(p->rchild);
    }
    else
    {
        return p->rchild; // rtag == 1 ֱ�ӷ��غ������
    }
}

// �ҵ���pΪ���������У����һ������������ĵ�
ThreadNode *LastNode(ThreadNode *p)
{
    // ѭ���ҵ������½�㣨��һ����Ҷ�ڵ㣩
    while (0 == p->rtag)
    {
        p = p->rchild;
    }
    return p;
}

// �������������������ҵ�p��ǰ��
ThreadNode *PreNode(ThreadNode *p)
{
    if (p->ltag == 0)
    {
        // �����������������½��
        return LastNode(p->lchild);
    }
    else
    {
        return p->lchild;
    }
}

// �����ڵ����ǰ�����
void TravelNode(ThreadNode *node)
{
    if (NULL == node->lchild)
    {
        preNodeValue[node->data] = 0;
    }
    else
    {
        if (node->ltag == 1)
        {
            preNodeValue[node->data] = node->lchild->data;
        }
        else
        {
            ThreadNode *p1;
            p1 = PreNode(node);
            preNodeValue[node->data] = p1->data;
        }
    }
    if (NULL == node->rchild)
    {
        aftNodeValue[node->data] = 0;
    }
    else
    {
        if (node->rtag == 1)
        {
            aftNodeValue[node->data] = node->rchild->data;
        }
        else
        {
            ThreadNode *p;
            p = NextNode(node);
            aftNodeValue[node->data] = p->data;
        }
    }
}
// ������������������������������ǵݹ��㷨��
void InOrder(ThreadNode *T)
{
    for (ThreadNode *p = FirstNode(T); p != NULL; p = NextNode(p))
    {
        TravelNode(p);
    }
}


int main()
{
    int tempNum;
    cin >> tempNum;
    while (tempNum--)
    {
        nums.clear();
        nums.push_back(0);
        ThreadTree T;
        InitThreadTree(T);
        CreateBiTree(T);   // ����������
        CreateInThread(T); // ��������������
        InOrder(T);        // ����������
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                continue;
            cout << preNodeValue[nums[i]] << " " << aftNodeValue[nums[i]] << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
1 2 3 4 0 0 5 6 7 8 9 0 0 0 0 0 0 0 0 -1
*/