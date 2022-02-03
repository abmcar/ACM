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
// #define int long long
int t, n;
double m;
int mm;

void work()
{
    cin >> n >> m;
    int ans = 0;
    int redPoints = 0;
    int greenPoints = 0;
    int rmb = n;
    mm = m * 10;
    while (1)
    {
        if (rmb == 0)
            break;
        redPoints = rmb * 100;
        greenPoints = min(10000, rmb * 10 * (mm - 10));
        ans += redPoints;
        ans += greenPoints;
        rmb = rmb / 2;
        // cout << redPoints / 10 + greenPoints / 10 << endl;
    }
    cout << ans/10 << endl;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> t;
    while (t--)
        work();
    return 0;
}