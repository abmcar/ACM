#include <bits/stdc++.h>

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug
// #define int long long
using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e6 + 10;

int n, m, q;
vector<int> g[Maxn];
int fa[Maxn][23];
int deep[Maxn];
bool used[Maxn];
long long high[Maxn];
long long cost1[Maxn], cost2[Maxn];

void dfs(int nowNode, int fatherNode)
{
    cost1[nowNode] = cost1[fatherNode];
    cost2[nowNode] = cost2[fatherNode];
    if (high[nowNode] > high[fatherNode])
        cost1[nowNode] += high[nowNode] - high[fatherNode];
    else
        cost2[nowNode] += high[fatherNode] - high[nowNode];
    deep[nowNode] = deep[fatherNode] + 1;
    fa[nowNode][0] = fatherNode;
    used[nowNode] = true;
    for (int i = 1; (1LL << i) <= deep[nowNode]; i++)
        fa[nowNode][i] = fa[fa[nowNode][i - 1]][i - 1];
    for (int i = 0; i < (int)g[nowNode].size(); i++)
        if (!used[g[nowNode][i]])
            dfs(g[nowNode][i], nowNode);
}

int lca(int pos1, int pos2)
{
    if (deep[pos1] < deep[pos2])
        swap(pos1, pos2);
    while (deep[pos2] != deep[pos1])
    {
        pos1 = fa[pos1][(int)log2(deep[pos1] - deep[pos2])];
    }
    while (pos1 != pos2)
    {
        int nexti = 0;
        while (fa[pos1][nexti] != fa[pos2][nexti])
            nexti++;
        if (nexti != 0)
            nexti--;
        pos1 = fa[pos1][nexti];
        pos2 = fa[pos2][nexti];
    }
    return pos1;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> high[i];
    for (int i = 1; i < n; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    high[0] = high[1];
    dfs(1, 0);
    while (q--)
    {
        int t1, t2;
        cin >> t1 >> t2;
        int t3 = lca(t1, t2);
        long long ans = cost2[t1] - cost2[t3] + high[t1];
        ans += cost1[t2] - cost1[t3];
        cout << ans << endl;
    }
    return 0;
}