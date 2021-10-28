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
#define String string
#define endl "\n"
#define Endl "\n"
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const ll Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

ll n, m;
ll num[Maxn];

struct Node
{
    ll l, r, sum, add;
    ll len()
    {
        return r - l + 1;
    }
    void prll()
    {
        cout << l << " " << r << " " << sum << ' ' << add << endl;
    }
} node[Maxn];

ll lc(ll x) { return x * 2; }
ll rc(ll x) { return x * 2 + 1; }

void pushUp(Node &x, Node &l, Node &r)
{
    x.sum = l.sum + r.sum;
}

void pushUp(ll x)
{
    pushUp(node[x], node[lc(x)], node[rc(x)]);
    // cout << " pushUp " << x << " ";
    // node[x].prll();
    // node[lc(x)].prll();
    // node[rc(x)].prll();
}

void pushDown(ll x)
{
    node[lc(x)].add += node[x].add;
    node[rc(x)].add += node[x].add;
    node[lc(x)].sum += node[x].add * node[lc(x)].len();
    node[rc(x)].sum += node[x].add * node[rc(x)].len();
    node[x].add = 0;
    // pushUp(x);
}

void build(ll x, ll l, ll r)
{
    node[x].l = l;
    node[x].r = r;
    if (l == r)
    {
        node[x].sum = num[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(lc(x), l, mid);
    build(rc(x), mid + 1, r);
    pushUp(x);
}

void modify(ll x, ll l, ll r, ll val)
{
    // cout << "modifyStr ";
    // cout << x << " " << l << " " << r << " " << val << " ";
    // node[x].prll();
    if (node[x].l >= l && node[x].r <= r)
    {
        node[x].add += val;
        node[x].sum += val * node[x].len();
        // cout << "modifyEnd ";
        // cout << x << " " << l << " " << r << " " << val << " ";
        // node[x].prll();
        return;
    }
    if (node[x].add)
        pushDown(x);
    ll mid = (node[x].l + node[x].r) / 2;
    if (l <= mid)
        modify(lc(x), l, r, val);
    if (mid + 1 <= r)
        modify(rc(x), l, r, val);
    pushUp(x);
    // cout << "modifyEnd ";
    // cout << x << " " << l << " " << r << " " << val << " ";
    // node[x].prll();
}

Node query(ll x, ll l, ll r)
{
    // cout << "query ";
    // cout << x << " " << l << " " << r << " ";
    // node[x].prll();
    if (node[x].l >= l && node[x].r <= r)
        return node[x];
    ll mid = (node[x].l + node[x].r) / 2;
    if (node[x].add)
        pushDown(x);
    if (r <= mid)
        return query(lc(x), l, r);
    if (l >= mid + 1)
        return query(rc(x), l, r);
    Node nowNode;
    Node n1 = query(lc(x), l, r);
    Node n2 = query(rc(x), l, r);
    pushUp(nowNode, n1, n2);
    return nowNode;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
        cin >> num[i];
    build(1, 1, n);
    for (ll i = 1; i <= m; i++)
    {
        char opt;
        ll arg1, arg2, arg3;
        cin >> opt;
        if (opt == 'Q')
        {
            cin >> arg1 >> arg2;
            cout << query(1, arg1, arg2).sum << endl;
        }
        else
        {
            cin >> arg1 >> arg2 >> arg3;
            modify(1, arg1, arg2, arg3);
        }
    }
    return 0;
}