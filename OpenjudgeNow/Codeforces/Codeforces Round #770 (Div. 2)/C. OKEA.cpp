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

int t, n, m;

void work()
{
    cin >> n >> m;
    vector<vector<int>> ans(n + 1, vector<int>(m + 1));
    bool ok = true;
    int nowNum = 1;
    for (int i = 1; i <= n; i += 2)
    {
        for (int j = 1; j <= m; j++)
        {
            if (nowNum > n * m)
                ok = false;
            ans[i][j] = nowNum;
            nowNum += 2;
        }
    }
    nowNum = 2;
    for (int i = 2; i <= n; i += 2)
    {
        for (int j = 1; j <= m; j++)
        {
            if (nowNum > n * m)
                ok = false;
            ans[i][j] = nowNum;
            nowNum += 2;
        }
    }
    if (!ok)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cout << ans[i][j] << " \n"[j == m];
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