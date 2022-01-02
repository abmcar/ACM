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

const int Maxn = 4e6 + 10;
ll Mod = 1e9 + 7;

int n;

ll f[Maxn];
ll preAns[Maxn];

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> Mod;
    f[1] = 1;
    preAns[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i] = preAns[i - 1];
        for (int l = 2, r; l <= i; l = r + 1)
        {
            r = i / (i / l);
            f[i] = f[i] + f[i / l] * (r - l + 1) % Mod;
        }
        preAns[i] = preAns[i - 1] + f[i] % Mod;
    }
    cout << f[n] % Mod << endl;
    return 0;
}