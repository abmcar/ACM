#include <bits/stdc++.h>
#include "test4.h"

using namespace std;

int main()
{
    Queue Q;
    InitQueue(Q);
    cout << EmptyQueue(Q) << endl;
    EnQueue(Q, "a");
    EnQueue(Q, "b");
    EnQueue(Q, "c");
    EnQueue(Q, "d");
    cout << EmptyQueue(Q) << endl;
    cout << PeekQueue(Q) << endl;
    cout << OutQueue(Q) << endl;
    cout << OutQueue(Q) << endl;
    cout << OutQueue(Q) << endl;
    EnQueue(Q, "a");
    EnQueue(Q, "b");
    EnQueue(Q, "c");
    EnQueue(Q, "d");
    ClearQueue(Q);
    cout << EmptyQueue(Q) << endl;

    partner();
    return 0;
}