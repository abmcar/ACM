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
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf ll_MAX
#define endl "\n"

using namespace std;

const ll Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

ll t, n, q;
ll num[Maxn];
ll tag[Maxn];
ll ans[Maxn];
ll sum[Maxn];

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
    sum[pos] = max(sum[lc(pos)], sum[rc(pos)]);
}

void build(long long pos, long long l, long long r)
{
    tag[pos] = 0;
    if (l == r)
    {
        ans[pos] = num[l];
        sum[pos] = ans[pos];
        return;
    }
    long long mid = (l + r) / 2;
    build(lc(pos), l, mid);
    build(rc(pos), mid + 1, r);
    pushUp(pos);
}

inline void update(long long nextl, long long nextr, long long l, long long r, long long pos)
{
    if (l == r)
    {
        ans[pos] = sqrt(ans[pos]);
        sum[pos] = ans[pos];
        return;
    }
    // pushDown(pos, l, r);
    if (sum[pos] <= 1)
        return;
    long long mid = (l + r) / 2;
    if (nextl <= mid)
        update(nextl, nextr, l, mid, lc(pos));
    if (nextr > mid) 
        update(nextl, nextr, mid + 1, r, rc(pos));
    pushUp(pos);
}

long long query(long long ql, long long qr, long long l, long long r, long long pos)
{
    long long res = 0;
    if (ql <= l && qr >= r)
        return ans[pos];
    long long mid = (l + r) / 2;
    // pushDown(pos, l, r);
    if (ql <= mid)
        res += query(ql, qr, l, mid, lc(pos));
    if (qr > mid)
        res += query(ql, qr, mid + 1, r, rc(pos));
    return res;
}

int main()
{
    Buff;
    ll cnt = 0;
    cin >> n;
    // while (cin >> n)
    {
        for (ll i = 1; i <= n; i++)
            cin >> num[i];
        build(1, 1, n);
        cin >> q;
        // string Opt;
        // cout << query(1, 8, 1, n, 1) << endl;
        // cout << "Case #" << ++cnt << ":" << endl;
        for (ll i = 1; i <= q; i++)
        {
            ll t1, t2, t3;
            cin >> t1 >> t2 >> t3;
            if (t2 > t3)
                swap(t2, t3);
            if (t1 == 0)
                update(t2, t3, 1, n, 1);
            else
            cout << query(t2, t3, 1, n, 1) << endl;
        }
        // cout << endl;
    }
    return 0;
}