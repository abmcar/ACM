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
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n;
int num[Maxn];
int tag[Maxn];
int ans[Maxn];

inline int lc(int pos)
{
    return pos * 2;
}

inline int rc(int pos)
{
    return pos * 2 + 1;
}

inline void pushUp(int pos)
{
    ans[pos] = ans[lc(pos)] + ans[rc(pos)];
}

void build(int pos, int l, int r)
{
    tag[pos] = 0;
    if (l == r)
    {
        ans[pos] = num[l];
        return;
    }
    int mid = (l + r) / 2;
    build(lc(pos), l, mid);
    build(rc(pos), mid + 1, r);
    pushUp(pos);
}

inline void fun(int pos, int l, int r, int k)
{
    tag[pos] += k;
    ans[pos] = ans[pos] + (r - l + 1) * k;
}

inline void pushDown(int pos, int l, int r)
{
    int mid = (l + r) / 2;
    fun(lc(pos), l, mid, tag[pos]);
    fun(rc(pos), mid+ 1, r, tag[pos]);
    tag[pos] = 0;
}

inline void update(int nextl, int nextr, int l, int r, int pos, int k)
{
    if (nextl <= l && nextr >= r)
    {
        ans[pos] += k * (r - l + 1);
        tag[pos] += k;
        return;
    }
    pushDown(pos, l, r);
    int mid = (l + r) / 2;
    if (nextl <= mid)
        update(nextl, nextr, l, mid, lc(pos), k);
    if (nextr > mid)
        update(nextl, nextr, mid + 1, r, rc(pos), k);
    pushUp(pos);
}

int query(int ql, int qr, int l, int r, int pos)
{
    if (ql <= l && qr >= r)
    {
        return ans[pos];
    }
    int res = 0;
    int mid = (l + r) / 2;
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
    int cnt = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++cnt << ":" << endl;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> num[i];
        build(1, 1, n);
        string Opt;
        while (cin >> Opt)
        {
            if (Opt == "End")
                break;
            if (Opt == "Add")
            {
                int t1, t2;
                cin >> t1 >> t2;
                update(t1, t1, 1, n, 1, t2);
            }
            if (Opt == "Sub")
            {
                int t1, t2;
                cin >> t1 >> t2;
                update(t1, t1, 1, n, 1, t2*-1);
            }
            if (Opt == "Query")
            {
                int t1, t2;
                cin >> t1 >> t2;
                cout << query(t1, t2, 1, n, 1) << endl;
            }
        }
    }
    return 0;
}