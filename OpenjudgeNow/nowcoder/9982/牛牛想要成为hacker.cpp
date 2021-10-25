#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#define ll long long

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;
int n;
queue<int> q;
stack<int> s;

int main()
{
    std::ios::sync_with_stdio(false);
    int strn = 1;
    int a,b,c;
    a = b = 1;
    int tnum = 2;
    cin >> n;
    s.push(1);
    s.push(1);
    for(c = a+b; c <= 1e9 && tnum <= n; c = a+b)
    {
        if(s.size() == n)
            break;
        tnum++;
        a = b;
        b = c;
        s.push(c);
    }
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    for(int i = tnum; i < n; i++)
        cout << "1 ";
    return 0;
}
/*
1 1 2 3 
2 2 
*/
