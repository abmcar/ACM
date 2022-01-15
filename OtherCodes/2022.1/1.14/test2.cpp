#include <bits/stdc++.h>
#include "LinkList.h"

using namespace std;

int main()
{
    ListNode *l1, *l2, *l3;
    InitList(l1);
    InitList(l2);
    InitList(l3);

    insertNum(1, 1, l1);
    insertNum(2, 2, l1);
    insertNum(3, 3, l1);

    cout << LengthList(l1) << endl;
    cout << EmptyList(l1) << endl;
    TraveralList(l1);
    DeleteNum(1,l1);
    TraveralList(l1);
    cout << GetList(l1,2) << endl;

    ClearList(l1);

    cout << LengthList(l1) << endl;
    cout << EmptyList(l1) << endl;

    insertNum(1, 1, l1);
    insertNum(3, 2, l1);
    insertNum(5, 3, l1);
    insertNum(2, 1, l2);
    insertNum(4, 2, l2);
    insertNum(6, 3, l2);

    MergeList(l1,l2,l3);

    TraveralList(l3);
    return 0;
}