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

const int Maxn = 600000;
const ll Mod = 1e9 + 7;

int n, m, k;
ll num[Maxn], tag[Maxn], ans[Maxn];

inline ll lc(ll x)
{
    return x * 2;
}

inline ll rc(ll x)
{
    return x * 2 + 1;
}

inline void pushUp(int pos)
{
    ans[pos] = ans[lc(pos)] | ans[rc(pos)];
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
    if (nextl <= l && nextr >= r)
    {
        ans[pos] = (ll)1 << k;
        tag[pos] = (ll)1 << k;
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
    // cin >> n >> k >> m;
    scanf("%d %d %d",&n,&k,&m);
    for (int i = 1; i <= 4*n; i++)
        ans[i] = 1 << 1;
}

void work()
{
    while (m--)
    {
        // string opt;
        char opt;
        int arg1, arg2, arg3;
        // cin >> opt;
        scanf("\n%c",&opt);
        if (opt == 'C')
        {
            // cin >> arg1 >> arg2 >> arg3;
            scanf("%d %d %d",&arg1,&arg2,&arg3);
            if (arg1 > arg2)
                swap(arg1, arg2);
            update(arg1, arg2, 1, n, 1, arg3);
        }
        else
        {
            // cin >> arg1 >> arg2;
            scanf("%d %d",&arg1,&arg2);
            if (arg1 > arg2)
                swap(arg1, arg2);
            // cout << getSum(query(arg1, arg2, 1, n, 1)) << endl;
            printf("%d\n",getSum(query(arg1, arg2, 1, n, 1)));
        }
    }
}

int main()
{
    // Buff;
    init();
    work();
    return 0;
}