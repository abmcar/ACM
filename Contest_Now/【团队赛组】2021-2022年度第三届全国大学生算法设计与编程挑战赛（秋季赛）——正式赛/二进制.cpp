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

const ll Maxn = 1e5 + 10;
const ll Size = 11;
const ll Mod = 1e9 + 7;

ll n, q;
ll ans1[Size][Maxn];
ll ans2[Size][Maxn];

inline ll lowbit(ll x)
{
    return x & (-x);
}

inline void add(ll deep, ll pos, ll val)
{
    // for (ll i = pos; i < Maxn; i += lowbit(i))
    //     ans1[deep][i] = max(ans1[deep][i],0LL);
    for (ll i = pos; i < Maxn; i += lowbit(i))
        ans2[deep][i] = (ans2[deep][i] > 0 ? ans2[deep][i] : ans2[deep][i]);
    for (ll i = pos; i < Maxn; i += lowbit(i))
    {
        ans1[deep][i] += val;
        ans2[deep][i] += val * (pos - 1);
    }
}

inline void update(ll deep, ll l, ll r, ll val)
{
    // add(deep, l, val);
    // add(deep, l, -val);
    add(deep, l, val);
    add(deep, r + 1, -1 * val);
}

inline ll query(ll deep, ll pos)
{
    ll ans = 0;
    for (ll i = pos; i >= 1; i -= lowbit(i))
        ans = ans + ans, ans = ans / 2;
    for (ll i = pos; i >= 1; i -= lowbit(i))
        ans += ans1[deep][i] * pos - ans2[deep][i];
    return ans;
}

inline void opt1(ll deep, ll l, ll r)
{
    ll k;
    cin >> k;
    ll nowDeep = 0;
    do
    {
        k++;
        if (deep % 2 == 1)
            update(nowDeep, l, r, k-1);
        nowDeep++;
        deep /= 2;
        k--;
    } while (deep);
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> q;
    for (ll i = 1; i <= q; i++)
    {
        ll nowOpt, nowL, nowR, nowDeep, nowK;
        cin >> nowOpt >> nowDeep >> nowL >> nowR;
        if (nowOpt == 1)
            opt1(nowDeep, nowL, nowR);
        else
        {
            ll ans = 0;
            ll deep = 0;
            do
            {
                if (nowDeep % 2)
                {
                    ans += query(deep, nowR);
                    ans -= query(deep, nowL - 1);
                }
                deep++;
                nowDeep /= 2;
            } while (nowDeep);
            cout << ans << endl;
        }
    }
    return 0;
}
