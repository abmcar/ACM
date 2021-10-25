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
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

ll n, w, t;
ll nowMaxn;
ll nowAns;

void work()
{
    cin >> n >> w;
    map<ll,ll> M;
    nowMaxn = nowAns = 0;
    nowAns++;
    ll nowLess = w;
    for (int i = 1; i <= n; i++)
    {
        ll temp;
        cin >> temp;
        M[temp]++;
        nowMaxn = max(nowMaxn,temp);
    }
    for (int i = 0; i < n;)
    {
        while(M[nowMaxn] == 0)
            nowMaxn = nowMaxn / 2;
        for (ll j = nowMaxn; j; j = j/2)
        {
            // cout << nowLess << " " << nowAns << " " << i << " " << j << endl;
            if (nowLess >= j)
            {
                if (M[j] == 0)
                    continue;
                int nowUse = min(M[j],nowLess/j);
                M[j] = M[j] - nowUse;
                nowLess = nowLess - nowUse*j;
                i += nowUse;
                if (nowLess == 0)
                    break;
            }
        }
        if (i == n)
            break;
        nowLess = w, nowAns++;
    }
    cout << nowAns << endl;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}