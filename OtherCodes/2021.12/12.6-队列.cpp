#include <bits/stdc++.h>
#define DataType int

using namespace std;

const int Maxn = 100;

class SeqQueue
{
public:
    SeqQueue();
    void push(DataType value);
    void pop();
    bool isEmpty();
    DataType getFront();
private:
    int maxNum;
    int front, tail;
    int *nums;
};

SeqQueue::SeqQueue()
{
    maxNum = Maxn;
    front = tail = 0;
    nums = new DataType[maxNum];
    cout << "Create queue" << endl;
}

DataType SeqQueue::getFront()
{
    cout << "Get front" << endl;
    if (front == tail)
    {
        cout << "Get front fail, queue empty" << endl;
        return 0;
    }
    return nums[front];
}

bool SeqQueue::isEmpty()
{
    cout << "Check emtpy" << endl;
    if (front == tail)
        return true;
    return false;
}

void SeqQueue::pop()
{
    cout << "Pop" << endl;
    if (tail == front)
    {
        cout << "Pop fail, queue empty" << endl;
        return;
    }
    front++;
    front = front % maxNum;
}

void SeqQueue::push(DataType value)
{
    cout << "Push " << value << endl;
    if ((tail+1)%maxNum == front)
    {
        cout << "Push fail, queue full" << endl;
        return;
    }
    nums[tail++] = value;
    tail = tail % maxNum;
}

int main()
{
    SeqQueue nowQueue;
    cout << nowQueue.isEmpty() << endl;
    nowQueue.push(1);
    cout << nowQueue.isEmpty() << endl;
    cout << nowQueue.getFront() << endl;
    nowQueue.pop();
    cout << nowQueue.getFront() << endl;
    cout << nowQueue.isEmpty() << endl;
}