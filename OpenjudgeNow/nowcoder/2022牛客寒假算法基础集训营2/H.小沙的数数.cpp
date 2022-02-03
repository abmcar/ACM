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

int n, m;

ll quick_pow(ll base, ll x)
{
    ll nowNum = 1;
    while (x)
    {
        if (x % 2)
            nowNum = nowNum * base % Mod;
        x = x / 2;
        base = base * base % Mod;
    }
    return nowNum;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif

    ll cnt = 0;
    cin >> m >> n;
    for (int i = 0; i <= 62; i++)
        if ((1LL << i) & n)
            cnt++;
    ll ans = 1;
    for (int i = 1; i <= cnt; i++)
        ans = m % Mod * ans % Mod;
    cout << ans << endl;
    // cout << quick_pow(m, cnt);
    return 0;
}