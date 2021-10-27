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
const ll Mod = 1e9 + 7;

int n, m;
int num[Maxn];

struct Node
{
    int l, r, val;
    int sum, tMax, lMax, rMax;
} node[Maxn];

int lc(int x) { return x * 2; }
int rc(int x) { return x * 2 + 1; }

void pushUp(Node &u, Node &l, Node &r)
{
    u.sum = l.sum + r.sum;
    u.lMax = max(l.lMax, l.sum + r.lMax);
    u.rMax = max(r.rMax, r.sum + l.rMax);
    u.tMax = max(max(l.tMax, r.tMax), l.rMax + r.lMax);
}

void pushUp(int x)
{
    pushUp(node[x], node[lc(x)], node[rc(x)]);
}

void build(int x, int l, int r)
{
    node[x].l = l;
    node[x].r = r;
    if (l == r)
    {
        node[x].lMax = node[x].rMax = node[x].sum = node[x].tMax = num[l];
        return;
    }
    int mid = (l + r) / 2;
    build(lc(x), l, mid);
    build(rc(x), mid + 1, r);
    pushUp(x);
}

void modify(int x, int l, int r, int val)
{
    Node *nowNode = &node[x];
    if (nowNode->l >= l && nowNode->r <= r)
    {
        nowNode->val = val;
        nowNode->lMax = nowNode->rMax = nowNode->sum = nowNode->tMax = val;
        return;
    }
    int mid = (nowNode->l + nowNode->r) / 2;
    if (mid >= l)
        modify(lc(x), l, r, val);
    if (mid + 1 <= r)
        modify(rc(x), l, r, val);
    pushUp(x);
}

Node query(int pos, int l, int r)
{
    Node x = node[pos];
    // cout << pos << " " << x.l << " " << x.r << " " << l << " " << r << "    !" << endl;
    if (x.l >= l && x.r <= r)
        return x;
    int mid = (x.l + x.r) / 2;
    Node nowNode;
    if (mid >= r)
        return query(lc(pos), l, r);
    else if (mid  < l)
        return query(rc(pos), l, r);
    else
    {
        Node n1 = query(lc(pos), l, r);
        Node n2 = query(rc(pos), l, r);
        pushUp(nowNode, n1, n2);
    }
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
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    build(1,1,n);
    for (int i = 1; i <= m; i++)
    {
        int opt, arg1, arg2;
        cin >> opt >> arg1 >> arg2;
        if (opt == 1)
        {
            if (arg1 > arg2)
                swap(arg1, arg2);
            cout << query(1, arg1, arg2).tMax << endl;
        }
        else
            modify(1, arg1, arg1, arg2);
    }
    return 0;
}