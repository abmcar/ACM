#include <iostream>
#include <algorithm>
#define Maxn (int)1e6 + 10
using namespace std;

int n, m;
long long ans[Maxn];
long long num[Maxn];
long long tag[Maxn];

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
    tag[pos] = tag[pos] + k;
    ans[pos] = ans[pos] + (r - l + 1) * k;
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
    if(ql <= l && qr >= r)
        return ans[pos];
    long long mid = (l + r) / 2;
    pushDown(pos,l,r);
    if(ql <= mid)
        res += query(ql, qr, l, mid, lc(pos));
    if(qr > mid)
        res += query(ql, qr, mid+1, r, rc(pos));
    return res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    build(1,1,1e5);
    cin >> m;
    for(int i = 1; i <= n; i++)
    {
        long long x,y,k;
        cin >> x >> y;
        k = 1;
        update(x, y, 1, 1e5, 1, k);
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        long long x,y;
        cin >> x >> y;
        cout << query(x, y, 1, 1e5, 1) << endl;
    }
    return 0;
}