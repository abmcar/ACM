#include <bits/stdc++.h>

using namespace std;

typedef string DataType;

const int Maxn = 100;

struct Queue
{
    int maxSize;
    int front, tail;
    DataType *nums;
};

void InitQueue(Queue &Q)
{
    Q.maxSize = Maxn;
    Q.front = Q.tail = 0;
    Q.nums = new DataType[Maxn];
}

bool EmptyQueue(Queue &Q)
{
    if (Q.front == Q.tail)
        return true;
    return false;
}

void EnQueue(Queue &Q, DataType e)
{
    if ((Q.tail + 1) % Q.maxSize == Q.front)
        return;
    Q.nums[Q.tail++] = e;
    Q.tail = Q.tail % Q.maxSize;
}

DataType OutQueue(Queue &Q)
{
    DataType nowVal = Q.nums[Q.front++];
    Q.front = Q.front % Q.maxSize;
    return nowVal;
}

DataType PeekQueue(Queue &Q)
{
    return Q.nums[Q.front];
}

void ClearQueue(Queue &Q)
{
    Q.front = Q.tail = 0;
    for (int i = 0; i < Q.maxSize; i++)
        Q.nums[i] = "";
}

void partner()
{
    string s1, s2;
    Queue Q1, Q2;
    InitQueue(Q1);
    InitQueue(Q2);

    while (cin >> s1 >> s2)
    {
        if (s1 == s2 && s1 == "#")
            break;
        if (s2 == "F")
            EnQueue(Q1, s1);
        else
            EnQueue(Q2, s1);
    }

    while (!EmptyQueue(Q1) && !EmptyQueue(Q2))
        cout << OutQueue(Q1) << " " << OutQueue(Q2) << endl;
    if (!EmptyQueue(Q1))
    {
        cout << "女队剩余" << endl;
        cout << PeekQueue(Q1) << "是下一轮得到舞伴的第一人" << endl;
    }
    if (!EmptyQueue(Q2))
    {
        cout << "男队剩余" << endl;
        cout << PeekQueue(Q2) << "是下一轮得到舞伴的第一人" << endl;
    }
}