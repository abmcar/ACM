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
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <bits/extc++.h>
// #include <bits/stdc++.h>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf ll_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const ll Maxn = 2e5 + 10;
const ll Mod = 1e9 + 7;

ll t, n, nowAns;
ll arr[Maxn], d[Maxn];
ll g[Maxn][20];
ll low[Maxn];

ll query(int l, int r)
{
    int p = low[r - l + 1];
    return __gcd(g[l][p], g[r - (1 << p) + 1][p]);
}

bool check(int mid)
{
    for (int i = 1; i <= n - mid; i++)
        if (query(i, i + mid - 1) > 1)
            return true;
    return false;
}

void work()
{
    // clock_t t1 = clock();
    nowAns = 0;
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> arr[i];
    for (ll i = 1; i < n; i++)
        d[i] = abs(arr[i + 1] - arr[i]), g[i][0] = d[i];
    for (int p = 1; (1 << p) < n; p++)
        for (int i = 1; i + (1 << p) - 1 < n; i++)
            g[i][p] = __gcd(g[i][p - 1], g[i + (1 << (p - 1))][p - 1]);
    for (int i = 2; i < n; i++)
        low[i] = low[i >> 1] + 1;
    int l, r;
    l = 1;
    r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        // cout << l << " " << r << " " << mid << endl;
        if (check(mid))
        {
            nowAns = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    // for (ll i = 1; i <= n - nowAns; i++)
    // {

    //     ll nowLen = 2;
    //     ll nowGcd = d[i];
    //     if (nowGcd == 1)
    //         continue;
    //     for (ll j = i + 1; j < n; j++)
    //     {
    //         nowGcd = __gcd(nowGcd, d[j]);
    //         if (nowGcd == 1)
    //             break;
    //         nowLen++;
    //     }
    //     i = i + max(0LL, nowLen - 2);
    //     // cout << nowGcd << " " << nowMax << " " << nowLen << endl;
    //     nowAns = max(nowAns, nowLen);
    // }
    // cout << clock() - t1 << endl;
    cout << nowAns + 1 << endl;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> t;
    while (t--)
        work();
    return 0;
}