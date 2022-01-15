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

const int Maxn = 1e5 + 10;
const ll Mod = 1e9 + 7;

int t, n, m;
vector<int> g[Maxn];
map<pair<int, int>, int> M;

void dfs(int x, int father, int color)
{
    for (int i = 0; i < g[x].size(); i++)
    {
        if (g[x][i] == father)
            continue;
        M[{x, g[x][i]}] = color;
        M[{g[x][i], x}] = color;
        dfs(g[x][i], x, ((color == 2) ? 3 : 2));
    }
}

void work()
{
    cin >> n;
    for (int i = 0; i <= n; i++)
        g[i].clear();
    M.clear();
    vector<pair<int, int>> V;
    for (int i = 1; i < n; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
        V.push_back({t1, t2});
    }
    bool ok = true;
    for (int i = 1; i <= n; i++)
        if (g[i].size() >= 3)
            ok = false;
    if (!ok)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i < n; i++)
    {
        if (g[i].size() == 1)
        {
            dfs(i, 0, 2);
            break;
        }
    }
    for (auto it : V)
        cout << M[it] << " ";
    cout << endl;
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