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

const int Maxn = 1e3 + 10;
const ll Mod = 1e9 + 7;

int n, m;
int f[Maxn][Maxn * 3];

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> m;
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            f[i][j] = (f[i][j] + f[i - 1][j]) % Mod;
            f[i][j + nums[i]] = (f[i][j + nums[i]] + f[i - 1][j]) % Mod;
            f[i][j + nums[i] / 2] = (f[i][j + nums[i] / 2] + f[i - 1][j]) % Mod;
        }
    }
    for (int i = 1; i <= m; i++)
        cout << f[n][i] << " ";

    return 0;
}