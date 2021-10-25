#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

int t;
int n;
/*
1 2 3
1 3
2
1 2 3 4 5 6
1 2 3 4 6
1 2 3 5
1 2 4
1 3
2

*/
void work()
{
    stack<int> s;
    cin >> n;
    cout << "2" << endl;
    for(int i = 1; i <= n; i++)
        s.push(i);
    while(s.size() != 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        cout << a << " " << b << endl;
        s.push((a+b+1)/2);
    }
}

int main()
{
    cin >> t;
    for(int i = 1; i <= t; i++)
        work();
    return 0;
}