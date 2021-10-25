#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
// #define long long long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7 + 10;
const long long Mod = 1e9 + 7;

int n, m;
long long ans[Maxn], num[Maxn], tag[Maxn];

inline long long lc(long long pos)
{
    return pos * 2;
}

inline long long rc(long long pos)
{
    return pos * 2 + 1;
}

void pushUp(long long pos)
{
    ans[pos] = ans[lc(pos)] + ans[rc(pos)];
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

inline void fun(long long pos, long long l, long long r, long long k)
{
    tag[pos] += k;
    ans[pos] += (r - l + 1) * k;
}

inline void pushDown(long long pos, long long l, long long r)
{
    long long mid = (l + r) / 2;
    fun(lc(pos), l, mid, tag[pos]);
    fun(rc(pos), mid + 1, r, tag[pos]);
    tag[pos] = 0;
}

inline void update(long long nextl, long long nextr, long long l, long long r, long long pos, long long k)
{
    if (nextl <= l && nextr >= r)
    {
        ans[pos] += k * (r - l + 1);
        tag[pos] += k;
        return;
    }
    pushDown(pos, l, r);
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
    pushDown(pos, l, r);
    if (ql <= mid)
        res += query(ql, qr, l, mid, lc(pos));
    else
        res += query(ql, qr, mid + 1, r, rc(pos));
    return res;
}

int main()
{
    Buff;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            long long x, y, k;
            cin >> x >> y >> k;
            update(x, y, 1, n, 1, k);
        }
        if (type == 2)
        {
            long long x, y;
            cin >> x >> y;
            cout << query(x, y, 1, n, 1) << endl;
        }
    }
    return 0;
}