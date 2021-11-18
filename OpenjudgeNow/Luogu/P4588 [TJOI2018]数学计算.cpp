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
ll Mod = 1e9 + 7;

ll t, n, m;
ll nums[Maxn];

struct Node
{
    ll l, r, sum;
    ll mid() { return (r + l) / 2; }
} node[Maxn];

ll lc(ll x) { return x * 2; }
ll rc(ll x) { return x * 2 + 1; }

void pushUp(ll x)
{
    node[x].sum = node[lc(x)].sum * node[rc(x)].sum % Mod;
}

void build(ll x, ll l, ll r)
{
    node[x].l = l;
    node[x].r = r;
    if (l == r)
    {
        node[x].sum = nums[l];
        return;
    }
    build(lc(x), l, node[x].mid());
    build(rc(x), node[x].mid() + 1, r);
    pushUp(x);
}

void modify(ll x, ll pos)
{
    if (node[x].l == pos && node[x].r == pos)
    {
        node[x].sum = 1;
        return;
    }
    if (pos <= node[x].mid())
        modify(lc(x), pos);
    else
        modify(rc(x), pos);
    pushUp(x);
}

ll query(ll x, ll l, ll r)
{
    // cout << x << " " << l << " " << r << endl;
    if (node[x].l >= l && node[x].r <= r)
        return node[x].sum;
    ll nowNum = 1;
    if (node[x].mid() >= l)
        nowNum = nowNum * query(lc(x), l, r) % Mod;
    if (node[x].mid() + 1 <= r)
        nowNum = nowNum * query(rc(x), l, r) % Mod;
    nowNum = nowNum % Mod;
    return nowNum;
}

void work()
{
    memset(nums, 0, sizeof nums);
    ll q;
    cin >> m >> q;
    Mod = q;
    n = 0;
    vector<ll> opts;
    map<ll,ll> M;
    for (ll i = 1; i <= m; i++)
    {
        ll opt, value;
        cin >> opt >> value;
        if (opt == 1)
            nums[++n] = value;
        else
            value = value * -1;
        opts.push_back(value);
        M[i] = n;
    }
    build(1, 1, n);
    // cout << "finsh build" << n <<  endl;
    ll nowNum = 0;
    for (ll i = 0; i < m; i++)
    {
        // cout << " now query " << i << " " << opts[i] << endl;
        if (opts[i] > 0)
        {
            nowNum++;
            cout << query(1, 1, nowNum) << endl;
        }
        else
        {
            modify(1, M[opts[i]*-1]);
            cout << query(1, 1, nowNum) << endl;
        }
    }
    // cout << "finsh query\n";
}

signed main()
{
    // Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> t;
    while (t--)
        work();
    return 0;
}