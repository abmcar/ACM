#include <bits/stdc++.h>

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug
#define int long long
using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int p, l, r, L, R;
int ans;

int getAns(int l, int r, int l1, int r1)
{
    int nowAns = min(r, r1) - max(l, l1);
    if (min(r, r1) >= max(l, l1))
        nowAns++;
    else
        nowAns = 0;
    return nowAns;
}

int getP(int x)
{
    int mul = x / p;
    int mVal = getAns(0, p - 1, l, r);
    int ex = getAns(0, x % p, l, r);
    if (x % p == 0)
        ex = 0;
    if (getAns(0, 0, l, r))
        ex--;
    // cout << x << " " << mul << " " << mVal << " " << ex << endl;
    return max(0LL, mul * mVal + ex);
}

int getUP(int x)
{
    x = x * -1;
    int mul = x / p;
    int mVal = getAns((p - 1) * -1, 0, l, r);
    int ex = getAns((x % p) * -1, 0, l, r);
    if (x % p == 0)
        ex = 0;
    if (getAns(0, 0, l, r))
        ex--;
    // cout << x << " " << mul << " " << mVal << " " << ex << endl;
    return max(0LL, mul * mVal + ex);
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> p >> l >> r >> L >> R;
    p = abs(p);
    if (R > 0)
    {
        if (L > 0)
            ans += getP(R) - getP(L);
        else
            ans += getP(R) + getUP(L);
    }
    else
        ans += getUP(L) - getUP(R);
    if (getAns(0, 0, l, r) && getAns(0, 0, L, R))
        ans++;
    cout << ans << endl;
    return 0;
}