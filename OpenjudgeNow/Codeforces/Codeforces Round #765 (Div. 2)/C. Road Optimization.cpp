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

int n, m, k;
vector<int> d, v;
map<int, int> dp[616][616];

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> m >> k;
    d.resize(n + 2);
    v.resize(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    dp[1][0][v[1]] = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (auto it : dp[i - 1][j])
            {
                dp[i][j][v[i]] = min(dp[i][j][v[i]], dp[i - 1][j][it.first] + it.first * (d[i] - d[i - 1]));
                if (dp[i][j][v[i]] == 0)
                    dp[i][j][v[i]] = dp[i - 1][j][it.first] + it.first * (d[i] - d[i - 1]);
                if (it.first < v[i])
                {
                    dp[i][j + 1][it.first] = min(dp[i][j + 1][it.first], dp[i - 1][j][it.first] + it.first * (d[i] - d[i - 1]));
                    if (dp[i][j + 1][it.first] == 0)
                        dp[i][j + 1][it.first] = dp[i - 1][j][it.first] + it.first * (d[i] - d[i - 1]);
                }
            }
        }
    }
    int ans = 1e12;
    for (int j = 0; j <= k; j++)
        for (auto it : dp[n][j])
        {
            // cout << j << " " << it.first << " " << it.second << endl;
            ans = min(ans, it.second + it.first * (m - d[n]));
        }
    cout << ans << endl;
    return 0;
}