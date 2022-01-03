#include <bits/stdc++.h>
#define DataType int
const int Maxn = 100;

using namespace std;

class SeqStack
{
public:
    void push(DataType value);
    void pop();
    bool isEmpty();
    DataType getTop();
    void push_back(DataType value);
    void pop_back();
    bool isEmpty_back();
    DataType getTail();
    SeqStack();
private:
    int top, tail, maxNum;
    DataType *nums;
};

SeqStack::SeqStack()
{
    maxNum = Maxn;
    nums = new DataType[maxNum];
    top = 0;
    tail = Maxn-1;
    cout << "Create stack" << endl;
}

void SeqStack::push(DataType value)
{
    cout << "Push " << value << endl;
    if (top + 1 == tail)
    {
        cout << "Push fail, stack full" << endl;
        return;
    }
    nums[top++] = value;
}

bool SeqStack::isEmpty()
{
    cout << "Check empty:" << endl;
    if (top == 0)
        return true;
    return false;
}

void SeqStack::pop()
{
    cout << "Pop" << endl;
    if (top == 0)
    {
        cout << "Pop fail, stack empty" << endl;
        return;
    }
    top--;
}

DataType SeqStack::getTop()
{
    cout << "Get top" << endl;
    if (top == 0)
    {
        cout << "Get top fail, stack empty" << endl;
        return 0;
    }
    return nums[top];
}

DataType SeqStack::getTail()
{
    cout << "Get tail" << endl;
    if (tail == maxNum-1)
    {
        cout << "Get tail fail, stack empty" << endl;
        return 0;
    }
    return nums[tail];
}

bool SeqStack::isEmpty_back()
{
    cout << "Check empty" << endl;
    if (tail == maxNum-1)
        return true;
    return false;
}

void SeqStack::pop_back()
{
    cout << "Pop back" << endl;
    if (tail == maxNum-1)
    {
        cout << "Pop back fail, stack empty" << endl;
        return;
    }
    tail--;
}

void SeqStack::push_back(DataType value)
{
    cout << "Push back " << value << endl;
    if (tail-1 == top)
    {
        cout << "Push back fail, stack full" << endl;
        return;
    }
    nums[tail--] = value;
}

int main()
{
    SeqStack nowStack;
    cout << nowStack.isEmpty() << endl;
    nowStack.push(1);
    cout << nowStack.isEmpty() << endl;
    nowStack.pop();
    nowStack.getTop();
    cout << nowStack.isEmpty() << endl;
    return 0;
}