#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define endl "\n"

using namespace std;

const ll Maxn = 510000;
const ll Mod = 1e9 + 7;

ll t, n, m;
ll sTime[Maxn], eTime[Maxn], posTime[Maxn], nowTime;
ll deep[Maxn], father[Maxn], sons[Maxn], tag[Maxn], gson[Maxn];
ll num[Maxn], ans[Maxn], temp[Maxn];
ll val[Maxn], cnt;
vector<ll> g[Maxn];

void dfs1(ll nowNode, ll fatherNode, ll nowDeep)
{
    nowTime++;
    sTime[nowNode] = nowTime;
    posTime[nowTime] = nowNode;
    val[nowNode] = nowDeep;
    for (ll i = 0; i < g[nowNode].size(); i++)
    {
        ll nextNode = g[nowNode][i];
        if (nextNode == fatherNode)
            continue;
        dfs1(nextNode, nowNode, nowDeep + temp[nextNode]);
    }
    eTime[nowNode] = nowTime;
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
    ans[x] = max(ans[lc(x)] , ans[rc(x)]);
}

void build(long long pos, long long l, long long r)
{
    tag[pos] = 0;
    if (l == r)
    {
        ans[pos] = val[posTime[l]];
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
    ans[pos] += k;
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
        ans[pos] += k;
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
    ll res = -1e12;
    if (nextl <= l && nextr >= r)
        return ans[pos];
    if (tag[pos])
        pushDown(pos, l, r);
    ll mid = (l + r) / 2;
    if (nextl <= mid)
        res = max(res, query(lc(pos), nextl, nextr, l, mid));
    if (nextr > mid)
        res = max(res, query(rc(pos), nextl, nextr, mid + 1, r));
    return res;
}

void init()
{
    nowTime = 0;
    cin >> n >> m;
    memset(val,0,sizeof(val));
    memset(ans,0,sizeof(ans));
    for (ll i = 1; i <= n; i++)
        g[i].clear(), sTime[i] = eTime[i] = 0;
    for (ll i = 1; i < n; i++)
    {
        ll t1, t2;
        cin >> t1 >> t2;
        t1++;
        t2++;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    for (ll i = 1; i <= n; i++)
        cin >> temp[i];
    dfs1(1, 0, temp[1]);
    // dfs2(1, 1);
    build(1, 1, n);
}

void work()
{
    cout << "Case #" << ++cnt << ":" << endl;
    while (m--)
    {
        ll opt, arg1, arg2;
        cin >> opt;
        if (opt == 0)
        {
            cin >> arg1 >> arg2;
            arg1++;
            ll tempAdd = arg2 - temp[arg1];
            temp[arg1] = arg2;
            update(1, sTime[arg1], eTime[arg1], 1, n, tempAdd);
        }
        if (opt == 1)
        {
            cin >> arg1;
            arg1++;
            ll maxVal = -1e12;
            cout << query(1, sTime[arg1], eTime[arg1], 1, n) << endl;
        }
    }
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
    {
        init();
        work();
    }
    return 0;
}