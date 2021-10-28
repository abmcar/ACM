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
// #define endl "\n"
// #define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const ll Maxn = 500010;
const ll Mod = 1e9 + 7;

struct Node
{
    ll l, r, sum, d;
} node[Maxn * 5];

ll n, m;
ll num[Maxn];

ll lc(ll x) { return x * 2; }
ll rc(ll x) { return x * 2 + 1; }

void pushUp(Node &x, Node &l, Node &r)
{
    x.sum = l.sum + r.sum;
    x.d = __gcd(l.d, r.d);
}

void pushUp(ll x)
{
    pushUp(node[x], node[lc(x)], node[rc(x)]);
}

void build(ll x, ll l, ll r)
{
    node[x].l = l;
    node[x].r = r;
    if (l == r)
    {
        node[x].sum = num[l] - num[l - 1];
        node[x].d = num[l] - num[l - 1];
        return;
    }
    ll mid = (l + r) / 2;
    build(lc(x), l, mid);
    build(rc(x), mid + 1, r);
    pushUp(x);
}

void modify(ll x, ll l, ll r, ll val)
{
    // cout << x << " " << node[x].l << " " << node[x].r << endl;
    if (node[x].l >= l && node[x].r <= r)
    {
        node[x].sum += val;
        node[x].d += val;
        // cout << x << " " << l << " " << node[x].sum << endl;
        return;
    }
    ll mid = (node[x].l + node[x].r) / 2;
    // if (mid >= r)
    if (l <= mid)
        modify(lc(x), l, r, val);
    // if (mid + 1 <= l)
    else
        modify(rc(x), l, r, val);
    pushUp(x);
}

Node query(ll x, ll l, ll r)
{
    // cout << x << " " << node[x].l << " " << node[x].r << " " << l << " " << r << endl;
    if (node[x].l >= l && node[x].r <= r)
        return node[x];
    ll mid = (node[x].l + node[x].r) / 2;
    // if (mid >= r)
    if (r <= mid)
        return query(lc(x), l, r);
    // if (mid + 1 <= l)
    if (l > mid)
        return query(rc(x), l, r);
    Node nowNode;
    Node n1 = query(lc(x), l, r);
    Node n2 = query(rc(x), l, r);
    pushUp(nowNode, n1, n2);
    return nowNode;
}

signed main()
{
    // Buff;
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
            Node leftNode = query(1, 1, arg1);
            Node rightNode{0, 0, 0, 0};
            if (arg1 + 1 <= arg2)
                rightNode = query(1, arg1 + 1, arg2);
            // cout << leftNode.sum << " " << rightNode.d << endl;
            cout << abs(__gcd(leftNode.sum, rightNode.d)) << endl;
        }
        else
        {
            cin >> arg1 >> arg2 >> arg3;
            modify(1, arg1, arg1, arg3);
            if (arg2 + 1 <= n)
                modify(1, arg2 + 1, arg2 + 1, -1*arg3);
        }
    }
    return 0;
}