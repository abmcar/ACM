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

inline ll lc(ll pos)
{
    return pos * 2;
}

inline ll rc(ll pos)
{
    return pos * 2 + 1;
}

inline void pushUp(ll pos)
{
    ans[pos] = ans[lc(pos)] + ans[rc(pos)];
}

void build(ll pos, ll l, ll r)
{
    tag[pos] = 0;
    if (l == r)
    {
        ans[pos] = num[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(lc(pos), l, mid);
    build(rc(pos), mid + 1, r);
    pushUp(pos);
}

inline void fun(ll pos, ll l, ll r, ll k)
{
    tag[pos] += k;
    ans[pos] = ans[pos] + (r - l + 1) * k;
}

inline void pushDown(ll pos, ll l, ll r)
{
    ll mid = (l + r) / 2;
    fun(lc(pos), l, mid, tag[pos]);
    fun(rc(pos), mid+ 1, r, tag[pos]);
    tag[pos] = 0;
}

inline void update(ll nextl, ll nextr, ll l, ll r, ll pos, ll k)
{
    if (nextl <= l && nextr >= r)
    {
        ans[pos] += k * (r - l + 1);
        tag[pos] += k;
        return;
    }
    pushDown(pos, l, r);
    ll mid = (l + r) / 2;
    if (nextl <= mid)
        update(nextl, nextr, l, mid, lc(pos), k);
    if (nextr > mid)
        update(nextl, nextr, mid + 1, r, rc(pos), k);
    pushUp(pos);
}

ll query(ll ql, ll qr, ll l, ll r, ll pos)
{
    if (ql <= l && qr >= r)
    {
        return ans[pos];
    }
    ll res = 0;
    ll mid = (l + r) / 2;
    pushDown(pos, l, r);
    if(ql <= mid)
        res += query(ql, qr, l, mid, lc(pos));
    if(qr > mid)
        res += query(ql, qr, mid+1, r, rc(pos));
    return res;
}

int main()
{
    Buff;
    ll cnt = 0;
    // cin >> t;
    cin >> n >> q;
    for (ll i = 1; i <= n; i++)
        cin >> num[i];
    build(1, 1, n);
    string Opt;
    for (ll i = 1; i <= q; i++)
    {
        cin >> Opt;
        if (Opt == "C")
        {
            ll t1, t2, t3;
            cin >> t1 >> t2 >> t3;
            update(t1, t2, 1, n, 1, t3);
        }
        if (Opt == "Q")
        {
            ll t1, t2;
            cin >> t1 >> t2;
            cout << query(t1, t2, 1, n, 1) << endl;
        }
    }
    return 0;
}