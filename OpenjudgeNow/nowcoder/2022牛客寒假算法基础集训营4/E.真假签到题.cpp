#include <bits/stdc++.h>

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

long long f(long long x)
{
    if (x == 1)
        return 1;
    return f(x / 2) + f(x / 2 + x % 2);
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    ll x;
    cin >> x;
    // for (int i = 1; i <= 100; i++)
    //     cout << f(i) << endl;
    cout << x << endl;
    return 0;
}