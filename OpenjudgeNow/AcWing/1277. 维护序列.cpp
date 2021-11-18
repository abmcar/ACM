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

const int Maxn = 1e7 + 10;
ll Mod = 1e9 + 7;

int n, p;
ll nums[Maxn];

struct Node
{
    ll l, r, add, mul, sum;
    ll mid() { return (l + r) / 2; }
    ll size() { return (r - l + 1); }
} node[Maxn];

int lc(int x) { return x * 2; }
int rc(int x) { return x * 2 + 1; }

void eval(int x, int add, int mul)
{
    node[x].sum = (node[x].sum * mul + node[x].size() * add) % Mod;
    node[x].add = (node[x].add * mul + add) % Mod;
    node[x].mul = (node[x].mul * mul) % Mod;
}

void pushUp(int x)
{
    node[x].sum = (node[lc(x)].sum + node[rc(x)].sum) % Mod;
}

void pushDown(int x)
{
    eval(lc(x), node[x].add, node[x].mul);
    eval(rc(x), node[x].add, node[x].mul);
    node[x].add = 0;
    node[x].mul = 1;
}

void build(int x, int l, int r)
{
    node[x].l = l;
    node[x].r = r;
    node[x].add = 0;
    node[x].mul = 1;
    if (l == r)
    {
        node[x].sum = nums[l];
        return;
    }
    build(lc(x), l, node[x].mid());
    build(rc(x), node[x].mid() + 1, r);
    pushUp(x);
}

void modify(int x, int l, int r, int add, int mul)
{
    if (node[x].l >= l && node[x].r <= r)
    {
        eval(x,add,mul);
        return;
    }
    pushDown(x);
    if (node[x].mid() >= l)
        modify(lc(x), l, r, add, mul);
    if (node[x].mid()+1 <= r)
        modify(rc(x), l, r, add, mul);
    pushUp(x);
}

int query(int x, int l, int r)
{
    if (node[x].l >= l && node[x].r <= r)
        return node[x].sum;
    pushDown(x);
    ll nowNum = 0;
    if (node[x].mid() >= l)
        nowNum += query(lc(x), l, r);
    if (node[x].mid() + 1 <= r)
        nowNum += query(rc(x), l, r);
    nowNum = nowNum % Mod;
    return nowNum;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> p;
    Mod = p;
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    build(1, 1, n);
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int opt, l, r, value;
        cin >> opt >> l >> r;
        if (opt == 1)
        {
            cin >> value;
            modify(1, l, r, 0, value);
        }
        else if (opt == 2)
        {
            cin >> value;
            modify(1, l, r, value, 1);
        }
        else if (opt == 3)
        {
            cout << query(1, l, r) << endl;
        }
    }
    return 0;
}