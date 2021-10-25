#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;

int t,n,s;

void work()
{
    cin >> n >> s;
    if(n == 1)
    {
        if(s > 9)
        {
            cout << "-1" << endl;
            return;
        }
        cout << s << endl;
        return;
    }
    if(s < 2 || s > n*9)
    {
        cout << "-1" << endl;
        return;
    }
    bool nisOdd,sisOdd;
    if(n % 2 == 1)
        nisOdd = true;
    else
        nisOdd = false;
    if(s % 2 == 1)
        sisOdd = true,s--;
    else
        sisOdd = false;
    if(!nisOdd && sisOdd)
    {
        cout << "-1" << endl;
        return;
    }
    stack<int> S;
    for(int i = 1; i <= n/2; i++)
    {
        int nownum = 0;
        if(s != 0)
        {
            s = s - 9*2;
            nownum = 9;
        }
        if(s < 0)
        {
            nownum += s/2;
            s = 0;
        }
        cout << nownum;
        S.push(nownum);
    }
    if(nisOdd)
    {
        int nownum = 0;
        if(sisOdd)
            nownum++;
        if(s != 0)
            nownum += s;
        cout << nownum;
    }
    while(!S.empty())
    {
        cout << S.top();
        S.pop();
    }
    cout << endl;
}

int main()
{
    Buff;
    cin >> t;
    while(t--)
        work();
    return 0;
}