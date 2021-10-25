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

int t;
ll x,y,k;

void work()
{
    cin >> x >> y >> k;
    if(x + y == 0)
    {
        cout << "0" << endl;
        return;
    }
    if(x == 0)
    {
        if(k/y * y == k)
            cout << "1" << endl;
        else
            cout << "0" << endl;
        return;
    }
    if(y == 0)
    {
        if(k/x * x == k)
            cout << "1" << endl;
        else
            cout << "0" << endl;
        return;
    }
    cout << min(k/x,k/y) << endl;
    
}

int main()
{
    Buff;
    cin >> t;
    while(t--)
        work();
    return 0;
}
/*
ax + by >= k
*/