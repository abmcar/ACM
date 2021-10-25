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
int n,cnt;

ll quickPow(ll x, ll p)
{
    ll now = 1;
    ll base = x;
    while(p != 0)
    {
        if(p % 2 == 1)
        {
            now = now * base % Mod;
            p--;
            continue;
        }
        base = base * base % Mod;
        p = p / 2;
    }
    // cout << x << endl;
    return now;
}

int main()
{
    Buff;
    while (cin >> n >> cnt)
    {
        ll now = 0;
        for(int i = 1; i <= n; i++)
        {
            ll temp;
            cin >> temp;
            now = now+temp;
        }
        if(n == 2)
        {
            cout << now - cnt << endl;
            continue;
        }
        cnt = cnt % 11;
        now = now % 11;
        if(now >= cnt)
            cout << now-cnt << endl;
        else
            cout << now-cnt+11 << endl;
    }
    
    return 0;
}
/*
(a % Mod + b % Mod) = c % Mod;
*/