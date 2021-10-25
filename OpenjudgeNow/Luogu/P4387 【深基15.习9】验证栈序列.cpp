#include <iostream>
#include <stack>

using namespace std;

int q;
int n;
int temppush[233333];
int temppop[233333];

void work()
{
    cin >> n;
    stack<int> pushed;
    stack<int> poped;
    for (int i = 1; i <= n; i++)
        cin >> temppush[i];
    for (int i = 1; i <= n; i++)
        cin >> temppop[i];
    for (int i = n; i >= 1; i--)
        poped.push(temppop[i]);
    for (int i = 1; i <= n; i++)
    {
        pushed.push(temppush[i]);
        while(pushed.top() == poped.top())
        {
            pushed.pop();
            poped.pop();
            if(pushed.empty())
                break;
        }
    }
    if (!pushed.empty())
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}

int main()
{
    cin >> q;
    for (int i = 1; i <= q; i++)
        work();
    return 0;
}