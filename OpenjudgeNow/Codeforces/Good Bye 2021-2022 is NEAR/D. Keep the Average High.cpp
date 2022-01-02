#include "bits/stdc++.h"

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

const int Maxn = 1e5 + 10;
const ll Mod = 1e9 + 7;

int t, n, x;
map<int, int> dp[4];

void work()
{
    for (int i = 0; i <= 3; i++)
        dp[i].clear();
    cin >> n;
    vector<int> V(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> V[i];
    cin >> x;
    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
        dp[0][i] = max(dp[0][i], dp[2][i - 1]);
        dp[0][i] = max(dp[0][i], dp[3][i - 1]);
        dp[1][i] = dp[0][i - 1] + 1;
        if (i >= 2 && V[i] + V[i - 1] >= 2 * x)
            dp[2][i] = max(dp[0][i - 2] + 2, dp[1][i - 1] + 1);
        if (i >= 3 && (V[i] + V[i - 1] >= 2 * x) && (V[i - 1] + V[i - 2] >= 2 * x) && (V[i - 2] + V[i - 1] + V[i] >= 3 * x))
        {
            dp[3][i] = max(dp[2][i - 1] + 1, dp[1][i - 2] + 2);
            dp[3][i] = max(dp[3][i], dp[0][i - 3] + 3);
            dp[3][i] = max(dp[3][i], dp[3][i - 1] + 1);
        }
    }
    int ans = 0;
    ans = max(dp[0][n], dp[1][n]);
    ans = max(ans, dp[2][n]);
    ans = max(ans, dp[3][n]);
    cout << ans << endl;
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