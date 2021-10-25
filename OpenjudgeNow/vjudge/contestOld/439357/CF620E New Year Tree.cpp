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
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 2e6 + 10;
const ll Mod = 1e9 + 7;

int n, m;
int sTime[Maxn], eTime[Maxn], posTime[Maxn], nowTime;
ll num[Maxn], tag[Maxn], ans[Maxn];
vector<int> g[Maxn];

inline ll lc(ll x)
{
    return x*2;
}

inline ll rc(ll x)
{
    return x*2+1;
}

void dfs(int x, int fa)
{
    nowTime++;
    sTime[x] = nowTime;
    posTime[nowTime] = x;
    for (int i = 0; i < g[x].size(); i++)
    {
        int nextNode = g[x][i];
        if (fa == nextNode)
            continue;
        dfs(nextNode, x);
    }
    eTime[x] = nowTime;
}

inline void pushUp(int pos)
{
    ans[pos] = ans[lc(pos)] | ans[rc(pos)];
}

void build(int pos, int l, int r)
{
    if (l == r)
    {
        ans[pos] = ((ll)1 << num[posTime[l]]);
        tag[pos] = 0;
        return;
    }
    long long mid = (l + r) / 2;
    build(lc(pos), l, mid);
    build(rc(pos), mid + 1, r);
    pushUp(pos);
}

void pushDown(int pos)
{
    if (tag[pos] != 0)
    {
        ans[rc(pos)] = tag[pos];
        ans[lc(pos)] = tag[pos];
        tag[rc(pos)] = tag[pos];
        tag[lc(pos)] = tag[pos];
        tag[pos] = 0;
    }
}

void update(long long nextl, long long nextr, long long l, long long r, long long pos, long long k)
{
    // cout << nextl << " " << nextr << " " << l << " " << r << " " << pos << " " << k << endl;
    // cout << "srt up" << endl;
    if (nextl <= l && nextr >= r)
    {
        ans[pos] = (ll) 1 << k;
        tag[pos] = (ll) 1 << k;
        // cout << "upd" << ans[pos] << endl;
        return;
    }
    pushDown(pos);
    long long mid = (l + r) / 2;
    if (nextl <= mid)
        update(nextl, nextr, l, mid, lc(pos), k);
    if (nextr > mid)
        update(nextl, nextr, mid + 1, r, rc(pos), k);
    pushUp(pos);
}

long long query(long long ql, long long qr, long long l, long long r, long long pos)
{
    // cout << "q " << ql << " " << qr << " " << l << " " << r << " " << pos << endl;
    long long res = 0;
    if (ql <= l && qr >= r)
        return ans[pos];
    long long mid = (l + r) / 2;
    pushDown(pos);
    if (ql <= mid)
        res = res | query(ql, qr, l, mid, lc(pos));
    if (qr > mid)
        res = res | query(ql, qr, mid + 1, r, rc(pos));
    return res;
}

ll lowbit(ll x)
{
    return x & -x;
}

int getSum(ll val)
{
    int res = 0;
    while (val != 0)
    {
        val = val - lowbit(val);
        res++;
    }
    return res;
}

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    for (int i = 1; i < n; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    dfs(1,0);
    build(1,1,n);
}

void work()
{
    while (m--)
    {
        int opt, arg1, arg2;
        cin >> opt;
        if (opt == 1)
        {
            cin >> arg1 >> arg2;
            update(sTime[arg1],eTime[arg1],1,n,1,arg2);
        }else
        {
            cin >> arg1;
            cout << getSum(query(sTime[arg1],eTime[arg1],1,n,1)) << endl;
        }
    }
}

int main()
{
    Buff;
    init();
    // cout << getSum(query(1,7,1,n,1)) << endl;
    // cout << nowTime << endl;
    // cout << sTime[1] << " " << eTime[1] << endl;
    work();
    return 0;
}