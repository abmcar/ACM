#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 5e4 + 10;
const ll Mod = 1e9 + 7;

int n, m, c;
int dis[Maxn];
bool vised[Maxn];
int deep[Maxn];
int fa[Maxn][32];
int ufa[Maxn];
vector<int> g[Maxn], w[Maxn];

int find(int son)
{
    if (ufa[son] == son)
        return son;
    ufa[son] = find(ufa[son]);
    return ufa[son];
}

void dfs(int nowNode, int fatherNode)
{
    // cout << nowNode << endl;
    deep[nowNode] = deep[fatherNode] + 1;
    vised[nowNode] = true;
    fa[nowNode][0] = fatherNode;
    for (int i = 1; (1 << i) <= deep[nowNode]; i++)
        fa[nowNode][i] = fa[fa[nowNode][i - 1]][i - 1];
    for (int i = 0; i < g[nowNode].size(); i++)
    {
        int nextNode = g[nowNode][i];
        if (vised[nextNode])
            continue;
        dis[nextNode] = dis[nowNode] + w[nowNode][i];
        dfs(nextNode, nowNode);
    }
}

void init()
{
    for (int i = 1; i <= n; i++)
        dis[i] = 1e9, vised[i] = false, deep[i] = 0, g[i].clear(), w[i].clear(), ufa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        int f1 = find(t1);
        int f2 = find(t2);
        g[t1].push_back(t2);
        g[t2].push_back(t1);
        w[t1].push_back(t3);
        w[t2].push_back(t3);
        if (f1 == f2)
            continue;
        ufa[f1] = f2;
    }
    for (int i = 1; i <= n; i++)
    if (find(i) == i)
    {
        dis[i] = 0;
        dfs(i, 0);
    }
}

int lca(int c1, int c2)
{
    if (deep[c1] < deep[c2])
        swap(c1, c2);
    while (deep[c1] != deep[c2])
        c1 = fa[c1][(int)log2(deep[c1]-deep[c2])];
    while (c1 != c2)
    {
        int nexti = 0;
        while (fa[c1][nexti] != fa[c2][nexti])
            nexti++;
        if (nexti != 0)
            nexti--;
        c1 = fa[c1][nexti];
        c2 = fa[c2][nexti];
    }
    return c1;
}

void work()
{
    init();
    for (int i = 1; i <= c; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        if (find(t1) != find(t2))
        {
            cout << "Not connected" << endl;
            continue;
        }
        int fa = lca(t1, t2);
        int nowDis = dis[t1] + dis[t2] - 2 * dis[fa];
        cout << nowDis << endl;
    }
}

int main()
{
    Buff;
    while (cin >> n >> m >> c)
        work();
    return 0;
}