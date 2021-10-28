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

struct Node
{
    ll l, r, sum;
    bool tag;
    ll len()
    {
        return r - l + 1;
    }
} node[Maxn];
ll n, m;
String oriString;

ll lc(ll x) { return x * 2; }
ll rc(ll x) { return x * 2 + 1; }

void pushUp(Node &x, Node &l, Node &r)
{
    x.sum = l.sum + r.sum;
}

void pushUp(ll x)
{
    pushUp(node[x], node[lc(x)], node[rc(x)]);
}

void pushDown(ll x)
{
    node[x].tag = 0;
    node[lc(x)].tag = !node[lc(x)].tag;
    node[rc(x)].tag = !node[rc(x)].tag;
    node[lc(x)].sum = node[lc(x)].len() - node[lc(x)].sum;
    node[rc(x)].sum = node[rc(x)].len() - node[rc(x)].sum;
    pushUp(x);
}

void build(ll x, ll l, ll r)
{
    node[x].l = l;
    node[x].r = r;
    if (l == r)
    {
        node[x].sum = oriString[l - 1] - '0';
        // cout << "!!!" << x << " " << l << " " << node[x].sum << Endl;
        return;
    }
    ll mid = (l + r) / 2;
    build(lc(x), l, mid);
    build(rc(x), mid + 1, r);
    pushUp(x);
}

void modify(ll x, ll l, ll r)
{
    if (node[x].l >= l && node[x].r <= r)
    {
        node[x].sum = node[x].len() - node[x].sum;
        node[x].tag = !node[x].tag;
        return;
    }
    if (node[x].tag)
        pushDown(x);
    ll mid = (node[x].l + node[x].r) / 2;
    if (mid >= l)
        modify(lc(x), l, r);
    if (mid + 1 <= r)
        modify(rc(x), l, r);
    pushUp(x);
}

ll query(ll x, ll l, ll r)
{
    // cout << x << " " << node[x].l << " " << node[x].r << " " << l << " " << r << endl;
    if (node[x].l >= l && node[x].r <= r)
        return node[x].sum;
    if (node[x].tag)
        pushDown(x);
    ll mid = (node[x].l + node[x].r) / 2;
    ll cnt = 0;
    if (mid >= l)
        cnt += query(lc(x), l, r);
    if (mid + 1 <= r)
        cnt += query(rc(x), l, r);
    return cnt;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> m;
    cin >> oriString;
    build(1, 1, n);
    for (ll i = 1; i <= m; i++)
    {
        char opt;
        ll l, r;
        cin >> opt >> l >> r;
        if (opt == '0')
            modify(1, l, r);
        else
            cout << query(1, l, r) << endl;
    }
    return 0;
}