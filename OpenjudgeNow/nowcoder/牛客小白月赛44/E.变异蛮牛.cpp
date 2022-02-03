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
#define int long long
int t, n, m;
vector<int> g[Maxn];
int blackNum;

void dfs(int nowNode, int fatherNode,bool color)
{
    if (color)
        blackNum++;
    for (int it : g[nowNode])
    {
        if (it == fatherNode)
            continue;
        dfs(it, nowNode, !color);
    }
}

void work()
{
    blackNum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 1; i < n; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    dfs(1, 0, true);
    // cout << blackNum << endl;
    cout << blackNum * (blackNum + 1) / 2 << endl;
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