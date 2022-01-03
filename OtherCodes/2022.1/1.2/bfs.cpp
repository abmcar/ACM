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

int n, m, s, t;
int bd[Maxn][Maxn];
queue<int> Q;
vector<int> ans;
vector<bool> vis;

void bfs(int x)
{
    Q.push(x);
    while (!Q.empty())
    {
        int nowNode = Q.front();
        Q.pop();
        for (int i = 1; i <= n; ++i)
        {
            if (vis[i])
                continue;
            if (!bd[nowNode][i])
                continue;
            vis[i] = true;
            Q.push(i);
        }
        ans.push_back(nowNode);
    }
    return;
}

void init()
{
    vis.resize(n + 1);
    vis.clear();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> bd[i][j];
}

void solve()
{
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i])
            continue;
        vis[i] = true;
        bfs(i);
    }
}

void output()
{
    for (int it : ans)
        cout << it - 1 << " ";
    cout << endl;
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