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
// using namespace __gnu_pbds;

const int Maxn = 1e6 + 10;
const ll Mod = 1e9 + 7;

int t, n, m, ans;
vector<int> q[Maxn], p[Maxn];

void work()
{
    ans = 0;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        p[i].resize(m + 1), p[i].clear();
    for (int i = 1; i <= m; i++)
        q[i].resize(n + 1), q[i].clear();
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> q[i][j];
            p[j][i] = q[i][j];
        }
    for (int i = 1; i <= m; i++)
        sort(q[i].begin() + 1, q[i].begin() + 1 + n, greater<int>());
    for (int i = 1; i <= n; i++)
        sort(p[i].begin() + 1, p[i].begin() + 1 + m, greater<int>());
    for (int i = 1; i <= m; i++)
    {
        ans = max(ans, q[i][2]);
        // cout << q[i][1] << " ";
    }
    // cout << endl;
    for (int i = 1; i <= n; i++)
        ans = min(ans, p[i][1]);
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