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

const int Maxn = 1e3 + 10;
const ll Mod = 1e9 + 7;

int n, m, s, t, bd[Maxn][Maxn];
vector<bool> vis;
vector<int> ans;

void dfs(int x)
{
    ans.push_back(x);
    vis[x] = true;
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i])
            continue;
        if (bd[x][i])
            dfs(i);
    }
}

void init()
{
    vis.resize(n + 1);
    vis.clear();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> bd[i][j];
}

void output()
{
    for (int it : ans)
        cout << it - 1 << " ";
    cout << endl;
}

void solve()
{
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i])
            continue;
        dfs(i);
    }
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    while (cin >> n)
    {
        init();
        solve();
        output();
    }
    return 0;
}