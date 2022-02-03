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

const int Maxn = 1e3 + 10;
const ll Mod = 1e9 + 7;

int t, n, m;

void work()
{
    int ans = 0;
    cin >> n >> m;
    vector<string> bd(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> bd[i], bd[i] = "=" + bd[i] + "=";
    bd[0] = bd[n + 1] = string(m + 10, '1');
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (bd[i][j] == 'P')
            {
                bool ok1 = false, ok2 = false;
                for (int p1 = i - 1; p1 <= i + 1; p1++)
                    for (int p2 = j - 1; p2 <= j + 1; p2++)
                        if (bd[p1][p2] == '*')
                            ok1 = true;
                if (ok1)
                    continue;
                ans++;
            }
        }
    cout << ans << endl;
}

signed main()
{
    // Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> t;
    while (t--)
        work();
    return 0;
}