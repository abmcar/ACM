#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
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

const int Maxn = 1e3+10;
const ll Mod = 1e9+7;

int t, fn ,fk;
int fans[Maxn][Maxn][3];
ll fun(int n,int k, int d)
{
    if(k == 1)
        return 1;
    if(fans[n][k][d] != 0)
        return fans[n][k][d];
    int ans = 2;
    if(d == 1)
    {
        if(n > 1)
            ans = (ans + fun(n-1,k-1,1-d)-1) % Mod;
        if(n < fn)
            ans = (ans + fun(n+1,k,d)-1) % Mod;  
    }else
    {
        if(n < fn)
            ans = (ans + fun(n+1,k-1,1-d)-1) % Mod;
        if(n > 1)
            ans = (ans + fun(n-1,k,d)-1) % Mod;  
    }
    fans[n][k][d] = ans;
    return ans;
}

void work()
{
    cin >> fn >> fk;
    memset(fans,0,sizeof(fans));
    cout << fun(1,fk,1) << endl;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}

/*
f(n,k) = 1 + f(n-1,k)
f(n,k) = 2*f(n,k-1)
f(1,1) = 1;
f(1,k) = 2;
*/