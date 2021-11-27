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

ll n, a, b;

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> a >> b;
    ll totNum = n * b - a;
    int nextNum = b + (totNum - b) % (n - 2);
    cout << fixed << setprecision(0);
    for (int i = 1; i <= n / 2; i++)
        cout << -1e11 << " ";
    cout << a << " ";
    cout << 1e11 + totNum << " ";
    for (int i = 2; i <= n / 2; i++)
        cout << 1e11 << " ";
    return 0;
}