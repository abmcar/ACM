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
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const ll Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

ll n, m, w;
ll arr[Maxn];
ll d[Maxn];

bool check(ll nowAns)
{
    // memset(d, 0, sizeof d);
    ll nowAdd = 0;
    ll nowUse = 0;
    for (int i = 1; i <= n; i++)
        d[i] = 0;
    for (ll i = 1; i <= n; i++)
    {
        nowAdd += d[i];
        // cout << i << " " << arr[i] << " " << nowAdd << " " << nowAns << endl;
        if (arr[i] + nowAdd < nowAns)
        {
            ll temp = nowAns - (arr[i] + nowAdd);
            nowUse += temp;
            nowAdd += temp;
            d[i+w] -= temp;
        }
        // nowAdd += d[i];
    }
    // cout << nowAns << " " << nowUse << endl;
    return nowUse <= m;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> m >> w;
    for (ll i = 1; i <= n; i++)
        cin >> arr[i];
    ll l, r, ans;
    l = 1;
    r = 2e9;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        // cout << l << " " << r << endl;
        if (check(mid))
        {
            l = mid + 1;
            ans = mid;
        }else
            r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}