#include "bits/stdc++.h"

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int n;
vector<int> lc, rc;
vector<char> da;

void solve1(int nowNode)
{
    if (nowNode == 0)
        return;
    cout << da[nowNode];
    solve1(lc[nowNode]);
    solve1(rc[nowNode]);
}

void solve2(int nowNode)
{
    if (nowNode == 0)
        return;
    solve2(lc[nowNode]);
    cout << da[nowNode];
    solve2(rc[nowNode]);
}

void solve3(int nowNode)
{
    if (nowNode == 0)
        return;
    solve3(lc[nowNode]);
    solve3(rc[nowNode]);
    cout << da[nowNode];
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n;
    lc.resize(n + 1);
    rc.resize(n + 1);
    da.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        char t1;
        int t2, t3;
        cin >> t1 >> t2 >> t3;
        da[i] = t1;
        lc[i] = t2;
        rc[i] = t3;
    }
    solve1(1);
    cout << endl;
    solve2(1);
    cout << endl;
    solve3(1);
    cout << endl;
    return 0;
}