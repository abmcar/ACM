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
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf ll_MAX
#define endl "\n"

using namespace std;

const ll Maxn = 510000;
const ll Mod = 1e9 + 7;

ll n, m, cntNode, num[Maxn], deep[Maxn], father[Maxn], sons[Maxn], gson[Maxn], id[Maxn], top[Maxn];
ll ans[Maxn], tag[Maxn], temp[Maxn];
vector<ll> g[Maxn];

void dfs1(ll nowNode, ll fatherNode, ll nowDeep)
{
    deep[nowNode] = nowDeep;
    father[nowNode] = fatherNode;
    sons[nowNode] = 1;
    ll maxSons = -1;
    for (ll i = 0; i < g[nowNode].size(); i++)
    {
        ll nextNode = g[nowNode][i];
        if (nextNode == fatherNode)
            continue;
        dfs1(nextNode, nowNode, nowDeep + 1);
        sons[nowNode] += sons[nextNode];
        if (maxSons < sons[nextNode])
        {
            maxSons = sons[nextNode];
            gson[nowNode] = nextNode;
        }
    }
}

void dfs2(ll nowNode, ll topNode)
{
    id[nowNode] = ++cntNode;
    num[cntNode] = temp[nowNode];
    top[nowNode] = topNode;
    if (!gson[nowNode])
        return;
    dfs2(gson[nowNode], topNode);
    for (ll i = 0; i < g[nowNode].size(); i++)
    {
        ll nextNode = g[nowNode][i];
        if (nextNode == father[nowNode] || nextNode == gson[nowNode])
            continue;
        dfs2(nextNode, nextNode);
    }
}

inline ll lc(ll x)
{
    return x * 2;
}

inline ll rc(ll x)
{
    return x * 2 + 1;
}

inline void pushUp(ll x)
{
    ans[x] = ans[lc(x)] + ans[rc(x)];
}

void build(long long pos, long long l, long long r)
{
    tag[pos] = 0;
    if (l == r)
    {
        ans[pos] = num[l];
        return;
    }
    long long mid = (l + r) / 2;
    build(lc(pos), l, mid);
    build(rc(pos), mid + 1, r);
    pushUp(pos);
}

void fun(ll pos, ll l, ll r, ll k)
{
    tag[pos] += k;
    ans[pos] += (r - l + 1) * k;
}

void pushDown(ll pos, ll l, ll r)
{
    ll mid = (l + r) / 2;
    fun(lc(pos), l, mid, tag[pos]);
    fun(rc(pos), mid + 1, r, tag[pos]);
    tag[pos] = 0;
}

void update(ll pos, ll nextl, ll nextr, ll l, ll r, ll k)
{
    // cout << "u " << pos << " " << nextl << " " << nextr <<  ' ' << l << " " << r << " " << k  << endl;
    if (nextl <= l && nextr >= r)
    {
        ans[pos] += k * (r - l + 1);
        tag[pos] += k;
        return;
    }
    if (tag[pos])
        pushDown(pos, l, r);
    ll mid = (l + r) / 2;
    if (nextl <= mid)
        update(lc(pos), nextl, nextr, l, mid, k);
    if (nextr > mid)
        update(rc(pos), nextl, nextr, mid + 1, r, k);
    pushUp(pos);
}

ll query(ll pos, ll nextl, ll nextr, ll l, ll r)
{
    ll res = 0;
    // cout << pos << " " << nextl << " " << nextr << " " << l << " " << r << " " << ans[pos] << endl;
    if (nextl <= l && nextr >= r)
        return ans[pos];
    if (tag[pos]);
    pushDown(pos, l, r);
    ll mid = (l + r) / 2;
    if (nextl <= mid)
        res += query(lc(pos), nextl, nextr, l, mid);
    if (nextr > mid)
        res += query(rc(pos), nextl, nextr, mid + 1, r);
    return res;
}

ll qRange(ll node1, ll node2)
{
    ll res = 0;
    while (top[node1] != top[node2])
    {
        // cout << node1 << " " << node2 << endl;
        if (deep[top[node1]] < deep[top[node2]])
            swap(node1, node2);
        res += query(1, id[top[node1]], id[node1], 1, n);
        node1 = father[top[node1]];
    }
    if (deep[node1] > deep[node2])
        swap(node1, node2);
    res += query(1, id[node1], id[node2], 1, n);
    return res;
}

void updateTree(ll node, ll k)
{
    return update(1, id[node], id[node] + sons[node] - 1, 1, n, k);
}

void init()
{
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
        cin >> temp[i];
    for (ll i = 1; i < n; i++)
    {
        ll t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    dfs1(1, 0, 1);
    dfs2(1, 1);
    build(1, 1, n);
}

void work()
{
    while (m--)
    {
        ll opt, arg1, arg2;
        cin >> opt;
        if (opt == 1)
        {
            cin >> arg1 >> arg2;
            update(1, id[arg1], id[arg1], 1, n, arg2);
        }
        if (opt == 2)
        {
            cin >> arg1 >> arg2;
            updateTree(arg1, arg2);
        }
        if (opt == 3)
        {
            cin >> arg1;
            cout << qRange(arg1, 1) << endl;
        }
    }
}

int main()
{
    Buff;
    init();
    work();
    return 0;
}