#include <bits/stdc++.h>
using namespace std;

typedef struct ThreadNode
{
    int data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

ThreadNode *preNode = NULL; // 全局变量，用来记录当前结点的前驱结点

// 线索化处理每一个结点
void travel(ThreadNode *nowNode)
{
    if (NULL == nowNode->lchild)
    { // 当前结点的前驱为空，为他建立前驱线索
        nowNode->lchild = preNode;
        nowNode->ltag = 1;
    }

    if (NULL != preNode && NULL == preNode->rchild)
    { // 为前驱结点建立后继线索
        preNode->rchild = nowNode;
        preNode->rtag = 1;
    }
    preNode = nowNode; // 后移，以便访问下一个结点
}

// 线索二叉树初始化
void InitThreadTree(ThreadTree &T)
{
    T == NULL;
}

// 中序线索
void InThread(ThreadTree T)
{
    if (NULL != T)
    {
        InThread(T->lchild); // 递归遍历左子树
        travel(T);            // 访问根节点
        InThread(T->rchild); // 递归遍历右子树
    }
}

// 建立二叉树结点并返回结点地址
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

// 建立二叉树
void CreateBiTree(ThreadTree &T)
{
    int temp;
    cin >> temp;
    nums.push_back(temp);
    T = CreateNode(temp);
    // 队列储存当前层节点
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
        // 如果非空压入队列
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

// 建立中序线索二叉树
void CreateInThread(ThreadTree T)
{
    preNode = NULL;
    if (NULL != T)
    {
        InThread(T); // 这一行是哪种遍历方式就是哪种线索化方式
        if (NULL == preNode->rchild)
        { // 遍历到的最后一个结点线索化
            preNode->rtag = 1;
        }
    }
}
// 找到以p为根的子树中，第一个被中序遍历的结点
ThreadNode *FirstNode(ThreadNode *p)
{
    while (0 == p->ltag)
    { // 循环找到最左下结点
        p = p->lchild;
    }
    return p;
}

// 中序线索二叉树中找到结点p的后继结点
ThreadNode *NextNode(ThreadNode *p)
{
    if (0 == p->rtag)
    {
        // 返回右子树中的最左下结点
        return FirstNode(p->rchild);
    }
    else
    {
        return p->rchild; // rtag == 1 直接返回后继线索
    }
}

// 找到以p为根的子树中，最后一个被中序遍历的点
ThreadNode *LastNode(ThreadNode *p)
{
    // 循环找到最右下结点（不一定是叶节点）
    while (0 == p->rtag)
    {
        p = p->rchild;
    }
    return p;
}

// 在中序线索二叉树中找到p的前驱
ThreadNode *PreNode(ThreadNode *p)
{
    if (p->ltag == 0)
    {
        // 返回左子树中最右下结点
        return LastNode(p->lchild);
    }
    else
    {
        return p->lchild;
    }
}

// 遍历节点查找前驱后继
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
// 对中序线索二叉树进行中序遍历（非递归算法）
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
        CreateBiTree(T);   // 建立二叉树
        CreateInThread(T); // 建立线索二叉树
        InOrder(T);        // 中序遍历输出
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